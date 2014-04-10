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

#ifndef WORD_COUNT_COMMANDER_SOURCE
#define WORD_COUNT_COMMANDER_SOURCE

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
    #include "../../constant/name/command_option/unix/word_count_unix_command_option_name.c"
#elif WIN32
    //#include "../../constant/name/command_option/win32/word_count_win32_command_option_name.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../constant/name/command_option/unix/word_count_unix_command_option_name.c"
#else
    #include "../../constant/name/command_option/unix/word_count_unix_command_option_name.c"
#endif

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Lists the directory contents.
 *
 * @param p0 the path model data
 * @param p1 the path model count
 * @param p2 the byte model data
 * @param p3 the char model data
 * @param p4 the line model data
 * @param p5 the max-line-length model data
 * @param p6 the word model data
 */
void command_word_count(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Command word count.");

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
    append_item_element(arg, (void*) WORD_COUNT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) WORD_COUNT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
 //append_item_element(arg, (void*) DIR_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DIR_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) WORD_COUNT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) WORD_COUNT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
    append_item_element(arg, (void*) WORD_COUNT_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) WORD_COUNT_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
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

//??        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
//??        append_item_element(arg, pd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

#ifdef WIN32
        // Deallocate path item.
        deallocate_item((void*) &p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
#endif
    }

#ifndef WIN32
    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append byte count option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BYTE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append char count option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHAR_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }


    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append line count option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LINE_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append max-line-length count option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MAX_LINE_LENGTH_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p6, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Append word count option.
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) WORD_WORD_COUNT_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    }
#endif

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

/* WORD_COUNT_COMMANDER_SOURCE */
#endif
