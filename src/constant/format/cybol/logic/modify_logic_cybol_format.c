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
static wchar_t* APPEND_MODIFY_LOGIC_CYBOL_FORMAT = L"modify/append";
static int* APPEND_MODIFY_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/* MODIFY_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
