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

//
// Library interface
//

#include "client.h"
#include "constant.h"
#include "logger.h"

/**
 * Opens up a first-in-first-out (fifo), also called "named pipeline" (named pipe).
 *
 * A fifo special file is similar to a pipe,
 * except that it is created in a different way.
 * Instead of being an anonymous communications channel,
 * a fifo special file is entered into the file system.
 *
 * Once created, any process can open the fifo special file
 * for reading or writing, in the same way as an ordinary file.
 *
 * However, it has to be open at both ends simultaneously before
 * one can proceed to do any input or output operations on it.
 * Opening a fifo for reading normally blocks until some other
 * process opens the same fifo for writing, and vice versa.
 *
 * https://www.gnu.org/software/libc/manual/html_mono/libc.html#FIFO-Special-Files
 *
 * @param p0 the file descriptor
 * @param p1 the filename data
 * @param p2 the filename count
 */
void open_fifo(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open fifo.");

#if defined(__linux__) || defined(__unix__)
    open_unix_fifo(p0, p1, p2);
#elif defined(__APPLE__) && defined(__MACH__)
    open_unix_fifo(p0, p1, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? open_win32_fifo(p0, p1, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
