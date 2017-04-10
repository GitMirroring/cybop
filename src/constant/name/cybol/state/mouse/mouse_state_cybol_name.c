/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE
#define MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The button-press mouse state cybol name. */
static wchar_t* BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME = L"button-press";
static int* BUTTON_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The button-release mouse state cybol name. */
static wchar_t* BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME = L"button-release";
static int* BUTTON_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The motion-notify mouse state cybol name. */
static wchar_t* MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME = L"motion-notify";
static int* MOTION_NOTIFY_MOUSE_STATE_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE */
#endif
