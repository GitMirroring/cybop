/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MESSAGE_LENGTH_DESERIALISER_SOURCE
#define MESSAGE_LENGTH_DESERIALISER_SOURCE

#include "../../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/binary_crlf_termination/binary_crlf_termination_deserialiser.c"
#include "../../../../executor/representer/deserialiser/ftp_line_end/ftp_line_end_deserialiser.c"
#include "../../../../executor/representer/deserialiser/http_request_content_length/http_request_content_length_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the message and searches for either:
 *
 * - a prefix containing the message length (number of bytes)
 * - a suffix sequence marking the end of the message
 *
 * Which of both options is chosen depends upon the language (protocol) used.
 *
 * @param p0 the destination message length
 * @param p1 the source message data
 * @param p2 the source message count
 * @param p3 the language (protocol)
 */
void deserialise_message_length(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length.");
    fwprintf(stdout, L"Debug: Deserialise message length. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Deserialise message length. *p0: %i\n", *((int*) p0));
    fwprintf(stdout, L"Debug: Deserialise message length. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise message length. *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) BINARY_CRLF_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A message length prefix does NOT exist.
            // Therefore, identify the message termination.
            //

            deserialise_binary_crlf_termination(p0, p1, p2);

            fwprintf(stdout, L"Debug: Deserialise message length. binary crlf p0: %i\n", p0);
            fwprintf(stdout, L"Debug: Deserialise message length. binary crlf *p0: %i\n", *((int*) p0));
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! An http message (request or response) HEADER section
            // is terminated by TWICE the suffix <cr> + <lf>.
            //
            // Additionally, the "Content-Length:" header MAY be given,
            // if the message contains a payload (appended data).
            //
            // The SUM of both equals the size of the complete message.
            //
            // CAUTION! Whilst a GET request contains just the header section,
            // a POST request will contain payload data, just as a response.
            //

            // The header length.
            int h = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            // The payload length.
            int p = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

            // Determine header length.
            deserialise_binary_crlf_termination((void*) &h, p1, p2);
            // Determine payload length.
            deserialise_http_request_content_length((void*) &p, p1, p2);

            fwprintf(stdout, L"Debug: Deserialise message length. http request h: %i\n", h);
            fwprintf(stdout, L"Debug: Deserialise message length. http request p: %i\n", p);

            //
            // Add header- and payload length.
            //
            // CAUTION! Do NOT add them if they have not been found before,
            // since adding the default value of -1 would falsify the result.
            //
            if (h >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //
                // Copy header length.
                //
                // CAUTION! Do NOT add but rather copy header length,
                // since the destination message length is -1 by default
                // and adding a value would falsify the result.
                //
                copy_integer(p0, (void*) &h);
                // Add double <cr> + <lf> separator length.
                calculate_integer_add(p0, (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);

                if (p >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    // Add payload length.
                    calculate_integer_add(p0, (void*) &p);
                }
            }

            fwprintf(stdout, L"Debug: Deserialise message length. http request p0: %i\n", p0);
            fwprintf(stdout, L"Debug: Deserialise message length. http request *p0: %i\n", *((int*) p0));
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) FTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A message length prefix does NOT exist.
            // Therefore, identify the message termination.
            //

            deserialise_ftp_line_end(p0, p1, p2);

            fwprintf(stdout, L"Debug: Deserialise message length. ftp response p0: %i\n", p0);
            fwprintf(stdout, L"Debug: Deserialise message length. ftp response *p0: %i\n", *((int*) p0));
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length. The language (protocol) is not known.");
        fwprintf(stdout, L"Debug: Deserialise message length. The language (protocol) is not known. p3: %i\n", p3);
        fwprintf(stdout, L"Debug: Deserialise message length. The language (protocol) is not known. *p3: %i\n", *((int*) p3));
    }
}

/* MESSAGE_LENGTH_DESERIALISER_SOURCE */
#endif
