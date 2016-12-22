/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_BOOLEAN_CYBOL_SERIALISER_SOURCE
#define SEPARATOR_BOOLEAN_CYBOL_SERIALISER_SOURCE

#include "../../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/comparator/basic/integer/unequal_integer_comparator.c"
#include "../../../../../logger/logger.c"

/**
 * Serialises the boolean separator.
 *
 * @param p0 the destination item
 * @param p1 the source boolean index
 */
void serialise_cybol_boolean_separator(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise cybol boolean separator.");

    // The index flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Test if this is NOT the first value.
    compare_integer_unequal((void*) &f, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append comma prefix if this is NOT the first value.
        append_item_element(p0, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* SEPARATOR_BOOLEAN_CYBOL_SERIALISER_SOURCE */
#endif
