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

#ifndef MESSAGE_LENGTH_OR_END_DESERIALISER_SOURCE
#define MESSAGE_LENGTH_OR_END_DESERIALISER_SOURCE

#include "../../../../constant/language/cyboi/state_cyboi_language.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/ftp_response_line_end/line_end_ftp_response_deserialiser.c"
#include "../../../../executor/representer/deserialiser/http_request_content_length/content_length_http_request_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the message and searches for either:
 *
 * - a prefix containing the message length (number of bytes)
 * - a suffix sequence marking the end of the message
 *
 * Which of both options is chosen depends upon the protocol used.
 *
 * @param p0 the complete flag
 * @param p1 the message length
 * @param p2 the message data
 * @param p3 the message count
 * @param p4 the language (protocol)
 */
void deserialise_message_length_or_end(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length or end.");
    fwprintf(stdout, L"Debug: Deserialise message length or end. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Deserialise message length or end. *p0: %i\n", *((int*) p0));
    fwprintf(stdout, L"Debug: Deserialise message length or end. p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Deserialise message length or end. *p4: %i\n", *((int*) p4));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A message end suffix does NOT exist in http request
            // and therefore the parametre p0 complete flag is NOT set.
            // Identifying the message (content) length header suffices here.
            //

            deserialise_http_request_content_length(p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p4, (void*) FTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A content length prefix does NOT exist in ftp response
            // and therefore the parametre p1 message length is NOT set.
            // Identifying the crlf line end separator suffices here.
            //

            deserialise_ftp_response_line_end(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length or end. The language (protocol) is not known.");
        fwprintf(stdout, L"Debug: Deserialise message length or end. The language (protocol) is not known. p4: %i\n", p4);
        fwprintf(stdout, L"Debug: Deserialise message length or end. The language (protocol) is not known. *p4: %i\n", *((int*) p4));
    }
}

/* MESSAGE_LENGTH_OR_END_DESERIALISER_SOURCE */
#endif
