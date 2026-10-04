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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Selects an xdt record by filtering out the record begin field.
 *
 * @param p0 the destination root model item
 * @param p1 the destination record model item (pointer reference)
 * @param p2 the destination record model item
 * @param p3 the source record part model data (record name as integer, if part is a record)
 * @param p4 the source record part model count
 * @param p5 the source record part name data (field name)
 * @param p6 the source record part name count
 * @param p7 the source record part (pointer reference)
 */
void select_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt record.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The field identification.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Deserialise identification as integer primitive.
    deserialise_numeral_integer((void*) &i, p5, p6, (void*) DECIMAL_BASE_NUMERAL_MODEL);

    // Compare if field represents a record identification.
    compare_integer_equal((void*) &r, (void*) &i, (void*) NUMBER_8000_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // Allocate new record part.
        //
        // CAUTION! The source part may NOT be reused as record part,
        // since the source's model is of type "character",
        // while the new record part's type has to be "part" (compound).
        //
        deserialise_xdt_record_part(p0, p1, p3);

    } else {

        //
        // Append current field part to destination record model item.
        //
        // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
        // This is necessary in order to activate rubbish (garbage) collection (gc).
        //
        modify_item(p2, p7, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    }
}
