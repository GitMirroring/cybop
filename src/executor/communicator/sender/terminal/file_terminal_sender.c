/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_TERMINAL_SENDER_SOURCE
#define FILE_TERMINAL_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/terminal/stream_terminal_sender.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the terminal file.
 *
 * @param p0 the source data (null-terminated)
 * @param p1 the source count
 * @param p2 the internal memory
 */
void send_terminal_file(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send terminal file.");

    // The terminal output file descriptor.
//??    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! This is a temporary solution.
    // Normally, EACH cybol application would have to call
    // the "maintain/startup" operation with channel "terminal",
    // in order to be able to output anything on terminal.
    // As a convenience for cybol developers, the standard
    // output stream is set as default here.
    void* t = (void*) stdout;

    // Get terminal output file descriptor.
//??    copy_array_forward((void*) &t, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_STREAM_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    send_terminal_stream(t, p0, p1);
}

/* FILE_TERMINAL_SENDER_SOURCE */
#endif
