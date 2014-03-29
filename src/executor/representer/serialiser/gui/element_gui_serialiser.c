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

#ifndef ELEMENT_GUI_SERIALISER_SOURCE
#define ELEMENT_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/vector_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/gui/gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/gui/context_gui_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the gui element properties.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the win32 device context
 * @param p5 the source properties data
 * @param p6 the source properties count
 * @param p7 the source whole properties data
 * @param p8 the source whole properties count
 * @param p9 the knowledge memory part
 */
void serialise_gui_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui element.");

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part.
    void* sh = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part.
    void* wp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part.
    void* ws = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item.
    void* superm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part model item.
    void* shm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part model item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part model item.
    void* wpm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part model item.
    void* wsm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item data, count.
    void* supermd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* supermc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The shape part model item data.
    void* shmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part model item data, count.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part model item data.
    void* wpmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part model item data.
    void* wsmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The position part model item data coordinates.
    int pmdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int pmdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The size part model item data coordinates.
    int smdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int smdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The whole position part model item data coordinates.
    int wpmdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int wpmdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The whole size part model item data coordinates.
    int wsmdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int wsmdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_knowledge((void*) &super, p4, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &p, p4, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &s, p4, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &sh, p4, (void*) SHAPE_GUI_STATE_CYBOL_NAME, (void*) SHAPE_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &l, p4, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (p == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &p, supermd, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &s, supermd, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (sh == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &sh, supermd, (void*) SHAPE_GUI_STATE_CYBOL_NAME, (void*) SHAPE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (l == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &l, supermd, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    // Get parts from whole properties.
    get_part_knowledge((void*) &wp, p6, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &ws, p6, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);

    // Get part model items.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &shm, sh, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model items from whole properties.
    copy_array_forward((void*) &wpm, wp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsm, ws, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &shmd, shm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Get part model item data from whole properties.
    copy_array_forward((void*) &wpmd, wpm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsmd, wsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get position coordinates.
    copy_array_forward((void*) &pmdx, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmdy, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size coordinates.
    copy_array_forward((void*) &smdx, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smdy, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Get position coordinates from whole properties.
    copy_array_forward((void*) &wpmdx, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wpmdy, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size coordinates from whole properties.
    copy_array_forward((void*) &wsmdx, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsmdy, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Adjust position coordinates by adding the origo (whole position).
    calculate_integer_add((void*) &pmdx, (void*) &wpmdx);
    calculate_integer_add((void*) &pmdy, (void*) &wpmdy);

    // Serialise context.
    serialise_gui_context(p0, p1, p2, p3, p4, p5, p6, p9);

    // Serialise shape.
    serialise_gui_shape(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, shmd);

    // Draw text.
    // CAUTION! This has to be done for ALL shapes.
    // A text is NOT treated as shape itself,
    // but may instead be drawn into the shape.
    xcb_image_text_8(c, strlen("TEST"), *d, *gc, *x + 20, *y + 20, "TEST");

    // Close font.
    xcb_close_font(c, f);
}

/* ELEMENT_GUI_SERIALISER_SOURCE */
#endif
