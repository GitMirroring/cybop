/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_WRITER_SOURCE
#define TERMINAL_WRITER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/streamer/writer/terminal/file_terminal_writer.c"
#include "../../../../executor/representer/serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Writes the source to the terminal.
 *
 * @param p0 the source data (null-terminated)
 * @param p1 the source count
 * @param p2 the internal memory
 */
void write_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write terminal.");

#ifdef __APPLE__
    write_terminal_file(p0, p1, p2);
#elif WIN32
    // Serialise tui DIRECTLY using win32 console function calls.
    // Therefore, encoding and sending are superfluous.
    // A destination item does NOT need to be handed over,
    // which is why the first parametre is NULL.
//??    serialise(*NULL_POINTER_STATE_CYBOI_MODEL, p0, p1, p2, p3, p4, p9, p10, p11, p5, p6, p7);
#elif GNU_LINUX_OPERATING_SYTEM
    write_terminal_file(p0, p1, p2);
#else
    write_terminal_file(p0, p1, p2);
#endif
}

/* TERMINAL_WRITER_SOURCE */
#endif
