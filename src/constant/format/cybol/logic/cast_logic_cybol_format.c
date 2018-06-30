/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The CYBOL type constants' names and values have been adapted to follow
// the style of the Internet media type / content type that is also
// known under the name Multipurpose Internet Mail Extensions (MIME).
// These types are managed by the Internet Assigned Numbers Authority (IANA).
// See document "Multipurpose Internet Mail Extensions (MIME) Part Two: Media Types":
// http://tools.ietf.org/html/rfc2046
//
// Since the MIME standard does not offer media types for certain data,
// CYBOL had to invent new languages (media types), e.g. for dates, numbers etc.
// This is not meant to pollute the MIME standard, just to fill a gap!
// In case IANA adopts these extensions one day -- fine.
// If, however, other media type values replacing ours are proposed,
// we are open to adapt the CYBOL language specification accordingly.
//

//
// Cast (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: cast
// This media type is a CYBOL extension.
//

/**
 * The cast/byte logic cybol format.
 *
 * Cast value to type byte.
 *
 * This is a CYBOL extension.
 */
static wchar_t* BYTE_CAST_LOGIC_CYBOL_FORMAT = L"cast/byte";
static int* BYTE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/character logic cybol format.
 *
 * Cast value to type character.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CHARACTER_CAST_LOGIC_CYBOL_FORMAT = L"cast/character";
static int* CHARACTER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/double logic cybol format.
 *
 * Cast value to type double.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DOUBLE_CAST_LOGIC_CYBOL_FORMAT = L"cast/double";
static int* DOUBLE_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The cast/integer logic cybol format.
 *
 * Cast value to type integer.
 *
 * This is a CYBOL extension.
 */
static wchar_t* INTEGER_CAST_LOGIC_CYBOL_FORMAT = L"cast/integer";
static int* INTEGER_CAST_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CAST_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
