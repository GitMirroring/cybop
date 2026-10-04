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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "xdt.h"

/**
 * Deserialises xdt field part.
 *
 * @param p0 the destination item
 * @param p1 the field identification data
 * @param p2 the field identification count
 * @param p3 the field content data
 * @param p4 the field content count
 * @param p5 the language properties (constraints) data
 * @param p6 the language properties (constraints) count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the field identification as integer number
 */
void deserialise_xdt_field_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt field part.");

    // The field format.
    int f = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The field type.
    int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Deserialise field identification into field format.
    deserialise_xdt_field_format((void*) &f, p10);
    //
    // Deserialise field format into cyboi runtime type.
    // It is needed for allocating the new part.
    //
    deserialise_xdt_field_type((void*) &t, (void*) &f);

    if (f != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

        if (t != *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

            //
            // Allocate part.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            // CAUTION! Use the cyboi runtime type determined above
            // (NOT the xdt format)!
            //
            allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);

            //
            // Get part model item.
            //
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            //
            copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

            // Fill part.
            modify_part(p, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
            modify_part(p, (void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
            modify_part(p, (void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

            // Deserialise language properties constraints.
            deserialise_xdt_field_constraints(pm, p3, p4, p5, p6, p7, p8, p9, (void*) &f);

            //
            // Add part to destination.
            //
            // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
            // This is necessary in order to activate rubbish (garbage) collection.
            //
            modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field part. The field type is invalid.");
            // CAUTION! An invalid type would lead to an allocation error.
            fwprintf(stdout, L"Could not deserialise xdt field part. The field type is invalid: %i\n", t);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt field part. The field format is invalid.");
        // CAUTION! An invalid format would lead to an allocation error.
        fwprintf(stdout, L"Could not deserialise xdt field part. The field format is invalid: %i\n", f);
    }
}
