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

#ifndef BUILDING_MEMORISER_SOURCE
#define BUILDING_MEMORISER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/modification/count_modification_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/knowledge_getter/knowledge_part_getter.c"
#include "../../executor/modifier/counter/part_counter.c"
#include "../../logger/logger.c"

/**
 * Builds a list name.
 *
 * Expected parametres:
 * - ?? (required): ?? (description)
 *
 * @param p0 the parametres
 * @param p1 the parametres count
 * @param p2 the knowledge memory
 * @param p3 the knowledge memory count
 * @param p4 the knowledge memory size
 */
void memorise_building(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Build list name.");

    // The basisname name, type, model, properties.
    void** bnn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bna = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bndc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** bnds = NULL_POINTER_STATE_CYBOI_MODEL;
    // The index name, type, model, properties.
    void** idxn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxa = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxdc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** idxds = NULL_POINTER_STATE_CYBOI_MODEL;
    // The result name, type, model, properties.
    void** resn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resa = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resdc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** resds = NULL_POINTER_STATE_CYBOI_MODEL;

    // get the basisname
    get_universal_compound_element_by_name(
        (void*) &bnn, (void*) &bnnc, (void*) &bnns,
        (void*) &bna, (void*) &bnac, (void*) &bnas,
        (void*) &bnm, (void*) &bnmc, (void*) &bnms,
        (void*) &bnd, (void*) &bndc, (void*) &bnds,
        p0, p1,
        (void*) BASE_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) BASE_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // get the index
    get_universal_compound_element_by_name(
        (void*) &idxn, (void*) &idxnc, (void*) &idxns,
        (void*) &idxa, (void*) &idxac, (void*) &idxas,
        (void*) &idxm, (void*) &idxmc, (void*) &idxms,
        (void*) &idxd, (void*) &idxdc, (void*) &idxds,
        p0, p1,
        (void*) INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) INDEX_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    // get the result
    get_universal_compound_element_by_name(
        (void*) &resn, (void*) &resnc, (void*) &resns,
        (void*) &resa, (void*) &resac, (void*) &resas,
        (void*) &resm, (void*) &resmc, (void*) &resms,
        (void*) &resd, (void*) &resdc, (void*) &resds,
        p0, p1,
        (void*) COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME, (void*) COMPOSITION_BUILD_FLOW_OPERATION_CYBOL_NAME_COUNT,
        p2, p3);

    //check the type for the operation element
    int comp_res1 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int comp_res2 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int comp_res3 = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Create compare string.
    wchar_t* int_string = *NULL_POINTER_STATE_CYBOI_MODEL;
    // todo Konstante noch definieren
    int int_string_count = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int int_string_size = *NUMBER_10_INTEGER_STATE_CYBOI_MODEL;

    allocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    int_string_count = swprintf(int_string, int_string_size, L"%i", *((int*) *idxm));

    // destination size
    *(int*)*resms = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;
    *(int*)*resmc = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT + int_string_count;

    // Reallocate result array.
    reallocate_array(resm, *resms, *resms, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Set result array.
    overwrite_array(*resm, *bnm, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *bnmc, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    overwrite_array(*resm, (void*) LIST_SEPARATOR_CYBOL_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) LIST_SEPARATOR_CYBOL_NAME_COUNT, *bnmc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    int temp_index = *((int*) *bnmc) + *LIST_SEPARATOR_CYBOL_NAME_COUNT;

    overwrite_array(*resm, int_string, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, &int_string_count, &temp_index, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *resmc, *resms, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    // Destroy int_string array.
    deallocate_array((void*) &int_string, (void*) &int_string_size, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* BUILDING_MEMORISER_SOURCE */
#endif
