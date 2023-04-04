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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef GREATER_POINTER_COMPARATOR_SOURCE
#define GREATER_POINTER_COMPARATOR_SOURCE

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"

/**
 * Compares the left- with the right pointer for greaterness.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_pointer_greater(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** rv = (void**) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** lv = (void**) p1;

            // CAUTION! Do NOT call the logger here.
            // It might use functions that cause circular references.

            if (*lv > *rv) {

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

/* GREATER_POINTER_COMPARATOR_SOURCE */
#endif
