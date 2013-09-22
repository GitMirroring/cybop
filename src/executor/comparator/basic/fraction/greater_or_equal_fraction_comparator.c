/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GREATER_OR_EQUAL_FRACTION_COMPARATOR_SOURCE
#define GREATER_OR_EQUAL_FRACTION_COMPARATOR_SOURCE

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/fraction_state_cyboi_name.c"
#include "../../../../executor/calculator/basic/integer/multiply_integer_calculator.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/modifier/copier/fraction_copier.c"

/**
 * Compares the left- with the right fraction for greaterness and equality.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void compare_fraction_greater_or_equal(void* p0, void* p1, void* p2) {

    // The left numerator, denominator.
    void* ln = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The right numerator, denominator.
    void* rn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination numerator.
    copy_array_forward((void*) &ln, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    // Get destination denominator.
    copy_array_forward((void*) &ld, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source numerator.
    copy_array_forward((void*) &rn, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    // Get source denominator.
    copy_array_forward((void*) &rd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);

    if (rd != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (rn != *NULL_POINTER_STATE_CYBOI_MODEL) {

            if (ld != *NULL_POINTER_STATE_CYBOI_MODEL) {

                if (ln != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // The expanded left numerator, right numerator.
                    // CAUTION! Initialise with ln and rn, respectively,
                    // since they are multiplied with their denominators below.
                    int eln = *((int*) ln);
                    int ern = *((int*) rn);

                    // Calculate expanded left numerator, right numerator.
                    // CAUTION! Multiplicate cross-wise.
                    calculate_integer_multiply((void*) &eln, (void*) &rd);
                    calculate_integer_multiply((void*) &ern, (void*) &ld);

                    if (eln >= ern) {

                        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare fraction. The left numerator is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare fraction. The left denominator is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare fraction. The right numerator is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not compare fraction. The right denominator is null.");
    }
}

/* GREATER_OR_EQUAL_FRACTION_COMPARATOR_SOURCE */
#endif
