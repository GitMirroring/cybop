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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_DISPLAY_SENSOR_SOURCE
#define WIN32_DISPLAY_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"

//
// The Win32 API:
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms632590(v=vs.85).aspx
//
// describes, among others, these functions:
// - GetMessage (blocking)
// - PeekMessage (non-blocking)
//
// Using "PeekMessage", one can choose between "PM_NOREMOVE" and
// "PM_REMOVE", to be handed over as last argument.
//
// Also, there are these functions:
// - GetQueueStatus
// - GetInputState
//
// Some reasons for why they might be useful are here:
// http://msdn.microsoft.com/en-us/library/windows/desktop/ms644928(v=vs.85).aspx#examining_queue
//

/**
 * Senses win32 display messages.
 *
 * @param p0 the internal memory data
 */
void sense_win32_display(void* p0) {

    // CAUTION! DO NOT log this function call!
    // This function is executed within a thread, but the
    // logging is not guaranteed to be thread-safe and might
    // cause unpredictable programme behaviour.
}

/* WIN32_DISPLAY_SENSOR_SOURCE */
#endif
