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
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the binary crlf data.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_binary_crlf_data(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise binary crlf data.");
    //?? fwprintf(stdout, L"Debug: Deserialise binary crlf data. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise binary crlf data. *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise binary crlf data. p1: %s\n", (char*) *((void**) p1));

    // The binary crlf data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The termination count.
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise binary crlf data.
    copy_pointer((void*) &bd, p1);

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //
        // CAUTION! The termination count is handed over as requested,
        // but it has NO MEANING here in the message deserialiser.
        //
        // However, it HAS a meaning in both the sensor and the reader,
        // which have been executed before. Within them, the termination
        // count/characters have to be added/copied so that this message
        // deserialiser right here can detect the end of the message.
        //
        select_binary_crlf_termination((void*) &b, p1, p2, (void*) &bc, (void*) &tc);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise binary crlf data. bc: %i\n", bc);
            //?? fwprintf(stdout, L"Debug: Deserialise binary crlf data. bd: %s\n", (char*) bd);

            //
            // Copy source data to destination item.
            //
            // CAUTION! The termination count is NOT added or considered
            // for the element count, since only the message data itself
            // but NOT the termination characters are to be copied.
            //
            modify_item(p0, bd, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &bc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

/*??
            //?? TEST BEGIN
            void* testd = *NULL_POINTER_STATE_CYBOI_MODEL;
            void* testc = *NULL_POINTER_STATE_CYBOI_MODEL;
            copy_array_forward((void*) &testd, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &testc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
            fwprintf(stdout, L"Debug: Deserialise binary crlf data. testc: %i\n", testc);
            fwprintf(stdout, L"Debug: Deserialise binary crlf data. *testc: %i\n", *((int*) testc));
            fwprintf(stdout, L"Debug: Deserialise binary crlf data. testd: %s\n", (char*) testd);
            //?? TEST END
*/

            break;
        }
    }
}
