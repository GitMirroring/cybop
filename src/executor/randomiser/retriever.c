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
 * @author Sandra Rum <sandra.rum@cs12-2.ba-leipzig.de>
 */

#ifndef RETRIEVER_SOURCE
#define RETRIEVER_SOURCE

//
// Library interface
//

#include "constant.h"
#include "logger.h"

//
// Executable interface
//

#include "../../executor/randomiser/maximum_retriever.c"

/**
 * Retrieves next pseudo-random number in the series.
 *
 * @param p0 the destination number
 * @param p1 the source minimum
 * @param p2 the source maximum
 */
void retrieve(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Retrieve.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_less((void*) &r, p1, p2);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The range is applied by shifting it using the formula:
        //     int r = min + retrieve_pseudo_random_number_with_given_maximum(max - min + 1)
        // This also works with negative values.
        //

        // The pseudo random number.
        int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The shifted maximum.
        int max = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Initialise shifted maximum.
        copy_integer((void*) &max, p2);
        // Shift range [min,max) to range [0,max - min).
        calculate_integer_subtract((void*) &max, p1);
        //
        // Retrieve pseudo random number.
        //
        // For testing, the following source code line may be used:
        // n = rand() % max;
        //
        // However, for reasons explained in file "maximum_retriever.c",
        // using the modulo operator is mathematically not quite correct.
        //
        retrieve_maximum((void*) &n, (void*) &max);
        // Shift back pseudo random number into original range [min,max].
        calculate_integer_add((void*) &n, p1);
        // Copy to destination number.
        copy_integer(p0, (void*) &n);

    } else {

        //?? TODO: Delete this test message later!
        fwprintf(stdout, L"Error: Could not retrieve. The minimum is greater or equal to the maximum. r: %i\n", r);
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve. The minimum is greater or equal to the maximum.");
    }
}

/* RETRIEVER_SOURCE */
#endif
