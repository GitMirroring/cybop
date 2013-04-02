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

#ifndef ELEMENT_X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define ELEMENT_X_WINDOW_SYSTEM_SERIALISER_SOURCE

#include <xcb/xcb.h>

/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <X11/Xlib.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the source part into the x window system.
 *
 * @param p0 the connection
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 */
void serialise_x_window_system_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* gc = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* w = (int*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                xcb_screen_t* s = (xcb_screen_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    xcb_connection_t* c = (xcb_connection_t*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise x window system element.");

                    // Use xcb type.
                    xcb_window_t window = *w;
                    // Use xcb type.
                    xcb_gcontext_t gcontext = *gc;

                    //
                    // Adjust value mask.
                    //
                    // The valuemask parameter could take any combination
                    // of these masks from the xcbgct enumeration:
                    //
                    // XCB_GC_FUNCTION
                    // XCB_GC_PLANE_MASK
                    // XCB_GC_FOREGROUND
                    // XCB_GC_BACKGROUND
                    // XCB_GC_LINE_WIDTH
                    // XCB_GC_LINE_STYLE
                    // XCB_GC_CAP_STYLE
                    // XCB_GC_JOIN_STYLE
                    // XCB_GC_FILL_STYLE
                    // XCB_GC_FILL_RULE
                    // XCB_GC_TILE
                    // XCB_GC_STIPPLE
                    // XCB_GC_TILE_STIPPLE_ORIGIN_X
                    // XCB_GC_TILE_STIPPLE_ORIGIN_Y
                    // XCB_GC_FONT
                    // XCB_GC_SUBWINDOW_MODE
                    // XCB_GC_GRAPHICS_EXPOSURES
                    // XCB_GC_CLIP_ORIGIN_X
                    // XCB_GC_CLIP_ORIGIN_Y
                    // XCB_GC_CLIP_MASK
                    // XCB_GC_DASH_OFFSET
                    // XCB_GC_DASH_LIST
                    // XCB_GC_ARC_MODE
                    //
                    // CAUTION! It is possible to set several attributes
                    // at the same time by OR'ing these values in valuemask.
                    //
                    // Example:
                    // Set the attributes of a font and the color
                    // which will be used to display a string.
                    //
                    uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;

                    // Adjust value mask values.
                    //
                    // CAUTION! The valuelist has to be an array which
                    // lists the value for the respective attributes.
                    // These values must be in the same order
                    // as masks listed above.
                    uint32_t values[] = { s->black_pixel, 0 };

                    // TEST: Create black (foreground) graphic context.
                    xcb_gcontext_t foreground = xcb_generate_id(c);
                    xcb_create_gc(c, foreground, window, mask, values);

/*??
                    // Change graphic context.
                    xcb_change_gc(c, // the xcb connection
                        gcontext, // the graphic context
                        mask, // value mask specifying components of the graphic context that have to be set
                        values); // value as specified by value mask
*/

                    // Draw source element on graphic context.
                    //?? TODO: ...

                    // TEST: Geometric objects.
                    xcb_point_t points[] = {
                        { 10, 10 },
                        { 10, 20 },
                        { 20, 10 },
                        { 20, 20 }};

                    xcb_point_t polyline[] = {
                        { 50, 10 },
                        { 5, 20 }, // rest of points are relative
                        { 25, -20 },
                        { 10, 10 }};

                    xcb_segment_t segments[] = {
                        { 100, 10, 140, 30 },
                        { 110, 25, 130, 60 }};

                    xcb_rectangle_t rectangles[] = {
                        { 10, 50, 40, 20 },
                        { 80, 50, 10, 40 }};

                    xcb_arc_t arcs[] = {
                        { 10, 100, 60, 40, 0, 90 << 6 },
                        { 90, 100, 55, 40, 0, 270 << 6 }};

                    // Draw points.
                    xcb_poly_point(c, XCB_COORD_MODE_ORIGIN, window, foreground, 4, points);

                    // Draw polygonal line.
                    xcb_poly_line(c, XCB_COORD_MODE_PREVIOUS, window, foreground, 4, polyline);

                    // Draw segements.
                    xcb_poly_segment(c, window, foreground, 2, segments);

                    // Draw rectangles.
                    xcb_poly_rectangle(c, window, foreground, 2, rectangles);

                    // Draw arcs.
                    xcb_poly_arc(c, window, foreground, 2, arcs);

/*??
                    // The source part name, type, model, properties.
                    void** n = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** nc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** a = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** as = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** m = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** mc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** d = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** dc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part layout name, type, model, properties.
                    void** ln = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** la = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** las = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ld = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ldc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** lds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part cell name, type, model, properties.
                    void** cn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ca = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** cds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part position name, type, model, properties.
                    void** pn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pa = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** pds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part shape name, type, model, properties.
                    void** shn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sha = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** shds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part size name, type, model, properties.
                    void** sn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** snc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sa = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** smc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sd = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** sds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part title name, type, model, properties.
                    void** tn = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tnc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tns = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ta = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tas = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tm = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tmc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tms = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** td = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tdc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** tds = NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part icon name, type, model, properties.
                    void** in = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** inc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ins = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ia = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** iac = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ias = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** im = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** imc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ims = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** id = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** idc = NULL_POINTER_STATE_CYBOI_MODEL;
                    void** ids = NULL_POINTER_STATE_CYBOI_MODEL;

                    // The terminated title.
                    void* tt = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* ttc = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* tts = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The terminated icon name.
                    void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* tic = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* tis = *NULL_POINTER_STATE_CYBOI_MODEL;

                    // The source part position coordinates.
                    int* pmx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
                    int* pmy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
                    int* pmz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The source part size coordinates.
                    int* smx = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
                    int* smy = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;
                    int* smz = (int*) *NULL_POINTER_STATE_CYBOI_MODEL;

                    // Get source part at index j.
                    get_compound_element_by_index(p3, p4, (void*) &j,
                        (void*) &n, (void*) &nc, (void*) &ns,
                        (void*) &a, (void*) &ac, (void*) &as,
                        (void*) &m, (void*) &mc, (void*) &ms,
                        (void*) &d, (void*) &dc, (void*) &ds);

                    // Get source part layout from properties.
                    get_universal_compound_element_by_name(
                        (void*) &ln, (void*) &lnc, (void*) &lns,
                        (void*) &la, (void*) &lac, (void*) &las,
                        (void*) &lm, (void*) &lmc, (void*) &lms,
                        (void*) &ld, (void*) &ldc, (void*) &lds,
                        *d, *dc,
                        (void*) LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) LAYOUT_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p7, p8);
                    // Get source part cell from properties.
                    get_universal_compound_element_by_name(
                        (void*) &cn, (void*) &cnc, (void*) &cns,
                        (void*) &ca, (void*) &cac, (void*) &cas,
                        (void*) &cm, (void*) &cmc, (void*) &cms,
                        (void*) &cd, (void*) &cdc, (void*) &cds,
                        *d, *dc,
                        (void*) CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) CELL_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p7, p8);
                    // Get source part position from properties.
                    get_universal_compound_element_by_name(
                        (void*) &pn, (void*) &pnc, (void*) &pns,
                        (void*) &pa, (void*) &pac, (void*) &pas,
                        (void*) &pm, (void*) &pmc, (void*) &pms,
                        (void*) &pd, (void*) &pdc, (void*) &pds,
                        *d, *dc,
                        (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) POSITION_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p7, p8);
                    // Get source part size from properties.
                    get_universal_compound_element_by_name(
                        (void*) &sn, (void*) &snc, (void*) &sns,
                        (void*) &sa, (void*) &sac, (void*) &sas,
                        (void*) &sm, (void*) &smc, (void*) &sms,
                        (void*) &sd, (void*) &sdc, (void*) &sds,
                        *d, *dc,
                        (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) SIZE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                        p7, p8);

                    // Get source part position coordinates.
                    get((void*) &pmx, *pm, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    get((void*) &pmy, *pm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    get((void*) &pmz, *pm, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    // Get source part size coordinates.
                    get((void*) &smx, *sm, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    get((void*) &smy, *sm, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    get((void*) &smz, *sm, (void*) NUMBER_2_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

/*??
                fwprintf(stdout, L"layout: %s\n", *lm);
                fwprintf(stdout, L"layout count: %i\n", *((int*) *lmc));
*/

/*??
                    compare_all_array((void*) &r, *lm, (void*) ROOT_LAYOUT_CYBOL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *lmc, (void*) ROOT_LAYOUT_CYBOL_MODEL_COUNT);

                    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // The source part is no root window.
                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"This is not a root window.");

                        // Calculate coordinates according to given layout.
/*??
                        serialise_x_window_system_layout(*pmx, *pmy, *pmz, *smx, *smy, *smz,
                            &fapx, &fapy, &fapz, &fasx, &fasy, &fasz,
                            &oapx, &oapy, &oapz, &oasx, &oasy, &oasz,
                            *cm, *cmc, *lm, *lmc);
*/

                        // Draw graphical element using given coordinates.
                //??        XDrawRectangle(*di, **w, *gc, *pmx, *pmy, *smx - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL, *smy - *NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
                        //?? TEST. Remove later.
                //??        XDrawRectangle((struct _XDisplay*) p5, *((int*) p6), (struct _XGC*) p7, *NUMBER_200_INTEGER_STATE_CYBOI_MODEL, *NUMBER_200_INTEGER_STATE_CYBOI_MODEL, *NUMBER_600_INTEGER_STATE_CYBOI_MODEL, *NUMBER_400_INTEGER_STATE_CYBOI_MODEL);

/*??
                        // Reset comparison result.
                        r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                        compare_integer_equal((void*) &r, *a, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

                        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                            // The terminated text item.
                            void* text = *NULL_POINTER_STATE_CYBOI_MODEL;
                            // The terminated text item data, count.
                            void* textd = *NULL_POINTER_STATE_CYBOI_MODEL;
                            void* textc = *NULL_POINTER_STATE_CYBOI_MODEL;

                            // Allocate terminated text item.
                            // CAUTION! Due to memory allocation handling, the size MUST NOT
                            // be negative or zero, but have at least a value of ONE.
                            allocate_item((void*) &text, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                            // Get terminated text item data, count.
                            copy_array_forward((void*) &textd, text, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                            copy_array_forward((void*) &textc, text, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                            // Encode wide character name into text, which is a multibyte character array.
                            encode_utf_8(text, *m, *mc);

                            // Append null termination character.
                            append_item_element(text, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                            //?? TODO: Create "text" as 2byte character array,
                            //?? since the xlib C library expects it that way.
                            //?? Introduce new array modules with functions for a 2byte character array!

                            // Draw the text (character vector/ string).
                            //
                            // CAUTION! The Xlib C Library offers a function "XDrawString16"
                            // to draw 2byte characters in a given drawable.
                            // However, standard utf-8 encoded characters are used here.
                            XDrawString(*di, **w, *gc, *pmx, *pmy + *NUMBER_20_INTEGER_STATE_CYBOI_MODEL, textd, *((int*) textc));

                            // Deallocate terminated text item.
                            deallocate_item((void*) &text, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                            /*
                            In the conventional 'XFontStruct' model, an X client opens
                            a font using 'XLoadQueryFont()', draws a string using
                            'XDrawString()', and closes the font using 'XFreeFont()'.
                            On the other hand, in the internationalised 'XFontSet'
                            model, an X client opens a font using 'XCreateFontSet()',
                            draws a string using 'XmbDrawString()', and closes the font
                            using 'XFreeFontSet()'.

                            Following is a concise list of substitutions:
                            - 'XFontStruct' -> 'XFontSet'
                            - 'XLoadQueryFont()' -> 'XCreateFontSet()'
                            - both of 'XDrawString()' and 'XDrawString16'
                                -> either of 'XmbDrawString()' or 'XwcDrawString()'
                            - both of 'XDrawImageString()' and 'XDrawImageString16'
                                -> either of 'XmbDrawImageString()' or 'XwcDrawImageString()'

                            Note that 'XFontStruct' is usually used as a pointer,
                            while 'XFontSet' itself is a pointer.

                            Some people (ISO-8859-1-language speakers) may think that
                            'XFontSet'-related functions are not 8-bit clean. This is wrong.
                            'XFontSet'-related functions work according to 'LC_CTYPE' locale.
                            The default LC_CTYPE locale uses ASCII. Thus, if a user doesn't
                            set the 'LANG', 'LC_CTYPE', nor 'LC_ALL' environmental variable,
                            'XFontSet'-related functions will use ASCII, i.e. are not 8-bit clean.
                            The user has to set the 'LANG', 'LC_CTYPE', or 'LC_ALL'
                            environmental variable properly (for example, 'LANG=en_US').

                            The upstream developers of X clients sometimes hate to
                            enforce users to set such environmental variables.
                            In such a case, The X clients should have two ways to
                            output text, i.e. the 'XFontStruct'-related conventional
                            way and the 'XFontSet'-related internationalized way.
                            If 'setlocale()' returns 'NULL', '"C"', or '"POSIX"', one
                            should use the 'XFontStruct' way, otherwise the 'XFontSet' way.
                            The author implemented this algorithm to a few window managers

                            [1] Though UTF-8 is an encoding with single CCS, the current
                            version of XFree86 (4.0.1) needs multiple fonts to handle UTF-8.
                            [2] All users will have to set LANG properly when UTF-8 will become popular.
*/

/*??
                            //?? TODO: Move these before the coordinate calculation,
                            //?? in order to adapt the size of the drawn rectangle.

                            // Find text width in pixels, using the given font.
                            // The XTextWidth() function is used to "predict" the width
                            // of a given text string, as it will be drawn using a
                            // given font. This may be used to determine where to draw
                            // the left end of the string so it will look like it's
                            // occupying the middle of the window, for example.
                            int tw = XTextWidth(f, text, wcslen(text));

                            // Find font height.
                            // A font has two attributes named "ascent" and "descent",
                            // used to specify the height of the font. Basically, a
                            // font's characters are drawn relative to some imaginary
                            // horizontal line. Part of a character is drawn above this
                            // line, and part of it is drawn below it. The highest
                            // letter is drawn at most "font->ascent" pixels above the
                            // line, while the letter with the lowest part is drawn at
                            // most "font->descent" pixels below that line. Thus, the
                            // sum of these two numbers determines the height of the font.
                            int fh = f->ascent + f->descent;
*/
/*??
                        }

/*??
                        //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.Datei.name, wcslen(Anwendung.menu_bar1.Datei.name));
                        //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, str_test, wcslen(str_test));
                        //XDrawImageString (e.xexpose.display, e.xexpose.window, gc, 50, 50, Anwendung.menu_bar1.menu1.name, wcslen(Anwendung.menu_bar1.menu1.name));

                        indent_x = 0;
                        indent_y = 0;
                        indent_menu_item_x = 0;

                        for (count_menu=0;count_menu<5;count_menu++) {

                            if (wcslen(Anwendung.menu_bar1.menus[count_menu].name)>0) {

                                XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 16, Anwendung.menu_bar1.menus[count_menu].name, wcslen(Anwendung.menu_bar1.menus[count_menu].name));

                                for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {
                                    if ((wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                    indent_menu_item_x = (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                    }
                                }

                                for (count_item=0; ((count_item<9) && (Anwendung.menu_bar1.menus[count_menu].angeklickt==1)); count_item++) {

                                    if (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)>0) {

                                        indent_y = indent_y + 17;
                                        //if ((wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6 > indent_menu_item_x) {
                                        //  XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu_border_bottom, indent_menu_item_x, 20 + (count_item*17), (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6, 19);
                                        //  indent_menu_item_x = (wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name)*6)+6;
                                        //
                                        //}
                                        //XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (5+indent_x), 20 + (count_item*17), (5+indent_x+50), 19);
                                        XFillRectangle (e.xexpose.display, e.xexpose.window, gc_menu, (3+indent_x), 20 + (count_item*17), indent_menu_item_x, 19);
                                        XDrawImageString (e.xexpose.display, e.xexpose.window, gc_menu_font, (5+indent_x), 33 + (count_item*17), Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name, wcslen(Anwendung.menu_bar1.menus[count_menu].menu_items[count_item].name));
                                    }
                                }

                                if (Anwendung.menu_bar1.menus[count_menu].angeklickt==1) {

                                    XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x), (21+indent_y), (3+indent_x+indent_menu_item_x), (21+indent_y));
                                    XDrawLine(*di, **w, gc_menu_border_bottom, (3+indent_x+indent_menu_item_x), 20, (3+indent_x+indent_menu_item_x), (21+indent_y));
                                    XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x+indent_menu_item_x), 19);
                                    XDrawLine(*di, **w, gc_menu_border_top, (3+indent_x), 19, (3+indent_x), (20+indent_y));
                                }

                                indent_x = indent_x + (wcslen(Anwendung.menu_bar1.menus[count_menu].name) * 6) + 10;
                            }
                        }
*/

/*??
                    } else {

                        // The source part is a root window.
                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"This is a root window.");

                        // Move window to new position coordinates for part.
                        XMoveWindow(*di, **w, *pmx, *pmy);
                        // Resize window to new size coordinates for part.
                        XResizeWindow(*di, **w, *smx, *smy);

                        // Get source part title from properties.
                        get_universal_compound_element_by_name(
                            (void*) &tn, (void*) &tnc, (void*) &tns,
                            (void*) &ta, (void*) &tac, (void*) &tas,
                            (void*) &tm, (void*) &tmc, (void*) &tms,
                            (void*) &td, (void*) &tdc, (void*) &tds,
                            *d, *dc,
                            (void*) TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) TITLE_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            p7, p8);
                        // Get source part icon from properties.
                        get_universal_compound_element_by_name(
                            (void*) &in, (void*) &inc, (void*) &ins,
                            (void*) &ia, (void*) &iac, (void*) &ias,
                            (void*) &im, (void*) &imc, (void*) &ims,
                            (void*) &id, (void*) &idc, (void*) &ids,
                            *d, *dc,
                            (void*) ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME, (void*) ICON_GRAPHICAL_USER_INTERFACE_CYBOL_NAME_COUNT,
                            p7, p8);

                        // The terminated title.
                        tt = *NULL_POINTER_STATE_CYBOI_MODEL;
                        ttc = *NULL_POINTER_STATE_CYBOI_MODEL;
                        tts = *NULL_POINTER_STATE_CYBOI_MODEL;
                        // The terminated icon name.
                        ti = *NULL_POINTER_STATE_CYBOI_MODEL;
                        tic = *NULL_POINTER_STATE_CYBOI_MODEL;
                        tis = *NULL_POINTER_STATE_CYBOI_MODEL;

                        // Allocate terminated title.
                        // CAUTION! Due to memory allocation handling, the size MUST NOT
                        // be negative or zero, but have at least a value of ONE.
                        allocate_array((void*) &tt, (void*) &ttc, (void*) &tts, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        // Allocate terminated icon name.
                        // CAUTION! Due to memory allocation handling, the size MUST NOT
                        // be negative or zero, but have at least a value of ONE.
                        allocate_array((void*) &ti, (void*) &tic, (void*) &tis, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

                        // Encode wide character name into title, which is a multibyte character array.
                        encode_utf_8((void*) &tt, ttc, tts, *tm, *tmc);
                        // Encode wide character name into icon name, which is a multibyte character array.
                        encode_utf_8((void*) &ti, tic, tis, *im, *imc);

                        if (*((int*) tts) <= *((int*) ttc)) {

                            // Increase character array size to have place for the termination character.
                            *((int*) tts) = *((int*) ttc) + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            // Reallocate title as multibyte character array.
                            reallocate_array((void*) &tt, ttc, tts, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
                        }

                        if (*((int*) tis) <= *((int*) tic)) {

                            // Increase character array size to have place for the termination character.
                            *((int*) tis) = *((int*) tic) + *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

                            // Reallocate icon name as multibyte character array.
                            reallocate_array((void*) &ti, tic, tis, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
                        }

                        // Add null termination character to title.
                        overwrite_array((void*) &tt, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, ttc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, ttc, tts, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        // Add null termination character to icon name.
                        overwrite_array((void*) &ti, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, tic, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, tic, tis, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                        // Set terminated window title.
                        //
                        // CAUTION! If the string "tt" is not in the host portable
                        // character encoding, the result is implementation-dependent.
                        XStoreName(*di, **w, (char*) tt);
                        // Set terminated window icon.
                        XSetIconName(*di, **w, (char*) ti);

                        // Destroy terminated title.
                        deallocate_array((void*) &tt, (void*) &ttc, (void*) &tts, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                        // Destroy terminated icon name.
                        deallocate_array((void*) &ti, (void*) &tic, (void*) &tis, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) CHARACTER_TEXT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
                    }

                    // Reset comparison result.
                    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                    compare_all_array((void*) &r, *a, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, *ac, (void*) PART_ELEMENT_STATE_PRIMITIVE_STATE_CYBOI_MODEL_COUNT);

                    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // The part model is a compound.
                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"The part model is a compound.");

                        // Recursively call this procedure for compound part model.
                        serialise_x_window_system(p0, p1, p2, *m, *mc, *d, *dc, p7, p8);
                    }
*/

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system element. The connection is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system element. The screen is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system element. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system element. The graphic context is null.");
    }
}

/* ELEMENT_X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
