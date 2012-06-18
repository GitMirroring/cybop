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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_TERMINAL_SENDER_SOURCE
#define STREAM_TERMINAL_SENDER_SOURCE

#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the terminal output.
 *
 * @param p0 the destination terminal output file descriptor
 * @param p1 the source data (null-terminated)
 * @param p2 the source count
 */
void send_terminal_stream(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send terminal stream.");

    // Check destination terminal output since it is
    // used directly by the "fwprintf" function below.
    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The character data are printed out at once,
        // using the "fwprintf" function, for two reasons:
        //
        // (1) This is more efficient than using a loop and
        //     writing each single character as done in
        //     "element_file_sender.c".
        //
        // (2) The ansi escape codes are interpreted correctly.
        //

        // Send to terminal.
        //
        // CAUTION! The placeholder %s is used, since the data are given
        // as utf-8 multibyte character sequence of type "char".
        // The placeholder %ls would be WRONG here as it expects data
        // of type "wchar_t".
        int e = fwprintf(p0, L"%s", (char*) p1);

        // Test error value.
        //
        // CAUTION! The macro WEOF is an integer value that is
        // returned by fwprintf to indicate an end-of-file
        // condition, or some other error situation.
        //
        // With the GNU library, WEOF is -1. In other libraries,
        // its value may be some other negative number.
        //
        // Therefore, this test checks for negative values in general.
        // The WEOF symbol which is declared in wchar.h then does
        // not have to be considered explicitly here anymore.
        if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send terminal stream. A write error occured.");
        }

        // Flush any buffered output on the stream to the file.
        //
        // If this was not done here, the buffered output on the
        // stream would only get flushed automatically when either:
        // - one tried to do output and the output buffer is full
        // - the stream was closed
        // - the program terminated by calling exit
        // - a newline was written with the stream being line buffered
        // - an input operation on any stream actually read data from its file
        fflush((FILE*) p0);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send terminal stream. The terminal output file descriptor is null.");
    }
}

/* STREAM_TERMINAL_SENDER_SOURCE */
#endif
