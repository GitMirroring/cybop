/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Sandra Rum <sandra.rum@cs12-2.ba-leipzig.de>
 */

#ifndef RETRIEVER_SOURCE
#define RETRIEVER_SOURCE

#include <stdlib.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Retrieves next pseudo-random number in the series.
 *
 * @param p0 the destination number
 * @param p1 the source minimum
 * @param p2 the source maximum
 */
void retrieve(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* max = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* min = (int*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* n = (int*) p0;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Retrieve.");

                // Get next pseudo-random number in the series.
                //
                // CAUTION! The value ranges from 0 (inclusive) to RAND_MAX (exclusive).
                // In the GNU C Library, RAND_MAX is 2147483647, which is
                // the largest signed integer representable in 32 bits.
                //
                // CAUTION! If calling "rand" before a seed has been established
                // with "srand", it uses the value 1 as a default seed.
                int r = rand();

                // Normalise to area between minimum and maximum.

                //?? TODO

                // Copy to destination number.
                copy_integer(p0, (void*) &r);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve. The destination number is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve. The source minimum is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve. The source maximum is null.");
    }
}

/* RETRIEVER_SOURCE */
#endif
