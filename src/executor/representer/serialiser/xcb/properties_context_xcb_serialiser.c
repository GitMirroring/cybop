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

#ifndef PROPERTIES_CONTEXT_XCB_SERIALISER_SOURCE
#define PROPERTIES_CONTEXT_XCB_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/state/gui/gui_state_cybol_name.c"
#include "../../../../executor/accessor/getter/part/name_part_getter.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/representer/serialiser/xcb/cap_style_xcb_serialiser.c"
#include "../../../../executor/representer/serialiser/xcb/fill_rule_xcb_serialiser.c"
#include "../../../../executor/representer/serialiser/xcb/fill_style_xcb_serialiser.c"
#include "../../../../executor/representer/serialiser/xcb/join_style_xcb_serialiser.c"
#include "../../../../executor/representer/serialiser/xcb/line_style_xcb_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the xcb context properties.
 *
 * @param p0 the foreground colour red
 * @param p1 the foreground colour green
 * @param p2 the foreground colour blue
 * @param p3 the background colour red
 * @param p4 the background colour green
 * @param p5 the background colour blue
 * @param p6 the line width
 * @param p7 the line style
 * @param p8 the cap style
 * @param p9 the join style
 * @param p10 the fill style
 * @param p11 the fill rule
 * @param p12 the font
 * @param p13 the source properties data
 * @param p14 the source properties count
 * @param p15 the knowledge memory part (pointer reference)
 * @param p16 the stack memory item
 * @param p17 the internal memory data
 */
void serialise_xcb_context_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xcb context properties.");

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
    // The line style part model item data, count.
    void* lsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* lsmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The cap style part model item data, count.
    void* csmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* csmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The join style part model item data, count.
    void* jsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* jsmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill style part model item data, count.
    void* fsmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fsmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The fill rule part model item data, count.
    void* frmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* frmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The font part model item data, count.
    void* fmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* fmc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_name((void*) &super, p13, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &fg, p13, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &bg, p13, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &lw, p13, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &ls, p13, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &cs, p13, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &js, p13, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &fs, p13, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &fr, p13, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);
    get_part_name((void*) &f, p13, (void*) FONT_GUI_STATE_CYBOL_NAME, (void*) FONT_GUI_STATE_CYBOL_NAME_COUNT, p14, p15, p16, p17);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &fg, supermd, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &bg, supermd, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (lw == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &lw, supermd, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME, (void*) LINE_WIDTH_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (ls == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &ls, supermd, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME, (void*) LINE_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (cs == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &cs, supermd, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME, (void*) CAP_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (js == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &js, supermd, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME, (void*) JOIN_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (fs == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &fs, supermd, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME, (void*) FILL_STYLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (fr == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &fr, supermd, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME, (void*) FILL_RULE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    if (f == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &f, supermd, (void*) FONT_GUI_STATE_CYBOL_NAME, (void*) FONT_GUI_STATE_CYBOL_NAME_COUNT, supermc, p15, p16, p17);
    }

    // Get part model items.
    copy_array_forward((void*) &fgm, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgm, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lwm, lw, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lsm, ls, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &csm, cs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &jsm, js, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fsm, fs, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &frm, fr, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fm, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data, count.
    copy_array_forward((void*) &fgmd, fgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgmd, bgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lwmd, lwm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lsmd, lsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lsmc, lsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &csmd, csm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &csmc, csm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &jsmd, jsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &jsmc, jsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fsmd, fsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fsmc, fsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &frmd, frm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &frmc, frm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmd, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fmc, fm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Set foreground red, green, blue.
    copy_array_forward(p0, fgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward(p1, fgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward(p2, fgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME);
    // Set background red, green, blue.
    copy_array_forward(p3, bgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward(p4, bgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward(p5, bgmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_2_VECTOR_STATE_CYBOI_NAME);
    // Set further destination values.
    copy_integer(p6, lwmd);
    serialise_xcb_line_style(p7, lsmd, lsmc);
    serialise_xcb_cap_style(p8, csmd, csmc);
    serialise_xcb_join_style(p9, jsmd, jsmc);
    serialise_xcb_fill_style(p10, fsmd, fsmc);
    serialise_xcb_fill_rule(p11, frmd, frmc);

    if (fmd != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A valid font was given.
        //

        // Encode font name wide character data into multibyte character item.
        encode_utf_8(p12, fmd, fmc);

    } else {

        //
        // No valid font was given.
        //

        //
        // Encode font name wide character data into multibyte character item.
        //
        // CAUTION! Use "7x13" as default font of the x window system platform.
        // This IS NECESSARY, since the graphic context expects a valid value,
        // EVEN IF no text is to be printed on screen, e.g. just an empty rectangle.
        //
        encode_utf_8(p12, (void*) L"7x13", (void*) NUMBER_4_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* PROPERTIES_CONTEXT_XCB_SERIALISER_SOURCE */
#endif
