/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SERIALISER_SOURCE
#define SERIALISER_SOURCE

#include "../../constant/language/cyboi/state_cyboi_language.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/html/document_type_html_model.c"
#include "../../executor/modifier/appender/item_appender.c"
// CAUTION! Do NOT include the "content_element_part_cybol_serialiser.c" module.
// It is true, the "serialise_cybol_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "cybol_serialiser.c" module is included here.
#include "../../executor/representer/serialiser/cybol/cybol_serialiser.c"
#include "../../executor/representer/serialiser/gui/initial_gui_serialiser.c"
// CAUTION! Do NOT include the "content_element_part_html_serialiser.c" module.
// It is true, the "serialise_html_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "html_serialiser.c" module is included here.
#include "../../executor/representer/serialiser/html/html_serialiser.c"
#include "../../executor/representer/serialiser/http_request/http_request_serialiser.c"
#include "../../executor/representer/serialiser/http_response/http_response_serialiser.c"
#include "../../executor/representer/serialiser/latex/latex_serialiser.c"
// CAUTION! Do NOT include the "content_element_part_model_diagram_serialiser.c" module.
// It is true, the "serialise_model_diagram_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "model_diagram_serialiser.c" module is included here.
#include "../../executor/representer/serialiser/model_diagram/model_diagram_serialiser.c"
#include "../../executor/representer/serialiser/terminal_mode/terminal_mode_serialiser.c"
#include "../../executor/representer/serialiser/tui/initial_tui_serialiser.c"
//?? #include "../../executor/representer/serialiser/xdt_field_description/xdt_field_description_serialiser.c"
#include "../../executor/representer/serialiser/xdt/xdt_serialiser.c"
// CAUTION! Do NOT include the "content_element_part_xml_serialiser.c" module.
// It is true, the "serialise_xml_part_element_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "xml_serialiser.c" module is included here.
//
// CAUTION! The xml serialiser is used e.g. in the cybol serialiser.
// Therefore, do NOT delete this include, even if the xml serialiser
// is not called directly below.
//
//?? TODO: The xml serialiser is not (yet) used here directly,
//?? but will in the future, for general xml files with suffix .xml.
#include "../../executor/representer/serialiser/xml/xml_serialiser.c"

/**
 * Serialises the source into the destination, according to the given language.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source channel data
 * @param p4 the source encoding data
 * @param p5 the source language data
 * @param p6 the source language properties data
 * @param p7 the source language properties count
 * @param p8 the source format data
 * @param p9 the source type data
 * @param p10 the source model data
 * @param p11 the source model count
 * @param p12 the source properties data
 * @param p13 the source properties count
 * @param p14 the clear flag
 * @param p15 the newline flag
 * @param p16 the knowledge memory part
 * @param p17 the internal memory data
 */
void serialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise.");

    // The functions below are for STATE models only.
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BINARY_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            append_item_element(p0, p10, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p11, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CLI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_tui_initial(p0, p10, p11, p12, p13, p16, p17, p14, p15, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_gui_initial(p10, p11, p12, p13, p16, p17, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_http_request(p0, p10, p11, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_http_response(p0, p10, p11, p12, p13, p16);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_tui_initial(p0, p10, p11, p12, p13, p16, p17, p14, p15, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p8);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) TERMINAL_MODE_NUMBER_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_terminal_mode(p0, p10, p11, p12, p13, p8);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_authority(p0, p10, p11, p12);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) BDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_xdt(p0, p10, p11, p12, p13, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_cybol(p0, p1, p2, p3, p4, p5, p8, p9, p10, p11, p12, p13);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_xdt(p0, p10, p11, p12, p13, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The indentation level.
            //
            // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the indentation level value gets changed in the following functions!
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The indentation flag part.
            void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The indentation flag part model item.
            void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The indentation flag part model item data.
            void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Get indentation flag part.
            get_part_knowledge((void*) &i, p6, (void*) INDENTATION_LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) INDENTATION_LANGUAGE_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p7, p16);
            // Get indentation flag part model item.
            copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get indentation flag part model item data.
            copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            // Append document type.
            append_item_element(p0, (void*) HTML_DOCUMENT_TYPE_HTML_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HTML_DOCUMENT_TYPE_HTML_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            // Serialise line break.
            serialise_html_break(p0, imd);
            // Append content.
            serialise_html_part_element_content(p0, p10, p11, p12, p13, imd, (void*) &l, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) LDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_xdt(p0, p10, p11, p12, p13, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The tree level.
            // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the tree level value gets changed in the following functions!
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            serialise_model_diagram_part_element_content(p0, (void*) L"[selected_node]", (void*) NUMBER_15_INTEGER_STATE_CYBOI_MODEL, p8, p10, p11, p12, p13, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &l);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) URI_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_uri(p0, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Uncomment this later again!
            //?? It is already implemented, but too large (4 MiB),
            //?? so that compilation takes much too long.
            //?? The xDT de-/serialisation should be moved
            //?? into a library in the future.
//??            serialise_xdt_field_description(p0, p10);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise. The language is unknown.");
    }
}

/* SERIALISER_SOURCE */
#endif
