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

#ifndef WRITER_SOURCE
#define WRITER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../logger/logger.c"
--
#include "../../constant/channel/cyboi/cyboi_channel.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../executor/streamer/writer/directory/directory_writer.c"
#include "../../executor/streamer/writer/display/display_writer.c"
#include "../../executor/streamer/writer/inline/inline_writer.c"
#include "../../executor/streamer/writer/signal/signal_writer.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../executor/streamer/writer/basic/basic_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../executor/streamer/writer/basic/basic_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../executor/streamer/writer/win32_console/win32_console_writer.c"
    #include "../../../executor/streamer/writer/winsock/winsock_writer.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Writes the source via the given channel.
 *
 * CAUTION! Do NOT rename this function to "write",
 * as that name is already used for glibc library's output.
 *
 * @param p0 the destination item (e.g. filename, client socket number, service identification, gui window id)
 * @param p1 the source model data (pointer reference)
 * @param p2 the source model count
 * @param p3 the source properties data (e.g. signal memory index)
 * @param p4 the source properties count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the source part (pointer reference), e.g. a signal
 * @param p9 the channel
 */
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p1;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write.");

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) DIRECTORY_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                write_directory(p0, *d, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) DISPLAY_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // The destination window identification item data.
                void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Get destination window identification item data.
                copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

                write_display(w, p7);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) FILE_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                write_basic(p0, *d, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) INLINE_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                write_inline(p0, *d, p2);
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

                write_basic(p0, *d, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) SIGNAL_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                write_signal(p7, p8);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) SOCKET_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#if defined(__linux__) || defined(__unix__)
                write_basic(p0, *d, p2);
#elif defined(__APPLE__) && defined(__MACH__)
                write_basic(p0, *d, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                write_winsock(p0, *d, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, p9, (void*) TERMINAL_CYBOI_CHANNEL);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

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

#if defined(__linux__) || defined(__unix__)
                write_basic(p0, *d, p2);
#elif defined(__APPLE__) && defined(__MACH__)
                write_basic(p0, *d, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
                write_win32_console(p0, *d, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write. The channel is unknown.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write. The source data is null.");
    }
}

/* WRITER_SOURCE */
#endif
