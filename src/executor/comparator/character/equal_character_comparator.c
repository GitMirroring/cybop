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
// Library interface
//

#include "constant.h"
#include "knowledge.h"

/**
 * Compares the left- with the right character for equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_character_equal(void* p0, void* p1, void* p2) {

    //
    // CAUTION! Use "unsigned char" with range 0..+255
    // and NOT just "char" here.
    // The reason is that this type is most commonly used for
    // characters from 0..255 (ascii extended by iso-8859),
    // for which the simple "char" type with range -128..+127
    // would NOT suffice.
    //

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        unsigned char* rv = (unsigned char*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            unsigned char* lv = (unsigned char*) p1;

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.

            if (*lv == *rv) {

                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It might use functions that cause circular references.
    }
}
