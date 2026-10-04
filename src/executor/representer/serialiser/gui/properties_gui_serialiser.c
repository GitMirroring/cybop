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
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the properties into gui.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the win32 device context
 * @param p6 the source model data
 * @param p7 the source model count
 * @param p8 the source properties data
 * @param p9 the source properties count
 * @param p10 the knowledge memory part (pointer reference)
 * @param p11 the stack memory item
 * @param p12 the internal memory data
 * @param p13 the window parent coordinates origo x
 * @param p14 the window parent coordinates origo y
 * @param p15 the format
 * @param p16 the child element coordinates origo x
 * @param p17 the child element coordinates origo y
 */
void serialise_gui_properties(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise gui properties.");
    //?? fwprintf(stdout, L"Debug: Serialise gui properties. Connexion p0: %i\n", p0);

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
    get_part_name((void*) &super, p8, (void*) SUPER_CYBOL_NAME, (void*) SUPER_CYBOL_NAME_COUNT, p9, p10, p11, p12);
    get_part_name((void*) &p, p8, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, p9, p10, p11, p12);
    get_part_name((void*) &s, p8, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, p9, p10, p11, p12);
    get_part_name((void*) &l, p8, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, p9, p10, p11, p12);
    get_part_name((void*) &w, p8, (void*) WINDOW_GUI_STATE_CYBOL_NAME, (void*) WINDOW_GUI_STATE_CYBOL_NAME_COUNT, p9, p10, p11, p12);

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

        get_part_name((void*) &p, supermd, (void*) POSITION_GUI_STATE_CYBOL_NAME, (void*) POSITION_GUI_STATE_CYBOL_NAME_COUNT, supermc, p10, p11, p12);
    }

    if (s == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &s, supermd, (void*) SIZE_GUI_STATE_CYBOL_NAME, (void*) SIZE_GUI_STATE_CYBOL_NAME_COUNT, supermc, p10, p11, p12);
    }

    if (l == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &l, supermd, (void*) LAYOUT_GUI_STATE_CYBOL_NAME, (void*) LAYOUT_GUI_STATE_CYBOL_NAME_COUNT, supermc, p10, p11, p12);
    }

    if (w == *NULL_POINTER_STATE_CYBOI_MODEL) {

        get_part_name((void*) &w, supermd, (void*) WINDOW_GUI_STATE_CYBOL_NAME, (void*) WINDOW_GUI_STATE_CYBOL_NAME_COUNT, supermc, p10, p11, p12);
    }

    // Get part model items.
    copy_array_forward((void*) &pm, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lm, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lp, l, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wm, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Get part model item data.
    copy_array_forward((void*) &pmd, pm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmd, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lmc, lm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpd, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &lpc, lp, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wmd, wm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Get position x, y.
    copy_array_forward((void*) &pmdx, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pmdy, pmd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);
    // Get size width, height.
    copy_array_forward((void*) &smdw, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_0_VECTOR_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smdh, smd, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DIMENSION_1_VECTOR_STATE_CYBOI_NAME);

    //?? fwprintf(stdout, L"Debug: Serialise gui properties pre pmdx: %i\n", pmdx);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties pre pmdy: %i\n", pmdy);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties pre smdw: %i\n", smdw);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties pre smdh: %i\n", smdh);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p15, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This IS a PART.
        //
        // CAUTION! Do NOT calculate the layout coordinates if
        // this is not a part, since only parts have child nodes.
        //

        //
        // Serialise layout.
        //
        // CAUTION! A layout is useful for BOTH,
        // element AND window below.
        //
        serialise_layout(p6, p7, (void*) &pmdx, (void*) &pmdy, (void*) &smdw, (void*) &smdh, wmd, lpd, lpc, p10, p11, p12, lmd, lmc);
    }

    //?? fwprintf(stdout, L"Debug: Serialise gui properties post pmdx: %i\n", pmdx);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties post pmdy: %i\n", pmdy);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties post smdw: %i\n", smdw);
    //?? fwprintf(stdout, L"Debug: Serialise gui properties post smdh: %i\n", smdh);

    //
    // Copy child element coordinates origo x, y.
    //
    // They are needed outside this function,
    // to calculate the new parent coordinates.
    //
    // CAUTION! Do this only AFTER having calculated the
    // new coordinates above, depending on the given layout.
    //
    copy_integer(p16, (void*) &pmdx);
    copy_integer(p17, (void*) &pmdy);

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Find out if this is the root window.
    compare_integer_unequal((void*) &r, wmd, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    //
    // CAUTION! The comparison of wmd for NULL IS NECESSARY,
    // since the "window" cybol property flag is OPTIONAL.
    // If this check for null were removed, then the
    // "else" branch below would ALWAYS be executed.
    //
    if ((wmd == *NULL_POINTER_STATE_CYBOI_MODEL) || (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

        //
        // This is a gui child element and NOT the root window.
        //

        // The screen coordinate x, y.
        int sx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int sy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add parent- to screen coordinate x, y.
        calculate_integer_add((void*) &sx, p13);
        calculate_integer_add((void*) &sy, p14);
        // Add child- to screen coordinate x, y.
        calculate_integer_add((void*) &sx, (void*) &pmdx);
        calculate_integer_add((void*) &sy, (void*) &pmdy);

        // Draw shape, colours, text.
        serialise_gui_component(p0, p1, p2, p3, p4, p5, p6, p7, (void*) &sx, (void*) &sy, (void*) &smdw, (void*) &smdh, p8, p9, p10, p11, p12, p15);

    } else {

        //
        // This IS the root window.
        //

        // Draw window using the operating system's window managing capabilities.
        serialise_gui_window(p0, p2, p5, (void*) &pmdx, (void*) &pmdy, (void*) &smdw, (void*) &smdh, p8, p9, p10, p11, p12);

/*??
        // The screen coordinate x, y.
        int sx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int sy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Add parent- to screen coordinate x, y.
        calculate_integer_add((void*) &sx, p13);
        calculate_integer_add((void*) &sy, p14);
        // Add child- to screen coordinate x, y.
        calculate_integer_add((void*) &sx, (void*) &pmdx);
        calculate_integer_add((void*) &sy, (void*) &pmdy);

        fwprintf(stdout, L"Debug: Serialise gui properties *p13: %i\n", *((int*) p13));
        fwprintf(stdout, L"Debug: Serialise gui properties *p14: %i\n", *((int*) p14));
        fwprintf(stdout, L"Debug: Serialise gui properties pmdx: %i\n", pmdx);
        fwprintf(stdout, L"Debug: Serialise gui properties pmdy: %i\n", pmdy);
        fwprintf(stdout, L"Debug: Serialise gui properties sx: %i\n", sx);
        fwprintf(stdout, L"Debug: Serialise gui properties sy: %i\n", sy);
        fwprintf(stdout, L"Debug: Serialise gui properties smdw: %i\n", smdw);
        fwprintf(stdout, L"Debug: Serialise gui properties smdh: %i\n", smdh);
*/

        //
        // Draw shape, colours, text.
        //
        // CAUTION! This is the root panel of the window.
        // The window itself is controlled by the window manager.
        // However, its initial properties such as the background colour
        // do have to be painted here calling a separate function.
        //
        serialise_gui_component(p0, p1, p2, p3, p4, p5, p6, p7, p13, p14, (void*) &smdw, (void*) &smdh, p8, p9, p10, p11, p12, p15);
    }
}
