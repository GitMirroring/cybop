/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MODEL_POP_HANDLER_SOURCE
#define MODEL_POP_HANDLER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../executor/memoriser/deallocator/part_deallocator.c"
#include "../../../logger/logger.c"

/**
 * Deallocates the part.
 *
 * @param p0 the part (pointer reference)
 */
void handle_pop_model(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle pop model.");

    // Deallocate part.
    deallocate_part(p0);

    // The comparison result.
    //?? int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check for reference format.
    //?? compare_integer_equal((void*) &r, p2, (void*) REFERENCE_ELEMENT_STATE_CYBOI_FORMAT);

    //?? if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The source part is NOT a pointer reference.
        //

    //?? } else {

        //
        // The source part IS a pointer reference.
        //
    //?? }
}

/* MODEL_POP_HANDLER_SOURCE */
#endif
