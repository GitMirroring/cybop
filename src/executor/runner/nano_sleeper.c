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

#ifndef NANO_SLEEPER_SOURCE
#define NANO_SLEEPER_SOURCE

#include <errno.h>
#include <time.h>

#ifdef _MSC_VER
    #include "../../windows/cyboi_win_mapper.h"
#else
    #include <unistd.h>
    #ifdef WIN32
        #include <pthread_time.h>
    #endif
#endif

/**
 * Suspends execution of the calling thread for (at least)
 * the given number of nanoseconds.
 *
 * CAUTION! Do NOT rename this function to "sleep", since
 * that name is already used by low-level system functionality.
 *
 * CAUTION! The duration uses type "int", so that values
 * greater than its number range are not permitted.
 * Internally, cyboi works exclusively with type "int"
 * (no short, long long etc.).
 *
 * @param p0 the duration data (as nanoseconds)
 */
void sleep_nano(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* d = (int*) p0;

        //
        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        //
        // Also, this function runs in an endless loop and would produce huge log files.
        //
        // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sleep nano.");
        //

        // The duration value must be in the range 0 to 999,999,999 nanoseconds.
        if (*d >= 0) {

            if (*d < 1000000000) {

                // The temporary struct timespec variable.
                struct timespec t;

                // Assign seconds.
                t.tv_sec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // Assign duration in nanoseconds.
                t.tv_nsec = *d;

                //
                // Initialise error number.
                //
                // It is a global variable/ function and other operations
                // may have set some value that is not wanted here.
                //
                // CAUTION! Initialise the error number BEFORE calling
                // the function that might cause an error.
                //
                copy_integer((void*) &errno, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                //
                // Suspend execution of this thread.
                //
                // CAUTION! The POSIX.1-2001 standard declares
                // the "usleep" function obsolete and defines
                // the "nanosleep" function instead.
                // POSIX.1-2008 removes the specification of "usleep".
                //
                // If the second parametre is null, then the
                // remaining time is just NOT remembered,
                // which is not needed here anyway.
                //
                int e = nanosleep(&t, *NULL_POINTER_STATE_CYBOI_MODEL);

                //
                // Test error value.
                //
                // The return value of the "nanosleep" function is zero
                // if no error occurred; otherwise, it is minus one.
                //
                if (e < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                    if (errno == EFAULT) {

                        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. There is a problem with copying information from user space.");
                        fwprintf(stdout, L"Error: Could not sleep. There is a problem with copying information from user space. errno: %i\n", errno);

                    } else if (errno == EINTR) {

                        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The pause has been interrupted by a signal that was delivered to the thread. The remaining sleep time has been written into *rem so that the thread can easily call nanosleep() again and continue with the pause.");
                        fwprintf(stdout, L"Error: Could not sleep. The pause has been interrupted by a signal that was delivered to the thread. The remaining sleep time has been written into *rem so that the thread can easily call nanosleep() again and continue with the pause. errno: %i\n", errno);

                    } else if (errno == EINVAL) {

                        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The value in the tv_nsec field was not in the range 0 to 999999999 or tv_sec was negative.");
                        fwprintf(stdout, L"Error: Could not sleep. The value in the tv_nsec field was not in the range 0 to 999999999 or tv_sec was negative. errno: %i\n", errno);

                    } else {

                        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. An unknown error occured.");
                        fwprintf(stdout, L"Error: Could not sleep. An unknown error occured. errno: %i\n", errno);
                    }
                }

            } else {

                //
                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                //
                // Also, this function runs in an endless loop and would produce huge log files.
                //
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The duration is negative.");
                //
                fwprintf(stdout, L"Error: Could not sleep nano. The duration is greater than the limit of 1,000,000,000.\n");
            }

        } else {

            //
            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            //
            // Also, this function runs in an endless loop and would produce huge log files.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The duration is negative.");
            //
            fwprintf(stdout, L"Error: Could not sleep nano. The duration is negative.\n");
        }

    } else {

        //
        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        //
        // Also, this function runs in an endless loop and would produce huge log files.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sleep. The duration is null.");
        //
        fwprintf(stdout, L"Error: Could not sleep nano. The duration is null.\n");
    }
}

/* NANO_SLEEPER_SOURCE */
#endif
