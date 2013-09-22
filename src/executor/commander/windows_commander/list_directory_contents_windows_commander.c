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

#ifndef LIST_DIRECTORY_CONTENTS_WINDOWS_COMMANDER_SOURCE
#define LIST_DIRECTORY_CONTENTS_WINDOWS_COMMANDER_SOURCE

#include <unistd.h>

#include "../../../executor/runner/executor.c"
#include "../../../constant/model/command/win32_command_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/command_option/win32/list_directory_contents_win32_command_option_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/commander/windows_commander/unix_to_windows_path_adapter_for_windows_commander.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Lists the directory contents.
 *
 * @param pmd the path model data
 * @param pmc the path model count
 * @param amd the all model data
 * @param lmd the long model data
 * @param orpemd the one row per entry model data
 * @param rmd the recursive model data
 * @param smd the short model data
 * @param sbfsmd the sort by file size model data
 * @param sbmdmd the sort by modification date model data
 * @param sbemd the sort by extension model data
 */
void list_directory_contents_windows_commander(void* pmd, void* pmc, void* amd, void* lmd, void* orpemd, void* rmd, void* smd, void* sbfsmd, void* sbmdmd, void* sbemd) {
    // The arguments item.
    void* arg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The arguments item data, count.
    void* argd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* argc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate arguments item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &arg, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Append command.
    append_item_element(arg, (void*) DIR_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DIR_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    if (pmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Append path option.
        apply_unix_to_windows_path_adapter_for_windows_commander(pmd, pmc);

        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, pmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, amd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append all option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, lmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append long option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        } else {
            // Append short as default.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, orpemd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append one row per entry option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, rmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append recursive option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, sbfsmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append sort by file size option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, sbmdmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append sort by modification date option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, sbemd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append sort by extension option.
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        }
    }

    // Get arguments item data, count.
    copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Execute command line in shell.
    execute(argd, argc);

    // Deallocate arguments item.
    deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* LIST_DIRECTORY_CONTENTS_WINDOWS_COMMANDER_SOURCE */
#endif
