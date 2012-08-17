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
#include "../../../../executor/representer/serialiser/character_reference/character_reference_serialiser.c"
#include "../../../../executor/representer/serialiser/html/begin_tag_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/break_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/end_tag_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/indentation_html_serialiser.c"
#include "../../../../executor/representer/serialiser/html/void_element_html_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_html(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);

/**
 * Serialises the part element content into html.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the formatting flag
 * @param p6 the indentation level
 * @param p7 the format
 */
void serialise_html_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise html part element content.");

    // The tag part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The tag part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part model.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The tag part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The preformatted part model data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The empty flag.
    int e = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The void flag.
    int v = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The compound flag.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get tag part by name.
    get_name_array((void*) &t, p3, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME, (void*) TAG_WEB_USER_INTERFACE_CYBOL_NAME_COUNT, p4);
    // Get preformatted part by name.
    get_name_array((void*) &p, p3, (void*) PREFORMATTED_WEB_USER_INTERFACE_CYBOL_NAME, (void*) PREFORMATTED_WEB_USER_INTERFACE_CYBOL_NAME_COUNT, p4);

    // Get tag part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get preformatted part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get tag part model item data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get preformatted part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // TEST: This block is NOT necessary and for testing only.
    // The generated html file will contain an error message for each nameless tag.
    if ((tmd == *NULL_POINTER_STATE_CYBOI_MODEL) || (tmc == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        tmd = (void*) L"ERROR_MISSING_TAG_NAME";
        int* tmc_tmp = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;
        tmc = (void*) tmc_tmp;
    }

    // Test if source model count is empty.
    compare_integer_smaller_or_equal((void*) &e, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    // Test if element is allowed to be void.
    serialise_html_void_element((void*) &v, tmd, tmc);
    // Serialise indentation.
    serialise_html_indentation(p0, p5, p6);
    // Append begin tag.
    serialise_html_begin_tag(p0, tmd, tmc, p3, p4, (void*) &e, (void*) &v);
    // Serialise line break.
    serialise_html_break(p0, p5);

    if (e != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The content IS empty.

        if (v != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // This element IS allowed to be void, following the html specification.
            // It may therefore be represented as empty tag.
            //
            // Example:
            // <img/>

            // NOTHING is to be done here.
            // The compiler will remove this block, since it is empty.
            // So, no need to worry about memory or bad performance.

        } else {

            // This element is NOT allowed to be void, following the html specification.
            // It therefore has to be represented with opening and closing tag.
            //
            // Example:
            // <div>
            // </div>

            // Serialise indentation.
            // CAUTION! Use original indentation that was handed over as parametre.
            serialise_html_indentation(p0, p5, p6);
            // Append end tag.
            serialise_html_end_tag(p0, tmd, tmc);
            // Serialise line break.
            serialise_html_break(p0, p5);
        }

    } else {

        // The content is NOT empty.

        // Test if this part is of type "element/part".
        // In this case, it is a compound part containing child parts
        // and not just primitive data like text or a number.
        compare_integer_equal((void*) &c, p7, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        // The new indentation level.
        //
        // CAUTION! Do NOT manipulate the original indentation level
        // that was handed over as parametre! Otherwise, it would never
        // get decremented anymore leading to wrong indentation.
        int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise new indentation level with current one.
        copy_integer((void*) &l, p6);
        // Increment new indentation level by one.
        calculate_integer_add((void*) &l, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

        if (c == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // This is a primitive value, NOT a compound element.
            // Example:
            // <p>
            //     some text
            // </p>

            // CAUTION! If this is NOT a preformatted element,
            // then the preformatted property may NOT be given
            // so that the pmd flag is NULL.
            // Or, the flag IS given, but has to be set to FALSE.
            if ((pmd == *NULL_POINTER_STATE_CYBOI_MODEL) || ((pmd != *NULL_POINTER_STATE_CYBOI_MODEL) && (*((int*) pmd) == *FALSE_BOOLEAN_STATE_CYBOI_MODEL))) {

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
                serialise_html_indentation(p0, p5, (void*) &l);
            }

            // Append part model.

            // The numeric character reference item.
            void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The numeric character reference item data, count.
            void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* rc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate numeric character reference item.
            // CAUTION! Use the source count as initial size,
            // since the destination will have at least the same size,
            // if not a greater one if numberic character references are inserted.
            allocate_item((void*) &r, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Serialise primitive value, e.g. a date, number or arbitrary text.
            serialise_html(r, p1, p2, p5, (void*) &l, p7);

            // Get numeric character reference item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &rd, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &rc, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Replace reserved characters/ predefined entities with
            // their corresponding numeric character reference.
            serialise_character_reference(p0, rd, rc, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

            // Deallocate numeric character reference item.
            deallocate_item((void*) &r, rc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

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
            serialise_html_break(p0, p5);

        } else {

            serialise_html(p0, p1, p2, p5, (void*) &l, p7);
        }

        // Serialise indentation.
        // CAUTION! Use original indentation that was handed over as parametre.
        serialise_html_indentation(p0, p5, p6);
        // Append end tag.
        serialise_html_end_tag(p0, tmd, tmc);
        // Serialise line break.
        serialise_html_break(p0, p5);
    }
}

/* CONTENT_ELEMENT_PART_HTML_SERIALISER_SOURCE */
#endif
