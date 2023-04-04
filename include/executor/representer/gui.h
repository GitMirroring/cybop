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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef GUI_HEADER
#define GUI_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/cybol/layout/border_layout_cybol_model.h"
#include "constant/model/cybol/layout/direction_layout_cybol_model.h"
#include "constant/model/cybol/layout/layout_cybol_model.h"
#include "constant/model/cybol/layout/stretch_layout_cybol_model.h"

#include "constant/model/cybol/xcb/cap_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/event_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/fill_rule_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/fill_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/join_style_xcb_cybol_model.h"
#include "constant/model/cybol/xcb/line_style_xcb_cybol_model.h"

//
// name
//

#include "constant/name/cybol/state/gui/event_gui_state_cybol_name.h"
#include "constant/name/cybol/state/gui/gui_state_cybol_name.h"

#include "constant/name/cybol/state/layout/grid_layout_state_cybol_name.h"

//
// Loading of a shared object (dynamic library)
//
// A shared object (.so) library gets loaded when needed
// at runtime. This kind of loading happens AUTOMATICALLY.
// The necessary machine language instructions got added to the
// binary executable by the compiler and linker during translation.
//

//
// Keyword "extern"
//
// A function is declared with storage class "extern"
// by DEFAULT, even if the keyword "extern" is missing.
// The keyword "extern" has NO influence on the source code in
// terms of optimisation or the like and thus is NOT necessary.
// It is just a HINT to the reader (developer) indicating that
// the function is implemented in an EXTERNAL source file.
// A COMMENT like this one can be used as hint, instead of that keyword.
//

//
// gui
//

void deserialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_gui_action(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void deserialise_gui_action_button_press(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_button_release(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void deserialise_gui_action_close_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_enter_notify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_expose(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_key_press(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_key_release(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_leave_notify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_action_motion_notify(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void deserialise_gui_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void deserialise_gui_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void deserialise_gui_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);
void deserialise_gui_event(void* p0, void* p1);
void deserialise_gui_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void deserialise_gui_whole(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);

void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);
void serialise_gui_cleanup(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_gui_component(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void serialise_gui_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_gui_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22);
void serialise_gui_context(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_gui_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21);
void serialise_gui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15);
void serialise_gui_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21);
void serialise_gui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void serialise_gui_shape(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_gui_shape_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void serialise_gui_text(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_gui_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);

//
// layout
//

void serialise_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_layout_absolute_position(void* p0, void* p1, void* p2, void* p3);
void serialise_layout_absolute_size(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_layout_grid_position(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_layout_grid_size(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_layout_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_layout_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_layout_position(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

//
// win32 display
//

void deserialise_win32_display(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

void serialise_win32_display_context(void* p0, void* p1, void* p2, void* p3);
void serialise_win32_display_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_win32_display_text(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_win32_display_window(void* p0, void* p1, void* p2, void* p3, void* p4);

//
// xcb
//

void deserialise_xcb_event(void* p0, void* p1);
void deserialise_xcb_event_button_press(void* p0, void* p1);
void deserialise_xcb_event_button_release(void* p0, void* p1);
void deserialise_xcb_event_client_message(void* p0, void* p1);
void deserialise_xcb_event_configure_notify(void* p0, void* p1);
void deserialise_xcb_event_enter_notify(void* p0, void* p1);
void deserialise_xcb_event_expose(void* p0, void* p1);
void deserialise_xcb_event_key_press(void* p0, void* p1);
void deserialise_xcb_event_key_release(void* p0, void* p1);
void deserialise_xcb_event_leave_notify(void* p0, void* p1);
void deserialise_xcb_event_motion_notify(void* p0, void* p1);

void serialise_xcb_cap_style(void* p0, void* p1, void* p2);
void serialise_xcb_cleanup(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_xcb_context(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_xcb_context_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17);
void serialise_xcb_fill_rule(void* p0, void* p1, void* p2);
void serialise_xcb_fill_style(void* p0, void* p1, void* p2);
void serialise_xcb_join_style(void* p0, void* p1, void* p2);
void serialise_xcb_line_style(void* p0, void* p1, void* p2);
void serialise_xcb_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_xcb_text(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_xcb_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/* GUI_HEADER */
#endif
