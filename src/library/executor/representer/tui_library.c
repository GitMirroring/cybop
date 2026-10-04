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

//
// terminal colour
//

#include "../../../executor/representer/deserialiser/colour/terminal_colour_deserialiser.c"
#include "../../../executor/representer/serialiser/colour/terminal_colour_serialiser.c"

//
// terminal mode
//

#include "../../../executor/representer/serialiser/terminal_mode/line_speed_terminal_mode_serialiser.c"
#include "../../../executor/representer/serialiser/terminal_mode/terminal_mode_serialiser.c"

//
// tui
//

#include "../../../executor/representer/deserialiser/tui/tui_deserialiser.c"

#include "../../../executor/representer/serialiser/tui/border_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/character_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/clear_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/constraints_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/content_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/default_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/element_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/horizontal_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/initial_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/newline_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/origo_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/part_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/primitive_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/properties_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/rectangle_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/row_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/rows_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/vertical_tui_serialiser.c"
#include "../../../executor/representer/serialiser/tui/wide_character_tui_serialiser.c"

#if defined(__linux__) || defined(__unix__)

    //
    // ansi escape code
    //

    #include "../../../executor/representer/deserialiser/ansi_escape_code/ansi_escape_code_deserialiser.c"
    #include "../../../executor/representer/deserialiser/ansi_escape_code/character_ansi_escape_code_deserialiser.c"
    #include "../../../executor/representer/deserialiser/ansi_escape_code_length/ansi_escape_code_length_deserialiser.c"

    #include "../../../executor/representer/serialiser/ansi_escape_code/attribute_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/attributes_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/background_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/character_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/clear_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/colour_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/effect_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/foreground_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/reset_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/wide_character_ansi_escape_code_serialiser.c"

    #include "../../../executor/selector/ansi_escape_code/ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code/character_ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code/command_ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/add_ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/character_ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/command_ansi_escape_code_length_selector.c"

#elif defined(__APPLE__) && defined(__MACH__)

    //
    // ansi escape code
    //

    #include "../../../executor/representer/deserialiser/ansi_escape_code/ansi_escape_code_deserialiser.c"
    #include "../../../executor/representer/deserialiser/ansi_escape_code/character_ansi_escape_code_deserialiser.c"
    #include "../../../executor/representer/deserialiser/ansi_escape_code_length/ansi_escape_code_length_deserialiser.c"

    #include "../../../executor/representer/serialiser/ansi_escape_code/attribute_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/attributes_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/background_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/character_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/clear_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/colour_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/effect_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/foreground_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/reset_ansi_escape_code_serialiser.c"
    #include "../../../executor/representer/serialiser/ansi_escape_code/wide_character_ansi_escape_code_serialiser.c"

    #include "../../../executor/selector/ansi_escape_code/ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code/character_ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code/command_ansi_escape_code_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/add_ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/character_ansi_escape_code_length_selector.c"
    #include "../../../executor/selector/ansi_escape_code_length/command_ansi_escape_code_length_selector.c"

// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)

    //
    // win32 console
    //

    #include "../../../executor/representer/deserialiser/win32_console/win32_console_deserialiser.c"

    #include "../../../executor/representer/serialiser/win32_console/attributes_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/background_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/character_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/clear_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/effect_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/foreground_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/position_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/reset_win32_console_serialiser.c"
    #include "../../../executor/representer/serialiser/win32_console/state_win32_console_serialiser.c"

#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
