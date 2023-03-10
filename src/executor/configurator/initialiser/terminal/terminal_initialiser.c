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

#ifndef TERMINAL_INITIALISER_SOURCE
#define TERMINAL_INITIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/accessor/getter/terminal_mode/terminal_mode_getter.c"
#include "../../../../executor/accessor/setter/terminal_mode/terminal_mode_setter.c"
#include "../../../../executor/configurator/initialiser/terminal/mode_terminal_initialiser.c"
#include "../../../../executor/copier/terminal_mode/terminal_mode_copier.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/allocator/terminal_mode_allocator.c"
#include "../../../../executor/memoriser/deallocator/terminal_mode_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the terminal.
 *
 * @param p0 the file descriptor
 * @param p1 the client entry
 */
void initialise_terminal(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise terminal.");
    //?? fwprintf(stdout, L"Debug: Initialise terminal. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Initialise terminal. *p0: %i\n", *((int*) p0));

    // The terminal mode.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal mode copy for storage.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate terminal mode.
    allocate_terminal_mode((void*) &m);
    // Allocate terminal mode copy for storage.
    allocate_terminal_mode((void*) &c);

    // Get current terminal mode.
    get_terminal_mode(m, p0);

    // Copy current terminal mode for storage.
    copy_terminal_mode(c, m);

    // Set terminal mode copy into client entry.
    copy_array_forward(p1, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    //?? TODO: For win32, also set separate output original mode.

    // Edit current terminal mode.
    initialise_terminal_mode(m);

    // Set edited terminal mode.
    set_terminal_mode(p0, m);

    // Deallocate terminal mode.
    deallocate_terminal_mode((void*) &m);
}

/* TERMINAL_INITIALISER_SOURCE */
#endif
