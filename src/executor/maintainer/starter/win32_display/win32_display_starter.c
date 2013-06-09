/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WIN32_DISPLAY_STARTER_SOURCE
#define WIN32_DISPLAY_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Process all messages (events) sent to the window.
 *
 * Each windows message may have up to two parameters,
 * of type WPARAM and LPARAM. Originally, WPARAM was 16 bit
 * and LPARAM was 32 bit, but in Win32 they are both 32 bit.
 *
 * Not every message uses these parameters,
 * and each message uses them differently.
 * For example the WM_CLOSE message doesn't
 * use either, and one should ignore them both.
 *
 * The WM_COMMAND message uses both, WPARAM contains two values,
 * HIWORD(WPARAM) is the notification message (if applicable)
 * and LOWORD(WPARAM) is the control or menu id that sent the message.
 * LPARAM is the window handle of type HWND to the control which
 * sent the message or NULL if the messages isn't from a control.
 *
 * HIWORD() and LOWORD() are macros defined by windows that
 * single out the two high bytes (High Word) of a 32 bit
 * value (0xFFFF0000) and the low word (0x0000FFFF) respectively.
 * In Win32 a WORD is a 16bit value, making DWORD
 * (or Double Word) a 32bit value.
 *
 * To send a message, one can use PostMessage() or SendMessage().
 * - PostMessage() puts the message into the Message Queue and
 *   returns immediatly. That means once the call to PostMessage()
 *   is done the message may or may not have been processed yet.
 * - SendMessage() sends the message directly to the window and
 *   does not return until the window has finished processing it.
 *
 * Example:
 *
 * If one wanted to close a window, he could send it a WM_CLOSE
 * message like this PostMessage(hwnd, WM_CLOSE, 0, 0);
 * which would have the same effect as clicking on the
 * close button (cross) on the top of the window.
 * Notice that wParam and lParam are both 0.
 * This is because, as mentioned, they aren't used for WM_CLOSE.
 *
 * http://www.winprog.org/tutorial/message_loop.html
 *
 * @param w the window where the message occured
 * @param m the message
 * @param p the additional message parametres of type WPARAM
 * @param l the additional message parametres of type LPARAM
 */
LRESULT CALLBACK WndProc(HWND w, UINT m, WPARAM p, LPARAM l) {

    LRESULT r = (LRESULT) 0;

    if (m == WM_PAINT) {

        // Paint the window's client area.

        // This is the place where graphics device interface (gdi)
        // drawing primitives may be used.
        //
        // The following objects are part of the gdi:
        // - pen
        // - brush
        // - font
        // - palette
        // - region
        // - bitmap
        //
        // They get parameterised through the
        // corresponding "Create" function call.
        // They get bound to a device context and
        // activated through the "SelectObject" function.
        // At the end, "DeleteObject" should
        // be called to release the object.

        // The paint structure.
        PAINTSTRUCT ps;
        // The device context (dc).
        HDC dc = BeginPaint(w, &ps);

        // The background colour.
        COLORREF bg = RGB(255, 255, 0);
        // The foreground colour.
        COLORREF fg = RGB(255, 0, 0);

        //?? TODO: Compiling the following lines with mingw brings the following error:
        //
        // christian@uranus:/home/project/cybop$ i586-mingw32msvc-gcc src/controller/cyboi.c -o src/controller/cyboi.exe -DPTW32_STATIC_LIB -lpthreadGC2 -lxcb -lX11 -lXau -lws2_32 -w
        // /tmp/cccHo74K.o:cyboi.c:(.text+0x40b5f): undefined reference to `_CreateSolidBrush@4'
        // /tmp/cccHo74K.o:cyboi.c:(.text+0x40b77): undefined reference to `_CreatePen@12'
        // /tmp/cccHo74K.o:cyboi.c:(.text+0x40b93): undefined reference to `_Rectangle@20'
        // collect2: ld returned 1 exit status
        //
        // Some web forums report that there are problems
        // compiling with cygwin or mingw.
        //

//        HBRUSH br = CreateSolidBrush(bg);
//        HPEN pe = CreatePen(PS_SOLID, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, fg);
//        BOOL b = Rectangle(dc, 50, 50, 400, 300);

        EndPaint(w, &ps);

    } else if (m == WM_LBUTTONDOWN) {

        // The MAX_PATH macro defines the maximum length of
        // a buffer needed to store a filename under Win32.
        char szFileName[MAX_PATH];
        HINSTANCE hInstance = GetModuleHandle(NULL);

        GetModuleFileName(hInstance, szFileName, MAX_PATH);
        MessageBox(w, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);

    } else if (m == WM_RBUTTONDOWN) {

    } else if (m == WM_MBUTTONDOWN) {

    } else if (m == WM_SIZE) {

        // Set size and position of the window.

    } else if (m == WM_CLOSE) {

        DestroyWindow(w);

    } else if (m == WM_CREATE) {

        // Initialize the window.

    } else if (m == WM_DESTROY) {

        // Clean up window-specific data objects.
        PostQuitMessage(0);

    } else {

        // Continue with the default processing,
        // if none of the above messages matched.
        r = DefWindowProc(w, m, p, l);
    }

    return r;
}

/**
 * Registers the window class.
 *
 * A window class stores information about the type of window.
 *
 * @param p0 the module instance
 * @param p1 the window class
 */
