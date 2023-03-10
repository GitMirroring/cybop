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

#ifndef CLEAR_CHARACTER_MANIPULATOR_SOURCE
#define CLEAR_CHARACTER_MANIPULATOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/logifier/character/and_character_logifier.c"
#include "../../../executor/logifier/character/not_character_logifier.c"
#include "../../../executor/manipulator/character/shift_left_character_manipulator.c"
#include "../../../logger/logger.c"

/**
 * Clears (in other words: resets) the bit at the given position.
 *
 * @param p0 the value
 * @param p1 the position
 */
void manipulate_character_clear(void* p0, void* p1) {

    //
    // CAUTION! Use "unsigned char" with range 0..+255
    // and NOT just "char" with range -128..+127 here.
    //

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Manipulate character clear.");

    // The bit mask.
    unsigned char b = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Prepare bit mask.
    manipulate_character_shift_left((void*) &b, p1);

    // Invert bit mask using NOT operator ~.
    logify_character_not((void*) &b);

    // Apply and.
    logify_character_and(p0, (void*) &b);
}

/* CLEAR_CHARACTER_MANIPULATOR_SOURCE */
#endif
