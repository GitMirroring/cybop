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

#ifndef WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER
#define WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

/** The WSANOTINITIALISED windows error message log cyboi model. */
static wchar_t* WSANOTINITIALISED_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"A successful WSAStartup call must occur before using this function.";

/** The WSAENETDOWN windows error message log cyboi model. */
static wchar_t* WSAENETDOWN_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The network subsystem has failed.";

/** The WSAEADDRINUSE windows error message log cyboi model. */
static wchar_t* WSAEADDRINUSE_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The socket's local address is already in use and the socket was not marked to allow address reuse with SO_REUSEADDR. This error usually occurs when executing bind, but could be delayed until the connect function if the bind was to a wildcard address (INADDR_ANY or in6addr_any) for the local IP address. A specific address needs to be implicitly bound by the connect function.";

/** The WSAEINTR windows error message log cyboi model. */
static wchar_t* WSAEINTR_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The blocking Windows Socket 1.1 call was canceled through WSACancelBlockingCall.";

/** The WSAEINPROGRESS windows error message log cyboi model. */
static wchar_t* WSAEINPROGRESS_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"A blocking Windows Sockets 1.1 call is in progress, or the service provider is still processing a callback function.";

/** The WSAEALREADY windows error message log cyboi model. */
static wchar_t* WSAEALREADY_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"A nonblocking connect call is in progress on the specified socket. In order to preserve backward compatibility, this error is reported as WSAEINVAL to Windows Sockets 1.1 applications that link to either Winsock.dll or Wsock32.dll.";

/** The WSAEADDRNOTAVAIL windows error message log cyboi model. */
static wchar_t* WSAEADDRNOTAVAIL_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The remote address is not a valid address (such as INADDR_ANY or in6addr_any).";

/** The WSAEAFNOSUPPORT windows error message log cyboi model. */
static wchar_t* WSAEAFNOSUPPORT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"Addresses in the specified family cannot be used with this socket.";

/** The WSAECONNREFUSED windows error message log cyboi model. */
static wchar_t* WSAECONNREFUSED_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The attempt to connect was forcefully rejected.";

/** The WSAEFAULT windows error message log cyboi model. */
static wchar_t* WSAEFAULT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The sockaddr structure pointed to by the name contains incorrect address format for the associated address family or the namelen parameter is too small. This error is also returned if the sockaddr structure pointed to by the name parameter with a length specified in the namelen parameter is not in a valid part of the user address space.";

/** The WSAEINVAL windows error message log cyboi model. */
static wchar_t* WSAEINVAL_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The parameter s is a listening socket.";

/** The WSAEISCONN windows error message log cyboi model. */
static wchar_t* WSAEISCONN_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The socket is already connected (connection-oriented sockets only).";

/** The WSAENETUNREACH windows error message log cyboi model. */
static wchar_t* WSAENETUNREACH_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The network cannot be reached from this host at this time.";

/** The WSAEHOSTUNREACH windows error message log cyboi model. */
static wchar_t* WSAEHOSTUNREACH_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"A socket operation was attempted to an unreachable host.";

/** The WSAENOBUFS windows error message log cyboi model. */
static wchar_t* WSAENOBUFS_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"No buffer space is available. The socket cannot be connected.";

/** The WSAENOTSOCK windows error message log cyboi model. */
static wchar_t* WSAENOTSOCK_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The descriptor specified in the s parameter is not a socket.";

/** The WSAETIMEDOUT windows error message log cyboi model. */
static wchar_t* WSAETIMEDOUT_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"An attempt to connect timed out without establishing a connection.";

/** The WSAEWOULDBLOCK windows error message log cyboi model. */
static wchar_t* WSAEWOULDBLOCK_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"The socket is marked as nonblocking and the connection cannot be completed immediately.";

/** The WSAEACCES windows error message log cyboi model. */
static wchar_t* WSAEACCES_WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL = L"An attempt to connect a datagram socket to broadcast address failed because setsockopt option SO_BROADCAST is not enabled.";

/* WINDOWS_ERROR_MESSAGE_LOG_CYBOI_MODEL_CONSTANT_HEADER */
#endif
