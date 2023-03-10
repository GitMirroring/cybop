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

#ifndef WRITE_SOURCE
#define WRITE_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/accessor/getter/part/name_part_getter.c"
#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/streamer/writer/writer.c"
#include "../../logger/logger.c"

/**
 * Writes data to a device.
 *
 * CAUTION! Do NOT rename this function to "write",
 * since that name is already used by low-level glibc
 * functionality in header file unistd.h.
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the internal memory data
 */
void apply_write(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply write.");

    //
    // Declaration
    //

    // The channel part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The asynchronicity part.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The handler part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model item.
    void* mm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The asynchronicity part model item.
    void* am = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The channel part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The port part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The receiver part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The message part model item data, count.
    void* mmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The asynchronicity part model item data.
    void* amd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval
    //

    // Get channel part.
    get_part_name((void*) &c, p0, (void*) CHANNEL_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) CHANNEL_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get server part.
    get_part_name((void*) &s, p0, (void*) SERVER_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) SERVER_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get port part.
    get_part_name((void*) &p, p0, (void*) PORT_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) PORT_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get receiver part.
    get_part_name((void*) &r, p0, (void*) RECEIVER_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) RECEIVER_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get message part.
    get_part_name((void*) &m, p0, (void*) MESSAGE_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) MESSAGE_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get asynchronicity part.
    get_part_name((void*) &a, p0, (void*) ASYNCHRONICITY_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) ASYNCHRONICITY_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);
    // Get handler part.
    get_part_name((void*) &h, p0, (void*) HANDLER_WRITE_STREAMING_LOGIC_CYBOL_NAME, (void*) HANDLER_WRITE_STREAMING_LOGIC_CYBOL_NAME_COUNT, p1, p2, p3, p4);

    // Get channel part model item.
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get server part model item.
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get port part model item.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get receiver part model item.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get message part model item.
    copy_array_forward((void*) &mm, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get asynchronicity part model item.
    copy_array_forward((void*) &am, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get channel part model item data.
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get server part model item data.
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get port part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get receiver part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get message part model item data, count.
    copy_array_forward((void*) &mmd, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mmc, mm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get asynchronicity part model item data.
    copy_array_forward((void*) &amd, am, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Functionality
    //

    // Write data to device.
    write_data(rm, mmd, mmc, (void*) &m, p4, cmd, smd, pmd, (void*) &h, amd);
}

/* WRITE_SOURCE */
#endif
