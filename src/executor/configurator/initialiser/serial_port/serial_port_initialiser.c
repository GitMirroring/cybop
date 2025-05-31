/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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

#include "client.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Initialises the serial port.
 *
 * @param p0 the file descriptor
 * @param p1 the client entry
 * @param p2 the baudrate
 */
void initialise_serial_port(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise serial port.");
    fwprintf(stdout, L"Debug: Initialise serial port. p0: %i\n", p0);
    fwprintf(stdout, L"Debug: Initialise serial port. *p0: %i\n", *((int*) p0));

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
    copy_array_forward(p1, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) ORIGINAL_MODE_SERIAL_CLIENT_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Edit current terminal mode for SERIAL PORT.
    initialise_serial_port_mode(m, p2);

    // Set edited terminal mode.
    set_terminal_mode(p0, m);

    // Deallocate terminal mode.
    deallocate_terminal_mode((void*) &m);
}
