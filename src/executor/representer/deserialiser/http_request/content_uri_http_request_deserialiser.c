/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_URI_HTTP_REQUEST_DESERIALISER_SOURCE
#define CONTENT_URI_HTTP_REQUEST_DESERIALISER_SOURCE

#include "../../../../constant/format/cybol/state/text_state_cybol_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/http/http_cyboi_name.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/overwriter/part_overwriter.c"
#include "../../../../executor/representer/deserialiser/http_request/decode_http_request_deserialiser.c"
#include "../../../../executor/searcher/selector/http_request/uri_http_request_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the http request uri content.
 *
 * The uri is added twice to the destination properties:
 * - as full text representation
 * - as hierarchy consisting of parts
 *
 * @param p0 the destination item
 * @param p1 the source uri data
 * @param p2 the source uri count
 */
void deserialise_http_request_uri_content(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise http request uri content.");

    // The character data, count, size.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cs = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    // Allocate character data.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &cd, (void*) &cs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // CAUTION! Percent-encoding may be used for all URI, including URL and URN.
    //

    // Decode percent-encoded character array into character data.
//??    deserialise_percent_encoding_vector((void*) &cd, (void*) &cc, (void*) &cs, p1, p2);

    //
    // Add uri as full text representation.
    //

    deserialise_http_request_decode(p0, (void*) URI_TEXT_HTTP_CYBOI_NAME, (void*) URI_TEXT_HTTP_CYBOI_NAME_COUNT, cd, (void*) &cc);

    //
    // Add uri as hierarchy consisting of parts.
    //

    // The uri part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The uri part model, properties.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate uri part.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get uri part model, properties.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Fill uri part.
    overwrite_part_element(p, (void*) URI_HTTP_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) URI_HTTP_CYBOI_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    overwrite_part_element(p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);
//??    receive_inline(pm, pd, cd, (void*) &cc, (void*) URI_TEXT_STATE_CYBOL_FORMAT);

    // Deallocate character data.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &cd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &cs, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Add uri part to destination item.
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection.
    append_item_element(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* CONTENT_URI_HTTP_REQUEST_DESERIALISER_SOURCE */
#endif
