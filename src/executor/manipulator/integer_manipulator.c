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

#ifndef INTEGER_MANIPULATOR_SOURCE
#define INTEGER_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/manipulator/integer/check_integer_manipulator.c"
#include "../../executor/manipulator/integer/clear_integer_manipulator.c"
#include "../../executor/manipulator/integer/rotate_left_integer_manipulator.c"
#include "../../executor/manipulator/integer/rotate_right_integer_manipulator.c"
#include "../../executor/manipulator/integer/set_integer_manipulator.c"
#include "../../executor/manipulator/integer/shift_left_integer_manipulator.c"
#include "../../executor/manipulator/integer/shift_right_integer_manipulator.c"
#include "../../executor/manipulator/integer/toggle_integer_manipulator.c"
#include "logger.h"

/**
 * Manipulates the integer value bit at the given position.
 *
 * @param p0 the value
 * @param p1 the bit position
 * @param p2 the operation type
 */
void manipulate_integer(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate integer.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_check(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_clear(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_rotate_left(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_rotate_right(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SET_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_set(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_shift_left(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_shift_right(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_toggle(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate integer. The operation type is unknown.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate integer. The operation type is null.");
    }
}

/* INTEGER_MANIPULATOR_SOURCE */
#endif
