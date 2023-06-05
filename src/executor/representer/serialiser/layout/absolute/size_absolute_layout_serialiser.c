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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Serialises absolute layout size.
 *
 * @param p0 the model data
 * @param p1 the model count
 * @param p2 the position x
 * @param p3 the position y
 * @param p4 the size width
 * @param p5 the size height
 * @param p6 the window flag
 * @param p7 the layout properties data
 * @param p8 the layout properties count
 * @param p9 the knowledge memory part (pointer reference)
 * @param p10 the stack memory item
 * @param p11 the internal memory data
 * @param p12 the layout data
 * @param p13 the layout count
 */
void serialise_layout_absolute_size(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout absolute size.");

    //
    // Serialise layout part and all of its children.
    //
    // CAUTION! Grand children are NOT considered.
    //
    // CAUTION! A layout-dependent formula has to be applied inside,
    // for calculating the position (x, y) of child elements.
    // The formula gets selected depending on the last parametre.
    //
    serialise_layout_part(p0, p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, p2, p3, p6, p9, p10, p11, p12, p13);
}
