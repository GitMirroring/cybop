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
// Library interface
//

#include "client.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Closes down the client on the given channel.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_close(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply close.");

    //
    // Declaration
    //

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part.
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part model item.
    void* sfm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item.
    void* idm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server flag part model item data.
    void* sfmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The identification part model item data.
    void* idmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME, (void*) CHANNEL_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get server flag part.
    get_part_name((void*) &sf, p0, (void*) SERVER_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME, (void*) SERVER_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get port part.
    get_part_name((void*) &p, p0, (void*) PORT_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME, (void*) PORT_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get identification part.
    get_part_name((void*) &id, p0, (void*) IDENTIFICATION_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME, (void*) IDENTIFICATION_CLOSE_DISPATCHING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get server flag part model item.
    copy_array_forward((void*) &sfm, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get identification part model item.
    copy_array_forward((void*) &idm, id, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get server flag part model item data.
    copy_array_forward((void*) &sfmd, sfm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get identification part model item data.
    copy_array_forward((void*) &idmd, idm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Default values
    //

    // Set server flag to FALSE (client mode) by default.
    int server = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    //
    // Set port to ZERO by default.
    //
    // CAUTION! It IS necessary so that the correct client entry
    // can be found in the DISPLAY server list, which was
    // assigned to port ZERO at service startup.
    //
    int port = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    //
    // CAUTION! The following values are ONLY copied,
    // if the source value is NOT NULL.
    // This is tested inside the "copy_integer" function.
    // Otherwise, the destination value remains as is.
    //

    copy_integer((void*) &server, sfmd);
    copy_integer((void*) &port, pmd);

    //
    // Functionality
    //

    // Close down client.
    close_client(idmd, (void*) &port, cmd, (void*) &server, p4);
}
