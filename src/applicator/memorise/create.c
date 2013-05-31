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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/memory/create_memory_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/memoriser/creator/creator.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Creates an empty part consisting of name and type only.
 *
 * The model and properties may get filled with data using a
 * "deserialise" operation, which is called when a "receive"
 * logic operation is found in cybol.
 *
 * The new knowledge model gets added to either of:
 * - whole model's part hierarchy
 *   (or knowledge memory's root, if no whole is given)
 * - whole model's properties hierarchy
 *   (or knowledge memory's root, if no whole is given)
 *
 * Expected parametres:
 * - name (required): the name of the part to be created
 * - format (required): the format of the part to be created, from which gets determined the type
 * - element (required): the kind of element to be created (part, property);
 *       a part element will be added to the whole model's part hierarchy;
 *       a property element to the whole model's properties hierarchy
 * - whole (optional; if null, the new part will be added to the knowledge memory root):
 *       the compound to which to add to the new part
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_create(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply create.");

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model item.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model item data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The format part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model item data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get name part.
    get_part_knowledge((void*) &n, p0, (void*) NAME_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get format part.
    get_part_knowledge((void*) &f, p0, (void*) FORMAT_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) FORMAT_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get element part.
    get_part_knowledge((void*) &e, p0, (void*) ELEMENT_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get whole part.
    get_part_knowledge((void*) &w, p0, (void*) WHOLE_CREATE_MEMORY_LOGIC_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get name part model item.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get format part model item.
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get element part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get name part model item data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get format part model item data.
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get element part model item data, count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    create(w, p2, nmd, nmc, fmd, emd, emc);
}

/* CREATE_SOURCE */
#endif
