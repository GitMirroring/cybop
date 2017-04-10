/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/serialiser/gui/properties_gui_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14);

/**
 * Serialises the part element content into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the source model data
 * @param p7 the source model count
 * @param p8 the source properties data
 * @param p9 the source properties count
 * @param p10 the knowledge memory part (pointer reference)
 * @param p11 the stack memory item
 * @param p12 the internal memory data
 * @param p13 the format
 */
void serialise_gui_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui part element content.");

fwprintf(stdout, L"TEST serialise gui part element content model count: %i\n", *((int*) p7));
fwprintf(stdout, L"TEST serialise gui part element content properties count: %i\n", *((int*) p9));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p13, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // This IS a part.
        // Therefore, draw properties first and
        // only afterwards, dive into the hierarchy.
        // Otherwise, inner elements would be drawn first
        // and outer elements, drawn later,
        // would overpaint them again.

        // Serialise properties.
        serialise_gui_properties(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        // Serialise embedded model.
        serialise_gui(p0, p1, p2, p3, p4, p5, *NULL_POINTER_STATE_CYBOI_MODEL, p6, p7, p8, p9, p10, p11, p12, p13);

    } else {

        // This is NOT a part, but a PRIMITIVE VALUE.
        // Therefore, serialise value first and
        // only afterwards, draw its properties.
        // The reason is that the serialised value
        // has to be handed over AS TEXT to the properties,
        // in order to be drawn correctly inside.

        // The text item.
        //
        // CAUTION! This local variable is used as buffer to
        // store primitive values, which get handed over to
        // function "serialise_gui_properties" below.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate text item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Serialise embedded model into text item.
        serialise_gui(p0, p1, p2, p3, p4, p5, t, p6, p7, p8, p9, p10, p11, p12, p13);

        // Draw text using properties.
        serialise_gui_properties(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

        // Deallocate text item.
        deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* CONTENT_ELEMENT_PART_GUI_SERIALISER_SOURCE */
#endif
