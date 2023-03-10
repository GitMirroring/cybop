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

#ifndef PROPERTIES_TUI_SERIALISER_SOURCE
#define PROPERTIES_TUI_SERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../../executor/representer/serialiser/tui/origo_tui_serialiser.c"
#include "../../../../executor/representer/serialiser/tui/rectangle_tui_serialiser.c"
#include "../../../../logger/logger.c"

#if defined(__linux__) || defined(__unix__)
    #include "../../../../executor/representer/serialiser/ansi_escape_code/attributes_ansi_escape_code_serialiser.c"
#elif defined(__APPLE__) && defined(__MACH__)
    #include "../../../../executor/representer/serialiser/ansi_escape_code/attributes_ansi_escape_code_serialiser.c"
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include "../../../../executor/representer/serialiser/win32_console/attributes_win32_console_serialiser.c"
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/**
 * Serialises the properties into tui.
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the source properties data
 * @param p3 the source properties count
 * @param p4 the source whole properties data
 * @param p5 the source whole properties count
 * @param p6 the knowledge memory part (pointer reference)
 * @param p7 the stack memory item
 * @param p8 the internal memory data
 * @param p9 the positioning flag
 */
void serialise_tui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui properties.");
    //?? fwprintf(stdout, L"Debug: Serialise tui properties. p0: %i\n", p0);

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
    // The bold part (relating to foreground/text).
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The intense part (relating to background).
    void* in = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The intense part model item.
    void* inm = *NULL_POINTER_STATE_CYBOI_MODEL;
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
    // The intense part model item data.
    void* inmd = *NULL_POINTER_STATE_CYBOI_MODEL;
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

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Get parts.
    get_part_name((void*) &super, p2, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &p, p2, (void*) POSITION_TUI_STATE_CYBOL_NAME, (void*) POSITION_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &s, p2, (void*) SIZE_TUI_STATE_CYBOL_NAME, (void*) SIZE_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &bg, p2, (void*) BACKGROUND_TUI_STATE_CYBOL_NAME, (void*) BACKGROUND_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &fg, p2, (void*) FOREGROUND_TUI_STATE_CYBOL_NAME, (void*) FOREGROUND_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &bo, p2, (void*) BORDER_TUI_STATE_CYBOL_NAME, (void*) BORDER_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &h, p2, (void*) HIDDEN_TUI_STATE_CYBOL_NAME, (void*) HIDDEN_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &i, p2, (void*) INVERSE_TUI_STATE_CYBOL_NAME, (void*) INVERSE_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &bl, p2, (void*) BLINK_TUI_STATE_CYBOL_NAME, (void*) BLINK_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &u, p2, (void*) UNDERLINE_TUI_STATE_CYBOL_NAME, (void*) UNDERLINE_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &b, p2, (void*) BOLD_TUI_STATE_CYBOL_NAME, (void*) BOLD_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);
    get_part_name((void*) &in, p2, (void*) INTENSE_TUI_STATE_CYBOL_NAME, (void*) INTENSE_TUI_STATE_CYBOL_NAME_COUNT, p3, p6, p7, p8);

    // Get super part model item.
    copy_array_forward((void*) &superm, super, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get super part model item data, count.
    copy_array_forward((void*) &supermd, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &supermc, superm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // If a standard property does NOT exist (and ONLY then),
    // the default property value of the super part is used.
    //

    if (p == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &p, supermd, (void*) POSITION_TUI_STATE_CYBOL_NAME, (void*) POSITION_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &s, supermd, (void*) SIZE_TUI_STATE_CYBOL_NAME, (void*) SIZE_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (bg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &bg, supermd, (void*) BACKGROUND_TUI_STATE_CYBOL_NAME, (void*) BACKGROUND_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (fg == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &fg, supermd, (void*) FOREGROUND_TUI_STATE_CYBOL_NAME, (void*) FOREGROUND_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (bo == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &bo, supermd, (void*) BORDER_TUI_STATE_CYBOL_NAME, (void*) BORDER_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (h == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &h, supermd, (void*) HIDDEN_TUI_STATE_CYBOL_NAME, (void*) HIDDEN_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (i == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &i, supermd, (void*) INVERSE_TUI_STATE_CYBOL_NAME, (void*) INVERSE_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (bl == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &bl, supermd, (void*) BLINK_TUI_STATE_CYBOL_NAME, (void*) BLINK_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (u == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &u, supermd, (void*) UNDERLINE_TUI_STATE_CYBOL_NAME, (void*) UNDERLINE_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (b == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &b, supermd, (void*) BOLD_TUI_STATE_CYBOL_NAME, (void*) BOLD_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    if (in == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &in, supermd, (void*) INTENSE_TUI_STATE_CYBOL_NAME, (void*) INTENSE_TUI_STATE_CYBOL_NAME_COUNT, supermc, p6, p7, p8);
    }

    // Get parts from whole properties.
    get_part_name((void*) &wp, p4, (void*) POSITION_TUI_STATE_CYBOL_NAME, (void*) POSITION_TUI_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);
    get_part_name((void*) &ws, p4, (void*) SIZE_TUI_STATE_CYBOL_NAME, (void*) SIZE_TUI_STATE_CYBOL_NAME_COUNT, p5, p6, p7, p8);

    // Get part model items.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgm, bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgm, fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bom, bo, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &hm, h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &im, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &blm, bl, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &um, u, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &inm, in, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model items from whole properties.
    copy_array_forward((void*) &wpm, wp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsm, ws, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bgmd, bgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &fgmd, fgm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomd, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bomc, bom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &hmd, hm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &imd, im, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &blmd, blm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &umd, um, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &inmd, inm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get part model item data from whole properties.
    copy_array_forward((void*) &wpmd, wpm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsmd, wsm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get position coordinates.
    copy_array_forward((void*) &pmdx, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmdy, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size coordinates.
    copy_array_forward((void*) &smdx, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smdy, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Get position coordinates from whole properties.
    copy_array_forward((void*) &wpmdx, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wpmdy, wpmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size coordinates from whole properties.
    copy_array_forward((void*) &wsmdx, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wsmdy, wsmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    // Adjust position coordinates by adding the origo (whole position).
    calculate_integer_add((void*) &pmdx, (void*) &wpmdx);
    calculate_integer_add((void*) &pmdy, (void*) &wpmdy);

    // Serialise attributes.
#if defined(__linux__) || defined(__unix__)
    serialise_ansi_escape_code_attributes(p0, bgmd, fgmd, hmd, imd, blmd, umd, bmd);
#elif defined(__APPLE__) && defined(__MACH__)
    serialise_ansi_escape_code_attributes(p0, bgmd, fgmd, hmd, imd, blmd, umd, bmd);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    serialise_win32_console_attributes(p1, bgmd, fgmd, hmd, imd, blmd, umd, bmd, inmd);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

    // Serialise rectangle border and area.
    serialise_tui_rectangle(p0, p1, (void*) &pmdx, (void*) &smdx, (void*) &pmdy, (void*) &smdy, bomd, bomc);

/*??
    fwprintf(stdout, L"Debug: Serialise tui properties. pmdx: %i\n", pmdx);
    fwprintf(stdout, L"Debug: Serialise tui properties. pmdy: %i\n", pmdy);
    fwprintf(stdout, L"Debug: Serialise tui properties. smdx: %i\n", smdx);
    fwprintf(stdout, L"Debug: Serialise tui properties. smdy: %i\n", smdy);
    fwprintf(stdout, L"Debug: Serialise tui properties. wpmdx: %i\n", wpmdx);
    fwprintf(stdout, L"Debug: Serialise tui properties. wpmdy: %i\n", wpmdy);
    fwprintf(stdout, L"\n");
*/

    compare_integer_unequal((void*) &r, p9, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The positioning flag IS set.
        //

        //
        // When printing a simple line as terminal output, then the cursor is
        // expected to stay where it is and be NOT repositioned into the
        // origin of coordinates (origo).
        //
        // When using a complete text user interface (tui) taking up the
        // whole screen space, however, positioning the cursor IS necessary.
        //
        // CAUTION! This function call is important for two reasons:
        //
        // 1 Reset cursor position, so that following EMBEDDED
        //   model characters are printed at the origo.
        //
        // 2 Position the cursor correctly for ZERO-size models.
        //   Such positioning is necessary for instance to
        //   place the cursor at a special input field.
        //   The "serialise_*_character" functions are NOT
        //   achieving this, since loops won't run with zero count.
        //
        serialise_tui_origo(p0, p1, (void*) &pmdx, (void*) &pmdy);
    }
}

/* PROPERTIES_TUI_SERIALISER_SOURCE */
#endif
