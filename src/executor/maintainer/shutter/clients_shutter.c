/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CLIENTS_SHUTTER_SOURCE
#define CLIENTS_SHUTTER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"
--
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/maintainer/shutter/client_shutter.c"

/**
 * Shuts down all clients of this server.
 *
 * @param p0 the client list data (pointer reference)
 * @param p1 the client list count
 * @param p2 the client list size
 */
void shutdown_clients(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown clients.");
    fwprintf(stdout, L"Debug: Shutdown clients. p0: %i\n", p0);

    //
    // CAUTION! The loop is running in REVERSE ORDER,
    // from the last to the first element, since that way,
    // the function "remove" works much FASTER inside,
    // WITHOUT having to move elements one step forward.
    //

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The client.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Initialise loop variable with list count.
    copy_integer((void*) &j, p1);
    // Subtract one, since this is an index.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (p1 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    fwprintf(stdout, L"Debug: Shutdown clients. The loop is running in reverse order! Loop count p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Shutdown clients. The loop is running in reverse order! Loop count p1: %i\n", *((int*) p1));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Get client from client list at the given index.
        copy_array_forward((void*) &c, *d, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p6);

        // Remove client from client list at the given index.
        modify_remove(p0, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p6, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // Close client.
        close_client(c);

        // Decrement loop variable.
        j--;
    }
}

/* CLIENTS_SHUTTER_SOURCE */
#endif
