/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Logify (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: logify
// This media type is a CYBOL extension.
//

/**
 * The logify/and logic cybol format.
 *
 * Apply a boolean AND operation.
 *
 * result = x AND y
 *
 * This is a CYBOL extension.
 */
static wchar_t* AND_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/and";
static int* AND_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/nand logic cybol format.
 *
 * Apply a boolean NAND operation.
 *
 * result = x NAND y
 *
 * This is a CYBOL extension.
 */
static wchar_t* NAND_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nand";
static int* NAND_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/neg logic cybol format.
 *
 * Apply a boolean NEG operation.
 * When used with Bit operands, then this is the TWO'S COMPLEMENT (all bits negated and added one).
 *
 * result = x NEG y
 *
 * This is a CYBOL extension.
 */
static wchar_t* NEG_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/neg";
static int* NEG_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/nor logic cybol format.
 *
 * Apply a boolean NOR operation.
 *
 * result = x NOR y
 *
 * This is a CYBOL extension.
 */
static wchar_t* NOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/nor";
static int* NOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/not logic cybol format.
 *
 * Apply a boolean NOT operation.
 * When used with Bit operands, then this is the ONE'S COMPLEMENT (all bits negated).
 *
 * result = x NOT y
 *
 * This is a CYBOL extension.
 */
static wchar_t* NOT_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/not";
static int* NOT_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/or logic cybol format.
 *
 * Apply a boolean OR operation.
 *
 * result = x OR y
 *
 * This is a CYBOL extension.
 */
static wchar_t* OR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/or";
static int* OR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xnor logic cybol format.
 *
 * Apply a boolean XNOR operation.
 *
 * result = x XNOR y
 *
 * This is a CYBOL extension.
 */
static wchar_t* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xnor";
static int* XNOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The logify/xor logic cybol format.
 *
 * Apply a boolean XOR operation.
 *
 * result = x XOR y
 *
 * This is a CYBOL extension.
 */
static wchar_t* XOR_LOGIFY_LOGIC_CYBOL_FORMAT = L"logify/xor";
static int* XOR_LOGIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
