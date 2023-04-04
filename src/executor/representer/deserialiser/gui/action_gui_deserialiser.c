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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ACTION_GUI_DESERIALISER_SOURCE
#define ACTION_GUI_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "gui.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the gui action properties.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source model data (user interface window model hierarchy used to identify nested components and their action via mouse coordinates)
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the source format
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the destination format
 */
void deserialise_gui_action(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise gui action.");
    //?? fwprintf(stdout, L"Debug: Deserialise gui action. destination format p10: %i\n", p10);
    //?? fwprintf(stdout, L"Debug: Deserialise gui action. destination format *p10: %i\n", *((int*) p10));

    //
    // The destination properties item data, count.
    //
    // CAUTION! Although they are called DESTINATION properties,
    // they contain the event details which were determined before
    // in the gui event deserialiser.
    //
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The event name part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part.
    void* x = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part.
    void* y = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The event name part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part model item.
    void* xm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part model item.
    void* ym = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The event name part model item data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse x part model item data.
    void* xmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mouse y part model item data.
    void* ymd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get destination properties item data, count.
    copy_array_forward((void*) &dd, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dc, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Get event name part.
    get_part_name((void*) &e, dd, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME, (void*) EVENT_EVENT_GUI_STATE_CYBOL_NAME_COUNT, dc, p7, p8, p9);
    // Get mouse x part.
    get_part_name((void*) &x, dd, (void*) X_EVENT_GUI_STATE_CYBOL_NAME, (void*) X_EVENT_GUI_STATE_CYBOL_NAME_COUNT, dc, p7, p8, p9);
    // Get mouse y part.
    get_part_name((void*) &y, dd, (void*) Y_EVENT_GUI_STATE_CYBOL_NAME, (void*) Y_EVENT_GUI_STATE_CYBOL_NAME_COUNT, dc, p7, p8, p9);

    // Get event name part model item.
    copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mouse x part model item.
    copy_array_forward((void*) &xm, x, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get mouse y part model item.
    copy_array_forward((void*) &ym, y, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get event name part model item data, count.
    copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    // Get mouse x part model item data.
    copy_array_forward((void*) &xmd, xm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mouse y part model item data.
    copy_array_forward((void*) &ymd, ym, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Deserialise gui content.
    //
    // CAUTION! A break flag is NOT needed here,
    // since this is not a loop.
    // Therefore, the last argument is NULL.
    //
    deserialise_gui_content(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, emd, emc, xmd, ymd, p10, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
}

/* ACTION_GUI_DESERIALISER_SOURCE */
#endif
