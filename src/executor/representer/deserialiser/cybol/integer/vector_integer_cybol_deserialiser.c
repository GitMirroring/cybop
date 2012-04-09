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

#ifndef VECTOR_INTEGER_CYBOL_DESERIALISER_SOURCE
#define VECTOR_INTEGER_CYBOL_DESERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../executor/representer/deserialiser/cybol/integer/value_integer_cybol_deserialiser.c"
#include "../../../../../executor/searcher/selector/cybol/integer_cybol_selector.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the comma-separated wide character data into integer values.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_cybol_integer_vector(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol integer vector.");

    // The element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise element.
    copy_pointer((void*) &e, p1);

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

        compare_integer_smaller_or_equal((void*) &b, p2, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_cybol_integer(p0, (void*) &b, p1, p2);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Increment element count.
            ec++;
        }
    }

    // Prepend element to destination.
    deserialise_cybol_integer_value(p0, e, (void*) &ec, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
}

/* VECTOR_INTEGER_CYBOL_DESERIALISER_SOURCE */
#endif
