/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PRIMITIVE_FILLED_ELEMENT_PART_HTML_SERIALISER_SOURCE
#define PRIMITIVE_FILLED_ELEMENT_PART_HTML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/character_reference/character_reference_serialiser.c"
#include "../../../../executor/representer/serialiser/html/break_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/indentation_html_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_html(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Serialises the primitive filled part element into html.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the indentation flag
 * @param p4 the indentation level
 * @param p5 the format
 * @param p6 the preformatted data
 */
void serialise_html_part_element_filled_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise html part element filled primitive.");

    // This is a primitive value, NOT a compound element.
    // Example:
    // <p>
    //     some text
    // </p>

    // CAUTION! If this is NOT a preformatted element,
    // then the preformatted property may NOT be given
    // so that the corresponding flag is NULL.
    // Or, the flag IS given, but was set to FALSE.
    if ((p6 == *NULL_POINTER_STATE_CYBOI_MODEL) || ((p6 != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) p6) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

        // This is a primitive value, NOT a compound element.
        // Further, this is NOT a preformatted element.
        // Example:
        // <p>
        //     some text
        // </p>

        // CAUTION! The content of compound parts gets
        // indented inside the called function stack:
        // - serialise_html
        // - serialise_html_part
        // - serialise_html_part_element
        // - serialise_html_part_element_content
        //
        // However, this is NOT the case for primitive values like a text or number.
        // Therefore, those have to get indented right here.
        //
        // But for preformatted elements an indentation is NOT wanted,
        // since it represents a block of text in which structure is
        // represented by typographic conventions rather than by elements.

        // Serialise indentation.
        serialise_html_indentation(p0, p3, p4);
    }

    // Append part model.

    // The numeric character reference item.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The numeric character reference item data, count.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate numeric character reference item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    // CAUTION! Use the source count as initial size, since
    // the destination will have at least the same, if not
    // a greater size if numeric character references are inserted.
    allocate_item((void*) &r, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise primitive value, e.g. a date, number or arbitrary text.
    serialise_html(r, p1, p2, p3, p4, p5);

    // Get numeric character reference item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &rc, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Replace reserved characters/ predefined entities with
    // their corresponding numeric character reference.
    serialise_character_reference(p0, rd, rc, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

    // Deallocate numeric character reference item.
    deallocate_item((void*) &r, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // This is a primitive value, NOT a compound element.
    // Example:
    // <p>
    //     some text
    // </p>

    // CAUTION! The content of compound parts gets
    // added a line break inside the called function stack:
    // - serialise_html
    // - serialise_html_part
    // - serialise_html_part_element
    // - serialise_html_part_element_content
    //
    // However, this is NOT the case for primitive values like a text or number.
    // Therefore, those have to get added a line break right here.

    // Serialise line break.
    serialise_html_break(p0, p3);
}

/* PRIMITIVE_FILLED_ELEMENT_PART_HTML_SERIALISER_SOURCE */
#endif
