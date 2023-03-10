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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WRITER_SOURCE
#define WRITER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/array/forward_array_copier.c"
#include "../../../executor/finder/entry_finder.c"
#include "../../../executor/streamer/writer/buffer_writer.c"
#include "../../../executor/streamer/writer/flag_writer.c"
#include "../../../logger/logger.c"
#include "../../../mapper/channel_to_type_mapper.c"

/**
 * Writes source data via the given channel into the destination device.
 *
 * CAUTION! Do NOT rename this function to "write", since that name is
 * already used by low-level glibc functionality in header file "unistd.h".
 * Function: ssize_t write (int filedes, const void *buffer, size_t size)
 *
 * @param p0 the destination device identification item, e.g. file descriptor (a file, serial port, terminal, socket) OR window id OR knowledge tree element (for inline channel)
 * @param p1 the source message data
 * @param p2 the source message count
 * @param p3 the source part (pointer reference), e.g. a signal
 * @param p4 the internal memory
 * @param p5 the channel
 * @param p6 the server flag
 * @param p7 the port
 * @param p8 the output writer handler (pointer reference)
 * @param p9 the asynchronicity flag
 */
void write_data(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write data.");
    //?? fwprintf(stdout, L"Information: Write data. message count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Information: Write data. message count *p2: %i\n", *((int*) p2));

/*??
    fwprintf(stdout, L"Information: Write data. internal memory p4: %i\n", p4);
    fwprintf(stdout, L"Information: Write data. channel p5: %i\n", p5);
    fwprintf(stdout, L"Information: Write data. channel *p5: %i\n", *((int*) p5));
    fwprintf(stdout, L"Information: Write data. server flag p6: %i\n", p6);
    if (p6 != 0)
        fwprintf(stdout, L"Information: Write data. server flag *p6: %i\n", *((int*) p6));
    fwprintf(stdout, L"Information: Write data. port p7: %i\n", p7);
    if (p7 != 0)
        fwprintf(stdout, L"Information: Write data. port *p7: %i\n", *((int*) p7));
*/

    //
    // Declaration
    //

    // The destination device identification item data.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output buffer item.
    void* bi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output buffer mutex.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output buffer item type.
    int t = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get destination device identification item data.
    copy_array_forward((void*) &dd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Information: Write data. device id dd: %i\n", dd);
    //?? fwprintf(stdout, L"Information: Write data. device id *dd: %i\n", *((int*) dd));

    // Get client entry belonging to given source device.
    find_entry((void*) &ce, p4, p5, p6, p7, dd);

    //?? fwprintf(stdout, L"Information: Write data. client entry ce: %i\n", ce);

    // Get output buffer item from client entry.
    copy_array_forward((void*) &bi, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);
    // Get output buffer mutex from client entry.
    copy_array_forward((void*) &bm, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MUTEX_BUFFER_OUTPUT_CLIENT_STATE_CYBOI_NAME);

    // Map channel to datatype.
    map_channel_to_type((void*) &t, p5);

    //
    // Writing
    //

    //
    // Copy source message into output buffer.
    //
    // CAUTION! This has to be done in ANY CASE, not only
    // in asynchronous mode, but also in synchronous mode.
    // The reason is UNIFORM processing.
    //
    // Within basic write functionality, the successfully
    // transmitted data are REMOVED from the buffer.
    // If it is empty, then the "loop break flag" is set,
    // so that the writing process finishes.
    //
    write_buffer(bi, p1, p2, (void*) &t, bm);

    //
    // CAUTION! Do NOT check client entry for NULL here, since the
    // INLINE_CYBOI_CHANNEL and SIGNAL_CYBOI_CHANNEL do NOT have one.
    // Otherwise, it would not be processed.
    //

    // Write data via the given channel into the destination.
    write_flag(p0, bi, (void*) &t, p3, bm, ce, p4, p5, p8, p9);
}

/* WRITER_SOURCE */
#endif
