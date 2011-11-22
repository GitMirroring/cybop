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

#ifndef ARCHIVE_FILE_SOURCE
#define ARCHIVE_FILE_SOURCE

#include <unistd.h>

#include "../../constant/model/command/unix_command_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../logger/logger.c"

/**
 * Archives the given data into a file.
 *
 * Expected parametres:
 * - create (optional): the option for creating an archive
 * - update (optional): the option for updating an archive
 * - bzip2 (optional): the option for using the bzip2 compression algorithm
 *
 * @param p0 the parametres array (signal/ operation part properties with pointers referencing parts)
 * @param p1 the parametres array count
 */
void apply_archive_file(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply archive file.");

    // The create part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bzip2 part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The create part model.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part model.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bzip2 part model.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The create part model data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The update part model data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bzip2 part model data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get create part.
    get_name_array((void*) &c, p0, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get update part.
    get_name_array((void*) &u, p0, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get bzip2 part.
    get_name_array((void*) &b, p0, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get create part model.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get update part model.
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get bzip2 part model.
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get create part model data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get update part model data.
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get bzip2 part model data.
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The arguments vector.
    void* arg = *NULL_POINTER_STATE_CYBOI_MODEL;
    int argc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int args = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate arguments vector.
    allocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Append command.
    overwrite_array((void*) &arg, (void*) ARCHIVE_UNIX_COMMAND_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ARCHIVE_UNIX_COMMAND_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *cmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append create option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CREATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *umd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append update option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UPDATE_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &r, (void*) *bmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Append bzip2 option.
            overwrite_array((void*) &arg, (void*) SPACE_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            overwrite_array((void*) &arg, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BZIP2_ARCHIVE_FILE_OPERATION_CYBOL_NAME_COUNT, (void*) &argc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &argc, (void*) &args, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    // Execute command line in shell.
    run_executing(arg, (void*) &argc);

    // Deallocate arguments vector.
    deallocate((void*) &arg, (void*) &args, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* ARCHIVE_FILE_SOURCE */
#endif
