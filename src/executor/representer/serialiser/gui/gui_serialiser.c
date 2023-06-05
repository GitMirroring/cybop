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
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises a part into graphical user interface (gui).
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the destination wide character text item
 * @param p7 the source model data
 * @param p8 the source model count
 * @param p9 the source properties data
 * @param p10 the source properties count
 * @param p11 the sign flag
 * @param p12 the number base
 * @param p13 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p14 the decimal separator data
 * @param p15 the decimal separator count
 * @param p16 the decimal places
 * @param p17 the scientific notation flag
 * @param p18 the knowledge memory part (pointer reference)
 * @param p19 the stack memory item
 * @param p20 the internal memory data
 * @param p21 the parent coordinates origo x
 * @param p22 the parent coordinates origo y
 * @param p23 the format
 */
void serialise_gui(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19, void* p20, void* p21, void* p22, void* p23) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // element
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p23, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // CAUTION! Do NOT call function "serialise_gui_properties" here.
            // It is called inside the "serialise_gui_part" function.
            //
            serialise_gui_part(p0, p1, p2, p3, p4, p5, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22);
        }
    }

    //
    // other formats
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Leave processing of other formats to cybol serialiser.
        serialise_cybol(p6, p7, p8, p9, p10, p11, p12, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p13, p14, p15, p16, p17, p23);
    }
}
