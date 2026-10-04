/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Decodes the windows 1252 character into a utf-32 wide character.
 *
 * @param p0 the destination item
 * @param p1 the source character
 */
void decode_windows_1252(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode windows 1252.");

    //
    // CAUTION! The ORDER of comparisons IS IMPORTANT!
    // Do NOT change it easily!
    //
    // The character is filtered in the following order:
    // - ASCII
    // - Windows
    // - ISO-8859
    //
    // The windows 1252 character set is based upon iso 8859-1.
    // It differs only in range 0x80 to 0x9f, where the rarely used
    // c1 control characters got replaced with printable ones.
    // Its first 128 characters are identical to ascii.
    //

    // The comparison results.
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

            decode_ascii(p0, p1);
        }
    }

    //
    // Characters 128..159 (windows)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Cast range border.
        b = (unsigned char) *NUMBER_160_INTEGER_STATE_CYBOI_MODEL;

        // CAUTION! Do NOT use function "compare_integer_less" here.
        compare_character_less((void*) &r, p1, (void*) &b);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_windows_1252_special(p0, p1);
        }
    }

    //
    // Characters 160..255 (iso-8859)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        decode_iso_8859_extension(p0, p1, (void*) ISO_8859_1_CYBOI_ENCODING);
    }
}
