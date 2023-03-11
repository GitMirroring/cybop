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

#ifndef CURRENT_TIMER_SOURCE
#define CURRENT_TIMER_SOURCE

#include <time.h>

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
    #include <mach/clock.h>
    #include <mach/mach.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    // Empty.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Retrieves the current time from the system.
 *
 * @param p0 the destination time
 */
void time_current(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* t = (int*) p0;

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Time current.");

        //?? TODO: A standard "int" is too small to capture a time,
        //?? which is of type "long int".
        //?? Possibly switch all "int" types within cyboi into "long int"?

        // Get current time of system.
        // CAUTION! In the GNU C Library, time_t is equivalent to long int.
        //*t = time((time_t*) *NULL_POINTER_STATE_CYBOI_MODEL) / 1000;

#if defined(__linux__) || defined(__unix__)
        struct timespec start;

        clock_gettime(CLOCK_MONOTONIC_RAW, &start);

        //*t = (start.tv_sec) * 1000000;
        *t = (start.tv_nsec) / 1000;
        //*t = (start.tv_sec) * 1000000 + (start.tv_nsec) / 1000;
#elif defined(__APPLE__) && defined(__MACH__)
        clock_serv_t cclock;
        mach_timespec_t mts;

        host_get_clock_service(mach_host_self(), CALENDAR_CLOCK, &cclock);
        // OS X does not have clock_gettime, use clock_get_time
        clock_get_time(cclock, &mts);
        mach_port_deallocate(mach_task_self(), cclock);

        *t = (mts.tv_nsec) / 1000;
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        // Empty.
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not time current. The destination time is null.");
    }
}

/* CURRENT_TIMER_SOURCE */
#endif
