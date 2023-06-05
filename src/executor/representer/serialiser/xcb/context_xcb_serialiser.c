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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <xcb/xcb.h>
#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises the xcb context.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the font
 * @param p5 the source properties data
 * @param p6 the source properties count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 */
void serialise_xcb_context(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

/*??
    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p4;
*/

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* gc = (int*) p3;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                xcb_screen_t* s = (xcb_screen_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    xcb_connection_t* c = (xcb_connection_t*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise xcb context.");

                    //
                    // The graphic context value mask.
                    //
                    // CAUTION! It is possible to set several attributes
                    // at the same time by OR'ing these values in valuemask.
                    //
                    // The values that a mask could take are given
                    // by the "xcb_gc_t" enumeration:
                    //
                    // enum xcb_gc_t {
                    //     XCB_GC_FUNCTION = 1,
                    //     XCB_GC_PLANE_MASK = 2,
                    //     XCB_GC_FOREGROUND = 4,
                    //     XCB_GC_BACKGROUND = 8,
                    //     XCB_GC_LINE_WIDTH = 16,
                    //     XCB_GC_LINE_STYLE = 32,
                    //     XCB_GC_CAP_STYLE = 64,
                    //     XCB_GC_JOIN_STYLE = 128,
                    //     XCB_GC_FILL_STYLE = 256,
                    //     XCB_GC_FILL_RULE = 512,
                    //     XCB_GC_TILE = 1024,
                    //     XCB_GC_STIPPLE = 2048,
                    //     XCB_GC_TILE_STIPPLE_ORIGIN_X = 4096,
                    //     XCB_GC_TILE_STIPPLE_ORIGIN_Y = 8192,
                    //     XCB_GC_FONT = 16384,
                    //     XCB_GC_SUBWINDOW_MODE = 32768,
                    //     XCB_GC_GRAPHICS_EXPOSURES = 65536,
                    //     XCB_GC_CLIP_ORIGIN_X = 131072,
                    //     XCB_GC_CLIP_ORIGIN_Y = 262144,
                    //     XCB_GC_CLIP_MASK = 524288,
                    //     XCB_GC_DASH_OFFSET = 1048576,
                    //     XCB_GC_DASH_LIST = 2097152,
                    //     XCB_GC_ARC_MODE = 4194304
                    // }
                    //
                    // CAUTION! Be careful when setting the values,
                    // as they HAVE TO FOLLOW THE ORDER of the enumeration.
                    // https://www.x.org/releases/X11R7.6/doc/libxcb/tutorial/
                    //
                    uint32_t m = XCB_GC_FOREGROUND
                        | XCB_GC_BACKGROUND
                        | XCB_GC_LINE_WIDTH
                        | XCB_GC_LINE_STYLE
                        | XCB_GC_CAP_STYLE
                        | XCB_GC_JOIN_STYLE
                        | XCB_GC_FILL_STYLE
                        | XCB_GC_FILL_RULE
                        | XCB_GC_FONT;
                    //
                    // The graphic context values.
                    //
                    // CAUTION! They have to be IN THE SAME ORDER
                    // as given in the value mask above.
                    //
                    uint32_t v[9];
                    // Get screen's default colour map.
                    xcb_colormap_t cm = (*s).default_colormap;
                    //
                    // The foreground colour red, green, blue.
                    // Default value: 0,0,0 == "black"
                    //
                    int fgr = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    int fgg = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    int fgb = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                    //
                    // The background colour red, green, blue.
                    // Default value: 255,255,255 == "white"
                    //
                    int bgr = *NUMBER_255_INTEGER_STATE_CYBOI_MODEL;
                    int bgg = *NUMBER_255_INTEGER_STATE_CYBOI_MODEL;
                    int bgb = *NUMBER_255_INTEGER_STATE_CYBOI_MODEL;
                    // The foreground colour.
                    uint32_t fg = (*s).black_pixel;
                    // The background colour.
                    uint32_t bg = (*s).white_pixel;
                    // The line width measured in pixels.
                    int lw = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
                    // The line style defining which sections of a line are drawn.
                    int ls = XCB_LINE_STYLE_SOLID;
                    // The cap style defining how the endpoints of a path are drawn.
                    int cs = XCB_CAP_STYLE_NOT_LAST;
                    // The join style defining how corners are drawn for wide lines.
                    int js = XCB_JOIN_STYLE_MITER;
                    // The fill style defining the contents of the
                    // source for line, text, and fill requests.
                    int fs = XCB_FILL_STYLE_SOLID;
                    // The fill rule.
                    int fr = XCB_FILL_RULE_EVEN_ODD;
                    // The font name item.
                    void* fn = *NULL_POINTER_STATE_CYBOI_MODEL;
                    // The font name item data, count.
                    void* fnd = *NULL_POINTER_STATE_CYBOI_MODEL;
                    void* fnc = *NULL_POINTER_STATE_CYBOI_MODEL;

                    //
                    // Allocate font name item.
                    //
                    // CAUTION! Due to memory allocation handling, the size MUST NOT
                    // be negative or zero, but have at least a value of ONE.
                    //
                    allocate_item((void*) &fn, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                    // Get properties.
                    serialise_xcb_context_properties((void*) &fgr, (void*) &fgg, (void*) &fgb, (void*) &bgr, (void*) &bgg, (void*) &bgb, (void*) &lw, (void*) &ls, (void*) &cs, (void*) &js, (void*) &fs, (void*) &fr, fn, p5, p6, p7, p8, p9);

                    //
                    // Set colour values.
                    //
                    // Transform colour values with maximum 255
                    // to values with a maximum of 65535,
                    // as expected by xcb for the x window system.
                    //
                    // Equation:
                    // dest / 65535 == src / 255
                    // dest = src * 65535 / 255
                    // dest = src * 257
                    //
                    // CAUTION! In order to OPTIMISE performance,
                    // the formula's division 65535 / 255
                    // is REPLACED by the result value 257.
                    //

                    // The foreground red, green, blue transformed.
                    uint16_t fgrt = (uint16_t) (fgr * 257);
                    uint16_t fggt = (uint16_t) (fgg * 257);
                    uint16_t fgbt = (uint16_t) (fgb * 257);
                    // The foreground red, green, blue transformed.
                    uint16_t bgrt = (uint16_t) (bgr * 257);
                    uint16_t bggt = (uint16_t) (bgg * 257);
                    uint16_t bgbt = (uint16_t) (bgb * 257);

                    // The foreground colour cookie.
                    xcb_alloc_color_cookie_t fgcc = xcb_alloc_color(c, cm, fgrt, fggt, fgbt);
                    // The background colour cookie.
                    xcb_alloc_color_cookie_t bgcc = xcb_alloc_color(c, cm, bgrt, bggt, bgbt);
                    // The foreground colour reply.
                    xcb_alloc_color_reply_t* fgcr = xcb_alloc_color_reply(c, fgcc, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                    // The background colour reply.
                    xcb_alloc_color_reply_t* bgcr = xcb_alloc_color_reply(c, bgcc, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                    // The foreground colour.
                    fg = (*fgcr).pixel;
                    // The background colour.
                    bg = (*bgcr).pixel;

                    //
                    // Ask x server to attribute an id to the font.
                    //
                    // The font type is defined as id internally:
                    // typedef uint32_t xcb_font_t;
                    //
                    // It is used to contain information about a font,
                    // and is passed to several functions that handle
                    // font selection and text drawing.
                    //
                    xcb_font_t f = xcb_generate_id(c);

                    //?? fwprintf(stdout, L"Debug: Serialise xcb context. generated id f: %i\n", f);

                    //
                    // Get font name item data, count.
                    //
                    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                    // Inside the structure, arrays may have been reallocated,
                    // with elements pointing to different memory areas now.
                    //
                    copy_array_forward((void*) &fnd, fn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
                    copy_array_forward((void*) &fnc, fn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

                    if (fnc != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        // Convert font name item data, count to expected type.
                        char* fndt = (char*) fnd;
                        uint16_t* fnct = (uint16_t*) fnc;

                        if (*fnct > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                            //
                            // Open font.
                            //
                            // CAUTION! Use command "xlsfonts" in terminal
                            // to know which are the fonts available.
                            //
                            // Examples:
                            // "7x13"
                            // "*-helvetica-*-12-*"
                            //
                            xcb_open_font(c, f, *fnct, fndt);

                            //?? fwprintf(stdout, L"Debug: Serialise xcb context. *fnct: %i\n", *fnct);
                            //?? fwprintf(stdout, L"Debug: Serialise xcb context. fndt: %s\n", fndt);

                        } else {

                            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The font name count is zero.");
                            fwprintf(stdout, L"Error: Could not serialise xcb context. The font name count is zero.\n");
                        }

                    } else {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The font name count is null.");
                        fwprintf(stdout, L"Error: Could not serialise xcb context. The font name count is null.\n");
                    }

                    // Deallocate font name item.
                    deallocate_item((void*) &fn, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                    //
                    // Initialise graphic context values.
                    // CAUTION! Initialise values BEFORE using them
                    // in function calls further below.
                    // Otherwise, drawings will not be displayed.
                    //

                    if (fgcr != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        v[0] = fg;

                    } else {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The foreground colour reply is null.");
                        fwprintf(stdout, L"Error: Could not serialise xcb context. The foreground colour reply is null.\n");
                    }

                    if (bgcr != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        v[1] = bg;

                    } else {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The background colour reply is null.");
                        fwprintf(stdout, L"Error: Could not serialise xcb context. The background colour reply is null.\n");
                    }

                    v[2] = lw;
                    v[3] = ls;
                    v[4] = cs;
                    v[5] = js;
                    v[6] = fs;
                    v[7] = fr;

//??                    if (f > *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL) {

                        v[8] = f;

/*??
                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The font is negative.");
                        fwprintf(stdout, L"Error: Could not serialise xcb context. The font is negative. f: %i\n", f);
                        fwprintf(stdout, L"Error: Could not serialise xcb context. The font is negative. *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL: %i\n", *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);
                    }
*/

                    // The xcb graphic context type value.
                    xcb_gcontext_t gct = (xcb_gcontext_t) *gc;
                    // Change graphic context.
                    xcb_change_gc(c, gct, m, v);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The connexion is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The screen is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The graphic context is null.");
        }

/*??
    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise xcb context. The font is null.");
        fwprintf(stdout, L"Error: Could not serialise xcb context. The font is null.\n");
    }
*/
}
