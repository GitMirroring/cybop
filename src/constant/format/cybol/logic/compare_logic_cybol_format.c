/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Compare (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: compare
// This media type is a CYBOL extension.
//

/**
 * The compare/equal logic cybol format.
 *
 * Compare for equality: ==
 *
 * This is a CYBOL extension.
 */
static wchar_t* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/equal";
static int* EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater logic cybol format.
 *
 * Compare for greaterness: >
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREATER_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater";
static int* GREATER_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/greater-or-equal logic cybol format.
 *
 * Compare for greaterness or equality: >=
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/greater-or-equal";
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/smaller logic cybol format.
 *
 * Compare for smallerness: <
 *
 * This is a CYBOL extension.
 */
static wchar_t* SMALLER_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/smaller";
static int* SMALLER_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/smaller-or-equal logic cybol format.
 *
 * Compare for smallerness or equality: <=
 *
 * This is a CYBOL extension.
 */
static wchar_t* SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/smaller-or-equal";
static int* SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The compare/unequal logic cybol format.
 *
 * Compare for unequality: !=
 *
 * This is a CYBOL extension.
 */
static wchar_t* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT = L"compare/unequal";
static int* UNEQUAL_COMPARE_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
