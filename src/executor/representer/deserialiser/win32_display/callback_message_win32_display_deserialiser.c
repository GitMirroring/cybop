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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf
#include <windowsx.h>

//
// Library interface
//

#include "constant.h"
#include "logger.h"

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
 * @param wp the additional message parametres of type WPARAM
 * @param lp the additional message parametres of type LPARAM
 */
LRESULT CALLBACK deserialise_win32_display_message_callback(HWND w, UINT m, WPARAM wp, LPARAM lp) {

    LRESULT r = (LRESULT) 0;

    fwprintf(stdout, L"Debug: deserialise win32 callback: %i\n", r);

    if (m == WM_PAINT) {

        //
        // Paint the window's client area.
        //

        //
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
        //

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

    } else {

        //
        // Continue with the default processing,
        // if none of the above messages matched.
        //
        r = DefWindowProc(w, m, wp, lp);
    }

    return r;
}
