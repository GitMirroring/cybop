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

#ifndef CONTEXT_WIN32_DISPLAY_SERIALISER_SOURCE
#define CONTEXT_WIN32_DISPLAY_SERIALISER_SOURCE

#include <windows.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "logger.h"

/**
 * Serialises the win32 display context.
 *
 * @param p0 the win32 device context
 * @param p1 the source properties data
 * @param p2 the source properties count
 * @param p3 the knowledge memory part (pointer reference)
 */
void serialise_win32_display_context(void* p0, void* p1, void* p2, void* p3) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // The handle to the device context.
        //
        // CAUTION! The device context type is defined as:
        // typedef HANDLE HDC;
        // typedef PVOID HANDLE;
        // typedef void* PVOID;
        //
        // The HDC type is: void*
        // Therefore, cast parametre value AS IS
        // to handle (WITHOUT dereferencing).
        HDC h = (HDC) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise win32 display context.");

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise win32 display context. The device context is null.");
    }
}

/* CONTEXT_WIN32_DISPLAY_SERIALISER_SOURCE */
#endif
