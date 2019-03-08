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

#ifndef VALUES_GUI_EVENT_DESERIALISER_SOURCE
#define VALUES_GUI_EVENT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/representer/deserialiser/xcb/xcb_deserialiser.c"
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO: Add Cocoa support
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/representer/deserialiser/win32_display/win32_display_deserialiser.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Deserialises the gui event values.
 *
 * @param p0 the event name item
 * @param p1 the window identification [window, event] (xcb_window_t) for event expose | mouse button press | mouse button release | movement | mouse pointer enter | mouse pointer leave | keyboard press | keyboard release
 * @param p2 the exposed rectangle coordinate x of the left-upper corner relative to the window's origin (uint16_t) for event expose
 * @param p3 the exposed rectangle coordinate y of the left-upper corner relative to the window's origin (uint16_t) for event expose
 * @param p4 the exposed rectangle width (uint16_t) for event expose
 * @param p5 the exposed rectangle height (uint16_t) for event expose
 * @param p6 the mouse coordinate x [event_x] (int16_t) relative to the event window's origin for event mouse button press | mouse button release | movement | mouse pointer enter | mouse pointer leave | keyboard press | keyboard release
 * @param p7 the mouse coordinate y [event_y] (int16_t) relative to the event window's origin for event mouse button press | mouse button release | movement | mouse pointer enter | mouse pointer leave | keyboard press | keyboard release
 * @param p8 the button [detail] (xcb_button_t) for event mouse button press | mouse button release | movement | mouse pointer enter | mouse pointer leave
 * @param p9 the keycode [detail] (xcb_keycode_t) of the physical key on the keyboard for event keyboard press | keyboard release
 * @param p10 the mask [state] (uint16_t) of the pointer buttons and modifier keys for event mouse button press | mouse button release | movement | mouse pointer enter | mouse pointer leave | keyboard press | keyboard release
 * @param p11 the mouse button identification [mode] (uint8_t) for event mouse pointer enter | mouse pointer leave
 * @param p12 the event
 */
void deserialise_gui_event_values(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui event values.");

#if defined(__linux__) || defined(__unix__)
    deserialise_xcb(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO: Add Cocoa support
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    deserialise_win32_display(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* VALUES_GUI_EVENT_DESERIALISER_SOURCE */
#endif
