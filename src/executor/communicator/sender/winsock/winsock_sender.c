/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINSOCK_SENDER_SOURCE
#define WINSOCK_SENDER_SOURCE

#include <winsock.h>

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Sends source data via winsock.
 *
 * @param p0 the destination socket
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number of bytes transferred
 */
void send_winsock(void* p0, void* p1, void* p2, void* p3) {

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

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send winsock.");

                    // Cast int to winsock SOCKET.
                    SOCKET ws = (SOCKET) *s;

                    //
                    // Send message to destination socket.
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

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. No data could be sent. Possibly, the connexion has been gracefully closed.");

                    } else {

                        // An error occured.

                        // Get the calling thread's last-error code.
                        //
                        // CAUTION! This function is the winsock substitute
                        // for the Windows "GetLastError" function.
                        int e = WSAGetLastError();

                        if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else if (e == TODO) {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. TODO");

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. An unknown error occured.");
                        }

                        // Cast int to DWORD (unsigned int 32-Bit).
                        DWORD dw = (DWORD) e;

                        log_windows_system_error((void*) &dw);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. The destination socket is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. The source data is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. The source count is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send winsock. The number of bytes transferred is null.");
    }
}

/* WINSOCK_SENDER_SOURCE */
#endif
