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

#ifndef HIERARCHY_FIELD_XDT_SELECTOR_SOURCE
#define HIERARCHY_FIELD_XDT_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../logger/logger.c"

/**
 * Selects the xdt field hierarchy.
 *
 * A comparison of the field hierarchy and current tree level
 * is especially needed for free self-defined records and fields,
 * since for those no types are defined in the xdt standard.
 *
 * @param p0 the parent model item
 * @param p1 the current tree level
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the field content data
 * @param p5 the field content count
 * @param p6 the field identification
 * @param p7 the field dependency hierarchy
 * @param p8 the field size
 * @param p9 the loop break flag
 * @param p10 the compound field flag
 */
void select_xdt_field_hierarchy(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt field hierarchy.");

    // The next lower tree level.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise next lower tree level.
    copy_integer((void*) &l, p1);
    // Calculate next lower tree level.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, p1);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The field is on the same tree level.

            deserialise_xdt_record_part(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller((void*) &r, p7, p1);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // This field belongs to a higher tree level (parent or higher)
            // and must NOT be added to the current parent part.

            // Set break flag.
            copy_integer(p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Reset data position and count remaining BACKWARD to
            // the beginning of the field last read by using its size.
            //
            // CAUTION! Reading the next field ("peeking ahead") is necessary
            // in order to find out about its dependency hierarchy level and type.
            // Only this way, the end of the current record can be detected.
            // This is not very convenient and efficient, but the only way
            // in which this is possible when processing xdt data.
            move_position(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Do NOT use the "compare_integer_greater" function here.
        // This comparison is to filter out ONLY nodes which are ONE level lower.
        // Other nodes which are yet lower should not appear and would be erroneous.
        // Those are filtered out in the last branch further below.
        compare_integer_equal((void*) &r, p7, (void*) &l);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The field is one tree level lower.

            //?? TODO: Remember previous parent node?
            //?? TODO: Is compound field flag and "rolling back" of this field necessary?
            //?? TODO: Needed for finding out of compound type.
            //?? TODO: But for the parent node finding out of type is too late.
            //?? TODO: Therefore, add children to properties item and not model item.
            //?? TODO: Possibly, the last node has to be remembered and forwarded as parametre,
            //?? TODO: in case it has to receive children in its properties.
            //?? TODO: Merge file "compound_part_record_xdt_deserialiser.c" into "part_record_xdt_deserialiser.c" and indicate compound via flag?

            // Reset compound field flag.
            copy_integer(p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            deserialise_xdt_record_part_compound(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The field is more than one level below the current node.
        // There is a gap in the hierarchy.
        // This should not happen.
        // Presumably, a field hierarchy value is wrong.
        // Therefore, ignore field and just do nothing.

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt field hierarchy. The hierarchy is more than one level below the current one.");
    }
}

/* HIERARCHY_FIELD_XDT_SELECTOR_SOURCE */
#endif
