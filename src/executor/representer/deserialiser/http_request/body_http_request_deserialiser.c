/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BODY_HTTP_REQUEST_DESERIALISER_SOURCE
#define BODY_HTTP_REQUEST_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the http request body.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_http_request_body(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise http request body.");

        //
        // CAUTION! There is NO NEED to detect the body end with a
        // function like "select_http_request_body".
        // ALL of the REMAINING characters represent the body.
        //

        //
        // The body represents the actual http message content.
        // Its data are thus added to the destination MODEL,
        // whilst the destination PROPERTIES contain meta data, i.e. the http headers.
        //
        // CAUTION! The body data may be encoded.
        // Therefore, use the CHARACTER_TEXT_STATE_CYBOI_TYPE type here
        // (and DO NOT convert to WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE by chance).
        //
        // One of the http request header argument/value pairs defines the encoding,
        // so that the cybol application will have to decode the data,
        // because here, the corresponding http encoding header is not available.
        //
        modify_item(p0, *d, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise http request body. The source data position is null.");
    }
}

/* BODY_HTTP_REQUEST_DESERIALISER_SOURCE */
#endif
