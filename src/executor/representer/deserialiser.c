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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DESERIALISER_SOURCE
#define DESERIALISER_SOURCE

#include "../../constant/language/cyboi/state_cyboi_language.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/representer/deserialiser/ansi_escape_code/ansi_escape_code_deserialiser.c"
#include "../../executor/representer/deserialiser/authority/authority_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/html/html_deserialiser.c"
#include "../../executor/representer/deserialiser/http_request/http_request_deserialiser.c"
#include "../../executor/representer/deserialiser/http_response/http_response_deserialiser.c"
#include "../../executor/representer/deserialiser/latex/latex_deserialiser.c"
#include "../../executor/representer/deserialiser/uri/uri_deserialiser.c"
#include "../../executor/representer/deserialiser/xdt/basic/basic_xdt_deserialiser.c"
#include "../../executor/representer/deserialiser/xml/xml_deserialiser.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../tester/data_as_model_diagram_tester.c"
#include "../../tester/item_as_model_diagram_tester.c"

//
// Sometimes, a cybol model represents a type, e.g. when creating a part.
// Other times, a cybol model represents a colour or other kinds of data.
// This is indicated by a type with special value, e.g. "text/type".
// In such cases, the cybol model's character array has to be converted into
// an integer value, since cyboi processes types in this form internally.
//
// Example 1 (see "type" property's "type" and "model" attribute):
//
// <part name="create_counter" channel="inline" type="memorise/create" model="">
//     <property name="name" channel="inline" type="text/plain" model="counter"/>
//     <property name="type" channel="inline" type="text/type" model="memory/compound"/>
//     <property name="element" channel="inline" type="text/plain" model="part"/>
// </part>
//
// Example 2 (see "background" property's "type" and "model" attribute):
//
// <part name="mc_item" channel="inline" type="text/plain" model="m - Start Midnight Commander (MC)">
//     <property name="position" channel="inline" type="number/integer" model="1,3,0"/>
//     <property name="size" channel="inline" type="number/integer" model="68,1,1"/>
//     <property name="background" channel="inline" type="colour/terminal" model="blue"/>
//     <property name="foreground" channel="inline" type="colour/terminal" model="white"/>
//     <property name="bold" channel="inline" type="logicvalue/boolean" model="true"/>
// </part>
//

/**
 * Deserialises the source into the destination, according to the given language.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the format
 * @param p5 the language
 */
void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise.");

    // The functions below are for STATE models only.
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // interface
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) GRAPHICAL_INTERFACE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_interface_graphical(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) X_WINAMP_SKIN_INTERFACE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_interface_x-winamp-skin(p0, p1, p2, p3);
        }
    }

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_ansi_escape_code(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request(p0, p1, p2, p3);

//??            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_HTTP_REQUEST.txt", *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary format, type, model, properties item.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary model, properties item data, count.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary format, type, model, properties item.
            // CAUTION! Initialise integer items with a size of ONE,
            // in order to avoid later reallocation when overwriting
            // the element and to thus increase efficiency.
            allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            allocate_item((void*) &m, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            allocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

            // Decode source message into temporary model, properties item.
            deserialise_xml(m, p, p2, p3);

            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_HTTP_RESPONSE.txt", *NULL_POINTER_STATE_CYBOI_MODEL, t, m, p);

            // Get temporary model, properties item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Decode temporary model, properties item into cyboi model using temporary type, format.
            deserialise_cybol_part_element_content(p0, md, mc, pd, pc, t, f);

            // Deallocate temporary format, type, model, properties item.
            deallocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &m, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

//??            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_HTTP_RESPONSE.txt", *NULL_POINTER_STATE_CYBOI_MODEL, t, m, p);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_authority(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) CYBOL_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol(p0, p1, p2, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) HTML_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_html(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) URI_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_uri(p0, p1, p2, p3);

//??            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_URI.txt", *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p0, p1);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p5, (void*) XDT_TEXT_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? Parse data in two steps:
            //?? - parse all xdt fields and add them as list to a root part
            //?? - loop through the list of fields and interpret these

            deserialise_xdt_basic(p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise. The language is unknown.");
    }
}

/* DESERIALISER_SOURCE */
#endif
