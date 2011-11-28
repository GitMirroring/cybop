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

#ifndef DECODER_SOURCE
#define DECODER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/cybol/logic_cybol_cyboi_type.c"
#include "../../constant/type/cyboi/cybol/state_cybol_cyboi_type.c"
#include "../../executor/converter/decoder/authority/authority_decoder.c"
#include "../../executor/converter/decoder/cybol/boolean_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/channel_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/complex_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/date_time_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/double_vector_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/fraction_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/integer_vector_cybol_decoder.c"
#include "../../executor/converter/decoder/cybol/type_cybol_decoder.c"
#include "../../executor/converter/decoder/html/html_decoder.c"
#include "../../executor/converter/decoder/http_request/http_request_decoder.c"
#include "../../executor/converter/decoder/http_response/http_response_decoder.c"
#include "../../executor/converter/decoder/latex/latex_decoder.c"
#include "../../executor/converter/decoder/terminal/terminal_decoder.c"
#include "../../executor/converter/decoder/uri/uri_decoder.c"
#include "../../executor/converter/decoder/utf/utf_16_unicode_character_decoder.c"
#include "../../executor/converter/decoder/utf/utf_8_unicode_character_decoder.c"
#include "../../executor/converter/decoder/xdt/xdt_decoder.c"
#include "../../executor/converter/decoder/xml/xml_decoder.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
//#include "../../executor/communicator/sender/file_sender.c"

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
 * Decodes the source into the destination, according to the given cybol cyboi type.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the type
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode.");

    // CAUTION! Cybol logic operations have an EMPTY model.
    // Hence, they do NOT have to be considered here.
    // Their parametres were already converted into properties
    // while having been decoded from cybol.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // datetime
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HH_MM_SS_DATETIME_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "decode_hhmmss_date_time"!
//??            decode_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) YYYY_MM_DD_DATETIME_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            decode_ddmmyyyy_date_time(p0, p2, p3);
        }
    }

    //
    // logicvalue
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_cybol_boolean(p0, p2, p3);
        }
    }

    //
    // message
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_http_request(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
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
            // Get temporary model, properties item data, count.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Decode source message into temporary model, properties item.
            decode_xml((void*) &m, (void*) &p, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
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

            // Decode temporary model, properties item into cyboi model.
            decode_cybol(p0, md, mc, pd, pc);

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
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
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
//??            decode_cartesian_complex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_DECIMAL_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "decode_decimal_fraction".
//??            decode_double_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FRACTION_VULGAR_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "decode_vulgar_fraction"!
//??            decode_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            decode_cybol_integer_vector(p0, p2, p3);
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

//??            decode_authority(p0, p1, p2, p3);
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
            allocate_item((void*) &m, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            allocate_item((void*) &p, (void*) ITEM_STATE_CYBOI_MODEL_COUNT, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);
            // Get temporary model, properties item data, count.
            copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Decode source message (cybol file) into temporary model, properties item.
            decode_xml((void*) &m, (void*) &p, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                m, mc, d, dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_XML.txt";
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

            // Decode temporary model, properties item into cyboi model.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            decode_cybol(p0, md, mc, pd, pc);

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
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
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

            decode_html(p0, p2, p3);
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
            // using the "decode_cybol_cyboi_type" function.
            decode_cybol_type(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) URI_TEXT_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_uri(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate_array((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PART_ELEMENT_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate_array((void*) &mb, (void*) &mbs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
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

            decode_xdt(p0, p1, p2, p3);
        }
    }

/*?? TODO:
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LATEX_APPLICATION_X_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_latex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_BACKGROUND_COLOUR_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal_background(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_FOREGROUND_COLOUR_STATE_CYBOL_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal_foreground(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_x_window_system(p0, p2, p3);
        }
    }
*/

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode. The type is unknown.");
    }
}

/* DECODER_SOURCE */
#endif
