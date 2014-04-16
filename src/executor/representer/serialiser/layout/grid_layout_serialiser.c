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

#ifndef GRID_LAYOUT_SERIALISER_SOURCE
#define GRID_LAYOUT_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../executor/representer/serialiser/layout/part_layout_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises grid layout coordinates.
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
 */
void serialise_layout_grid(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

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
    get_part_knowledge((void*) &r, p2, (void*) ROWS_GUI_STATE_CYBOL_NAME, (void*) ROWS_GUI_STATE_CYBOL_NAME_COUNT, p3, p8);
    get_part_knowledge((void*) &c, p2, (void*) COLUMNS_GUI_STATE_CYBOL_NAME, (void*) COLUMNS_GUI_STATE_CYBOL_NAME_COUNT, p3, p8);

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

        // Calculate row count.
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
    copy_integer((void*) &x, p4);
    copy_integer((void*) &y, p5);
    // Initialise current size.
    copy_integer((void*) &w, p6);
    copy_integer((void*) &h, p7);
    calculate_integer_divide((void*) &w, (void*) &cc);
    calculate_integer_divide((void*) &h, (void*) &rc);

    // Serialise layout part and all of its children.
    //
    // CAUTION! Grand children are NOT considered.
    //
    // CAUTION! A layout-dependent formula has to be applied inside,
    // for calculating the position (x, y) of child elements.
    // The formula gets selected depending on the last parametre.
    serialise_layout_part(p0, (void*) &x, (void*) &y, (void*) &w, (void*) &h, (void*) GRID_LAYOUT_STATE_CYBOI_LANGUAGE);
}

/* GRID_LAYOUT_SERIALISER_SOURCE */
#endif
