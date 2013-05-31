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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ARRAY_DETECTOR_SOURCE
#define ARRAY_DETECTOR_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/searcher/mover/position_mover.c"
#include "../../../logger/logger.c"

/**
 * Detects the given array.
 *
 * This code was moved into its own function, because:
 * - the current position pointer needs to be dereferenced
 * - the element count and remaining count need to be compared
 *   in order to avoid crossing array boundaries
 * - the current position and remaining count are moved automatically
 *
 * Example calls of this function for ascii characters:
 * detect_element(p0, p1, p2, p3, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, p7);
 *
 * Example calls of this function for wide characters:
 * detect_array((void*) &r, p7, p8, (void*) QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) QUERY_PARAMETRE_BEGIN_SEPARATOR_URI_NAME_COUNT, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
 *
 * @param p0 the comparison result
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the data
 * @param p4 the type
 * @param p5 the count
 * @param p6 the move flag
 */
void detect_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* m = (int*) p6;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* r = (int*) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Detect array.");

            // The count flag.
            int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            // CAUTION! This comparison ensures that array boundaries are not crossed.
            // The count is used for both, the array AND source data.
            compare_integer_greater_or_equal((void*) &c, p2, p5);

            if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // CAUTION! The remaining count may NOT be handed over as position count,
                // since it might be greater than the array count and would thus differ.
                compare_all_array(p0, *((void**) p1), p3, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, p4, p5, p5);

                if (*r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (*m != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        move_position(p1, p2, p4, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
                    }
                }

            } else {

                log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not detect array. The remaining count is smaller than the array count.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not detect array. The comparison result is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not detect array. The move flag is null.");
    }
}

/* ARRAY_DETECTOR_SOURCE */
#endif
