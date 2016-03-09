/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SHALLOW_ARRAY_CLONER_SOURCE
#define SHALLOW_ARRAY_CLONER_SOURCE

#include <stdlib.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/basic/integer/multiply_integer_calculator.c"
#include "../../../executor/memoriser/size_determiner.c"
#include "../../../logger/logger.c"
#include "../../../variable/reference_counter.c"

/**
 * Clones the source array into the destination array.
 *
 * Handles elements representing primitive values.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the source count
 * @param p3 the type
 */
void clone_array_shallow(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Clone array shallow.");

    // The memory area.
    int ma = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Determine type size.
    determine_size((void*) &ma, p3);
    // Calculate memory area.
    calculate_integer_multiply((void*) &ma, p2);

    // The temporary size_t variable.
    //
    // CAUTION! It IS NECESSARY because on 64 Bit machines,
    // the "size_t" type has a size of 8 Byte,
    // whereas the "int" type has the usual size of 4 Byte.
    // When trying to cast between the two, memory errors
    // will occur and the valgrind memcheck tool report:
    // "Invalid read of size 8".
    //
    // CAUTION! Initialise temporary size_t variable with final int value
    // JUST BEFORE handing that over to the glibc function requiring it.
    //
    // CAUTION! Do NOT use cyboi-internal copy functions to achieve that,
    // because values are casted to int* internally again.
    size_t tma = (size_t) ma;

    // Clone source array by shallow copying values in memory bytewise.
    memcpy(p0, p1, tma);
}

/* SHALLOW_ARRAY_CLONER_SOURCE */
#endif
