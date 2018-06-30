/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VALUE_BOOLEAN_CYBOL_DESERIALISER_SOURCE
#define VALUE_BOOLEAN_CYBOL_DESERIALISER_SOURCE

#include "../../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../constant/model/cybol/state/boolean_state_cybol_model.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/checker/operation_checker.c"
#include "../../../../../executor/representer/deserialiser/cybol/boolean/modify_boolean_cybol_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the wide character data into an integer value
 * representing a boolean value of 0 or 1.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the prepend flag (false - append value at destination end; true - prepend value at destination beginning)
 * @param p4 the old destination item count (only needed if prepend flag is true, for insertion; may otherwise be null)
 */
void deserialise_cybol_boolean_value(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol boolean value.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) TRUE_BOOLEAN_STATE_CYBOL_MODEL, p2, (void*) TRUE_BOOLEAN_STATE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_boolean_modify(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p1, (void*) FALSE_BOOLEAN_STATE_CYBOL_MODEL, p2, (void*) FALSE_BOOLEAN_STATE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_cybol_boolean_modify(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol boolean value. The value cannot be interpreted.");
    }
}

/* VALUE_BOOLEAN_CYBOL_DESERIALISER_SOURCE */
#endif
