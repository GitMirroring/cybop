/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef HELPER_SOURCE
#define HELPER_SOURCE

#include "../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../constant/model/cyboi/identification/identification_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../executor/memoriser/allocator/array_allocator.c"
#include "../executor/memoriser/deallocator/array_deallocator.c"
#include "../executor/modifier/overwrite_modifier.c"

/**
 * Writes cyboi help message to given output stream.
 *
 * @param p0 the output stream
 */
void help(void* p0) {

    // The message.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    int mc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Set size to arbitrary big value, so that message does
    // not have to be reallocated for every character below.
    // This lets the programme run faster.
    int ms = *NUMBER_1024_INTEGER_STATE_CYBOI_MODEL;

    // Allocate message.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &m, (void*) &ms, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Copy message.
    modify_overwrite((void*) &m, (void*) HELP_IDENTIFICATION_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) HELP_IDENTIFICATION_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &mc, (void*) &ms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    // Copy line feed control wide character.
    modify_overwrite((void*) &m, (void*) LINE_FEED_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &mc, (void*) &ms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    // Copy null termination wide character.
    modify_overwrite((void*) &m, (void*) NULL_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &mc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &mc, (void*) &ms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Log message.
    log_write(p0, m);

    // Deallocate message.
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    deallocate_array((void*) &m, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ms, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* HELPER_SOURCE */
#endif
