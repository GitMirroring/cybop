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

#ifndef WIN32_DISPLAY_DESERIALISER_SOURCE
#define WIN32_DISPLAY_DESERIALISER_SOURCE

#include <windowsx.h>

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the win32 event message.
 *
 * @param p0 the event type data (pointer reference)
 * @param p1 the event type count (pointer reference)
 * @param p2 the mouse button or key code
 * @param p3 the window identification
 * @param p4 the mouse position x coordinate
 * @param p5 the mouse position y coordinate
 * @param p6 the button- or key mask
 * @param p7 the mouse button identification
 * @param p8 the expose area x coordinate
 * @param p9 the expose area y coordinate
 * @param p10 the expose area width
 * @param p11 the expose area height
 * @param p12 the event message
 */
void deserialise_win32_display(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    //
    // The following code sections are NOT indented,
    // in order to better keep overview,
    // since more may have to be added in future.
    //

    if (p12 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        MSG* msg = (MSG*) p12;

    if (p11 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* h = (int*) p11;

    if (p10 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* w = (int*) p10;

    if (p9 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* y = (int*) p9;

    if (p8 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* x = (int*) p8;

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* b = (int*) p7;

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* m = (int*) p6;

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* py = (int*) p5;

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* px = (int*) p4;

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* win = (int*) p3;

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* bk = (int*) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise win32 display.");

        //
        // CAUTION! Process messages here and NOT
        // in a callback function, as suggested by win32.
        // The reason is that the callback function
        // has only four fixed parametres, but many
        // more have to be set here.
        //

        //
        // Get message type.
        //
        // https://docs.microsoft.com/en-us/windows/desktop/api/winuser/ns-winuser-msg
        //
        UINT t = (*msg).message;
        //
        // Get handle to the window whose window procedure receives the message.
        // This member is NULL when the message is a thread message.
        //
        HWND win = (*msg).hwnd;
        //
        // Get additional information about the message.
        // The exact meaning depends on the message type.
        //
        WPARAM t = (*msg).wParam;
        //
        // Get additional information about the message.
        // The exact meaning depends on the message type.
        //
        LPARAM t = (*msg).lParam;
        //
        // The cursor position, in SCREEN coordinates,
        // when the message was posted.
        //
        POINT pos = (*msg).pt;

        fwprintf(stdout, L"Debug: deserialise win32 display t: %i\n", t);

        if (t == WM_ACTIVATE) {

            //
            // Sent when a window is activated or becomes the focus.
            //

        } else if (t == WM_CHAR) {

        } else if (t == WM_CLOSE) {

            //
            // Sent when a window is closed.
            //

            //?? PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
            DestroyWindow((HWND) w);

        } else if (t == WM_CREATE) {

            //
            // Sent when a window is first created. Used for window initialisation.
            //

        } else if (t == WM_DESTROY) {

            //
            // Sent when a window is about to be destroyed.
            //

            // Clean up window-specific data objects.
            PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        } else if (t == WM_ENTERSIZEMOVE) {

            //
            // There are a number of modal operations that happen on windows.
            // Win32 Modal operations refer to functions that put an
            // application into a "mode" by starting their own event
            // processing loop until the mode finishes.
            // Common application modes include:
            // - drag and drop operations
            // - move/size operations
            // - anytime a dialog pops up that needs input
            //   before the application can continue.
            //
            // So what is happening is: Your message loop is NOT being run.
            // Your window recieved a WM_LBUTTONDOWN message
            // that you passed to DefWindowProc.
            // DefWindowProc determined that the user was trying
            // to size or move the window interactively and
            // entered a sizing/moving modal function.
            // This function is in a message processing loop
            // watching for mouse messages so that it can intercept
            // them to provide the interactive sizing experience,
            // and will only exit when the sizing operation completes --
            // typically by the user releasing the held button,
            // or by pressing escape.
            //
            // You get notified of this: DefWindowProc sends a
            // WM_ENTERSIZEMOVE and WM_EXITSIZEMOVE messages as it
            // enters and exits the modal event processing loop.
            //
            // To continue to generate "idle" messages, typically create
            // a timer (SetTimer) before calling a modal function --
            // or when getting a message that DefWindowProc is
            // entering a modal function -- the modal loop will
            // continue to dispatch WM_TIMER messages ...
            // and call the idle proc from the timer message handler.
            // Destroy the timer when the modal function returns.
            //
            // http://stackoverflow.com/questions/3102074/win32-my-application-freezes-while-the-user-resizes-the-window
            //

        } else if (t == WM_EXITSIZEMOVE) {

        } else if (t == WM_KEYDOWN) {

            //
            // Sent when a key is pressed.
            //

            copy_pointer(p0, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME_COUNT);

            // The additional message parametres of type WPARAM.
            WPARAM wp = (*msg).wParam;

            if (wp == VK_ESCAPE) {

                PostQuitMessage(*NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

                //?? TODO: Alternative to send message to windows to exit.
                //?? PostMessage(w, WM_DESTROY, 0, 0);
            }

        } else if (t == WM_KEYUP) {

            //
            // Sent when a key is released.
            //

            copy_pointer(p0, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_KILLFOCUS) {

            //
            // May be used to hide and delete the caret (cursor).
            //

            copy_pointer(p0, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_LBUTTONDOWN) {

            copy_pointer(p0, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT);

            // Get window where the message occured (identification).
            *win = (int) (*msg).hwnd;

            // The additional message parametres of type LPARAM.
            LPARAM lp = (*msg).lParam;

            //
            // Get mouse coordinates.
            //
            // CAUTION! Do NOT use the LOWORD or HIWORD macros to
            // extract the x- and y- coordinates of the cursor position
            // because these macros return incorrect results
            // on systems with multiple monitors.
            // Systems with multiple monitors can have negative
            // x- and y- coordinates, and LOWORD and HIWORD treat
            // the coordinates as unsigned quantities.
            //
            *px = GET_X_LPARAM(lp);
            *py = GET_Y_LPARAM(lp);

            // The additional message parametres of type WPARAM (button mask).
            *m = (int) (*msg).wParam;

        } else if (t == WM_LBUTTONUP) {

            copy_pointer(p0, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT);

            // Get window where the message occured (identification).
            *win = (int) (*msg).hwnd;

            // The additional message parametres of type LPARAM.
            LPARAM lp = (*msg).lParam;

            //
            // Get mouse coordinates.
            //
            // CAUTION! Do NOT use the LOWORD or HIWORD macros to
            // extract the x- and y- coordinates of the cursor position
            // because these macros return incorrect results
            // on systems with multiple monitors.
            // Systems with multiple monitors can have negative
            // x- and y- coordinates, and LOWORD and HIWORD treat
            // the coordinates as unsigned quantities.
            //
            *px = GET_X_LPARAM(lp);
            *py = GET_Y_LPARAM(lp);

            // The additional message parametres of type WPARAM (button mask).
            *m = (int) (*msg).wParam;

        } else if (t == WM_MBUTTONDOWN) {

            copy_pointer(p0, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_MOUSEMOVE) {

            //
            // Sent when the mouse has been moved.
            //

            copy_pointer(p0, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_MOVE) {

            //
            // Sent when a window has been moved.
            //

        } else if (t == WM_PAINT) {

            //
            // Sent when a window needs repainting.
            //

            //
            // Paint the window's client area.
            //
            // CAUTION! The window content is ONLY painted properly
            // when catching the WM_PAINT message in the CALLBACK
            // function "read_win32_display_message_callback",
            // and NOT here!
            //
            // Perhaps this is related to the following effect:
            //
            // The "PeekMessage" function normally does NOT remove
            // WM_PAINT messages from the queue. They remain
            // in the queue until they are processed.
            // However, if a WM_PAINT message has a NULL update
            // region, "PeekMessage" DOES remove it from the queue.
            //
            // http://msdn.microsoft.com/en-us/library/windows/desktop/ms644943(v=vs.85).aspx
            //

            //?? copy_pointer(p0, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME);
            //?? copy_pointer(p1, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_QUIT) {

            //
            // Sent when a Windows application is finally terminating.
            //

            //?? TODO: Set global "break" flag here, in order to exit cyboi?

        } else if (t == WM_RBUTTONDOWN) {

            copy_pointer(p0, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT);

            // The additional message parametres of type LPARAM.
            LPARAM lp = (*msg).lParam;

            int x = GET_X_LPARAM(lp);
            int y = GET_Y_LPARAM(lp);

            fwprintf(stdout, L"Debug: WM_RBUTTONDOWN x: %i\n", x);
            fwprintf(stdout, L"Debug: WM_RBUTTONDOWN y: %i\n", y);

        } else if (t == WM_SETFOCUS) {

            //
            // May be used to create and display the caret (cursor).
            //

            copy_pointer(p0, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

        } else if (t == WM_SIZE) {

            //
            // Sent when a window has changed size.
            //

        } else if (t == WM_TIMER) {

            //
            // Sent when a timer event occurs.
            //

        } else if (t == WM_USER) {

            //
            // Allows you to send messages.
            //

        } else {

            //
            // Translate any virtual accelerator keys.
            //
            // They get translated into character messages,
            // in order for keystrokes being delivered correctly.
            //
            // The character message is posted to the calling thread's
            // message queue, to be read the next time the thread
            // calls the "GetMessage" or "PeekMessage" function.
            //
            // This step is actually optional, but certain
            // things won't work if it's not there.
            //
            // Example: Generating WM_CHAR messages to
            // go along with WM_KEYDOWN messages.
            //
            TranslateMessage(msg);

            //
            // Send message to windows procedure.
            //
            // The message is sent out to the window
            // where the message (event) occured.
            // That window's "WndProc" procedure is called back.
            //
            // CAUTION! The window's "WndProc" procedure
            // is NOT magically called by the system.
            // It is called indirectly through the programme,
            // by calling "DispatchMessage" HERE.
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
            DispatchMessage(msg);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The mouse button or key code is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The id of the window is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The mouse position x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The mouse position y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The button- or key mask is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The mouse button identification is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The expose area x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The expose area y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The expose area width is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The expose area height is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read win32 display process. The message is null.");
    }
}

/* WIN32_DISPLAY_DESERIALISER_SOURCE */
#endif
