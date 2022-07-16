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

#ifndef MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Modify
//
// IANA media type: not defined
// Self-defined media type: modify
// This media type is a CYBOL extension.
//

/**
 * The modify/append logic cybol format.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/append";
static int* APPEND_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/concatenate logic cybol format.
 *
 * Concatenate strings given as child nodes of the source part into the destination part.
 * Optionally provide a cybol property "separator" as character sequence
 * added between the concatenated strings.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CONCATENATE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/concatenate";
static int* CONCATENATE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/empty logic cybol format.
 *
 * Empty all data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/empty";
static int* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/fill logic cybol format.
 *
 * Fills places of a container with a given initialisation element.
 *
 * This is a CYBOL extension.
 */
static wchar_t* FILL_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/fill";
static int* FILL_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/insert logic cybol format.
 *
 * Insert data into other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* INSERT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/insert";
static int* INSERT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/lower logic cybol format.
 *
 * Convert string to lower case letters.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LOWER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/lower";
static int* LOWER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/normalise logic cybol format.
 *
 * Remove leading and trailing whitespaces and additionally
 * replace all internal sequences of white space with one
 * (useful e.g. when parsing xml or html of a webpage).
 *
 * This is a CYBOL extension.
 */
static wchar_t* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/normalise";
static int* NORMALISE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/overwrite logic cybol format.
 *
 * Overwrite data with other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/overwrite";
static int* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/remove logic cybol format.
 *
 * Remove data from other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/remove";
static int* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/repeat logic cybol format.
 *
 * Produce a string whose value is the concatenation of the source string repeated count times.
 *
 * This is a CYBOL extension.
 */
static wchar_t* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/repeat";
static int* REPEAT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/replace logic cybol format.
 *
 * Replace searched character sequence with a new sequence.
 *
 * This is a CYBOL extension.
 */
static wchar_t* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/replace";
static int* REPLACE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/reverse logic cybol format.
 *
 * Reverse the order of child nodes of the source part storing them in the destination part.
 *
 * This is a CYBOL extension.
 */
static wchar_t* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/reverse";
static int* REVERSE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/split logic cybol format.
 *
 * Split string into parts which are stored as child nodes of the destination part.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SPLIT_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/split";
static int* SPLIT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip logic cybol format.
 *
 * Remove leading and trailing whitespaces.
 *
 * This is a CYBOL extension.
 */
static wchar_t* STRIP_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip";
static int* STRIP_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-leading logic cybol format.
 *
 * Remove leading whitespaces.
 *
 * This is a CYBOL extension.
 */
static wchar_t* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-leading";
static int* STRIP_LEADING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/strip-trailing logic cybol format.
 *
 * Remove trailing whitespaces.
 *
 * This is a CYBOL extension.
 */
static wchar_t* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/strip-trailing";
static int* STRIP_TRAILING_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/upper logic cybol format.
 *
 * Convert string to upper case letters.
 *
 * This is a CYBOL extension.
 */
static wchar_t* UPPER_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/upper";
static int* UPPER_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
