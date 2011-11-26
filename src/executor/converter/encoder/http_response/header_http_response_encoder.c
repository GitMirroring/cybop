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

#ifndef HEADER_HTTP_RESPONSE_ENCODER_SOURCE
#define HEADER_HTTP_RESPONSE_ENCODER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/http/http_cyboi_name.c"
#include "../../../../executor/converter/encoder/http_response/header_entry_http_response_encoder.c"
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
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* as = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate character array.
    allocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character array into multibyte character array.
    encode_integer((void*) &a, ac, as, p3, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

    overwrite_array(p0, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    overwrite_array(p0, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    // CAUTION! Use the message count (content length) integer value
    // that was handed over as parametre!
    select_http_response_header_entry_overwrite_array(p0, p1, p2, a, ac);
    overwrite_array(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Deallocate character array.
    deallocate_model((void*) &a, (void*) &ac, (void*) &as, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
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

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode http response header.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p4);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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
