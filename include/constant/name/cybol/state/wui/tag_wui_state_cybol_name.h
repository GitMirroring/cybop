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

#ifndef TAG_WUI_CYBOL_NAME_CONSTANT_HEADER
#define TAG_WUI_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The tag wui state cybol name. */
static wchar_t* TAG_WUI_STATE_CYBOL_NAME = L"tag";
static int* TAG_WUI_STATE_CYBOL_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The preformatted wui state cybol name. */
static wchar_t* PREFORMATTED_WUI_STATE_CYBOL_NAME = L"preformatted";
static int* PREFORMATTED_WUI_STATE_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The property wui state cybol name. */
/*??
static wchar_t* PROPERTY_WUI_STATE_CYBOL_NAME = L"property";
static int* PROPERTY_WUI_STATE_CYBOL_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;
*/

/** The document_type wui state cybol name. */
static wchar_t* DOCUMENT_TYPE_WUI_STATE_CYBOL_NAME = L"document_type";
static int* DOCUMENT_TYPE_WUI_STATE_CYBOL_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAG_WUI_CYBOL_NAME_CONSTANT_HEADER */
#endif
