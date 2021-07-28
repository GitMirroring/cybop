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

#ifndef IO_STARTER_SOURCE
#define IO_STARTER_SOURCE

#include <threads.h> // mtx_t, mtx_init

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/model/file/opentype_file_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/setter/internal_memory_setter.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/maintainer/starter/pipe/create_pipe_starter.c"
#include "../../executor/memoriser/allocator/array_allocator.c"
#include "../../executor/porter/descriptor_to_stream_converter.c"
#include "../../logger/logger.c"
#include "../../variable/symbolic_name/mutex_thread_symbolic_name.c"

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
// The display interrupt request flag.
// volatile sig_atomic_t display_irq_array[1];
// volatile sig_atomic_t* display_irq = display_irq_array;
//

/**
 * Retrieves or allocates the input/output entry of the given service.
 *
 * @param p0 the input/output entry (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the socket port
 * @param p4 the thread function (pointer reference)
 */
void startup_io(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** io = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup io.");

        if (*io == *NULL_POINTER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Test: Startup io. *io: %i\n", *io);

            //
            // The input/output entry (service) does NOT yet exist in internal memory.
            //

            //
            // Declaration.
            //

            // The enable flag.
            void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The interrupt request.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The sender identification.
            void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The thread identification.
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The thread function.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The function argument.
            void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The access mutex.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The exit flag.
            void* ex = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The pipe.
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The read pipe stream.
            void* rp = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The write pipe stream.
            void* wp = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocation.
            //

            //
            // Allocate input/output entry.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array(p0, (void*) IO_ENTRY_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);

            //
            // Allocate enable flag.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &e, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Allocate interrupt request.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &i, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ATOMIC_SIGNAL_STATE_CYBOI_TYPE);
            //
            // Allocate sender identification.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &s, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Allocate thread identification.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &t, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_STATE_CYBOI_TYPE);
            //
            // Allocate thread function.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            //?? allocate_array((void*) &f, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FUNCTION_THREAD_STATE_CYBOI_TYPE);
            allocate_array((void*) &f, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
            //
            // Allocate function argument.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &a, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) POINTER_STATE_CYBOI_TYPE);
            //
            // Allocate access mutex.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &m, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_STATE_CYBOI_TYPE);
            //
            // Allocate exit flag.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &ex, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // Allocate pipe.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &p, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            //
            // CAUTION! Do NOT allocate read/write pipe streams, since
            // they are just references to the array elements of the pipe.
            //

            //
            // Initialisation.
            //

            // Initialise enable flag.
            copy_integer(e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            // Initialise interrupt request.
            copy_integer(i, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            // Initialise sender identification.
            copy_integer(s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            // Initialise thread identification.
            copy_integer(t, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            // Initialise thread function.
            // CAUTION! Hand over function as pointer REFERENCE.
            copy_pointer(f, p4);
            // Initialise function argument.
            // CAUTION! Hand over input/output entry as pointer REFERENCE.
            copy_pointer(a, p0);
            // The access mutex with casted type.
            mtx_t* mt = (mtx_t*) m;
            // Initialise access mutex.
            int r = mtx_init(mt, *PLAIN_MUTEX_TYPE_THREAD_SYMBOLIC_NAME);

            if (r == thrd_error) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The mutex object creation failed.");
                fwprintf(stdout, L"Error: Could not startup io. The mutex object creation failed. r: %i\n", r);
            }

            // Initialise exit flag.
            copy_integer(ex, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            // Initialise pipe.
            startup_pipe_create(p);

            //
            // Opening.
            //

            // The read pipe file descriptor.
            int rd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The write pipe file descriptor.
            int wd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // Get read pipe file descriptor.
            copy_array_forward((void*) &rd, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            // Get write pipe file descriptor.
            copy_array_forward((void*) &wd, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
            // Get read pipe stream.
            convert_descriptor_to_stream((void*) &rp, (void*) &rd, (void*) READ_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL);
            // Get write pipe stream.
            convert_descriptor_to_stream((void*) &wp, (void*) &wd, (void*) WRITE_WITHOUT_BINARY_MODE_OPENTYPE_FILE_MODEL);

            //
            // Storing.
            //

            // Set enable flag into input/output entry.
            copy_array_forward(*io, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ENABLE_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set interrupt request into input/output entry.
            copy_array_forward(*io, (void*) &i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTERRUPT_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set sender identification into input/output entry.
            copy_array_forward(*io, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SENDER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set thread identification into input/output entry.
            copy_array_forward(*io, (void*) &t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IDENTIFICATION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set thread function into input/output entry.
            copy_array_forward(*io, (void*) &f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FUNCTION_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set function argument into input/output entry.
            copy_array_forward(*io, (void*) &a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ARGUMENT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set access mutex into input/output entry.
            copy_array_forward(*io, (void*) &m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) MUTEX_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set exit flag into input/output entry.
            copy_array_forward(*io, (void*) &ex, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) EXIT_THREAD_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set pipe into input/output entry.
            copy_array_forward(*io, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set read pipe stream into input/output entry.
            copy_array_forward(*io, (void*) &rp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) READ_STREAM_PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Set write pipe stream into input/output entry.
            copy_array_forward(*io, (void*) &wp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WRITE_STREAM_PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Set input/output entry.
            set_internal_memory_element(p1, p0, p2, p3);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry (service) is not null, i.e. it does already exist in internal memory.");
            fwprintf(stdout, L"Warning: Could not startup io. The input/output entry (service) is not null, i.e. it does already exist in internal memory. *io: %i\n", *io);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup io. The input/output entry is null.");
        fwprintf(stdout, L"Error: Could not startup io. The input/output entry is null. p0: %i\n", p0);
    }
}

/* IO_STARTER_SOURCE */
#endif
