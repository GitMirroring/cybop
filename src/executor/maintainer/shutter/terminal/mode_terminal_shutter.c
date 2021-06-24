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

#ifndef MODE_TERMINAL_SHUTTER_SOURCE
#define MODE_TERMINAL_SHUTTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/editor/terminal/retrieve_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/deallocate_mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/set_mode_terminal_editor.c"
#include "../../../../logger/logger.c"

/**
 * Restores the original terminal mode.
 *
 * @param p0 the file descriptor
 * @param p1 the input/output entry
 * @param p2 the flag indicating input (true) or output (false)
 */
void shutdown_terminal_mode(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal mode.");

    // The original terminal mode (attributes).
    void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieve original terminal mode.
    //
    // CAUTION! Hand over pointer REFERENCE.
    //
    edit_terminal_mode_retrieve((void*) &o, p1, p2);

    //
    // Write original terminal mode.
    //
    // CAUTION! Do NOT hand over pointer reference.
    //
    edit_terminal_mode_set(p0, o);

    //
    // Deallocate original terminal mode.
    //
    // CAUTION! Hand over pointer REFERENCE.
    //
    edit_terminal_mode_deallocate((void*) &o);
}

/* MODE_TERMINAL_SHUTTER_SOURCE */
#endif
