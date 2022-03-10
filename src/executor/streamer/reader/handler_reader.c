/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef HANDLER_READER_SOURCE
#define HANDLER_READER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
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
 * @param p2 the interrupt handlers item
 * @param p3 the interrupt mutex
 * @param p4 the handler (pointer reference)
 * @param p5 the closer (pointer reference)
 * @param p6 the thread exit flag
 * @param p7 the message length (possibly detected previously; should be initialised with a value < 0, e.g. with -1)
 * @param p8 the close flag
 */
void read_handler(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read handler.");
    fwprintf(stdout, L"Debug: Read handler. close flag p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Read handler. close flag *p8: %i\n", *((int*) p8));

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
        write_interrupt_pipe(p1, p2, p4, p3);

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

        // Hand over client closer handler to interrupt pipe of main threaad.
        write_interrupt_pipe(p1, p2, p5, p3);

        //
        // Set client stub sensing thread exit flag.
        //
        // CAUTION! The exit flag might be set in the close handler
        // as well, but requires a thread awakener to be called.
        // Therefore, setting the flag right here is more efficient,
        // since the thread can exit itself when leaving the sensing loop
        // (which is calling this read function).
        //
        copy_integer(p6, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //
        // Set read loop break flag.
        //
        // CAUTION! This is important, so that the calling
        // sensing function can be reached and the exit flag
        // be detected there.
        //
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* HANDLER_READER_SOURCE */
#endif
