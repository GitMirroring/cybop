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

#ifndef HIERARCHY_FIELD_XDT_SELECTOR_SOURCE
#define HIERARCHY_FIELD_XDT_SELECTOR_SOURCE

//
// Executable interface
//

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/representer/deserialiser/xdt/part_record_xdt_deserialiser.c"
#include "../../../executor/mover/mover.c"
#include "../../../logger/logger.c"

//
// Forbidden includes
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "../../../../executor/representer/deserialiser/xdt/record_xdt_deserialiser.c"

//
// Forward declarations
//

void deserialise_xdt_record(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Selects the xdt field hierarchy.
 *
 * A comparison of the field hierarchy and current tree level
 * is especially needed for free self-defined records and fields,
 * since for those no types are defined in the xdt standard.
 *
 * @param p0 the destination parent properties item
 * @param p1 the destination part properties item
 * @param p2 the current tree level
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 * @param p5 the field content data
 * @param p6 the field content count
 * @param p7 the field identification
 * @param p8 the field dependency hierarchy
 * @param p9 the field size
 * @param p10 the bdt standard main version
 */
void select_xdt_field_hierarchy(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt field hierarchy.");

    // The next lower tree level.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The new part properties item.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Initialise next lower tree level.
    copy_integer((void*) &l, p2);
    // Calculate next lower tree level.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    fwprintf(stdout, L"Debug: select xdt field hierarchy current level: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: select xdt field hierarchy next lower level: %i\n", l);
    fwprintf(stdout, L"Debug: select xdt field hierarchy dependency hierarchy: %i\n", *((int*) p8));

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, p2);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The field is on the same tree level.
            //

            //
            // Create new part.
            //
            // CAUTION! Hand over parent properties item p0 as parent parametre.
            //
            // CAUTION! Do NOT hand over the null pointer constant as last parametre like:
            // deserialise_xdt_record_part(p0, p5, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL);
            //
            // The reason is that it might get changed inside the called function, e.g. p4 in:
            // copy_pointer(p4, (void*) &pp);
            //
            // But then, errors might occur and programme execution fail,
            // since many variables are compared against the null pointer.
            //
            deserialise_xdt_record_part(p0, p5, p6, p7, (void*) &p);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT use the "compare_integer_greater" function here.
        // This comparison is to filter out ONLY nodes which are ONE level lower.
        // Other nodes which are yet lower should not appear and would be erroneous.
        // Those are filtered out in the last branch further below.
        //
        compare_integer_equal((void*) &r, p8, (void*) &l);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The field is one tree level lower.
            //

            //
            // Create new part.
            //
            // CAUTION! Hand over part properties item p1 as new parent parametre.
            //
            deserialise_xdt_record_part(p1, p5, p6, p7, (void*) &p);

            //
            // Increment current tree level.
            // An alternative could be to assign to it the field hierarchy.
            //
            calculate_integer_add(p2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

            //
            // Deserialise fields following this field recursively.
            //
            // CAUTION! Hand over part properties item p1 as new parent parametre.
            //
            // CAUTION! Also, hand over NEW part properties item p as POTENTIAL new parent parametre.
            //
            deserialise_xdt_record(p1, p, p2, p3, p4, p10);

            // Decrement current tree level.
            calculate_integer_subtract(p2, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &r, p8, p2);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This field belongs to a higher tree level (parent or higher)
            // and must NOT be added to the current parent part.
            //

            //
            // Reset data position and count remaining BACKWARD to
            // the beginning of the field last read by using its size.
            //
            // CAUTION! Reading the next field ("peeking ahead") is necessary
            // in order to find out about its dependency hierarchy level and type.
            // Only this way, the end of the current record can be detected.
            // This is not very convenient and efficient, but the only way
            // in which this is possible when processing xdt data.
            //
            move(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p9, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The field is more than one level below the current node.
        // There is a gap in the hierarchy.
        // This should not happen.
        // Presumably, a field hierarchy value is wrong.
        // Therefore, ignore field and just do nothing.
        //

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt field hierarchy. The hierarchy is more than one level below the current one.");
        fwprintf(stdout, L"Warning: Could not select xdt field hierarchy. The hierarchy is more than one level below the current one. field dependency hierarchy p8: %i\n", p8);
        fwprintf(stdout, L"Warning: Could not select xdt field hierarchy. The hierarchy is more than one level below the current one. field dependency hierarchy *p8: %i\n", *((int*) p8));
    }
}

/* HIERARCHY_FIELD_XDT_SELECTOR_SOURCE */
#endif
