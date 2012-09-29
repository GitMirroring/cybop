/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_RECORD_XDT_DESERIALISER_SOURCE
#define ELEMENT_RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises an xdt record element.
 *
 * @param p0 the record size (pointer reference)
 * @param p1 the record identification (pointer reference)
 * @param p2 the record data (pointer reference)
 * @param p3 the record count (pointer reference)
 * @param p4 the source data (pointer reference)
 * @param p5 the source count
 */
void deserialise_xdt_record_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record element.");

    // The field content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field dependency hierarchy.
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field size.
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The next tree level.
    int ln = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    deserialise_xdt_field((void*) &cd, (void*) &cc, (void*) &i, (void*) &h, (void*) &s, pos, rem);

    //
    // This comparison of the current and old field hierarchy
    // is especially needed for free-self-defined records and fields
    // since for those no types are defined in the xdt standard.
    //
    // All fields listed in the xdt standard have a defined type.
    // Each field id may be assigned a type as constant, following the xdt standard.
    // This type constant my be e.g. integer or element/part (compound)
    // and be used for creating the new part representing the field.
    //

    // Calculate next lower tree level.
    calculate_integer_add((void*) &ln, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) &h, px_current_tree_level);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_record_element_part();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, (void*) &h, (void*) &ln);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt_record_element_part();

            // Increment current tree level.
            // An alternative could be to assign to it the field hierarchy.
            calculate_integer_add(px, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            // Deserialise child fields of this record recursively.
            // Hand over new part as parent parametre.
            deserialise_xdt_record();

            // Decrement current tree level.
            calculate_integer_add(px, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller((void*) &r, (void*) &h, px_current_tree_level);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // This field belongs to a higher record level
            // and must NOT be added to the current parent part.

            // Set break flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Reset data position and count remaining BACKWARD to
            // the beginning of the field last read by using its size.
            //
            // CAUTION! Reading the next field ("peeking ahead") is necessary
            // in order to find out about its dependency hierarchy level and type.
            // Only this way, the end of the current record can be detected.
            // This is not very convenient and efficient, but the only way
            // in which this is possible when processing xdt data.
            move_position(p1, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &s, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Ignore field if there is a gap in the hierarchy,
        // i.e. the field hierarchy is more than one level
        // below the current node.

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xdt record element. The field hierarchy is more than one level below the current one.");
    }
--
    deserialise_xdt_record_element_part() {
        determine field type using field id; DEFINE constants in new file assigning a type constant like INTEGER_TYPE to an xdt field id, for all possible xdt fields
        allocate new part using field type
        if (field_type == compound) {
            // This is a compound part.
            // Copy field content to part NAME.
            copy field content to part's NAME (not model)
        } else {
            // This is a primitive part.
            // Copy field content to part MODEL.
            copy field content to part's MODEL (not name)
        }
        add part to parent
    }
--
    select_xdt_record(p0, p1, p2, fc, (void*) &fcc, (void*) &fid);
    select_xdt_record_end(p0, p1, (void*) &b, p2, p3);
}

/* ELEMENT_RECORD_XDT_DESERIALISER_SOURCE */
#endif
