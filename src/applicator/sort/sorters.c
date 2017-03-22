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

#ifndef SORTERS_SOURCE
#define SORTERS_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/sort/sort_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/sorter/quicksorter.c"
#include "../../executor/sorter/bubblesorter.c"
#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../logger/logger.c"

/*
 * Sorts numbers using quicksort algorithm.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_quicksort(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply quicksort.");

    // The input part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The input part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part model item.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The input part model item data and count.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* imc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part model item data and count.
    void* omd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* omc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* oms = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input part.
    get_part_name((void*) &i, p0, (void*) INPUT_SORT_LOGIC_CYBOL_NAME, (void*) INPUT_SORT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get output part.
    get_part_name((void*) &o, p0, (void*) OUTPUT_SORT_LOGIC_CYBOL_NAME, (void*) OUTPUT_SORT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get file part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get output part model item.
    copy_array_forward((void*) &om, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get file part model item data and count.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imc, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get output part model item data and count.
    copy_array_forward((void*) &omd, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &omc, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &oms, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    sorter_quick(imd, imc, (void*) &omd, omc, oms);
}

/*
 * Sorts numbers using bubblesort algorithm.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_bubblesort(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply bubblesort.");

    // The input part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part.
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The input part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part model item.
    void* om = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The input part model item data and count.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* imc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The output part model item data, count, size.
    void* omd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* omc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* oms = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input part.
    get_part_name((void*) &i, p0, (void*) INPUT_SORT_LOGIC_CYBOL_NAME, (void*) INPUT_SORT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get output part.
    get_part_name((void*) &o, p0, (void*) OUTPUT_SORT_LOGIC_CYBOL_NAME, (void*) OUTPUT_SORT_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get file part model item.
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get output part model item.
    copy_array_forward((void*) &om, o, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get file part model item data and count.
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imc, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get output part model item data and count.
    copy_array_forward((void*) &omd, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &omc, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &oms, om, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SIZE_ITEM_STATE_CYBOI_NAME);

    sorter_bubble(imd, imc, (void*) &omd, omc, oms);
}

/* SORTERS_SOURCE */
#endif
