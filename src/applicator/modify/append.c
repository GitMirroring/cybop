/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef APPEND_SOURCE
#define APPEND_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/append_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Appends the source- to the destination part.
 *
 * Expected parametres:
 * - destination (required): the destination part
 * - source (required): the source part
 * - type (required): the operand type which is equal for both operands
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be appended
 * - index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start copying elements from
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_append(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply append.");

    // The destination part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part model item count.
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model item data, count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data, count.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item data, count.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_knowledge((void*) &d, p0, (void*) DESTINATION_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) DESTINATION_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get source part.
    get_part_knowledge((void*) &s, p0, (void*) SOURCE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) SOURCE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get type part.
    get_part_knowledge((void*) &a, p0, (void*) TYPE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) TYPE_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get count part.
    get_part_knowledge((void*) &c, p0, (void*) COUNT_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) COUNT_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get index part.
    get_part_knowledge((void*) &i, p0, (void*) INDEX_APPEND_MODIFICATION_LOGIC_CYBOL_NAME, (void*) INDEX_APPEND_MODIFICATION_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get source part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get index part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source part model item count.
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model item data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data, count.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get index part model item data, count.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the source part model count by default.
    copy_integer((void*) &count, smc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit index that was given as parametre.
    copy_integer((void*) &index, imd);

    // Append the source- to the destination part.
    append_part(d, s, amd, (void*) &count, (void*) &index);
}

/* APPEND_SOURCE */
#endif
