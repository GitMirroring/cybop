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
#include "type.h"
#include "wui.h"

/**
 * Deserialises the decimal numeric character reference.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_character_reference_decimal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise character reference decimal.");
    //?? fwprintf(stdout, L"Debug: Deserialise character reference decimal. source count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise character reference decimal. source count remaining *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise character reference decimal. source data position p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Deserialise character reference decimal. source data position *p1: %i\n", *((void**) p1));

    // The decimal numeric character reference data, count.
    void* rd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int rc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The deserialised integer.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The deserialised character.
    wchar_t c = *NULL_UNICODE_CHARACTER_CODE_MODEL;

    // Initialise decimal numeric character reference data.
    copy_pointer((void*) &rd, p1);

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

        select_character_reference_end((void*) &b, p1, p2, (void*) &rc);
    }

    //
    // Deserialise decimal numeric character reference data into integer number.
    //
    // CAUTION! Hand over number base 10 as parametre!
    //
    deserialise_numeral_integer((void*) &i, rd, (void*) &rc, (void*) DECIMAL_BASE_NUMERAL_MODEL);

    //
    // Cast integer to wide character.
    //
    // CAUTION! This is ONLY POSSIBLE because the glibc types
    // "int" and "wchar_t" have a size of 4 Byte each.
    // If this changes one day, something will have to be adapted here.
    //
    c = (wchar_t) i;

    // Append character to destination.
    modify_item(p0, (void*) &c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}
