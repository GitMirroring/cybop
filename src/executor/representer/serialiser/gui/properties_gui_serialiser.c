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

#ifndef PROPERTIES_GUI_SERIALISER_SOURCE
#define PROPERTIES_GUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/vector_state_cyboi_name.c"
#include "../../../../constant/name/cybol/state/gui/gui_state_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../executor/representer/serialiser/gui/element_gui_serialiser.c"
#include "../../../../executor/representer/serialiser/gui/window_gui_serialiser.c"
#include "../../../../executor/representer/serialiser/layout/layout_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the properties into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the win32 device context
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p9 the knowledge memory part
 */
void serialise_gui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui properties.");

fwprintf(stdout, L"TEST serialise gui properties: %i\n", p0);

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part.
    void* l = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window flag part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item.
    void* superm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item.
    void* pm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part model item.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part model, properties item.
    void* lm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window flag part model item.
    void* wm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item data, count.
    void* supermd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* supermc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part model item data.
    void* pmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part model item data.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The layout part model, properties item data, count.
    void* lmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lpd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lpc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The window flag part model item data.
    void* wmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The position part model item data x, y.
    int pmdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int pmdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The size part model item data width, height.
    int smdw = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int smdh = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_knowledge((void*) &super, p7, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p8, p9);
    get_part_knowledge((void*) &p, p7, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, p8, p9);
    get_part_knowledge((void*) &s, p7, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, p8, p9);
    get_part_knowledge((void*) &l, p7, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, p8, p9);
    get_part_knowledge((void*) &w, p7, (void*) WINDOW_GUI_STATE_CYBOL_NAME, (void*) WINDOW_GUI_STATE_CYBOL_NAME_COUNT, p8, p9);

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

        get_part_knowledge((void*) &p, supermd, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9);
    }

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &s, supermd, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9);
    }

    if (l == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &l, supermd, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9);
    }

    if (w == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &w, supermd, (void*) WINDOW_GUI_STATE_CYBOL_NAME, (void*) WINDOW_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9);
    }

    // Get part model items.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lp, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpd, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpc, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get position x, y.
    copy_array_forward((void*) &pmdx, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmdy, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size width, height.
    copy_array_forward((void*) &smdw, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smdh, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Serialise layout.
    // CAUTION! A layout is useful for both,
    // element AND window below.
    serialise_layout(p5, p6, (void*) &pmdx, (void*) &pmdy, (void*) &smdw, (void*) &smdh, lpd, lpc, p9, lmd, lmc);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Find out if this is the root window.
    compare_integer_equal((void*) &r, wmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // CAUTION! The comparison of wmd for null IS NECESSARY,
    // since the "window" cybol property flag is OPTIONAL.
    // If this check for null were removed, then the
    // "else" branch below would ALWAYS be executed.
    if ((wmd == *NULL_POINTER_STATE_CYBOI_MODEL) || (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        // This is a gui child element and NOT the root window.

        serialise_gui_element(p0, p1, p2, p3, p4, p5, p6, (void*) &pmdx, (void*) &pmdy, (void*) &smdw, (void*) &smdh, p7, p8, p9);

    } else {

        // This is the root window.

        serialise_gui_window(p0, p2, p4, (void*) &pmdx, (void*) &pmdy, (void*) &smdw, (void*) &smdh, p7, p8, p9);
    }
}

/* PROPERTIES_GUI_SERIALISER_SOURCE */
#endif
