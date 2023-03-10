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

#ifndef NUMBER_5001_END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE
#define NUMBER_5001_END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Checks if the field is permitted to be a child of the given compound field.
 *
 * If it is not, then the field demarcates the end of a compound field's children.
 *
 * @param p0 the end flag
 * @param p1 the next source field name
 */
void select_xdt_bdt_field_compound_end_5001(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt field compound end treatment data collection date.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1503_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1550_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_1560_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5002_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5003_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5004_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5005_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5006_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5007_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5008_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5009_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5011_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5012_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5013_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5015_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5016_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5017_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5018_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5019_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5020_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5023_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5024_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5025_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5026_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5034_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5035_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5036_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5037_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5038_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5039_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5040_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5042_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5044_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5098_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p1, (void*) NUMBER_5099_INTEGER_STATE_CYBOI_MODEL);
    }

   if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The source field did NOT match any of the
        // xdt constants listed above. That is, it is NOT
        // permitted to be a child of the current compound field.
        // Therefore, it demarcates the end of this list of child fields.

        // Set end flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* NUMBER_5001_END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE */
#endif
