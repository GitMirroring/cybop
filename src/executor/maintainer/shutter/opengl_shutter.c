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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPENGL_SHUTTER_SOURCE
#define OPENGL_SHUTTER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/getter.c"
#include "../../../executor/memoriser/allocator.c"

/**
 * Shuts down the opengl system.
 *
 * This is done in the reverse order that the opengl system was started up.
 *
 * @param p0 the internal memory array
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_opengl(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown opengl.");

#ifdef GNU_LINUX_OPERATING_SYSTEM

    // Shutdown x window system AT LAST.
    // The opengl environment needed its windows to have something to paint on.
    shutdown_x_window_system(p0, p1, p2);

/* GNU_LINUX_OPERATING_SYSTEM */
#endif
}

/* OPENGL_SHUTTER_SOURCE */
#endif
