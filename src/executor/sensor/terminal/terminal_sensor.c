/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TERMINAL_SENSOR_SOURCE
#define TERMINAL_SENSOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../executor/sensor/unix_terminal/unix_terminal_sensor.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../executor/sensor/unix_terminal/unix_terminal_sensor.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../executor/sensor/win32_console/win32_console_sensor.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Forward declarations.
//
// The following functions HAVE TO BE declared here since
// otherwise, the compiler will report errors like:
//
// error: 'sense_terminal' undeclared
//
// The reason is (probably) that the functions are forwarded
// as reference (function pointer), for example:
//
// &sense_unix_terminal
//
// The compiler does not seem to be able to recognise them
// as functions that way. Therefore, the following explicit
// declarations of the functions are necessary.
//

void sense_serial_port(void* p0);
int sense_unix_terminal(void* p0);

/**
 * Senses terminal messages.
 *
 * @param p0 the data available flag
 * @param p1 the interrupt request
 * @param p2 the mutex
 * @param p3 the input/output entry
 */
void sense_terminal(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense terminal.");

    //
    // Run sensing thread ONLY for unix terminal.
    //
    // CAUTION! A sensing thread for win32 console is NOT necessary,
    // since its input gets sensed in the main thread.
    // Therefore, the function "sense_unix_terminal" and NOT
    // "sense_terminal" is called here.
    //

#if defined(__linux__) || defined(__unix__)
    //
    // CAUTION! Do NOTHING here.
    //
    // Data input detection (sensing) gets activated in file
    // "channel_enabler.c" using the following function "spin".
    //
#elif defined(__APPLE__) && defined(__MACH__)
    //
    // CAUTION! Do NOTHING here.
    //
    // Data input detection (sensing) gets activated in file
    // "channel_enabler.c" using the following function "spin".
    //
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    sense_win32_console(p0, p1, p2, p3);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_SENSOR_SOURCE */
#endif
