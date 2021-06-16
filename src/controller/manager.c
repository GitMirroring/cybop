/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MANAGER_SOURCE
#define MANAGER_SOURCE

#include "../constant/format/cyboi/logic_cyboi_format.c"
#include "../constant/format/cyboi/state_cyboi_format.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/double_state_cyboi_model.c"
#include "../constant/model/cyboi/state/extra_integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../controller/manager/internal_memory_startup_manager.c"
#include "../controller/manager/shutdown_manager.c"
#include "../controller/manager/system_signal_handler_startup_manager.c"
#include "../controller/initialiser.c"
#include "../executor/maintainer/shutter/display/display_shutter.c"
#include "../executor/maintainer/shutter/opengl/opengl_shutter.c"
#include "../executor/maintainer/shutter/serial_port/serial_port_shutter.c"
#include "../executor/maintainer/shutter/socket/socket_shutter.c"
#include "../executor/maintainer/shutter/terminal/terminal_shutter.c"
#include "../executor/modifier/part_modifier.c"
#include "../logger/logger.c"
#include "../variable/type_size/integral_type_size.c"
#include "../variable/type_size/real_type_size.c"

/**
 * Manages the system.
 *
 * A system lifecycle consists of the three phases:
 * - startup
 * - running
 * - shutdown
 *
 * in the following order:
 * - startup internal memory (system parametres; globally accessible; e.g. for input/output)
 * - startup knowledge memory (heap; statics = state knowledge + logic knowledge)
 * - startup stack memory (stack)
 * - startup signal memory (event queue; knowledge models to be executed as operations)
 * - allocate startup signal and add to signal memory
 * - run signal checker loop (dynamics)
 * - deallocate startup signal
 * - shutdown signal memory
 * - shutdown stack memory
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
    // The stack memory part.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The signal memory sleep time.
    int signal_memory_sleep_time_array[1];
    int* signal_memory_sleep_time = signal_memory_sleep_time_array;

    //
    // Variable allocation.
    //

    //
    // Allocate internal memory data.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! The internal memory has a pre-defined count/size,
    // given by the constant INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT.
    //
    allocate_array((void*) &i, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
    //
    // Allocate knowledge memory part.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_part((void*) &k, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    //
    // Allocate stack memory item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! It is given an initial size of 1024, in order
    // to avoid steady reallocation, for better performance.
    //
    allocate_part((void*) &st, (void*) NUMBER_1024_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
    //
    // Allocate signal memory item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! It is given an initial size of 1024, in order
    // to avoid steady reallocation, for better performance.
    //
    allocate_part((void*) &s, (void*) NUMBER_1024_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

    //
    // Variable initialisation.
    //

    //
    // Initialise knowledge memory.
    //
    // CAUTION! It is not essential but just correct to assign a type here.
    // Furthermore, an initialised root node is needed e.g. when printing
    // the whole runtime memory tree as model diagram.
    // Otherwise (empty root type), the printed model diagram would be empty.
    //
    modify_part(k, (void*) L"knowledge", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NUMBER_9_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
    modify_part(k, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(k, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    //
    // Initialise stack memory.
    //
    // CAUTION! It is not essential but just correct to assign a type here.
    // Furthermore, an initialised root node is needed e.g. when printing
    // the whole runtime memory tree as model diagram.
    // Otherwise (empty root type), the printed model diagram would be empty.
    //
    modify_part(st, (void*) L"stack", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NUMBER_5_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
    modify_part(st, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(st, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    //
    // Initialise signal memory.
    //
    // CAUTION! It is not essential but just correct to assign a type here.
    // Furthermore, an initialised root node is needed e.g. when printing
    // the whole runtime memory tree as model diagram.
    // Otherwise (empty root type), the printed model diagram would be empty.
    //
    modify_part(s, (void*) L"signal", (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NUMBER_6_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
    modify_part(s, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(s, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    //
    // Initialise signal memory sleep time.
    //
    // Unit: nano second
    // Current value: 0.1 s == 100 ms == 100,000 us == 100.000.000 ns
    //
    copy_integer((void*) signal_memory_sleep_time, (void*) NUMBER_100000000_INTEGER_STATE_CYBOI_MODEL);

    //
    // System startup.
    //

    //
    // Startup internal memory.
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
    // Therefore, the knowledge memory and signal memory NEED TO BE ADDED
    // to the internal memory, in order to be forwardable to threads.
    //
    manage_startup_internal_memory(i, (void*) &k, (void*) &st, (void*) &s, (void*) &signal_memory_sleep_time);

    // Startup system signal handler.
    manage_startup_system_signal_handler();

    //
    // System initialisation.
    //

    //
    // Get signal memory part model item.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Initialise system with an initial signal.
    initialise(sm, p0, i);

    //
    // System shutdown.
    //
    manage_shutdown(i);

    //
    // Variable finalisation.
    //

    //
    // CAUTION! Do NOT REMOVE any internal memory internals!
    // The internals have a fixed position within the internal memory.
    // Removing them would shift all entries by one position and
    // thus make ALL entries INVALID, since they could not be found
    // at their original index anymore.
    //

    //
    // Variable deallocation.
    //

    // Deallocate signal memory item.
    deallocate_part((void*) &s);
    // Deallocate stack memory item.
    deallocate_part((void*) &st);
    //
    // Deallocate knowledge memory part.
    //
    // CAUTION! This is the knowledge memory tree root node.
    // It has to be deallocated MANUALLY here.
    // Its references count was initially zero and never
    // got changed during programme execution,
    // so that this root part is not deallocated automatically.
    //
    deallocate_part((void*) &k);
    //
    // Deallocate internal memory data.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    // CAUTION! The parts within internal memory should NOT be
    // considered for that, only those in knowledge memory.
    //
    deallocate_array((void*) &i, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
}

/* MANAGER_SOURCE */
#endif
