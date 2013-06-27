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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef X_WINDOW_SYSTEM_STARTER_SOURCE
#define X_WINDOW_SYSTEM_STARTER_SOURCE

#ifdef WIN32
    #include <winsock2.h>
#endif
#include <xcb/xcb.h>

#ifdef WIN32
    int initWSA(void);

    static xcb_gc_t
        getFontGC (xcb_connection_t *connection,
               xcb_screen_t     *screen,
               xcb_window_t      window,
               const char       *fontName );
    static void
        testCookie (xcb_void_cookie_t cookie,
                xcb_connection_t *connection,
                char *errMessage )
        {
        xcb_generic_error_t *error = xcb_request_check (connection, cookie);
        if (error)
           {
           fprintf (stderr, "ERROR: %s : %d\n", errMessage , error->error_code);
           xcb_disconnect (connection);
           exit (-1);
           }
        }


    static void
    drawButton (xcb_connection_t *connection,
                xcb_screen_t     *screen,
                xcb_window_t      window,
                int16_t           x1,
                int16_t           y1,
                const char       *label )
    {
        uint8_t length = strlen (label);
        int16_t inset = 2;
        int16_t width = 7 * length + 2 * (inset + 1);
        int16_t height = 13 + 2 * (inset + 1);

        xcb_point_t points[5];
        points[0].x = x1;
        points[0].y = y1;
        points[1].x = x1 + width;
        points[1].y = y1;
        points[2].x = x1 + width;
        points[2].y = y1 - height;
        points[3].x = x1;
        points[3].y = y1 - height;
        points[4].x = x1;
        points[4].y = y1;


        xcb_gcontext_t gc = getFontGC (connection, screen, window, "7x13");


        xcb_void_cookie_t lineCookie = xcb_poly_line_checked (connection,
                                                              XCB_COORD_MODE_ORIGIN,
                                                              window,
                                                              gc,
                                                              5,
                                                              points );
        testCookie (lineCookie, connection, "can't draw lines");


        xcb_void_cookie_t textCookie = xcb_image_text_8_checked (connection,
                                                                 length,
                                                                 window,
                                                                 gc,
                                                                 x1 + inset + 1,
                                                                 y1 - inset - 1,
                                                                 label );
        testCookie (textCookie, connection, "can't paste text");


        xcb_void_cookie_t gcCookie = xcb_free_gc (connection, gc);
        testCookie (gcCookie, connection, "can't free gc");
    }



    static void
    drawText (xcb_connection_t *connection,
              xcb_screen_t     *screen,
              xcb_window_t      window,
              int16_t           x1,
              int16_t           y1,
              const char       *label )
    {

        xcb_gcontext_t gc = getFontGC (connection, screen, window, "7x13");


        xcb_void_cookie_t textCookie = xcb_image_text_8_checked (connection,
                                                                 strlen (label),
                                                                 window,
                                                                 gc,
                                                                 x1,
                                                                 y1,
                                                                 label );
        testCookie(textCookie, connection, "can't paste text");


        xcb_void_cookie_t gcCookie = xcb_free_gc (connection, gc);
        testCookie (gcCookie, connection, "can't free gc");
    }


    static xcb_gc_t
    getFontGC (xcb_connection_t *connection,
               xcb_screen_t     *screen,
               xcb_window_t      window,
               const char       *fontName )
    {

        xcb_font_t font = xcb_generate_id (connection);
        xcb_void_cookie_t fontCookie = xcb_open_font_checked (connection,
                                                              font,
                                                              strlen (fontName),
                                                              fontName );
        testCookie (fontCookie, connection, "can't open font");


        xcb_gcontext_t gc = xcb_generate_id (connection);
        uint32_t  mask = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND | XCB_GC_FONT;
        uint32_t value_list[3];
        value_list[0] = screen->black_pixel;
        value_list[1] = screen->white_pixel;
        value_list[2] = font;


        xcb_void_cookie_t gcCookie = xcb_create_gc_checked (connection,
                                                            gc,
                                                            window,
                                                            mask,
                                                            value_list );
        testCookie (gcCookie, connection, "can't create gc");


        fontCookie = xcb_close_font_checked (connection, font);
        testCookie (fontCookie, connection, "can't close font");

        return gc;
    }


    static void
    setCursor (xcb_connection_t *connection,
                xcb_screen_t     *screen,
                xcb_window_t      window,
                int               cursorId )
    {
        uint32_t mask;
    xcb_font_t font = xcb_generate_id (connection);
        xcb_void_cookie_t fontCookie = xcb_open_font_checked (connection,
                                                              font,
                                                              strlen ("cursor"),
                                                              "cursor" );
        testCookie (fontCookie, connection, "can't open font");


        xcb_cursor_t cursor = xcb_generate_id (connection);
        xcb_create_glyph_cursor (connection,
                                 cursor,
                                 font,
                                 font,
                                 cursorId,
                                 cursorId + 1,
                                 0, 0, 0, 0, 0, 0 );


        xcb_gcontext_t gc = xcb_generate_id (connection);

        mask = XCB_GC_FOREGROUND | XCB_GC_BACKGROUND | XCB_GC_FONT;
        uint32_t values_list[3];
        values_list[0] = screen->black_pixel;
        values_list[1] = screen->white_pixel;
        values_list[2] = font;

        xcb_void_cookie_t gcCookie = xcb_create_gc_checked (connection, gc, window, mask, values_list);
        testCookie (gcCookie, connection, "can't create gc");


        mask = XCB_CW_CURSOR;
        uint32_t value_list = cursor;
        xcb_change_window_attributes (connection, window, mask, &value_list);


        xcb_free_cursor (connection, cursor);



        fontCookie = xcb_close_font_checked (connection, font);
        testCookie (fontCookie, connection, "can't close font");
    }
