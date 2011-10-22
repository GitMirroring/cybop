/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: http_request_compound_selector.c,v $ $Revision: 1.1 $ $Date: 2009-02-17 23:20:03 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NAME_PARAMETER_QUERY_HTTP_URI_SELECTOR_SOURCE
#define NAME_PARAMETER_QUERY_HTTP_URI_SELECTOR_SOURCE

#include "../../../../../constant/abstraction/memory/primitive_memory_abstraction.c"
#include "../../../../../constant/model/log/message_log_model.c"
#include "../../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../../constant/name/uri/cyboi_uri_name.c"
#include "../../../../../constant/name/uri/separator_uri_name.c"
#include "../../../../../executor/converter/decoder/uri/http/fragment_http_uri_decoder.c"
#include "../../../../../executor/searcher/detector/array_detector.c"
#include "../../../../../executor/searcher/mover/position_mover.c"
#include "../../../../../logger/logger.c"
#include "../../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the http uri query parameter name.
 *
 * @param p0 the destination model item
 * @param p1 the destination details item
 * @param p2 the break flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 * @param p5 the parameter value (Hand over as reference!)
 * @param p6 the parameter value count
 */
void select_http_uri_query_parameter_name(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Select http uri query parameter name.");

    //
    // CAUTION! The order of the comparisons is IMPORTANT! Do NOT change it easily!
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_MEMORY_MODEL;

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) QUERY_PARAMETER_ASSIGNMENT_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_PRIMITIVE_MEMORY_ABSTRACTION, (void*) QUERY_PARAMETER_ASSIGNMENT_SEPARATOR_URI_NAME_COUNT, (void*) TRUE_BOOLEAN_MEMORY_MODEL);

        if (r != *FALSE_BOOLEAN_MEMORY_MODEL) {

            //
            // The separator = was found.
            // It serves as delimiter for the parameter name,
            // so that the calling function knows its count (length).
            // The remaining data represent the parameter value,
            // which was handed over to here and can now be assigned.
/*?? TODO!
            assign(p9, p7, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) POINTER_PRIMITIVE_MEMORY_ABSTRACTION);
            assign(p10, p8, (void*) NUMBER_0_INTEGER_MEMORY_MODEL, (void*) INTEGER_PRIMITIVE_MEMORY_ABSTRACTION);
*/

            // Set break flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_MEMORY_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_MEMORY_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE, (void*) NUMBER_1_INTEGER_MEMORY_MODEL);
    }
}

/* NAME_PARAMETER_QUERY_HTTP_URI_SELECTOR_SOURCE */
#endif
