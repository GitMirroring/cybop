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

#ifndef GUI_DESERIALISER_SOURCE
#define GUI_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/gui/part_gui_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Searches an action in the root window handed over.
 *
 * Also searches through the window's child elements.
 * An action found in a child element has higher priority
 * and overwrites a previously set action found in the
 * surrounding container element.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source gui element data
 * @param p3 the source gui element count
 * @param p4 the knowledge memory part
 * @param p5 the stack memory item
 * @param p6 the event type data
 * @param p7 the event type count
 * @param p8 the button mask
 * @param p9 the mouse x coordinate
 * @param p10 the mouse y coordinate
 * @param p11 the format data
 */
void deserialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p11, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_gui_part(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
        }
    }
}

/* GUI_DESERIALISER_SOURCE */
#endif
