/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Adds offset to destination and source.
 *
 * @param p0 the result array, which contains the operand BEFORE the operation
 * @param p1 the operand array
 * @param p2 the operation type
 * @param p3 the operand type
 * @param p4 the count
 * @param p5 the result index
 * @param p6 the operand index
 */
void calculate_array_offset(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! These null pointer comparisons are IMPORTANT,
    // in order to avoid a system crash if parametre values are null!
    //

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate array offset.");

            //
            // The result array, operand array.
            //
            // CAUTION! They HAVE TO BE initialised with p0 and p1,
            // since an offset is added below.
            //
            void* r = p0;
            void* o = p1;

            // Add offset.
            add_offset((void*) &r, p3, p5);
            add_offset((void*) &o, p3, p6);

            calculate_array_elements(r, o, p2, p3, p4);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array offset. The result array (operand before the operation) is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate array offset. The operand array is null.");
    }
}
