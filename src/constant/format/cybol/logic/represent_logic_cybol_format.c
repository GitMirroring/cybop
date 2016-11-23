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

#ifndef REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE
#define REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Represent (some operation to be processed over time).
//
// IANA media type: not defined
// Self-defined media type: represent
// This media type is a CYBOL extension.
//

/**
 * The represent/deserialise logic cybol format.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/deserialise";
static int* DESERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The represent/serialise logic cybol format.
 *
 * Append data to other data.
 *
 * This is a CYBOL extension.
 */
static wchar_t* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT = L"represent/serialise";
static int* SERIALISE_REPRESENT_LOGIC_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REPRESENT_LOGIC_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