#endif

/*??
#include <X11/Xlib.h>
#include <X11/Xutil.h>
*/

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/x_window_system_type_size.c"

//
// The X.Org Foundation formed by X.Org and freedesktop.org
// has an oversight role in X Window System development.
// XFree86 is still being developed at a very slow pace,
// but the X.Org Foundation currently sets the standard.
//
// http://www.x.org/wiki/Documentation:
// For low-level X development, the X C Bindings (XCB)
// provide a clean low-level protocol binding:
// http://xcb.freedesktop.org/tutorial/
//
// Its older cousin Xlib (or libX11), is NOT recommended
// for new development, but is still very widely used.
// Xt is a similarly DEPRECATED library for building toolkits.
//

/**
 * Starts up the x window system.
 *
 * @param p0 the internal memory data
 */
void startup_x_window_system(void* p0) {

    // The connexion.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get connexion.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only establish connexion if not existent.
    if (c == *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup x window system.");

        // The screen.
        void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The window.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The graphic context.
        // CAUTION! It is possible to use more than one
        // graphical context with a single window,
        // in order to draw in multiple styles
        // (different colors, different line widths etc).
        void* gc = *NULL_POINTER_STATE_CYBOI_MODEL;
/*??
        // The default colourmap id.
        // For allocation on the specified screen.
        // Most routine allocations of colour should be made out of this colormap.
        void* cm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The background pixel values.
        void* bg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The foreground pixel values.
        void* fg = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font name.
        void* fn = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font.
        void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The font id.
//??        int fid = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The size hint.
        XSizeHints sh;
        // The colours.
        XColor gray;
        XColor light_gray;
        XColor vlight_gray;
        XColor dark_gray;
        // The menu graphic context.
        void* gc_menu = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu border top graphic context.
        void* gc_menu_border_top = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu border bottom graphic context.
        void* gc_menu_border_bottom = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The menu font graphic context.
        void* gc_menu_font = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The value mask.
        // It defines the attributes for the graphics context.
        // This argument is the bitwise inclusive OR of zero or more
        // of the valid graphic context component mask bits.
        void* vm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The values for the attributes defined in the value mask.
        void* v = *NULL_POINTER_STATE_CYBOI_MODEL;
*/

        // Allocate x window system internals.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_array((void*) &w, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &gc, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
/*??
        allocate_array((void*) &cm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &bg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &fg, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
        allocate_array((void*) &vm, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNSIGNED_LONG_NUMBER_STATE_CYBOI_TYPE);
//??        v = malloc(*XGC_VALUES_X_WINDOW_SYSTEM_TYPE_SIZE);
*/


fwprintf(stdout, L"TEST startup x window system c: %i\n", c);

        #ifdef WIN32
            int screenNum,i;
            int rc;

            rc = initWSA();
            if(rc != 0)
            {
                fprintf(stderr,"Unable to load Winsock: %d\n",rc);
                return; //?? -1;
            }

            // Open connexion to x server.
            xcb_connection_t *c = xcb_connect("127.0.0.1:0.0", &screenNum);
            if (!c) {
                fprintf (stderr, "ERROR: can't connect to an X server\n");
                return; //?? -1;
            }

            // Get first screen.
            xcb_screen_iterator_t iter = xcb_setup_roots_iterator (xcb_get_setup (c));

            for (i = 0; i < screenNum; ++i) {
                xcb_screen_next (&iter);
            }

            s = (void*) iter.data;
        #endif
        #ifdef GNU_LINUX_OPERATING_SYSTEM
            // Open connexion.
            c = (void*) xcb_connect(NULL, NULL);

            // Get first screen.
            const xcb_setup_t* setup = xcb_get_setup((xcb_connection_t*) c);
            xcb_screen_iterator_t iter = xcb_setup_roots_iterator(setup);
            s = (void*) iter.data;

        #endif


fwprintf(stdout, L"TEST startup x window system s: %i\n", s);
        // Define window background.
        //
        // The mask.
        //
        // The values that a mask could take are given
        // by the "xcb_cw_t" enumeration:
        //
        // typedef enum {
        //     XCB_CW_BACK_PIXMAP       = 1L<<0,
        //     XCB_CW_BACK_PIXEL        = 1L<<1,
        //     XCB_CW_BORDER_PIXMAP     = 1L<<2,
        //     XCB_CW_BORDER_PIXEL      = 1L<<3,
        //     XCB_CW_BIT_GRAVITY       = 1L<<4,
        //     XCB_CW_WIN_GRAVITY       = 1L<<5,
        //     XCB_CW_BACKING_STORE     = 1L<<6,
        //     XCB_CW_BACKING_PLANES    = 1L<<7,
        //     XCB_CW_BACKING_PIXEL     = 1L<<8,
        //     XCB_CW_OVERRIDE_REDIRECT = 1L<<9,
        //     XCB_CW_SAVE_UNDER        = 1L<<10,
        //     XCB_CW_EVENT_MASK        = 1L<<11,
        //     XCB_CW_DONT_PROPAGATE    = 1L<<12,
        //     XCB_CW_COLORMAP          = 1L<<13,
        //     XCB_CW_CURSOR            = 1L<<14
        // } xcb_cw_t;
        //
        // CAUTION! Be careful when setting the values,
        // as they HAVE TO FOLLOW the order of
        // the "xcb_cw_t" enumeration.
        //
        uint32_t mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
//??        uint32_t values[2] = { ((xcb_screen_t*) s)->white_pixel, XCB_EVENT_MASK_EXPOSURE };
        uint32_t values[2];
        values[0] = ((xcb_screen_t*) s)->white_pixel;
        // Register for all possible event types.
        values[1] =
            // Expose.
            // - a window that covered part of the current window has moved away, exposing part (or all) of the current window
            // - the current window was raised above other windows
            // - the current window was mapped for the first time
            // - the current window was de-iconified (to 'iconify' a window is to minimize it or send it to the tray such that it is not shown at all)
            XCB_EVENT_MASK_EXPOSURE
            // Mouse button press and release.
            | XCB_EVENT_MASK_BUTTON_PRESS
            | XCB_EVENT_MASK_BUTTON_RELEASE
            // Mouse movement.
            | XCB_EVENT_MASK_POINTER_MOTION // motion with no mouse button held
            | XCB_EVENT_MASK_BUTTON_MOTION // motion with one or more of the mouse buttons held
            | XCB_EVENT_MASK_BUTTON_1_MOTION // motion while only 1st mouse button is held
            | XCB_EVENT_MASK_BUTTON_2_MOTION // and so on ...
            | XCB_EVENT_MASK_BUTTON_3_MOTION
            | XCB_EVENT_MASK_BUTTON_4_MOTION
            | XCB_EVENT_MASK_BUTTON_5_MOTION
            // Mouse pointer enter and leave.
            | XCB_EVENT_MASK_ENTER_WINDOW
            | XCB_EVENT_MASK_LEAVE_WINDOW
            // Keyboard press and release (while focus is on window).
            | XCB_EVENT_MASK_KEY_PRESS
            | XCB_EVENT_MASK_KEY_RELEASE;

        // Create window.
        xcb_window_t window = xcb_generate_id((xcb_connection_t*) c);

        xcb_create_window((xcb_connection_t*) c, // connexion
            XCB_COPY_FROM_PARENT, // depth (same as root)
            window, // window id
            ((xcb_screen_t*) s)->root, // parent window
            0, 0, // x, y
            150, 150, // width, height
            10, // border_width
            XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
            ((xcb_screen_t*) s)->root_visual, // visual
            mask, values); // masks
        // Store window identification in internal memory.
        // CAUTION! The xcb_window_t type is defined as follows:
        // typedef uint32_t xcb_window_t;
        // It may therefore be stored as integer pointer.
        *((int*) w) = window;

fwprintf(stdout, L"TEST startup x window system window: %i\n", window);

        // Create graphic context.
/*??
        xcb_gcontext_t gcontext = xcb_generate_id((xcb_connection_t*) c);
        uint32_t mask = XCB_GC_FOREGROUND;
        uint32_t value[] = { ((xcb_screen_t*) s)->black_pixel };
        xcb_create_gc((xcb_connection_t*) c, gcontext, window, mask, value);
*/
        // Store graphic context identification in internal memory.
        // CAUTION! The xcb_gcontext_t type is defined as follows:
        // typedef uint32_t xcb_gcontext_t;
        // It may therefore be stored as integer pointer.
//??        *((int*) gc) = gcontext;

//?? fwprintf(stdout, L"TEST startup x window system gcontext: %i\n", gcontext);

/*??
        *((int*) cm) = XDefaultColormap((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) bg) = XWhitePixel((struct _XDisplay*) d, *((int*) sn));
        *((unsigned long*) fg) = XBlackPixel((struct _XDisplay*) d, *((int*) sn));
/*??
        fn = (void*) "*-helvetica-*-12-*";
        f = (void*) XLoadQueryFont((struct _XDisplay*) d, (char*) fn);

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fid = ((XFontStruct*) f)->fid;
        }
*/

/*??
        sh.x = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        sh.y = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        sh.width = *NUMBER_800_INTEGER_STATE_CYBOI_MODEL;
        sh.height = *NUMBER_600_INTEGER_STATE_CYBOI_MODEL;
        sh.flags = PPosition | PSize;
        *((int*) w) = XCreateSimpleWindow(d, *((int*) r), sh.x, sh.y, sh.width, sh.height, *NUMBER_5_INTEGER_STATE_CYBOI_MODEL, *((unsigned long*) fg), *((unsigned long*) bg));
        *((unsigned long*) vm) = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
//??        *((unsigned long*) vm) = GCCapStyle | GCJoinStyle;
//??        *((XGCValues*) v) = CapButt | JoinBevel;

        gray.red = 49125;
        gray.green = 49125;
        gray.blue = 49125;
        light_gray.red = 56000;
        light_gray.green = 58000;
        light_gray.blue = 60000;
        vlight_gray.red = 60000;
        vlight_gray.green = 61000;
        vlight_gray.blue = 62000;
        dark_gray.red = 32768;
        dark_gray.green = 32768;
        dark_gray.blue = 32768;
/*??
        gc_menu = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_border_top = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_border_bottom = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        gc_menu_font = (void*) XCreateGC(d, *((int*) w), *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
*/

/*??
        // Assign x window system internals.
        XSetStandardProperties((struct _XDisplay*) d, *((int*) w), "Application", "Icon", None, *NULL_POINTER_STATE_CYBOI_MODEL, *NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) &sh);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &light_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &vlight_gray);
        XAllocColor((struct _XDisplay*) d, *((int*) cm), &dark_gray);
/*??
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu, light_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_top, vlight_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_border_bottom, dark_gray.pixel);
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, light_gray.pixel);
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc_menu_font, *((unsigned long*) fg));
*/
/*??
        XSetBackground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) bg));
        XSetForeground((struct _XDisplay*) d, (struct _XGC*) gc, *((unsigned long*) fg));
//??        XSetFont((struct _XDisplay*) d, (struct _XGC*) gc, fi);
*/

        // Set x window system items.
        // CAUTION! Do NOT use "overwrite_array" function here,
        // since it adapts the array count and size.
        // But the internal array's count and size are CONSTANT.
        copy_array_forward(p0, (void*) &c, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CONNEXION_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) SCREEN_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WINDOW_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
/*??
        copy_array_forward(p0, (void*) &cm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) COLOUR_MAP_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &bg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BACKGROUND_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &fg, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) FOREGROUND_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &gc_menu_border_bottom, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) BOTTOM_BORDER_MENU_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &vm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_MASK_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &v, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUES_GRAPHIC_CONTEXT_X_WINDOW_SYSTEM_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
*/

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup x window system. The x window system is already running.");
    }
}

#ifdef WIN32
int initWSA(void)
{
    WSADATA wsd;
    int rc;

    rc = WSAStartup(MAKEWORD(2,2),&wsd);

    return rc;
}
#endif

/* X_WINDOW_SYSTEM_STARTER_SOURCE */
#endif
