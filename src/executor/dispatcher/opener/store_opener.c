/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STORE_OPENER_SOURCE
#define STORE_OPENER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../executor/modifier/array_modifier.c"
#include "../../../logger/logger.c"

/**
 * Stores the client entry in the client list.
 *
 * @param p0 the destination client list item
 * @param p1 the client entry (pointer reference)
 * @param p2 the client identification (e.g. client socket)
 */
void open_store(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open store.");
    fwprintf(stdout, L"Debug: Open store. p0: %i\n", p0);

    // The destination data, size.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get destination client list item data, size.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    //
    // Why use function "modify_array" and NOT "modify_item" here?
    //
    // CAUTION! Do NOT use the function "modify_item" with "append",
    // since it is far more efficient to store and access entries by index
    // than having to loop through and compare client identifications.
    //
    // CAUTION! Do NOT use the function "modify_item" with "overwrite", since it:
    // - either adjusts the count, so that client entries following behind get lost
    // - or does not adjust the count but then cannot grow in size for new entries.
    //
    // CAUTION! The destination array count does not really matter,
    // since the client list is used like a random access file.
    //
    // CAUTION! It suffices to store the client entry here, since the
    // client socket as identification is stored within the client entry.
    //

/*??
    fwprintf(stdout, L"Debug: Open store. client socket p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Open store. client socket *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Open store. destination size s: %i\n", s);
    fwprintf(stdout, L"Debug: Open store. destination size *s: %i\n", *((int*) s));
*/

    //
    // Store client entry in client list of input/output entry.
    //
    // CAUTION! Hand over the CLIENT SOCKET c as DESTINATION INDEX.
    // The client socket numbers are unique, so that they may be
    // used as destination item array index, which is very efficient.
    //
    // CAUTION! Use s for both arguments, count AND size.
    //
    modify_array((void*) &d, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, s, s, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);
    //
    // Set data array as destination item element.
    //
    // CAUTION! This is necessary since the array may have been
    // reallocated above, so that the pointer now has a different address.
    //
    copy_array_forward(p0, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) DATA_ITEM_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* STORE_OPENER_SOURCE */
#endif
