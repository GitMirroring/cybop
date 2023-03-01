/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef LEVEL_NAME_LOGGER_SOURCE
#define LEVEL_NAME_LOGGER_SOURCE

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/level_name_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"

//
// CAUTION! This logger uses some CYBOI functions so that
// an ENDLESS LOOP might occur, if those functions call
// the logger in turn.
//
// In order to avoid circular references, cyboi functions
// used by the logger are NOT permitted to use the logger.
//

//
// Forward declarations
//

void compare_integer_equal(void* p0, void* p1, void* p2);
void copy_integer(void* p0, void* p1);
void copy_pointer(void* p0, void* p1);

/**
 * Gets the log level name.
 *
 * @param p0 the log level name (pointer reference)
 * @param p1 the log level name count
 * @param p2 the log level
 */
void log_level_name(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) DEBUG_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) DEBUG_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) ERROR_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &ERROR_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) ERROR_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) INFORMATION_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) WARNING_LEVEL_LOG_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_pointer(p0, (void*) &WARNING_LEVEL_NAME_LOG_CYBOI_MODEL);
            copy_integer(p1, (void*) WARNING_LEVEL_NAME_LOG_CYBOI_MODEL_COUNT);
        }
    }
}

/* LEVEL_NAME_LOGGER_SOURCE */
#endif
