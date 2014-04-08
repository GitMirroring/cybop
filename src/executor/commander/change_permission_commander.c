/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CHANGE_PERMISSION_COMMANDER_SOURCE
#define CHANGE_PERMISSION_COMMANDER_SOURCE

#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/commander/adapt_unix_to_windows_path_commander.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../logger/logger.c"

#ifndef _MSC_VER
    #include <unistd.h>
#endif

#ifdef __APPLE__
    #include "../../constant/name/command_option/unix/change_permission_unix_command_option_name.c"
#elif WIN32
    //TODO: if file available remove ifndef WIN32 in related source code statement below
    //#include "../../constant/name/command_option/win32/change_permission_win32_command_option_name.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../constant/name/command_option/unix/change_permission_unix_command_option_name.c"
#else
    #include "../../constant/name/command_option/unix/change_permission_unix_command_option_name.c"
#endif

/**
 * Changes the file permissions.
 *
 * @param p0 the path model data
 * @param p1 the path model count
 * @param p2 the user model data
 * @param p3 the user model count
 * @param p4 the group model data
 * @param p5 the group model count
 * @param p6 the other model data
 * @param p7 the other model count
 * @param p8 the recursive model data
 * @param p9 the silent model data
 * @param p10 the verbose model data
 */
void command_change_permission(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Command change permission.");

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
    append_item_element(arg, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
    //append_item_element(arg, (void*) DIR_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DIR_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
    append_item_element(arg, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHANGE_PERMISSION_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
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

//append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//append_item_element(arg, pd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

#ifdef WIN32
        // Deallocate path item.
        deallocate_item((void*) &p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
#endif
    }

    // example: u=rwx,g=,o=rw
    append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) LATIN_SMALL_LETTER_U_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    append_item_element(arg, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) LATIN_SMALL_LETTER_G_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    append_item_element(arg, (void*) COMMA_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) LATIN_SMALL_LETTER_O_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, (void*) EQUALS_SIGN_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);


    // optional recursive parameter
    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append recursive option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifndef WIN32
        append_item_element(arg, (void*) RECURSIVE_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // optional silent parameter
    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by modification date option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifndef WIN32
        append_item_element(arg, (void*) SILENT_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SILENT_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // optional verbose parameter
    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append sort by modification date option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifndef WIN32
        append_item_element(arg, (void*) VERBOSE_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) VERBOSE_CHANGE_PERMISSION_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
    }

    // required parameter
    // Append source
    append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(arg, p0, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p1, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Get arguments item data, count.
    copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Execute command line in shell.
    execute(argd, argc);

    // Deallocate arguments item.
    deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* CHANGE_PERMISSION_COMMANDER_SOURCE */
#endif
