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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WIDE_CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define WIDE_CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

//
// Library interface
//

#include "communication.h"
#include "logger.h"

/**
 * Serialises the wide character into an ansi escape code.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void serialise_ansi_escape_code_wide_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code wide character.");

    // Encode wide character and append it to the destination.
    deserialise_ascii(p0, p1, p2);
}

/* WIDE_CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
