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

#ifndef MESSAGE_LENGTH_DESERIALISER_SOURCE
#define MESSAGE_LENGTH_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/ansi_escape_code_length/ansi_escape_code_length_deserialiser.c"
#include "../../../../executor/representer/deserialiser/binary_crlf_termination/binary_crlf_termination_deserialiser.c"
#include "../../../../executor/representer/deserialiser/ftp_line_end/ftp_line_end_deserialiser.c"
#include "../../../../executor/representer/deserialiser/http_request_message_length/http_request_message_length_deserialiser.c"
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

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length.");
    //?? fwprintf(stdout, L"Debug: Deserialise message length. language (protocol) p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise message length. language (protocol) *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) BINARY_CRLF_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A message length prefix does NOT exist in the language (protocol).
            // Therefore, identify the message termination.
            //

            deserialise_binary_crlf_termination(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) FTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! A message length prefix does NOT exist in the language (protocol).
            // Therefore, identify the message termination.
            //

            deserialise_ftp_line_end(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request_message_length(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) TUI_MESSAGE_STATE_CYBOI_LANGUAGE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_ansi_escape_code_length(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise message length. The language (protocol) is not known.");
        fwprintf(stdout, L"Warning: Deserialise message length. The language (protocol) is not known. p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Deserialise message length. The language (protocol) is not known. *p3: %i\n", *((int*) p3));
    }
}

/* MESSAGE_LENGTH_DESERIALISER_SOURCE */
#endif
