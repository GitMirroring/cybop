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

#ifndef COMPLETION_READER_SOURCE
#define COMPLETION_READER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/pointer/unequal_pointer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/streamer/reader/handler_reader.c"
#include "../../../logger/logger.c"

/**
 * Informs the system about completion of the read process.
 *
 * - synchronous reading: set loop break flag
 * - asynchronous reading: write into interrupt pipe
 *
 * @param p0 the loop break flag
 * @param p1 the interrupt pipe write file descriptor
 * @param p2 the interrupt mutex
 * @param p3 the handler (pointer reference)
 * @param p4 the closer (pointer reference)
 * @param p5 the client identification
 * @param p6 the thread exit flag
 * @param p7 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p8 the close flag
 */
void read_completion(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read completion.");
    //?? fwprintf(stdout, L"Debug: Read completion. handler p3: %i\n", p3);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Check for asynchronous mode.
    //
    // CAUTION! The existence of a handler is taken as CRITERION.
    // The "asynchronicity" flag handed over to the reader as parametre
    // decides whether to read data from a device OR buffer.
    // It CANNOT be taken here as criterion, since a sense thread
    // reads data in synchronous mode from device and would thus
    // never be able to inform the interrupt pipe here, since that
    // is only written if in asynchronous mode.
    //
    // Therefore, write to the interrupt pipe whenever
    // a HANDLER is available.
    //
    // CAUTION! Do NOT use "equal" comparison, since synchronous
    // mode (NO handler given) has to be the DEFAULT.
    //
    compare_pointer_unequal((void*) &r, p3, NULL_POINTER_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is SYNCHRONOUS mode.
        //
        // The message was read from the device DIRECTLY
        // into the CYBOL destination.
        //

        //?? fwprintf(stdout, L"Debug: Read completion. Synchronous mode. Set loop break flag. p0: %i\n", p0);

        // Set loop break flag.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        //
        // This is ASYNCHRONOUS mode.
        //
        // The message was read from the device INDIRECTLY
        // into a cyboi-internal BUFFER.
        //

        //?? fwprintf(stdout, L"Debug: Read completion. Asynchronous mode. Add handler to interrupt pipe. p0: %i\n", p0);

        // Write handler into interrupt pipe.
        read_handler(p0, p1, p2, p3, p4, p5, p6, p7, p8);
    }
}

/* COMPLETION_READER_SOURCE */
#endif
