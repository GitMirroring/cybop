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

#ifndef X_WINDOW_SYSTEM_RECEIVER_SOURCE
#define X_WINDOW_SYSTEM_RECEIVER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/communicator/receiver/x_window_system/event_x_window_system_receiver.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives x window system input.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the format
 * @param p3 the language
 * @param p4 the internal memory data
 */
void receive_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive x window system.");

    // The button mask.
    int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The mouse coordinates.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Receive event.
    receive_x_window_system_event((void*) &b, (void*) &x, (void*) &y, p4);

    // Deserialise event into a meaningful command.
    deserialise(p0, p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &b, (void*) &x, (void*) &y, p2, p3);
}

/* X_WINDOW_SYSTEM_RECEIVER_SOURCE */
#endif
