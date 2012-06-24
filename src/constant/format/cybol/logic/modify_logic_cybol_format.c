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

#ifndef MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Modify (some operation to be processed over time).
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
static wchar_t APPEND_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'a', L'p', L'p', L'e', L'n', L'd'};
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_FORMAT = APPEND_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* APPEND_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/build logic cybol format.
 *
 * Build a list name.
 *
 * This is a CYBOL extension.
 */
static wchar_t BUILD_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'b', L'u', L'i', L'l', L'd'};
static wchar_t* BUILD_MODIFY_LOGIC_CYBOL_FORMAT = BUILD_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* BUILD_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/count logic cybol format.
 *
 * Count parts of a compound part.
 *
 * This is a CYBOL extension.
 */
static wchar_t COUNT_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_MODIFY_LOGIC_CYBOL_FORMAT = COUNT_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* COUNT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/empty logic cybol format.
 *
 * Empty all data.
 *
 * This is a CYBOL extension.
 */
static wchar_t EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'e', L'm', L'p', L't', L'y'};
static wchar_t* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT = EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* EMPTY_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/get logic cybol format.
 *
 * Get a reference to data.
 *
 * This is a CYBOL extension.
 */
static wchar_t GET_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'g', L'e', L't'};
static wchar_t* GET_MODIFY_LOGIC_CYBOL_FORMAT = GET_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* GET_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/indicate-empty logic cybol format.
 *
 * Indicates if data are empty, i.e. the count is zero.
 *
 * This is a CYBOL extension.
 */
static wchar_t EMPTY_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'i', L'n', L'd', L'i', L'c', L'a', L't', L'e', L'-', L'e', L'm', L'p', L't', L'y'};
static wchar_t* EMPTY_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT = EMPTY_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* EMPTY_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/indicate-exists logic cybol format.
 *
 * Indicates if data exist, i.e. the count is greater than zero.
 *
 * This is a CYBOL extension.
 */
static wchar_t EXISTS_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'i', L'n', L'd', L'i', L'c', L'a', L't', L'e', L'-', L'e', L'x', L'i', L's', L't', L's'};
static wchar_t* EXISTS_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT = EXISTS_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* EXISTS_INDICATE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/insert logic cybol format.
 *
 * Insert data into other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t INSERT_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'i', L'n', L's', L'e', L'r', L't'};
static wchar_t* INSERT_MODIFY_LOGIC_CYBOL_FORMAT = INSERT_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* INSERT_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/overwrite logic cybol format.
 *
 * Overwrite data with other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L'e'};
static wchar_t* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT = OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* OVERWRITE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The modify/remove logic cybol format.
 *
 * Remove data from other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'r', L'e', L'm', L'o', L'v', L'e'};
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT = REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_ARRAY;
static int* REMOVE_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
