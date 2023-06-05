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

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

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
 * @param p10 the sign flag
 * @param p11 the number base
 * @param p12 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p13 the decimal separator data
 * @param p14 the decimal separator count
 * @param p15 the decimal places
 * @param p16 the scientific notation flag
 * @param p17 the knowledge memory part (pointer reference)
 * @param p18 the stack memory item
 * @param p19 the internal memory data
 * @param p20 the window parent coordinates origo x
 * @param p21 the window parent coordinates origo y
 * @param p22 the format
 */
void serialise_gui_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui content.");
    //?? fwprintf(stdout, L"Debug: Serialise gui content. source model count p7: %i\n", p7);
    //?? fwprintf(stdout, L"Debug: Serialise gui content. source model count *p7: %i\n", *((int*) p7));
    //?? fwprintf(stdout, L"Debug: Serialise gui content. source properties count p9: %i\n", p9);
    //?? fwprintf(stdout, L"Debug: Serialise gui content. source properties count *p9: %i\n", *((int*) p9));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p22, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This IS a PART.
        //
        // Therefore, draw PROPERTIES FIRST and
        // only afterwards, dive into the hierarchy.
        //
        // Otherwise, inner elements would be drawn first
        // and outer elements, drawn later,
        // would overpaint them again.
        //

        // The new parent coordinates origo x and y.
        int px = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int py = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The child element coordinates origo x and y.
        int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Serialise properties.
        serialise_gui_properties(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p17, p18, p19, p20, p21, p22, (void*) &x, (void*) &y);

        // Add parent- to new parent coordinate x, y.
        calculate_integer_add((void*) &px, p20);
        calculate_integer_add((void*) &py, p21);
        // Add child- to new parent coordinate x, y.
        calculate_integer_add((void*) &px, (void*) &x);
        calculate_integer_add((void*) &py, (void*) &y);

        //?? fwprintf(stdout, L"Debug: Serialise gui part element content. child element x: %i\n", x);
        //?? fwprintf(stdout, L"Debug: Serialise gui part element content. child element y: %i\n", y);
        //?? fwprintf(stdout, L"Debug: Serialise gui part element content. new parent px: %i\n", px);
        //?? fwprintf(stdout, L"Debug: Serialise gui part element content. new parent py: %i\n", py);

        // Serialise embedded model.
        serialise_gui(p0, p1, p2, p3, p4, p5, *NULL_POINTER_STATE_CYBOI_MODEL, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, (void*) &px, (void*) &py, p22);

    } else {

        //
        // This is NOT a part, but a PRIMITIVE VALUE.
        //
        // Therefore, serialise VALUE FIRST and
        // only afterwards, draw its properties.
        //
        // The reason is that the serialised value
        // has to be handed over AS TEXT to the properties,
        // in order to be drawn correctly inside.
        //

        //
        // The text item.
        //
        // CAUTION! This local variable is used as
        // buffer to store primitive values.
        //
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate text item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Serialise embedded model into text item.
        serialise_gui(p0, p1, p2, p3, p4, p5, t, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);

        // Draw text using properties.
        serialise_gui_properties(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p17, p18, p19, p20, p21, p22, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        // Deallocate text item.
        deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}
