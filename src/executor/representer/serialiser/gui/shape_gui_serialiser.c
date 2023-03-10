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

#ifndef SHAPE_GUI_SERIALISER_SOURCE
#define SHAPE_GUI_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

//?? #include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/representer/serialiser/gui/shape/rectangle_shape_gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the shape into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the win32 device context
 * @param p5 the position x
 * @param p6 the position y
 * @param p7 the size width
 * @param p8 the size height
 * @param p9 the shape data
 * @param p10 the shape count
 */
void serialise_gui_shape(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui shape.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) ARC_SHAPE_CYBOL_MODEL, p10, (void*) ARC_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_arc(p0, p2, p3);
//??    win32: Arc(X, Y, RADIUS, START, SWEEP)
//??    xcb_poly_arc();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) BUTTON_SHAPE_CYBOL_MODEL, p10, (void*) BUTTON_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_button(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) FILLED_ARC_SHAPE_CYBOL_MODEL, p10, (void*) FILLED_ARC_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_filled_arc(p0, p2, p3);
//??    xcb_poly_fill_arc();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) FILLED_POLYGON_SHAPE_CYBOL_MODEL, p10, (void*) FILLED_POLYGON_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_filled_polygon(p0, p2, p3);
//??    xcb_fill_poly();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) FILLED_RECTANGLE_SHAPE_CYBOL_MODEL, p10, (void*) FILLED_RECTANGLE_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_filled_rectangle(p0, p2, p3);
//??    xcb_poly_fill_rectangle(c, *d, *gc, *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, &r);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) LABEL_SHAPE_CYBOL_MODEL, p10, (void*) LABEL_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_label(p0, p2, p3);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) POINT_SHAPE_CYBOL_MODEL, p10, (void*) POINT_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_point(p0, p2, p3);
//??    xcb_poly_point();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) POLYGON_SHAPE_CYBOL_MODEL, p10, (void*) POLYGON_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_polygon(p0, p2, p3);
//??    xcb_poly_line();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) RECTANGLE_SHAPE_CYBOL_MODEL, p10, (void*) RECTANGLE_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            serialise_gui_shape_rectangle(p0, p1, p2, p3, p4, p5, p6, p7, p8);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_operation((void*) &r, p9, (void*) SEGMENT_SHAPE_CYBOL_MODEL, p10, (void*) SEGMENT_SHAPE_CYBOL_MODEL_COUNT, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??            serialise_gui_shape_segment(p0, p2, p3);
//??    xcb_poly_segment();
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise gui shape. The shape is unknown.");
    }
}

/* SHAPE_GUI_SERIALISER_SOURCE */
#endif
