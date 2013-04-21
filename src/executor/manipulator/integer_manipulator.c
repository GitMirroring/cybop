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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef INTEGER_MANIPULATOR_SOURCE
#define INTEGER_MANIPULATOR_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/manipulator/basic/integer/equal_integer_manipulator.c"
#include "../../../executor/manipulator/basic/integer/greater_integer_manipulator.c"
#include "../../../executor/manipulator/basic/integer/greater_or_equal_integer_manipulator.c"
#include "../../../executor/manipulator/basic/integer/smaller_integer_manipulator.c"
#include "../../../executor/manipulator/basic/integer/smaller_or_equal_integer_manipulator.c"
#include "../../../executor/manipulator/basic/integer/unequal_integer_manipulator.c"
#include "../../../logger/logger.c"

/**
 * Manipulates the left- with the right integer.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 * @param p3 the operation type
 */
void manipulate_integer(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* a = (int*) p3;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate integer.");

        // The comparison result.
        // CAUTION! It is used instead of if-else statements.
        // May be one day, this is useful when using assembler or implementing cyboi as hardware chip.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *EQUAL_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_equal(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_greater_or_equal(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *GREATER_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_greater(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_smaller_or_equal(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *SMALLER_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_smaller(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*a == *UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer_unequal(p0, p1, p2);
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
