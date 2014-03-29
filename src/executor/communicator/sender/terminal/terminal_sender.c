/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SENDER_SOURCE
#define TERMINAL_SENDER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/sender/terminal/standard_terminal_sender.c"
#include "../../../../executor/representer/serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the terminal.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the knowledge memory part
 * @param p5 the format
 * @param p6 the language indentation
 * @param p7 the language
 * @param p8 the encoding
 * @param p9 the internal memory data
 * @param p10 the clear flag
 * @param p11 the newline flag
 */
void send_terminal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send terminal.");

#ifdef __APPLE__
    // Process all other cases in the standard way.
    send_terminal_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
#elif WIN32
    // Serialise tui DIRECTLY using win32 console function calls.
    // Therefore, encoding and sending are superfluous.
    // A destination item does NOT need to be handed over,
    // which is why the first parametre is NULL.
    serialise(*NULL_POINTER_STATE_CYBOI_MODEL, p0, p1, p2, p3, p4, p9, p10, p11, p5, p6, p7);
#elif GNU_LINUX_OPERATING_SYTEM
    // Process all other cases in the standard way.
    send_terminal_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
#else
    // Process all other cases in the standard way.
    send_terminal_standard(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
#endif
}

/* TERMINAL_SENDER_SOURCE */
#endif
