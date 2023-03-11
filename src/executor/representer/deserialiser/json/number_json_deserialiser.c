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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef NUMBER_JSON_DESERIALISER_SOURCE
#define NUMBER_JSON_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/less_or_equal_integer_comparator.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/representer/deserialiser/numeral/numeral_deserialiser.c"
#include "../../../../executor/selector/json/end_number_json_selector.c"
#include "logger.h"

/**
 * Deserialises the json number.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the decimal separator data
 * @param p5 the decimal separator count
 * @param p6 the thousands separator data
 * @param p7 the thousands separator count
 * @param p8 the name data
 * @param p9 the name count
 */
void deserialise_json_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise json number.");
    fwprintf(stdout, L"Debug: Deserialise json number. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise json number. count remaining *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Deserialise json number. data position *p2 ls: %ls\n", (wchar_t*) *((void**) p2));
    fwprintf(stdout, L"Debug: Deserialise json number. data position *p2 lc: %lc\n", *((wchar_t*) *((void**) p2)));
    fwprintf(stdout, L"Debug: Deserialise json number. data position *p2 lc as int: %i\n", *((wchar_t*) *((void**) p2)));

    // The number data, count.
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int nc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Initialise number data.
    copy_pointer((void*) &nd, p2);

    if (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null numbers.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_json_number_end(p2, p3, (void*) &nc, (void*) &b);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"Debug: Deserialise json number. nc: %i\n", nc);
            fwprintf(stdout, L"Debug: Deserialise json number. nd: %ls\n", (wchar_t*) nd);

            //
            // Deserialise numeral.
            //
            // CAUTION! The number part gets allocated inside the called function.
            // Therefore, its name data and count are handed over as parametre.
            //
            // CAUTION! Hand over FALSE as consider number base prefix flag,
            // since the json specification does not allow using number
            // prefixes like "0x" for hexadecimal or just "0" for octal numbers.
            // If a number literal with LEADING ZERO is found in some json data,
            // then it has to be interpreted as DECIMAL number by default,
            // by just IGNORING any leading zeros.
            // Furthermore, this is important so that leading zeros as pre-point
            // value get recognised correctly and used with decimal number base.
            //
            deserialise_numeral(*NULL_POINTER_STATE_CYBOI_MODEL, (void*) &p, nd, (void*) &nc, p4, p5, p6, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p8, p9, *NULL_POINTER_STATE_CYBOI_MODEL);

            //
            // Append number part to destination.
            //
            // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
            // This is necessary in order to activate rubbish (garbage) collection.
            //
            modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            break;
        }
    }
}

/* NUMBER_JSON_DESERIALISER_SOURCE */
#endif
