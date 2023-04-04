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

#ifndef CLOSE_WINDOW_GUI_ACTION_DESERIALISER_SOURCE
#define CLOSE_WINDOW_GUI_ACTION_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises a gui action close window event.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source format
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the event name data
 * @param p11 the event name count
 * @param p12 the mouse x coordinate
 * @param p13 the mouse y coordinate
 * @param p14 the message format
 * @param p15 the loop break flag
 */
void deserialise_gui_action_close_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui action close window.");

    // The action part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The action part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The action part model item data, count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* amc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

/*??
    fwprintf(stdout, L"Debug: Deserialise gui action close window. event name count p11: %i\n", p11);
    fwprintf(stdout, L"Debug: Deserialise gui action close window. event name count *p11: %i\n", *((int*) p11));
    fwprintf(stdout, L"Debug: Deserialise gui action close window. event name data p10: %i\n", p10);
    fwprintf(stdout, L"Debug: Deserialise gui action close window. event name data p10 as string: %ls\n", (wchar_t*) p10);
*/

    // Get action part.
    get_part_name((void*) &a, p4, p10, p11, p5, p7, p8, p9);

    // Get action part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get action part model item data, count.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &amc, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Set break flag, so that the loop can be left in the next cycle.
    // The gui element on which the event occured has been
    // detected, so that further elements on the SAME level
    // do not have to be checked in the loop anymore.
    //
    copy_integer(p15, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    compare_integer_equal((void*) &r, p14, (void*) PLAIN_TEXT_STATE_CYBOI_FORMAT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        if ((amd != *NULL_POINTER_STATE_CYBOI_MODEL) && (amc != *NULL_POINTER_STATE_CYBOI_MODEL)) {

            //
            // CAUTION! The action is NOT assigned if it is null,
            // which is checked inside the function called below.
            // However, in order to avoid unnecessary warnings and
            // to speed up processing, an additional null pointer check
            // is done here above.
            //

/*??
            fwprintf(stdout, L"Debug: Deserialise gui action close window. amc: %i\n", amc);
            fwprintf(stdout, L"Debug: Deserialise gui action close window. *amc: %i\n", *((int*) amc));
            fwprintf(stdout, L"Debug: Deserialise gui action close window. amd: %i\n", amd);
            fwprintf(stdout, L"Debug: Deserialise gui action close window. (wchar_t*) amd: %ls\n", (wchar_t*) amd);
*/

            //?? fwprintf(stdout, L"Debug: Deserialise gui action close window. Modify overwrite action.\n");

            //
            // Overwrite previous action of parent element
            // with that of the contained child element.
            //
            modify_item(p0, amd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, amc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise gui action close window. The action part model data is null.");
            fwprintf(stdout, L"Error: Could not deserialise gui action close window. The action part model data is null.\n");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise gui action close window. The message format is not text/plain.");
        fwprintf(stdout, L"Error: Could not deserialise gui action close window. The message format is not text/plain.\n");
    }
}

/* CLOSE_WINDOW_GUI_ACTION_DESERIALISER_SOURCE */
#endif
