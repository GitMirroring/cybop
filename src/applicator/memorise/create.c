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
// Library interface
//

#include "applicator.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Creates an empty part consisting of name and type only.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_create(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply create.");

    //
    // Declaration
    //

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The properties part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get name part.
    get_part_name((void*) &n, p0, (void*) NAME_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get format part.
    get_part_name((void*) &f, p0, (void*) FORMAT_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) FORMAT_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get whole part.
    get_part_name((void*) &w, p0, (void*) WHOLE_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get properties part.
    get_part_name((void*) &p, p0, (void*) PROPERTIES_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) PROPERTIES_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get properties part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get name part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get properties part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // The default values.
    int whole_part_item_index = *MODEL_PART_STATE_CYBOI_NAME;

    //
    // Set destination part item index depending on
    // the destination properties flag that was given as parametre.
    //
    // CAUTION! The function of directory "applicator/modify/"
    // is REUSED here, in order to avoid redundant source code.
    //
    apply_modify_index((void*) &whole_part_item_index, pmd);

    //
    // Functionality
    //

    apply_create_part(w, p2, nmd, nmc, fmd, (void*) &whole_part_item_index);
}
