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

#ifndef MESSAGE_WRITER_SOURCE
#define MESSAGE_WRITER_SOURCE

#include "../../../constant/channel/cyboi/cyboi_channel.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/streamer/writer/display/display_writer.c"
#include "../../../executor/streamer/writer/inline/inline_writer.c"
#include "../../../executor/streamer/writer/signal/signal_writer.c"
#include "../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/streamer/writer/basic/basic_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/streamer/writer/basic/basic_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/streamer/writer/win32_console/win32_console_writer.c"
    #include "../../../../executor/streamer/writer/winsock/winsock_writer.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Writes the source message to the destination device.
 *
 * @param p0 the destination device file descriptor (a file, serial port, terminal, socket) OR window id OR item (for inline channel)
 * @param p1 the source buffer data (pointer reference)
 * @param p2 the source buffer count
 * @param p3 the source buffer size
 * @param p4 the source buffer type
 * @param p5 the source part (pointer reference), e.g. a signal
 * @param p6 the source buffer mutex
 * @param p7 the client entry
 * @param p8 the loop break flag
 * @param p9 the channel
 */
void write_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write message.");
    fwprintf(stdout, L"Information: Write message. p9: %i\n", p9);
    fwprintf(stdout, L"Information: Write message. *p9: %i\n", *((int*) p9));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) DISPLAY_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_display(p0, p7);

            //
            // Set loop break flag.
            //
            // The window has been mapped to screen and all
            // pending requests flushed to the x server.
            // Therefore, further loop cycles are not necessary.
            //
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The loop break flag is adjusted inside the "write_basic" function.
            write_basic(p0, p1, p2, p3, p4, p6, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_inline(p0, *d, p2);

            //
            // Set loop break flag.
            //
            // The buffer data have been copied within cyboi, all at once.
            // Therefore, further loop cycles are not necessary.
            //
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SERIAL_CYBOI_CHANNEL);

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
            write_basic(p0, p1, p2, p3, p4, p6, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SIGNAL_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            write_signal(p5, p7);

            //
            // Set loop break flag.
            //
            // The source signal has been placed into the signal memory.
            // Therefore, further loop cycles are not necessary.
            //
            copy_integer(p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) SOCKET_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The loop break flag is adjusted inside the "write_basic" function.
#if defined(__linux__) || defined(__unix__)
            write_basic(p0, p1, p2, p3, p4, p6, p8);
#elif defined(__APPLE__) && defined(__MACH__)
            write_basic(p0, p1, p2, p3, p4, p6, p8);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            write_winsock(p0, p1, p2, p3, p4, p6, p8);
#else
#error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p9, (void*) TERMINAL_CYBOI_CHANNEL);

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
            write_basic(p0, p1, p2, p3, p4, p6, p8);
#elif defined(__APPLE__) && defined(__MACH__)
            write_basic(p0, p1, p2, p3, p4, p6, p8);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
            write_win32_console(p0, p1, p2, p3, p4, p6, p8);
#else
#error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write message. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not write message. The channel is unknown. p9: %i\n", p9);
    }
}

/* MESSAGE_WRITER_SOURCE */
#endif
