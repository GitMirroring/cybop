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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "gui.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the gui element.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data
 * @param p3 the source model index
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the event name data
 * @param p8 the event name count
 * @param p9 the mouse x coordinate
 * @param p10 the mouse y coordinate
 * @param p11 the message format
 * @param p12 the window parent coordinates origo x
 * @param p13 the window parent coordinates origo y
 * @param p14 the loop break flag
 */
void deserialise_gui_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui element.");

    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

/*??
    fwprintf(stdout, L"Debug: Deserialise gui element. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise gui element. *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Deserialise gui element. p2: %i\n", p2);
*/

    // Get part from source whole at given index.
    copy_array_forward((void*) &p, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p3);

    //?? fwprintf(stdout, L"Debug: Deserialise gui element. p: %i\n", p);

    // Deserialise gui part.
    deserialise_gui_part(p0, p1, p, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
}
