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
 * @param p1 the source query
 * @param p2 the source query count
 */
void decode_http_uri_query_content(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** dd = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http uri query content.");

        // The query name, abstraction, model, details.
        void* n = *NULL_POINTER_MEMORY_MODEL;
        void* nc = *NULL_POINTER_MEMORY_MODEL;
        void* ns = *NULL_POINTER_MEMORY_MODEL;
        void* a = *NULL_POINTER_MEMORY_MODEL;
        void* ac = *NULL_POINTER_MEMORY_MODEL;
        void* as = *NULL_POINTER_MEMORY_MODEL;
        void* m = *NULL_POINTER_MEMORY_MODEL;
        void* mc = *NULL_POINTER_MEMORY_MODEL;
        void* ms = *NULL_POINTER_MEMORY_MODEL;
        void* d = *NULL_POINTER_MEMORY_MODEL;
        void* dc = *NULL_POINTER_MEMORY_MODEL;
        void* ds = *NULL_POINTER_MEMORY_MODEL;

        // Allocate query.
        allocate_part((void*) &n, (void*) &nc, (void*) &ns, (void*) &a, (void*) &ac, (void*) &as,
            (void*) &m, (void*) &mc, (void*) &ms, (void*) &d, (void*) &dc, (void*) &ds,
            (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT);

        // Decode query name.
        decode((void*) &n, (void*) nc, (void*) ns, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) CYBOI_QUERY_URI_NAME, (void*) CYBOI_QUERY_URI_NAME_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Decode query abstraction.
        decode((void*) &a, (void*) ac, (void*) as, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) COMPOUND_MEMORY_ABSTRACTION, (void*) COMPOUND_MEMORY_ABSTRACTION_COUNT, *NULL_POINTER_MEMORY_MODEL, *NULL_POINTER_MEMORY_MODEL,
            (void*) PLAIN_TEXT_CYBOL_ABSTRACTION, (void*) PLAIN_TEXT_CYBOL_ABSTRACTION_COUNT);

        // Decode query model and details.
        // CAUTION! Hand over p3 as reference!
        decode_http_uri_query_parameter((void*) &m, (void*) mc, (void*) ms, (void*) &d, (void*) dc, (void*) ds, (void*) &p1, p2);

        // Add query as compound hierarchy consisting of parts.
        // CAUTION! Hand over the name as reference!
        append_compound_element_by_name(*dd, (void*) &n, nc, ns, a, ac, as, m, mc, ms, d, dc, ds);
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
--

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http uri query content. The destination details is null.");
    }
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
