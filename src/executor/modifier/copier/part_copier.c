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

#ifndef PART_COPIER_SOURCE
#define PART_COPIER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/memory/part_memory_name.c"
#include "../../../constant/name/memory/primitive_memory_name.c"
#include "../../../logger/logger.c"

//
// Forward declarations.
//

void overwrite_part_all(void* p0, void* p1);

/**
 * Allocates a new destination part for the given source part.
 *
 * Copies the source part's name, type, model, properties
 * into the destination part.
 *
 * This is DEEP COPYING, i.e. all child nodes will be copied as well.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_part(void* p0, void* p1) {

    //
    // Recursively call an overwrite function, which in turn
    // may call this copying function and so forth.
    // This is necessary when processing knowledge tree hierarchies.
    //
    // CAUTION! The "overwrite_" as well as "insert_" functions
    // call basic copying functions.
    // If a part value is to be copied, then this function will be called.
    //
    // There is NO need to implement an "insert_part_all" function,
    // since copying just overwrites, but does not insert values.
    //

    overwrite_part_all(p0, p1);

/*??
    //??
    //?? The code below is an ALTERNATIVE to the "overwrite_part_all" function.
    //?? It may be deleted later, if not needed.
    //??

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy part.");

    // The source part name, type, model, properties.
    void* sn = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sa = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part elements data, count.
    void* snd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* snc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sac = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sdd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sdc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part name, type, model, properties.
    copy_array_forward((void*) &sn, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sa, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sd, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get source item data, count.
    copy_array_forward((void*) &snd, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &snc, sn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sad, sa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sac, sa, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sdd, sd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sdc, sd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Allocate destination part.
    // CAUTION! Use source part type for allocation!
    allocate_part(p0, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, sad);

    // Copy source part name, type, model, properties to destination.
    // The name is always of type "wide_character".
    overwrite_part_element(*d, snd, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, snc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);
    // The type is always of type "wide_character".
    overwrite_part_element(*d, sad, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, sac, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TYPE_PART_STATE_CYBOI_NAME);
    // The model is always of the type determined above.
    overwrite_part_element(*d, smd, sad, smc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // The properties is always of type "part" (whole, compound).
    overwrite_part_element(*d, sdd, (void*) PART_STATE_CYBOI_TYPE, sdc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
*/
}

/* PART_COPIER_SOURCE */
#endif
