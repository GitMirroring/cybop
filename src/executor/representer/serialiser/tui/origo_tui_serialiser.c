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

#ifndef ORIGO_TUI_SERIALISER_SOURCE
#define ORIGO_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/representer/serialiser/win32_console/position_win32_console_serialiser.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
#endif

/**
 * Reset cursor position to origo.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the x coordinate
 * @param p3 the y coordinate
 * @param p4 the clear flag
 */
void serialise_tui_origo(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui origo.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_unequal((void*) &r, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Only reset cursor position to origo if
    // clear terminal screen flag is set.
    //
    // Clear flag IS set:
    //
    // The terminal screen was cleared before,
    // so that the output may be written to the origo
    // (top-left corner of terminal screen).
    // It is important to reset the cursor position,
    // since otherwise, text of embedded rectangles
    // may not be positioned correctly.
    //
    // Clear flag is NOT set:
    //
    // The terminal screen was not cleared before,
    // so that the user probably expects the output
    // to be written at the current prompt and
    // NOT to appear at the top-left corner.
    // Therefore, the cursor is NOT reset in this case.
    //
    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#ifdef WIN32
        serialise_win32_console_position(p1, p2, p3);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
        serialise_ansi_escape_code_position(p0, p2, p3);
#endif
    }
}

/* ORIGO_TUI_SERIALISER_SOURCE */
#endif
