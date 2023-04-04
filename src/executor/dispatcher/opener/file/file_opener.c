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

#ifndef FILE_OPENER_SOURCE
#define FILE_OPENER_SOURCE

//
// System interface
//

#include <sys/stat.h> // mode_t, S_IRWXU
#include <fcntl.h> // O_RDONLY
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "client.h"
#include "constant.h"
#include "logger.h"

/**
 * Opens the file with the given filename.
 *
 * @param p0 the file descriptor
 * @param p1 the filename data
 * @param p2 the filename count
 * @param p3 the file open mode data
 * @param p4 the file open mode count
 */
void open_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open file.");
    //?? fwprintf(stdout, L"Debug: Open file. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Open file. *p0: %i\n", *((int*) p0));

    //
    // The file open mode.
    //
    // CAUTION! The default is READ mode.
    //
    int m = O_RDONLY;

    //
    // The file access permissions.
    //
    // CAUTION! S_IRWXU is equivalent to (S_IRUSR | S_IWUSR | S_IXUSR).
    // It assigns the rights to read/write/execute for the owner of the file.
    //
    // CAUTION! These permissions are used only when a file is CREATED,
    // but it doesn't hurt to supply the argument in any case.
    //
    mode_t p = S_IRWXU;

    // Cast file access permissions to parametre type.
    int pt = (int) p;

    // Determine file open mode.
    open_file_mode((void*) &m, p3, p4);

    // Open device.
    open_basic(p0, p1, p2, (void*) &m, (void*) &pt);
}

/* FILE_OPENER_SOURCE */
#endif
