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

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/client_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/server_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/calculator/integer/subtract_integer_calculator.c"
#include "../../../executor/comparator/integer/less_integer_comparator.c"
#include "../../../executor/configurator/finaliser/finaliser.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/dispatcher/closer/device_closer.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Shuts down all clients of this server.
 *
 * @param p0 the server entry
 * @param p1 the channel
 */
void shutdown_clients(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown clients.");
    fwprintf(stdout, L"Debug: Shutdown clients. p0: %i\n", p0);

    // The client list item.
    void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client list item data, count.
    void* cld = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* clc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The client entry.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client identification.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get client list item from server entry.
    copy_array_forward((void*) &cl, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ITEM_CLIENTS_SERVER_STATE_CYBOI_NAME);
    // Get client list item data, count.
    copy_array_forward((void*) &cld, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &clc, cl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Initialise loop variable with client list count.
    copy_integer((void*) &j, clc);
    // Subtract one, since this is an index.
    calculate_integer_subtract((void*) &j, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    if (clc == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

    fwprintf(stdout, L"Debug: Shutdown clients. The loop is running in reverse order! Loop count clc: %i\n", clc);
    fwprintf(stdout, L"Debug: Shutdown clients. The loop is running in reverse order! Loop count *clc: %i\n", *((int*) clc));

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! The loop is running in REVERSE ORDER,
        // from the last to the first element, since that way,
        // the function "remove" works much FASTER inside,
        // WITHOUT having to move elements one step forward.
        //
        compare_integer_less((void*) &b, (void*) &j, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Get client entry from client list data at the given index.
        copy_array_forward((void*) &ce, cld, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &j);
        // Remove client entry from client list item at the given index.
        modify_item(cl, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &j, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        // Get client identification from client entry.
        copy_array_forward((void*) &id, ce, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_GENERAL_CLIENT_STATE_CYBOI_NAME);

        //
        // CAUTION! The function "close_client" is NOT called on purpose.
        //
        // Instead, the following function calls are REDUNDANT and were
        // copied from file "closer.c", in order to increase efficiency
        // and to avoid searching the client entry,  since it is already
        // stored in a variable here.
        //

        // Finalise device.
        finalise(id, ce, p1);

        //
        // Close client device.
        //
        // CAUTION! Contrary to the opening, client socket stubs
        // do NOT need a special treatment here. Their file descriptor
        // gets closed in the same way as for the other channels.
        //
        close_device(id, ce, p1);

        // Decrement loop variable.
        j--;
    }
}

/* CLIENTS_SHUTTER_SOURCE */
#endif
