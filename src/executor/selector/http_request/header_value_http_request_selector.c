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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Forward declaration
//

void deserialise_http_request_header_argument(void* p0, void* p1, void* p2, void* p3);

/**
 * Selects the http request header value.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the header value count
 * @param p5 the break flag
 */
void select_http_request_header_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http request header value.");

    //
    // CAUTION! The ORDER of the following comparisons is IMPORTANT!
    //
    // Before the header value http name or header http name
    // (ending with "carriage return" and "line feed")
    // can be identified, the possibility of a body begin
    // (twice "carriage return" and "line feed") indicating
    // the message body has to be considered:
    //
    // - twice "carriage return" and "line feed"
    // - "carriage return" and "line feed"
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) BODY_BEGIN_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BODY_BEGIN_SEPARATOR_HTTP_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request_body(p0, p1, p2, p3);

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p2, p3, (void*) HEADER_SEPARATOR_HTTP_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HEADER_SEPARATOR_HTTP_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_http_request_header_argument(p0, p1, p2, p3);

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The step.
        int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Move the current position.
        move(p2, p3, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust header value count.
        calculate_integer_add(p4, (void*) &step);
    }
}
