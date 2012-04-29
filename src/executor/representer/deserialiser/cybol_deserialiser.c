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

#ifndef CYBOL_DESERIALISER_SOURCE
#define CYBOL_DESERIALISER_SOURCE

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/format/logic_format_type.c"
#include "../../../constant/type/format/state_format_type.c"
#include "../../../executor/representer/deserialiser/ansi_escape_code/ansi_escape_code_deserialiser.c"
#include "../../../executor/representer/deserialiser/authority/authority_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/integer/integer_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/boolean_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/complex_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/content_node_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/date_time_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/double_vector_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/format_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/fraction_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/language_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/html/html_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_request/http_request_deserialiser.c"
#include "../../../executor/representer/deserialiser/http_response/http_response_deserialiser.c"
#include "../../../executor/representer/deserialiser/latex/latex_deserialiser.c"
#include "../../../executor/representer/deserialiser/uri/uri_deserialiser.c"
#include "../../../executor/representer/deserialiser/xdt/xdt_deserialiser.c"
#include "../../../executor/representer/deserialiser/xml/xml_deserialiser.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../../tester/data_as_model_diagram_tester.c"
#include "../../../tester/item_as_model_diagram_tester.c"

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
 * Deserialises the source into the destination, according to the given format.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the format
 */
void deserialise_cybol(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol.");

    // The functions below are for STATE models only.
    // CAUTION! CYBOL LOGIC operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // They are detected via their "format" xml attribute.
    // Their parametres were converted from cybol properties.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // colour
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_BACKGROUND_COLOUR_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_terminal_background(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_FOREGROUND_COLOUR_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_terminal_foreground(p0, p2, p3);
        }
    }

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HH_MM_SS_DATETIME_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "deserialise_hhmmss_date_time"!
//??            deserialise_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) YYYY_MM_DD_DATETIME_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_ddmmyyyy_date_time(p0, p2, p3);
        }
    }

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PART_ELEMENT_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_cybol_??part??(p0, p2, p3);

            // The temporary format, type, model, properties item.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary model, properties data, count.
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

            // Decode source message (cybol file) into temporary model, properties item.
            deserialise_xml(m, p, p2, p3);

            // Get temporary model, properties data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_XML.txt", *NULL_POINTER_STATE_CYBOI_MODEL, t, m, p);

            // Decode temporary model, properties item into cyboi model using temporary type, format.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            deserialise_cybol_node_content(p0, md, mc, pd, pc, t, f);

            test_item_as_model_diagram((void*) L"TEST_DESERIALISE_CYBOL.txt", *NULL_POINTER_STATE_CYBOI_MODEL, t, p0, p1);

            // Deallocate temporary format, type, model, properties item.
            deallocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
            deallocate_item((void*) &m, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_boolean(p0, p2, p3);
        }
    }

    //
    // meta
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CHANNEL_META_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_channel(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCODING_META_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_encoding(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LANGUAGE_META_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Decode cybol source language (mime type as string) into cyboi-internal language (an integer).
            deserialise_cybol_language(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FORMAT_META_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Decode cybol source format (mime type as string) into cyboi-internal format (an integer).
            deserialise_cybol_format(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TYPE_META_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary format item.
            void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary format item data.
            void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary format item.
            // CAUTION! Initialise integer items with a size of ONE,
            // in order to avoid later reallocation when overwriting
            // the element and to thus increase efficiency.
            allocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            // Decode cybol source format (mime type as string) into cyboi-internal type (an integer).
            deserialise_cybol_format(f, p2, p3);
            // Get temporary format item data.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            // Decode cyboi-internal type into cyboi runtime type.
            // CAUTION! Both are not always equal in their meaning.
            // For example, an "xdt" file is converted into a cyboi "part".
            // Therefore, a runtime type has to be figured out here.
            // The latter is needed for allocating the new part.
            deserialise_cybol_type(p0, fd);

            // Deallocate temporary format item.
            deallocate_item((void*) &f, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Implement the following function!
//??            deserialise_cartesian_complex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_DECIMAL_NUMBER_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "deserialise_decimal_fraction".
//??            deserialise_double_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_VULGAR_NUMBER_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "deserialise_vulgar_fraction"!
//??            deserialise_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_integer(p0, p2, p3);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCAPSULATED_PATH_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) KNOWLEDGE_PATH_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_TEXT_STATE_FORMAT_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol. The format is unknown.");
    }
}

/* CYBOL_DESERIALISER_SOURCE */
#endif
