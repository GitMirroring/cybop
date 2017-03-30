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

#ifndef CAST_SOURCE
#define CAST_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/cast/cast_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/caster/all/part_all_caster.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Casts a value from one type to another.
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - type (required): the source type
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 * @param p5 the operation type
 */
void apply_cast(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply cast.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The type part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The type part model item data.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_CAST_LOGIC_CYBOL_NAME, (void*) TYPE_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Cast value by applying operation.
    cast_all_part(d, s, tmd, p5);
}

/* CAST_SOURCE */
#endif
