/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <string.h> // strlen
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the gui window properties.
 *
 * @param p0 the connexion
 * @param p1 the window
 * @param p2 the win32 device context
 * @param p3 the source position x
 * @param p4 the source position y
 * @param p5 the source size width
 * @param p6 the source size height
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p9 the knowledge memory part (pointer reference)
 * @param p10 the stack memory item
 * @param p11 the internal memory data
 */
void serialise_gui_window(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui window.");

    //?? fwprintf(stdout, L"Debug: Serialise gui window. Connexion p0: %i\n", p0);

    // The super part.
    void* super = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The title part.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon part.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon title part.
    void* it = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part.
    void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part.
    void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part.
    void* bo = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part.
    //?? void* wp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part.
    //?? void* ws = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item.
    void* superm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The title part model item.
    void* tm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon part model item.
    void* im = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon title part model item.
    void* itm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part model item.
    void* bgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item.
    void* fgm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part model item.
    void* bom = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part model item.
    //?? void* wpm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part model item.
    //?? void* wsm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The super part model item data, count.
    void* supermd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* supermc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The title part model item data, count.
    void* tmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* tmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon part model item data, count.
    void* imd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* imc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The icon title part model item data, count.
    void* itmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* itmc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The background part model item data.
    void* bgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The foreground part model item data.
    void* fgmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The border part model item data, count.
    void* bomd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* bomc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole position part model item data.
    //?? void* wpmd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The whole size part model item data.
    //?? void* wsmd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // The whole position part model item data x, y.
    //?? int wpmdx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //?? int wpmdy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The whole size part model item data width, height.
    //?? int wsmdw = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    //?? int wsmdh = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_name((void*) &super, p7, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    get_part_name((void*) &t, p7, (void*) TITLE_GUI_STATE_CYBOL_NAME, (void*) TITLE_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    get_part_name((void*) &i, p7, (void*) ICON_GUI_STATE_CYBOL_NAME, (void*) ICON_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    get_part_name((void*) &it, p7, (void*) ICON_TITLE_GUI_STATE_CYBOL_NAME, (void*) ICON_TITLE_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    get_part_name((void*) &bg, p7, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    get_part_name((void*) &fg, p7, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    //?? get_part_name((void*) &bo, p7, (void*) BORDER_GUI_STATE_CYBOL_NAME, (void*) BORDER_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (t == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &t, supermd, (void*) TITLE_GUI_STATE_CYBOL_NAME, (void*) TITLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    if (i == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &i, supermd, (void*) ICON_GUI_STATE_CYBOL_NAME, (void*) ICON_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    if (it == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &it, supermd, (void*) ICON_TITLE_GUI_STATE_CYBOL_NAME, (void*) ICON_TITLE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    if (bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &bg, supermd, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME, (void*) BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    if (fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &fg, supermd, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME, (void*) FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    if (bo == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //?? get_part_name((void*) &bo, supermd, (void*) BORDER_GUI_STATE_CYBOL_NAME, (void*) BORDER_GUI_STATE_CYBOL_NAME_COUNT, supermc, p9, p10, p11);
    }

    // Get parts from whole properties.
    //?? get_part_name((void*) &wp, p7, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);
    //?? get_part_name((void*) &ws, p7, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, p8, p9, p10, p11);

    // Get part model items.
    copy_array_forward((void*) &tm, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &itm, it, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgm, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgm, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bom, bo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model items from whole properties.
    //?? copy_array_forward((void*) &wpm, wp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    //?? copy_array_forward((void*) &wsm, ws, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &tmd, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &tmc, tm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imc, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &itmd, itm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &itmc, itm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgmd, bgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgmd, fgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomd, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomc, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Get part model item data from whole properties.
    //?? copy_array_forward((void*) &wpmd, wpm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    //?? copy_array_forward((void*) &wsmd, wsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get position coordinates from whole properties.
    //?? copy_array_forward((void*) &wpmdx, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    //?? copy_array_forward((void*) &wpmdy, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size coordinates from whole properties.
    //?? copy_array_forward((void*) &wsmdx, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    //?? copy_array_forward((void*) &wsmdy, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Adjust position coordinates by adding the origo (whole position).
    //?? calculate_integer_add((void*) &pmdx, (void*) &wpmdx);
    //?? calculate_integer_add((void*) &pmdy, (void*) &wpmdy);

#if defined(__linux__) || defined(__unix__)
    serialise_xcb_window(p0, p1, p3, p4, p5, p6, tmd, tmc, itmd, itmc);
#elif defined(__APPLE__) && defined(__MACH__)
    //?? TODO: Add support for Cocoa
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    serialise_win32_display_window(p2, p3, p4, p5, p6);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
