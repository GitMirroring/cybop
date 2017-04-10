/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOWS_1252_DECODER_SOURCE
#define WINDOWS_1252_DECODER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/smaller_integer_comparator.c"
#include "../../../../executor/converter/decoder/ascii/ascii_decoder.c"
#include "../../../../executor/converter/decoder/iso_8859/extension_iso_8859_decoder.c"
#include "../../../../executor/converter/decoder/windows/special_windows_1252_decoder.c"
#include "../../../../logger/logger.c"

/**
 * Decodes the windows 1252 character into a utf-32 wide character.
 *
 * @param p0 the destination item
 * @param p1 the source character
 */
void decode_windows_1252(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode windows 1252.");

    // The comparison results.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // CAUTION! The ORDER of comparisons IS IMPORTANT!
    // Do NOT change it easily!
    //
    // The character is filtered in the following order:
    // - ASCII
    // - Windows
    // - ISO-8859
    //

    //
    // Characters 0..127 (ascii)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller((void*) &r, p1, (void*) NUMBER_128_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_ascii(p0, p1);
        }
    }

    //
    // Characters 128..159 (windows)
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller((void*) &r, p1, (void*) NUMBER_160_INTEGER_STATE_CYBOI_MODEL);

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

/* WINDOWS_1252_DECODER_SOURCE */
#endif
