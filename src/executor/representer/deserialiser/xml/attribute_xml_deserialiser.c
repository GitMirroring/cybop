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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "xml.h"

/**
 * Deserialises the xml attribute.
 *
 * @param p0 the destination properties item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the has content flag
 * @param p4 the is empty flag
 */
void deserialise_xml_attribute(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml attribute.");

    // The attribute name data, count.
    void* and = *NULL_POINTER_STATE_CYBOI_MODEL;
    int anc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The attribute value data, count.
    void* avd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int avc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    //
    // The has attribute flag.
    //
    // CAUTION! This HAS TO BE a local variable, because the function
    // may be called recursively and if the flag were handed over
    // as argument to this function, then it would have an initial value
    // from a previous call of this function, which might lead to wrong results.
    //
    int ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The has content flag.
    int hc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The is empty flag.
    int ie = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The tag name count.
    //
    // CAUTION! This variable is NOT needed in this context,
    // but declared here anyway, since the below function
    // "select_xml_attribute_begin_or_tag_end" expects it.
    //
    int tnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Deserialise xml attribute name and value.
    deserialise_xml_attribute_name(p1, p2, (void*) &and, (void*) &anc);
    deserialise_xml_attribute_value(p1, p2, (void*) &avd, (void*) &avc);

    //
    // Allocate part.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Initialise part.
    modify_part(p, and, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &anc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
    modify_part(p, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    modify_part(p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    //
    // Get part model item.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Assign attribute value to part model.
    deserialise_xml_string(pm, avd, (void*) &avc, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Append part to destination model.
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    //
    modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_xml_attribute_begin_or_tag_end(p1, p2, (void*) &ha, (void*) &hc, (void*) &ie, (void*) &tnc);

        if (ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A space character as indicator of subsequent attributes was detected.
            //

            // Call this function itself recursively.
            deserialise_xml_attribute(p0, p1, p2, (void*) &hc, (void*) &ie);
        }

        if (hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        if (ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        if ((hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

            //
            // A tag end character as indicator of subsequent element content or
            // an empty tag end character was detected.
            //

            break;
        }
    }
}
