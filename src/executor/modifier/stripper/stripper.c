/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STRIPPER_SOURCE
#define STRIPPER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../executor/modifier/stripper/leading_stripper.c"
#include "../../../executor/modifier/stripper/trailing_stripper.c"
#include "../../../logger/logger.c"

/**
 * Removes leading and trailing whitespaces from the string.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the destination array count
 * @param p2 the destination array size
 * @param p3 the source data
 * @param p4 the source count
 * @param p5 the type
 */
void strip(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Strip.");
    //?? fwprintf(stdout, L"Debug: Strip. type p5: %i\n", p5);
    //?? fwprintf(stdout, L"Debug: Strip. type *p5: %i\n", *((int*) p5));

    //
    // The string array data, count, size.
    //
    // It is used for temporary storage of the string
    // WITHOUT leading whitespaces.
    //
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int sc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ss = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Allocate string array.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array((void*) &sd, (void*) &ss, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Strip leading whitespaces from the string.
    strip_leading((void*) &sd, (void*) &sc, (void*) &ss, p3, p4, p5);
    // Strip trailing whitespaces from the string.
    strip_trailing(p0, p1, p2, sd, (void*) &sc, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Deallocate string array.
    //
    // CAUTION! The second argument "count" is NULL,
    // since it is only needed for looping elements of type PART,
    // in order to decrement the rubbish (garbage) collection counter.
    //
    deallocate_array((void*) &sd, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &ss, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* STRIPPER_SOURCE */
#endif
