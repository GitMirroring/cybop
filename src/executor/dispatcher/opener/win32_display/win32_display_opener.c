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

#ifndef WIN32_DISPLAY_OPENER_SOURCE
#define WIN32_DISPLAY_OPENER_SOURCE

#include <windows.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/registrar/opener/win32_display/register_win32_display_opener.c"
#include "../../../../logger/logger.c"

/**
 * Opens up a win32 display window.
 *
 * @param p0 the window identification
 * @param p1 the client entry
 */
void open_win32_display(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open win32 display.");
    fwprintf(stdout, L"Debug: Open win32 display. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Open win32 display. *p0: %i\n", *((int*) p0));

    // The extended style.
    DWORD e = (DWORD) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL; // WS_EX_CLIENTEDGE;
    // The class.
    LPCTSTR c = (LPCTSTR) L"myWindowClass"; // const char g_szClassName[] = "myWindowClass";
    // The title.
    LPCTSTR t = (LPCTSTR) L"Default Window Title";
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
    //
    // The module.
    //
    // Normally, the name of the loaded module
    // (either a .dll or .exe file) is handed over as parametre.
    // However, NULL is used here instead, in order to get a handle
    // to the file used to create the calling process (.exe file).
    // This helps AVOID having to use the "WinMain" function
    // to get the module handle.
    //
    // CAUTION! This handle is associated with the window created below.
    //
    // http://msdn.microsoft.com/en-us/library/windows/desktop/ms683199.aspx
    // http://stackoverflow.com/questions/11785157/replacing-winmain-with-main-function-in-win32-programs?rq=1
    //
    HMODULE mo = GetModuleHandle((LPCTSTR) *NULL_POINTER_STATE_CYBOI_MODEL);
    fwprintf(stdout, L"Debug: mo: %i\n", mo);
    // The module instance to be associated with the window.
    HINSTANCE i = (HINSTANCE) mo;
    fwprintf(stdout, L"Debug: i: %i\n", i);
    // The additional application data.
    LPVOID a = (LPVOID) *NULL_POINTER_STATE_CYBOI_MODEL;

    // Register window class.
    open_win32_display_register((void*) i, (void*) c);
    fwprintf(stdout, L"Debug: pre create: %i\n", i);
    // Create window.
    HWND wnd = CreateWindowEx(e, c, t, s, x, y, w, h, p, m, i, a);
    fwprintf(stdout, L"Debug: wnd: %i\n", wnd);
    // Convert window handle to integer.
    int wndi = (int) wnd;
    fwprintf(stdout, L"Debug: wndi: %i\n", wndi);

    // Set window.
    copy_integer(p0, (void*) &wndi);
}

/* WIN32_DISPLAY_OPENER_SOURCE */
#endif
