/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TERMINAL_INITIALISER_SOURCE
#define TERMINAL_INITIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"
--
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/editor/terminal/allocate_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/deallocate_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/edit_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/get_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/set_mode_terminal_editor.c"

/**
 * Initialises the terminal.
 *
 * @param p0 the file descriptor
 * @param p1 the client entry
 */
void initialise_terminal(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise terminal.");

    //
    //?? TODO:
    //
    // Is it necessary to use the file "win32_console_mode_copier.c"?
    // Why was it introduced in an older version of cyboi?
    //

    // The terminal mode.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate terminal mode.
    allocate_terminal_mode((void*) &m);

    // Read current terminal mode.
    get_terminal_mode(m, p0);

    // Store current terminal mode in client entry.
    copy_array_forward(p0, p4, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SERVER_ENTRY_BACKLINK_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Edit terminal mode.
    initialise_terminal_mode(m);

    // Write new terminal mode.
    set_terminal_mode(p0, m);

    // Deallocate terminal mode.
    deallocate_terminal_mode((void*) &m);
}

/* TERMINAL_INITIALISER_SOURCE */
#endif
