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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SECOND_SLEEPER_SOURCE
#define SECOND_SLEEPER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <unistd.h> // sleep
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"

/**
 * Suspends execution of the calling thread for (at least)
 * the given number of seconds.
 *
 * CAUTION! Do NOT rename this function to "sleep", since
 * that name is already used by low-level system functionality.
 *
 * CAUTION! The duration uses type "int", so that values
 * greater than its number range are not permitted.
 * Internally, cyboi works exclusively with type "int"
 * (no short, long long etc.).
 *
 * @param p0 the duration data (as seconds)
 */
void sleep_second(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // Also, this function runs in an endless loop and would produce huge log files.
        //
        // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sleep second.");

        // The duration value must not be negative.
        if (*d >= 0) {

            sleep(*d);

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // Also, this function runs in an endless loop and would produce huge log files.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The duration is negative.");
            fwprintf(stdout, L"Error: Could not sleep second. The duration is negative.\n");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // Also, this function runs in an endless loop and would produce huge log files.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The duration is null.");
        fwprintf(stdout, L"Error: Could not sleep second. The duration is null.\n");
    }
}

/* SECOND_SLEEPER_SOURCE */
#endif
