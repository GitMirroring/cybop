/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GUI_DESERIALISER_SOURCE
#define GUI_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
#else
//??    #include "../../../../executor/representer/deserialiser/x_window_system/x_window_system_deserialiser.c"
#endif

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
 * @param p2 the source root window data
 * @param p3 the source root window count
 * @param p4 the event type data
 * @param p5 the event type count
 * @param p6 the button mask
 * @param p7 the x coordinate
 * @param p8 the y coordinate
 */
void deserialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui.");

    //?? TODO:

    // Hand over root window part to here.

    // Iterate through part hierarchy.

    // Get a gui part in loop cycle.
    // Remember the gui part's properties
    // (used further below to get the action).

    // The gui part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The gui part model, properties item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pp = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Compare if action for event exists.
    // If yes, assign event.

    // The action part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The action part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The action part model item data, count.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* amc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get action part.
//??    get_part_knowledge((void*) &a, ppd-param_prop_data, p3, p4, ppc-param_prop_count, knowledge_part);
    // Get action part model item.
    copy_array_forward(p0, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Assign event again (overwrite previous one),
    // if a contained child element has an action.

#ifdef WIN32
#else
//??    deserialise_gui_x_window_system(p0, p1, p2);
#endif
}

/* GUI_DESERIALISER_SOURCE */
#endif
