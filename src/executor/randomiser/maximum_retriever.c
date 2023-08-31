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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Sandra Rum <sandra.rum@cs12-2.ba-leipzig.de>
 */

//
// System interface
//

#include <stdlib.h> // rand

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "logger.h"

/**
 * Retrieves next pseudo-random number in the series,
 * with the given maximum.
 *
 * The values are in the range: [0,max]
 * that is zero AND the given maximum are INCLUSIVE.
 *
 * @param p0 the destination number
 * @param p1 the source maximum
 */
void retrieve_maximum(void* p0, void* p1) {

    //?? TODO: This test for null may be REMOVED when "int" has been replaced by "long long int", so that below commented functions may be used.
    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* max = (int*) p1;

        //?? TODO: This test for null may be REMOVED when "int" has been replaced by "long long int", so that below commented functions may be used.
        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* dest = (int*) p0;

            // The maximum value the "rand" function can return.
            // CAUTION! The value is a macro and CANNOT be
            // handed over as reference directly.
            int mv = RAND_MAX;
            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_less_or_equal((void*) &r, p1, (void*) &mv);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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
                //
                // The following algorithm was proposed by Ryan Reich at:
                // https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range/6852396#6852396
                //

                // The interval count (number of bins).
                // CAUTION! Extend by one, in order to INCLUDE the
                // possible maximum, so that [0,max) becomes [0,max]
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                // CAUTION! Initialise with ONE and NOT zero,
                // in order to save one addition calculation below.
                long long int c = (long long int) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                calculate_integer_add((void*) &c, p1);
*/
                // CAUTION! Convert to greater number range FIRST,
                // BEFORE adding number 1.
                unsigned long int c = (unsigned long) *max;
                c += *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                // The maximum random value range.
                // CAUTION! Extend by one, in order to INCLUDE the
                // possible maximum, so that [0,RAND_MAX) becomes [0,RAND_MAX]
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                // CAUTION! Initialise with ONE and NOT zero,
                // in order to save one addition calculation below.
                long long int m = (long long int) *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
                calculate_integer_add((void*) &m, (void*) &mv);
*/
                // CAUTION! Convert to greater number range FIRST,
                // BEFORE adding number 1.
                unsigned long int m = (unsigned long) mv;
                m += *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                // The interval size (size of one bin).
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                long long int s = (long long int) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                calculate_integer_add((void*) &s, (void*) &m);
                calculate_integer_divide((void*) &s, (void*) &c);
*/
                unsigned long int s = m / c;

                // The defect (remainder).
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                long long int d = (long long int) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                calculate_integer_add((void*) &d, (void*) &m);
                calculate_integer_modulo((void*) &d, (void*) &c);
*/
                unsigned long int d = m % c;

                // The multiple [Vielfaches] dividable without remainder.
                unsigned long int mul = m - d;

                //
                // The pseudo random number.
                //
                // CAUTION! The type "long" is okay, since:
                // max <= RAND_MAX < ULONG_MAX
                //
                // CAUTION! Initialise with a random number here since otherwise,
                // at least two loop cycles are necessary to find an initial number below.
                //
                // CAUTION! Do NOT initialise with zero or similar since otherwise,
                // that value will be returned as always identical result.
                //
                // CAUTION! The value ranges from 0 (inclusive) to RAND_MAX (exclusive).
                // In the GNU C Library, RAND_MAX is 2147483647, which is
                // the largest signed integer representable in 32 bits.
                //
                // CAUTION! If calling "rand" before a seed has been established
                // with "srand", it uses the value 1 as a default seed.
                //
                // CAUTION! The bsd "random" function is claimed to have a
                // better distribution than the glibc "rand" function
                // (noted by the man page for "rand"), as Ryan Reich wrote at:
                // https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range/6852396#6852396
                // However, since "random" is a BSD function, the compilation failes
                // with mingw, because it is not supported on Windows OS.
                // Therefore, the standard glibc "rand" function is used here.
                //
                long int n = (long int) rand();

                //
                // The loop IS NECESSARY to get a perfectly uniform distribution.
                // For example, if being given random numbers from 0 to 2
                // and wanting only the ones from 0 to 1,
                // one just keeps pulling until not getting a 2.
                // This gives 0 or 1 with equal probability.
                //
                // CAUTION! This is carefully written not to overflow.
                //
                while (*NUMBER_1_INTEGER_STATE_CYBOI_MODEL) {

                    // The loop is left as soon as a random number is found
                    // that lies within the given range "mul".
                    // Any other random numbers outside (in the remainder)
                    // are ignored, so that all intervals have an equal chance.
                    if (mul > ((unsigned long) n)) {

                        break;
                    }

                    //
                    // Get next pseudo-random number in the series.
                    //
                    // CAUTION! The value ranges from 0 (inclusive) to RAND_MAX (exclusive).
                    // In the GNU C Library, RAND_MAX is 2147483647, which is
                    // the largest signed integer representable in 32 bits.
                    //
                    // CAUTION! If calling "rand" before a seed has been established
                    // with "srand", it uses the value 1 as a default seed.
                    //
                    // CAUTION! The bsd "random" function is claimed to have a
                    // better distribution than the glibc "rand" function
                    // (noted by the man page for "rand"), as Ryan Reich wrote at:
                    // https://stackoverflow.com/questions/2509679/how-to-generate-a-random-number-from-within-a-range/6852396#6852396
                    // However, since "random" is a BSD function, the compilation failes
                    // with mingw, because it is not supported on Windows OS.
                    // Therefore, the standard glibc "rand" function is used here.
                    //
                    n = (long int) rand();
                }

                // Divide pseudo random number by interval size.
                // CAUTION! The truncated division is intentional.
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                calculate_integer_divide((void*) &n, (void*) &s);
*/
                n = n / s;

                // Copy to destination number.
/*?? TODO: The following functions may NOT be used as long as they use "int" and not "long long int" internally.
                copy_integer(p0, (void*) &n);
*/
                *dest = (int) n;

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve maximum. The maximum is greater than RAND_MAX.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve maximum. The destination number is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not retrieve maximum. The source maximum is null.");
    }
}
