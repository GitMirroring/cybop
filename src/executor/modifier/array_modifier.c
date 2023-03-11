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

#ifndef ARRAY_MODIFIER_SOURCE
#define ARRAY_MODIFIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/modifier/filler/filler.c"
#include "../../executor/modifier/inserter/inserter.c"
#include "../../executor/modifier/lowerer/lowerer.c"
#include "../../executor/modifier/normaliser/normaliser.c"
#include "../../executor/modifier/overwriter/overwriter.c"
#include "../../executor/modifier/remover/remover.c"
#include "../../executor/modifier/repeater/repeater.c"
#include "../../executor/modifier/replacer/replacer.c"
#include "../../executor/modifier/reverser/reverser.c"
#include "../../executor/modifier/stripper/leading_stripper.c"
#include "../../executor/modifier/stripper/stripper.c"
#include "../../executor/modifier/stripper/trailing_stripper.c"
#include "../../executor/modifier/upperer/upperer.c"
#include "logger.h"

/**
 * Modifies the destination array using the given operation.
 *
 * @param p0 the destination array (pointer reference)
 * @param p1 the source array (should be null for remove)
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index (should be null for append)
 * @param p6 the source index (should be null for remove)
 * @param p7 the destination array count
 * @param p8 the destination array size
 * @param p9 the adjust count flag (should be null for append and insert)
 * @param p10 the repetition number for "modify/repeat"
 * @param p11 the searchterm data for "modify/replace"
 * @param p12 the searchterm count for "modify/replace"
 * @param p13 the operation type
 */
void modify_array(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify array.");
    //?? fwprintf(stdout, L"Debug: Modify array. p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Modify array. *p13: %i\n", *((int*) p13));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Append source to destination.
            //
            // CAUTION! Hand over the destination array count TWICE,
            // as destination index (sixth parametre, INSTEAD of p5)
            // AND as destination array count (eighth parametre)
            //
            // CAUTION! Set adjust count flag to TRUE,
            // since destination gets extended by append.
            //
            overwrite(p0, p1, p2, p3, p4, p7, p6, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) EMPTY_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Remove all elements from array.
            //
            // CAUTION! Hand over the destination array count p7 TWICE,
            // as count of elements to be removed (third parametre, INSTEAD of p4)
            // AND as destination array count (fifth parametre).
            //
            remove_data(p0, p2, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) FILL_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fill(p0, p1, p2, p3, p4, p5, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) INSERT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            insert(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) LOWER_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            lower(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) NORMALISE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            normalise(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            remove_data(p0, p2, p4, p5, p7, p8, p9);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) REPEAT_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            repeat(p0, p7, p8, p1, p4, p10, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) REPLACE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            replace(p0, p7, p8, p1, p4, p11, p12, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) REVERSE_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            reverse(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) STRIP_LEADING_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            strip_leading(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) STRIP_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            strip(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) STRIP_TRAILING_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            strip_trailing(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p13, (void*) UPPER_MODIFY_LOGIC_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            upper(p0, p7, p8, p1, p4, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not modify array. The operation type is unknown.");
        fwprintf(stdout, L"Warning: Could not modify array. The operation type is unknown. p13: %i\n", p13);
        fwprintf(stdout, L"Warning: Could not modify array. The operation type is unknown. *p13: %i\n", *((int*) p13));
    }
}

/* ARRAY_MODIFIER_SOURCE */
#endif
