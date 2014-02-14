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

#ifndef REMOVE_FILE_COMMANDER_SOURCE
#define REMOVE_FILE_COMMANDER_SOURCE
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include "../../../executor/runner/executor.c"

#ifdef __APPLE__
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/remove_file_unix_command_option_name.c"
#elif WIN32
    #include "../../../constant/model/command/win32_command_model.c"
    #include "../../../constant/name/command_option/win32/remove_file_win32_command_option_name.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/remove_file_unix_command_option_name.c"
#else
    #include "../../../constant/model/command/unix_command_model.c"
    #include "../../../constant/name/command_option/unix/remove_file_unix_command_option_name.c"
#endif

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
//???#include "../../../executor/commander/windows_commander/unix_to_windows_path_adapter_for_windows_commander.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Removing files and directories from a path.
 *
 * @param pmd the path model data
 * @param pmc the path model count
 * @param fmd the force model data
 * @param imd the interactive model data
 * @param rmd the recursive model data
 * @param vmd the verbal model data
 */
void remove_file_commander(void* pmd, void* pmc, void* fmd, void* imd, void* rmd, void* vmd) {

    // The path argument must be set or the remove file command will not be executed
    if (pmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
    append_item_element(arg, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif WIN32
    append_item_element(arg, (void*) DEL_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DEL_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#else
    append_item_element(arg, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) REMOVE_FILE_UNIX_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
#endif	
      
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, fmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append force option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                
#ifdef __APPLE__
    append_item_element(arg, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
    append_item_element(arg, (void*) FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORCE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
    append_item_element(arg, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORCE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif	
            }
        }

        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, imd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append interactive option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                		
#ifdef __APPLE__
    append_item_element(arg, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
    append_item_element(arg, (void*) INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERACTIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
    append_item_element(arg, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INTERACTIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif	
            }
        }

        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, rmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append recursive option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                
#ifdef __APPLE__
    append_item_element(arg, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
    append_item_element(arg, (void*) RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_REMOVE_FILE_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
    append_item_element(arg, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) RECURSIVE_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
            }
        }
        
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, vmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append verbal option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                
		
#ifdef __APPLE__
    append_item_element(arg, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#elif WIN32
    // ... not exist
#elif GNU_LINUX_OPERATING_SYSTEM
    append_item_element(arg, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#else
    append_item_element(arg, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) VERBAL_REMOVE_FILE_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#endif
            }
        }

    // Append path option.
    if (pmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The path item.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The path item data, count.
        void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

#ifdef __APPLE__
        pd = pmd;
        pc = pmc;
#elif WIN32
        // Allocate path item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
        
        // Convert slash to backslash.
        command_adapt_unix_to_windows_path(p, pmd, pmc);
        
        // Get path item data, count.
        copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
        
#elif GNU_LINUX_OPERATING_SYSTEM
        pd = pmd;
        pc = pmc;
#else
        pd = pmd;
        pc = pmc;
#endif
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, pd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, pc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
#ifdef WIN32
        // Deallocate path item.
        deallocate_item((void*) &p, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
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
}

/* REMOVE_FILE_COMMANDER_SOURCE */
#endif