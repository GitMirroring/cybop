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

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Decodes the source into the destination, according to the given encoding.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the encoding
 */
void decode(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Decode.");
    //?? fwprintf(stdout, L"Information: Decode. encoding p3: %i\n", p3);
    //?? fwprintf(stdout, L"Information: Decode. encoding *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // base 64
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) BASE_64_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_base_64(p0, p1, p2);
        }
    }

    //
    // dos
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) DOS_437_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_dos(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) DOS_850_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_dos(p0, p1, p2, p3);
        }
    }

    //
    // iso 8859
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) ISO_8859_1_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_iso_8859(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) ISO_8859_15_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_iso_8859(p0, p1, p2, p3);
        }
    }

    //
    // unicode
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) UTF_16_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_utf_16(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) UTF_8_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_utf_8(p0, p1, p2);
        }
    }

    //
    // windows
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) WINDOWS_1252_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            decode_windows(p0, p1, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not decode. The encoding is unknown.");
        fwprintf(stdout, L"Warning: Could not decode. The encoding is unknown or null. encoding p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not decode. The encoding is unknown or null. encoding *p3: %i\n", *((int*) p3));
    }
}
