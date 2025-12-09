/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Retrieves language properties (constraints) necessary for deserialisation.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the language properties (constraints) data
 * @param p7 the language properties (constraints) count
 * @param p8 the knowledge memory part (pointer reference)
 * @param p9 the stack memory item
 * @param p10 the internal memory data
 * @param p11 the format
 * @param p12 the language
 */
void deserialise_cybol_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol constraints.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol constraints. format p11: %i\n", p11);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol constraints. format *p11: %i\n", *((int*) p11));

    //
    // Declaration
    //

    // The consider number base prefix flag part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thousands separator part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The consider number base prefix flag part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thousands separator part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The consider number base prefix flag part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The decimal separator part model item data, count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The thousands separator part model item data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // The root node flag.
    //
    // A root node usually just serves as CONTAINER for child nodes,
    // but does not contain any other semantic data itself.
    // Therefore, it gets treated DIFFERENTLY than standard nodes on parsing.
    //
    // This is achieved by using this flag, which is initially set to TRUE
    // in file "constraints_cybol_deserialiser.c" and gets reset to FALSE
    // in file "content_cybol_deserialiser.c", after having detected the root node.
    //
    int r = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The initial fileread flag.
    //
    // If a knowledge tree is stored in just ONE file (e.g. in json format) instead of
    // in many (e.g. in xml format), then it needs to be read from file just ONCE,
    // but NOT again for each of its child nodes.
    //
    // This is achieved by using this flag, which is initially set to TRUE
    // in file "constraints_cybol_deserialiser.c" and gets reset to FALSE
    // in file "step1_cybol_deserialiser.c", after having read the data from file.
    //
    int i = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get consider number base prefix flag part.
    get_part_name((void*) &p, p6, (void*) PREFIX_LANGUAGE_STATE_CYBOL_NAME, (void*) PREFIX_LANGUAGE_STATE_CYBOL_NAME_COUNT, p7, p8, p9, p10);
    // Get decimal separator part.
    get_part_name((void*) &d, p6, (void*) SEPARATOR_LANGUAGE_STATE_CYBOL_NAME, (void*) SEPARATOR_LANGUAGE_STATE_CYBOL_NAME_COUNT, p7, p8, p9, p10);
    // Get thousands separator part.
    get_part_name((void*) &t, p6, (void*) GROUPING_LANGUAGE_STATE_CYBOL_NAME, (void*) GROUPING_LANGUAGE_STATE_CYBOL_NAME_COUNT, p7, p8, p9, p10);

    // Get consider number base prefix flag part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get decimal separator part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get thousands separator part model item.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get consider number base prefix flag part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get decimal separator part model item data, count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get thousands separator part model item data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Deserialise cybol.
    deserialise_cybol(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p12, dmd, dmc, tmd, tmc, pmd, (void*) &r, (void*) &i, p11);
}
