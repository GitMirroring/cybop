/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE
#define TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/option/test_unit_option_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/test/test_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Selects the command line test unit option.
 *
 * @param p0 the test unit
 * @param p1 the test unit name data
 * @param p2 the test unit name count
 */
void select_command_line_test_unit(void* p0, void* p1, void* p2) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Select command line test unit.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) ALL_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) ALL_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) ALL_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) COPIER_TEST_UNIT_OPTION_CYBOI_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) COPIER_TEST_UNIT_OPTION_CYBOI_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) COPIER_TEST_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! DO NOT use logging functionality here!
        // The logger will not work before its options are set.
        log_write((void*) stdout, L"Warning: Could not select command line test unit. The test unit name is unknown.\n");
    }
}

/* TEST_UNIT_COMMAND_LINE_SELECTOR_SOURCE */
#endif
