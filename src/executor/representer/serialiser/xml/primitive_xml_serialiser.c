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

#ifndef PRIMITIVE_XML_SERIALISER_SOURCE
#define PRIMITIVE_XML_SERIALISER_SOURCE

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

#include "../../../../executor/representer/serialiser/character_reference/character_reference_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/break_xml_serialiser.c"
#include "../../../../executor/representer/serialiser/xml/indentation_xml_serialiser.c"
#include "logger.h"

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
 * Serialises the primitive filled part element into xml.
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
 * @param p10 the indentation flag
 * @param p11 the indentation level
 * @param p12 the void flag
 * @param p13 the format
 * @param p14 the preformatted data
 */
void serialise_xml_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xml primitive.");

    //
    // This is a primitive value, NOT a compound element.
    //
    // Example:
    //
    // <p>
    //     some text
    // </p>
    //

    //
    // CAUTION! If this is NOT a preformatted element,
    // then the preformatted property may NOT be given
    // so that the corresponding flag is NULL.
    //
    // Or, the flag IS given, but was set to FALSE.
    //
    if ((p14 == *NULL_POINTER_STATE_CYBOI_MODEL) || ((p14 != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) p14) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

        //
        // This is a primitive value, NOT a compound element.
        // Further, this is NOT a preformatted element.
        //
        // Example:
        //
        // <p>
        //     some text
        // </p>
        //

        //
        // CAUTION! The content of compound parts gets
        // indented inside the called function stack:
        //
        // - serialise_xml
        // - serialise_xml_part
        // - serialise_xml_element
        // - serialise_xml_content
        //
        // However, this is NOT the case for primitive values like a text or number.
        // Therefore, those have to get indented right here.
        //
        // But for preformatted elements an indentation is NOT wanted,
        // since it represents a block of text in which structure is
        // represented by typographic conventions rather than by elements.
        //

        // Serialise indentation.
        serialise_xml_indentation(p0, p10, p11);
    }

    //
    // Append part model.
    //

    // The numeric character reference item.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The numeric character reference item data, count.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate numeric character reference item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    // CAUTION! Use the source count as initial size, since
    // the destination will have at least the same, if not
    // a greater size if numeric character references are inserted.
    //
    allocate_item((void*) &r, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise primitive value, e.g. a date, number or arbitrary text.
    serialise_xml(r, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);

    //
    // Get numeric character reference item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rc, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Replace reserved characters/predefined entities with
    // their corresponding numeric character reference.
    //
    serialise_character_reference(p0, rd, rc, (void*) XML_APPLICATION_STATE_CYBOI_LANGUAGE);

    // Deallocate numeric character reference item.
    deallocate_item((void*) &r, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // This is a primitive value, NOT a compound element.
    //
    // Example:
    //
    // <p>
    //     some text
    // </p>
    //

    //
    // CAUTION! The content of compound parts gets
    // added a line break inside the called function stack:
    //
    // - serialise_xml
    // - serialise_xml_part
    // - serialise_xml_part_element
    // - serialise_xml_content
    //
    // However, this is NOT the case for primitive values like a text or number.
    // Therefore, those have to get added a line break right here.
    //

    // Serialise line break.
    serialise_xml_break(p0, p10);
}

/* PRIMITIVE_XML_SERIALISER_SOURCE */
#endif
