/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WINDOWS_ERRNO_TO_MESSAGE_MAPPER_SOURCE
#define WINDOWS_ERRNO_TO_MESSAGE_MAPPER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf
#include <winsock.h> // WSAENOTSOCK

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"

//
// Forbidden interface
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "logger.h"

//
// Forward declaration
//

void log_message_terminated(void* p0, void* p1);

/**
 * Maps the windows errno value to an error message.
 *
 * @param p0 the error message (pointer reference)
 * @param p1 the errno value
 */
void map_errno_to_message_windows(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* e = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Map errno to message windows.");

        if (*e == WSANOTINITIALISED) {

            copy_pointer(p0, (void*) &WSANOTINITIALISED_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAENETDOWN) {

            copy_pointer(p0, (void*) &WSAENETDOWN_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEADDRINUSE) {

            copy_pointer(p0, (void*) &WSAEADDRINUSE_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEINTR) {

            copy_pointer(p0, (void*) &WSAEINTR_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEINPROGRESS) {

            copy_pointer(p0, (void*) &WSAEINPROGRESS_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEALREADY) {

            copy_pointer(p0, (void*) &WSAEALREADY_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEADDRNOTAVAIL) {

            copy_pointer(p0, (void*) &WSAEADDRNOTAVAIL_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEAFNOSUPPORT) {

            copy_pointer(p0, (void*) &WSAEAFNOSUPPORT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAECONNREFUSED) {

            copy_pointer(p0, (void*) &WSAECONNREFUSED_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEFAULT) {

            copy_pointer(p0, (void*) &WSAEFAULT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEINVAL) {

            copy_pointer(p0, (void*) &WSAEINVAL_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEISCONN) {

            copy_pointer(p0, (void*) &WSAEISCONN_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAENETUNREACH) {

            copy_pointer(p0, (void*) &WSAENETUNREACH_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEHOSTUNREACH) {

            copy_pointer(p0, (void*) &WSAEHOSTUNREACH_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAENOBUFS) {

            copy_pointer(p0, (void*) &WSAENOBUFS_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAENOTSOCK) {

            copy_pointer(p0, (void*) &WSAENOTSOCK_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAETIMEDOUT) {

            copy_pointer(p0, (void*) &WSAETIMEDOUT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEWOULDBLOCK) {

            copy_pointer(p0, (void*) &WSAEWOULDBLOCK_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else if (*e == WSAEACCES) {

            copy_pointer(p0, (void*) &WSAEACCES_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map errno to message windows. The errno value is unknown.");
            fwprintf(stdout, L"Warning: Could not map errno to message windows. The errno value is unknown. p1: %i\n", p1);
            fwprintf(stdout, L"Warning: Could not map errno to message windows. The errno value is unknown. *p1: %i\n", *((int*) p1));
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not map errno to message windows. The errno value is null.");
        fwprintf(stdout, L"Error: Could not map errno to message windows. The errno value is null. p1: %i\n", p1);
    }
}

/* WINDOWS_ERRNO_TO_MESSAGE_MAPPER_SOURCE */
#endif
