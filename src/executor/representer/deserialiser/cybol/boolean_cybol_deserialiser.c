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

#ifndef BOOLEAN_CYBOL_DESERIALISER_SOURCE
#define BOOLEAN_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cybol/state/boolean_state_cybol_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the boolean wide character data into an integer.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_boolean(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol boolean.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) TRUE_BOOLEAN_STATE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) TRUE_BOOLEAN_STATE_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set value to "true", i.e. the integer value to "one".
            // CAUTION! Do NOT use a simple "copy_integer" function here,
            // since that does NOT resize the destination item.
            // The "overwrite_item_element" function would be possible, too,
            // but "append_item_element" is just more convenient.
            append_item_element(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) FALSE_BOOLEAN_STATE_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_FORMAT_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) FALSE_BOOLEAN_STATE_CYBOL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set value to "false", i.e. the integer value to "zero".
            // CAUTION! Do NOT use a simple "copy_integer" function here,
            // since that does NOT resize the destination item.
            // The "overwrite_item_element" function would be possible, too,
            // but "append_item_element" is just more convenient.
            append_item_element(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol boolean. The value cannot be interpreted.");
    }
}

/* BOOLEAN_CYBOL_DESERIALISER_SOURCE */
#endif
