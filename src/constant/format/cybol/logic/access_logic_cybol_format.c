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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Access
//
// IANA media type: not defined
// Self-defined media type: access
// This media type is a CYBOL extension.
//

/**
 * The access/count logic cybol format.
 *
 * Count parts of a compound part.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - count (required): the knowledge model in which to store the result
 * - part (required): the part whose elements are to be counted
 * - selection (optional; if null, the element count is returned without any comparison):
 *   the area of the elements' names to be compared;
 *   may be one of: all, prefix, suffix, subsequence
 * - filter (optional; corresponds with "selection" property):
 *   string to compare the elements' names with;
 *   only those parts will be counted whose name matches the filter string
 */
static wchar_t* COUNT_ACCESS_LOGIC_CYBOL_FORMAT = L"access/count";
static int* COUNT_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-format logic cybol format.
 *
 * Get a part's format.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
 */
static wchar_t* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-format";
static int* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-index logic cybol format.
 *
 * Gets the index of the part within the whole.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - index (required): the determined index of the part
 * - part (required): the name of the part whose index is to be determined
 * - whole (required): the compound within which the part is situated
 */
static wchar_t* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-index";
static int* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-name logic cybol format.
 *
 * Get a part's name.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
 */
static wchar_t* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-name";
static int* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-type logic cybol format.
 *
 * Get a part's type.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
 */
static wchar_t* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-type";
static int* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-empty logic cybol format.
 *
 * Indicates if data are empty, i.e. the count is zero.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - result (required): the result flag
 *   (set to true upon successful comparison; left untouched otherwise)
 * - part (required): the part
 */
static wchar_t* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-empty";
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-exists logic cybol format.
 *
 * Indicates if data exist, i.e. the count is greater than zero.
 *
 * This is a CYBOL extension.
 *
 * Expected parametres:
 * - result (required): the result flag
 *   (set to true upon successful comparison; left untouched otherwise)
 * - part (required): the part
 */
static wchar_t* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-exists";
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
