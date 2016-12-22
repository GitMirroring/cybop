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

#ifndef COLOUR_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define COLOUR_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Colour (colour formats).
//
// IANA media type: not defined
// Self-defined media type: colour
// This media type is a CYBOL extension.
//

/**
 * The colour/cmyk state cybol format.
 *
 * Cyan, Magenta, Yellow, Key (black) (CMYK) colour model,
 * also referred to as "process color" or "four color".
 *
 * This is a CYBOL extension.
 */
static wchar_t* CMYK_COLOUR_STATE_CYBOL_FORMAT = L"colour/cmyk";
static int* CMYK_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colour/rgb state cybol format.
 *
 * Red, Green, Blue colour model.
 *
 * This is a CYBOL extension.
 */
static wchar_t* RGB_COLOUR_STATE_CYBOL_FORMAT = L"colour/rgb";
static int* RGB_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colour/terminal state cybol format.
 *
 * Terminal colour name as written word.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TERMINAL_COLOUR_STATE_CYBOL_FORMAT = L"colour/terminal";
static int* TERMINAL_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COLOUR_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
