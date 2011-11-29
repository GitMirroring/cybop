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

#ifndef STATUS_CODE_HTTP_RESPONSE_SERIALISER_SOURCE
#define STATUS_CODE_HTTP_RESPONSE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/http/status_code_http_model.c"
#include "../../../../constant/name/cyboi/http/http_cyboi_name.c"
#include "../../../../executor/searcher/selector/http_request/protocol_http_request_selector.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the http response status code.
 *
 * @param p0 the destination character item
 * @param p1 the source metadata type
 * @param p2 the source metadata type count
 * @param p3 the source metadata model
 * @param p4 the source metadata model count
 * @param p5 the source metadata properties
 * @param p6 the source metadata properties count
 */
void serialise_http_response_status_code(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise http response status code.");

    append_item_element(p0, (void*) OK_200_STATUS_CODE_HTTP_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) OK_200_STATUS_CODE_HTTP_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* STATUS_CODE_HTTP_RESPONSE_SERIALISER_SOURCE */
#endif
