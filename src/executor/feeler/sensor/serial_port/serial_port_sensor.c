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

#ifndef SERIAL_PORT_SENSOR_SOURCE
#define SERIAL_PORT_SENSOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/streamer/reader/basic/basic_reader.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/streamer/reader/basic/basic_reader.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? #include "../../../../executor/sensor/win32_console/win32_console_sensor.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Senses serial port message.
 *
 * @param p0 the destination item
 * @param p1 the source file descriptor (client socket number)
 * @param p2 the input memory data
 * @param p3 the input memory size
 * @param p4 the destination item mutex
 * @param p5 the exit flag
 */
void sense_serial_port(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense serial port.");

    // Read data from terminal.
#if defined(__linux__) || defined(__unix__)
    read_basic(p0, p1, p2, p3, p4, p5, *NULL_POINTER_STATE_CYBOI_MODEL);
#elif defined(__APPLE__) && defined(__MACH__)
    read_basic(p0, p1, p2, p3, p4, p5, *NULL_POINTER_STATE_CYBOI_MODEL);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //?? sense_win32_console(p0, p1, p2, p3);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* SERIAL_PORT_SENSOR_SOURCE */
#endif
