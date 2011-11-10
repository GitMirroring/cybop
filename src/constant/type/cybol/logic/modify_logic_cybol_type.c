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

#ifndef MODIFY_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE
#define MODIFY_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE

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
// Modify (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: modify
// This media type is a CYBOL extension.
//

/**
 * The modify/append cybol type.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t APPEND_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'a', L'p', L'p', L'e', L'n', L'd'};
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_TYPE = APPEND_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* APPEND_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/build cybol type.
 *
 * Build a list name.
 *
 * This is a CYBOL extension.
 */
static wchar_t BUILD_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'b', L'u', L'i', L'l', L'd'};
static wchar_t* BUILD_MODIFY_LOGIC_CYBOL_TYPE = BUILD_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* BUILD_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/count cybol type.
 *
 * Count parts of a compound part.
 *
 * This is a CYBOL extension.
 */
static wchar_t COUNT_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'c', L'o', L'u', L'n', L't'};
static wchar_t* COUNT_MODIFY_LOGIC_CYBOL_TYPE = COUNT_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* COUNT_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/get cybol type.
 *
 * Get a reference to data.
 *
 * This is a CYBOL extension.
 */
static wchar_t GET_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'g', L'e', L't'};
static wchar_t* GET_MODIFY_LOGIC_CYBOL_TYPE = GET_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* GET_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/insert cybol type.
 *
 * Insert data into other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t INSERT_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'i', L'n', L's', L'e', L'r', L't'};
static wchar_t* INSERT_MODIFY_LOGIC_CYBOL_TYPE = INSERT_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* INSERT_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/overwrite cybol type.
 *
 * Overwrite data with other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'o', L'v', L'e', L'r', L'w', L'r', L'i', L't', L'e'};
static wchar_t* OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE = OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* OVERWRITE_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The modify/remove cybol type.
 *
 * Remove data from other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t REMOVE_MODIFY_LOGIC_CYBOL_TYPE_ARRAY[] = {L'm', L'o', L'd', L'i', L'f', L'y', L'/', L'r', L'e', L'm', L'o', L'v', L'e'};
static wchar_t* REMOVE_MODIFY_LOGIC_CYBOL_TYPE = REMOVE_MODIFY_LOGIC_CYBOL_TYPE_ARRAY;
static int* REMOVE_MODIFY_LOGIC_CYBOL_TYPE_COUNT = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/* MODIFY_LOGIC_CYBOL_TYPE_CONSTANT_SOURCE */
#endif
