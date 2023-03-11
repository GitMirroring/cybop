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

#ifndef WINDOWS_SYSTEM_ERROR_LOGGER_SOURCE
#define WINDOWS_SYSTEM_ERROR_LOGGER_SOURCE

//
// System interface
//

#include <windows.h>

#ifndef _MSC_VER
    #include <unistd.h>
#endif

//
// Library interface
//

#include "constant.h"

/**
 * Logs a windows system error.
 *
 * @param p0 the error code
 */
void log_windows_system_error(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* e = (DWORD*) p0;

        // The local handle.
        HLOCAL l = (HLOCAL) *NULL_POINTER_STATE_CYBOI_MODEL;

        // Convert error code into message.
        BOOL b = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, (LPCVOID) *NULL_POINTER_STATE_CYBOI_MODEL, *e, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), (PTSTR) &l, 0, (va_list*) *NULL_POINTER_STATE_CYBOI_MODEL);

        if (b == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // A network-related error.

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not log windows system error. The FormatMessage function failed.");
            fwprintf(stdout, L"Error: Could not log windows system error. The FormatMessage function failed. b: %i\n", b);

            // Load dynamic link library.
            HMODULE dll = LoadLibraryEx(TEXT("netmsg.dll"), (HANDLE) *NULL_POINTER_STATE_CYBOI_MODEL, DONT_RESOLVE_DLL_REFERENCES);

            if (((void*) dll) != *NULL_POINTER_STATE_CYBOI_MODEL) {

                FormatMessage(FORMAT_MESSAGE_FROM_HMODULE | FORMAT_MESSAGE_FROM_SYSTEM, dll, (DWORD) p0, MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT), (PTSTR) &l, 0, (va_list*) *NULL_POINTER_STATE_CYBOI_MODEL);
                FreeLibrary(dll);
            }
        }

        if (((void*) l) != *NULL_POINTER_STATE_CYBOI_MODEL) {

            MessageBox((HWND) *NULL_POINTER_STATE_CYBOI_MODEL, (LPCTSTR) LocalLock(l), TEXT("Windows Error in CYBOI"), MB_ICONERROR);
            LocalFree(l);
        }
    }
}

/* WINDOWS_SYSTEM_ERROR_LOGGER_SOURCE */
#endif
