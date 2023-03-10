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

#ifndef BREAK_JSON_SERIALISER_SOURCE
#define BREAK_JSON_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Appends two line breaks.
 *
 * This is done ONLY if the indentation flag is set.
 *
 * @param p0 the destination item
 * @param p1 the indentation flag
 */
void serialise_json_break(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise json break.");
    //?? fwprintf(stdout, L"Debug: Serialise json break. indentation flag p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Serialise json break. indentation flag *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append TWO line feed characters.
        modify_item(p0, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    }
}

/* BREAK_JSON_SERIALISER_SOURCE */
#endif
