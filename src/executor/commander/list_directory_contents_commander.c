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

#ifndef LIST_DIRECTORY_CONTENTS_COMMANDER_SOURCE
#define LIST_DIRECTORY_CONTENTS_COMMANDER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/commander/adapt_unix_to_windows_path_commander.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../logger/logger.c"

//
// CAUTION! The options of many commands are SIMILAR on various platforms.
// Therefore, it might suffice to distinguish included files here
// and use IDENTICAL CONSTANTS whose values are determined
// by the include they stem from.
//
// However, there ARE commands on some platforms that do NOT
// exist on another. The same is true for command options.
// Therefore, it makes sense to distinguish between platforms
// at EVERY option, even if that produces some redundant code.
//
#ifdef __APPLE__
    #include "../../constant/name/command_option/unix/list_directory_contents_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#elif WIN32
    #include "../../constant/name/command_option/win32/list_directory_contents_win32_command_option_name.c"
    #include "../../constant/model/command/win32_command_model.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../constant/name/command_option/unix/list_directory_contents_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#else
    #include "../../constant/name/command_option/unix/list_directory_contents_unix_command_option_name.c"
    #include "../../constant/model/command/unix_command_model.c"
#endif

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Lists the directory contents.
 *
 * @param p0 the path model data
 * @param p1 the path model count
 * @param p2 the all model data
 * @param p3 the long model data
 * @param p4 the one row per entry model data
 * @param p5 the recursive model data
 * @param p6 the short model data
 * @param p7 the sort by file size model data
 * @param p8 the sort by modification date model data
 * @param p9 the sort by extension model data
 * @param p10 the almost-all model data
 * @param p11 the export model data
 * @param p12 the export model count
 *
 */
void command_list_directory_contents(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Command list directory contents.");

    // The arguments item.
    void* arg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The arguments item data, count.
    void* argd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* argc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Allocate arguments item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &arg, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Append command.
#ifdef __APPLE__
    append_item_element(arg, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
    append_item_element(arg, (void*) DIR_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DIR_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
    append_item_element(arg, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif

    // Append path option.
    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The path item.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The path item data, count.
        void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef __APPLE__
        pd = p0;
        pc = p1;
#elif WIN32
        // Allocate path item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Convert slash to backslash.
        command_adapt_unix_to_windows_path(p, p0, p1);

        // Get path item data, count.
        copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

#elif GNU_LINUX_OPERATING_SYSTEM
        pd = p0;
        pc = p1;
#else
        pd = p0;
        pc = p1;
#endif
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, pd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#ifdef WIN32
        // Deallocate path item.
        deallocate_item((void*) &p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append all option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append long option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LONG_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

#ifdef WIN32
    } else {

        // Append short option as default.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SHORT_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append one row per entry option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ONE_ROW_PER_ENTRY_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append recursive option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by file size option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_SIZE_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by modification date option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_MODIFICATION_TIME_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by extension option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef __APPLE__
        append_item_element(arg, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
        append_item_element(arg, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
        append_item_element(arg, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SORT_BY_FILE_EXTENSION_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

#ifndef WIN32
    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by extension option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef WIN32 // unreachable because ALMOST_ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME not available
        append_item_element(arg, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
        append_item_element(arg, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ALMOST_ALL_LIST_DIRECTORY_CONTENTS_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }
#endif

    // Append path option.
    if (p12 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The path item.
        void* pe = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The path item data, count.
        void* ped = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pec = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef __APPLE__
        ped = p11;
        pec = p12;
#elif WIN32
        // Allocate path item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &pe, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Convert slash to backslash.
        command_adapt_unix_to_windows_path(pe, p11, p12);

        // Get path item data, count.
        copy_array_forward((void*) &ped, pe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pec, pe, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

#elif GNU_LINUX_OPERATING_SYSTEM
        ped = p11;
        pec = p12;
#else
        ped = p11;
        pec = p12;
#endif
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) GREATER_THAN_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, ped, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pec, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#ifdef WIN32
        // Deallocate path item.
        deallocate_item((void*) &pe, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
#endif
    }

    // Get arguments item data, count.
    copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Execute command line in shell.
    execute(argd, argc);

    // Deallocate arguments item.
    deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* LIST_DIRECTORY_CONTENTS_COMMANDER_SOURCE */
#endif
