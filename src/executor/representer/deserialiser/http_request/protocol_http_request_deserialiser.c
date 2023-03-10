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

#ifndef PROTOCOL_HTTP_REQUEST_DESERIALISER_SOURCE
#define PROTOCOL_HTTP_REQUEST_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/deserialiser/http_request/decode_http_request_deserialiser.c"
#include "../../../../executor/selector/http_request/protocol_http_request_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the http request protocol.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_http_request_protocol(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise http request protocol.");

    // The protocol data, count.
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int pc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise protocol data.
    copy_pointer((void*) &pd, p2);

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_http_request_protocol(p0, p1, p2, p3, (void*) &pc, (void*) &b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request_decode(p1, (void*) PROTOCOL_HTTP_CYBOI_NAME, (void*) PROTOCOL_HTTP_CYBOI_NAME_COUNT, pd, (void*) &pc);

            break;
        }
    }
}

/* PROTOCOL_HTTP_REQUEST_DESERIALISER_SOURCE */
#endif
