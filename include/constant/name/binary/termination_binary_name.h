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

#ifndef TERMINATION_BINARY_NAME_CONSTANT_HEADER
#define TERMINATION_BINARY_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Binary data.
//

/**
 * The crlf termination binary name.
 *
 * carriage return (cr)
 * line feed (lf)
 */
static unsigned char CRLF_TERMINATION_BINARY_NAME_ARRAY[] = { 0x0D, 0x0A };
static unsigned char* CRLF_TERMINATION_BINARY_NAME = CRLF_TERMINATION_BINARY_NAME_ARRAY;
static int* CRLF_TERMINATION_BINARY_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TERMINATION_BINARY_NAME_CONSTANT_HEADER */
#endif
