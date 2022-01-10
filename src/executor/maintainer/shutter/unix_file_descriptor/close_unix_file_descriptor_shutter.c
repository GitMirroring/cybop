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

#ifndef CLOSE_UNIX_FILE_DESCRIPTOR_SHUTTER_SOURCE
#define CLOSE_UNIX_FILE_DESCRIPTOR_SHUTTER_SOURCE

#include <errno.h> // errno
#include <unistd.h> // close

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Closes the unix file descriptor.
 *
 * @param p0 the file descriptor
 */
void shutdown_unix_file_descriptor_close(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown unix file descriptor close.");

        //
        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        //
        // Close file descriptor.
        //
        // The function actually closes the file descriptor handed over.
        // Closing a file has the following consequences:
        // - The file descriptor is deallocated.
        // - Any record locks owned by the process on the file are unlocked.
        // - When all file descriptors associated with a pipe or fifo
        //   have been closed, any unread data is discarded.
        //
        // If there is still data waiting to be transmitted over the
        // connexion, normally close tries to complete this transmission.
        // One can control this behaviour using the SO_LINGER socket option
        // to specify a timeout period.
        //
        int r = close(*f);

        //?? fwprintf(stdout, L"\nTest: Shutdown unix file descriptor close. *f: %i \n\n", *f);

        if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown unix file descriptor close. success");
            //?? fwprintf(stdout, L"Debug: Shutdown unix file descriptor close. success r: %i\n", r);

        } else {

            if (errno == EBADF) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. The filedes argument is not a valid file descriptor.");
                //?? fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. The filedes argument is not a valid file descriptor. error EBADF: %i\n", errno);

            } else if (errno == EINTR) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. The close call was interrupted by a signal.");
                fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. The close call was interrupted by a signal. error EINTR: %i\n", errno);

            } else if (errno == ENOSPC) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. Error: ENOSPC. NO ERROR CONDITION DEFINED IN GLIBC.");
                fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. Error: ENOSPC. NO ERROR CONDITION DEFINED IN GLIBC. error ENOSPC: %i\n", errno);

            } else if (errno == EIO) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. Error: EIO. NO ERROR CONDITION DEFINED IN GLIBC.");
                fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. Error: EIO. NO ERROR CONDITION DEFINED IN GLIBC. error EIO: %i\n", errno);

            } else if (errno == EDQUOT) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");
                fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. When the file is accessed by NFS, these errors from write can sometimes not be detected until close. error EDQUOT: %i\n", errno);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. An unknown error occured while binding the socket to the address.");
                fwprintf(stdout, L"Debug: Could not shutdown unix file descriptor close. An unknown error occured while binding the socket to the address. error UNKNOWN: %i\n", errno);
            }
        }

    } else {

        //
        // CAUTION! This log message has been commented out
        // due to the large number of potential calls caused
        // by the the number of socket services (65536).
        // See file "shutdown_manager.c".
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown unix file descriptor close. The file descriptor is null.");
        // fwprintf(stdout, L"Error: Could not shutdown unix file descriptor close. The file descriptor is null. p0: %i\n", p0);
    }
}

/* CLOSE_UNIX_FILE_DESCRIPTOR_SHUTTER_SOURCE */
#endif
