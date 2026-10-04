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
 * @author Franziska Wehner
 */

#ifndef DRAWING_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define DRAWING_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Drawing
//
// IANA media type: drawing
//

/**
 * The drawing/x-dwf state cybol format.
 *
 * Drawing files.
 * Registered.
 * Common file suffixes: dwf
 */
static wchar_t* X_DWF_DRWAING_STATE_CYBOL_FORMAT = L"drawing/x-dwf";
static int* X_DWF_DRAWING_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DRAWING_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
