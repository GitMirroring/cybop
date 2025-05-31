/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <fcntl.h> // O_RDONLY, O_WRONLY, O_CREAT, O_TRUNC
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Determine file open mode.
 *
 * @param p0 the destination mode
 * @param p1 the source file open mode data
 * @param p2 the source file open mode count
 */
void open_file_mode(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open file mode.");
    //?? fwprintf(stdout, L"Debug: Open file mode. mode p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open file mode. mode *p0: %i\n", *((int*) p0));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) READ_OPEN_MODE_FILE_MODEL, p2, (void*) READ_OPEN_MODE_FILE_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The meaning of the single flags:
            //
            // O_RDONLY - open file for read access
            //
            int m = O_RDONLY;

            copy_integer(p0, (void*) &m);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) WRITE_OPEN_MODE_FILE_MODEL, p2, (void*) WRITE_OPEN_MODE_FILE_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The meaning of the single flags:
            //
            // O_WRONLY - open file for write access
            // O_CREAT - create file if it does not already exist
            // O_TRUNC - truncate file to zero length
            //
            // CAUTION! The truncation is IMPORTANT since otherwise,
            // old data will remain at the end of the file if the new data
            // is shorter so that only some of the already existing
            // previous data get overwritten.
            //
            int m = O_WRONLY | O_CREAT | O_TRUNC;

            copy_integer(p0, (void*) &m);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file mode. The open mode is unknown.");
        fwprintf(stdout, L"Warning: Could not open file mode. The open mode is unknown. open mode count p2: %i\n", p2);
        fwprintf(stdout, L"Warning: Could not open file mode. The open mode is unknown. open mode count *p2: %i\n", *((int*) p2));
        fwprintf(stdout, L"Warning: Could not open file mode. The open mode is unknown. open mode data p1: %ls\n", (wchar_t*) p1);
    }
}
