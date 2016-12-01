/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_UNIX_TERMINAL_READER_SOURCE
#define STREAM_UNIX_TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/streamer/reader/unix_terminal/character_unix_terminal_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads data stream from unix terminal.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor
 * @param p2 the source mutex
 * @param p3 the blocking flag
 */
void read_unix_terminal_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* bl = (int*) p3;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read unix terminal stream.");

        // The loop break flag.
        int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The escape character flag.
        // CAUTION! This variable HAS TO BE defined here,
        // since it is used across many loop cycles.
        int esc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The ansi escape code flag.
        // CAUTION! This variable HAS TO BE defined here,
        // since it is used across many loop cycles.
        int aec = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
        // The input character.
        //
        // CAUTION! This variable HAS TO BE defined here,
        // since it is used across many loop cycles.
        //
        // CAUTION! The initial value is set to WEOF,
        // since it is returned by the fgetwc function by default.
        // Hence, do NOT assign the following value:
        // wint_t c = *((wint_t*) NULL_UNICODE_CHARACTER_CODE_MODEL);
        wint_t c = WEOF;

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                if (*bl == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // Break loop only if break flag is set
                    // AND blocking flag is false
                    // (possibly reset inside when data were available).
                    break;
                }
            }

            read_unix_terminal_character(p0, p1, p2, p3, (void*) &b, (void*) &esc, (void*) &aec, (void*) &c);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal stream. The blocking flag is null.");
    }
}

/* STREAM_UNIX_TERMINAL_READER_SOURCE */
#endif
