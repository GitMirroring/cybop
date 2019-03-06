/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef XCB_DESERIALISER_SOURCE
#define XCB_DESERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/gui/event_gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/keyboard/keyboard_state_cybol_name.c"
#include "../../../../constant/name/cybol/state/mouse/mouse_state_cybol_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the given xcb event.
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
 * @param p12 the event
 */
void deserialise_xcb(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    //
    // The following code sections are NOT indented,
    // in order to better keep overview,
    // since more may have to be added in future.
    //

    if (p12 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_generic_event_t* e = (xcb_generic_event_t*) p12;

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

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xcb.");

        //
        // Get response type.
        //
        // CAUTION! The type of the returned value is "uint8_t".
        // Since it is just one byte in size, it may be assigned
        // to an "int" variable of four byte without loss.
        //
        int t = (int) e->response_type;

fwprintf(stdout, L"TEST deserialise xcb t: %i\n", t);

        //
        // Convert type using bit operation AND.
        // The hexadecimal value 0x80 is decimal 128.
        //
        //?? TODO: Why is this conversion necessary?
        //?? It works correctly also without conversion.
        //?? Nothing explained in the tutorials ...
        //
        t = t & (~0x80);

fwprintf(stdout, L"TEST deserialise xcb converted t: %i\n", t);

        if (t == XCB_EXPOSE) {

            //
            // Expose events are sensed when a window needs
            // to be repainted, e.g. when being displayed after
            // having been covered by another window before.
            //

fwprintf(stdout, L"TEST deserialise xcb XCB_EXPOSE t: %i\n", t);

            xcb_expose_event_t* ev = (xcb_expose_event_t*) e;

            //
            // Consider only the last in a row of multiple expose
            // events, in order to avoid flickering of the display.
            //
            //?? TODO: ... did work in xlib, but not with xcb anymore
            // if (ev->xexpose.count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
//??                        if (ev->count == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

fwprintf(stdout, L"TEST deserialise xcb XCB_EXPOSE ev->count: %i\n", ev->count);

            copy_pointer(p0, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &EXPOSE_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

            // Get window identification.
            *win = (int) ev->window;
            // Get expose area position.
            *x = (int) ev->x;
            *y = (int) ev->y;
            // Get expose area size.
            *w = (int) ev->width;
            *h = (int) ev->height;
//??                    }

        } else if (t == XCB_BUTTON_PRESS) {

fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_PRESS t: %i\n", t);

            copy_pointer(p0, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT);

            xcb_button_press_event_t* ev = (xcb_button_press_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;

        } else if (t == XCB_BUTTON_RELEASE) {

fwprintf(stdout, L"TEST deserialise xcb XCB_BUTTON_RELEASE t: %i\n", t);

            copy_pointer(p0, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT);

            xcb_button_release_event_t* ev = (xcb_button_release_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;

        } else if (t == XCB_MOTION_NOTIFY) {

fwprintf(stdout, L"TEST deserialise xcb XCB_MOTION_NOTIFY t: %i\n", t);

            copy_pointer(p0, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME_COUNT);

            xcb_motion_notify_event_t* ev = (xcb_motion_notify_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;

/*??
            //?? The an_event.xmotion.state variable (unsigned int state) contains
            //?? a mask of the buttons (or keys) held down during this event - if any.
            //?? This field is a bitwise OR of any of the following:
            Button1Mask
            Button2Mask
            Button3Mask
            Button4Mask
            Button5Mask
            ShiftMask
            LockMask
            ControlMask
            Mod1Mask
            Mod2Mask
            Mod3Mask
            Mod4Mask
            Mod5Mask

            //?? Example:
            //?? If the 1st mouse button was held during this event,
            //?? draw a pixel at the mouse pointer location.
            if (an_event.xmotion.state & Button1Mask) {
                XDrawPoint(display, the_win, gc_draw, x, y);
            }
    */

        } else if (t == XCB_ENTER_NOTIFY) {

fwprintf(stdout, L"TEST deserialise xcb XCB_ENTER_NOTIFY t: %i\n", t);

            copy_pointer(p0, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &ENTER_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

            xcb_enter_notify_event_t* ev = (xcb_enter_notify_event_t*) e;

            //?? an_event.xcrossing

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;
            // Get mouse button identification.
            *b = (int) ev->mode;

        } else if (XCB_LEAVE_NOTIFY) {

fwprintf(stdout, L"TEST deserialise xcb XCB_LEAVE_NOTIFY t: %i\n", t);

            copy_pointer(p0, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &LEAVE_NOTIFY_EVENT_GUI_STATE_CYBOL_NAME_COUNT);

            xcb_leave_notify_event_t* ev = (xcb_leave_notify_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;
            // Get mouse button identification.
            *b = (int) ev->mode;

        } else if (t == XCB_KEY_PRESS) {

fwprintf(stdout, L"TEST deserialise xcb XCB_KEY_PRESS t: %i\n", t);

            copy_pointer(p0, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &KEY_PRESS_KEYBOARD_STATE_CYBOL_NAME_COUNT);

            // Key press events relate to keyboard keys.
            xcb_key_press_event_t* ev = (xcb_key_press_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;

    /*??
            Example:
            // Translate the key code to a key symbol.
            KeySym key_symbol = XKeycodeToKeysym(display, an_event.xkey.keycode, 0);
            switch (key_symbol) {
                case XK_1:
                case XK_KP_1:
                    // '1' key was pressed, either the normal '1',
                    // or the '1' on the keypad. draw the current pixel.
                    XDrawPoint(display, the_win, gc_draw, x, y);
                    break;
                case XK_Delete:
                    // DEL key was pressed, erase the current pixel.
                    XDrawPoint(display, the_win, gc_erase, x, y);
                    break;
                default:
                    // Anything else - check if it is a letter key
                    if (key_symbol >= XK_A && key_symbol <= XK_Z) {
                        int ascii_key = key_symbol - XK_A + 'A';
                        printf("Key pressed - '%c'\n", ascii_key);
                    }
                    if (key_symbol >= XK_a && key_symbol <= XK_z) {
                        int ascii_key = key_symbol - XK_a + 'a';
                        printf("Key pressed - '%c'\n", ascii_key);
                    }
                    break;
            }
    */

    /*??
            KeySym k;
            char text[10];
            char str_test[1000];
            char str_zugriff[1000];
            char str_menubar[100];
            //?? long long int or double menu_foreground;
            // The temporary variables.
        //??    int k;
            int menu_eintrage_ende;
            int window;
            int i = 0, count_menu, count_item, indent_x, indent_y, indent_menu_item_x;
    */

    /*??
            i = XLookupString(&e, text, 10, &k, 0);

            //// Das gehoert hier eigentlich nicht her, nur zu Demonstartionszwecken
            //// Bei Tastendruck 'a' wird erstes Menue gezeichenet, bei b das Zweite, bei c das Dritte

            if (i == 1 && text[0] == 'a') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 1;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'b') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 1;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'c') {

                XClearArea (d, w, 0, 0, 0, 0, True);
                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 1;
            }

            if (i == 1 && text[0] == 'x') {

                XClearArea (d, w, 0, 0, 0, 0, True);

                Anwendung.menu_bar1.menus[0].angeklickt = 0;
                Anwendung.menu_bar1.menus[1].angeklickt = 0;
                Anwendung.menu_bar1.menus[2].angeklickt = 0;

            } else if (i == 1 && text[0] == 'q') {

                f = 1;
            }
    */

            //?? To erase graphical areas (such as an open menu), use:
            //?? XClearArea (d, w, 0, 0, 0, 0, True);

            //?? What is this useful for?
            //?? XDrawImageString(e.xexpose.display, e.xexpose.window, gc_menu_font, 100, 100, event.xbutton.x, wcslen(event.xbutton.x));

        } else if (t == XCB_KEY_RELEASE) {

fwprintf(stdout, L"TEST deserialise xcb XCB_KEY_RELEASE t: %i\n", t);

            copy_pointer(p0, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME);
            copy_pointer(p1, (void*) &KEY_RELEASE_KEYBOARD_STATE_CYBOL_NAME_COUNT);

            xcb_key_release_event_t* ev = (xcb_key_release_event_t*) e;

            // Get mouse button or keycode.
            *bk = (int) ev->detail;
            // Get window identification.
            *win = (int) ev->event;
            // Get mouse coordinates.
            *px = (int) ev->event_x;
            *py = (int) ev->event_y;
            // Get button mask.
            *m = (int) ev->state;
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse button or key code is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The id of the window is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse position x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse position y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The button- or key mask is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The mouse button identification is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The expose area x coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The expose area y coordinate is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The expose area width is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The expose area height is null.");
    }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise xcb. The event is null.");
    }
}

/* XCB_DESERIALISER_SOURCE */
#endif
