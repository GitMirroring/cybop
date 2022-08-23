/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Convert
//
// IANA media type: not defined
// Self-defined media type: convert
// This media type is a CYBOL extension.
//

/**
 * The convert/decode logic cybol format.
 *
 * Decode data from a special format into cyboi.
 * Decodes the source- into the destination part.
 *
 * CAUTION! The result gets APPENDED to the destination.
 * It does NOT overwrite already existing content in the destination.
 *
 * Expected parametres:
 * - destination (required): the destination wide character string consisting of elements of type wchar_t
 * - source (required): the source byte stream consisting of elements of type char
 * - encoding (required): the encoding
 */
static wchar_t* DECODE_CONVERT_LOGIC_CYBOL_FORMAT = L"convert/decode";
static int* DECODE_CONVERT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The convert/encode logic cybol format.
 *
 * Encode data from cyboi into a special format.
 * Encodes the source- into the destination part.
 *
 * CAUTION! The result gets APPENDED to the destination.
 * It does NOT overwrite already existing content in the destination.
 *
 * Expected parametres:
 * - destination (required): the destination byte stream consisting of elements of type char
 * - source (required): the source wide character string consisting of elements of type wchar_t
 * - encoding (required): the encoding
 */
static wchar_t* ENCODE_CONVERT_LOGIC_CYBOL_FORMAT = L"convert/encode";
static int* ENCODE_CONVERT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CONVERT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
