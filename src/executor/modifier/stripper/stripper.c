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

#ifndef STRIPPER_SOURCE
#define STRIPPER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/modifier/stripper/leading_stripper.c"
#include "../../../executor/modifier/stripper/trailing_stripper.c"
#include "logger.h"

/**
 * Removes leading and trailing whitespaces from the string.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the type
 */
void strip(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** dd = (void**) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip.");
        //?? fwprintf(stdout, L"Information: Strip. type p5: %i\n", p5);
        //?? fwprintf(stdout, L"Information: Strip. type *p5: %i\n", *((int*) p5));

        //
        // CAUTION! The destination is NOT an item, but an array,
        // since this function is called from file "array_modifier.c".
        //

        // Strip leading whitespaces from the string.
        strip_leading(p0, p1, p2, p3, p4, p5);
        // Strip trailing whitespaces from the string.
        strip_trailing(p0, p1, p2, *dd, p1, p5);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not strip. The destination array is null.");
        fwprintf(stdout, L"Error: Could not strip. The destination array is null. destination array p0: %i\n", p0);
    }
}

/* STRIPPER_SOURCE */
#endif
