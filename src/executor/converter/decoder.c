/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: converter.c,v $ $Revision: 1.76 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DECODER_SOURCE
#define DECODER_SOURCE

#include "../../constant/abstraction/cybol/application_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/application_x_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/colour_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/datetime_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/interface_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/logicvalue_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/message_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/number_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/operation_cybol_abstraction.c"
#include "../../constant/abstraction/cybol/text_cybol_abstraction.c"
#include "../../constant/abstraction/memory/memory_abstraction.c"
#include "../../constant/abstraction/operation/primitive_operation_abstraction.c"
#include "../../constant/channel/cybol_channel.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/converter/decoder/abstraction_decoder.c"
#include "../../executor/converter/decoder/authority_decoder.c"
#include "../../executor/converter/decoder/ascii_character_vector_decoder.c"
#include "../../executor/converter/decoder/boolean_decoder.c"
#include "../../executor/converter/decoder/complex_decoder.c"
#include "../../executor/converter/decoder/cybol_decoder.c"
#include "../../executor/converter/decoder/date_time_decoder.c"
#include "../../executor/converter/decoder/double_vector_decoder.c"
#include "../../executor/converter/decoder/fraction_decoder.c"
#include "../../executor/converter/decoder/gnu_linux_console_decoder.c"
#include "../../executor/converter/decoder/html_decoder.c"
#include "../../executor/converter/decoder/http_request_decoder.c"
#include "../../executor/converter/decoder/http_response_decoder.c"
#include "../../executor/converter/decoder/integer_decoder.c"
#include "../../executor/converter/decoder/integer_vector_decoder.c"
#include "../../executor/converter/decoder/latex_decoder.c"
#include "../../executor/converter/decoder/model_diagram_decoder.c"
#include "../../executor/converter/decoder/terminal_background_decoder.c"
#include "../../executor/converter/decoder/terminal_foreground_decoder.c"
#include "../../executor/converter/decoder/uri_decoder.c"
#include "../../executor/converter/decoder/utf_16_unicode_character_decoder.c"
#include "../../executor/converter/decoder/utf_8_unicode_character_decoder.c"
#include "../../executor/converter/decoder/xdt_decoder.c"
#include "../../executor/converter/decoder/xml_decoder.c"
#include "../../executor/converter/decoder/x_window_system_decoder.c"
#include "../../executor/memoriser/allocator/model_allocator.c"
#include "../../executor/memoriser/deallocator/model_deallocator.c"

//?? TEMPORARY FOR TESTING! DELETE LATER!
#include "../../executor/communicator/sender/file_sender.c"

/**
 * Decodes the source into the destination, according to the given abstraction.
 *
 * @param p0 the destination model item
 * @param p1 the destination details item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the abstraction
 */
void decode(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Decode.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ABSTRACTION_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_abstraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) AUTHORITY_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_authority(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) BOOLEAN_LOGICVALUE_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_boolean(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CARTESIAN_COMPLEX_NUMBER_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //?? TODO: Implement the following function!
            //?? decode_cartesian_complex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) CYBOL_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // The temporary model data, count, size.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The temporary details data, count, size.
            void* dd = *NULL_POINTER_MEMORY_MODEL;
            int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate temporary model.
            allocate_array((void*) &md, (void*) &ms, (void*) PART_MEMORY_ABSTRACTION);
            // Allocate temporary details.
            allocate_array((void*) &dd, (void*) &ds, (void*) PART_MEMORY_ABSTRACTION);

            // Decode source message (cybol file) into temporary model.
            decode_xml((void*) &md, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p2, p3);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                m, mc, d, dc);
*/
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_XML.txt";
            int fnc = *NUMBER_20_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_21_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            // Basically, tags (structural data) and attributes (meta data) are swapped in meaning.
            decode_cybol(p0, m, mc, d, dc);

            // Deallocate temporary model.
            deallocate_array((void*) &md, (void*) &ms, (void*) PART_MEMORY_ABSTRACTION);
            // Deallocate temporary details.
            deallocate_array((void*) &dd, (void*) &ds, (void*) PART_MEMORY_ABSTRACTION);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
*/
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_DECODER_CYBOL.txt";
            fnc = *NUMBER_22_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_23_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) DECIMAL_FRACTION_NUMBER_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //?? TEMPORARY solution!
            //?? TODO: Replace with something like "decode_decimal_fraction".
            //?? decode_double_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) ENCAPSULATED_KNOWLEDGE_PATH_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) GNU_LINUX_CONSOLE_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_gnu_linux_console(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HH_MM_SS_DATETIME_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //?? TODO: Rename into "decode_hhmmss_date_time"!
            //?? decode_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTML_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_html(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_REQUEST_MESSAGE_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_http_request(p0, p1, p2, p3);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
