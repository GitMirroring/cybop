/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DEVICE_WRITER_SOURCE
#define DEVICE_WRITER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../executor/streamer/writer/unix_device/unix_device_writer.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../executor/streamer/writer/unix_device/unix_device_writer.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../executor/streamer/writer/win32_device/win32_device_writer.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Sends a command to the device given by the file descriptor.
 *
 * @param p0 the destination device file descriptor
 * @param p1 the source command (device-dependent request code)
 * @param p2 the argument (either a single number or a pointer to a structure, depending upon the command used)
 */
void write_device(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write device.");
    fwprintf(stdout, L"Debug: Write device. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Write device. *p0: %i\n", *((int*) p0));

#if defined(__linux__) || defined(__unix__)
    write_unix_device(p0, p1, p2);
#elif defined(__APPLE__) && defined(__MACH__)
    write_unix_device(p0, p1, p2);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    write_win32_device(p0, p1, p2);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* DEVICE_WRITER_SOURCE */
#endif
