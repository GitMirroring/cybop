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

#ifndef PROPERTIES_CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define PROPERTIES_CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the x window system context properties.
 *
 * @param p0 the foreground colour
 * @param p1 the background colour
 * @param p2 the line width
 * @param p3 the line style
 * @param p4 the cap style
 * @param p5 the join style
 * @param p6 the fill style
 * @param p7 the fill rule
 * @param p8 the font
 * @param p9 the source properties data
 * @param p10 the source properties count
 * @param p11 the knowledge memory part
 */
void serialise_x_window_system_context_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise x window system context properties.");

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part.
    void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part.
    void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line width part.
    void* lw = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line style part.
    void* ls = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cap style part.
    void* cs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The join style part.
    void* js = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill style part.
    void* fs = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill rule part.
    void* fr = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The font part.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item.
    void* superm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item.
    void* fgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part model item.
    void* bgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line width part model item.
    void* lwm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line style part model item.
    void* lsm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cap style part model item.
    void* csm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The join style part model item.
    void* jsm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill style part model item.
    void* fsm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill rule part model item.
    void* frm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The font part model item.
    void* fm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item data, count.
    void* supermd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* supermc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item data.
    void* fgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part model item data.
    void* bgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line width part model item data.
    void* lwmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The line style part model item data.
    void* lsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cap style part model item data.
    void* csmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The join style part model item data.
    void* jsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill style part model item data.
    void* fsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill rule part model item data.
    void* frmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The font part model item data.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_knowledge((void*) &super, p6, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &fg, p4, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &bg, p4, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);
    get_part_knowledge((void*) &lw, p6, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &ls, p6, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &cs, p6, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &js, p6, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &fs, p6, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &fr, p6, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME_COUNT, p7, p8);
    get_part_knowledge((void*) &f, p4, (void*) FONT_GUI_STATE_CYBOL_NAME, (void*) FONT_GUI_STATE_CYBOL_NAME_COUNT, p5, p8);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &fg, supermd, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &bg, supermd, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (lw == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &lw, supermd, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (ls == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &ls, supermd, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (cs == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &cs, supermd, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (js == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &js, supermd, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (fs == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &fs, supermd, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (fr == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &fr, supermd, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    if (f == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &f, supermd, (void*) FONT_GUI_STATE_CYBOL_NAME, (void*) FONT_GUI_STATE_CYBOL_NAME_COUNT, supermc, p8);
    }

    // Get part model items.
    copy_array_forward((void*) &fgm, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgm, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lwm, lw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lsm, ls, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &csm, cs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &jsm, js, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fsm, fs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &frm, fr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &fgmd, fgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgmd, bgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lwmd, lwm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lsmd, lsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &csmd, csm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &jsmd, jsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fsmd, fsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &frmd, frm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Initialise destination values.
    copy_integer(p0, fgmd);
    copy_integer(p1, bgmd);
    copy_integer(p2, lwmd);
    copy_integer(p3, lsmd);
    copy_integer(p4, csmd);
    copy_integer(p5, jsmd);
    copy_integer(p6, fsmd);
    copy_integer(p7, frmd);
    copy_integer(p8, fmd);
}

/* PROPERTIES_CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