void startup_win32_display_register(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        LPCTSTR c = (LPCTSTR) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            HINSTANCE i = (HINSTANCE) p0;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 display register.");

            WNDCLASSEX wc; // = {0};

            wc.cbSize = (UINT) sizeof(WNDCLASSEX);
            wc.style = (UINT) 0; // CS_HREDRAW | CS_VREDRAW;
            wc.lpfnWndProc = (WNDPROC) WndProc; // &WndProc;
            wc.cbClsExtra = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            wc.cbWndExtra = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL; //
            wc.hInstance = i;
            wc.hIcon = (HICON) LoadIcon((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDI_APPLICATION); // LoadIcon(hInstance, (LPCTSTR)IDI_RAHMEN);
            wc.hCursor = (HCURSOR) LoadCursor((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH) (COLOR_WINDOW + 1); // (HBRUSH)GetStockObject(WHITE_BRUSH);
            wc.lpszMenuName = (LPCTSTR) *NULL_POINTER_STATE_CYBOI_MODEL; // (LPCSTR) IDC_RAHMEN;
            wc.lpszClassName = c;
            wc.hIconSm = (HICON) LoadIcon((HINSTANCE) *NULL_POINTER_STATE_CYBOI_MODEL, IDI_APPLICATION); // wndclassex.hIcon; // LoadIcon(wcex.hInstance, (LPCTSTR) IDI_SMALL);

fwprintf(stdout, L"TEST reg c: %i\n", c);
fwprintf(stdout, L"TEST reg i: %i\n", i);

            ATOM e = RegisterClassEx(&wc);

fwprintf(stdout, L"TEST reg e: %i\n", e);

            if (e == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // Get the calling thread's last-error code.
                DWORD e = GetLastError();

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 display register. The window class registration failed.");
                log_windows_system_error((void*) &e);

                MessageBox(*NULL_POINTER_STATE_CYBOI_MODEL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 display register. The application instance is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 display register. The window class is null.");
    }
}

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
    // The opening style.
    int o = SW_MAXIMIZE;
//??    int o = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Register window class.
    startup_win32_display_register((void*) i, (void*) c);
fwprintf(stdout, L"TEST pre create: %i\n", i);
    // Create window.
    HWND wnd = CreateWindowEx(e, c, t, s, x, y, w, h, p, m, i, a);
fwprintf(stdout, L"TEST wnd: %i\n", wnd);

    // Display window.
    ShowWindow(wnd, o);

    UpdateWindow(wnd);

    MSG msg;

    //?? TODO: Delete when "while" loop gets deleted later!
    BOOL b = 0;

    //
    // Get message from application's message queue.
    // CAUTION! This function blocks, if there is no message.
    //
    // Possible alternative:
    // PeekMessage(&msg, (HWND) *NULL_POINTER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_NOREMOVE); // PM_REMOVE
    //
//??    BOOL b = GetMessage(&msg, (HWND) *NULL_POINTER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
    //?? TODO: Delete loop later!
    while ((b = GetMessage(&msg, (HWND) *NULL_POINTER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

    if (b > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST valid message: %i\n", b);

        // A valid message was retrieved.

        //
        // Translate virtual-key messages into character messages.
        // The character messages are posted to the calling thread's
        // message queue, to be read the next time the thread
        // calls the GetMessage or PeekMessage function.
        //
        // This step is actually optional, but certain
        // things won't work if it's not there.
        //
        // Example:
        //
        // Generating WM_CHAR messages to go
        // along with WM_KEYDOWN messages.
        //
        TranslateMessage(&msg);

        //
        // Send message out to the window
        // where the message (event) occured.
        // Call back the window's "WndProc" procedure.
        //
        // CAUTION! The window's "WndProc" procedure
        // is NOT magically called by the system.
        // It is called indirectly through the programme,
        // by calling "DispatchMessage".
        //
        // Alternatively, one could use "GetWindowLong" on
        // the window handle that the message is destined for
        // to look up the window's "WndProc" procedure and
        // call it directly, e.g.:
        //
        // WNDPROC fWndProc = (WNDPROC) GetWindowLong(Msg.hwnd, GWL_WNDPROC);
        // fWndProc(Msg.hwnd, Msg.message, Msg.wParam, Msg.lParam);
        //
        // http://www.winprog.org/tutorial/message_loop.html
        //
        // The author of the above-mentioned article
        // tried this with the previous example code,
        // and it does work.
        // However, there are various issues such as
        // Unicode/ASCII translation, calling timer callbacks
        // and so forth that this method will not account for,
        // and very likely will break all but trivial applications.
        // Therefore, it is NOT used here.
        //
        DispatchMessage(&msg);

    } else if (b == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST zero message: %i\n", b);

        // The WM_QUIT message was retrieved.

    } else {

fwprintf(stdout, L"TEST negative message: %i\n", b);

        // An error occured.

        // Get the calling thread's last-error code.
        DWORD e = GetLastError();

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 display. The message retrieval failed.");
        log_windows_system_error((void*) &e);
    }
    //?? TODO: Delete when "while" loop gets deleted later!
    }

    exit(0);
}

/*?? TODO:
    //
    // Retrieve the type of messages found in the
    // calling thread's message queue.
    //
    // GetQueueStatus should be considered only a hint as to
    // whether GetMessage or PeekMessage should be called.
    //
    // QS_ALLINPUT is identical to:
    // QS_INPUT | QS_POSTMESSAGE | QS_TIMER
    // | QS_PAINT | QS_HOTKEY | QS_SENDMESSAGE
    //
    // Possible alternative: GetInputState
    //
    DWORD d = GetQueueStatus(QS_ALLINPUT);
*/

/* WIN32_DISPLAY_STARTER_SOURCE */
#endif
