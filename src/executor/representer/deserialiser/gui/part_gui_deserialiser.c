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

#ifndef PART_GUI_DESERIALISER_SOURCE
#define PART_GUI_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/representer/deserialiser/gui/content_gui_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the gui part element into an action.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source part
 * @param p3 the knowledge memory part (pointer reference)
 * @param p4 the stack memory item
 * @param p5 the internal memory data
 * @param p6 the event name data
 * @param p7 the event name count
 * @param p8 the mouse x coordinate
 * @param p9 the mouse y coordinate
 * @param p10 the message format
 * @param p11 the window parent coordinates origo x
 * @param p12 the window parent coordinates origo y
 * @param p13 the loop break flag
 */
void deserialise_gui_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui part.");

    // The part format, model, properties item.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part format, model, properties item data, count.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? fwprintf(stdout, L"Debug: Deserialise gui part. p2: %i\n", p2);

    // Get part format, model, properties item.
    copy_array_forward((void*) &f, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &p, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

/*??
    fwprintf(stdout, L"Debug: Deserialise gui part. f: %i\n", f);
    fwprintf(stdout, L"Debug: Deserialise gui part. m: %i\n", m);
    fwprintf(stdout, L"Debug: Deserialise gui part. p: %iv, p);
*/

    // Get part format, model, properties item data, count.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
    fwprintf(stdout, L"Debug: Deserialise gui part. fd: %i\n", fd);
    fwprintf(stdout, L"Debug: Deserialise gui part. *fd: %i\n", *((int*) fd));
    fwprintf(stdout, L"Debug: Deserialise gui part. *mc: %i\n", *((int*) mc));
    fwprintf(stdout, L"Debug: Deserialise gui part. *pc: %i\n", *((int*) pc));
*/

    //
    // Deserialise content.
    //
    // CAUTION! The source format fd should NOT be
    // mixed up with the message format p10.
    //
    deserialise_gui_content(p0, p1, md, mc, pd, pc, fd, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13);
}

/* PART_GUI_DESERIALISER_SOURCE */
#endif
