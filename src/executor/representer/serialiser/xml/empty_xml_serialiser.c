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

#ifndef EMPTY_XML_SERIALISER_SOURCE
#define EMPTY_XML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/xml/break_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/end_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the empty part element into xml.
 *
 * @param p0 the destination item
 * @param p1 the tag data
 * @param p2 the tag count
 * @param p3 the indentation flag
 * @param p4 the indentation level
 * @param p5 the void flag
 */
void serialise_xml_empty(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml empty.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Two kinds of elements exist.
    //
    // 1 standard
    //
    // It is represented by an opening AND closing tag.
    //
    // Example:
    //
    // <div>
    //     Here is the content of the element.
    // </div>
    //
    // 2 void | empty
    //
    // It is represented by just ONE tag.
    //
    // Example:
    //
    // <img alt="without content, but attributes are possible"/>
    //

    compare_integer_equal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This element is NOT allowed to be void.
        //

        //
        // Serialise indentation.
        //
        // CAUTION! Use original indentation that was handed over as parametre.
        //
        serialise_xml_indentation(p0, p3, p4);
        // Append end tag.
        serialise_xml_end(p0, p1, p2);
        // Serialise line break.
        serialise_xml_break(p0, p3);
    }
}

/* EMPTY_XML_SERIALISER_SOURCE */
#endif
