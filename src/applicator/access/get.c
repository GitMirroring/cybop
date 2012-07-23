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

#ifndef GET_SOURCE
#define GET_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/access/get_access_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part_getter.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Gets an element (attribute) of the given part.
 *
 * Expected parametres:
 * - destination (required): the element retrieved from the part
 * - source (required): the knowledge path to the part
 * - element (required): the kind of element (name, channel, encoding, language, format, type, model, properties)
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_get(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply get.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part part.
    get_part_knowledge((void*) &p, p0, (void*) PART_GET_ACCESS_OPERATION_CYBOL_NAME, (void*) PART_GET_ACCESS_OPERATION_CYBOL_NAME_COUNT, p1, p2);
    // Get index part.
    get_part_knowledge((void*) &i, p0, (void*) INDEX_GET_ACCESS_OPERATION_CYBOL_NAME, (void*) INDEX_GET_ACCESS_OPERATION_CYBOL_NAME_COUNT, p1, p2);

    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get part element.
    get_part_element(dest_arr, src_part, type, count, dest_arr_idx, src_part_idx, src_part_element_idx);
*/
}

/* GET_SOURCE */
#endif
