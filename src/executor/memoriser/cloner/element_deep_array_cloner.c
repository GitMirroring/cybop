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

#ifndef ELEMENT_DEEP_ARRAY_CLONER_SOURCE
#define ELEMENT_DEEP_ARRAY_CLONER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/memoriser/allocator/part_allocator.c"
#include "../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Clones the source array into the destination array.
 *
 * Handles a child node element representing a part.
 *
 * @param p0 the destination array
 * @param p1 the source array
 * @param p2 the source index
 */
void clone_array_deep_element(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Clone array deep element.");

    // The destination part.
    void* dp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part.
    void* sp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get source part with given index.
    copy_array_forward((void*) &sp, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Clone source- into destination part.
    // CAUTION! Hand over destination part as pointer reference.
    clone_part((void*) &dp, sp);

    // Add destination part to destination array.
    // CAUTION! The destination array got allocated already,
    // so that its size matches that of the source array.
    // CAUTION! The same index is used for source- and destination array.
    copy_array_forward(p0, (void*) &dp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* ELEMENT_DEEP_ARRAY_CLONER_SOURCE */
#endif
