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

#ifndef TERMINAL_READER_SOURCE
#define TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/streamer/reader/terminal/entry_terminal_reader.c"
#include "../../../../executor/streamer/reader/terminal/stream_terminal_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads data via terminal.
 *
 * @param p0 the destination item
 * @param p1 the source service identification data
 * @param p2 the internal memory data
 * @param p3 the blocking flag
 */
void read_terminal(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read terminal.");

    // The terminal input file stream.
    void* is = *NULL_POINTER_STATE_CYBOI_MODEL;

    read_terminal_entry((void*) &is, p2, p1);

    // Read data from stream.
    read_terminal_stream(p0, is, p3);
}

/* TERMINAL_READER_SOURCE */
#endif
