/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Decodes the dos character into a utf-32 wide character.
 *
 * @param p0 the destination item
 * @param p1 the source character
 * @param p2 the encoding
 */
void decode_dos_character(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode dos character.");
    //?? fwprintf(stdout, L"Debug: Decode dos character. p1: %i\n", p1);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The range border.
    unsigned char b = (unsigned char) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // Characters 0..127 (ascii)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Cast range border.
        b = (unsigned char) *NUMBER_128_INTEGER_STATE_CYBOI_MODEL;

        // CAUTION! Do NOT use function "compare_integer_less" here.
        compare_character_less((void*) &r, p1, (void*) &b);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Decode dos character. ascii: %i\n", r);

            decode_ascii(p0, p1);
        }
    }

    //
    // Characters 128..255 (dos)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Decode dos character. dos: %i\n", r);

        decode_dos_extension(p0, p1, p2);
    }
}
