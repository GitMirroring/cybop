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

#ifndef EDIT_MODE_WIN32_CONSOLE_STARTER_SOURCE
#define EDIT_MODE_WIN32_CONSOLE_STARTER_SOURCE

#include <windows.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../../executor/maintainer/starter/win32_console/input_edit_mode_win32_console_starter.c"
#include "../../../../executor/maintainer/starter/win32_console/output_edit_mode_win32_console_starter.c"
#include "../../../../logger/logger.c"

/**
 * Edits the win32 console mode.
 *
 * @param p0 the terminal mode
 * @param p1 the flag indicating input (true) or output (false)
 */
void startup_win32_console_mode_edit(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup win32 console mode edit.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        startup_win32_console_mode_edit_output(p0);

    } else {

        startup_win32_console_mode_edit_input(p0);
    }
}

/* EDIT_MODE_WIN32_CONSOLE_STARTER_SOURCE */
#endif
