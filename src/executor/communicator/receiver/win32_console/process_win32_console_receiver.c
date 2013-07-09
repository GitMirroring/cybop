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

#ifndef PROCESS_WIN32_CONSOLE_RECEIVER_SOURCE
#define PROCESS_WIN32_CONSOLE_RECEIVER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../logger/logger.c"

/**
 * Processes a win32 console message.
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
 * @param p12 the input buffer data
 * @param p13 the input buffer count
 */
void receive_win32_console_process(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    // The following code sections are NOT indented,
    // since more may have to be added in future.

    if (p13 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        DWORD* ic = (DWORD*) p13;

    if (p12 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        INPUT_RECORD* id = (INPUT_RECORD*) p12;

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

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive win32 console process.");

        if (*ic > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            if (*ic < *NUMBER_2_INTEGER_STATE_CYBOI_MODEL) {

                // The message type.
                WORD t = id[*NUMBER_0_INTEGER_STATE_CYBOI_MODEL].EventType;

                if (t == FOCUS_EVENT) {

                    // CAUTION! These events are used internally
                    // by win32 and are recommended to be ignored.
                    // http://msdn.microsoft.com/en-us/windows/desktop/ms683149(v=vs.85)

                } else if (t == KEY_EVENT) {

                    // Get event record.
                    KEY_EVENT_RECORD r = id[*NUMBER_0_INTEGER_STATE_CYBOI_MODEL].Event.KeyEvent;

                    // Get flag if key is pressed
                    // (true - pressed; false - released).
                    //?? BOOL b = (int) r.bKeyDown;

                    // Get repeat count, which indicates
                    // that a key is being held down.
                    //?? WORD rc = (int) r.wRepeatCount;

                    // Get virtual key code that identifies
                    // the given key in a device-INDEPENDENT manner.
                    *bk = (int) r.wVirtualKeyCode;

                    // Get virtual scan code of the given key
                    // that represents the device-DEPENDENT value
                    // generated by the keyboard hardware.
                    //?? WORD sc = (int) r.wVirtualScanCode;

                    // Get translated unicode character.
                    //?? WCHAR wc = (wchar_t) r.uChar.UnicodeChar;

                    // Get control key state (button or key mask).
                    *m = (int) r.dwControlKeyState;

                } else if (t == MENU_EVENT) {

                    // CAUTION! These events are used internally
                    // by win32 and are recommended to be ignored.
                    // http://msdn.microsoft.com/en-us/windows/desktop/ms684213(v=vs.85)
                    //
                    // CAUTION! Furthermore, this event type is NOT useful in cyboi.
                    // The reason is that menu items and corresponding
                    // action commands are identified via knowledge tree.

                } else if (t == MOUSE_EVENT) {

                    // Get event record.
                    MOUSE_EVENT_RECORD r = id[*NUMBER_0_INTEGER_STATE_CYBOI_MODEL].Event.MouseEvent;

                    // Get mouse coordinates.
                    COORD c = r.dwMousePosition;
                    *px = c.X;
                    *py = c.Y;

                    // Get mouse button state.
                    *b = r.dwButtonState;

                    // Get control key state (button or key mask).
                    *m = r.dwControlKeyState;

                    // Get event flags.
                    //?? *TODO = r.dwEventFlags;

                } else if (t == WINDOW_BUFFER_SIZE_EVENT) {

                    // Get event record.
                    WINDOW_BUFFER_SIZE_RECORD r = id[*NUMBER_0_INTEGER_STATE_CYBOI_MODEL].Event.WindowBufferSizeEvent;

                    // Get new size of console screen buffer,
                    // in character cell columns and rows.
                    COORD c = r.dwSize;
                    *w = c.X;
                    *h = c.Y;

                } else {

                    log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The event type is unknown.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The input buffer count is greater than one, even though the buffer has a size of only one.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The input buffer count is zero, even though an input had been sensed before.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The mouse button or key code is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The id of the window is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The mouse position x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The mouse position y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The button- or key mask is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The mouse button identification is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The expose area x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The expose area y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The expose area width is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The expose area height is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The input buffer data is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive win32 console process. The input buffer count is null.");
    }
}

/* PROCESS_WIN32_CONSOLE_RECEIVER_SOURCE */
#endif
