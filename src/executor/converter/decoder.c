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

#ifndef DECODER_SOURCE
#define DECODER_SOURCE

#include "../../constant/encoding/cyboi/cyboi_encoding.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../executor/converter/decoder/iso_8859/iso_8859_decoder.c"
#include "../../executor/converter/decoder/utf/utf_16_decoder.c"
#include "../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../executor/converter/decoder/windows/windows_decoder.c"
#include "../../executor/modifier/overwriter/item_overwriter.c"
#include "../../logger/logger.c"

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

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // general
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p3, (void*) NONE_CYBOI_ENCODING);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            overwrite_item_element(p0, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        }
    }

    //
    // iso
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
    // utf
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
    }
}

/* DECODER_SOURCE */
#endif
