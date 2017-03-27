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

#ifndef PRIMITIVE_VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE
#define PRIMITIVE_VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE

#ifdef WIN32
    #include <windows.h>
#endif

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../../executor/modifier/item_modifier.c"
#include "../../../../../executor/representer/deserialiser/cybol/integer/value_integer_cybol_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the wide character data into an integer value primitive.
 *
 * @param p0 the destination data
 * @param p1 the source wchar_t data
 * @param p2 the source wchar_t count
 * @param p3 the number base:
 *           0 - tries to automatically identify the correct number base
 *           8 - octal, e.g. 083
 *           10 - decimal, e.g. 1234
 *           16 - hexadecimal, e.g. 3d4 or, optionally, 0x3d4
 * @param p4 the prepend flag (false - append value at destination end; true - prepend value at destination beginning)
 * @param p5 the old destination item count (only needed if prepend flag is true, for insertion; may otherwise be null)
 */
void deserialise_cybol_integer_value_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol integer value primitive.");

    // The temporary item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary item data.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate temporary item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    // Deserialise source.
    deserialise_cybol_integer_value(i, p1, p2, p3, p4, p5);

    // Get temporary item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Copy temporary value to destination.
    copy_integer(p0, id);

    // Deallocate temporary item.
    deallocate_item((void*) &i, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
}

/* PRIMITIVE_VALUE_INTEGER_CYBOL_DESERIALISER_SOURCE */
#endif
