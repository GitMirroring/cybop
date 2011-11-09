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

#ifndef QUERY_HTTP_URI_DECODER_SOURCE
#define QUERY_HTTP_URI_DECODER_SOURCE

#include "../../../../../constant/model/log/message_log_model.c"
#include "../../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../executor/accessor/appender/part_appender.c"
#include "../../../../../executor/converter/decoder/uri/http/parameter_query_http_uri_decoder.c"
#include "../../../../../executor/converter/selector/uri/http/query_http_uri_selector.c"
#include "../../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../../logger/logger.c"

/**
 * Decodes the http uri query content.
 *
 * @param p0 the destination model item
 * @param p1 the source query data
 * @param p2 the source query count
 */
void decode_http_uri_query_content(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http uri query content.");

    // The source data position.
    void* sd = *NULL_POINTER_MEMORY_MODEL;
    // The source count remaining.
    int sc = *NUMBER_0_INTEGER_MEMORY_MODEL;

    // Copy source data position.
    copy_pointer((void*) &sd, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &sc, p2);

    // The part.
    void* p = *NULL_POINTER_MEMORY_MODEL;
    // The part model, details.
    void* pm = *NULL_POINTER_MEMORY_MODEL;
    void* pd = *NULL_POINTER_MEMORY_MODEL;

    // Allocate part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_MEMORY_TYPE);

    // Get part model, details.
    copy_array_forward((void*) &pm, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

    // Fill part.
    overwrite_part_element(p, (void*) CYBOI_QUERY_URI_NAME, (void*) WIDE_CHARACTER_MEMORY_TYPE, (void*) CYBOI_QUERY_URI_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    overwrite_part_element(p, (void*) PART_MEMORY_TYPE, (void*) INTEGER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    decode_http_uri_query_parameter(pm, pd, (void*) &sd, (void*) &sc);

    // Append part to destination model.
    append_item_element(p0, (void*) &p, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);
}

/**
 * Decodes the http uri query.
 *
 * @param p0 the destination model item
 * @param p1 the destination details item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_http_uri_query(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http uri query.");

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

        select_http_uri_query(p0, p1, (void*) &b, p2, p3);

        if (b == *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Increment element count.
            ec++;
        }
    }

    // The query is always added, independent from whether
    // or not a fragment separator was found.
    //
    // If a fragment was found right at
    // the first position, then no query was given.
    // In this case, a query with empty value is added.
    decode_http_uri_query_content(p0, e, (void*) &ec);
}

/* QUERY_HTTP_URI_DECODER_SOURCE */
#endif
