/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ENTRY_DIRECTORY_READER_SOURCE
#define ENTRY_DIRECTORY_READER_SOURCE

#include <dirent.h>
#include <errno.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Reads an entry (file) within the given directory.
 *
 * @param p0 the destination item
 * @param p1 the source model data (directory name)
 * @param p2 the source model count
 * @param p3 the source properties data (binary mode etc.)
 * @param p4 the source properties count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 */
void read_directory_entry(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DIR* d = (DIR*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read directory entry.");

        // Initialise error number.
        // It is a global variable/function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Read next entry from directory stream.
        struct dirent* e = readdir(d);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get filename.
            char* f = (*e).d_name;

            // Process file.
//??            receive_data(pm, *NULL_POINTER_STATE_CYBOI_MODEL, smmd, smmc, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, ..., fd, pld, ped, pcd);

        } else {

            // An error occured.

            if (errno == EBADF) {

                fwprintf(stdout, L"Could not read directory entry. The directory entry is null. The dirstream argument is not valid. error EBADF: %i\n", errno);
                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory entry. The directory entry is null. The dirstream argument is not valid.");

            } else {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory entry. The directory entry is null. This is normal behaviour. There are no more files in the directory.");
            }

            // Set break flag.
            // In this manner, the loop that is processing directory entries may be left.
            //
            // CAUTION! The gnu c library manual writes:
            // To avoid entering an infinite loop, you should stop
            // reading from the directory after the first error.
//??            copy_integer(px??_break_flag, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory entry. The directory is null.");
    }
}

/* ENTRY_DIRECTORY_READER_SOURCE */
#endif
