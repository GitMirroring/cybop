/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "cyboi.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the command line log level option.
 *
 * @param p0 the log level
 * @param p1 the log level name data
 * @param p2 the log level name count
 */
void select_command_line_log_level(void* p0, void* p1, void* p2) {

    //
    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    //
    // log_write((void*) stdout, L"Debug: Select command line log level.\n");
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) OFF_LOG_LEVEL_OPTION_CYBOI_MODEL, p2, (void*) OFF_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) OFF_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL, p2, (void*) ERROR_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ERROR_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL, p2, (void*) WARNING_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) WARNING_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL, p2, (void*) INFORMATION_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL, p2, (void*) DEBUG_LOG_LEVEL_OPTION_CYBOI_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) DEBUG_LEVEL_LOG_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        //
        log_write((void*) stdout, L"Warning: Could not select command line log level. The log level name is unknown.\n");
    }
}
