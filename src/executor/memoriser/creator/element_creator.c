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

#ifndef ELEMENT_CREATOR_SOURCE
#define ELEMENT_CREATOR_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"

/**
 * Creates an element (part or property).
 *
 * @param p0 the whole part
 * @param p1 the knowledge memory part
 * @param p2 the name data
 * @param p3 the name count
 * @param p4 the type data
 * @param p5 the destination part element index
 */
void create_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Create element.");

    // The element (part or property).
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate element (part or property).
    allocate_part((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p4);

    // Fill element (part or property).
    overwrite_part_element(e, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p3, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) NAME_PART_STATE_CYBOI_NAME);
    overwrite_part_element(e, p4, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) TYPE_PART_STATE_CYBOI_NAME);

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A whole part exists.

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add element to whole model.");

        // Append element (handed over as array reference) to whole model (being a part itself).
        // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
        // The reason is that deep copying would be used to assign the element inside,
        // instead of just assigning the element reference in a shallow copying manner.
        append_part_element(p0, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);

    } else {

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Add element to knowledge memory root model.");

        // The whole part is null.
        //
        // CAUTION! The new element allocated above HAS TO BE added to the
        // knowledge memory tree, so that it can be deallocated properly at
        // system shutdown and is not lost somewhere in Random Access Memory (RAM).
        // Therefore, if the whole part is null, the knowledge memory is used instead.

        // Append element (handed over as array reference) to knowledge memory root model (being a part itself).
        // CAUTION! Do NOT use PART_ELEMENT_STATE_CYBOI_TYPE here!
        // The reason is that deep copying would be used to assign the element inside,
        // instead of just assigning the element reference in a shallow copying manner.
        append_part_element(p1, (void*) &e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);
    }
}

/* ELEMENT_CREATOR_SOURCE */
#endif
