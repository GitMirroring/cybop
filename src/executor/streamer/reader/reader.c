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
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter/channel_internal_memory_getter.c"
#include "../../../executor/calculator/server_identification/channel_server_identification_calculator.c"
#include "../../../executor/finder/server_entry_finder.c"
#include "../../../executor/streamer/reader/flag_reader.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_internal_memory_mapper.c"

/**
 * Reads data via the given channel into the destination.
 *
 * CAUTION! Do NOT rename this function to "read",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 * Function: ssize_t read (int filedes, void *buffer, size_t size)
 *
 * @param p0 the destination item
 * @param p1 the source device data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source device count
 * @param p3 the destination mutex (only relevant, if destination is the internal buffer, which is shared with the sensing thread, may otherwise be NULL)
 * @param p4 the language (protocol)
 * @param p5 the internal memory
 * @param p6 the channel
 * @param p7 the port
 * @param p8 the asynchronous mode
 * @param px the stub flag
 */
void read_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read data.");
    fwprintf(stdout, L"Debug: Read data. p0: %i\n", p0);

    // The internal memory name.
    int n = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The clients list.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The servers list.
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get internal memory name by channel.
    map_channel_to_internal_memory((void*) &n, p6);

    // Get channel input output entry from internal memory.
    copy_array_forward((void*) &io, p5, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &n);

    if (stub == false) {

        //
        // This is a standalone client.
        //
        // It may send requests to a server.
        //

        // Get clients list from input output entry.
        copy_array_forward((void*) &cl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CLIENTS_INPUT_OUTPUT_STATE_CYBOI_NAME);

    } else {

        //
        // This is a server-side client stub.
        //
        // It was created by the server and is stored
        // in the server's client list.
        //

        // Get servers list from input output entry.
        copy_array_forward((void*) &sl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);

        // Get server entry from servers list by port number.
        //?? TODO

        // Get stub clients list from server entry.
        copy_array_forward((void*) &cl, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);
    }

    // Get client entry from stub clients list by identification.
    find_client_list((void*) &ce, cl, p1);

    //
    // CAUTION! Do NOT check client entry for NULL here,
    // since the INLINE_CYBOI_CHANNEL does NOT have one.
    // Otherwise, it would not be processed.
    //

 * @param p0 the destination item
 * @param p1 the source data (identification e.g. file descriptor of a file, serial port, client socket, window id OR input text for inline channel)
 * @param p2 the source count
 * @param p3 the destination mutex
 * @param p4 the client entry
 * @param p5 the language (protocol)
 * @param p6 the channel
 * @param p7 the asynchronous mode
    // Read data via the given channel into the destination.
    read_flag(p0, p1, p2, p3, ce, p4, p6, p8);
}

/* READER_SOURCE */
#endif
