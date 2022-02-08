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

    // The server identification (server base + service port).
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Calculate server identification.
    calculate_server_identification_channel((void*) &id, p6, p7);
    // Get server entry from internal memory.
    get_internal_memory_channel((void*) &se, p5, p6, p7);

    //
    // CAUTION! Do NOT check server entry or client entry for NULL here,
    // since the INLINE_CYBOI_CHANNEL does have NEITHER a server entry
    // NOR a client entry. Otherwise, it would not be processed.
    //

    // Get client entry from server entry client list by given device identification.
    find_server_entry((void*) &ce, se, p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Write data via the given channel.
    write_flag(p0, p1, p2, p3, ce, (void*) &id, p4, p6, p8);
}

/* WRITER_SOURCE */
#endif
