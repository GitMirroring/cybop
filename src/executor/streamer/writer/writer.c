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

#ifndef WRITER_SOURCE
#define WRITER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/finder/entry_finder.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter/channel_internal_memory_getter.c"
#include "../../../executor/calculator/server_identification/channel_server_identification_calculator.c"
#include "../../../executor/finder/server_entry_finder.c"
#include "../../../executor/streamer/reader/flag_reader.c"

/**
 * Writes source data via the given channel into the destination device.
 *
 * CAUTION! Do NOT rename this function to "write",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 *
 * @param p0 the destination device data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p1 the destination device count
 * @param p2 the source item
 * @param p3 the source mutex (only relevant, if destination is the internal buffer, which is shared with the sensing thread)
 * @param p4 the language (protocol)
 * @param p5 the internal memory
 * @param p6 the channel
 * @param p7 the port
 * @param p8 the asynchronous mode
 */
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write data.");
    fwprintf(stdout, L"Debug: Write data. p0: %i\n", p0);

    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source message mutex.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, p5, p6, p7, p8, p1);
    // Get source message mutex.
    copy_array_forward((void*) &m, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

    //
    // CAUTION! Do NOT check client entry for NULL here,
    // since the INLINE_CYBOI_CHANNEL does NOT have one.
    // Otherwise, it would not be processed.
    //

    //
    // Write source message into buffer.
    //
    // CAUTION! This has to be done in ANY CASE, not only
    // in asynchronous mode, but also in synchronous mode.
    // The reason is UNIFORM processing.
    //
    // Within basic write functionality, the successfully
    // transmitted data are REMOVED from the buffer.
    // If it is empty, then the "complete flag" is set,
    // so that the loop can be left.
    //
    write_buffer(p0, p4, p6, p7);

 * @param p0 the destination device file descriptor (a file, serial port, terminal, socket) OR window id OR item (for inline channel)
 * @param p1 the source buffer data (pointer reference)
 * @param p2 the source buffer count
 * @param p3 the source buffer size
 * @param p4 the source buffer type
 * @param p5 the source part (pointer reference), e.g. a signal
 * @param p6 the source buffer mutex
 * @param p7 the client entry
 * @param p8 the channel
 * @param p9 the asynchronicity flag
    // Write data via the given channel into the destination.
    write_flag(p0, p1, p2, p3, ce, p4, p6, p8);
}

/* WRITER_SOURCE */
#endif
