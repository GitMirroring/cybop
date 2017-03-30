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

#ifndef OPEN_TERMINAL_STARTER_SOURCE
#define OPEN_TERMINAL_STARTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/maintainer/starter/unix_terminal/open_unix_terminal_starter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/maintainer/starter/unix_terminal/open_unix_terminal_starter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/maintainer/starter/win32_console/open_win32_console_starter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Opens the terminal.
 *
 * @param p0 the internal memory data
 */
void startup_terminal_open(void* p0) {

    // The input- and output data.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input- and output data.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create new terminal resources if both,
    // input- AND output are null.
    if ((ip == *NULL_POINTER_STATE_CYBOI_MODEL) && (op == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal open.");

        // Allocate input- and output data.
        //
        // A unix file descriptor AS WELL AS a win32
        // console handle is just an int value.
        // Therefore, the INTEGER_NUMBER_STATE_CYBOI_TYPE
        // constant may be used here for both.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_array((void*) &ip, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &op, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Set input- and output data.
        //
        // CAUTION! Add it as soon as it was allocated above
        // ALWAYS and not only if opened successfully below.
        // Otherwise, in case of an error, the shutdown function
        // freeing it may not find it leading to a memory leak.
        //
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#if defined(__linux__) || defined(__unix__)
        startup_unix_terminal_open(ip, op, p0);
#elif defined(__APPLE__) && defined(__MACH__)
        startup_unix_terminal_open(ip, op, p0);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        startup_win32_console_open(ip, op, p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal open. The input- or output data or both already exist.");
    }
}

/* OPEN_TERMINAL_STARTER_SOURCE */
#endif
