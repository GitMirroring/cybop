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

#ifndef DESERIALISER_SOURCE
#define DESERIALISER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/cybol/logic_cybol_cyboi_type.c"
#include "../../constant/type/cyboi/cybol/state_cybol_cyboi_type.c"
#include "../../executor/representer/deserialiser/authority/authority_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/boolean_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/complex_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/date_time_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/double_vector_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/fraction_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/integer_vector_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"
#include "../../executor/representer/deserialiser/html/html_deserialiser.c"
#include "../../executor/representer/deserialiser/http_request/http_request_deserialiser.c"
#include "../../executor/representer/deserialiser/http_response/http_response_deserialiser.c"
#include "../../executor/representer/deserialiser/latex/latex_deserialiser.c"
#include "../../executor/representer/deserialiser/terminal/terminal_deserialiser.c"
#include "../../executor/representer/deserialiser/uri/uri_deserialiser.c"
#include "../../executor/representer/deserialiser/xdt/xdt_deserialiser.c"
#include "../../executor/representer/deserialiser/xml/xml_deserialiser.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../executor/communicator/sender/file_system_sender.c"
#include "../../executor/representer/serialiser/model_diagram/node_model_diagram_serialiser.c"

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
 * Deserialises the source into the destination, according to the given cybol cyboi type.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the type
 */
void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode.");

    // CAUTION! Cybol operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // Their parametres were already converted into
    // properties while being decoded from cybol.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "deserialise_hhmmss_date_time"!
//??            deserialise_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_ddmmyyyy_date_time(p0, p2, p3);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_boolean(p0, p2, p3);
        }
    }

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            serialise_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_HTTP_REQUEST.txt";
            int fnc = *NUMBER_29_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_30_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_RESPONSE_MESSAGE_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary model, properties item.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary model, properties item data, count.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary model, properties item.
            allocate_item((void*) &m, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            allocate_item((void*) &p, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

            // Decode source message into temporary model, properties item.
            deserialise_xml((void*) &m, (void*) &p, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            serialise_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_RESPONSE_CYBOL.txt";
            int fnc = *NUMBER_28_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_29_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END
*/

            // Get temporary model, properties item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Decode temporary model, properties item into cyboi model.
            deserialise_cybol(p0, md, mc, pd, pc);

            // Deallocate temporary model, properties item.
            deallocate_item((void*) &m, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &p, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

/*??
//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_STATE_CYBOI_MODEL;
            mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            serialise_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_RESPONSE_COMPOUND.txt";
            fnc = *NUMBER_31_INTEGER_STATE_CYBOI_MODEL;
            fns = *NUMBER_32_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END
*/
        }
    }

    //
    // number
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) COMPLEX_CARTESIAN_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Implement the following function!
//??            deserialise_cartesian_complex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "deserialise_decimal_fraction".
//??            deserialise_double_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "deserialise_vulgar_fraction"!
//??            deserialise_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_cybol_integer_vector(p0, p2, p3);
        }
    }

    //
    // path
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCAPSULATED_PATH_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) KNOWLEDGE_PATH_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // text
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) AUTHORITY_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            deserialise_authority(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CYBOL_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary model, properties item.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The temporary model, properties item data, count.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

            // Allocate temporary model, properties item.
            allocate_item((void*) &m, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            allocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

fwprintf(stdout, L"TEST file data:\n%ls\n", (wchar_t*) p2);
fwprintf(stdout, L"TEST file count: %i\n", *((int*) p3));

fwprintf(stdout, L"TEST pre deserialise xml:\n%i\n", m);
            // Decode source message (cybol file) into temporary model, properties item.
            deserialise_xml(m, p, p2, p3);

            // Get temporary model, properties item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

//?? TEST BEGIN
            // The model diagram item.
            void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The multibyte character stream item.
            void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The file name.
            void* fd = L"TEST_DESERIALISE_XML.txt";
            int fc = *NUMBER_24_INTEGER_STATE_CYBOI_MODEL;
            int fs = *NUMBER_25_INTEGER_STATE_CYBOI_MODEL;
            // The model diagram item data, count.
            void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The multibyte character stream item model data, count.
            void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The tree level.
            int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram item.
            allocate_item((void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Allocate multibyte character stream item.
            allocate_item((void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
fwprintf(stdout, L"TEST pre serialise:\n%i\n", m);
            // Encode model into model diagram item.
            // CAUTION! Do NOT forward NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
            // since the tree level value gets changed in the following functions!
            serialise_model_diagram_node(d, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) CYBOI_TYPE_COUNT, md, mc, pd, pc, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &l);
            // Get model diagram item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &dd, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &dc, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST pre encode:\n%i\n", m);
            // Encode model diagram into multibyte character stream.
            encode_utf_8(b, dd, dc);
            // Get multibyte character stream item data, count.
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
fwprintf(stdout, L"TEST pre send:\n%i\n", m);
            // Write multibyte character stream to file system.
            send_file((void*) &fd, (void*) &fc, (void*) &fs, bd, bc);
//??            send_file((void*) &STANDARD_OUTPUT_STREAM_TERMINAL_MODEL, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL_COUNT, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL_COUNT, bd, bc);
fwprintf(stdout, L"TEST pre deallocate diagram:\n%i\n", m);
            // Deallocate model diagram item.
            deallocate_item((void*) &d, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_item((void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END

fwprintf(stdout, L"TEST pre deserialise cybol mc:\n%i\n", *((int*) mc));
fwprintf(stdout, L"TEST pre deserialise cybol pc:\n%i\n", *((int*) pc));
            // Decode temporary model, properties item into cyboi model.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            deserialise_cybol(p0, md, mc, pd, pc);

fwprintf(stdout, L"TEST pre deallocate temporary:\n%i\n", m);
            // Deallocate temporary model, properties item.
            deallocate_item((void*) &m, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            deallocate_item((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

/*??
//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_STATE_CYBOI_MODEL;
            mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            serialise_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_DECODER_CYBOL.txt";
            fnc = *NUMBER_22_INTEGER_STATE_CYBOI_MODEL;
            fns = *NUMBER_23_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTML_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_html(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TYPE_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // CAUTION! Decode cybol- into cybol cyboi type.
            // This should be sufficient for sending and receiving messages.
            // If the type is needed to allocate memory,
            // then ONE MORE conversion has to be done,
            // using the "deserialise_cybol_cyboi_type" function.
            deserialise_cybol_type(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) URI_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_uri(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            serialise_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_URI.txt";
            int fnc = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_21_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) XDT_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_xdt(p0, p1, p2, p3);
        }
    }

/*?? TODO:
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_terminal(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LATEX_APPLICATION_X_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_latex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_BACKGROUND_COLOUR_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_terminal_background(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_FOREGROUND_COLOUR_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_terminal_foreground(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_x_window_system(p0, p2, p3);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise. The type is unknown.");
    }
}

/* DESERIALISER_SOURCE */
#endif
