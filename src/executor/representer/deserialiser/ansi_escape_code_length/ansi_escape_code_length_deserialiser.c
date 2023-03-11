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

#ifndef ANSI_ESCAPE_CODE_LENGTH_DESERIALISER_SOURCE
#define ANSI_ESCAPE_CODE_LENGTH_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/selector/ansi_escape_code_length/ansi_escape_code_length_selector.c"
#include "logger.h"

/**
 * Deserialises the ansi escape code length.
 *
 * @param p0 the destination message length
 * @param p1 the source character data
 * @param p2 the source character count
 */
void deserialise_ansi_escape_code_length(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise ansi escape code length.");
    //?? fwprintf(stdout, L"Debug: Deserialise ansi escape code length. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise ansi escape code length. *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise ansi escape code length. p1: %s\n", (char*) p1);

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    //
    // CAUTION! A COPY of source count remaining is forwarded here,
    // so that the original source value does NOT get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    select_ansi_escape_code_length(p0, (void*) &d, (void*) &c);
}

/* ANSI_ESCAPE_CODE_LENGTH_DESERIALISER_SOURCE */
#endif
