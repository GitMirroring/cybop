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

#ifndef SOWER_SOURCE
#define SOWER_SOURCE

//
// System interface
//

#include <stdlib.h> // srand

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Sows a seed for a new series of pseudo-random numbers.
 *
 * @param p0 the source seed
 */
void sow(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sow.");

        // The numbers generated here are not truly random,
        // which is why they are called "pseudo-random".
        // Typically, they form a sequence that repeats periodically,
        // with a period so large that you can ignore it for ordinary purposes.
        // The random number generator works by remembering a seed value
        // which it uses to compute the next random number and also to compute a new seed.
        //
        // Although the generated numbers look unpredictable within one run of a program,
        // the sequence of numbers is exactly the same from one run to the next.
        // This is because the initial seed is always the same.
        // If a different pseudo-random series is wanted each time a program runs,
        // one must specify a different seed each time.
        // For ordinary purposes, basing the seed on the current time works well.
        //
        // One can obtain repeatable sequences of numbers on a particular machine type
        // by specifying the same initial seed value for the random number generator.
        // There is no standard meaning for a particular seed value;
        // the same seed, used in different C libraries or on different
        // CPU types, will deliver different random numbers.

        //?? TODO: A standard "int" is too small to capture a seed,
        //?? which is of type "unsigned int".
        //?? Possibly switch all "int" types within cyboi into "long int" or "unsigned int"?

        // Establish seed for new series of pseudo-random numbers.
        srand(*s);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sow. The source seed is null.");
    }
}

/* SOWER_SOURCE */
#endif
