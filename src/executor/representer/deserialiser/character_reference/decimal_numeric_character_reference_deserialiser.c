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

#ifndef DECIMAL_NUMERIC_CHARACTER_REFERENCE_DESERIALISER_SOURCE
#define DECIMAL_NUMERIC_CHARACTER_REFERENCE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the decimal numeric character reference.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_character_reference_numeric_decimal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise character reference numeric decimal.");

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

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_character_reference_end((void*) &b, p1, p2);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment decimal numeric character reference count.
            rc++;
        }
    }

    // Deserialise decimal numeric character reference data into integer number.
    //
    // CAUTION! Hand over number base 10 as parametre!
    deserialise_cybol_integer_value((void*) &i, rd, (void*) &rc, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Cast integer to wide character.
    //
    // CAUTION! This is ONLY POSSIBLE because the glibc types
    // "int" and "wchar_t" have a size of 4 Byte each.
    // If this changes one day, something will have to be adapted here.
    c = (wchar_t) i;

    // Append character to destination.
    modify_item(p0, (void*) &c, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
}

/* DECIMAL_NUMERIC_CHARACTER_REFERENCE_DESERIALISER_SOURCE */
#endif
