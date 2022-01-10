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

#ifndef CREATE_UNIX_FIFO_STARTER_SOURCE
#define CREATE_UNIX_FIFO_STARTER_SOURCE

#include <sys/stat.h> // mkfifo, S_IRWXU
#include <errno.h> // errno

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Creates a unix fifo, also called "anonymous pipe".
 *
 * A fifo special file is similar to a pipe,
 * except that it is created in a different way.
 * Instead of being an anonymous communications channel,
 * a fifo special file is entered into the file system.
 *
 * Once created, any process can open the fifo special file
 * for reading or writing, in the same way as an ordinary file.
 *
 * However, it has to be open at both ends simultaneously before
 * one can proceed to do any input or output operations on it.
 * Opening a fifo for reading normally blocks until some other
 * process opens the same fifo for writing, and vice versa.
 *
 * https://www.gnu.org/software/libc/manual/html_mono/libc.html#FIFO-Special-Files
 *
 * @param p0 the source model data (file name)
 * @param p1 the source model count
 */
void startup_unix_fifo_create(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix fifo create.");
    fwprintf(stdout, L"Debug: Startup unix fifo create. p1: %i\n", p1);

    // The terminated file name item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminated file name item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate terminated file name item.
    //
    // CAUTION! Do NOT use wide characters here.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character name into multibyte character array.
    encode_utf_8(t, p0, p1);

    // Add null termination character.
    modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Get terminated file name item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Initialise error number.
    // It is a global variable/function and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the function that might cause an error.
    //
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Create fifo.
    int r = mkfifo((char*) td, S_IRWXU);

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix fifo create success.");
        fwprintf(stdout, L"Debug: Startup unix fifo create success. r: %i\n", r);

    } else {

        //
        // An error occured.
        //

        fwprintf(stdout, L"Error: Could not startup unix fifo create. errno: %i\n", errno);

        //
        // The usual file name errors.
        //

        if (errno == EACCES) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The process does not have search permission for a directory component of the file name.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. The process does not have search permission for a directory component of the file name. error EACCES: %i\n", errno);

        } else if (errno == ENAMETOOLONG) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX. error ENAMETOOLONG: %i\n", errno);

        } else if (errno == ENOENT) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist. error ENOENT: %i\n", errno);

        } else if (errno == ENOTDIR) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. A file that is referenced as a directory component in the file name exists, but it isn’t a directory.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. A file that is referenced as a directory component in the file name exists, but it isn’t a directory. error ENOTDIR: %i\n", errno);

        } else if (errno == ELOOP) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops. error ELOOP: %i\n", errno);

        //
        // The error conditions defined for this function.
        //

        } else if (errno == EEXIST) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The named file already exists.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. The named file already exists. EEXIST: %i\n", errno);

        } else if (errno == ENOSPC) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The directory or file system cannot be extended.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. The directory or file system cannot be extended. ENOSPC: %i\n", errno);

        } else if (errno == EROFS) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. The directory that would contain the file resides on a read-only file system.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. The directory that would contain the file resides on a read-only file system. EROFS: %i\n", errno);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup unix fifo create. An unknown error occured.");
            fwprintf(stdout, L"Error: Could not startup unix fifo create. An unknown error occured. errno: %i file: %s\n", errno, (char*) td);
        }
    }

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* CREATE_UNIX_FIFO_STARTER_SOURCE */
#endif
