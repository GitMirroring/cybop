/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define X_WINDOW_SYSTEM_SERIALISER_SOURCE

/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <xcb/xcb.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/x_window_system/element_x_window_system_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source parts into the x window system.
 *
 * This means that a hierarchical knowledge model's parts
 * are drawn as rectangle or other graphical elements
 * onto the window's graphic context.
 *
 * @param p0 the internal memory data
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 */
void serialise_x_window_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise x window system.");

    // The connection.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The screen.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window.
//??    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The graphic context.
    void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window attributes.
//??    XWindowAttributes wa;

    // Get x window system internals.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNECTION_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &s, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) SCREEN_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
//??    copy_array_forward((void*) &w, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WINDOW_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &gc, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get window attributes.
//??    XGetWindowAttributes((struct _XDisplay*) d, *((int*) w), &wa);

/*??
    // The source whole size.
    void** wsn = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsnc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsns = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsa = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsac = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsas = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsm = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsmc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsms = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsd = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsdc = NULL_POINTER_STATE_CYBOI_MODEL;
    void** wsds = NULL_POINTER_STATE_CYBOI_MODEL;

    // The source whole size coordinates.
    int* wsmx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wsmy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
    int* wsmz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;

    // The original area position coordinates, set to the zero origo.
    int oapx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oapy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oapz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The original area size coordinates, initialised with whole coordinates.
    int oasx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oasy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int oasz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // The free area position coordinates, initialised with original area position coordinates.
    int fapx = oapx;
    int fapy = oapy;
    int fapz = oapz;
    // The free area size coordinates, initialised with original area position coordinates.
    int fasx = oasx;
    int fasy = oasy;
    int fasz = oasz;

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Get source whole size from properties.
        get_universal_compound_element_by_name(
            (void*) &wsn, (void*) &wsnc, (void*) &wsns,
            (void*) &wsa, (void*) &wsac, (void*) &wsas,
            (void*) &wsm, (void*) &wsmc, (void*) &wsms,
            (void*) &wsd, (void*) &wsdc, (void*) &wsds,
            p5, p6,
            (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
            p7, p8);

        // Determine source whole size coordinates.
        get((void*) &wsmx, *wsm, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        get((void*) &wsmy, *wsm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
        get((void*) &wsmz, *wsm, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

        // Set original area position coordinates, set to the zero origo.
        oapx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        oapy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        oapz = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // Set original area size coordinates, initialised with whole coordinates.
        oasx = *wsmx;
        oasy = *wsmy;
        oasz = *wsmz;

        // Set free area position coordinates, initialised with original area position coordinates.
        fapx = oapx;
        fapy = oapy;
        fapz = oapz;
        // Set free area size coordinates, initialised with original area position coordinates.
        fasx = oasx;
        fasy = oasy;
        fasz = oasz;
    }

    // The loop count.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p2 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    // Iterate through compound parts.
    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }
*/

//??        serialise_x_window_system_element(p0, p1, (void*) &j, p3, p4, d, w, gc);
        //?? TEST ONLY, DELETE LATER
        serialise_x_window_system_element(c, s, gc, p1, p2, p3, p4);

/*??
        // Increment loop count.
        j++;
    }
*/
}

/* X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
