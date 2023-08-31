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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"
#include "xdt.h"

/**
 * Deserialises the xdt bdt field.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source record model (fields) data
 * @param p3 the source record model (fields) count
 * @param p4 the source record model (fields) index
 * @param p5 the source record name data
 * @param p6 the source record name count
 * @param p7 the parent field name as integer
 * @param p8 the loop break flag
 */
void deserialise_xdt_bdt_field(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p8;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt bdt field.");

        // The source field part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source field part name, model item.
        void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source field part name, model item data, count.
        void* pnd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pnc = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source field part name as integer.
        int pni = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Get source field part with given index.
        copy_array_forward((void*) &p, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p4);
        // Get source field part name, model item.
        copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get source field part name, model item data, count.
        copy_array_forward((void*) &pnd, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pnc, pn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        // Deserialise source field part name string into integer number.
        deserialise_numeral_integer((void*) &pni, pnd, pnc, (void*) DECIMAL_BASE_NUMERAL_MODEL);

        select_xdt_bdt_field_compound_end(p8, (void*) &pni, p7);

        // CAUTION! The source record model index gets incremented ONLY if
        // the field got processed (selected + deserialised) right above.
        // If the field demarcates the end of a compound field's children,
        // then the source record model index does NOT get incremented,
        // so that the field can be processed once again on a higher level.
        if (*b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Following the xdt standard, the next field IS
            // permitted to be a child of the current compound field.
            // Therefore, it may be deserialised and added.

            // Increment source record model index.
            //
            // CAUTION! It has to be incremented BEFORE
            // deserialising the field below.
            // Otherwise, following fields are not properly
            // sorted into the compound field hierarchy!
            // This is because a wrong next field is identified
            // which seemingly demarcates the end of a compound field,
            // even though it has NOT been reached yet.
            calculate_integer_add(p4, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            // Find out whether this is a simple or compound field.
            // Deserialise field, if compound.
            // Append field to destination.
            select_xdt_bdt_field(p0, p1, p2, p3, p4, p5, p6, (void*) &p, pmd, pmc, pnd, pnc, (void*) &pni);

        } else {

            // Following the xdt standard, the next field is NOT
            // permitted to be a child of the current compound field.
            // Therefore, it demarcates the END of this list of child fields.

            // The break flag was set so that the loop
            // will be left in the next loop cycle.
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt bdt field. The loop break flag is null.");
    }
}
