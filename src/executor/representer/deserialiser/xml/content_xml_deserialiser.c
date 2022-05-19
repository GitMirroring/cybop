/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONTENT_XML_DESERIALISER_SOURCE
#define CONTENT_XML_DESERIALISER_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/selector/xml/content_xml_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the xml element content.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the normalisation flag
 * @param p5 the part type
 */
void deserialise_xml_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml content.");

    // The content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The normalisation comparison result.
    int r2 = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise content data.
    copy_pointer((void*) &cd, p2);
    // Check if destination model item type is string.
    compare_integer_equal((void*) &r, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Check if normalisation flag is set.
    // CAUTION! Do NOT use "equal" comparison, since standalone client has to be the DEFAULT.
    // compare_integer_unequal((void*) &r, p12, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    compare_integer_unequal((void*) &r2, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_xml_content(p0, p1, (void*) &b, p2, p3);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a string xml element.
            //

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The end tag of the xml element has been reached.
                //

                if (r2 != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //
                    // The normalisation flag IS set.
                    //

                    //
                    // Overwrite destination model item.
                    //
                    // CAUTION! The function "normalise" gets called inside.
                    // It removes leading and trailing whitespaces as well as
                    // line breaks and merges multiple ones into just ONE,
                    // before writing the string into the destination.
                    //
                    modify_item(p0, cd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &cc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NORMALISE_MODIFY_LOGIC_CYBOI_FORMAT);

                } else {

                    //
                    // The normalisation flag is NOT set.
                    //

                    // Overwrite destination model item with
                    // source data WITHOUT normalising.
                    modify_item(p0, cd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &cc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
                }

                break;

            } else {

                // Increment content count.
                cc++;
            }
        }
    }
}

/* CONTENT_XML_DESERIALISER_SOURCE */
#endif
