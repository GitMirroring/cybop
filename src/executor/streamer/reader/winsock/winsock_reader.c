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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <winsock.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

/**
 * Reads data via winsock and stores them in the given destination array.
 *
 * @param p0 the destination data
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source socket
 * @param p4 the socket options
 */
void read_winsock(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* ss = (int*) p3;

            if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* s = (int*) p2;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // CAUTION! The winsock function "recv" expects
                    // a char* instead of void* buffer.
                    char* d = (char*) p0;

                    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read winsock.");

                    // Cast int to winsock SOCKET.
                    SOCKET ws = (SOCKET) *ss;

                    //
                    // Read message.
                    //
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "read" instead of the "recv" procedure.
                    // Normally, "recv" blocks until there is input available to be read.
                    //
                    // CAUTION! A message MUST NOT be longer than the given buffer size!
                    //
                    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms740121%28v=vs.85%29.aspx
                    //
                    int c = recv(ws, d, *s, *o);

                    if (c > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully read winsock.");

                        // Copy destination count.
                        // CAUTION! Copy value only if >= zero.
                        // Otherwise (with negative value), buffer deallocation will fail.
                        copy_integer(p1, (void*) &c);

                    } else if (c == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. No data could be sensed. Possibly, the connexion has been gracefully closed.");

                        // Copy destination count.
                        // CAUTION! Copy value only if >= zero.
                        // Otherwise (with negative value), buffer deallocation will fail.
                        copy_integer(p1, (void*) &c);

                    } else {

                        // An error occured.

                        // Get the calling thread's last-error code.
                        //
                        // CAUTION! This function is the winsock substitute
                        // for the Windows "GetLastError" function.
                        int e = WSAGetLastError();

                        if (e == WSANOTINITIALISED) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. A successful WSAStartup call must occur before using this function.");

                        } else if (e == WSAENETDOWN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The network subsystem has failed.");

                        } else if (e == WSAEFAULT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The buf parameter is not completely contained in a valid part of the user address space.");

                        } else if (e == WSAENOTCONN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The socket is not connected.");

                        } else if (e == WSAEINTR) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The (blocking) call was canceled through WSACancelBlockingCall.");

                        } else if (e == WSAEINPROGRESS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                        } else if (e == WSAENETRESET) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. For a connection-oriented socket, this error indicates that the connection has been broken due to keep-alive activity that detected a failure while the operation was in progress. For a datagram socket, this error indicates that the time to live has expired.");

                        } else if (e == WSAENOTSOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The descriptor is not a socket.");

                        } else if (e == WSAEOPNOTSUPP) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only send operations.");

                        } else if (e == WSAESHUTDOWN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The socket has been shut down; it is not possible to read on a socket after shutdown has been invoked with how set to SD_RECEIVE or SD_BOTH.");

                        } else if (e == WSAEWOULDBLOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The socket is marked as nonblocking and the read operation would block.");

                        } else if (e == WSAEMSGSIZE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The message was too large to fit into the specified buffer and was truncated.");

                        } else if (e == WSAEINVAL) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The socket has not been bound with bind, or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled or (for byte stream sockets only) len was zero or negative.");

                        } else if (e == WSAECONNABORTED) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable.");

                        } else if (e == WSAETIMEDOUT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The connection has been dropped because of a network failure or because the peer system failed to respond.");

                        } else if (e == WSAECONNRESET) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The virtual circuit was reset by the remote side executing a hard or abortive close. The application should close the socket as it is no longer usable. On a UDP-datagram socket, this error would indicate that a previous send operation resulted in an ICMP 'Port Unreachable' message.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. An unknown error occured.");
                        }

                        // Cast int to DWORD (unsigned int 32-Bit).
                        DWORD dw = (DWORD) e;

                        log_error((void*) &dw);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The destination data is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The destination size is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The source socket is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read winsock. The socket options is null.");
    }
}
