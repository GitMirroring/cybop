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

#ifndef INITIAL_GUI_SERIALISER_SOURCE
#define INITIAL_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
//
// CAUTION! Do NOT include the "content_gui_serialiser.c" module.
// It is true, the "serialise_gui_content" function is called from here,
// but the module dependency hierarchy slightly differs and just goes top-down
// by module granularity and NOT by call hierarchy.
// Therefore, the "gui_serialiser.c" module is included here.
//
#include "../../../../executor/representer/serialiser/gui/gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Initialises the gui serialiser.
 *
 * @param p0 the destination window identification item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the sign flag
 * @param p6 the number base
 * @param p7 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p8 the decimal separator data
 * @param p9 the decimal separator count
 * @param p10 the decimal places
 * @param p11 the scientific notation flag
 * @param p12 the knowledge memory part (pointer reference)
 * @param p13 the stack memory item
 * @param p14 the internal memory data
 * @param p15 the format
 */
void serialise_gui_initial(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui initial.");
    //?? fwprintf(stdout, L"Debug: Serialise gui initial. format p15: %i\n", p15);
    //?? fwprintf(stdout, L"Debug: Serialise gui initial. format *p15: %i\n", *((int*) p15));

    //
    // Declaration.
    //

    // The destination window identification item data.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The input output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server list.
    void* sl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The server entry.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The screen.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The graphic context.
    void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The font.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The win32 device context.
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Retrieval.
    //

    // Get destination window identification item data.
    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get input output entry from internal memory.
    copy_array_forward((void*) &io, p14, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DISPLAY_INPUT_OUTPUT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    // Get server list from input output entry.
    copy_array_forward((void*) &sl, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SERVERS_INPUT_OUTPUT_STATE_CYBOI_NAME);
    //
    // Get server entry from server list by service identification (port number).
    //
    // CAUTION! The port number is relevant ONLY for SOCKET communication.
    // Therefore, the port value ZERO was assigned to the display server
    // at service startup by default.
    //
    find_list((void*) &se, sl, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) IDENTIFICATION_GENERAL_SERVER_STATE_CYBOI_NAME);

    // Retrieve connexion from server entry.
    copy_array_forward((void*) &c, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
    // Retrieve screen from server entry.
    copy_array_forward((void*) &s, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SCREEN_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
    // Retrieve graphic context from server entry.
    copy_array_forward((void*) &gc, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) GRAPHIC_CONTEXT_XCB_DISPLAY_SERVER_STATE_CYBOI_NAME);
    // Retrieve font from server entry.
    //?? copy_array_forward((void*) &f, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FONT_XCB_DISPLAY_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Retrieve win32 device context from server entry.
    copy_array_forward((void*) &dc, se, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DEVICE_CONTEXT_WIN32_DISPLAY_SERVER_STATE_CYBOI_NAME);

    serialise_gui_content(c, s, w, gc, f, dc, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p15);
}

/* INITIAL_GUI_SERIALISER_SOURCE */
#endif
