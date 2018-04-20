/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CLOSE_BSD_SOCKET_SHUTTER_SOURCE
#define CLOSE_BSD_SOCKET_SHUTTER_SOURCE

#include <errno.h>
#include <unistd.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Closes the bsd socket.
 *
 * @param p0 the socket
 */
void shutdown_bsd_socket_close(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* s = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown bsd socket close.");

        // Initialise error number.
        // It is a global variable/ function and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the procedure that might cause an error.
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Close socket.
        //
        // The function actually closes the file descriptor handed over.
        // Closing a file has the following consequences:
        // - The file descriptor is deallocated.
        // - Any record locks owned by the process on the file are unlocked.
        // - When all file descriptors associated with a pipe or FIFO
        //   have been closed, any unread data is discarded.
        //
        // If there is still data waiting to be transmitted over the
        // connexion, normally close tries to complete this transmission.
        // One can control this behaviour using the SO_LINGER socket option
        // to specify a timeout period.
        int r = close(*s);

//?? fwprintf(stdout, L"\nTEST: shutdown bsd socket close *s: %i \n\n", *s);

        if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST: shutdown bsd socket close success r: %i \n", r);

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully shutdown bsd socket close.");

        } else {

            if (errno == EBADF) {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error EBADF: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. The filedes argument is not a valid file descriptor.");

            } else if (errno == EINTR) {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error EINTR: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. The close call was interrupted by a signal.");

            } else if (errno == ENOSPC) {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error ENOSPC: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. Error: ENOSPC. NO ERROR CONDITION DEFINED IN GLIBC.");

            } else if (errno == EIO) {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error EIO: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. Error: EIO. NO ERROR CONDITION DEFINED IN GLIBC.");

            } else if (errno == EDQUOT) {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error EDQUOT: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. When the file is accessed by NFS, these errors from write can sometimes not be detected until close.");

            } else {

    fwprintf(stdout, L"TEST: shutdown bsd socket close error UNKNOWN: %i \n", errno);

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. An unknown error occured while binding the socket to the address.");
            }
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown bsd socket close. The socket is null.");
    }
}

/* CLOSE_BSD_SOCKET_SHUTTER_SOURCE */
#endif
