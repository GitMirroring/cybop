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

#ifndef ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Access (some operation to be processed over time).
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
 */
static wchar_t* COUNT_ACCESS_LOGIC_CYBOL_FORMAT = L"access/count";
static int* COUNT_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-channel logic cybol format.
 *
 * Get a part's channel.
 *
 * This is a CYBOL extension.
 */
static wchar_t* CHANNEL_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-channel";
static int* CHANNEL_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-encoding logic cybol format.
 *
 * Get a part's encoding.
 *
 * This is a CYBOL extension.
 */
static wchar_t* ENCODING_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-encoding";
static int* ENCODING_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-format logic cybol format.
 *
 * Get a part's format.
 *
 * This is a CYBOL extension.
 */
static wchar_t* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-format";
static int* FORMAT_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-index logic cybol format.
 *
 * Get a part's index within a whole.
 *
 * This is a CYBOL extension.
 */
static wchar_t* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-index";
static int* GET_INDEX_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-language logic cybol format.
 *
 * Get a part's language.
 *
 * This is a CYBOL extension.
 */
static wchar_t* LANGUAGE_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-language";
static int* LANGUAGE_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-name logic cybol format.
 *
 * Get a part's name.
 *
 * This is a CYBOL extension.
 */
static wchar_t* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-name";
static int* NAME_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/get-type logic cybol format.
 *
 * Get a part's type.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT = L"access/get-type";
static int* TYPE_GET_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-empty logic cybol format.
 *
 * Indicates if data are empty, i.e. the count is zero.
 *
 * This is a CYBOL extension.
 */
static wchar_t* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-empty";
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The access/indicate-exists logic cybol format.
 *
 * Indicates if data exist, i.e. the count is greater than zero.
 *
 * This is a CYBOL extension.
 */
static wchar_t* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT = L"access/indicate-exists";
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ACCESS_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
