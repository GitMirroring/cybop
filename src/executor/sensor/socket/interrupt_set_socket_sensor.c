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

#ifndef INTERRUPT_SOCKET_SENSOR_SOURCE
#define INTERRUPT_SOCKET_SENSOR_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../logger/logger.c"

/*??
#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <unistd.h> // read, write

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/modifier/item_modifier.c"
*/

/**
 * Senses socket message end.
 *
 * Depending on the protocol used, this can be either:
 * - a prefix containing the message length (number of bytes)
 * - a suffix sequence marking the end of the message
 *
 * @param p0 the interrupt pipe write file descriptor
 * @param p1 the interrupt mutex
 * @param p2 the input/output identification (input/output base + socket port)
 * @param p3 the source identification (client socket number)
 * @param p4 the destination buffer item
 * @param p5 the message length detected previously
 */
void sense_socket_set_interrupt(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    //
    // CAUTION! Do NOT log messages within thread,
    // in order to avoid race conditions and other conflicts.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense socket set interrupt.");
    fwprintf(stdout, L"Debug: Sense socket set interrupt. p4: %i\n", p4);

    //
    // The number of bytes predicted by the message prefix has been received.
    //
    // Therefore, the message is COMPLETE and
    // the interrupt pipe may be informed below.
    //
    // CAUTION! The comparison above tests for equal AND greater at the same time
    // since it is possible that many messages have been received at once,
    // so that a second message follows the first directly.
    // In this case, the messages will be SPLIT, which is
    // not done here, but later in the main thread's "reader".
    //

    //?? fwprintf(stdout, L"Debug: Sense socket message. *ipw: %i\n", *ipw);

    // Lock interrupt mutex.
    mtx_lock(im);

    //
    // Write to interrupt pipe.
    //
    // - input/output entry identification (base + port)
    // - client identification
    //
    // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
    // However, if both processes were created using the same compiler version,
    // one can take advantage of the fact that anything in C can be
    // read or written as an array of char (byte).
    //
    // Example:
    //
    // int n = something();
    // write(pipe_w, &n, sizeof(n));
    // int n;
    // read(pipe_r, &n, sizeof(n));
    //
    // https://stackoverflow.com/questions/5237041/how-to-send-integer-with-pipe-between-two-processes
    //
    write(*ipw, p7, sizeof(int));
    write(*ipw, p1, sizeof(int));

    // Unlock interrupt mutex.
    mtx_unlock(im);
}

/* INTERRUPT_SOCKET_SENSOR_SOURCE */
#endif
