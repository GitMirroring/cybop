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

#ifndef COPY_FILE_SOURCE
#define COPY_FILE_SOURCE

#include <unistd.h>

#include "../../applicator/runner/executing_runner.c"
#include "../../constant/type/cybol/text_cybol_type.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/command_option/unix/copy_unix_command_option_name.c"
#include "../../constant/name/cybol/operation/file/copy_file_operation_cybol_name.c"
#include "../../executor/memoriser/allocator.c"
#include "../../logger/logger.c"
#include "../../variable/reallocation_factor.c"

/**
 * Copies the file resource.
 *
 * Expected parametres:
 * - recursive (optional): the option indicating that all sub directories should be copied as well
 * - source (required): the source to be copied
 * - destination (required): the destination to copy to
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 */
void apply_copy_file(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply copy file.");

    // The recursive part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The recursive part model.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The recursive part model data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination part model data.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get recursive part.
    get_name_array((void*) &r, p0, (void*) RECURSIVE_COPY_FILE_OPERATION_CYBOL_NAME, (void*) RECURSIVE_COPY_FILE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get source part.
    get_name_array((void*) &s, p0, (void*) SOURCE_COPY_FILE_OPERATION_CYBOL_NAME, (void*) SOURCE_COPY_FILE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get destination part.
    get_name_array((void*) &d, p0, (void*) DESTINATION_COPY_FILE_OPERATION_CYBOL_NAME, (void*) DESTINATION_COPY_FILE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get recursive part model.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source part model.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get destination part model.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get recursive part model data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get source part model data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get destination part model data.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The arguments vector.
    void* arg = *NULL_POINTER_STATE_CYBOI_MODEL;
    int argc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int args = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Append command.
    overwrite_array((void*) &arg, (void*) COPY_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) COPY_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *rmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append recursive option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) RECURSIVE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *smd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append source option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) SOURCE_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *dmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append source option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, (void*) DESTINATION_COPY_UNIX_COMMAND_OPTION_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/* COPY_FILE_SOURCE */
#endif
