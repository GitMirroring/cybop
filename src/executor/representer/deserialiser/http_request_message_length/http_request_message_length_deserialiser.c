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

#ifndef HTTP_REQUEST_MESSAGE_LENGTH_DESERIALISER_SOURCE
#define HTTP_REQUEST_MESSAGE_LENGTH_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/blank_line_termination/blank_line_termination_deserialiser.c"
#include "../../../../executor/representer/deserialiser/http_request_content_length/http_request_content_length_deserialiser.c"
#include "logger.h"

/**
 * Deserialises the http request message length.
 *
 * @param p0 the destination message length
 * @param p1 the source message data
 * @param p2 the source message count
 */
void deserialise_http_request_message_length(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise http request message length.");
    //?? fwprintf(stdout, L"Debug: Deserialise http request message length. source message count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise http request message length. source message count *p2: %i\n", *((int*) p2));

    //
    // CAUTION! An http message (request or response) HEADER section
    // is terminated by a blank line, that is TWICE the suffix <cr> + <lf>.
    //
    // Additionally, the "Content-Length:" header MAY be given,
    // if the message contains a payload (appended data).
    //
    // The SUM of both equals the size of the complete message.
    //
    // CAUTION! Whilst a GET request contains just the header section,
    // a POST request will contain payload data, just like a response.
    //

    // The header length.
    int h = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The payload length.
    int p = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Determine header length.
    deserialise_blank_line_termination((void*) &h, p1, p2);
    // Determine payload length.
    deserialise_http_request_content_length((void*) &p, p1, p2);

    //?? fwprintf(stdout, L"Debug: Deserialise http request message length. header h: %i\n", h);
    //?? fwprintf(stdout, L"Debug: Deserialise http request message length. payload p: %i\n", p);

    //
    // Add header- and payload length.
    //
    // CAUTION! Do NOT add header length if it has not been found before,
    // since adding the default value of -1 would falsify the result.
    //
    if (h >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        //
        // Copy header length.
        //
        // CAUTION! Do NOT add but rather COPY header length,
        // since the destination message length is -1 by default
        // and adding a value would falsify the result.
        //
        copy_integer(p0, (void*) &h);

        if (p >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // Add payload length.
            //
            // CAUTION! Do NOT add payload length if it has not been found before,
            // since adding the default value of -1 would falsify the result.
            //
            calculate_integer_add(p0, (void*) &p);
        }
    }
}

/* HTTP_REQUEST_MESSAGE_LENGTH_DESERIALISER_SOURCE */
#endif
