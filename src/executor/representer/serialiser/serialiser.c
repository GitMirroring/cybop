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

#ifndef SERIALISER_SOURCE
#define SERIALISER_SOURCE

#include "../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/html/document_type_html_model.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../executor/representer/serialiser/binary_crlf/binary_crlf_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/cybol_serialiser.c"
#include "../../../executor/representer/serialiser/gui/initial_gui_serialiser.c"
//
// CAUTION! Do NOT include the "content_element_part_html_serialiser.c" module.
// It is true, the "serialise_html_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
//
// Therefore, the "html_serialiser.c" module is included here.
//
#include "../../../executor/representer/serialiser/html/html_serialiser.c"
#include "../../../executor/representer/serialiser/http_request/http_request_serialiser.c"
#include "../../../executor/representer/serialiser/http_response/http_response_serialiser.c"
//
// CAUTION! Do NOT include the "part_json_serialiser.c" module.
// It is true, the "serialise_json_part" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
//
// Therefore, the "json_serialiser.c" module is included here.
//
#include "../../../executor/representer/serialiser/json/json_serialiser.c"
#include "../../../executor/representer/serialiser/latex/latex_serialiser.c"
//
// CAUTION! Do NOT include the "content_element_part_model_diagram_serialiser.c" module.
// It is true, the "serialise_model_diagram_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
//
// Therefore, the "model_diagram_serialiser.c" module is included here.
//
#include "../../../executor/representer/serialiser/model_diagram/model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/terminal_mode/terminal_mode_serialiser.c"
#include "../../../executor/representer/serialiser/tui/initial_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/primitive_tui_serialiser.c"
//?? #include "../../../executor/representer/serialiser/xdt_field_description/xdt_field_description_serialiser.c"
#include "../../../executor/representer/serialiser/xdt/xdt_serialiser.c"
//
// CAUTION! Do NOT include the "content_element_part_xml_serialiser.c" module.
// It is true, the "serialise_xml_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
//
// Therefore, the "xml_serialiser.c" module is included here.
//
//
// CAUTION! The xml serialiser is used e.g. in the cybol serialiser.
// Therefore, do NOT delete this include, even if the xml serialiser
// is possibly not called directly below.
//
#include "../../../executor/representer/serialiser/xml/xml_serialiser.c"

/**
 * Serialises the source into the destination, according to the given language.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source channel
 * @param p4 the source encoding
 * @param p5 the source language
 * @param p6 the indentation flag
 * @param p7 the source format
 * @param p8 the source type
 * @param p9 the source model data
 * @param p10 the source model count
 * @param p11 the source properties data
 * @param p12 the source properties count
 * @param p13 the clear flag
 * @param p14 the newline flag
 * @param p15 the knowledge memory part (pointer reference)
 * @param p16 the stack memory item
 * @param p17 the internal memory data
 * @param p18 the destination device identification item, currently only needed for gui window id
 */
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise.");

    //
    // The functions below are for STATE models only.
    //
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // application
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) JSON_APPLICATION_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The tree level.
            //
            // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the tree level value gets changed in the following functions!
            //
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // CAUTION! Only the part's model gets serialised here.
            //
            // For easy handling and storage, the root parts to be serialised
            // should NOT contain properties.
            //
            // However, if a root part's properties are to be serialised anyway,
            // then they have to be treated as separate part and get stored
            // in a SEPARATE FILE.
            //

            serialise_json_part(p0, p9, p10, p6, (void*) &l);

            // Append line feed.
            modify_item(p0, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BINARY_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A translation is NOT necessary.
            // The data are forwarded as they are.
            //

            modify_item(p0, p9, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p10, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BINARY_CRLF_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_binary_crlf(p0, p9, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CLI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Serialise data and encode them as utf-8 multibyte character sequence.
            serialise_tui_primitive(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p9, p10, p11, p12, p7);

            // Append newline.
            serialise_tui_newline(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p14, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GUI_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The destination window identification item data.
            void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get destination window identification item data.
            copy_array_forward((void*) &w, p18, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            serialise_gui_initial(w, p9, p10, p11, p12, p15, p16, p17, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_http_request(p0, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_http_response(p0, p9, p10, p11, p12, p15, p16, p17);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_tui_initial(p0, p9, p10, p11, p12, p15, p16, p17, p13, p14, p7);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_MODE_NUMBER_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_terminal_mode(p0, p9, p10, p11, p12, p7);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_authority(p0, p9, p10, p11);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_xdt(p0, p9, p10, p11, p12, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_xdt(p0, p9, p10, p11, p12, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The indentation level.
            //
            // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the indentation level value gets changed in the following functions!
            //
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The indentation flag part.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The indentation flag part model item.
            void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The indentation flag part model item data.
            void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Append content.
            serialise_html_part_element_content(p0, p9, p10, p11, p12, p6, (void*) &l, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_xdt(p0, p9, p10, p11, p12, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The tree level.
            //
            // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the tree level value gets changed in the following functions!
            //
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            serialise_model_diagram_part_element_content(p0, (void*) L"[selected_node]", (void*) NUMBER_15_INTEGER_STATE_CYBOI_MODEL, p7, p9, p10, p11, p12, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &l);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) URI_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? serialise_uri(p0, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            //?? TODO: Uncomment this later again!
            //
            // It is already implemented, but too large (4 MiB),
            // so that compilation takes much too long.
            // The xDT de-/serialisation should be moved
            // into a library in the future.
            //
            //?? serialise_xdt_field_description(p0, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise. The language is unknown or null.");
    }
}

/* SERIALISER_SOURCE */
#endif
