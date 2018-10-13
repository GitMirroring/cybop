/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef OPEN_UNIX_TERMINAL_STARTER_SOURCE
#define OPEN_UNIX_TERMINAL_STARTER_SOURCE

#include <stdio.h> // FILE, stdout, stdin

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../logger/logger.c"

/**
 * Opens the unix terminal.
 *
 * @param p0 the destination output file descriptor
 * @param p1 the destination input file descriptor
 */
void startup_unix_terminal_open(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup unix terminal open.");

    // The terminal output- and input file streams.
    FILE* os = stdout;
    FILE* is = stdin;

    // Get terminal file descriptors from file streams.
    int o = fileno(os);
    int i = fileno(is);

    // Copy file descriptors to destination.
    copy_integer(p0, (void*) &o);
    copy_integer(p1, (void*) &i);
}

/* OPEN_UNIX_TERMINAL_STARTER_SOURCE */
#endif
