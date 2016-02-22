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

#ifndef FIND_FILE_COMMANDER_SOURCE
#define FIND_FILE_COMMANDER_SOURCE

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/commander/adapt_unix_to_windows_path_commander.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/runner/executor.c"
#include "../../variable/reallocation_factor.c"

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
    #include "../../constant/model/command/unix_command_model.c"
    #include "../../constant/name/command_option/unix/find_file_unix_command_option_name.c"
#elif WIN32
    #include "../../constant/model/command/win32_command_model.c"
    #include "../../constant/name/command_option/win32/find_file_win32_command_option_name.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../constant/model/command/unix_command_model.c"
    #include "../../constant/name/command_option/unix/find_file_unix_command_option_name.c"
#else
    #include "../../constant/model/command/unix_command_model.c"
    #include "../../constant/name/command_option/unix/find_file_unix_command_option_name.c"
#endif

#ifndef _MSC_VER
    #include <unistd.h>
#endif

/**
 * Find a file.
 * 
 * With Unix: Path, insensitive, name. 
 * With Windows: recursive, path, name
 * Therefore: R, path, I, name
 * 
 * @param pmd the path model data
 * @param pmc the path model count
 * @param nmd the name model data
 * @param nmc the name model count
 * @param imd the insensitive model data
 * @param rmd the recursive model data
 */
void command_find_file(void* pmd, void* pmc, void* nmd, void* nmc, void* imd, void* rmd) {
  printf("Ready to go");

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Command find file.");
    
    if (pmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

        if (nmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
#ifdef __APPLE__
            append_item_element(arg, (void*) FIND_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FIND_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
            append_item_element(arg, (void*) FIND_FILE_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FIND_FILE_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) FIND_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FIND_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
            append_item_element(arg, (void*) FIND_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FIND_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            compare_integer_unequal((void*) &r, rmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append recursive option (Windows only).
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#ifdef WIN32
            append_item_element(arg, (void*) RECURSIVE_FIND_FILE_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_FIND_FILE_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
            }

            // Reset comparison result.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
	    
	    // Append path.
#ifdef __APPLE__
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, pmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, pmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, pmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);;
#else
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, pmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif

	    
            compare_integer_unequal((void*) &r, imd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append interactive option (Unix only).
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

#ifdef __APPLE__
                append_item_element(arg, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
                
#elif GNU_LINUX_OPERATING_SYSTEM
                append_item_element(arg, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
                append_item_element(arg, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INAME_FIND_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
            }

            // Reset comparison result.
            r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

	    // Append name.
#ifdef __APPLE__
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, nmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, nmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, nmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, nmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, nmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, nmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);;
#else
            append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
            append_item_element(arg, nmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, nmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
            // Get arguments item data, count.
            copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Execute command line in shell.
            execute(argd, argc);

            // Deallocate arguments item.
            deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not command find file. The file name is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not command find file. The path is null.");
    }
}

/* FIND_FILE_COMMANDER_SOURCE */
#endif
