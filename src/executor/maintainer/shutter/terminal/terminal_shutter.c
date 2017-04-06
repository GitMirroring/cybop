/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/maintainer/shutter/unix_terminal/unix_terminal_shutter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/maintainer/shutter/unix_terminal/unix_terminal_shutter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/shutter/win32_console/win32_console_shutter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

    //?? TODO: Is the terminal parametres retrieved here an ITEM or ARRAY??
    //?? --> Adapt the functions and arguments below!

    // The input- and output item.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input- and output item.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate terminal resources if AT LEAST ONE,
    // the input- OR output stream internal is NOT null.
    if ((ip != *NULL_POINTER_STATE_CYBOI_MODEL) || (op != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Interrupt terminal service thread.
        interrupt_thread(p1, p2);

#if defined(__linux__) || defined(__unix__)
        shutdown_unix_terminal(ip, op, p0);
#elif defined(__APPLE__) && defined(__MACH__)
        shutdown_unix_terminal(ip, op, p0);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        shutdown_win32_console(ip, op, p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        // Deallocate input- and output array.
        // CAUTION! The second argument "count" is NULL,
        // since it is only needed for looping elements of type PART,
        // in order to decrement the rubbish (garbage) collection counter.
        deallocate_array((void*) &ip, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate_array((void*) &op, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Reset terminal values.
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. There is no terminal running.");
    }
}

/* TERMINAL_SHUTTER_SOURCE */
#endif
