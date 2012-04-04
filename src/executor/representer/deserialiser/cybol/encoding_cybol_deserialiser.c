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

#ifndef ENCODING_CYBOL_DESERIALISER_SOURCE
#define ENCODING_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/encoding/cyboi/cyboi_encoding.c"
#include "../../../../constant/encoding/cybol/cybol_encoding.c"
#include "../../../../constant/encoding/cybol/dos_cybol_encoding.c"
#include "../../../../constant/encoding/cybol/iso_8859_cybol_encoding.c"
#include "../../../../constant/encoding/cybol/unicode_cybol_encoding.c"
#include "../../../../constant/encoding/cybol/windows_cybol_encoding.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol encoding into a cyboi encoding.
 *
 * @param p0 the destination data
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_encoding(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol encoding.");

    // CAUTION! Do NOT use the "append" function here!
    // The encoding of each part has been given a size of ONE,
    // so that reallocation is not necessary for adding an element.
    // Therefore, the "overwrite" function has to be used instead.

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) UTF_8_UNICODE_CYBOL_ENCODING, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) UTF_8_UNICODE_CYBOL_ENCODING_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            copy_integer(p0, (void*) UTF_8_CYBOI_ENCODING);
        }
    }

    //?? TODO: Add further encodings here ...

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol encoding. The source encoding is unknown.");
    }
}

/* ENCODING_CYBOL_DESERIALISER_SOURCE */
#endif
