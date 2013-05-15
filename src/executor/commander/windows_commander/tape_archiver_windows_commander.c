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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TAPE_ARCHIVER_WINDOWS_COMMANDER_SOURCE
#define TAPE_ARCHIVER_WINDOWS_COMMANDER_SOURCE

#include <unistd.h>

#include "../../../executor/runner/executor.c"
#include "../../../constant/model/command/win32_command_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/command_option/win32/tape_archiver_win32_command_option_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../variable/reallocation_factor.c"
#include "unix_to_windows_path_adapter_for_windows_commander.c"

/**
 * Packs/Unpacks a directory or file 
 *
 * @param smd the source path model data
 * @param smc the source path model count
 * @param dmd the destination path model data
 * @param dmc the destination path model count
 * @param fmd the force model data
 * @param gmd the gzip model data
 * @param umd the unpack model data
 * @param vmd the verbal model data
 */
void tape_archiver_windows_commander(void* smd, void* smc, void* dmd, void* dmc, void* fmd, void* gmd, void* umd, void* vmd) {

    // The source and destination path argument must be set or pack / unpack command wont be executed
    if (smc != *NULL_POINTER_STATE_CYBOI_MODEL && dmc != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
        append_item_element(arg, (void*) SEVEN_ZIP_WIN32_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) SEVEN_ZIP_WIN32_COMMAND_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, umd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append unpack option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                append_item_element(arg, (void*) UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UNPACK_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            } else {

                // Append add to archive option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                append_item_element(arg, (void*) ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ADD_TO_ARCHIVE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
                if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    compare_integer_unequal((void*) &r, gmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // Append gzip option.
                        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                        append_item_element(arg, (void*) GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) GZIP_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                    } else {

                        // Append tar option.
                        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                        append_item_element(arg, (void*) TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TAR_FORMAT_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
                    }
                }
            }
        }

        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, fmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Append force option.
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                append_item_element(arg, (void*) FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FORCE_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        // Append source and destination path.
        apply_unix_to_windows_path_adapter_for_windows_commander(smd, smc);
        apply_unix_to_windows_path_adapter_for_windows_commander(dmd, dmc);
        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, smd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, smc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        
        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_unequal((void*) &r, umd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                
                // Channel unpack output if it is a unpack operation
                append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
                append_item_element(arg, (void*) DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DESTINATION_TAPE_ARCHIVER_WIN32_COMMAND_OPTION_NAME_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }
        }

        append_item_element(arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(arg, dmd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, dmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        // Get arguments item data, count.
        copy_array_forward((void*) &argd, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &argc, arg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // Execute command line in shell.
        execute(argd, argc);

        // Deallocate arguments item.
        deallocate_item((void*) &arg, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* TAPE_ARCHIVER_WIN32_COMMANDER_SOURCE */
#endif