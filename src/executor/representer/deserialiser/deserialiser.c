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

#ifndef DESERIALISER_SOURCE
#define DESERIALISER_SOURCE

#include "../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../executor/representer/deserialiser/authority/authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/binary_crlf/binary_crlf_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_event/gui_event_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/action_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/html/html_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_response/http_response_deserialiser.c"
#include "../../../executor/representer/deserialiser/latex/latex_deserialiser.c"
#include "../../../executor/representer/deserialiser/tui/tui_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/xdt/xdt_deserialiser.c"
#include "../../../executor/representer/deserialiser/xml/xml_deserialiser.c"

/**
 * Deserialises the source into the destination, according to the given language.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data (pointer reference for display channel, otherwise not)
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source format
 * @param p7 the medium model data (user interface window model hierarchy used to identify nested components and their action via mouse coordinates)
 * @param p8 the medium model count
 * @param p9 the medium properties data
 * @param p10 the medium properties count
 * @param p11 the medium format
 * @param p12 the knowledge memory part (pointer reference)
 * @param p13 the stack memory item
 * @param p14 the internal memory data
 * @param p15 the destination format
 * @param p16 the language
 */
void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // event
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) GUI_EVENT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** e = (void**) p2;

                //
                // CAUTION! The source model data p2 is a pointer REFERENCE
                // of type void** for the display channel with gui language,
                // since it stores event objects.
                //
                // Therefore, it has to be DEREFERENCED yet.
                //
                deserialise_gui_event(p1, *e);

                //
                // CAUTION! Hand over cybol window hierarchy model and properties,
                // but NOT those of the original event, since its characteristics
                // have been stored in the destination properties already.
                //
                deserialise_gui_action(p0, p1, p7, p8, p9, p10, p11, p12, p13, p14, p15);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise. The source model data is null.");
                fwprintf(stdout, L"Error: Could not deserialise. The source model data is null. p2: %i\n", p2);
            }
        }
    }

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) BINARY_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A translation is NOT necessary.
            // The data are forwarded as they are.
            //

            modify_item(p0, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) BINARY_CRLF_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_binary_crlf(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) CLI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_tui(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary model, properties item.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary model, properties item data, count.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate temporary model, properties item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            // CAUTION! Initialise integer items with a size of ONE,
            // in order to avoid later reallocation when overwriting
            // the element and to thus increase efficiency.
            //
            allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

            // Decode source message into temporary model, properties item.
            deserialise_xml(m, p, p2, p3);

            //
            // Get temporary model, properties item data, count.
            //
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            //
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Decode temporary model, properties item into cyboi model.
            deserialise_cybol_content(p0, md, mc, pd, pc);

            // Deallocate temporary model, properties item.
            deallocate_item((void*) &m, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) TUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_tui(p0, p2, p3);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_authority(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) BDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt(p0, p1, p2, p3, p16);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol(p0, p1, p2, p3, p15);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) GDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt(p0, p1, p2, p3, p16);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_html(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) LDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt(p0, p1, p2, p3, p16);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p16, (void*) URI_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_uri(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise. The language is unknown or null.");
    }
}

/* DESERIALISER_SOURCE */
#endif
