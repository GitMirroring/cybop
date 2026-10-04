/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "gui.h"
#include "logger.h"

/**
 * Searches an action in the root window handed over.
 *
 * Also searches through the window's child elements.
 * A previously set action found in the surrounding container element
 * gets overwritten by the action found in a child element.
 * That is, the child element's action has HIGHER PRIORITY.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source format
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 * @param p8 the event name data
 * @param p9 the event name count
 * @param p10 the mouse x coordinate
 * @param p11 the mouse y coordinate
 * @param p12 the message format
 * @param p13 the window parent coordinates origo x
 * @param p14 the window parent coordinates origo y
 */
void deserialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui.");

/*??
    fwprintf(stdout, L"Debug: Deserialise gui. source format p4: %i\n", p4);
    fwprintf(stdout, L"Debug: Deserialise gui. source format *p4: %i\n", *((int*) p4));
    fwprintf(stdout, L"Debug: Deserialise gui. source model count p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise gui. source model count *p3: %i\n", *((int*) p3));
    fwprintf(stdout, L"Debug: Deserialise gui. source model data p2: %i\n", p2);
*/

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // element
    //

    compare_integer_equal((void*) &r, p4, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The parent is a composed (whole) node.
        //

        // Process child nodes.
        deserialise_gui_whole(p0, p1, p2, p3, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14);
    }
}
