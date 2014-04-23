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
#include "../../../../executor/representer/serialiser/layout/properties_layout_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_layout(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9);

/**
 * Serialises part element content layout properties into graphical user interface (gui) coordinates.
 *
 * @param p0 the model data
 * @param p1 the model count
 * @param p2 the properties data
 * @param p3 the properties count
 * @param p4 the knowledge memory part
 */
void serialise_layout_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout part element content.");

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
    serialise_layout_properties((void*) &x, (void*) &y, (void*) &w, (void*) &h, (void*) &l, (void*) &lpd, (void*) &lpc, p2, p3, p4);

    // Serialise embedded model.
    // CAUTION! The parametres layout and
    // layout properties are SWAPPED here,
    // so that after comparison for layout,
    // the layout parametre may be omitted inside,
    // without having to change the order of other parametres.
    serialise_layout(p0, p1, (void*) &x, (void*) &y, (void*) &w, (void*) &h, (void*) &lpd, (void*) &lpc, p4, (void*) &l);
}

/* CONTENT_ELEMENT_PART_LAYOUT_SERIALISER_SOURCE */
#endif
