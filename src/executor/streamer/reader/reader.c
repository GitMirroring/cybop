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

#ifndef READER_SOURCE
#define READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/streamer/reader/entry_reader.c"
#include "../../../executor/streamer/reader/flag_reader.c"
#include "../../../logger/logger.c"

/**
 * Reads data via the given channel into the destination.
 *
 * CAUTION! Do NOT rename this function to "read",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 * Function: ssize_t read (int filedes, void *buffer, size_t size)
 *
 * @param p0 the destination item
 * @param p1 the source device identification (e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source device count
 * @param p3 the destination mutex (only relevant, if destination is the internal buffer, which is shared with the sensing thread, may otherwise be NULL)
 * @param p4 the language (protocol)
 * @param p5 the internal memory
 * @param p6 the channel
 * @param p7 the server flag
 * @param p8 the port
 * @param p9 the asynchronicity flag
 */
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read data.");
    fwprintf(stdout, L"Debug: Read data. p0: %i\n", p0);

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client entry belonging to given source device.
    read_entry((void*) &ce, p5, p6, p7, p8, p1);

    //
    // CAUTION! Do NOT check client entry for NULL here,
    // since the INLINE_CYBOI_CHANNEL does NOT have one.
    // Otherwise, it would not be processed.
    //

    // Read data via the given channel into the destination.
    read_flag(p0, p1, p2, p3, ce, p4, p6, p9);
}

/* READER_SOURCE */
#endif
