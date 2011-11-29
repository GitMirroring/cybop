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

#ifndef HTTP_RESPONSE_SERIALISER_SOURCE
#define HTTP_RESPONSE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/http_response/body_http_response_serialiser.c"
#include "../../../../executor/representer/serialiser/http_response/header_http_response_serialiser.c"
#include "../../../../executor/representer/serialiser/http_response/protocol_http_response_serialiser.c"
#include "../../../../executor/representer/serialiser/http_response/status_code_http_response_serialiser.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the compound into an http response.
 *
 * @param p0 the destination item
 * @param p1 the source message type
 * @param p2 the source message type count
 * @param p3 the source message model
 * @param p4 the source message model count
 * @param p5 the source message properties
 * @param p6 the source message properties count
 * @param p7 the source metadata type
 * @param p8 the source metadata type count
 * @param p9 the source metadata model
 * @param p10 the source metadata model count
 * @param p11 the source metadata properties
 * @param p12 the source metadata properties count
 */
void serialise_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise http response.");

    //
    // CAUTION! The body is encoded to UTF-8 first, so that its count
    // can be determined, since it has to be given as header value in http.
    //

    // The body item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The body item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate body item.
    allocate_item((void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Get body item data, count.
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode body wide character array into body multibyte character item.
    encode_utf_8(b, p3, p4);

    serialise_http_response_protocol(p0, p7, p8, p9, p10, p11, p12);
    append_item_element(p0, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    serialise_http_response_status_code(p0, p7, p8, p9, p10, p11, p12);
    append_item_element(p0, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    serialise_http_response_header(p0, p7, p8, p9, p10, p11, p12, bc);

    //
    // CAUTION! Do NOT add the BODY_BEGIN_SEPARATOR_HTTP_NAME
    // (twice carriage return and line feed).
    // One CR + LF was already added by HEADER_SEPARATOR_HTTP_NAME
    // inside the "serialise_http_response_header" function.
    // If there are no header entries (which shouldn't happen normally),
    // then one CR + LF was already added by
    // REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME above.
    // Therefore, ONLY ONE MORE CR + LF is to be added here.
    //
    append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // This function is commented out, since it is not needed for now.
    // Its content was moved directly into here (see above),
    // since the body count (length) needs to be determined.
    // serialise_http_response_body(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    // CAUTION! Append body ONLY here and NOT before,
    // since it has to stand at the end of the http message.
    append_item_element(p0, a, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, ac, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate body item.
    deallocate_item((void*) &b, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
