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

#ifndef CHARACTER_MANIPULATOR_SOURCE
#define CHARACTER_MANIPULATOR_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/manipulator/character/check_character_manipulator.c"
#include "../../executor/manipulator/character/clear_character_manipulator.c"
#include "../../executor/manipulator/character/rotate_left_character_manipulator.c"
#include "../../executor/manipulator/character/rotate_right_character_manipulator.c"
#include "../../executor/manipulator/character/set_character_manipulator.c"
#include "../../executor/manipulator/character/shift_left_character_manipulator.c"
#include "../../executor/manipulator/character/shift_right_character_manipulator.c"
#include "../../executor/manipulator/character/toggle_character_manipulator.c"
#include "../../logger/logger.c"

/**
 * Manipulates the character value bit at the given position.
 *
 * @param p0 the value
 * @param p1 the bit position
 * @param p2 the operation type
 */
void manipulate_character(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate character.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_check(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_clear(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_rotate_left(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_rotate_right(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SET_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_set(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_shift_left(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_shift_right(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (*t == *TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT) {

                r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                manipulate_character_toggle(p0, p1);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate character. The operation type is unknown.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate character. The operation type is null.");
    }
}

/* CHARACTER_MANIPULATOR_SOURCE */
#endif
