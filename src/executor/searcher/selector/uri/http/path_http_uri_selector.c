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

#ifndef PATH_HTTP_URI_SELECTOR_SOURCE
#define PATH_HTTP_URI_SELECTOR_SOURCE

#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../constant/name/uri/separator_uri_name.c"
#include "../../../../../executor/converter/decoder/uri/http/fragment_http_uri_decoder.c"
#include "../../../../../executor/converter/decoder/uri/http/query_http_uri_decoder.c"
#include "../../../../../executor/searcher/detector/array_detector.c"
#include "../../../../../executor/searcher/mover/position_mover.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the http uri path.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void select_http_uri_path(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http uri path.");

    //
    // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) QUERY_BEGIN_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) QUERY_BEGIN_SEPARATOR_URI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_http_uri_query(p0, p1, p3, p4);

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) FRAGMENT_BEGIN_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) FRAGMENT_BEGIN_SEPARATOR_URI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_http_uri_fragment(p0, p1, p3, p4);

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* PATH_HTTP_URI_SELECTOR_SOURCE */
#endif
