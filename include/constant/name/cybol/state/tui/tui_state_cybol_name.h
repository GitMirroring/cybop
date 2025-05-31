/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TUI_STATE_CYBOL_NAME_CONSTANT_HEADER
#define TUI_STATE_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The background tui state cybol name. */
static wchar_t* BACKGROUND_TUI_STATE_CYBOL_NAME = L"background";
static int* BACKGROUND_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The blink tui state cybol name. */
static wchar_t* BLINK_TUI_STATE_CYBOL_NAME = L"blink";
static int* BLINK_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bold tui state cybol name. */
static wchar_t* BOLD_TUI_STATE_CYBOL_NAME = L"bold";
static int* BOLD_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The border tui state cybol name. */
static wchar_t* BORDER_TUI_STATE_CYBOL_NAME = L"border";
static int* BORDER_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The foreground tui state cybol name. */
static wchar_t* FOREGROUND_TUI_STATE_CYBOL_NAME = L"foreground";
static int* FOREGROUND_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hidden tui state cybol name. */
static wchar_t* HIDDEN_TUI_STATE_CYBOL_NAME = L"hidden";
static int* HIDDEN_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The intense tui state cybol name. */
static wchar_t* INTENSE_TUI_STATE_CYBOL_NAME = L"intense";
static int* INTENSE_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The inverse tui state cybol name. */
static wchar_t* INVERSE_TUI_STATE_CYBOL_NAME = L"inverse";
static int* INVERSE_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The position tui state cybol name. */
static wchar_t* POSITION_TUI_STATE_CYBOL_NAME = L"position";
static int* POSITION_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The size tui state cybol name. */
static wchar_t* SIZE_TUI_STATE_CYBOL_NAME = L"size";
static int* SIZE_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The underline tui state cybol name. */
static wchar_t* UNDERLINE_TUI_STATE_CYBOL_NAME = L"underline";
static int* UNDERLINE_TUI_STATE_CYBOL_NAME_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TUI_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
