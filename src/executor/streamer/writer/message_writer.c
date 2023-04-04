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

#ifndef MESSAGE_WRITER_SOURCE
#define MESSAGE_WRITER_SOURCE

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
#include "knowledge.h"
#include "logger.h"

/**
 * Writes the source message to the destination device.
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source buffer item
 * @param p2 the source buffer type
 * @param p3 the source part (pointer reference), e.g. a signal
 * @param p4 the source buffer mutex
 * @param p5 the client entry
 * @param p6 the internal memory (needed for signal only)
 * @param p7 the loop break flag
 * @param p8 the channel
 */
void write_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write message.");
    //?? fwprintf(stdout, L"Debug: Write message. p8: %i\n", p8);
    //?? fwprintf(stdout, L"Debug: Write message. *p8: %i\n", *((int*) p8));

    // The destination device identification item data.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination device identification item data.
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_display(d, p5);

            //
            // Set loop break flag.
            //
            // The window has been mapped to screen and all
            // pending requests flushed to the x server.
            // Therefore, further loop cycles are not necessary.
            //
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FIFO_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The loop break flag is adjusted inside the "write_basic" function.
            write_basic(d, p1, p2, p4, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The loop break flag is adjusted inside the "write_basic" function.
            write_basic(d, p1, p2, p4, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_inline(p0, p1, p2, p4, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SERIAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Locking for exclusive read or write is NOT necessary.
            //
            // The serial RS-232 interface has two independent data wires,
            // one for input and another one for output.
            // In case a sensing thread is running for serial input detection,
            // there is NO problem in sending data here,
            // since input and output may be accessed in parallel
            // without having to fear conflicts.
            //

            // The loop break flag is adjusted inside the "write_basic" function.
            write_basic(d, p1, p2, p4, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_signal(p6, p3);

            //
            // Set loop break flag.
            //
            // The source signal has been placed into the signal memory.
            // Therefore, further loop cycles are not necessary.
            //
            copy_integer(p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The loop break flag is adjusted inside the "write_basic" function.
#if defined(__linux__) || defined(__unix__)
            write_basic(d, p1, p2, p4, p7);
#elif defined(__APPLE__) && defined(__MACH__)
            write_basic(d, p1, p2, p4, p7);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            write_winsock(d, p1, p2, p4, p7);
#else
#error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p8, (void*) TERMINAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Comment from an earlier version of cyboi -- DELETE LATER:
            //
            //?? TODO: Reflect on this if something does NOT work correctly.
            //?? DELETE this comment later.
            //
            // CAUTION! The character data are printed out using "fwprintf",
            // so that the ansi escape codes are interpreted correctly.
            //
            // CAUTION! The placeholder %s is used, since the data are given
            // as utf-8 multibyte character sequence of type "char".
            // The placeholder %ls would be WRONG here as it expects data
            // of type "wchar_t".
            //
            // CAUTION! The data ought to be null-terminated.
            //
            // int e = fwprintf(f, L"%s", d);
            // int e = fwprintf(stdout, L"%s", d);
            //

            // The loop break flag is adjusted inside the "write_basic" function.
#if defined(__linux__) || defined(__unix__)
            write_basic(d, p1, p2, p4, p7);
#elif defined(__APPLE__) && defined(__MACH__)
            write_basic(d, p1, p2, p4, p7);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            write_win32_console(d, p1, p2, p4, p7);
#else
#error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write message. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not write message. The channel is unknown. p8: %i\n", p8);
    }
}

/* MESSAGE_WRITER_SOURCE */
#endif
