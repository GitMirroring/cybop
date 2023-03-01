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

#ifndef SHIFT_LEFT_CHARACTER_MANIPULATOR_SOURCE
#define SHIFT_LEFT_CHARACTER_MANIPULATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Shifts all bits of value to the left by position.
 *
 * @param p0 the value
 * @param p1 the position
 */
void manipulate_character_shift_left(void* p0, void* p1) {

    //
    // CAUTION! Use "unsigned char" with range 0..+255
    // and NOT just "char" with range -128..+127 here.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* p = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            unsigned char* v = (unsigned char*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate character shift left.");

            *v = *v << (*p);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate character shift left. The value is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not manipulate character shift left. The position is null.");
    }
}

/* SHIFT_LEFT_CHARACTER_MANIPULATOR_SOURCE */
#endif
