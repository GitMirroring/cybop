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

#ifndef MODIFY_BOOLEAN_CYBOL_DESERIALISER_SOURCE
#define MODIFY_BOOLEAN_CYBOL_DESERIALISER_SOURCE

#include "../../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../../executor/modifier/item_modifier.c"
#include "../../../../../logger/logger.c"

/**
 * Appends or inserts boolean value to destination item.
 *
 * @param p0 the destination item
 * @param p1 the source value
 * @param p2 the prepend flag (false - append value at destination end; true - prepend value at destination beginning)
 * @param p3 the old destination item count (only needed if prepend flag is true, for insertion; may otherwise be null)
 */
void deserialise_cybol_boolean_modify(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol boolean modify.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The prepend flag is set to TRUE.
        // Therefore, insert value.
        //

        // Set value to "true", i.e. the integer value to "one".
        //
        // CAUTION! Do NOT use a simple "copy_integer" function here,
        // since that does NOT resize the destination item.
        // The "overwrite_item_element" function would be possible, too,
        // but "modify_item_element" is just more convenient.
        modify_item(p0, p1, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        //
        // The prepend flag is set to FALSE.
        // Therefore, append value.
        //

        // Set value to "false", i.e. the integer value to "zero".
        //
        // CAUTION! Do NOT use a simple "copy_integer" function here,
        // since that does NOT resize the destination item.
        // The "overwrite_item_element" function would be possible, too,
        // but "modify_item_element" is just more convenient.
        modify_item(p0, p1, (void*) BOOLEAN_LOGICVALUE_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    }
}

/* MODIFY_BOOLEAN_CYBOL_DESERIALISER_SOURCE */
#endif
