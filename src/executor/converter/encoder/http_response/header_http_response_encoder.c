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

#ifndef HEADER_HTTP_RESPONSE_ENCODER_SOURCE
#define HEADER_HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/encoder/http_response/header_entry_http_response_encoder.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the http response header content length.
 *
 * @param p0 the destination character item
 * @param p1 the source message model count (content length)
 */
void encode_http_response_header_content_length(void* p0, void* p1) {

    // The wide character array.
    void* a = *NULL_POINTER_MEMORY_MODEL;
    void* ac = *NULL_POINTER_MEMORY_MODEL;
    void* as = *NULL_POINTER_MEMORY_MODEL;

    // Allocate character array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);

    // Encode wide character array into multibyte character array.
    encode_integer((void*) &a, ac, as, p3, (void*) PRIMITIVE_MEMORY_MODEL_COUNT);

    overwrite_array(p0, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
    overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);
    // CAUTION! Use the message count (content length) integer value
    // that was handed over as parameter!
    select_http_response_header_entry_overwrite_array(p0, p1, p2, a, ac);
    overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_MEMORY_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_MEMORY_NAME, p1, p2);

    // Deallocate character array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) WIDE_CHARACTER_MEMORY_TYPE_COUNT);
}

/**
 * Encodes the http response header.
 *
 * @param p0 the destination character item
 * @param p1 the source metadata type
 * @param p2 the source metadata type count
 * @param p3 the source metadata model
 * @param p4 the source metadata model count
 * @param p5 the source metadata properties
 * @param p6 the source metadata properties count
 * @param p7 the source message model count
 */
void encode_http_response_header(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Encode http response header.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p4);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        encode_http_response_header_entry(p0, p3, (void*) &j);

        // Increment loop variable.
        j++;
    }

    // The content length is currently always added
    // (but this solution may change later).
    encode_http_response_header_content_length(p0, p7);
}

/* HEADER_HTTP_RESPONSE_ENCODER_SOURCE */
#endif
