/*
* Copyright (C) 1999-2022. Christian Heller.
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
* @version CYBOP 0.24.0 2022-12-24
* @author Christian Heller <christian.heller@cybop.org>
*/

#ifndef CYBOI_WIN_MAPPER
#define CYBOI_WIN_MAPPER

#include <time.h>
#include <windows.h>
#include <stdio.h> 
#include <BaseTsd.h>
#include <pthread.h>

// Not used, in pthread.h declared
// For the rescue: copied from glibc time.h
/* POSIX.1b structure for a time value.  This is like a `struct timeval' but
has nanoseconds instead of microseconds.  */
//struct timespec
//{
//    time_t tv_sec;        /* Seconds.  */
//    long int tv_nsec;        /* Nanoseconds.  */
//};

typedef int pid_t; /* Type of process identifications.  */

typedef SSIZE_T ssize_t;

int nanosleep(struct timespec *__requested_time, struct timespec *__remaining);

/* CYBOI_WIN_MAPPER */
#endif