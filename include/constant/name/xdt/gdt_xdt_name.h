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

#ifndef GDT_XDT_NAME_CONSTANT_HEADER
#define GDT_XDT_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The send sequence counter gdt xdt name. */
static int* SEND_SEQUENCE_COUNTER_GDT_XDT_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification data gdt xdt name. */
static int* IDENTIFICATION_DATA_GDT_XDT_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The field gdt xdt name. */
static int* FIELD_GDT_XDT_NAME_MAXIMUM_COUNT = NUMBER_128_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bdt line end (file separator) gdt xdt name. */
static wchar_t BDT_LINE_END_GDT_XDT_NAME_ARRAY[] = { 0x001C };
static wchar_t* BDT_LINE_END_GDT_XDT_NAME = BDT_LINE_END_GDT_XDT_NAME_ARRAY;
static int* BDT_LINE_END_GDT_XDT_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The checksum (crc-16) gdt xdt name. */
static int* CHECKSUM_GDT_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end block (carriage return) gdt xdt name. */
static wchar_t END_BLOCK_GDT_XDT_NAME_ARRAY[] = { 0x000D };
static wchar_t* END_BLOCK_GDT_XDT_NAME = END_BLOCK_GDT_XDT_NAME_ARRAY;
static int* END_BLOCK_GDT_XDT_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* GDT_XDT_NAME_CONSTANT_HEADER */
#endif
