/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_PROPERTIES_HANDLER_SOURCE
#define ELEMENT_PROPERTIES_HANDLER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/appender/item_appender.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Handles the properties element.
 *
 * It represents a local variable to be stored on stack memory.
 *
 * @param p0 the properties data
 * @param p1 the properties index
 * @param p2 the stack memory item
 */
void handle_properties_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle properties element.");

    // The source property part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The destination variable part.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source property part with given index.
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1);

    //?? Determine format + type of source property part.
    //?? Allocate destination variable part (using format determined above).
    //?? Assign clone to destination variable part.
    //?? See: copy_item(), copy_part() for cloning
    //?? See: file initialiser.c for how to use functions to assign values
    //?? Assign name, format, type, model, properties.

    //
    // Add destination variable part to stack memory.
    //
    // CAUTION! Use simple POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here.
    // The stack memory holds parts that were allocated as CLONE on purpose.
    // However, these parts will get deallocated MANUALLY, WITHOUT rubbish (garbage) collection.
    // Hence, rubbish (garbage) collection would only disturb here.
    //
    append_item_element(p2, (void*) &d, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ELEMENT_PROPERTIES_HANDLER_SOURCE */
#endif
