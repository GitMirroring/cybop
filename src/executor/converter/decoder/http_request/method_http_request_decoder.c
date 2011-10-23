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
 * @version $RCSfile: http_request_processor.c,v $ $Revision: 1.6 $ $Date: 2009-10-06 21:25:27 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef METHOD_HTTP_REQUEST_DECODER_SOURCE
#define METHOD_HTTP_REQUEST_DECODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/selector/http_request/method_http_request_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Converts the given characters to wide characters and
 * appends them to the destination.
 *
 * @param p0 the destination (Hand over as reference!)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source name
 * @param p4 the source name count
 * @param p5 the source abstraction
 * @param p6 the source abstraction count
 * @param p7 the source model
 * @param p8 the source model count
 * @param p9 the source details
 * @param p10 the source details count
 */
void decode_http_request_method_append_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    // The serialised wide character array.
    void* s = *NULL_POINTER_MEMORY_MODEL;
    void* sc = *NULL_POINTER_MEMORY_MODEL;
    void* ss = *NULL_POINTER_MEMORY_MODEL;

    // Allocate serialised wide character array.
    allocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);

    // Decode encoded character array into serialised wide character array.
    decode_utf_8_unicode_character_vector((void*) &s, sc, ss, p7, p8);

    append_part(p0, p1, p2, p3, p4, p5, p6, s, sc, p9, p10);

    // Deallocate serialised wide character array.
    deallocate_model((void*) &s, (void*) &sc, (void*) &ss, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT);
--
    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

    // Fill part.
    overwrite_part_element(p, (void*) CYBOI_HOSTNAME_AUTHORITY_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CYBOI_HOSTNAME_AUTHORITY_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
    overwrite_part_element(p, e, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) &ec, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

    // Append part to destination model.
    append_item_element(p0, (void*) &p, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/**
 * Decodes the http request method.
 *
 * @param p0 the destination model item
 * @param p1 the destination details item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_http_request_method(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http request method.");

    // The element.
    void* e = *NULL_POINTER_MEMORY_MODEL;
    int ec = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    // Initialise element.
    copy_pointer((void*) &e, p2);

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_MEMORY_MODEL);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        select_http_request_method(p0, p1, (void*) &b, p2, p3);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            decode_http_request_method_append_part(p1,
                (void*) CYBOI_METHOD_HTTP_NAME, (void*) CYBOI_METHOD_HTTP_NAME_COUNT,
                (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION, (void*) WIDE_CHARACTER_MEMORY_ABSTRACTION_COUNT,
                e, (void*) &ec, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL);

            break;

        } else {

            // Increment request method count.
            ec++;
        }
    }
}

/* METHOD_HTTP_REQUEST_DECODER_SOURCE */
#endif
