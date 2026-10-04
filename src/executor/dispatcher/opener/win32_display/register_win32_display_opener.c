/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf
#include <windows.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"
#include "variable.h"

//?? #include "../../../../executor/representer/deserialiser/win32_display/callback_message_win32_display_deserialiser.c"

/**
 * Registers the window class.
 *
 * A window class stores information about the type of window.
 *
 * @param p0 the module instance
 * @param p1 the window class
 */
void open_win32_display_register(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        LPCTSTR c = (LPCTSTR) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            HINSTANCE i = (HINSTANCE) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open win32 display register.");

            WNDCLASSEX wc; // = {0};

            wc.cbSize = (UINT) *WNDCLASSEX_DISPLAY_TYPE_SIZE;
            wc.style = (UINT) 0; // CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc = (WNDPROC) deserialise_win32_display_message_callback;
            wc.cbClsExtra = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            wc.cbWndExtra = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL; //
            wc.hInstance = i;
            wc.hIcon = (HICON) LoadIcon((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDI_APPLICATION); // LoadIcon(hInstance, (LPCTSTR)IDI_RAHMEN);
            wc.hCursor = (HCURSOR) LoadCursor((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); // (HBRUSH)GetStockObject(WHITE_BRUSH);
            wc.lpszMenuName = (LPCTSTR) *NULL_POINTER_STATE_CYBOI_MODEL; // (LPCSTR) IDC_RAHMEN;
            wc.lpszClassName = c;
            wc.hIconSm = (HICON) LoadIcon((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDI_APPLICATION); // wndclassex.hIcon; // LoadIcon(wcex.hInstance, (LPCTSTR) IDI_SMALL);

            fwprintf(stdout, L"Debug: reg c: %i\n", c);
            fwprintf(stdout, L"Debug: reg i: %i\n", i);

            ATOM e = RegisterClassEx(&wc);

            fwprintf(stdout, L"Debug: reg e: %i\n", e);

            if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open win32 display register. The window class registration failed.");
                log_error((void*) &e);

                MessageBox(*NULL_POINTER_STATE_CYBOI_MODEL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open win32 display register. The application instance is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open win32 display register. The window class is null.");
    }
}