*/
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_HTTP_REQUEST.txt";
            int fnc = *NUMBER_29_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_30_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_RESPONSE_MESSAGE_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            // The temporary model.
            void* m = *NULL_POINTER_MEMORY_MODEL;
            int mc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ms = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // The temporary details.
            void* d = *NULL_POINTER_MEMORY_MODEL;
            int dc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int ds = *NUMBER_0_INTEGER_MEMORY_MODEL;

            // Allocate temporary model.
            allocate((void*) &m, (void*) &ms, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT);
            // Allocate temporary details.
            allocate((void*) &d, (void*) &ds, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT);

            // Decode source message into temporary compound memory model.
            decode_xml((void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds, p2, p3);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                m, (void*) &mc, d, (void*) &dc);
*/
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_HTTP_RESPONSE_CYBOL.txt";
            int fnc = *NUMBER_28_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_29_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END

            // Decode temporary compound memory model into cyboi knowledge compound memory model.
            decode_cybol(p0, m, (void*) &mc, d, (void*) &dc);

            // Deallocate temporary model.
            deallocate((void*) &m, (void*) &ms, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT);
            // Deallocate temporary details.
            deallocate((void*) &d, (void*) &ds, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT);

//?? TEST BEGIN
            // Reset model diagram.
            md = *NULL_POINTER_MEMORY_MODEL;
            mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
*/
            // Reset multibyte character stream.
            mb = *NULL_POINTER_MEMORY_MODEL;
            mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // Reset file name.
            fn = L"TEST_HTTP_RESPONSE_COMPOUND.txt";
            fnc = *NUMBER_31_INTEGER_MEMORY_MODEL;
            fns = *NUMBER_32_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) INTEGER_NUMBER_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_integer_vector(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) KNOWLEDGE_PATH_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) LATEX_APPLICATION_X_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_latex(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) MODEL_DIAGRAM_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_model_diagram(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_OPERATION_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            overwrite_item_element(p0, p2, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) TRUE_BOOLEAN_MEMORY_MODEL, (void*) DATA_ITEM_MEMORY_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_BACKGROUND_COLOUR_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_terminal_background(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) TERMINAL_FOREGROUND_COLOUR_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_terminal_foreground(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) URI_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_uri(p0, p1, p2, p3);

//?? TEST BEGIN
            // The model diagram.
            void* md = *NULL_POINTER_MEMORY_MODEL;
            int mdc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mds = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate model diagram.
            allocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
/*?? TODO!
            // Encode model into model diagram.
            encode_model_diagram((void*) &md, (void*) &mdc, (void*) &mds,
                *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, (void*) PART_MEMORY_ABSTRACTION, (void*) PART_MEMORY_ABSTRACTION_COUNT,
                *((void**) p0), p1, *((void**) p3), p4);
*/
            // The multibyte character stream.
            void* mb = *NULL_POINTER_MEMORY_MODEL;
            int mbc = *NUMBER_0_INTEGER_MEMORY_MODEL;
            int mbs = *NUMBER_0_INTEGER_MEMORY_MODEL;
            // Allocate multibyte character stream.
            allocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Encode model diagram into multibyte character stream.
            encode_utf_8_unicode_character_vector((void*) &mb, (void*) &mbc, (void*) &mbs, md, (void*) &mdc);
            // The file name.
            void* fn = L"TEST_DECODER_URI.txt";
            int fnc = *NUMBER_20_INTEGER_MEMORY_MODEL;
            int fns = *NUMBER_21_INTEGER_MEMORY_MODEL;
            // Write multibyte character stream as message to file system.
            send_file((void*) &fn, (void*) &fnc, (void*) &fns, mb, (void*) &mbc);
            // Deallocate model diagram.
            deallocate((void*) &md, (void*) &mds, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
            // Deallocate multibyte character stream.
            deallocate((void*) &mb, (void*) &mbs, (void*) CHARACTER_MEMORY_ABSTRACTION, (void*) CHARACTER_MEMORY_ABSTRACTION_COUNT);
//?? TEST END
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) VULGAR_FRACTION_NUMBER_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //?? TODO: Rename into "decode_vulgar_fraction"!
            //?? decode_fraction(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) X_WINDOW_SYSTEM_CYBOL_CHANNEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_x_window_system(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) XDT_TEXT_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_xdt(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) YYYY_MM_DD_DATETIME_CYBOL_ABSTRACTION);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_ddmmyyyy_date_time(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not decode. The abstraction is unknown.");
    }
}

/* DECODER_SOURCE */
#endif
