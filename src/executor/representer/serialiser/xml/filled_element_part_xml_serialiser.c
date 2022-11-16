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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FILLED_ELEMENT_PART_XML_SERIALISER_SOURCE
#define FILLED_ELEMENT_PART_XML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/xml/break_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/end_tag_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/primitive_xml_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations
//

void serialise_xml(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Serialises the filled part element into xml.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the tag data
 * @param p4 the tag count
 * @param p5 the preformatted data
 * @param p6 the indentation flag
 * @param p7 the indentation level
 * @param p8 the void flag
 * @param p9 the format
 */
void serialise_xml_part_element_filled(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml part element filled.");

    // The compound flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The new indentation level.
    //
    // CAUTION! Do NOT manipulate the original indentation level
    // that was handed over as parametre! Otherwise, it would never
    // get decremented anymore leading to wrong indentation.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Test if this part is of type "element/part".
    // In this case, it is a compound part containing child parts
    // and not just primitive data like text or a number.
    compare_integer_equal((void*) &c, p9, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);
    // Initialise new indentation level with current one.
    copy_integer((void*) &l, p7);
    // Increment new indentation level by one.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (c == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        serialise_xml_primitive(p0, p1, p2, p6, (void*) &l, p8, p9, p5);

    } else {

        serialise_xml(p0, p1, p2, p6, (void*) &l, p8, p9);
    }

    // Serialise indentation.
    // CAUTION! Use original indentation that was handed over as parametre.
    serialise_xml_indentation(p0, p6, p7);
    // Append end tag.
    serialise_xml_end_tag(p0, p3, p4);
    // Serialise line break.
    serialise_xml_break(p0, p6);
}

/* FILLED_ELEMENT_PART_XML_SERIALISER_SOURCE */
#endif
