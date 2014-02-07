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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GRID_LAYOUT_SERIALISER_SOURCE
#define GRID_LAYOUT_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/layout/part_layout_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises grid layout coordinates.
 *
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 * @param p8 the knowledge memory part
 * @param p9 the whole position x
 * @param p10 the whole position y
 * @param p11 the whole width
 * @param p12 the whole height
 * @param p12 the whole layout properties
 */
void serialise_layout_grid(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise layout grid.");

    //
    // CAUTION! Using a "super" property does NOT make sense here,
    // since these properties are CONSTRAINTS (meta data)
    // of the "layout" property.
    //

    // The rows part.
    void* r = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The columns part.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The rows part model item.
    void* rm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The columns part model item.
    void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The rows part model item data.
    void* rmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The columns part model item data.
    void* cmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_knowledge((void*) &r, p4, (void*) ROWS_GUI_STATE_CYBOL_NAME, (void*) ROWS_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &c, p4, (void*) COLUMNS_GUI_STATE_CYBOL_NAME, (void*) COLUMNS_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);

    // Get part model items.
    copy_array_forward((void*) &rm, r, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &cm, c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &rmd, rm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &cmd, cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The row count.
    int rc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The column count.
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int cr = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_greater((void*) &cr, rmd, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (cr != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Calculate column count.
        // cc = (source_model_count + *rmd - 1) / *rmd;
        copy_integer((void*) &cc, source_model_count);
        calculate_integer_add((void*) &cc, rmd);
        calculate_integer_subtract((void*) &cc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_divide((void*) &cc, rmd);

    } else {

        // Calculate column count.
        // rc = (source_model_count + *cmd - 1) / *cmd;
        copy_integer((void*) &rc, source_model_count);
        calculate_integer_add((void*) &rc, cmd);
        calculate_integer_subtract((void*) &rc, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
        calculate_integer_divide((void*) &rc, cmd);
    }

    // The current position (x, y).
    // CAUTION! They are TEMPORARY and get
    // MANIPULATED inside the called function.
    int x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The current size (width, height).
    // CAUTION! They are TEMPORARY and get
    // MANIPULATED inside the called function.
    int w = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Initialise current position.
    copy_integer((void*) &x, whole_x);
    copy_integer((void*) &y, whole_y);
    // Initialise current size.
    copy_integer((void*) &w, whole_width);
    copy_integer((void*) &h, whole_height);
    calculate_integer_divide((void*) &w, (void*) &cc);
    calculate_integer_divide((void*) &h, (void*) &rc);

    //?? TODO: Hand over function pointer to manipulate position and size?
    // The advantage is, that "serialise_layout_part" and other looping
    // functions would not have to be copied into redundant source code.
    // This is a form of "callback".
    serialise_layout_part(p0, p1, p2, p3, p4, (void*) &x, (void*) &y, (void*) &w, (void*) &h, &FUNCTION_POINTER);
}

/* GRID_LAYOUT_SERIALISER_SOURCE */
#endif
