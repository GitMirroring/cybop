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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the binary data by adding a crlf termination.
 *
 * @param p0 the destination item
 * @param p1 the source message data
 * @param p2 the source message count
 */
void serialise_binary_crlf(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise binary crlf.");
    //?? fwprintf(stdout, L"Debug: Serialise binary crlf. p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Serialise binary crlf. *p2: %i\n", *((int*) p2));

    // Add binary data as they are.
    modify_item(p0, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p2, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Add crlf termination.
    modify_item(p0, (void*) CRLF_TERMINATION_BINARY_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) CRLF_TERMINATION_BINARY_NAME_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

/*??
    //?? TEST only -- delete later
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    copy_array_forward((void*) &d, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    fwprintf(stdout, L"Debug: Serialise binary crlf. post c: %i\n", c);
    fwprintf(stdout, L"Debug: Serialise binary crlf. post *c: %i\n", *((int*) c));
    fwprintf(stdout, L"Debug: Serialise binary crlf. post d: %s\n", (char*) d);
*/
}
