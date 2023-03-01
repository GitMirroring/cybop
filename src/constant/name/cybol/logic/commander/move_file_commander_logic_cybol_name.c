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

#ifndef MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE
#define MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The force parameter for the move logic in cybol. */
static wchar_t* FORCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"force";
static int* FORCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source path parameter for the move logic in cybol. */
static wchar_t* SOURCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"source";
static int* SOURCE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destination path parameter for the move logic in cybol. */
static wchar_t* DESTINATION_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"destination";
static int* DESTINATION_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive parameter for the move logic in cybol. */
static wchar_t* INTERACTIVE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"interactive";
static int* INTERACTIVE_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal parameter for the move logic in cybol. */
static wchar_t* VERBAL_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"verbal";
static int* VERBAL_MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MOVE_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_SOURCE */
#endif
