/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef EMPTY_SOURCE
#define EMPTY_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/empty_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/emptier/part_emptier.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../logger/logger.c"

/**
 * Empties the part, i.e. removes all of its elements.
 *
 * Expected parametres:
 * - part (required): the part
 * - model (optional): the flag indicating whether all children of the MODEL are to be deleted; however, at least ONE of "model" or "properties" HAS TO BE specified
 * - properties (optional): the flag indicating whether all children of the PROPERTIES are to be deleted; however, at least ONE of "model" or "properties" HAS TO BE specified
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_empty(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply empty.");

    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part.
    void* mo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part.
    void* pr = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The part part type item.
    void* pt = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model part model item.
    void* mom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part model item.
    void* prm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The part type item data.
    void* ptd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The model model item data.
    void* momd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties model item data.
    void* prmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part part.
    get_part_name((void*) &p, p0, (void*) PART_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME, (void*) PART_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get model part.
    get_part_name((void*) &mo, p0, (void*) MODEL_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME, (void*) MODEL_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get properties part.
    get_part_name((void*) &pr, p0, (void*) PROPERTIES_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME, (void*) PROPERTIES_EMPTY_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get part type item.
    copy_array_forward((void*) &pt, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get model model item.
    copy_array_forward((void*) &mom, mo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get properties model item.
    copy_array_forward((void*) &prm, pr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part type item data.
    copy_array_forward((void*) &ptd, pt, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get part type item data.
    copy_array_forward((void*) &momd, mom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get part type item data.
    copy_array_forward((void*) &prmd, prm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Empty part, i.e. remove all of its elements.
    empty_part(p, ptd, momd, prmd);
}

/* EMPTY_SOURCE */
#endif
