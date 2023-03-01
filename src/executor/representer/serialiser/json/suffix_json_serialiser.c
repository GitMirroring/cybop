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

#ifndef SUFFIX_JSON_SERIALISER_SOURCE
#define SUFFIX_JSON_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/logifier/boolean/and_boolean_logifier.c"
#include "../../../../executor/representer/serialiser/json/indentation_json_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Appends part suffix to the destination item.
 *
 * It consists of the indentation spaces.
 *
 * This is done ONLY if both:
 * 1 the indentation flag IS set
 * 2 the source count handed over is NOT empty
 *
 * @param p0 the destination item
 * @param p1 the source count
 * @param p2 the indentation flag
 * @param p3 the tree level
 */
void serialise_json_suffix(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json suffix.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The boolean result.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check if source count is not empty.
    compare_integer_greater((void*) &r, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    //
    // Initialise boolean result with indentation flag.
    //
    // CAUTION! This IS necessary since the indentation flag
    // might be NULL, leading to a wrong boolean "true" result
    // when using it directly below and only one operand is true.
    //
    copy_integer((void*) &b, p2);
    // Check if indentation flag is set.
    logify_boolean_and((void*) &r, (void*) &b);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        serialise_json_indentation(p0, p3, p2);
    }
}

/* SUFFIX_JSON_SERIALISER_SOURCE */
#endif
