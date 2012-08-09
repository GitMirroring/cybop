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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_HTML_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_HTML_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/web_user_interface/tag_web_user_interface_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/representer/serialiser/html/begin_tag_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/empty_tag_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/end_tag_html_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_html(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_html_part(void* p0, void* p1, void* p2, void* p3);

/**
 * Serialises the part element content into html.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the indentation level
 * @param p6 the format
 */
void serialise_html_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise html part element content.");

    // The tag part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The tag part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The tag part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The empty flag.
    int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The compound flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get tag part by name.
    get_name_array((void*) &t, p3, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
    // Get tag part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get tag part model item data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Check if content is empty and if this tag is allowed
    // to be an empty tag, following the html specification.
    serialise_html_empty_tag((void*) &e, tmd, tmc, p2);

    // Serialise indentation.
    serialise_html_indentation(p0, p5);
    // Append begin tag.
    serialise_html_begin_tag(p0, tmd, tmc, p3, p4, (void*) &e);
    // Append line feed character, for better source reading.
    append_item_element(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    if (e == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The content is NOT empty, since the empty flag is false.

        // Check if this part is of type "element/part".
        // In this case, it is a compound part containing child parts
        // and not just primitive data like text or a number.
        compare_integer_equal((void*) &c, p6, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        // The new indentation level.
        //
        // CAUTION! Do NOT manipulate the original indentation level
        // that was handed over as parametre! Otherwise, it would never
        // get decremented anymore leading to wrong indentation.
        int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise new indentation level with current one.
        copy_integer((void*) &l, p5);
        // Increment new indentation level by one.
        calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        if (c == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The content of compound parts gets
            // indented inside the called function stack:
            // - serialise_html
            // - serialise_html_part
            // - serialise_html_part_element
            // - serialise_html_part_element_content
            //
            // However, this is NOT the case for primitive values like a text or number.
            // Therefore, those have to get indented right here.

            // Serialise indentation.
            serialise_html_indentation(p0, (void*) &l);
        }

        // Append part model.
        serialise_html(p0, p1, p2, p3, p4, (void*) &l, p6);

        if (c == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! The content of compound parts gets
            // added a line break inside the called function stack:
            // - serialise_html
            // - serialise_html_part
            // - serialise_html_part_element
            // - serialise_html_part_element_content
            //
            // However, this is NOT the case for primitive values like a text or number.
            // Therefore, those have to get added a line break right here.

            // Append line feed character, for better source reading.
            append_item_element(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }

        // Serialise indentation.
        // CAUTION! Use original indentation that was handed over as parametre.
        serialise_html_indentation(p0, p5);
        // Append end tag.
        serialise_html_end_tag(p0, tmd, tmc);
        // Append line feed character, for better source reading.
        append_item_element(p0, (void*) LINE_FEED_CONTROL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* CONTENT_ELEMENT_PART_HTML_SERIALISER_SOURCE */
#endif
