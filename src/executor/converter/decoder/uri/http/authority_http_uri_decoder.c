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

#ifndef AUTHORITY_HTTP_URI_DECODER_SOURCE
#define AUTHORITY_HTTP_URI_DECODER_SOURCE

#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../executor/accessor/appender/part_appender.c"
#include "../../../../../executor/converter/selector/uri/http/authority_http_uri_selector.c"
#include "../../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../../logger/logger.c"

/**
 * Decodes the http uri authority content.
 *
 * The authority is added twice to the destination properties:
 * - as full text representation
 * - as hierarchy consisting of parts
 *
 * @param p0 the destination model item
 * @param p1 the source uri data
 * @param p2 the source uri count
 */
void decode_http_uri_authority_content(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode http uri authority content.");

    //
    // Add authority as full text representation.
    //

    append_item_allocate_part(p0, (void*) CYBOI_AUTHORITY_TEXT_URI_NAME, (void*) CYBOI_AUTHORITY_TEXT_URI_NAME_COUNT, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, p2, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    //
    // Add authority as hierarchy consisting of parts.
    //

    // The hierarchy part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hierarchy part model, properties.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* hd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate hierarchy part.
    allocate_part((void*) &h, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_STATE_CYBOI_TYPE);

    // Get hierarchy part model, properties.
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &hd, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Fill hierarchy part.
    overwrite_part_element(h, (void*) CYBOI_AUTHORITY_URI_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) CYBOI_AUTHORITY_URI_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(h, (void*) PART_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    receive_inline(hm, hd, p1, p2, (void*) AUTHORITY_TEXT_CYBOL_TYPE);

    // Append hierarchy part to destination model.
    append_item_element(p0, (void*) &h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/**
 * Decodes the http uri authority.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_http_uri_authority(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode http uri authority.");

    // The element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element.
    copy_pointer((void*) &e, p2);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_http_uri_authority(p0, p1, (void*) &b, p2, p3);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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
