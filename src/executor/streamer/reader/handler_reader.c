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

#ifndef HANDLER_READER_SOURCE
#define HANDLER_READER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/streamer/writer/interrupt_pipe/interrupt_pipe_writer.c"
#include "../../../logger/logger.c"

/**
 * Writes a suitable handler into the interrupt pipe.
 *
 * - standard: data sensing event handler
 * - closing: closer handler since client has closed the connexion
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
void read_handler(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read handler.");
    //?? fwprintf(stdout, L"Debug: Read handler. close flag p8: %i\n", p8);
    //?? fwprintf(stdout, L"Debug: Read handler. close flag *p8: %i\n", *((int*) p8));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p8, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The close flag is NOT set.
        //

        // Reset message length.
        copy_integer(p7, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

        // Hand over sensing handler to interrupt pipe of main threaad.
        write_interrupt_pipe(p1, p3, p5, p2);

        //
        // CAUTION! Do NOT set the loop break flag here,
        // since the loop has to CONTINUE to run as long as
        // the sensing thread is active and the exit flag not set.
        //

    } else {

        //
        // The close flag IS set.
        //
        // This means that the communication partner (peer)
        // has closed its connexion.
        //

        //?? fwprintf(stdout, L"\n\n\nDebug: Read handler. close flag *p8: %i\n\n\n", *((int*) p8));

        //
        // Set client stub sensing thread exit flag.
        //
        // CAUTION! The thread exit flag has to be set HERE and
        // NOT only in the close handler since otherwise:
        // - the thread sensing loop would run on and
        // - the "read" function continue to return zero and
        // - THIS source code right here be executed repeatedly and
        // - another (redundant) close handler be put into the interrupt pipe
        //
        // ... until the first of these close handlers would finally
        // be executed in the main thread and exit this sensing flag.
        //
        // CAUTION! However, a close handler HAS TO BE added to the interrupt pipe
        // below anyway, in order to properly deallocate the client entry.
        //
        // When the close handler is executed in the main thread,
        // it tries to exit this (then already exited) sensing thread.
        // But this call will be just IGNORED if the thread is NULL.
        //
        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Set read loop break flag.
        //
        // CAUTION! This is IMPORTANT, so that the calling sensing function
        // can be reached and the thread EXIT flag be detected THERE.
        //
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Hand over client closer handler to interrupt pipe of main thread.
        //
        // CAUTION! The closer handler IS NECESSARY for deallocating
        // the client entry and its resources. Just setting the
        // thread exit flag further above is NOT sufficient.
        //
        write_interrupt_pipe(p1, p4, p5, p2);
    }
}

/* HANDLER_READER_SOURCE */
#endif
