/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGIFY_SOURCE
#define LOGIFY_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/logic/logic_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../executor/logifier/boolean_logifier.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Applies the boolean logic operation.
 *
 * Properties:
 * - output (required): the knowledge model in which the output is stored; used as first input operand
 * - input (required): the second input operand
 *
 * CAUTION! There are several ways to use addition, with unary or binary operators.
 * This function works like an UNARY operator.
 * The "output" parametre represents the first operand;
 * the "input" parametre the second.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the operation type
 */
void apply_logify(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply logify.");

    // The output part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The output part model item.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The output part model item data.
    void* omd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get output part.
    get_part_knowledge((void*) &o, p0, (void*) OUTPUT_LOGIC_LOGIC_CYBOL_NAME, (void*) OUTPUT_LOGIC_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get input part.
    get_part_knowledge((void*) &i, p0, (void*) INPUT_LOGIC_LOGIC_CYBOL_NAME, (void*) INPUT_LOGIC_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get output part model item.
    copy_array_forward((void*) &om, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get input part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get output part model item data.
    copy_array_forward((void*) &omd, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get input part model item data.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    fwprintf(stdout, L"pre i: %i\n", *((int*) imd));
    fwprintf(stdout, L"pre o: %i\n", *((int*) omd));

    // Calculate output by applying operation.
    logify_boolean(o, i, p3);

    fwprintf(stdout, L"post i: %i\n", *((int*) imd));
    fwprintf(stdout, L"post o: %i\n", *((int*) omd));
}

/* LOGIFY_SOURCE */
#endif
