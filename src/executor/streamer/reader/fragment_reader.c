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

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Reads a message fragment via the given channel.
 *
 * @param p0 the destination item
 * @param p1 the source data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the message fragment data
 * @param p4 the message fragment size
 * @param p5 the destination mutex
 * @param p6 the eof-or-close flag
 * @param p7 the channel
 */
void read_fragment(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read fragment.");
    //?? fwprintf(stdout, L"Debug: Read fragment. p7: %i\n", p7);
    //?? fwprintf(stdout, L"Debug: Read fragment. *p7: %i\n", *((int*) p7));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // For linux xcb, this is NOT needed, since the activator
            // display xcb enabler catches ALL events and distributes
            // them to the input buffers of the single client windows.
            //
            // For win32, it yet has to be figured out how to catch events
            // (either globally as in xcb, or per window).
            //
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) FIFO_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_basic(p0, p1, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_basic(p0, p1, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_inline(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_basic(p0, p1, p3, p4, p5, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            read_signal(p0, p1, p2, p6);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#if defined(__linux__) || defined(__unix__)
            read_basic(p0, p1, p3, p4, p5, p6);
#elif defined(__APPLE__) && defined(__MACH__)
            read_basic(p0, p1, p3, p4, p5, p6);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            read_winsock(p0, p1, p3, p4, p5, p6);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#if defined(__linux__) || defined(__unix__)
            read_basic(p0, p1, p3, p4, p5, p6);
#elif defined(__APPLE__) && defined(__MACH__)
            read_basic(p0, p1, p3, p4, p5, p6);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            read_win32_console(p0, p1, p3, p4, p5, p6);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read fragment. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not read fragment. The channel is unknown. p7: %i\n", p7);
        fwprintf(stdout, L"Warning: Could not read fragment. The channel is unknown. *p7: %i\n", *((int*) p7));
    }
}
