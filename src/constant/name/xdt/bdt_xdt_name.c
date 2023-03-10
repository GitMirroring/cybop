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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef BDT_XDT_NAME_CONSTANT_HEADER
#define BDT_XDT_NAME_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The size field bdt xdt name. */
static int* SIZE_FIELD_BDT_XDT_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The identification field bdt xdt name. */
static int* IDENTIFICATION_FIELD_BDT_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The content field bdt xdt name. */
static int* CONTENT_FIELD_BDT_XDT_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end (carriage return, line feed) field bdt xdt name. */
static wchar_t END_FIELD_BDT_XDT_NAME_ARRAY[] = { 0x000D, 0x000A };
static wchar_t* END_FIELD_BDT_XDT_NAME = END_FIELD_BDT_XDT_NAME_ARRAY;
static int* END_FIELD_BDT_XDT_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* BDT_XDT_NAME_CONSTANT_HEADER */
#endif
