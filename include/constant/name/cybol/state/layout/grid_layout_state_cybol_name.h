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

#ifndef GRID_LAYOUT_STATE_CYBOL_NAME_CONSTANT_HEADER
#define GRID_LAYOUT_STATE_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The columns grid layout state cybol name. */
static wchar_t* COLUMNS_GRID_LAYOUT_STATE_CYBOL_NAME = L"columns";
static int* COLUMNS_GRID_LAYOUT_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rows grid layout state cybol name. */
static wchar_t* ROWS_GRID_LAYOUT_STATE_CYBOL_NAME = L"rows";
static int* ROWS_GRID_LAYOUT_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* GRID_LAYOUT_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
