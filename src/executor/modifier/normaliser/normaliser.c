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

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Normalises the string.
 *
 * It removes leading and trailing whitespaces and additionally
 * replaces ALL internal sequences of whitespace with just ONE.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the type
 */
void normalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** dd = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Normalise.");
        //?? fwprintf(stdout, L"Debug: Normalise. type p5: %i\n", p5);
        //?? fwprintf(stdout, L"Debug: Normalise. type *p5: %i\n", *((int*) p5));

        //
        // CAUTION! The destination is NOT an item, but an array,
        // since this function is called from file "array_modifier.c".
        //

        // Strip leading and trailing whitespaces from the string.
        strip(p0, p1, p2, p3, p4, p5);
        // Normalise string (replace internal sequences of whitespace with just ONE).
        normalise_type(p0, p1, p2, *dd, p1, p5);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not normalise. The destination array is null.");
        fwprintf(stdout, L"Error: Could not normalise. The destination array is null. destination array p0: %i\n", p0);
    }
}
