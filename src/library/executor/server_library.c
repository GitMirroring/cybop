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
// activator
//

#include "../../executor/activator/disabler/disabler.c"
#include "../../executor/activator/disabler/thread_disabler.c"

#include "../../executor/activator/enabler/client_enabler.c"
#include "../../executor/activator/enabler/display/display_enabler.c"
#include "../../executor/activator/enabler/enabler.c"
#include "../../executor/activator/enabler/entry_enabler.c"
#include "../../executor/activator/enabler/function_enabler.c"
#include "../../executor/activator/enabler/loop_enabler.c"
#include "../../executor/activator/enabler/request_enabler.c"
#include "../../executor/activator/enabler/socket/request_socket_enabler.c"
#include "../../executor/activator/enabler/socket/socket_enabler.c"
#include "../../executor/activator/enabler/thread_enabler.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/activator/enabler/bsd_socket/bsd_socket_enabler.c"
    #include "../../executor/activator/enabler/xcb/buffer_xcb_enabler.c"
    #include "../../executor/activator/enabler/xcb/client_xcb_enabler.c"
    #include "../../executor/activator/enabler/xcb/event_xcb_enabler.c"
    #include "../../executor/activator/enabler/xcb/xcb_enabler.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/activator/enabler/bsd_socket/bsd_socket_enabler.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/activator/enabler/win32_display/win32_display_enabler.c"
    #include "../../executor/activator/enabler/winsock/winsock_enabler.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// awakener
//

//?? #include "../../executor/awakener/awakener.c"
//?? #include "../../executor/awakener/display_awakener.c"
//?? #include "../../executor/awakener/serial_port_awakener.c"
//?? #include "../../executor/awakener/socket_awakener.c"
//?? #include "../../executor/awakener/terminal_awakener.c"

//
// maintainer
//

#include "../../executor/maintainer/shutter/display/display_shutter.c"
#include "../../executor/maintainer/shutter/flag_shutter.c"
#include "../../executor/maintainer/shutter/lifecycle_shutter.c"
#include "../../executor/maintainer/shutter/list_shutter.c"
#include "../../executor/maintainer/shutter/service_shutter.c"
#include "../../executor/maintainer/shutter/shutter.c"
#include "../../executor/maintainer/shutter/socket/socket_shutter.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/maintainer/shutter/xcb/xcb_shutter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? TODO
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../executor/maintainer/starter/display/display_starter.c"
#include "../../executor/maintainer/starter/entry_starter.c"
#include "../../executor/maintainer/starter/service_starter.c"
#include "../../executor/maintainer/starter/socket/bind_socket_starter.c"
#include "../../executor/maintainer/starter/socket/lifecycle_socket_starter.c"
#include "../../executor/maintainer/starter/socket/listen_socket_starter.c"
#include "../../executor/maintainer/starter/socket/socket_starter.c"
#include "../../executor/maintainer/starter/starter.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../executor/maintainer/starter/bsd_socket/bind_bsd_socket_starter.c"
    #include "../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
    #include "../../executor/maintainer/starter/xcb/xcb_starter.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../executor/maintainer/starter/bsd_socket/bind_bsd_socket_starter.c"
    #include "../../executor/maintainer/starter/bsd_socket/listen_bsd_socket_starter.c"
    #include "../../executor/maintainer/starter/xcb/xcb_starter.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../executor/maintainer/starter/winsock/bind_winsock_starter.c"
    #include "../../executor/maintainer/starter/winsock/listen_winsock_starter.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
