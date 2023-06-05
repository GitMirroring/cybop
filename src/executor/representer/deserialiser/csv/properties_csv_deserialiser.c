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
 * @version CYBOP 0.26.0 2023-04-04
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
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"
#include "text.h"

/**
 * Prepares variables necessary for deserialisation.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source textline list data
 * @param p3 the source textline list count
 * @param p4 the language properties (constraints) data
 * @param p5 the language properties (constraints) count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 */
void deserialise_csv_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise csv properties.");
    //?? fwprintf(stdout, L"Debug: Deserialise csv properties. source textline list count p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise csv properties. source textline list count *p3: %i\n", *((int*) p3));

    //
    // Declaration
    //

    // The delimiter part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The quotation part.
    void* q = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The header part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The delimiter part model item.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The quotation part model item.
    void* qm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The header part model item.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The delimiter part model item data, count.
    void* dmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The quotation part model item data, count.
    void* qmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* qmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The header part model item data.
    void* hmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get delimiter part.
    get_part_name((void*) &d, p4, (void*) DELIMITER_LANGUAGE_STATE_CYBOL_NAME, (void*) DELIMITER_LANGUAGE_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);
    // Get quotation part.
    get_part_name((void*) &q, p4, (void*) QUOTATION_LANGUAGE_STATE_CYBOL_NAME, (void*) QUOTATION_LANGUAGE_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);
    // Get header part.
    get_part_name((void*) &h, p4, (void*) HEADER_LANGUAGE_STATE_CYBOL_NAME, (void*) HEADER_LANGUAGE_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);

    // Get delimiter part model item.
    copy_array_forward((void*) &dm, d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get quotation part model item.
    copy_array_forward((void*) &qm, q, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get header part model item.
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get delimiter part model item data, count.
    copy_array_forward((void*) &dmd, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dmc, dm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get quotation part model item data, count.
    copy_array_forward((void*) &qmd, qm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &qmc, qm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get header part model item data.
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Prepare variables necessary for deserialisation.
    deserialise_csv_preparation(p0, p1, p2, p3, dmd, dmc, qmd, qmc, hmd);
}
