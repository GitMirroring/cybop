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

#ifndef ARRAY_CLONER_SOURCE
#define ARRAY_CLONER_SOURCE

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
 * Essentially, the "clone" function does nothing else than combining:
 * - allocation of a destination or cloning of a source element
 * - copying content from source to destination
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array
 * @param p2 the source count
 * @param p3 the type
 */
void clone_array(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** a = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Clone array.");

        // Allocate destination array.
        allocate_array(p0, p2, p3);

        if (*a != *NULL_POINTER_STATE_CYBOI_MODEL) {

            clone_array_type(*a, p1, p2, p3);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not clone array. The allocated destination array is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not clone array. The destination array is null.");
    }
}

/* ARRAY_CLONER_SOURCE */
#endif
