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

#ifndef MODE_TERMINAL_STARTER_SOURCE
#define MODE_TERMINAL_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/maintainer/starter/terminal/allocate_mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/copy_mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/edit_mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/get_mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/set_mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/store_mode_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Configures the terminal mode.
 *
 * @param p0 the file descriptor
 * @param p1 the input/output entry
 * @param p2 the flag indicating input (true) or output (false)
 */
void startup_terminal_mode(void* p0, void* p1, void* p2) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal mode.");

        // The original terminal mode (attributes).
        void* o = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The new terminal mode (attributes).
        void* n = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate memory for storing original as well as new terminal mode.
        startup_terminal_mode_allocate((void*) &o, (void*) &n);

        // Read original terminal mode.
        startup_terminal_mode_get(o, p0);

        // Store original terminal mode.
        startup_terminal_mode_store(p1, (void*) &o, p2);

        // Copy original to new terminal mode.
        startup_terminal_mode_copy((void*) &n, (void*) &o);

        // Edit new terminal mode.
        startup_terminal_mode_edit((void*) &n, p2);

        // Write new terminal mode.
        startup_terminal_mode_set(p0, (void*) &n);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal mode. The file descriptor is null.");
    }
}

/* MODE_TERMINAL_STARTER_SOURCE */
#endif
