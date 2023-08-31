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
// gui
//

#include "../../../executor/representer/deserialiser/gui/action_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/constraints_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/content_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/element_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/part_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui/whole_gui_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/button_press_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/button_release_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/close_window_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/enter_notify_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/expose_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/key_press_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/key_release_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/leave_notify_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_action/motion_notify_gui_action_deserialiser.c"
#include "../../../executor/representer/deserialiser/gui_event/gui_event_deserialiser.c"

#include "../../../executor/representer/serialiser/gui/cleanup_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/component_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/constraints_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/content_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/context_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/element_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/initial_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/part_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/properties_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/shape/rectangle_shape_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/shape_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/text_gui_serialiser.c"
#include "../../../executor/representer/serialiser/gui/window_gui_serialiser.c"

//
// layout
//

#include "../../../executor/representer/serialiser/layout/absolute/position_absolute_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/absolute/size_absolute_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/element_part_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/grid/position_grid_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/grid/size_grid_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/part_layout_serialiser.c"
#include "../../../executor/representer/serialiser/layout/position_layout_serialiser.c"

#if defined(__linux__) || defined(__unix__)

    //
    // xcb
    //

    #include "../../../executor/representer/deserialiser/xcb_event/button_press_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/button_release_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/client_message_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/configure_notify_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/enter_notify_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/expose_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/key_press_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/key_release_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/leave_notify_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/motion_notify_xcb_event_deserialiser.c"
    #include "../../../executor/representer/deserialiser/xcb_event/xcb_event_deserialiser.c"

    #include "../../../executor/representer/serialiser/xcb/cap_style_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/cleanup_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/context_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/fill_rule_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/fill_style_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/join_style_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/line_style_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/properties_context_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/rectangle_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/text_xcb_serialiser.c"
    #include "../../../executor/representer/serialiser/xcb/window_xcb_serialiser.c"

#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)

    //
    // win32 display
    //

    #include "../../../executor/representer/deserialiser/win32_display/callback_message_win32_display_deserialiser.c"
    #include "../../../executor/representer/deserialiser/win32_display/win32_display_deserialiser.c"

    #include "../../../executor/representer/serialiser/win32_display/context_win32_display_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_display/rectangle_win32_display_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_display/text_win32_display_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_display/window_win32_display_serialiser.c"

#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
