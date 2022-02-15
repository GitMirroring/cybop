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

#ifndef FLAG_WRITER_SOURCE
#define FLAG_WRITER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/streamer/writer/entry_writer.c"
#include "../../../executor/streamer/writer/loop_writer.c"
#include "../../../executor/streamer/writer/thread_writer.c"
#include "../../../logger/logger.c"

/**
 * Writes data in synchronous (direct) or asynchronous (indirect) mode.
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source buffer data (pointer reference)
 * @param p2 the source buffer count
 * @param p3 the source buffer size
 * @param p4 the source buffer type
 * @param p5 the source part (pointer reference), e.g. a signal
 * @param p6 the source buffer mutex
 * @param p7 the client entry
 * @param p8 the channel
 * @param p9 the destination device identification item (pointer reference)
 * @param p10 the output buffer item (pointer reference)
 * @param p11 the output buffer mutex (pointer reference)
 * @param p12 the source part (pointer reference)
 * @param p13 the channel (pointer reference)
 * @param p14 the asynchronicity flag
 */
void write_flag(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write flag.");
    fwprintf(stdout, L"Debug: Write flag. p0: %i\n", p0);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // CAUTION! Do NOT use "equal" comparison, since synchronous mode has to be the DEFAULT.
    compare_integer_unequal((void*) &r, p14, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is SYNCHRONOUS mode.
        //

        // Write directly into device.
        write_loop(p0, p1, p2, p3, p4, p5, p6, p7, p8);

    } else {

        //
        // This is ASYNCHRONOUS mode.
        //

        // Store data in client entry.
        write_entry(ce, p9, p10, p11, p12, p13);

        // Invoke write function within a new thread.
        write_thread(ce);
    }
}

/* FLAG_WRITER_SOURCE */
#endif
