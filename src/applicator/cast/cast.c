/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CAST_SOURCE
#define CAST_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/cast/cast_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/accessor/name_getter/array_name_getter.c"
#include "../../executor/caster/part_caster.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Casts a value from one type to another.
 *
 * Expected parametres:
 * - destination (required): the knowledge model to cast to
 * - source (required): the knowledge model to cast from
 * - count (optional; if null, the source part model count will be used instead):
 *   the number of elements to be casted
 * - destination_index (optional; if null, an index of zero will be used instead):
 *   the destination index from which to start casting
 * - source_index (optional; if null, an index of zero will be used instead):
 *   the source index from which to start casting
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
    // The count part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The result index part.
    void* ri = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand index part.
    void* oi = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part type item.
    void* st = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The result index part model item.
    void* rim = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand index part model item.
    void* oim = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The source part type item data.
    void* std = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The count part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The result index part model item data.
    void* rimd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The operand index part model item data.
    void* oimd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part.
    get_part_name((void*) &d, p0, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME, (void*) DESTINATION_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get source part.
    get_part_name((void*) &s, p0, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME, (void*) SOURCE_CAST_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get count part.
    get_part_name((void*) &c, p0, (void*) COUNT_CALCULATION_LOGIC_CYBOL_NAME, (void*) COUNT_CALCULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get result index part.
    get_part_name((void*) &ri, p0, (void*) RESULT_INDEX_CALCULATION_LOGIC_CYBOL_NAME, (void*) RESULT_INDEX_CALCULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get operand index part.
    get_part_name((void*) &oi, p0, (void*) OPERAND_INDEX_CALCULATION_LOGIC_CYBOL_NAME, (void*) OPERAND_INDEX_CALCULATION_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get source part type item.
    copy_array_forward((void*) &st, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // Get count part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get result index part model item.
    copy_array_forward((void*) &rim, ri, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get operand index part model item.
    copy_array_forward((void*) &oim, oi, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get source part type item data.
    copy_array_forward((void*) &std, st, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get count part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get result index part model item data.
    copy_array_forward((void*) &rimd, rim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get operand index part model item data.
    copy_array_forward((void*) &oimd, oim, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The default values.
    int type = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    int count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int result_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int operand_index = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.

    // Use the result part type data by default.
    copy_integer((void*) &type, rtd);
    // Use the operand part model count by default.
    copy_integer((void*) &count, omc);
    // Use the explicit count that was given as parametre.
    copy_integer((void*) &count, cmd);
    // Use the explicit result index that was given as parametre.
    copy_integer((void*) &result_index, rimd);
    // Use the explicit operand index that was given as parametre.
    copy_integer((void*) &operand_index, oimd);

    // Cast value by applying operation.
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the source type
 * @param p3 the operation (destination) type
 * @param p4 the count
 * @param p5 the destination index
 * @param p6 the source index
//??    apply_calculate_type(r, o, p5, (void*) &type, (void*) &count, (void*) &result_index, (void*) &operand_index, otd);
    cast_part(d, s, std, p5);
}

/* CAST_SOURCE */
#endif
