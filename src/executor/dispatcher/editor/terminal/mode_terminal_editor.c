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

#ifndef MODE_TERMINAL_EDITOR_SOURCE
#define MODE_TERMINAL_EDITOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/editor/terminal/allocate_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/deallocate_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/edit_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/get_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/set_mode_terminal_editor.c"
#include "../../../../logger/logger.c"

/**
 * Edits the terminal mode.
 *
 * @param p0 the file descriptor
 * @param p1 the input/output entry
 */
void edit_terminal_mode(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Edit terminal mode.");

    // The terminal mode (attributes).
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate terminal mode.
    //
    // CAUTION! Hand over pointer REFERENCE.
    //
    edit_terminal_mode_allocate((void*) &m);

    //
    // Read current terminal mode.
    //
    // CAUTION! Do NOT hand over pointer reference.
    //
    edit_terminal_mode_get(m, p0);

    //
    // Edit terminal mode.
    //
    // CAUTION! Do NOT hand over pointer reference,
    // since only the CONTENT, but not pointer is to be edited.
    //
    edit_terminal_mode_edit(m, p1);

    //
    // Write new terminal mode.
    //
    // CAUTION! Do NOT hand over pointer reference.
    //
    edit_terminal_mode_set(p0, m);

    //
    // Deallocate terminal mode.
    //
    // CAUTION! It is not stored in input/output memory and
    // used as TEMPORARY variable only.
    //
    // CAUTION! Hand over pointer REFERENCE.
    //
    edit_terminal_mode_deallocate((void*) &m);
}

/* MODE_TERMINAL_EDITOR_SOURCE */
#endif
