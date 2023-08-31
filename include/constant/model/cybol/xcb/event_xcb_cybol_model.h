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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef EVENT_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define EVENT_XCB_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The button-press event xcb cybol model. */
static wchar_t* BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL = L"button-press";
static int* BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The button-release event xcb cybol model. */
static wchar_t* BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL = L"button-release";
static int* BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The circulate-notify event xcb cybol model. */
static wchar_t* CIRCULATE_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"circulate-notify";
static int* CIRCULATE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The circulate-request event xcb cybol model. */
static wchar_t* CIRCULATE_REQUEST_EVENT_XCB_CYBOL_MODEL = L"circulate-request";
static int* CIRCULATE_REQUEST_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The close window event xcb cybol model. */
static wchar_t* CLOSE_WINDOW_EVENT_XCB_CYBOL_MODEL = L"close-window";
static int* CLOSE_WINDOW_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The colormap-notify event xcb cybol model. */
static wchar_t* COLORMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"colormap-notify";
static int* COLORMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The configure-notify event xcb cybol model. */
static wchar_t* CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"configure-notify";
static int* CONFIGURE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The configure-request event xcb cybol model. */
static wchar_t* CONFIGURE_REQUEST_EVENT_XCB_CYBOL_MODEL = L"configure-request";
static int* CONFIGURE_REQUEST_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The create-notify event xcb cybol model. */
static wchar_t* CREATE_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"create-notify";
static int* CREATE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy-notify event xcb cybol model. */
static wchar_t* DESTROY_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"destroy-notify";
static int* DESTROY_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The enter-notify event xcb cybol model. */
static wchar_t* ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"enter-notify";
static int* ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expose event xcb cybol model. */
static wchar_t* EXPOSE_EVENT_XCB_CYBOL_MODEL = L"expose";
static int* EXPOSE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The focus-in event xcb cybol model. */
static wchar_t* FOCUS_IN_EVENT_XCB_CYBOL_MODEL = L"focus-in";
static int* FOCUS_IN_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The focus-out event xcb cybol model. */
static wchar_t* FOCUS_OUT_EVENT_XCB_CYBOL_MODEL = L"focus-out";
static int* FOCUS_OUT_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ge-generic event xcb cybol model. */
static wchar_t* GE_GENERIC_EVENT_XCB_CYBOL_MODEL = L"ge-generic";
static int* GE_GENERIC_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The graphics-exposure event xcb cybol model. */
static wchar_t* GRAPHICS_EXPOSURE_EVENT_XCB_CYBOL_MODEL = L"graphics-exposure";
static int* GRAPHICS_EXPOSURE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gravity-notify event xcb cybol model. */
static wchar_t* GRAVITY_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"gravity-notify";
static int* GRAVITY_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The key-press event xcb cybol model. */
static wchar_t* KEY_PRESS_EVENT_XCB_CYBOL_MODEL = L"key-press";
static int* KEY_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The key-release event xcb cybol model. */
static wchar_t* KEY_RELEASE_EVENT_XCB_CYBOL_MODEL = L"key-release";
static int* KEY_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The keymap-notify event xcb cybol model. */
static wchar_t* KEYMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"keymap-notify";
static int* KEYMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The leave-notify event xcb cybol model. */
static wchar_t* LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"leave-notify";
static int* LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The map-notify event xcb cybol model. */
static wchar_t* MAP_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"map-notify";
static int* MAP_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The map-request event xcb cybol model. */
static wchar_t* MAP_REQUEST_EVENT_XCB_CYBOL_MODEL = L"map-request";
static int* MAP_REQUEST_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mapping-notify event xcb cybol model. */
static wchar_t* MAPPING_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"mapping-notify";
static int* MAPPING_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The motion-notify event xcb cybol model. */
static wchar_t* MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"motion-notify";
static int* MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The no-exposure event xcb cybol model. */
static wchar_t* NO_EXPOSURE_EVENT_XCB_CYBOL_MODEL = L"no-exposure";
static int* NO_EXPOSURE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The property-notify event xcb cybol model. */
static wchar_t* PROPERTY_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"property-notify";
static int* PROPERTY_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reparent-notify event xcb cybol model. */
static wchar_t* REPARENT_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"reparent-notify";
static int* REPARENT_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The resize-request event xcb cybol model. */
static wchar_t* RESIZE_REQUEST_EVENT_XCB_CYBOL_MODEL = L"resize-request";
static int* RESIZE_REQUEST_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The selection-clear event xcb cybol model. */
static wchar_t* SELECTION_CLEAR_EVENT_XCB_CYBOL_MODEL = L"selection-clear";
static int* SELECTION_CLEAR_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The selection-notify event xcb cybol model. */
static wchar_t* SELECTION_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"selection-notify";
static int* SELECTION_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The selection-request event xcb cybol model. */
static wchar_t* SELECTION_REQUEST_EVENT_XCB_CYBOL_MODEL = L"selection-request";
static int* SELECTION_REQUEST_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unmap-notify event xcb cybol model. */
static wchar_t* UNMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"unmap-notify";
static int* UNMAP_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The visibility-notify event xcb cybol model. */
static wchar_t* VISIBILITY_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"visibility-notify";
static int* VISIBILITY_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* EVENT_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
