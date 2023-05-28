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

#ifndef STRINGPART_SMTP_RESPONSE_DESERIALISER_SOURCE
#define STRINGPART_SMTP_RESPONSE_DESERIALISER_SOURCE

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
 * Deserialises the string part.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source string list data
 * @param p3 the source string list index
 */
void deserialise_smtp_response_stringpart(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise smtp response stringpart.");
    fwprintf(stdout, L"Debug: Deserialise smtp response stringpart. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise smtp response stringpart. *p3: %i\n", *((int*) p3));

    // The string part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The string part model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The string part model item data, count.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get string part at index from list.
    copy_array_forward((void*) &p, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);
    // Get string part model item.
    copy_array_forward((void*) &m, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get string part model item data, count.
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Select and deserialise string ...
    select ... TODO
    // Add textline as string to destination model item.
    // Deserialise reply code into integer NUMBER.
    // Add reply code as integer NUMBER to destination properties item.
    // Add reply textstring to destination properties item.
}

/* STRINGPART_SMTP_RESPONSE_DESERIALISER_SOURCE */
#endif
