/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_LAYOUT_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_LAYOUT_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/**
 * Serialises part element content layout properties into graphical user interface (gui) coordinates.
 *
 * @param p0 the source model data
 * @param p1 the source model count
 * @param p2 the source layout properties data
 * @param p3 the source layout properties count
 * @param p4 the source whole position x
 * @param p5 the source whole position y
 * @param p6 the source whole width
 * @param p7 the source whole height
 * @param p8 the knowledge memory part
 * @param p9 the whole layout
 */
void serialise_layout_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout part element content.");

    // The whole position x, y.
    int wx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int wy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The whole size width, height.
    int ww = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int wh = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The position x, y.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The size width, height.
    int w = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The layout.
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The layout properties data, count.
    void* lpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lpc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Append properties.
 * @param p11 the source properties data
 * @param p12 the source properties count
 * @param p13 the source whole properties data
 * @param p14 the source whole properties count
 * @param p15 the knowledge memory part
    serialise_layout_properties((void*) &wx, (void*) &wy, (void*) &ww, (void*) &wh, (void*) &x, (void*) &y, (void*) &w, (void*) &h, (void*) &l, (void*) &lpd, (void*) &lpc, spd, spc, swpd, swpc, k);

    // Serialise embedded model.
    // CAUTION! The parametres layout and
    // layout properties are SWAPPED here,
    // so that after comparison for layout,
    // the layout parametre may be omitted inside,
    // without having to change the order of other parametres.
    serialise_layout(p0, p1, p2, p3, p4, p5, p6, p7, p10, p11, (void*) &x, (void*) &y, (void*) &w, (void*) &h, (void*) &lp, (void*) &l);
}

/* CONTENT_ELEMENT_PART_LAYOUT_SERIALISER_SOURCE */
#endif
