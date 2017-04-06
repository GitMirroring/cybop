/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_SENSOR_SOURCE
#define TERMINAL_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    // CAUTION! Calling a sensing function for unix terminal is NOT necessary,
    // since its input gets sensed in the corresponding sensing thread.
    // Therefore, the following include is disabled.
    // #include "../../../../executor/lifeguard/sensor/unix_terminal/unix_terminal_sensor.c"
#elif defined(__APPLE__) && defined(__MACH__)
    // CAUTION! Calling a sensing function for unix terminal is NOT necessary,
    // since its input gets sensed in the corresponding sensing thread.
    // Therefore, the following include is disabled.
    // #include "../../../../executor/lifeguard/sensor/unix_terminal/unix_terminal_sensor.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/lifeguard/sensor/win32_console/win32_console_sensor.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Senses terminal messages.
 *
 * @param p0 the interrupt request
 * @param p1 the break flag
 * @param p2 the internal memory data
 */
void sense_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense terminal.");

#if defined(__linux__) || defined(__unix__)
    // CAUTION! Calling a sensing function for unix terminal is NOT necessary,
    // since its input gets sensed in the corresponding sensing thread.
    // Therefore, the following function call is disabled.
    // sense_unix_terminal(p0, p1, p2);
#elif defined(__APPLE__) && defined(__MACH__)
    // CAUTION! Calling a sensing function for unix terminal is NOT necessary,
    // since its input gets sensed in the corresponding sensing thread.
    // Therefore, the following function call is disabled.
    // sense_unix_terminal(p0, p1, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    sense_win32_console(p0, p1, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_SENSOR_SOURCE */
#endif
