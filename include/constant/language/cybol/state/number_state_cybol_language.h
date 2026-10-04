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

#ifndef NUMBER_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER
#define NUMBER_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Number
//
// IANA media type: not defined
// Self-defined media type: number
// This media type is a CYBOL extension.
//

/**
 * The number/terminal-mode state cybol language.
 *
 * CYBOL (XML) format.
 * Defined in CYBOL specification:
 * http://www.nongnu.org/cybop/books/cybol/cybol.pdf
 */
static wchar_t* TERMINAL_MODE_NUMBER_STATE_CYBOL_LANGUAGE = L"number/terminal-mode";
static int* TERMINAL_MODE_NUMBER_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* NUMBER_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER */
#endif
