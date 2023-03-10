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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_INDICATOR_SOURCE
#define PART_INDICATOR_SOURCE

#include "../../../executor/accessor/indicator/item_indicator.c"
#include "../../../logger/logger.c"

/**
 * Indicates the fill level of the part.
 *
 * The kind of comparison depends upon the given operation type.
 *
 * @param p0 the result flag (1 upon successful comparison; left untouched otherwise)
 * @param p1 the part
 * @param p2 the operation type
 */
void indicate_part(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Indicate part.");

    // The part model item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part model item.
    copy_array_forward((void*) &m, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Indicate part model item.
    indicate_item(p0, m, p2);
}

/* PART_INDICATOR_SOURCE */
#endif
