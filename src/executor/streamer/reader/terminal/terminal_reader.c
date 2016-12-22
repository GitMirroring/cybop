/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_READER_SOURCE
#define TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef __APPLE__
    #include "../../../../executor/streamer/reader/unix_terminal/unix_terminal_reader.c"
#elif WIN32
    #include "../../../../executor/streamer/reader/win32_console/win32_console_reader.c"
#elif GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/streamer/reader/unix_terminal/unix_terminal_reader.c"
#else
    #include "../../../../executor/streamer/reader/unix_terminal/unix_terminal_reader.c"
#endif

/**
 * Reads data via terminal.
 *
 * @param p0 the destination item
 * @param p1 the internal memory data
 * @param p2 the blocking flag
 */
void read_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read terminal.");

#ifdef __APPLE__
    read_unix_terminal(p0, p1, p2);
#elif WIN32
    //?? CAUTION! Possibly move this functionality into "win32_console_deserialiser".
    //?? See "write_terminal"!
//??    read_win32_console(p0, p1);
#elif GNU_LINUX_OPERATING_SYSTEM
    read_unix_terminal(p0, p1, p2);
#else
    read_unix_terminal(p0, p1, p2);
#endif
}

/* TERMINAL_READER_SOURCE */
#endif
