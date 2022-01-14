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

#ifndef FUNCTION_ENABLER_SOURCE
#define FUNCTION_ENABLER_SOURCE

#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/threader/spinner.c"
#include "../../logger/logger.c"

/**
 * Enables channel function.
 *
 * @param p0 the thread identification
 * @param p1 the thread function
 * @param p2 the function argument
 * @param p3 the channel
 */
void enable_function(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // Cast back parametre to correct function-pointer type.
        //
        // Signature of the original function in file "opener.c":
        // int open_general(void* p0)
        //
        // Definition of the function pointer in file "channel_enabler.c":
        // void* f = (void*) &open_general;
        //
        // CAUTION! There are TWO possible ways of calling the thread function,
        // which are exactly equivalent in every way by definition:
        //
        // (*f)(arg);
        // f(arg);
        //
        // See also discussion at:
        // https://stackoverflow.com/questions/1952175/how-can-i-call-a-function-using-a-function-pointer
        //
        // CAUTION! One may use void (*)() as kind of a void pointer for function pointers.
        // It is thus safe to store a pointer to a function inside of: void (*f)()
        // But one must ALWAYS back-cast to the correct function-pointer type before calling it.
        //
        // Otherwise, the following compiler messages will occur:
        // warning: dereferencing ‘void *’ pointer
        // error: called object is not a function or function pointer
        //
        //?? int (*f)(void* p0) = (int (*f)(void* p0)) p1;
        int (*f)(void* p0) = p1;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Enable function.");
        fwprintf(stdout, L"Debug: Enable function. channel p3: %i\n", p3);
        fwprintf(stdout, L"Debug: Enable function. channel *p3: %i\n", *((int*) p3));

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) DISPLAY_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Invoke accept function directly WITHOUT separate thread.
                (*f)(p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) SERIAL_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Invoke accept function directly WITHOUT separate thread.
                (*f)(p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) SOCKET_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Invoke accept function WITHIN a new thread.
                spin(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p3, (void*) TERMINAL_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Invoke accept function directly WITHOUT separate thread.
                (*f)(p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable function. The channel is unknown.");
            fwprintf(stdout, L"Warning: Could not enable function. The channel is unknown. Channel p3: %i\n", *((int*) p3));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not enable function. The thread function is null.");
        fwprintf(stdout, L"Error: Could not enable function. The thread function is null. p1: %i\n", p1);
    }
}

/* FUNCTION_ENABLER_SOURCE */
#endif
