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
 * @version CYBOP 0.27.0 2023-08-31
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
 * Deserialises the binary crlf termination data.
 *
 * @param p0 the destination message length
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_binary_crlf_termination_data(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise binary crlf termination data.");
    //?? fwprintf(stdout, L"Debug: Deserialise binary crlf termination data. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise binary crlf termination data. *p2: %i\n", *((int*) p2));

    // The binary crlf termination data, count.
    void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int bc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The termination count.
    int tc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise binary crlf termination data.
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

        select_binary_crlf_termination((void*) &b, p1, p2, (void*) &bc, (void*) &tc);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Copy binary crlf termination count to destination message length.
            copy_integer(p0, (void*) &bc);

            //
            // Add termination count to destination message length.
            //
            // CAUTION! This is IMPORTANT since without termination characters,
            // the message would be incomplete and might lead to errors
            // when deserialising it later.
            //
            calculate_integer_add(p0, (void*) &tc);

            break;
        }
    }
}
