/*
 * Copyright (C) 1999-2013. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published
 * by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI. If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org/>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include <pthread.h>
#include <signal.h>

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../controller/manager/internal_memory_manager.c"
#include "../controller/manager/system_signal_handler_manager.c"
#include "../controller/initialiser.c"
#include "../executor/maintainer/shutter/display/display_shutter.c"
#include "../executor/maintainer/shutter/opengl/opengl_shutter.c"
#include "../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../logger/logger.c"
#include "../variable/type_size/integral_type_size.c"
#include "../variable/type_size/real_type_size.c"
#include "../variable/type_size/signal_type_size.c"
#include "../variable/type_size/thread_type_size.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup internal memory (global system parametres, e.g. for input/output)
 * - startup knowledge memory (statics = state knowledge + logic knowledge)
 * - startup signal memory (knowledge models to be executed as operations)
 * - allocate startup signal and add to signal memory
 * - run signal checker loop (dynamics)
 * - deallocate startup signal
 * - shutdown signal memory
 * - shutdown knowledge memory
 * - shutdown internal memory
 *
 * @param p0 the run source item
 */
void manage(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manage.");

    //
    // Variable declaration.
    //

    // The internal memory data.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge memory part.
    void* k = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Explanation concerning interrupt request flags:
    //
    // Unix system signal handlers that return normally must modify some global
    // variable in order to have any effect. Typically, the variable is one that
    // is examined periodically by the program during normal operation.
    //
    // Whether the data in an application concerns atoms, or mere text, one has to
    // be careful about the fact that access to a single datum is not necessarily
    // atomic. This means that it can take more than one instruction to read or
    // write a single object. In such cases, a signal handler might be invoked in
    // the middle of reading or writing the object.
    // The usage of data types that are always accessed atomically is one way to
    // cope with this problem. Therefore, this flag is of type sig_atomic_t.
    //
    // Reading and writing this data type is guaranteed to happen in a single
    // instruction, so there's no way for a handler to run in the middle of an access.
    // The type sig_atomic_t is always an integer data type, but which one it is,
    // and how many bits it contains, may vary from machine to machine.
    // In practice, one can assume that int and other integer types no longer than
    // int are atomic, that is objects of this type are always accessed atomically.
    // One can also assume that pointer types are atomic; that is very convenient.
    // Both of these assumptions are true on all of the machines that the GNU C
    // library supports and on all known POSIX systems.
    //
    // Why is the keyword "volatile" used here?
    //
    // In the following example, the code sets the value stored in "foo" to 0.
    // It then starts to poll that value repeatedly until it changes to 255:
    //
    // static int foo;
    // void bar(void) {
    //     foo = 0;
    //     while (foo != 255);
    // }
    //
    // An optimizing compiler will notice that no other code can possibly
    // change the value stored in "foo", and will assume that it will
    // remain equal to "0" at all times. The compiler will therefore
    // replace the function body with an infinite loop similar to this:
    //
    // void bar_optimized(void) {
    //     foo = 0;
    //     while (true);
    // }
    //
    // However, foo might represent a location that can be changed
    // by other elements of the computer system at any time,
    // such as a hardware register of a device connected to the CPU.
    // The above code would never detect such a change;
    // without the "volatile" keyword, the compiler assumes that
    // the current program is the only part of the system that could
    // change the value (which is by far the most common situation).
    //
    // To prevent the compiler from optimising code as above,
    // the "volatile" keyword is used:
    //
    // static volatile int foo;
    // void bar (void) {
    //     foo = 0;
    //     while (foo != 255);
    // }
    //
    // With this modification, the loop condition will not be optimised
    // away, and the system will detect the change when it occurs.
    //

    // The cyboi service interrupt request flag.
    volatile sig_atomic_t cyboi_service_irq_array[1];
    volatile sig_atomic_t* cyboi_service_irq = cyboi_service_irq_array;
    // The display interrupt request flag.
    volatile sig_atomic_t display_irq_array[1];
    volatile sig_atomic_t* display_irq = display_irq_array;
    // The serial port interrupt request flag.
    volatile sig_atomic_t serial_port_irq_array[1];
    volatile sig_atomic_t* serial_port_irq = serial_port_irq_array;
    // The terminal interrupt request flag.
    volatile sig_atomic_t terminal_irq_array[1];
    volatile sig_atomic_t* terminal_irq = terminal_irq_array;
    // The www service interrupt request flag.
    volatile sig_atomic_t www_service_irq_array[1];
    volatile sig_atomic_t* www_service_irq = www_service_irq_array;

    // The cyboi service mutex.
    pthread_mutex_t cyboi_service_mutex_array[1];
    pthread_mutex_t* cyboi_service_mutex = cyboi_service_mutex_array;
    // The display mutex.
    pthread_mutex_t display_mutex_array[1];
    pthread_mutex_t* display_mutex = display_mutex_array;
    // The serial port mutex.
    pthread_mutex_t serial_port_mutex_array[1];
    pthread_mutex_t* serial_port_mutex = serial_port_mutex_array;
    // The terminal mutex.
    pthread_mutex_t terminal_mutex_array[1];
    pthread_mutex_t* terminal_mutex = terminal_mutex_array;
    // The www service mutex.
    pthread_mutex_t www_service_mutex_array[1];
    pthread_mutex_t* www_service_mutex = www_service_mutex_array;

    // The cyboi service sleep time.
    int cyboi_service_sleep_time_array[1];
    int* cyboi_service_sleep_time = cyboi_service_sleep_time_array;
    // The display sleep time.
    int display_sleep_time_array[1];
    int* display_sleep_time = display_sleep_time_array;
    // The serial port sleep time.
    int serial_port_sleep_time_array[1];
    int* serial_port_sleep_time = serial_port_sleep_time_array;
    // The signal memory sleep time.
    int signal_memory_sleep_time_array[1];
    int* signal_memory_sleep_time = signal_memory_sleep_time_array;
    // The terminal sleep time.
    int terminal_sleep_time_array[1];
    int* terminal_sleep_time = terminal_sleep_time_array;
    // The www service sleep time.
    int www_service_sleep_time_array[1];
    int* www_service_sleep_time = www_service_sleep_time_array;

    //
    // Variable allocation.
    //

    // Allocate internal memory data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! The internal memory has a pre-defined count/size,
    // given by the constant INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT.
    allocate_array((void*) &i, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
    // Allocate knowledge memory part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &k, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    // Allocate signal memory item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! It is given an initial size of 1024, in order
    // to avoid steady reallocation, for better performance.
    // CAUTION! The signal memory should be a simple array only.
    // If it was a part, rubbish (garbage) collection would become effective
    // and manipulate the references count of child parts when removing them,
    // so that these might get deallocated while still needed.
    // But only the knowledge memory part has the right to do that.
    allocate_item((void*) &s, (void*) NUMBER_1024_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);

    //
    // Variable initialisation.
    //

    // Initialise knowledge memory part.
    //
    // CAUTION! It is not essential but just correct to assign a type here.
    // Furthermore, an initialised root node is needed e.g. when printing
    // the whole runtime knowledge tree as model diagram.
    // Otherwise (empty root type), the printed model diagram would be empty.

    // Fill knowledge memory.
    overwrite_part_element(k, (void*) L"root", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(k, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(k, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);

    // Initialise cyboi service interrupt request flag.
    copy_integer((void*) cyboi_service_irq, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise display interrupt request flag.
    copy_integer((void*) display_irq, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise serial port interrupt request flag.
    copy_integer((void*) serial_port_irq, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise terminal interrupt request flag.
    copy_integer((void*) terminal_irq, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    // Initialise www service interrupt request flag.
    copy_integer((void*) www_service_irq, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // In the following mutex initialisation functions, the second parametre
    // specifies attributes that are to be used to initialise the mutex.
    // If the parametre is null, the mutex is initialised with default attributes.
    //

    // Initialise cyboi service mutex.
    pthread_mutex_init(cyboi_service_mutex, *NULL_POINTER_STATE_CYBOI_MODEL);
    // Initialise display mutex.
    pthread_mutex_init(display_mutex, *NULL_POINTER_STATE_CYBOI_MODEL);
    // Initialise serial port mutex.
    pthread_mutex_init(serial_port_mutex, *NULL_POINTER_STATE_CYBOI_MODEL);
    // Initialise terminal mutex.
    pthread_mutex_init(terminal_mutex, *NULL_POINTER_STATE_CYBOI_MODEL);
    // Initialise www service mutex.
    pthread_mutex_init(www_service_mutex, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Initialise cyboi service sleep time.
    copy_integer((void*) cyboi_service_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);
    // Initialise display sleep time.
    copy_integer((void*) display_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);
    // Initialise serial port sleep time.
    copy_integer((void*) serial_port_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);
    // Initialise signal memory sleep time.
    copy_integer((void*) signal_memory_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);
    // Initialise terminal sleep time.
    copy_integer((void*) terminal_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);
    // Initialise www service sleep time.
    copy_integer((void*) www_service_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);

    //
    // System startup.
    //

    // Start up internal memory.
    //
    // CAUTION! The internal memory items have a fixed position,
    // determined by constants. The items HAVE TO be assigned an
    // initial value, since all source code relies on them.
    //
    // Most values are compared against the *NULL_POINTER_STATE_CYBOI_MODEL constant
    // to find out whether they are set or not. If now initial values
    // would be arbitrary pointers, the program would follow a wrong path,
    // because it would guess that an instance was properly allocated,
    // while in reality the value was just an arbitrary initial one.
    // Therefore, such values are initialised with the well-defined *NULL_POINTER_STATE_CYBOI_MODEL.
    //
    // CAUTION! ONLY ONE parametre can be handed over to threads!
    // For example, the tcp socket is running in an own thread.
    // Therefore, the knowledge memory and signal memory NEED TO BE ADDED
    // to the internal memory, in order to be forwardable to threads.

    startup_internal_memory(i, (void*) &k, (void*) &s, (void*) &signal_memory_sleep_time,
        (void*) &cyboi_service_irq, (void*) &cyboi_service_mutex, (void*) &cyboi_service_sleep_time,
        (void*) &serial_port_irq, (void*) &serial_port_mutex, (void*) &serial_port_sleep_time,
        (void*) &terminal_irq, (void*) &terminal_mutex, (void*) &terminal_sleep_time,
        (void*) &www_service_irq, (void*) &www_service_mutex, (void*) &www_service_sleep_time,
        (void*) &display_irq, (void*) &display_mutex, (void*) &display_sleep_time);

    // Start up system signal handler.
    startup_system_signal_handler();

    //
    // System initialisation.
    //

    // Initialise system with an initial signal.
    initialise(s, p0, i);

    //
    // System shutdown.
    //

    // The following calls of "shutdown" procedures are just to be sure,
    // in case a cybol application developer has forgotten to call the
    // corresponding service shutdown operation in cybol logic templates.
    // The "interrupt" procedures are called within the "shutdown" procedures.

    // Shutdown cyboi service.
    shutdown_socket(i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) CYBOI_SERVICE_THREAD, (void*) CYBOI_SERVICE_EXIT);
    // Shutdown display.
    shutdown_display(i, (void*) DISPLAY_THREAD, (void*) DISPLAY_EXIT);
    // Shutdown serial port.
    shutdown_serial_port(i, (void*) SERIAL_PORT_THREAD, (void*) SERIAL_PORT_EXIT);
    // Shutdown terminal.
    shutdown_terminal(i, (void*) TERMINAL_THREAD, (void*) TERMINAL_EXIT);
    // Shutdown www service.
    shutdown_socket(i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME,(void*) WWW_SERVICE_THREAD, (void*) WWW_SERVICE_EXIT);

    //
    // Variable finalisation.
    //

    // CAUTION! Do NOT REMOVE any internal memory internals!
    // The internals have a fixed position within the internal memory.
    // Removing them would shift all entries by one position and
    // thus make all entries invalid, since they could not be found
    // at their original index anymore.

    // Destroy cyboi service mutex.
    pthread_mutex_destroy(cyboi_service_mutex);
    // Destroy display mutex.
    pthread_mutex_destroy(display_mutex);
    // Destroy serial port mutex.
    pthread_mutex_destroy(serial_port_mutex);
    // Destroy terminal mutex.
    pthread_mutex_destroy(terminal_mutex);
    // Destroy www service mutex.
    pthread_mutex_destroy(www_service_mutex);

    //
    // Variable deallocation.
    //

    // Deallocate signal memory item.
    deallocate_item((void*) &s, (void*) POINTER_STATE_CYBOI_TYPE);
    // Deallocate knowledge memory part.
    // CAUTION! This is the knowledge memory tree root node.
    // It has to be deallocated MANUALLY here.
    // Its references count was initially zero and never
    // got changed during programme execution,
    // so that this root part is not deallocated automatically.
    deallocate_part((void*) &k);
    // Deallocate internal memory data.
    deallocate_array((void*) &i, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
}

/* MANAGER_SOURCE */
#endif
