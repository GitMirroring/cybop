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

#ifndef AUTHORITY_HTTP_URI_DECODER_SOURCE
#define AUTHORITY_HTTP_URI_DECODER_SOURCE

#include "../../../../../constant/model/log/message_log_model.c"
#include "../../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../executor/accessor/appender/part_appender.c"
#include "../../../../../executor/converter/selector/uri/http/authority_http_uri_selector.c"
#include "../../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../../logger/logger.c"

/**
 * Decodes the http uri authority content.
 *
 * The uri is added twice to the destination details:
 * - as full text representation
 * - as compound hierarchy consisting of parts
 *
 * @param p0 the destination model item
 * @param p1 the source uri
 * @param p2 the source uri count
 */
void decode_http_uri_authority_content(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_MEMORY_MODEL) {

        void** dd = (void**) p0;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http uri authority content.");

        //
        // Add authority as full text representation.
        //

        // The text part.
        void* t = *NULL_POINTER_MEMORY_MODEL;

        // Allocate text part.
        allocate_part((void*) &t, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION);

        // Fill text part.
        overwrite_part_element(t, (void*) CYBOI_AUTHORITY_TEXT_URI_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CYBOI_AUTHORITY_TEXT_URI_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
        overwrite_part_element(t, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);
        overwrite_part_element(t, p1, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, p2, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);

        // Append text part to destination model.
        append_item_element(p0, (void*) &t, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) NUMBER_1_INTEGER_MEMORY_MODEL, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

        //
        // Add authority as hierarchy consisting of parts.
        //

        // The hierarchy part.
        void* h = *NULL_POINTER_MEMORY_MODEL;
        // The hierarchy part model, details.
        void* hm = *NULL_POINTER_MEMORY_MODEL;
        void* hd = *NULL_POINTER_MEMORY_MODEL;

        // Allocate hierarchy part.
        allocate_part((void*) &h, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION);

        // Fill hierarchy part.
        overwrite_part_element(h, (void*) CYBOI_AUTHORITY_URI_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) CYBOI_AUTHORITY_URI_NAME_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
        overwrite_part_element(h, (void*) PART_PRIMITIVE_MEMORY_ABSTRACTION, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) ABSTRACTION_PART_MEMORY_NAME);

        // Get hierarchy part model, details.
        copy_array_forward((void*) &hm, h, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
        copy_array_forward((void*) &hd, h, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DETAILS_PART_MEMORY_NAME);

        // Receive hierarchy model, details.
        receive_inline(hm, hd, p1, p2, (void*) AUTHORITY_TEXT_CYBOL_ABSTRACTION);

        // Append hierarchy part to destination model.
        append_item_element(p0, (void*) &h, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) PRIMITIVE_MEMORY_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME);

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not decode http uri authority content. The destination details is null.");
    }
}

/**
 * Decodes the http uri authority.
 *
 * @param p0 the destination model item
 * @param p1 the destination details item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_http_uri_authority(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Decode http uri authority.");

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

        select_http_uri_authority(p0, p1, (void*) &b, p2, p3);

        if (b == *FALSE_BOOLEAN_MEMORY_MODEL) {

            // Increment element count.
            ec++;
        }
    }

    // The authority is always added, independent from whether
    // or not a path or query or fragment separator was found.
    //
    // If a path or query or fragment was found right at
    // the first position, then no authority was given.
    // In this case, an authority with empty value is added.
    decode_http_uri_authority_content(p0, e, (void*) &ec);
}

/* AUTHORITY_HTTP_URI_DECODER_SOURCE */
#endif
