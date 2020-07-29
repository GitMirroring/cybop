/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DISPLAY_TESTER
#define DISPLAY_TESTER

#ifdef WIN32
#ifndef _MSC_VER
#define INCLUDE_WINSOCK2
#endif
#endif

#ifdef WIN32_LEAN_AND_MEAN
#ifdef _MSC_VER
#define INCLUDE_WINSOCK2
#endif
#endif

#ifdef WIN32
#ifdef INCLUDE_WINSOCK2
#include <winsock2.h>
#endif
#endif

#include <xcb/xcb.h>
#ifdef WIN32
int initWSA(void);
#endif

#include "../constant/type/cyboi/state_cyboi_type.c"

/**
 * Tests the display drawing.
 */

void test_display_drawing() {

    fwprintf(stdout, L"TEST display drawing.\n");

    // Geometric objects.
    xcb_point_t points[] = {{10, 10}, {10, 20}, {20, 10}, {20, 20}};

    xcb_point_t polyline[] = {{50, 10},
                              {5, 20}, // rest of points are relative
                              {25, -20},
                              {10, 10}};

    xcb_segment_t segments[] = {{100, 10, 140, 30}, {110, 25, 130, 60}};

    xcb_rectangle_t rectangles[] = {{10, 50, 40, 20}, {80, 50, 10, 40}};

    xcb_arc_t arcs[] = {{10, 100, 60, 40, 0, 90 << 6}, {90, 100, 55, 40, 0, 270 << 6}};

#if defined(__linux__) || defined(__unix__)
    // Open connection to x server.
    xcb_connection_t* connection = xcb_connect(NULL, NULL);
    // Get first screen.
    xcb_screen_t* screen = xcb_setup_roots_iterator(xcb_get_setup(connection)).data;
#elif defined(__APPLE__) && defined(__MACH__)
   //?? TODO: Add support for Cocoa
#elif defined(_WIN32) || defined(__CYGWIN__)
    int screenNum, i;
    int rc;

    rc = initWSA();
    if (rc != 0) {
        fprintf(stderr, "Unable to load Winsock: %d\n", rc);
        return -1;
    }

    // Open connection to x server.
    xcb_connection_t* connection = xcb_connect("127.0.0.1:0.0", &screenNum);
    if (!connection) {
        fprintf(stderr, "ERROR: can't connect to an X server\n");
        return -1;
    }

    // Get first screen.
    xcb_screen_iterator_t iter = xcb_setup_roots_iterator(xcb_get_setup(connection));

    for (i = 0; i < screenNum; ++i) {
        xcb_screen_next(&iter);
    }

    xcb_screen_t* screen = iter.data;
#else
   #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

    // Create black (foreground) graphic context.
    xcb_drawable_t window = screen->root;
    xcb_gcontext_t foreground = xcb_generate_id(connection);
    uint32_t mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
    uint32_t values[2] = {screen->black_pixel, 0};

    xcb_create_gc(connection, foreground, window, mask, values);

    // Create window.
    window = xcb_generate_id(connection);

    mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
    values[0] = screen->white_pixel;
    values[1] = XCB_EVENT_MASK_EXPOSURE;

    xcb_create_window(connection,                    // connection
                      XCB_COPY_FROM_PARENT,          // depth (same as root)
                      window,                        // window id
                      screen->root,                  // parent window
                      0, 0,                          // x, y
                      150, 150,                      // width, height
                      10,                            // border_width
                      XCB_WINDOW_CLASS_INPUT_OUTPUT, // class
                      screen->root_visual,           // visual
                      mask, values);                 // masks

    // Map window on the screen and flush.
    xcb_map_window(connection, window);
    xcb_flush(connection);

    // Draw primitives.
    xcb_generic_event_t* event;

    while (event = xcb_wait_for_event(connection)) {

        switch (event->response_type & ~0x80) {

        case XCB_EXPOSE:

            // Draw points.
            xcb_poly_point(connection, XCB_COORD_MODE_ORIGIN, window, foreground, 4, points);

            // Draw polygonal line.
            xcb_poly_line(connection, XCB_COORD_MODE_PREVIOUS, window, foreground, 4, polyline);

            // Draw segements.
            xcb_poly_segment(connection, window, foreground, 2, segments);

            // Draw rectangles.
            xcb_poly_rectangle(connection, window, foreground, 2, rectangles);

            // Draw arcs.
            xcb_poly_arc(connection, window, foreground, 2, arcs);

            // Flush request.
            xcb_flush(connection);

            break;

        default:

            // Unknown event type, ignore it.
            break;
        }

        free(event);
    }
}

/**
 * Tests the display.
 *
 * Sub test procedure calls can be activated/ deactivated here
 * by simply commenting/ uncommenting the corresponding lines.
 */
void test_display() {

    fwprintf(stdout, L"TEST display.\n");

    test_display_drawing();
}

/* DISPLAY_TESTER */
#endif
