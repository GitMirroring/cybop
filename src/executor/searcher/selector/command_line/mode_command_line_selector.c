/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MODE_COMMAND_LINE_SELECTOR_SOURCE
#define MODE_COMMAND_LINE_SELECTOR_SOURCE

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/operation_mode/operation_mode_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/option/option_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/searcher/selector/command_line/log_level_command_line_selector.c"
#include "../../../../executor/searcher/selector/command_line/test_unit_command_line_selector.c"

/**
 * Selects the cyboi operation mode.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the test unit
 * @param p4 the terminated log file name item (multibyte character data)
 * @param p5 the value data
 * @param p6 the value count
 * @param p7 the option data
 * @param p8 the option count
 */
void select_command_line_mode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Select command line mode.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) HELP_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) HELP_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set help operation mode.
            copy_integer(p0, (void*) HELP_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) KNOWLEDGE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) KNOWLEDGE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy file path from value to cybol knowledge file path.
            append_item_element(p1, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p6, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            // Set knowledge operation mode.
            copy_integer(p0, (void*) KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) LOG_FILE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) LOG_FILE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Encode wide character value data into multibyte character array filename data.
            encode_utf_8(p4, p5, p6);

            // Add null termination character to terminated file name.
            append_item_element(p4, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) LOG_LEVEL_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) LOG_LEVEL_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set log level.
            select_command_line_log_level(p2, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) TEST_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) TEST_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set test unit.
            select_command_line_test_unit(p3, p5, p6);

            // Set test operation mode.
            copy_integer(p0, (void*) TEST_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p7, (void*) VERSION_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) VERSION_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set version operation mode.
            copy_integer(p0, (void*) VERSION_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // If no option was given, then assume "--knowledge" as default.
        // This is just convenient when starting cybol applications like:
        // cyboi helloworld/run.cybol
        // Other interpreters like "perl", "php" etc. do it the same way.

        // Copy file path from OPTION to cybol knowledge file path.
        //
        // CAUTION! The OPTION has to be handed over INSTEAD OF the value,
        // since the value itself is null, because no separator was used.
        append_item_element(p1, p7, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p8, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Set knowledge operation mode.
        copy_integer(p0, (void*) KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL);
    }
}

/* MODE_COMMAND_LINE_SELECTOR_SOURCE */
#endif
