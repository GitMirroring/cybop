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

#ifndef FILL_RULE_XCB_CYBOL_MODEL_CONSTANT_HEADER
#define FILL_RULE_XCB_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Possible values:
//
// XCB_FILL_RULE_EVEN_ODD
// XCB_FILL_RULE_WINDING
//

/** The even-odd fill rule xcb cybol model. */
static wchar_t* EVEN_ODD_FILL_RULE_XCB_CYBOL_MODEL = L"even-odd";
static int* EVEN_ODD_FILL_RULE_XCB_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The winding fill rule xcb cybol model. */
static wchar_t* WINDING_FILL_RULE_XCB_CYBOL_MODEL = L"winding";
static int* WINDING_FILL_RULE_XCB_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* FILL_RULE_XCB_CYBOL_MODEL_CONSTANT_HEADER */
#endif
