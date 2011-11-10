/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONVERT_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE
#define CONVERT_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/memory/integer_memory_model.c"

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
// Convert (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: convert
// This media type is a CYBOL extension.
//

/**
 * The convert/decode cybol type.
 *
 * Decode data from a special format into cyboi.
 *
 * This is a CYBOL extension.
 */
static wchar_t DECODE_CONVERT_LOGIC_CYBOL_TYPE_ARRAY[] = {L'c', L'o', L'n', L'v', L'e', L'r', L't', L'/', L'd', L'e', L'c', L'o', L'd', L'e'};
static wchar_t* DECODE_CONVERT_LOGIC_CYBOL_TYPE = DECODE_CONVERT_LOGIC_CYBOL_TYPE_ARRAY;
static int* DECODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The convert/encode cybol type.
 *
 * Encode data from cyboi into a special format.
 *
 * This is a CYBOL extension.
 */
static wchar_t ENCODE_CONVERT_LOGIC_CYBOL_TYPE_ARRAY[] = {L'c', L'o', L'n', L'v', L'e', L'r', L't', L'/', L'e', L'n', L'c', L'o', L'd', L'e'};
static wchar_t* ENCODE_CONVERT_LOGIC_CYBOL_TYPE = ENCODE_CONVERT_LOGIC_CYBOL_TYPE_ARRAY;
static int* ENCODE_CONVERT_LOGIC_CYBOL_TYPE_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/* CONVERT_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE */
#endif
