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
#include "xml.h"

/**
 * Deserialises the xml tag name.
 *
 * @param p0 the destination part name item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the has attribute flag
 * @param p4 the has content flag
 * @param p5 the is empty flag
 */
void deserialise_xml_tag_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml tag name.");

    // The has attribute flag.
    int ha = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The has content flag.
    int hc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The is empty flag.
    int ie = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The tag name data, count.
    void* tnd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int tnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise tag name data.
    copy_pointer((void*) &tnd, p1);

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

            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        if (hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        if (ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

        if ((ha != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (hc != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (ie != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

            //
            // A space character as indicator of subsequent attributes or
            // a tag end character as indicator of subsequent element content or
            // an empty tag end character was detected.
            //

            // Overwrite part name item.
            modify_item(p0, tnd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &tnc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }
    }
}
