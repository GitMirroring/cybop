/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEARCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define SEARCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The backward searching logic cybol name. */
static wchar_t* BACKWARD_SEARCHING_LOGIC_CYBOL_NAME = L"backward";
static int* BACKWARD_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The index searching logic cybol name. */
static wchar_t* INDEX_SEARCHING_LOGIC_CYBOL_NAME = L"index";
static int* INDEX_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list searching logic cybol name. */
static wchar_t* LIST_SEARCHING_LOGIC_CYBOL_NAME = L"list";
static int* LIST_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model searching logic cybol name. */
static wchar_t* MODEL_SEARCHING_LOGIC_CYBOL_NAME = L"model";
static int* MODEL_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The perfectmatch searching logic cybol name. */
static wchar_t* PERFECTMATCH_SEARCHING_LOGIC_CYBOL_NAME = L"perfectmatch";
static int* PERFECTMATCH_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The searchword searching logic cybol name. */
static wchar_t* SEARCHWORD_SEARCHING_LOGIC_CYBOL_NAME = L"searchword";
static int* SEARCHWORD_SEARCHING_LOGIC_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEARCHING_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
