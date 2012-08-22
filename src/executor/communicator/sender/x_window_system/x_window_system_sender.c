/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SENDER_SOURCE
#define X_WINDOW_SYSTEM_SENDER_SOURCE

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <pthread.h>

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/graphical_user_interface_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../executor/communicator/sender/x_window_system/window_x_window_system_sender.c"
#include "../../../../logger/logger.c"

/**
 * Sends the source to the x window system.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the knowledge memory part
 * @param p5 the format
 * @param p6 the language
 * @param p7 the internal memory
 */
void send_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send x window system.");

    // Serialise (draw) source knowledge model into window.
    serialise(p7, p0, p1, p2, p3, p4, p5, *NULL_POINTER_STATE_CYBOI_MODEL, p6);

    // Send serialised window (with drawn content) to x window system.
    send_x_window_system_window(p7);
}

/* X_WINDOW_SYSTEM_SENDER_SOURCE */
#endif
