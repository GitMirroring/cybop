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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"

/**
 * Compares the left- with the right wide character for lessness and equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_wide_character_less_or_equal(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wchar_t* rv = (wchar_t*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            wchar_t* lv = (wchar_t*) p1;

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.

            if (*lv <= *rv) {

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
