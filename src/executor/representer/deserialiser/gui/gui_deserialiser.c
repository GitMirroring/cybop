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
 * Deserialises the gui input data into a command.
 *
 * @param p0 the destination item
 * @param p1 the button mask
 * @param p2 the x coordinate
 * @param p3 the y coordinate
 */
void deserialise_gui(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui.");

    //?? TODO: Hand over root window part to here.
    //?? Iterate through part hierarchy
    // Compare if command for event exists.
    // If yes, assign event.
    // Assign event again (overwrite previous one),
    // if a contained child element has a command.

#ifdef WIN32
#else
//??    deserialise_gui_x_window_system(p0, p1, p2);
#endif
}

/* GUI_DESERIALISER_SOURCE */
#endif
