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

#include <BaseTsd.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "cyboi_win_mapper.h"

int nanosleep(struct timespec* __requested_time, struct timespec* __remaining) {
    // Replacement for glibc version
    // based on:
    // http://www.c-plusplus.de/forum/43364-full
    // see: http://msdn.microsoft.com/en-us/library/windows/desktop/ms686289(v=vs.85).aspx
    // Description of desired behavior:

    /*nanosleep() suspends the execution of the calling thread until either
       at least the time specified in *req has elapsed, or the delivery of a
       signal that triggers the invocation of a handler in the calling
       thread or that terminates the process.

       If the call is interrupted by a signal handler, nanosleep() returns
       -1, sets errno to EINTR, and writes the remaining time into the
       structure pointed to by rem unless rem is NULL.  The value of *rem
       can then be used to call nanosleep() again and complete the specified
       pause (but see NOTES).

       The structure timespec is used to specify intervals of time with
       nanosecond precision.  It is defined as follows:

           struct timespec {
               time_t tv_sec;        // seconds
                long   tv_nsec;      // nanoseconds
            };

        The value of the nanoseconds field must be in the range 0 to
        999999999.
        */

    // see: http://man7.org/linux/man-pages/man2/nanosleep.2.html

    HANDLE hTimer = NULL;
    LARGE_INTEGER liDueTime;

    // Wartezeit in 100ns Schritten
    liDueTime.QuadPart = -(__requested_time->tv_sec * 10000000 + __requested_time->tv_nsec);
    //-100 000 000; = 10s
    // negativer Wert= relative Zeit, positiv=absoluter Zeit (siehe SetWaitableTimer)

    // Create a waitable timer.
    hTimer = CreateWaitableTimer(NULL, TRUE, "WaitableTimer");
    if (!hTimer) {
        printf("CreateWaitableTimer failed (%d)\n", GetLastError());
        return 1;
    }

    // printf("Waiting for %i seconds...\n", liDueTime.QuadPart / -10000000);
    // Set a timer to wait for 10 seconds.
    if (!SetWaitableTimer(hTimer, &liDueTime, 0, NULL, NULL, 0)) {
        printf("SetWaitableTimer failed (%d)\n", GetLastError());
        return 2;
    }

    // Wait for the timer.
    if (WaitForSingleObject(hTimer, INFINITE) != WAIT_OBJECT_0)
        printf("WaitForSingleObject failed (%d)\n", GetLastError());
    // else printf("Timer was signaled.\n");
    return 0;
}
