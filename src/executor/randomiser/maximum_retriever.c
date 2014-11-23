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

#ifndef MAXIMUM_RETRIEVER_SOURCE
#define MAXIMUM_RETRIEVER_SOURCE

#include <stdlib.h>

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../logger/logger.c"

/**
 * Retrieves next pseudo-random number in the series,
 * with the given maximum.
 *
 * The values are in the range: [0,max)
 * that is zero (inclusive) and the given maximum (exclusive).
 *
 * @param p0 the destination number
 * @param p1 the source maximum
 */
void retrieve_maximum(void* p0, void* p1) {

    // The maximum value the "rand" function can return.
    // CAUTION! The value is a macro and CANNOT be
    // handed over as reference directly.
    int mv = RAND_MAX;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_smaller_or_equal((void*) &r, p1, (void*) &mv);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? TODO: Delete this test message later!
        fwprintf(stdout, L"INFORMATION: Retrieve maximum. n: %i\n", *((int*) p1));
        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Retrieve maximum.");

        //
        // Some sources suggest using the modulo operator:
        //
        // 1 to get a number between 0 and n - 1:
        //     int r = rand() % n;
        //
        // 2 to get a number between min and max:
        //     int r = (rand() % (max - min + 1)) + min;
        //
        // However, there are TWO PROBLEMS with this solution:
        //
        // Problem 1:
        //
        // It does not uniformly give a number in the range [0, N)
        // unless N divides the length of the interval into
        // which rand() returns (i.e. is a power of 2).
        // In other words, it produces biased results,
        // when n is not an exact divisor of RAND_MAX.
        // The higher the value of n, the stronger this bias becomes.
        // Hence, this is mathematically wrong.
        //
        // To illustrate why this happens, let's imagine that
        // rand() would be implemented with a six-sided die.
        // So RAND_MAX would be 5. We want to use this die to
        // generate random numbers between 0 and 3, so we do this:
        //     int r = rand() % 4;
        //
        // The value of r for each of the six outcomes of rand is:
        //     0 % 4 = 0
        //     1 % 4 = 1
        //     2 % 4 = 2
        //     3 % 4 = 3
        //     4 % 4 = 0
        //     5 % 4 = 1
        //
        // As you can see, the numbers 0 and 1 will be generated
        // twice as often as the numbers 2 and 3.
        //
        // Problem 2:
        //
        // Furthermore, one has no idea whether the moduli
        // of rand() are independent. It's possible that they
        // go 0, 1, 2, ..., which is uniform but not very random.
        //
        // Solution:
        //
        // The only assumption it seems reasonable to make is
        // that rand() puts out a POISSON distribution:
        // Any two nonoverlapping subintervals of the
        // same size are equally likely and independent.
        // For a finite set of values, this implies a
        // uniform distribution and also ensures that
        // the values of rand() are nicely scattered.
        //
        // This means that the only correct way of changing
        // the range of rand() is to DIVIDE IT INTO BOXES.
        // For example, if RAND_MAX == 11 and one wants a range of 1..6,
        // one should assign {0,1} to 1, {2,3} to 2, and so on.
        // These are disjoint, equally-sized intervals and
        // thus are uniformly and independently distributed.
        //
        // The suggestion to use floating-point division
        // is mathematically plausible but suffers from
        // rounding issues in principle. Perhaps double is
        // high-enough precision to make it work; perhaps not.
        // In any case, the answer is system-dependent.
        // The correct way is to use INTEGER ARITHMETIC.
        //
        // https://stackoverflow.com/questions/12807459/generate-random-number-in-a-range-l-u?lq=1
        // https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range/6852396#6852396
        //

        //
        // The following algorithm was proposed by Ryan Reich at:
        // https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range/6852396#6852396
        //
        // long x; // This result type is okay, since: max <= RAND_MAX < ULONG_MAX
        // unsigned long num_bins = (unsigned long) max + 1; // number of bins, interval count
        // unsigned long num_rand = (unsigned long) RAND_MAX + 1; // interval maximum extended by one, since it is exclusive
        // unsigned long bin_size = num_rand / num_bins; // size of a bin, interval size
        // unsigned long defect   = num_rand % num_bins; // remainder
        // while (num_rand - defect <= (unsigned long) (x = random())); // This is carefully written not to overflow
        // x = x / bin_size; // Truncated division is intentional
        //

        //
        // ??TODO: The data type used here should be "unsigned long",
        // but the integer calculation functions use simple "int",
        // which leads to data loss.
        // Change this later. Possibly use "long long int" or
        // "unsigned long" everywhere in cyboi?
        //

        // The interval count.
        // CAUTION! Initialise with ONE and NOT zero,
        // in order to save one addition calculation below.
        unsigned long c = (unsigned long) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        calculate_integer_add((void*) &c, p1);
        // The maximum.
        unsigned long m = (unsigned long) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
        calculate_integer_add((void*) &m, (void*) &mv);
        // The interval size.
        unsigned long s = (unsigned long) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        calculate_integer_add((void*) &s, (void*) &m);
        calculate_integer_divide((void*) &s, (void*) &c);
        // The defect (remainder).
        unsigned long d = (unsigned long) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        calculate_integer_add((void*) &d, (void*) &m);
        calculate_integer_modulo((void*) &d, (void*) &c);
        // The multiple.
        unsigned long mul = (unsigned long) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // Initialise pseudo random number.
//??        long n = rand();
        long n;

        // The loop IS NECESSARY to get a perfectly uniform distribution.
        // For example, if being given random numbers from 0 to 2
        // and wanting only the ones from 0 to 1,
        // one just keeps pulling until not getting a 2.
        // This gives 0 or 1 with equal probability.

        //?? TEST
        while (m - d <= (unsigned long) (n = rand())); // This is carefully written not to overflow
/*??
        while (*NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"TEST: loop n: %i\n", n);

            // Calculate multiple [Vielfaches] dividable without remainder.
            mul = m - d;

            if (mul <= (unsigned long) n) {

                break;
            }

            // Get next pseudo-random number in the series.
            //
            // CAUTION! The value ranges from 0 (inclusive) to RAND_MAX (exclusive).
            // In the GNU C Library, RAND_MAX is 2147483647, which is
            // the largest signed integer representable in 32 bits.
            //
            // CAUTION! If calling "rand" before a seed has been established
            // with "srand", it uses the value 1 as a default seed.
            n = rand();
        }
*/

        //?? TODO: Delete this test message later!
        fwprintf(stdout, L"TEST: after loop c: %ul\n", c);
        fwprintf(stdout, L"TEST: after loop m: %ul\n", m);
        fwprintf(stdout, L"TEST: after loop s: %ul\n", s);
        fwprintf(stdout, L"TEST: after loop d: %ul\n", d);
        fwprintf(stdout, L"TEST: after loop n: %li\n", n);

        // Divide pseudo random number by interval size.
        // CAUTION! Truncated division is intentional.
        calculate_integer_divide((void*) &n, (void*) &s);
        fwprintf(stdout, L"TEST: after division n: %li\n", n);
        // Copy to destination number.
        copy_integer(p0, (void*) &n);

    } else {

        fwprintf(stdout, L"ERROR: Could not retrieve maximum. The maximum is greater than RAND_MAX. n: %i\n", *((int*) p1));
        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve maximum. The maximum is greater than RAND_MAX.");
    }
}

/* MAXIMUM_RETRIEVER_SOURCE */
#endif
