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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef GUI_STATE_CYBOL_NAME_CONSTANT_HEADER
#define GUI_STATE_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The background gui state cybol name. */
static wchar_t* BACKGROUND_GUI_STATE_CYBOL_NAME = L"background";
static int* BACKGROUND_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cap-style gui state cybol name. */
static wchar_t* CAP_STYLE_GUI_STATE_CYBOL_NAME = L"cap-style";
static int* CAP_STYLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cell gui state cybol name. */
static wchar_t* CELL_GUI_STATE_CYBOL_NAME = L"cell";
static int* CELL_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The direction gui state cybol name. */
static wchar_t* DIRECTION_GUI_STATE_CYBOL_NAME = L"direction";
static int* DIRECTION_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fill-style gui state cybol name. */
static wchar_t* FILL_STYLE_GUI_STATE_CYBOL_NAME = L"fill-style";
static int* FILL_STYLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fill-rule gui state cybol name. */
static wchar_t* FILL_RULE_GUI_STATE_CYBOL_NAME = L"fill-rule";
static int* FILL_RULE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The font gui state cybol name. */
static wchar_t* FONT_GUI_STATE_CYBOL_NAME = L"font";
static int* FONT_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The foreground gui state cybol name. */
static wchar_t* FOREGROUND_GUI_STATE_CYBOL_NAME = L"foreground";
static int* FOREGROUND_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The icon gui state cybol name. */
static wchar_t* ICON_GUI_STATE_CYBOL_NAME = L"icon";
static int* ICON_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The icon_title gui state cybol name. */
static wchar_t* ICON_TITLE_GUI_STATE_CYBOL_NAME = L"icon_title";
static int* ICON_TITLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The join-style gui state cybol name. */
static wchar_t* JOIN_STYLE_GUI_STATE_CYBOL_NAME = L"join-style";
static int* JOIN_STYLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The layout gui state cybol name. */
static wchar_t* LAYOUT_GUI_STATE_CYBOL_NAME = L"layout";
static int* LAYOUT_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line-width gui state cybol name. */
static wchar_t* LINE_WIDTH_GUI_STATE_CYBOL_NAME = L"line-width";
static int* LINE_WIDTH_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line-style gui state cybol name. */
static wchar_t* LINE_STYLE_GUI_STATE_CYBOL_NAME = L"line-style";
static int* LINE_STYLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The position gui state cybol name. */
static wchar_t* POSITION_GUI_STATE_CYBOL_NAME = L"position";
static int* POSITION_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shape gui state cybol name. */
static wchar_t* SHAPE_GUI_STATE_CYBOL_NAME = L"shape";
static int* SHAPE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The size gui state cybol name. */
static wchar_t* SIZE_GUI_STATE_CYBOL_NAME = L"size";
static int* SIZE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The stretch gui state cybol name. */
static wchar_t* STRETCH_GUI_STATE_CYBOL_NAME = L"stretch";
static int* STRETCH_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The title gui state cybol name. */
static wchar_t* TITLE_GUI_STATE_CYBOL_NAME = L"title";
static int* TITLE_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The window gui state cybol name. */
static wchar_t* WINDOW_GUI_STATE_CYBOL_NAME = L"window";
static int* WINDOW_GUI_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* GUI_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
