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

#ifndef CREATE_SOURCE
#define CREATE_SOURCE

#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/operation/memory/create_memory_operation_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/memoriser/creator/creator.c"
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
 * - type (required): the type (type) of the part to be created
 * - element (required): the kind of element to be created (part, property);
 *   a part element will be added to the whole model's part hierarchy;
 *   a property element to the whole model's properties hierarchy
 * - whole (optional; if null, the new part will be added to the knowledge memory root):
 *   the compound to which to add to the new part
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 */
void apply_create(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply create.");

    // The name part.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model.
    void* nm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The name part model data, count.
    void* nmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The type part model data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get name part.
    get_name_array((void*) &n, p0, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) NAME_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get type part.
    get_name_array((void*) &t, p0, (void*) TYPE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) TYPE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get element part.
    get_name_array((void*) &e, p0, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) ELEMENT_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);
    // Get whole part.
    get_name_array((void*) &w, p0, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME, (void*) WHOLE_CREATE_MEMORY_OPERATION_CYBOL_NAME_COUNT, p1);

    // Get name part model.
    copy_array_forward((void*) &nm, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get type part model.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get element part model.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get name part model data, count.
    copy_array_forward((void*) &nmd, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &nmc, nm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get type part model data, count.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get element part model data, count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The destination type cybol form.
    // CAUTION! This is a cyboi integer representing a cybol mime type.
    int dtc = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The destination type cyboi form.
    // CAUTION! This is a cyboi integer representing a cyboi-internal type.
    int dt = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Decode cybol source type into cybol cyboi destination type.
    deserialise_cybol_type((void*) &dtc, tmd, tmc);
    // Decode cybol cyboi destination type into cyboi destination type.
    // CAUTION! A cybol type is of type "wchar_t"; a cyboi-internal type of type "int".
    // Both are not always equal in their meaning.
    // For example, an "xdt" file is converted into a cyboi "part".
    // Therefore, the type has to be converted here.
    deserialise_cybol_cyboi_type((void*) &dt, (void*) &dtc);

    create(w, p2, nmd, nmc, (void*) &dt, emd, emc);
}

/* CREATE_SOURCE */
#endif
