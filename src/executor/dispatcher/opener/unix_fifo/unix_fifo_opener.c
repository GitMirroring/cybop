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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNIX_FIFO_OPENER_SOURCE
#define UNIX_FIFO_OPENER_SOURCE

#include <sys/stat.h> // mode_t, S_IRWXU
#include <fcntl.h> // O_RDWR, O_NOCTTY

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/dispatcher/opener/basic/basic_opener.c"
#include "../../../../executor/dispatcher/opener/unix_fifo/file_unix_fifo_opener.c"
#include "../../../../logger/logger.c"

/**
 * Makes a unix first-in-first-out (fifo), also called "named pipeline" (named pipe).
 *
 * @param p0 the file descriptor
 * @param p1 the filename data
 * @param p2 the filename count
 */
void open_unix_fifo(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open unix fifo.");
    fwprintf(stdout, L"Debug: Open unix fifo. p0: %i\n", p0);

    //
    // The open mode (access permission bits).
    //
    // CAUTION! S_IRWXU is equivalent to (S_IRUSR | S_IWUSR | S_IXUSR).
    // It assigns the rights to read/write/execute for the owner of the file.
    //
    // CAUTION! This mode is used only when a file is CREATED,
    // but it doesn't hurt to supply the argument in any case.
    //
    mode_t m = S_IRWXU;

    // Cast to parametre type.
    int mt = (int) m;

    // Create fifo special file in filesystem.
    open_unix_fifo_file(p1, p2, (void*) &mt);

    //
    // The open flags.
    //
    // Default settings:
    // O_RDWR - open file for both reading and writing
    // O_NOCTTY - don't make the terminal device referenced by
    //      the filename the controlling terminal for the process
    //      (possibly important for compatibility with GNU/Hurd systems and 4.4 BSD)
    //
    int f = O_RDWR | O_NOCTTY;

    // Open device.
    open_basic(p0, p1, p2, (void*) &f, (void*) &mt);
}

/* UNIX_FIFO_OPENER_SOURCE */
#endif
