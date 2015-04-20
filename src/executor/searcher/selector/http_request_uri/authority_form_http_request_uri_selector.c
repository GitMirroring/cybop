/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef AUTHORITY_FORM_HTTP_REQUEST_URI_SELECTOR_SOURCE
#define AUTHORITY_FORM_HTTP_REQUEST_URI_SELECTOR_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/uri/scheme_uri_model.c"
#include "../../../../constant/name/http_request_uri/http_request_uri_name.c"
#include "../../../../executor/representer/deserialiser/uri/http_uri_deserialiser.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

/**
 * Selects authority form http request uri.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void select_authority_form_http_request_uri(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select authority form http request uri.");

    //
    // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) AUTHORITY_FORM_HTTP_REQUEST_URI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) AUTHORITY_FORM_HTTP_REQUEST_URI_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* AUTHORITY_FORM_HTTP_REQUEST_URI_SELECTOR_SOURCE */
#endif
