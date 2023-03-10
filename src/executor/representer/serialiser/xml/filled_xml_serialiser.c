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

#ifndef FILLED_XML_SERIALISER_SOURCE
#define FILLED_XML_SERIALISER_SOURCE

//
// Executable interface
//

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/serialiser/xml/break_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/end_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/primitive_xml_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forbidden includes
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "../../../../executor/representer/serialiser/xml/xml_serialiser.c"

//
// Forward declarations
//

void serialise_xml(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);

/**
 * Serialises the filled part element into xml.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the sign flag
 * @param p4 the number base
 * @param p5 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p6 the decimal separator data
 * @param p7 the decimal separator count
 * @param p8 the decimal places
 * @param p9 the scientific notation flag
 * @param p10 the tag data
 * @param p11 the tag count
 * @param p12 the preformatted data
 * @param p13 the indentation flag
 * @param p14 the indentation level
 * @param p15 the void flag
 * @param p16 the format
 */
void serialise_xml_filled(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml filled.");

    // The compound flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The new indentation level.
    //
    // CAUTION! Do NOT manipulate the original indentation level
    // that was handed over as parametre! Otherwise, it would never
    // get decremented anymore leading to wrong indentation.
    //
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Test if this part is of type "element/part".
    //
    // In this case, it is a compound part containing child parts
    // and not just primitive data like text or a number.
    //
    compare_integer_equal((void*) &c, p16, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);
    // Initialise new indentation level with current one.
    copy_integer((void*) &l, p14);
    // Increment new indentation level by one.
    calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (c == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        serialise_xml_primitive(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p13, (void*) &l, p15, p16, p12);

    } else {

        serialise_xml(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p13, (void*) &l, p15, p16);
    }

    //
    // Serialise indentation.
    //
    // CAUTION! Use original indentation that was handed over as parametre.
    //
    serialise_xml_indentation(p0, p13, p14);
    // Append end tag.
    serialise_xml_end(p0, p10, p11);
    // Serialise line break.
    serialise_xml_break(p0, p13);
}

/* FILLED_XML_SERIALISER_SOURCE */
#endif
