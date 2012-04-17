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

#ifndef INLINE_RECEIVER_SOURCE
#define INLINE_RECEIVER_SOURCE

#include <stdio.h>

#include "../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Receives inline into the destination.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data
 * @param p3 the source count
 * @param p4 the format
 */
void receive_inline(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive inline.");

    // CAUTION! Do NOT try to decode from UTF-8 or other formats here!
    //
    // The reason is that each cybol file is already decoded from a multibyte
    // character array into a wide character array at once when being read.
    // Therefore, data do NOT have to be decoded once more when being
    // evaluated as inline wide character array.

    // Decode source data according to given type.
    deserialise(p0, p1, p2, p3, p4);
}

/* INLINE_RECEIVER_SOURCE */
#endif
