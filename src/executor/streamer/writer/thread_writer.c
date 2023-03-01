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

#ifndef THREAD_WRITER_SOURCE
#define THREAD_WRITER_SOURCE

#include <threads.h> // thrd_t

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/streamer/writer/function_writer.c"
#include "../../../executor/threader/spinner.c"
#include "../../../logger/logger.c"
#include "../../../variable/thread_identification.c"

/**
 * Prepares the write thread.
 *
 * @param p0 the client entry
 */
void write_thread(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write thread.");
    //?? fwprintf(stdout, L"Debug: Write thread. client entry p0: %i\n", p0);

    // The thread identification.
    thrd_t t = DEFAULT_THREAD_IDENTIFICATION;
    // The thread function.
    void* f = (void*) &write_function;

    //
    // CAUTION! Do NOT get thread identification from client entry.
    // Contrarily to the input, the output thread gets exited AUTOMATICALLY
    // if all data has been written. Therefore, neither the thread
    // identification, nor an exit flag have to be stored in client entry.
    //

    // Invoke write function WITHIN a new thread.
    spin((void*) &t, f, p0);
}

/* THREAD_WRITER_SOURCE */
#endif
