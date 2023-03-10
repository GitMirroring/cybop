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

#ifndef VALUE_MANIPULATOR_SOURCE
#define VALUE_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/manipulator/character_manipulator.c"
#include "../../executor/manipulator/integer_manipulator.c"
#include "../../logger/logger.c"

/**
 * Manipulates the bit at the given position.
 *
 * @param p0 the value
 * @param p1 the bit position
 * @param p2 the operation type
 * @param p3 the operand type
 */
void manipulate_value(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p3;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate value.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // number
        //

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *BYTE_NUMBER_STATE_CYBOI_TYPE) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *INTEGER_NUMBER_STATE_CYBOI_TYPE) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_integer(p0, p1, p2);
            }
        }

        //
        // text
        //

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *CHARACTER_TEXT_STATE_CYBOI_TYPE) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character(p0, p1, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate value. The operand type is unknown.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate value. The operand type is null.");
    }
}

/* VALUE_MANIPULATOR_SOURCE */
#endif
