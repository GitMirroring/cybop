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

#ifndef URI_HTTP_REQUEST_DECODER_SOURCE
#define URI_HTTP_REQUEST_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/http/cyboi_http_name.c"
#include "../../../../executor/accessor/appender/part_appender.c"
#include "../../../../executor/converter/decoder/percent_encoding_vector_decoder.c"
#include "../../../../executor/converter/selector/http_request/uri_http_request_selector.c"
#include "../../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the http request uri content.
 *
 * The uri is added twice to the destination properties:
 * - as full text representation
 * - as hierarchy consisting of parts
 *
 * @param p0 the destination properties item
 * @param p1 the source uri data
 * @param p2 the source uri count
 */
void decode_http_request_uri_content(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode http request uri content.");

    // The character data, count, size.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cs = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate character data.
    allocate_array((void*) &cd, (void*) &cs, (void*) CHARACTER_STATE_CYBOI_TYPE);

    //
    // CAUTION! Percent-encoding may be used for all URI, including URL and URN.
    //

    // Decode percent-encoded character array into character data.
    decode_percent_encoding_vector((void*) &cd, (void*) &cc, (void*) &cs, p1, p2);

    //
    // Add uri as full text representation.
    //

    append_item_allocate_part_decode_character(p0, (void*) CYBOI_URI_TEXT_HTTP_NAME, (void*) CYBOI_URI_TEXT_HTTP_NAME_COUNT, cd, (void*) &cc);

    //
    // Add uri as hierarchy consisting of parts.
    //

    // The uri part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The uri part model, properties.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate uri part.
    allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Get uri part model, properties.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Fill uri part.
    overwrite_part_element(p, (void*) CYBOI_URI_HTTP_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) CYBOI_URI_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) PART_STATE_CYBOI_TYPE, (void*) INTEGER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    receive_inline(pm, pd, cd, (void*) &cc, (void*) URI_TEXT_CYBOL_TYPE);

    // Deallocate character data.
    deallocate_array((void*) &cd, (void*) &cs, (void*) CHARACTER_STATE_CYBOI_TYPE);

    // Add uri part to destination item.
    append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/**
 * Decodes the http request uri.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void decode_http_request_uri(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode http request uri.");

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

        select_http_request_uri(p0, p1, (void*) &b, p2, p3);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_http_request_uri_content(p1, e, (void*) &ec);

            break;

        } else {

            // Increment uri count.
            ec++;
        }
    }
}

/* URI_HTTP_REQUEST_DECODER_SOURCE */
#endif
