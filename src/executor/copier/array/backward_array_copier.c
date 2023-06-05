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
 * Copies source- into destination array,
 * starting from the given offset.
 *
 * This is the BACKWARD version.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
 */
void copy_array_backward(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! These null pointer comparisons are IMPORTANT, in order to
    // avoid a system crash if one or both of the two arrays are null!
    // All other copying functions are based on this copier function,
    // so that checking for null pointer right here suffices.
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy array backward.");

            //
            // The destination array, source array.
            //
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            //
            void* d = p0;
            void* s = p1;

            add_offset((void*) &d, p2, p5);
            add_offset((void*) &s, p2, p6);

            copy_array_elements_backward(d, s, p2, p3, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array backward. The destination array is null.");
            fwprintf(stdout, L"Error: Could not copy array forward. The destination array is null. p0: %i\n", p0);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy array backward. The source array is null.");
        fwprintf(stdout, L"Error: Could not copy array forward. The source array is null. p1: %i\n", p1);
    }
}
