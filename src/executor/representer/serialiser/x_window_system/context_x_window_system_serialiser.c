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

#ifndef CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE
#define CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE

#include <xcb/xcb.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the x window system context.
 *
 * @param p0 the connexion
 * @param p1 the screen
 * @param p2 the window
 * @param p3 the graphic context
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the knowledge memory part
 */
void serialise_x_window_system_context(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        xcb_gcontext_t* gc = (xcb_gcontext_t*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            xcb_drawable_t* d = (xcb_drawable_t*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                xcb_screen_t* s = (xcb_screen_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    xcb_connection_t* c = (xcb_connection_t*) p0;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise x window system context.");

                    // The graphic context value mask.
                    // CAUTION! It is possible to set several attributes
                    // at the same time by OR'ing these values in valuemask.
                    uint32_t m = XCB_GC_FOREGROUND
                        | XCB_GC_BACKGROUND
                        | XCB_GC_LINE_WIDTH
                        | XCB_GC_LINE_STYLE
                        | XCB_GC_CAP_STYLE
                        | XCB_GC_JOIN_STYLE
                        | XCB_GC_FILL_STYLE
                        | XCB_GC_FILL_RULE
                        | XCB_GC_FONT;
                    // The graphic context values.
                    // CAUTION! They have to be IN THE SAME ORDER
                    // as given in the value mask above.
                    uint32_t v[9];
                    // Get screen's default colour map.
                    xcb_colormap_t cm = (*s).default_colormap;
                    // The foreground colour cookie.
                    xcb_alloc_color_cookie_t fgcc = xcb_alloc_color(c, cm, 65535, 0, 0);
                    // The background colour cookie.
                    xcb_alloc_color_cookie_t bgcc = xcb_alloc_color(c, cm, 0, 65535, 0);
                    // The foreground colour reply.
                    xcb_alloc_color_reply_t* fgcr = xcb_alloc_color_reply(c, fgcc, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                    // The background colour reply.
                    xcb_alloc_color_reply_t* bgcr = xcb_alloc_color_reply(c, bgcc, (xcb_generic_error_t**) NULL_POINTER_STATE_CYBOI_MODEL);
                    // The foreground colour.
                    uint32_t* fg = (*fgcr).pixel;
                    // The background colour.
                    uint32_t* bg = (*bgcr).pixel;
                    // The line width measured in pixels.
                    int lw = *NUMBER_2_INTEGER_STATE_CYBOI_MODEL;
                    // The line style defining which sections of a line are drawn.
                    //
                    // Possible values:
                    //
                    // XCB_LINE_STYLE_SOLID: FULL PATH of the line is drawn
                    // XCB_LINE_STYLE_DOUBLE_DASH: full path of the line is drawn,
                    //     but EVEN DASHES are filled DIFFERENTLY
                    //     than odd dashes (see fill-style), with
                    //     Butt cap-style used where even and odd dashes meet
                    // XCB_LINE_STYLE_ON_OFF_DASH: ONLY EVEN DASHES are drawn, and
                    //     cap-style applies to all internal ends of
                    //     individual dashes (except NotLast is treated as Butt)
                    int ls = XCB_LINE_STYLE_DOUBLE_DASH; //?? XCB_LINE_STYLE_SOLID;
                    // The cap style defining how the endpoints of a path are drawn.
                    //
                    // Possible values:
                    //
                    // XCB_CAP_STYLE_NOT_LAST: result is EQUIVALENT TO Butt,
                    //     except that for a line-width of zero
                    //     the final endpoint is not drawn
                    // XCB_CAP_STYLE_BUTT: result is SQUARE at the endpoint
                    //     (perpendicular to the slope of the line)
                    //     with no projection beyond
                    // XCB_CAP_STYLE_ROUND: result is a CIRCULAR ARC with its
                    //     diameter equal to the line-width,
                    //     centered on the endpoint;
                    //     equivalent to Butt for line-width zero
                    // XCB_CAP_STYLE_PROJECTING: result is SQUARE at the end,
                    //     but the path continues BEYOND the endpoint
                    //     for a distance equal to half the line-width;
                    //     equivalent to Butt for line-width zero
                    int cs = XCB_CAP_STYLE_NOT_LAST;
                    // The join style defining how corners are drawn for wide lines.
                    //
                    // Possible values:
                    //
                    // XCB_JOIN_STYLE_MITER: OUTER EDGES of the two lines extend to MEET at an angle;
                    //     however, if the angle is less than 11 degrees,
                    //     a Bevel join-style is used instead
                    // XCB_JOIN_STYLE_ROUND: result is a CIRCULAR ARC with a diameter
                    //     equal to the line-width, centered on the joinpoint
                    // XCB_JOIN_STYLE_BEVEL: result is Butt endpoint styles,
                    //     and then the TRIANGULAR NOTCH IS FILLED
                    int js = XCB_JOIN_STYLE_MITER;
                    // The fill style defining the contents of the
                    // source for line, text, and fill requests.
                    //
                    // Possible values:
                    //
                    // XCB_FILL_STYLE_SOLID
                    // XCB_FILL_STYLE_TILED
                    // XCB_FILL_STYLE_STIPPLED
                    // XCB_FILL_STYLE_OPAQUE_STIPPLED
                    int fs = XCB_FILL_STYLE_SOLID;
                    // The fill rule.
                    //
                    // Possible values:
                    //
                    // XCB_FILL_RULE_EVEN_ODD
                    // XCB_FILL_RULE_WINDING
                    int fr = XCB_FILL_RULE_EVEN_ODD;
                    // The font defining the font to use for
                    // the ImageText8 and ImageText16 requests.
                    //
                    // CAUTION! This function asks the x server
                    // to attribute an id to the font.
                    xcb_font_t f = xcb_generate_id(c);
                    // Open font.
                    //
                    // CAUTION! Use command "xlsfonts" in terminal
                    // to know which are the fonts available.
                    xcb_open_font(c, f, strlen("7x13"), "7x13");

                    serialise_x_window_system_context_properties(fg, bg, lw, ls, cs, js, fs, fr, f, p4, p5, p6);

                    //
                    // Initialise graphic context values.
                    // CAUTION! Initialise values BEFORE using them
                    // in function calls further below.
                    // Otherwise, drawings will not be displayed.
                    //

                    if (crf != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        v[0] = fg;

                    } else {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The foreground colour reply is null.");
                    }

                    if (crb != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        v[1] = bg;

                    } else {

                        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The background colour reply is null.");
                    }

                    v[2] = lw;
                    v[3] = ls;
                    v[4] = cs;
                    v[5] = js;
                    v[6] = fs;
                    v[7] = fr;
                    v[8] = f;

                    // Change graphic context.
                    xcb_change_gc(c, *gc, m, v);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The connexion is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The screen is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The window is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not serialise x window system context. The graphic context is null.");
    }
}

/* CONTEXT_X_WINDOW_SYSTEM_SERIALISER_SOURCE */
#endif
