/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef EVENT_XCB_CYBOL_MODEL_CONSTANT_SOURCE
#define EVENT_XCB_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The button_press event xcb cybol model. */
static wchar_t* BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL = L"button_press";
static int* BUTTON_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The button_release event xcb cybol model. */
static wchar_t* BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL = L"button_release";
static int* BUTTON_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The enter_notify event xcb cybol model. */
static wchar_t* ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"enter_notify";
static int* ENTER_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The expose event xcb cybol model. */
static wchar_t* EXPOSE_EVENT_XCB_CYBOL_MODEL = L"expose";
static int* EXPOSE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The key_press event xcb cybol model. */
static wchar_t* KEY_PRESS_EVENT_XCB_CYBOL_MODEL = L"key_press";
static int* KEY_PRESS_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The key_release event xcb cybol model. */
static wchar_t* KEY_RELEASE_EVENT_XCB_CYBOL_MODEL = L"key_release";
static int* KEY_RELEASE_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The leave_notify event xcb cybol model. */
static wchar_t* LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"leave_notify";
static int* LEAVE_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The motion_notify event xcb cybol model. */
static wchar_t* MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL = L"motion_notify";
static int* MOTION_NOTIFY_EVENT_XCB_CYBOL_MODEL_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* EVENT_XCB_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
