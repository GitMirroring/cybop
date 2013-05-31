/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_TERMINAL_RECEIVER_SOURCE
#define STREAM_TERMINAL_RECEIVER_SOURCE

#include <errno.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/terminal/character_terminal_receiver.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Receives data stream from terminal.
 *
 * @param p0 the destination data item
 * @param p1 the source file descriptor data
 * @param p2 the source mutex
 */
void receive_terminal_stream(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive terminal.");

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

            break;
        }

        receive_terminal_character(p0, p1, p2, (void*) &b, (void*) &esc, (void*) &aec, (void*) &c);
    }
}

/* STREAM_TERMINAL_RECEIVER_SOURCE */
#endif
