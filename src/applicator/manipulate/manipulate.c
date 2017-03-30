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

#ifndef MANIPULATE_SOURCE
#define MANIPULATE_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/manipulation/manipulation_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/manipulator/part_manipulator.c"
#include "../../logger/logger.c"

/**
 * Manipulates the bit at the given position by applying the given operation to the given value.
 *
 * Expected parametres:
 * - value (required): the knowledge model representing the value
 * - position (required): the bit position within the value
 * - type (required): the value type
 * - count (optional; if null, the value part model count will be used instead):
 *   the number of values to be manipulated
 * - index (optional; if null, an index of zero will be used instead):
 *   the index from which to start manipulating values
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
void apply_manipulate(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply manipulate.");

    // The value part.
    void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The value part model item.
    void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The value part model item count.
    void* vmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item data.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get value part.
    get_part_name((void*) &v, p0, (void*) VALUE_MANIPULATION_LOGIC_CYBOL_NAME, (void*) VALUE_MANIPULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get position part.
    get_part_name((void*) &p, p0, (void*) POSITION_MANIPULATION_LOGIC_CYBOL_NAME, (void*) POSITION_MANIPULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get type part.
    get_part_name((void*) &t, p0, (void*) TYPE_MANIPULATION_LOGIC_CYBOL_NAME, (void*) TYPE_MANIPULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_MANIPULATION_LOGIC_CYBOL_NAME, (void*) COUNT_MANIPULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get index part.
    get_part_name((void*) &i, p0, (void*) INDEX_MANIPULATION_LOGIC_CYBOL_NAME, (void*) INDEX_MANIPULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get value part model item.
    copy_array_forward((void*) &vm, v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get position part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get value part model item count.
    copy_array_forward((void*) &vmc, vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get position part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the value part model count by default.
    copy_integer((void*) &count, vmc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit index that was given as parametre.
    copy_integer((void*) &index, imd);

    // Manipulate value bitwise by applying operation.
    manipulate_part(v, pmd, p5, tmd, (void*) &count, (void*) &index);
}

/* MANIPULATE_SOURCE */
#endif
