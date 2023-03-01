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

#ifndef ROW_TUI_SERIALISER_SOURCE
#define ROW_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/tui/default_tui_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/horizontal_tui_serialiser.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/representer/serialiser/ansi_escape_code/wide_character_ansi_escape_code_serialiser.c"
    #include "../../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/representer/serialiser/ansi_escape_code/wide_character_ansi_escape_code_serialiser.c"
    #include "../../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/representer/serialiser/win32_console/character_win32_console_serialiser.c"
    #include "../../../../executor/representer/serialiser/win32_console/position_win32_console_serialiser.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Serialises the row into tui.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the horizontal border character
 * @param p3 the vertical border character
 * @param p4 the left top border character
 * @param p5 the right top border character
 * @param p6 the left bottom border character
 * @param p7 the right bottom border character
 * @param p8 the position x
 * @param p9 the size x
 * @param p10 the y coordinate
 * @param p11 the top vertical position flag
 * @param p12 the middle vertical position flag
 * @param p13 the bottom vertical position flag
 */
void serialise_tui_row(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui row.");

    // The loop count.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The loop variable.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The left border index.
    int li = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The right border index.
    int ri = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The left, centre, right horizontal position flags.
    int lp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int cp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    int rp = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // The character to be written.
    //
    // CAUTION! Initialise with space character,
    // which is used everywhere else aside the border.
    //
    // CAUTION! The properties like colour etc. become visible
    // ONLY if some character is actually printed on screen.
    // Therefore, initialising with the space character
    // is NECESSARY here.
    //
    wchar_t ch = *SPACE_UNICODE_CHARACTER_CODE_MODEL;

    // Initialise loop count.
    copy_integer((void*) &c, p8);
    calculate_integer_add((void*) &c, p9);
    // Initialise loop variable.
    copy_integer((void*) &x, p8);
    // Initialise left border index.
    copy_integer((void*) &li, (void*) &x);
    // Initialise right border index.
    copy_integer((void*) &ri, (void*) &c);
    calculate_integer_subtract((void*) &ri, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //?? TODO: Check loop count parametre for null!

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &x, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Determine horizontal position of x coordinate.
        serialise_tui_horizontal((void*) &lp, (void*) &cp, (void*) &rp, (void*) &x, (void*) &li, (void*) &ri);
#if defined(__linux__) || defined(__unix__)
        serialise_ansi_escape_code_position(p0, (void*) &x, p10);
#elif defined(__APPLE__) && defined(__MACH__)
        serialise_ansi_escape_code_position(p0, (void*) &x, p10);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        serialise_win32_console_position(p1, (void*) &x, p10);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        serialise_tui_default((void*) &ch, p2, p3, p4, p5, p6, p7, (void*) &lp, (void*) &cp, (void*) &rp, p11, p12, p13);

#if defined(__linux__) || defined(__unix__)
        serialise_ansi_escape_code_wide_character(p0, (void*) &ch, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
#elif defined(__APPLE__) && defined(__MACH__)
        serialise_ansi_escape_code_wide_character(p0, (void*) &ch, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
        serialise_win32_console_character(p1, (void*) &ch, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

        // Increment loop variable.
        x++;
    }
}

/* ROW_TUI_SERIALISER_SOURCE */
#endif
