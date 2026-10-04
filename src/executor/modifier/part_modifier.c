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
 * Modifies the destination part using the source array.
 *
 * Only that item of the destination part gets modified
 * whose index is given by the destination part item index parametre.
 *
 * The destination part item index may be one of:
 * - NAME_PART_STATE_CYBOI_NAME
 * - FORMAT_PART_STATE_CYBOI_NAME
 * - TYPE_PART_STATE_CYBOI_NAME
 * - MODEL_PART_STATE_CYBOI_NAME
 * - PROPERTIES_PART_STATE_CYBOI_NAME
 *
 * @param p0 the destination part
 * @param p1 the source array (should be null for remove)
 * @param p2 the type
 * @param p3 the deep copying flag
 * @param p4 the count
 * @param p5 the destination index (should be null for append)
 * @param p6 the source index (should be null for remove)
 * @param p7 the adjust count flag (should be null for append and insert)
 * @param p8 the repetition number for "modify/repeat"
 * @param p9 the searchterm data for "modify/replace"
 * @param p10 the searchterm count for "modify/replace"
 * @param p11 the operation type
 * @param p12 the destination part item index
 */
void modify_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify part.");
    //?? fwprintf(stdout, L"Debug: Modify part. p3: %i\n", p3);

    // The destination part item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part item.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p12);

    // Modify item as element of the part container.
    modify_item(i, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11);
}
