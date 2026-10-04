/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TUI_HEADER
#define TUI_HEADER

//
// CAUTION! The following header files are included here so that
// it gets easier for other source files to use them by just
// including this ONE file instead of many.
//

//
// model
//

#include "constant/model/ansi_escape_code/ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/attribute_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/background_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/foreground_ansi_escape_code_model.h"
#include "constant/model/ansi_escape_code/input_ansi_escape_code_model.h"

#include "constant/model/cyboi/state/colour/terminal_colour_state_cyboi_model.h"

#include "constant/model/cybol/colour/terminal_colour_cybol_model.h"

#include "constant/model/cybol/device/terminal_device_cybol_model.h"

#include "constant/model/terminal/key_code_terminal_model.h"

//
// name
//

#include "constant/name/cybol/state/tui/tui_state_cybol_name.h"

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
// ansi escape code
//

void deserialise_ansi_escape_code(void* p0, void* p1, void* p2);
void deserialise_ansi_escape_code_character(void* p0, void* p1, void* p2);
void deserialise_ansi_escape_code_length(void* p0, void* p1, void* p2);

void select_ansi_escape_code(void* p0, void* p1, void* p2);
void select_ansi_escape_code_character(void* p0, void* p1, void* p2);
void select_ansi_escape_code_command(void* p0, void* p1, void* p2);
void select_ansi_escape_code_length(void* p0, void* p1, void* p2);
void select_ansi_escape_code_length_add(void* p0, void* p1, void* p2);
void select_ansi_escape_code_length_character(void* p0, void* p1, void* p2);
void select_ansi_escape_code_length_command(void* p0, void* p1, void* p2);

void serialise_ansi_escape_code_attribute(void* p0, void* p1, void* p2, void* p3);
void serialise_ansi_escape_code_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_ansi_escape_code_background(void* p0, void* p1, void* p2);
void serialise_ansi_escape_code_character(void* p0, void* p1, void* p2);
void serialise_ansi_escape_code_clear(void* p0);
void serialise_ansi_escape_code_colour(void* p0, void* p1, void* p2, void* p3);
void serialise_ansi_escape_code_effect(void* p0, void* p1, void* p2, void* p3, void* p4);
void serialise_ansi_escape_code_foreground(void* p0, void* p1, void* p2);
void serialise_ansi_escape_code_position(void* p0, void* p1, void* p2);
void serialise_ansi_escape_code_reset(void* p0);
void serialise_ansi_escape_code_wide_character(void* p0, void* p1, void* p2);

//
// terminal colour
//

void deserialise_colour_terminal(void* p0, void* p1, void* p2);
void serialise_colour_terminal(void* p0, void* p1);

//
// terminal mode
//

void serialise_terminal_mode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_terminal_mode_line_speed(void* p0, void* p1);

//
// tui
//

void deserialise_tui(void* p0, void* p1, void* p2);

void serialise_tui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21);
void serialise_tui_border(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_tui_character(void* p0, void* p1, void* p2, void* p3);
void serialise_tui_clear(void* p0, void* p1, void* p2, void* p3);
void serialise_tui_constraints(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10);
void serialise_tui_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23);
void serialise_tui_default(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12);
void serialise_tui_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20);
void serialise_tui_horizontal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_tui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18);
void serialise_tui_newline(void* p0, void* p1, void* p2, void* p3);
void serialise_tui_origo(void* p0, void* p1, void* p2, void* p3);
void serialise_tui_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20);
void serialise_tui_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_tui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);
void serialise_tui_rectangle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);
void serialise_tui_row(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13);
void serialise_tui_rows(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11);
void serialise_tui_vertical(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5);
void serialise_tui_wide_character(void* p0, void* p1, void* p2, void* p3);

//
// win32 console
//

void deserialise_win32_console(void* p0, void* p1, void* p2);

void serialise_win32_console_attributes(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);
void serialise_win32_console_background(void* p0, void* p1);
void serialise_win32_console_character(void* p0, void* p1, void* p2);
void serialise_win32_console_clear(void* p0);
void serialise_win32_console_effect(void* p0, void* p1, void* p2);
void serialise_win32_console_foreground(void* p0, void* p1);
void serialise_win32_console_position(void* p0, void* p1, void* p2);
void serialise_win32_console_reset(void* p0, void* p1);
void serialise_win32_console_state(void* p0, void* p1);

/* TUI_HEADER */
#endif
