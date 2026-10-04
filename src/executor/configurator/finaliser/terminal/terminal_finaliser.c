/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Finalises the terminal.
 *
 * @param p0 the file descriptor
 * @param p1 the client entry
 */
void finalise_terminal(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Finalise terminal.");
    //?? fwprintf(stdout, L"Debug: Finalise terminal. p0: %i\n", p0);
    //?? fwprintf(stdout, L"Debug: Finalise terminal. *p0: %i\n", *((int*) p0));

    // The terminal mode.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get original terminal mode from client entry.
    copy_array_forward((void*) &m, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_ORIGINAL_MODE_TERMINAL_CLIENT_STATE_CYBOI_NAME);
    //?? TODO: For win32, also get separate output original mode.

    // Set back original terminal mode.
    set_terminal_mode(p0, m);

    // Deallocate terminal mode.
    deallocate_terminal_mode((void*) &m);
}
