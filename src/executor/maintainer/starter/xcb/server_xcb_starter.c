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

#ifndef SERVER_XCB_STARTER_SOURCE
#define SERVER_XCB_STARTER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the x window system server.
 *
 * @param p0 the input/output entry
 */
void startup_xcb_server(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup xcb server.");

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate and open connexion.
    //
    // CAUTION! Do NOT allocate the connexion manually here.
    // The xcb_connection_t is a structure containing
    // all data needed to communicate with an x server.
    //
    c = (void*) xcb_connect(*NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    //
    // Store various values in input/output entry.
    //
    // CAUTION! Do NOT use "overwrite_array" function here,
    // since it adapts the array count and size.
    // But the array's count and size are CONSTANT.
    //
    // CAUTION! Do NOT hand over input/output entry as pointer reference.
    //
    // CAUTION! Hand over values as pointer REFERENCE.
    //

    // Store connexion in input/output entry.
    set_io_entry_element(p0, (void*) &c, (void*) CONNEXION_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
}

/* SERVER_XCB_STARTER_SOURCE */
#endif
