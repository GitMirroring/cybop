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

#ifndef NAME_PARAMETRE_QUERY_HTTP_URI_SELECTOR_SOURCE
#define NAME_PARAMETRE_QUERY_HTTP_URI_SELECTOR_SOURCE

#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/uri/uri_cyboi_name.c"
#include "../../../../../constant/name/uri/separator_uri_name.c"
#include "../../../../../executor/representer/deserialiser/uri/http/fragment_http_uri_deserialiser.c"
#include "../../../../../executor/searcher/detector/array_detector.c"
#include "../../../../../executor/searcher/mover/position_mover.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the http uri query parametre name.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 * @param p5 the parametre value (pointer reference)
 * @param p6 the parametre value count
 */
void select_http_uri_query_parametre_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select http uri query parametre name.");

    //
    // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) QUERY_PARAMETRE_ASSIGNMENT_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) QUERY_PARAMETRE_ASSIGNMENT_SEPARATOR_URI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The separator = was found.
            // It serves as delimiter for the parametre name,
            // so that the calling function knows its count (length).
            // The remaining data represent the parametre value,
            // which was handed over to here and can now be assigned.
/*?? TODO!
            assign(p9, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);
            assign(p10, p8, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
*/

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* NAME_PARAMETRE_QUERY_HTTP_URI_SELECTOR_SOURCE */
#endif
