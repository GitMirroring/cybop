/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTION_OPTIONALISER_SOURCE
#define OPTION_OPTIONALISER_SOURCE

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/operation_mode/operation_mode_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/name/cyboi/option/option_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/optionaliser/log_file_optionaliser.c"
#include "../../controller/optionaliser/log_level_optionaliser.c"
#include "../../executor/comparator/all/array_all_comparator.c"
#include "../../executor/modifier/appender/item_appender.c"
#include "../../executor/modifier/copier/integer_copier.c"

/**
 * Optionalises the given command line argument option.
 *
 * This function finds out whether an option is actually a value
 * or vice versa, by just comparing with known cyboi options.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the value data
 * @param p5 the value count
 * @param p6 the option data
 * @param p7 the option count
 */
void optionalise_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Debug: Optionalise option.\n");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) HELP_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) HELP_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set help operation mode.
            copy_integer(p0, (void*) HELP_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) KNOWLEDGE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) KNOWLEDGE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy file path from value to cybol knowledge file path.
            append_item_element(p1, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p5, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // Set knowledge operation mode.
            copy_integer(p0, (void*) KNOWLEDGE_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_FILE_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) LOG_FILE_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set log file to store log messages in.
            optionalise_log_file(p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) LOG_LEVEL_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) LOG_LEVEL_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set log level, which is a global variable.
            optionalise_log_level(p2, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) TEST_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) TEST_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set test operation mode.
            copy_integer(p0, (void*) TEST_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p6, (void*) VERSION_OPTION_CYBOI_NAME, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) VERSION_OPTION_CYBOI_NAME_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set version operation mode.
            copy_integer(p0, (void*) VERSION_OPERATION_MODE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! This function call HAS TO BE COMMENTED OUT,
        // in order to avoid disturbing messages at system startup!
        // The last option argument read from command line is
        // always null, so that this warning would ALWAYS appear.
        // log_write((void*) stdout, L"Warning: Could not optionalise option. The command line option is unknown.\n");
    }
}

/* OPTION_OPTIONALISER_SOURCE */
#endif
