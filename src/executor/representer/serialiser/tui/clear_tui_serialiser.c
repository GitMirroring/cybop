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

#ifndef CLEAR_TUI_SERIALISER_SOURCE
#define CLEAR_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/representer/serialiser/win32_console/clear_win32_console_serialiser.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/ansi_escape_code/clear_ansi_escape_code_serialiser.c"
#endif

/**
 * Clears the terminal screen.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the clear flag
 * @param p3 the tree level
 */
void serialise_tui_clear(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui clear.");

    // The root tree level comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The clear flag comparison result.
    int c = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    // Only clear terminal screen if this is the root
    // tree level, which means that this is the initial
    // (and not a recursive) call of this function.
    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_unequal((void*) &c, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Only clear terminal screen if clear flag is set.
        if (c != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

#ifdef WIN32
            serialise_win32_console_clear(p1);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
            serialise_ansi_escape_code_clear(p0);
#endif
        }
    }
}

/* CLEAR_TUI_SERIALISER_SOURCE */
#endif
