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
#include "../../constant/type/cyboi/state_cyboi_type.c"
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

/**
 * Decodes the source into the destination, according to the given type.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the type
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) AUTHORITY_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_authority(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_boolean(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Implement the following function!
            //?? decode_cartesian_complex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CYBOL_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary model data, count, size.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int ms = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The temporary properties data, count, size.
            void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
            int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Allocate temporary model.
            allocate_array((void*) &md, (void*) &ms, (void*) PART_STATE_CYBOI_TYPE);
            // Allocate temporary properties.
            allocate_array((void*) &dd, (void*) &ds, (void*) PART_STATE_CYBOI_TYPE);

            // Decode source message (cybol file) into temporary model.
            decode_xml((void*) &md, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                m, mc, d, dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_XML.txt";
            int fnc = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_21_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            decode_cybol(p0, m, mc, d, dc);

            // Deallocate temporary model.
            deallocate_array((void*) &md, (void*) &ms, (void*) PART_STATE_CYBOI_TYPE);
            // Deallocate temporary properties.
            deallocate_array((void*) &dd, (void*) &ds, (void*) PART_STATE_CYBOI_TYPE);

/*??
//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_STATE_CYBOI_MODEL;
            mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_DECODER_CYBOL.txt";
            fnc = *NUMBER_22_INTEGER_STATE_CYBOI_MODEL;
            fns = *NUMBER_23_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "decode_decimal_fraction".
            //?? decode_double_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HH_MM_SS_DATETIME_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "decode_hhmmss_date_time"!
            //?? decode_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTML_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_html(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_REQUEST_MESSAGE_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_http_request(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_HTTP_REQUEST.txt";
            int fnc = *NUMBER_29_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_30_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The temporary model.
            void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int ms = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The temporary properties.
            void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
            int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Allocate temporary model.
            allocate((void*) &m, (void*) &ms, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT);
            // Allocate temporary properties.
            allocate((void*) &d, (void*) &ds, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT);

            // Decode source message into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                m, (void*) &mc, d, (void*) &dc);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_RESPONSE_CYBOL.txt";
            int fnc = *NUMBER_28_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_29_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT);
            // Deallocate temporary properties.
            deallocate((void*) &d, (void*) &ds, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT);

/*??
//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_STATE_CYBOI_MODEL;
            mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // Reset multibyte character stream.
            mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_RESPONSE_COMPOUND.txt";
            fnc = *NUMBER_31_INTEGER_STATE_CYBOI_MODEL;
            fns = *NUMBER_32_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_integer_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) KNOWLEDGE_PATH_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LATEX_APPLICATION_X_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_latex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) MODEL_DIAGRAM_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_model_diagram(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_OPERATION_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal_background(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_terminal_foreground(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TYPE_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_type(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) URI_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_uri(p0, p1, p2, p3);

/*??
//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mdc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE, (void*) PART_STATE_CYBOI_TYPE_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
            // The multibyte character stream.
            void* mb = *NULL_POINTER_STATE_CYBOI_MODEL;
            int mbc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            int mbs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_URI.txt";
            int fnc = *NUMBER_20_INTEGER_STATE_CYBOI_MODEL;
            int fns = *NUMBER_21_INTEGER_STATE_CYBOI_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) CHARACTER_STATE_CYBOI_TYPE_COUNT);
//?? TEST END
*/
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) VULGAR_FRACTION_NUMBER_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? TODO: Rename into "decode_vulgar_fraction"!
            //?? decode_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_x_window_system(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) XDT_TEXT_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_xdt(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) YYYY_MM_DD_DATETIME_CYBOL_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_ddmmyyyy_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode. The type is unknown.");
    }
}

/* DECODER_SOURCE */
#endif
