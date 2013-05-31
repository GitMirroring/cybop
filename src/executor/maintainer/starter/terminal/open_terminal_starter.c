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
 * @version CYBOP 0.14.0 2013-05-31
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
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/maintainer/starter/win32_console/open_win32_console_starter.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/maintainer/starter/unix_terminal/open_unix_terminal_starter.c"
#endif

/**
 * Opens the terminal.
 *
 * @param p0 the internal memory data
 */
void startup_terminal_open(void* p0) {

    // The input- and output item.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input- and output item data.
    void* ipd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* opd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input- and output item.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create new terminal resources if both,
    // input- AND output are null.
    if ((ip == *NULL_POINTER_STATE_CYBOI_MODEL) && (op == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal open.");

        // Allocate input- and output item.
        //
        // A unix file descriptor AS WELL AS a win32
        // console handle is just an int value.
        // Therefore, the INTEGER_NUMBER_STATE_CYBOI_TYPE
        // constant may be used here for both.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        // CAUTION! Use "item" for input- and output storage in internal memory,
        // since their counts and sizes are needed for deallocation.
        //
        allocate_item((void*) &ip, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &op, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Set input- and output item.
        // CAUTION! Add it as soon as it was allocated above
        // ALWAYS and not only if opened successfully below.
        // Otherwise, in case of an error, the shutdown function
        // freeing it may not find it leading to a memory leak.
        copy_array_forward(p0, (void*) &ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) OUTPUT_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Get input- and output item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &ipd, ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &opd, op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

#ifdef WIN32
        startup_win32_console_open(ipd, opd);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
        startup_unix_terminal_open(ipd, opd, p0);
#endif

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal open. The input- or output item or both already exist.");
    }
}

/* OPEN_TERMINAL_STARTER_SOURCE */
#endif
