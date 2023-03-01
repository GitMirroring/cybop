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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TOUCH_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define TOUCH_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The path for the touch logic cybol name.
 */
static wchar_t* PATH_TOUCH_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_TOUCH_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The reference for the touch logic cybol name.
 *
 * It indicates the timestamp of another file used instead of standard.
 */
static wchar_t* REFERENCE_TOUCH_COMMANDER_LOGIC_CYBOL_NAME = L"reference";
static int* REFERENCE_TOUCH_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The timestamp for the touch logic cybol name.
 *
 * It indicates the timestamp for the file.
 */
static wchar_t* TIMESTAMP_TOUCH_COMMANDER_LOGIC_CYBOL_NAME = L"timestamp";
static int* TIMESTAMP_TOUCH_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TOUCH_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
