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

#ifndef MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE
#define MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The left-press mouse state cybol name. */
static wchar_t LEFT_PRESS_MOUSE_STATE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'-', L'p', L'r', L'e', L's', L's'};
static wchar_t* LEFT_PRESS_MOUSE_STATE_CYBOL_NAME = LEFT_PRESS_MOUSE_STATE_CYBOL_NAME_ARRAY;
static int* LEFT_PRESS_MOUSE_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left-release mouse state cybol name. */
static wchar_t LEFT_RELEASE_MOUSE_STATE_CYBOL_NAME_ARRAY[] = {L'l', L'e', L'f', L't', L'-', L'r', L'e', L'l', L'e', L'a', L's', L'e'};
static wchar_t* LEFT_RELEASE_MOUSE_STATE_CYBOL_NAME = LEFT_RELEASE_MOUSE_STATE_CYBOL_NAME_ARRAY;
static int* LEFT_RELEASE_MOUSE_STATE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MOUSE_STATE_CYBOL_NAME_CONSTANT_SOURCE */
#endif
