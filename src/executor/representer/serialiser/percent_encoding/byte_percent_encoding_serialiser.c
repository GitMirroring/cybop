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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises multibyte character sequence into percent-encoded bytes.
 *
 * @param p0 the destination character item
 * @param p1 the source wide character
 */
void serialise_percent_encoding_byte(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise percent encoding byte.");

    //
    // Serialise byte into string of two hexadecimal digits.
    //
    // CAUTION! Hand over HEXADECIMAL number base as parametre!
    //
    // CAUTION! Hand over prefix flag value FALSE, since a prefix "%"
    // was already prepended above and the "0x" prefix is NOT wanted.
    //
    //?? TODO:
    //?? serialise_numeral_integer((void*) &i, rd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) HEXADECIMAL_BASE_NUMERAL_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
}
