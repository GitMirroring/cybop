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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BUILD_SOURCE
#define BUILD_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/modification/build_modification_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
//?? #include "../../executor/modifier/builder/part_builder.c"
#include "../../logger/logger.c"

/**
 * Builds a part name to be used in a list of many parts.
 * Uses a base name and adds an index to retrieve a unique resulting composed name.
 *
 * Expected parametres:
 * - result (required): the knowledge part where to store the resulting composed name
 * - base (required): the base name
 * - index (required): the index to add to the base name
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_build(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply build.");

    // The result part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The base part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The result part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The base part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The index part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? ... TODO: continue here!

/*??

    VERY OLD CODE TO BE DELETED!

    //check the type for the operation element
    int comp_res1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int comp_res2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int comp_res3 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Create compare string.
    wchar_t* int_string = *NULL_POINTER_STATE_CYBOI_MODEL;
    // todo Konstante noch definieren
    int int_string_count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int int_string_size = *NUMBER_10_INTEGER_STATE_CYBOI_MODEL;

    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    int_string_count = swprintf(int_string, int_string_size, L"%i", *((int*) *idxm));

    // destination size
    *(int*)*resms = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;
    *(int*)*resmc = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;

    // Reallocate result array.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    reallocate_array(resm, *resms, *resms, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Set result array.
    overwrite_array(*resm, *bnm, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *bnmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    overwrite_array(*resm, (void*) LIST_SEPARATOR_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_SEPARATOR_CYBOL_NAME_COUNT, *bnmc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    int temp_index = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

    overwrite_array(*resm, int_string, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, &int_string_count, &temp_index, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Destroy int_string array.
    deallocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
*/
}

/* BUILD_SOURCE */
#endif
