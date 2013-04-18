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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PROPERTIES_TUI_SERIALISER_SOURCE
#define PROPERTIES_TUI_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/vector_state_cyboi_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/tui/rectangle_tui_serialiser.c"
#include "../../../../logger/logger.c"

#ifdef WIN32
    #include "../../../../executor/representer/serialiser/win32_console/attributes_win32_console_serialiser.c"
    #include "../../../../executor/representer/serialiser/win32_console/position_win32_console_serialiser.c"
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include "../../../../executor/representer/serialiser/ansi_escape_code/attributes_ansi_escape_code_serialiser.c"
    #include "../../../../executor/representer/serialiser/ansi_escape_code/position_ansi_escape_code_serialiser.c"
#endif

/**
 * Serialises the properties into tui.
 *
 * @param p0 the destination item
 * @param p1 the destination win32 console output data
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the source whole properties data
 * @param p5 the source whole properties count
 * @param p6 the knowledge memory part
 */
void serialise_tui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui properties.");

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The position part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The size part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part.
    void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part.
    void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part.
    void* bo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hidden part.
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The inverse part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blink part.
    void* bl = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The underline part.
    void* u = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bold part.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The background part model item.
    void* bgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item.
    void* fgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part model item.
    void* bom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hidden part model item.
    void* hm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The inverse part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blink part model item.
    void* blm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The underline part model item.
    void* um = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bold part model item.
    void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The background part model item data.
    void* bgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item data.
    void* fgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part model item data, count.
    void* bomd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bomc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The hidden part model item data.
    void* hmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The inverse part model item data.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The blink part model item data.
    void* blmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The underline part model item data.
    void* umd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The bold part model item data.
    void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    get_part_knowledge((void*) &super, p2, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &p, p2, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &s, p2, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &bg, p2, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &fg, p2, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &bo, p2, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &h, p2, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &i, p2, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &bl, p2, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &u, p2, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);
    get_part_knowledge((void*) &b, p2, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p3, p6);

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

        get_part_knowledge((void*) &p, supermd, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &s, supermd, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &bg, supermd, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BACKGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &fg, supermd, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) FOREGROUND_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (bo == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &bo, supermd, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BORDER_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (h == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &h, supermd, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) HIDDEN_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (i == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &i, supermd, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) INVERSE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (bl == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &bl, supermd, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BLINK_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (u == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &u, supermd, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) UNDERLINE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    if (b == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_knowledge((void*) &b, supermd, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) BOLD_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, supermc, p6);
    }

    // Get parts from whole properties.
    get_part_knowledge((void*) &wp, p4, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p5, p6);
    get_part_knowledge((void*) &ws, p4, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_TEXT_USER_INTERFACE_CYBOL_NAME_COUNT, p5, p6);

    // Get part model items.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgm, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgm, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bom, bo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &blm, bl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model items from whole properties.
    copy_array_forward((void*) &wpm, wp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsm, ws, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgmd, bgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgmd, fgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomd, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomc, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &blmd, blm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

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

    // Serialise attributes.
#ifdef WIN32
    serialise_win32_console_attributes(p1, bgmd, fgmd, hmd, imd, blmd, umd, bmd);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    serialise_ansi_escape_code_attributes(p0, bgmd, fgmd, hmd, imd, blmd, umd, bmd);
#endif

    // Serialise rectangle border and area.
    serialise_tui_rectangle(p0, (void*) &pmdx, (void*) &smdx, (void*) &pmdy, (void*) &smdy, bomd, bomc);

    // Reset position, so that following model characters are printed at the origo.
#ifdef WIN32
    serialise_win32_console_position(p1, (void*) &pmdx, (void*) &pmdy);
#endif
#ifdef GNU_LINUX_OPERATING_SYSTEM
    serialise_ansi_escape_code_position(p0, (void*) &pmdx, (void*) &pmdy);
#endif
}

/* PROPERTIES_TUI_SERIALISER_SOURCE */
#endif
