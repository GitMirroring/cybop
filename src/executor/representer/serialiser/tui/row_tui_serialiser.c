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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ROW_TUI_SERIALISER_SOURCE
#define ROW_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/tui/character_tui_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/horizontal_position_tui_serialiser.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/representer/serialiser/win32_console/character_win32_console_serialiser.c"
    #include "../../../../executor/representer/serialiser/win32_console/position_win32_console_serialiser.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/ansi_escape_code/character_ansi_escape_code_serialiser.c"
    #include "../../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
#endif

/**
 * Serialises the row into tui.
 *
 * @param p0 the destination item
 * @param p1 the horizontal border character
 * @param p2 the vertical border character
 * @param p3 the left top border character
 * @param p4 the right top border character
 * @param p5 the left bottom border character
 * @param p6 the right bottom border character
 * @param p7 the position x
 * @param p8 the size x
 * @param p9 the y coordinate
 * @param p10 the top vertical position flag
 * @param p11 the middle vertical position flag
 * @param p12 the bottom vertical position flag
 */
void serialise_tui_row(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12) {

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
    // The character to be written.
    // CAUTION! Initialise with space character,
    // which is used everywhere else aside the border.
    // CAUTION! The properties like colour etc. become only visible,
    // if some character is actually printed on screen.
    // Therefore, initialising with the space character
    // IS NECESSARY here.
    wchar_t ch = *SPACE_UNICODE_CHARACTER_CODE_MODEL;

    // Initialise loop count.
    copy_integer((void*) &c, p7);
    calculate_integer_add((void*) &c, p8);
    // Initialise loop variable.
    copy_integer((void*) &x, p7);
    // Initialise left border index.
    copy_integer((void*) &li, (void*) &x);
    // Initialise right border index.
    copy_integer((void*) &ri, (void*) &c);
    calculate_integer_subtract((void*) &ri, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &x, (void*) &c);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Determine horizontal position of x coordinate.
        serialise_tui_position_horizontal((void*) &lp, (void*) &cp, (void*) &rp, (void*) &x, (void*) &li, (void*) &ri);

#ifdef WIN32
        serialise_win32_console_position(p0, (void*) &x, p9);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
        serialise_ansi_escape_code_position(p0, (void*) &x, p9);
#endif

        serialise_tui_character((void*) &ch, p1, p2, p3, p4, p5, p6, (void*) &lp, (void*) &cp, (void*) &rp, p10, p11, p12);

#ifdef WIN32
        serialise_win32_console_character(p0, (void*) &ch, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
        serialise_ansi_escape_code_character(p0, (void*) &ch, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
#endif

        // Increment loop variable.
        x++;
    }
}

/* ROW_TUI_SERIALISER_SOURCE */
#endif
