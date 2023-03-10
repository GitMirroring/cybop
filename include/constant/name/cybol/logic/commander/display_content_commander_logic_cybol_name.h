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

#ifndef DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

/** The path parameter for the display content logic in cybol. */
static wchar_t* PATH_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The number all output lines option for the display content logic in cybol. */
static wchar_t* NUMBER_LINES_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"number-lines";
static int* NUMBER_LINES_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The squeeze blank lines option for the display content logic in cybol. */
static wchar_t* SQUEEZE_BLANK_LINES_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"squeeze";
static int* SQUEEZE_BLANK_LINES_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear screen option for the display content logic in cybol. */
static wchar_t* CLEAR_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME = L"clear";
static int* CLEAR_DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DISPLAY_CONTENT_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
