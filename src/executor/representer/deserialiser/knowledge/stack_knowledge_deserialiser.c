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

#ifndef STACK_KNOWLEDGE_DESERIALISER_SOURCE
#define STACK_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/accessor/name_getter/item_name_getter.c"
#include "../../../../executor/modifier/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

//?? void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Gets a knowledge part from stack memory.
 *
 * @param p0 the destination name or part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 */
void deserialise_knowledge_stack(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** d = (void**) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge stack.");

        // Get part with name from stack memory.
//??        get_name_item_element(p0, p5, *d, p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        //?? TEST -------------------------

        // The source part format, model item.
        void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source part format, model item data, count.
        void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The temporary source data position and source count remaining.
        void* pathd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int pathc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The temporary part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source part format, model item.
        // CAUTION! It is necessary to find out about the format and model.
        // The format may be "path/reference", "path/knowledge", or some other.
        // The model may contain a knowledge path or reference knowledge path.
        copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get source part format, model data, count.
        copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //
        // Get part as stack memory model.
        //
        // CAUTION! The format "path/stack" is processed as wchar_t inside.
        // The "properties" are uninteresting, since a stack variable name
        // cannot have constraints. That is, only the model is of interest.
        // It contains the name of the stack variable to be retrieved.
        //
        // Example of a model containing a stack variable name:
        // <node name="result" channel="inline" format="path/stack" model="break"/>
        //

        // Get temporary part from stack memory.
        get_name_item_element(p0, p5, smd, smc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

/*??
        // Get temporary part from stack memory.
        get_name_item_element((void*) &p, p5, smd, smc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // Copy source data position.
        copy_pointer((void*) &pathd, (void*) &smd);
        // Copy source count remaining.
        copy_integer((void*) &pathc, smc);

        // Get knowledge part from knowledge memory.
        // CAUTION! Hand over name as reference!
        // CAUTION! A COPY of path data and count is forwarded here,
        // so that the original values do NOT get changed.
        // This is IMPORTANT since otherwise, the original data position
        // gets increased and the count remaining decreased to zero,
        // so that knowledge access works only once, but not anymore afterwards.
        deserialise_knowledge(p0, (void*) &p, (void*) &pathd, (void*) &pathc, p4, p5, p6);
*/

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge stack. The knowledge path data position is null.");
    }
}

/* STACK_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
