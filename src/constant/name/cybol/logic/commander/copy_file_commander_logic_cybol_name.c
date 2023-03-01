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

#ifndef COPY_FILE_COMMANDER_OPTION_NAME_CONSTANT_SOURCE
#define COPY_FILE_COMMANDER_OPTION_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The destination copy file logic cybol name. */
static wchar_t* DESTINATION_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"destination";
static int* DESTINATION_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The force copy file logic cybol name. */
static wchar_t* FORCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"force";
static int* FORCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interactive copy file logic cybol name. */
static wchar_t* INTERACTIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"interactive";
static int* INTERACTIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserver all attributes copy file logic cybol name. */
static wchar_t* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"preserve-all-attributes";
static int* PRESERVE_ALL_ATTRIBUTES_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preserver links copy file logic cybol name. */
static wchar_t* PRESERVE_LINKS_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"preserve-links";
static int* PRESERVE_LINKS_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The recursive copy file logic cybol name. */
static wchar_t* RECURSIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"recursive";
static int* RECURSIVE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The source copy file logic cybol name. */
static wchar_t* SOURCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"source";
static int* SOURCE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The update copy file logic cybol name. */
static wchar_t* UPDATE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"update";
static int* UPDATE_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The verbal copy file logic cybol name. */
static wchar_t* VERBAL_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"verbal";
static int* VERBAL_COPY_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COPY_FILE_COMMANDER_OPTION_NAME_CONSTANT_SOURCE */
#endif
