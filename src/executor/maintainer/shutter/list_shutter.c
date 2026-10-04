/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "server.h"

/**
 * Shuts down or closes all list entries.
 *
 * There are THREE categories of lists that may be handed over:
 * - standalone client entries
 * - client entries of a server
 * - server entries
 *
 * @param p0 the list item
 * @param p1 the identification name
 * @param p2 the channel
 * @param p3 the internal memory data
 * @param p4 the server flag
 */
void shutdown_list(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown list.");
    //?? fwprintf(stdout, L"Debug: Shutdown list. channel p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Shutdown list. channel *p2: %i\n", *((int*) p2));

    // The list item data, count.
    void* ld = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The client entry OR server entry.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client identification OR port (service identification).
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get list item data, count.
    copy_array_forward((void*) &ld, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Initialise loop variable with list count.
    copy_integer((void*) &j, lc);
    // Subtract one, since this is an index.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (lc == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the client list count is NULL, then the loop variable
        // is NOT initialised and still has the value ZERO.
        // In this case, the break flag will NEVER be set to true,
        // because the loop variable comparison below uses LESS than zero.
        //
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    //?? fwprintf(stdout, L"Debug: Shutdown list. loop count lc: %i\n", lc);
    //?? fwprintf(stdout, L"Debug: Shutdown list. loop count *lc: %i\n", *((int*) lc));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The loop is running in REVERSE ORDER,
        // from the last to the first element, since that way,
        // the function "remove" works much FASTER inside,
        // WITHOUT having to move all elements one step forward.
        //
        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        //?? fwprintf(stdout, L"Debug: Shutdown list. index j: %i\n", j);

        // Get entry from list data at the given index.
        copy_array_forward((void*) &e, ld, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);
        // Get identification from entry.
        copy_array_forward((void*) &id, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);

        //
        // Executes client close lifecycle OR service shutdown lifecycle, depending on the given identification name.
        //
        // CAUTION! Hand over entry as REFERENCE.
        //
        shutdown_flag(id, (void*) &e, p2, p0, (void*) &j, p3, p4);

        // Decrement loop variable.
        j--;
    }
}
