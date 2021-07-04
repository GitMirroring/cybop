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

#ifndef STREAM_UNIX_TERMINAL_READER_SOURCE
#define STREAM_UNIX_TERMINAL_READER_SOURCE

#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <wchar.h> // WEOF

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/editor.c"
#include "../../../../executor/streamer/reader/unix_terminal/character_unix_terminal_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads data stream from unix terminal.
 *
 * @param p0 the destination item
 * @param p1 the source file stream
 * @param p2 the interrupt request
 * @param p3 the mutex
 * @param p4 the internal memory data
 */
void read_unix_terminal_stream(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        mtx_t* m = (mtx_t*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* i = (int*) p2;

                log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read unix terminal stream.");

                //?? fwprintf(stdout, L"Test: Read unix terminal stream. irq p2 %i\n", p2);
                //?? fwprintf(stdout, L"Test: Read unix terminal stream. irq *p2 %i\n", *((int*) p2));

                // The loop break flag.
                int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
                //
                // The escape character flag.
                //
                // CAUTION! This variable HAS TO BE defined here,
                // since it is used across many loop cycles.
                //
                int esc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
                //
                // The ansi escape code flag.
                //
                // CAUTION! This variable HAS TO BE defined here,
                // since it is used across many loop cycles.
                //
                int aec = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
                //
                // The input character.
                //
                // CAUTION! This variable HAS TO BE defined here,
                // since it is used across many loop cycles.
                //
                // CAUTION! The initial value is set to WEOF,
                // since it is returned by the fgetwc function by default.
                // Hence, do NOT assign the following value:
                // wint_t c = *((wint_t*) NULL_UNICODE_CHARACTER_CODE_MODEL);
                //
                volatile wint_t c = WEOF;

                //?? fwprintf(stdout, L"Test: Read unix terminal stream. b %i\n", b);

                //
                // Lock mutex.
                //
                // CAUTION! This function call blocks the current thread
                // until the mutex is locked.
                //
                // CAUTION! This guarantees exclusive access to
                // input/output resources as well as the interrupt request,
                // which are shared between input sensing (child) threads
                // and the main (parent) thread.
                //
                // CAUTION! Not all input/output channels use sensing threads.
                // Sometimes, the main thread is the only one accessing resources.
                // However, in order to have a uniform implementation,
                // a mutex exists for all channels and it does no harm
                // to lock it here even if only the main thread accesses it.
                //
                mtx_lock(m);

                //
                // Set unblocking mode in terminal.
                //
                // CAUTION! The unix terminal reader is looking ahead for special
                // characters, in order to detect a possible ansi escape code sequence.
                // If no more character is available, then "read" will block
                // the whole main thread with MIN = 1. Therefore, set MIN = 0 here.
                //
                // Example:
                // Pressing the escape key should get processed right away,
                // e.g. to exit a cybol application, WITHOUT WAITING for
                // yet another character input as would be the case
                // with blocking terminal.
                //
                // The value of MIN is set back to 1 (blocking mode) further below,
                // so that sensing terminal data input does not take too much
                // processor time due to busy waiting in an endless loop.
                //
                fwprintf(stdout, L"Test: Read unix terminal stream. set unblocking c %i\n", c);
                edit_service(p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TERMINAL_CYBOI_CHANNEL);

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    //?? fwprintf(stdout, L"Test: Read unix terminal stream. inside loop b %i\n", b);

                    if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        break;
                    }

                    read_unix_terminal_character(p0, p1, (void*) &b, (void*) &esc, (void*) &aec, (void*) &c);
                }

                // Set blocking mode in terminal. VMIN = 1
                fwprintf(stdout, L"Test: Read unix terminal stream. set blocking c %i\n", c);
                edit_service(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TERMINAL_CYBOI_CHANNEL);

                // Reset interrupt request in input/output entry.
                copy_integer(i, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                // Unlock mutex.
                mtx_unlock(m);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal stream. The interrupt request is null.");
            fwprintf(stdout, L"Error: Could not read unix terminal stream. The interrupt request is null.\n");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal stream. The mutex is null.");
        fwprintf(stdout, L"Error: Could not read unix terminal stream. The mutex is null.\n");
    }
}

/* STREAM_UNIX_TERMINAL_READER_SOURCE */
#endif
