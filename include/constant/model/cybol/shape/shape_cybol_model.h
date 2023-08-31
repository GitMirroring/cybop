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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SHAPE_CYBOL_MODEL_CONSTANT_HEADER
#define SHAPE_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The arc shape cybol model. */
static wchar_t* ARC_SHAPE_CYBOL_MODEL = L"arc";
static int* ARC_SHAPE_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The button shape cybol model. */
static wchar_t* BUTTON_SHAPE_CYBOL_MODEL = L"button";
static int* BUTTON_SHAPE_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filled_arc shape cybol model. */
static wchar_t* FILLED_ARC_SHAPE_CYBOL_MODEL = L"filled_arc";
static int* FILLED_ARC_SHAPE_CYBOL_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filled_polygon shape cybol model. */
static wchar_t* FILLED_POLYGON_SHAPE_CYBOL_MODEL = L"filled_polygon";
static int* FILLED_POLYGON_SHAPE_CYBOL_MODEL_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The filled_rectangle shape cybol model. */
static wchar_t* FILLED_RECTANGLE_SHAPE_CYBOL_MODEL = L"filled_rectangle";
static int* FILLED_RECTANGLE_SHAPE_CYBOL_MODEL_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The label shape cybol model. */
static wchar_t* LABEL_SHAPE_CYBOL_MODEL = L"label";
static int* LABEL_SHAPE_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The point shape cybol model. */
static wchar_t* POINT_SHAPE_CYBOL_MODEL = L"point";
static int* POINT_SHAPE_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The polygon shape cybol model. */
static wchar_t* POLYGON_SHAPE_CYBOL_MODEL = L"polygon";
static int* POLYGON_SHAPE_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rectangle shape cybol model. */
static wchar_t* RECTANGLE_SHAPE_CYBOL_MODEL = L"rectangle";
static int* RECTANGLE_SHAPE_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The segment shape cybol model. */
static wchar_t* SEGMENT_SHAPE_CYBOL_MODEL = L"segment";
static int* SEGMENT_SHAPE_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SHAPE_CYBOL_MODEL_CONSTANT_HEADER */
#endif
