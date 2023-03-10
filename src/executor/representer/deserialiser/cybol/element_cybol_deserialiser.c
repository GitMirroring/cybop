/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ELEMENT_CYBOL_DESERIALISER_SOURCE
#define ELEMENT_CYBOL_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/content_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol part element.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model index (NOT count)
 * @param p3 the language properties (constraints) data
 * @param p4 the language properties (constraints) count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the thousands separator data
 * @param p11 the thousands separator count
 * @param p12 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 */
void deserialise_cybol_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol element.");

    // The source part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model, properties.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part model, properties data, count.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ppd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ppc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part with given index.
    copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);
    // Get source part model, properties.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pp, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get source part model, properties data, count.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmc, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ppd, pp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ppc, pp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    deserialise_cybol_content(p0, pmd, pmc, ppd, ppc, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
}

/* ELEMENT_CYBOL_DESERIALISER_SOURCE */
#endif
