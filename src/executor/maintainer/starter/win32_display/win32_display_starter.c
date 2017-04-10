/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_DISPLAY_STARTER_SOURCE
#define WIN32_DISPLAY_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/win32_display/register_win32_display_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the win32 display.
 *
 * @param p0 the internal memory data
 */
void startup_win32_display(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 display.");

    // The extended style.
    DWORD e = (DWORD) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL; // WS_EX_CLIENTEDGE;
    // The class.
    LPCTSTR c = (LPCTSTR) L"myWindowClass"; // const char g_szClassName[] = "myWindowClass";
    // The title.
    LPCTSTR t = (LPCTSTR) L"Learn to Program Windows";
    // The style.
    DWORD s = (DWORD) WS_OVERLAPPEDWINDOW;
    // The position (x, y) and size (width, height).
    int x = *NUMBER_200_INTEGER_STATE_CYBOI_MODEL; //?? CW_USEDEFAULT;
    int y = *NUMBER_200_INTEGER_STATE_CYBOI_MODEL; //?? CW_USEDEFAULT;
    int w = 400; //?? CW_USEDEFAULT;
    int h = 300; //?? CW_USEDEFAULT;
    // The parent window.
    HWND p = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The menu.
    HMENU m = (HMENU) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The module.
    //
    // Normally, the name of the loaded module
    // (either a .dll or .exe file) is handed over as parametre.
    // However, NULL is used here instead, in order to get a handle
    // to the file used to create the calling process (.exe file).
    // This helps AVOID having to use the "WinMain" function
    // to get the module handle.
    //
    // CAUTION! This handle is associated
    // with the window created below.
    //
    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms683199.aspx
    // http://stackoverflow.com/questions/11785157/replacing-winmain-with-main-function-in-win32-programs?rq=1
    HMODULE mo = GetModuleHandle((LPCTSTR) *NULL_POINTER_STATE_CYBOI_MODEL);
fwprintf(stdout, L"TEST mo: %i\n", mo);
    // The module instance to be associated with the window.
    HINSTANCE i = (HINSTANCE) mo;
fwprintf(stdout, L"TEST i: %i\n", i);
    // The additional application data.
    LPVOID a = (LPVOID) *NULL_POINTER_STATE_CYBOI_MODEL;

    // Register window class.
    startup_win32_display_register((void*) i, (void*) c);
fwprintf(stdout, L"TEST pre create: %i\n", i);
    // Create window.
    HWND wnd = CreateWindowEx(e, c, t, s, x, y, w, h, p, m, i, a);
fwprintf(stdout, L"TEST wnd: %i\n", wnd);

    // Set window.
    copy_array_forward(p0, (void*) &wnd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* WIN32_DISPLAY_STARTER_SOURCE */
#endif
