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

#ifndef HTTP_RESPONSE_SERIALISER_SOURCE
#define HTTP_RESPONSE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/serialiser/http_response/header_http_response_serialiser.c"
#include "../../../../executor/representer/serialiser/http_response/protocol_http_response_serialiser.c"
#include "../../../../executor/representer/serialiser/http_response/status_code_http_response_serialiser.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source into an http response.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the knowledge memory part
 */
void serialise_http_response(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise http response.");

    // The encoding part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoding part model item data.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The body item.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The body item data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get encoding part.
    get_part_knowledge((void*) &e, p3, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) ENCODING_SEND_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p4, p5);
    // Get encoding part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get encoding part model item data.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST serialise http response *p4: %i\n", *((int*) p4));
//?? fwprintf(stdout, L"TEST serialise http response *emd: %i\n", *((int*) emd));

    // Allocate body item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &b, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode body wide character array into body multibyte character item.
    //
    // CAUTION! The body has to be encoded FIRST, so that its count can be
    // determined, since it has to be given as header value in http.
    //
    encode(b, p1, p2, emd);

fwprintf(stdout, L"TEST serialise http response *p2: %i\n", *((int*) p2));
fwprintf(stdout, L"TEST serialise http response p1: %i\n", (wchar_t*) p1);

    // Get body item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bc, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Serialise protocol.
    serialise_http_response_protocol(p0);
    append_item_element(p0, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Serialise status.
    serialise_http_response_status_code(p0);
    append_item_element(p0, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Serialise header.
    // CAUTION! The body count is handed over as argument,
    // since it gets generated into the "Content-Length:" header.
    serialise_http_response_header(p0, p3, p4, bc);

    // Serialise separator.
    //
    // CAUTION! Do NOT add the BODY_BEGIN_SEPARATOR_HTTP_NAME
    // (twice carriage return and line feed).
    //
    // One CR + LF was already added by HEADER_SEPARATOR_HTTP_NAME
    // inside the "serialise_http_response_header" function.
    // If there are no header entries (which shouldn't happen normally),
    // then one CR + LF was already added by
    // REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME above.
    //
    // Therefore, only ONE more CR + LF is to be added here.
    //
    append_item_element(p0, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Serialise body.
    // CAUTION! Append body ONLY HERE and NOT before,
    // since it has to stand at the end of the http message.
    append_item_element(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, bc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate body item.
    deallocate_item((void*) &b, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //?? --- TEST ONLY ---
    void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* testc = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &testd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &testc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST serialise http response *testc: %i\n", *((int*) testc));
fwprintf(stdout, L"TEST serialise http response testd: %s\n", (char*) testd);
}

/* HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
