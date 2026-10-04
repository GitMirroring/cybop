/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
 * Writes source data via winsock.
 *
 * @param p0 the destination socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void write_winsock(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* n = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* c = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                // CAUTION! The winsock function "send" expects
                // a char* instead of void* buffer.
                char* d = (char*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* s = (int*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write winsock.");

                    // Cast int to winsock SOCKET.
                    SOCKET ws = (SOCKET) *s;

                    //
                    // Write message to destination socket.
                    //
                    // If the flags argument (fourth one) is zero, then one can
                    // just as well use the "write" instead of the "send" procedure.
                    // If the socket is nonblocking, then "send" can return after
                    // sending just PART OF the data.
                    // Note, however, that a successful return value merely indicates
                    // that the message has been SENT without error, NOT necessarily
                    // that it has been received without error!
                    //
                    // The function returns the number of bytes transmitted
                    // or -1 on failure.
                    //
                    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms740149%28v=vs.85%29.aspx
                    //
                    *n = send(ws, d, *c, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                    if (*n > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Successfully sent winsock.");

                    } else if (*n == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. No data could be sent. Possibly, the connexion has been gracefully closed.");

                    } else {

                        // An error occured.

                        // Get the calling thread's last-error code.
                        //
                        // CAUTION! This function is the winsock substitute
                        // for the Windows "GetLastError" function.
                        int e = WSAGetLastError();

                        if (e == WSANOTINITIALISED) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. A successful WSAStartup call must occur before using this function.");

                        } else if (e == WSAENETDOWN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The network subsystem has failed.");

                        } else if (e == WSAEACCES) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The requested address is a broadcast address, but the appropriate flag was not set. Call setsockopt with the SO_BROADCAST socket option to enable use of the broadcast address.");

                        } else if (e == WSAEINTR) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. A blocking Windows Sockets 1.1 call was canceled through WSACancelBlockingCall.");

                        } else if (e == WSAEINPROGRESS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.");

                        } else if (e == WSAEFAULT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The buf parameter is not completely contained in a valid part of the user address space.");

                        } else if (e == WSAENETRESET) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The connection has been broken due to the keep-alive activity detecting a failure while the operation was in progress.");

                        } else if (e == WSAENOBUFS) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. No buffer space is available.");

                        } else if (e == WSAENOTCONN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The socket is not connected.");

                        } else if (e == WSAENOTSOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The descriptor is not a socket.");

                        } else if (e == WSAEOPNOTSUPP) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. MSG_OOB was specified, but the socket is not stream-style such as type SOCK_STREAM, OOB data is not supported in the communication domain associated with this socket, or the socket is unidirectional and supports only receive operations.");

                        } else if (e == WSAESHUTDOWN) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The socket has been shut down; it is not possible to write on a socket after shutdown has been invoked with how set to SD_SEND or SD_BOTH.");

                        } else if (e == WSAEWOULDBLOCK) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The socket is marked as nonblocking and the requested operation would block.");

                        } else if (e == WSAEMSGSIZE) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The socket is message oriented, and the message is larger than the maximum supported by the underlying transport.");

                        } else if (e == WSAEHOSTUNREACH) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The remote host cannot be reached from this host at this time.");

                        } else if (e == WSAEINVAL) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The socket has not been bound with bind, or an unknown flag was specified, or MSG_OOB was specified for a socket with SO_OOBINLINE enabled.");

                        } else if (e == WSAECONNABORTED) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The virtual circuit was terminated due to a time-out or other failure. The application should close the socket as it is no longer usable.");

                        } else if (e == WSAECONNRESET) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The virtual circuit was reset by the remote side executing a hard or abortive close. For UDP sockets, the remote host was unable to deliver a previously sent UDP datagram and responded with a 'Port Unreachable' ICMP packet. The application should close the socket as it is no longer usable.");

                        } else if (e == WSAETIMEDOUT) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The connection has been dropped, because of a network failure or because the system on the other end went down without notice.");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. An unknown error occured.");
                        }

                        // Cast int to DWORD (unsigned int 32-Bit).
                        DWORD dw = (DWORD) e;

                        log_error((void*) &dw);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The destination socket is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write winsock. The number of bytes transferred is null.");
    }
}
