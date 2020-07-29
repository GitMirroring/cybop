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

#ifndef FILE_TERMINAL_WRITER_SOURCE
#define FILE_TERMINAL_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/streamer/writer/unix_terminal/file_unix_terminal_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/streamer/writer/unix_terminal/file_unix_terminal_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Serialise tui DIRECTLY using win32 console function calls.
    // Therefore, encode and write are superfluous.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Writes the data to the terminal output file stream.
 *
 * @param p0 the destination output file stream
 * @param p1 the source data (null-terminated)
 */
void write_terminal_file(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write terminal file.");

#if defined(__linux__) || defined(__unix__)
    write_unix_terminal_file(p0, p1);
#elif defined(__APPLE__) && defined(__MACH__)
    write_unix_terminal_file(p0, p1);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Serialise tui DIRECTLY using win32 console function calls.
    // Therefore, encode and write are superfluous.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* FILE_TERMINAL_WRITER_SOURCE */
#endif
