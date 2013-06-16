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

#ifndef MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE
#define MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE

#include <windowsx.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Receives a win32 display message.
 *
 * @param p0 the internal memory data
 * @param p1 the event type data (pointer reference)
 * @param p2 the event type count (pointer reference)
 * @param p3 the mouse button or key code
 * @param p4 the window identification
 * @param p5 the mouse position x coordinate
 * @param p6 the mouse position y coordinate
 * @param p7 the button- or key mask
 * @param p8 the mouse button identification
 * @param p9 the expose area x coordinate
 * @param p10 the expose area y coordinate
 * @param p11 the expose area width
 * @param p12 the expose area height
 * @param p13 the loop break flag
 */
void receive_win32_display_message(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 display message.");

fwprintf(stdout, L"TEST receive win32: %i\n", p13);

    // The message structure.
    MSG msg;

    // The window.
    //
    // CAUTION! It is initialised with null,
    // so that not only the main window's messages,
    // but all messages of the thread are received.
    //
    // This is important if using a dialogue window
    // besides the main window, for example.
    // CYBOI will then have to find out internally,
    // to which window a message belongs.
    // It thus has to keep a list of existing windows
    // in a container structure stored in internal memory.
    HWND wnd = (HWND) *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Get message from application's message queue.
    //
    // Using "PeekMessage", one can choose between "PM_NOREMOVE" and
    // "PM_REMOVE", to be handed over as last argument.
    //
    // CAUTION! DO remove the message from the queue with flag PM_REMOVE here!
    // It was detected in the sensing thread and may be removed and processed now.
    //
    // IF a message is available, the return value is NONZERO (TRUE).
    // If NO messages are available, the return value is ZERO (FALSE).
    // The loop sleeps if no messages are available.
    //
    BOOL a = PeekMessage(&msg, wnd, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (UINT) *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, PM_REMOVE);

    if (a > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST valid message: %i\n", a);

        // A valid message was retrieved.

        // CAUTION! Process messages here and NOT
        // in a callback function, as suggested by win32.
        // The reason is that the callback function
        // has only four fixed parametres, but many
        // more have to be set here.

        // The window where the message occured.
        HWND w = msg.hwnd;
        // The message.
        UINT m = msg.message;
        // The additional message parametres of type WPARAM.
        WPARAM wp = msg.wParam;
        // The additional message parametres of type LPARAM.
        LPARAM lp = msg.lParam;

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

            HBRUSH br = CreateSolidBrush(bg);
            HPEN pe = CreatePen(PS_SOLID, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, fg);
            BOOL b = Rectangle(dc, 50, 50, 200, 100);

            EndPaint(w, &ps);

        } else if (m == WM_LBUTTONDOWN) {

            // The MAX_PATH macro defines the maximum length of
            // a buffer needed to store a filename under Win32.
            char szFileName[MAX_PATH];
            HINSTANCE hInstance = GetModuleHandle(NULL);

            GetModuleFileName(hInstance, szFileName, MAX_PATH);
            MessageBox(w, szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);

        } else if (m == WM_RBUTTONDOWN) {

            int x = GET_X_LPARAM(lp);
            int y = GET_Y_LPARAM(lp);

            fwprintf(stdout, L"TEST WM_RBUTTONDOWN x: %i\n", x);
            fwprintf(stdout, L"TEST WM_RBUTTONDOWN y: %i\n", y);

        } else if (m == WM_MBUTTONDOWN) {

        } else if (m == WM_KEYDOWN) {

            if (wp == VK_ESCAPE) {

                PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            }

        } else if (m == WM_SIZE) {

            // Set size and position of the window.

        } else if (m == WM_CLOSE) {

    //??        PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            DestroyWindow(w);

        } else if (m == WM_CREATE) {

            // Initialize the window.

        } else if (m == WM_DESTROY) {

            // Clean up window-specific data objects.
            PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        } else if (m == WM_QUIT) {

            //?? TODO

        } else {

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
-            //
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
        }

    } else if (a == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // No messages are available.

fwprintf(stdout, L"TEST no message available: %i\n", a);

        // Set loop break flag.
        copy_integer(p13, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

fwprintf(stdout, L"TEST negative message: %i\n", a);

        // An error occured.

        // Get the calling thread's last-error code.
        DWORD e = GetLastError();

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup win32 display. The message retrieval failed.");
        log_windows_system_error((void*) &e);

        // Set loop break flag.
        copy_integer(p13, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* MESSAGE_WIN32_DISPLAY_RECEIVER_SOURCE */
#endif
