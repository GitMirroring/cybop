/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COLOUR_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define COLOUR_STATE_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// Colour (colour formats)
//
// IANA media type: not defined
// Self-defined media type: colour
// This media type is a CYBOL extension.
//

/**
 * The colour/cmyk state cybol format.
 *
 * TODO: Description:
 *
 * A colour whose values are given in the CMYK colour model,
 * also referred to as process color or four color.
 *
 * The abbreviation CMYK refers to the four ink plates used in some
 * colour printing: cyan, magenta, yellow, and key (black).
 *
 * TODO: Examples:
 *
 * <node name="value" channel="inline" format="colour/cmyk" model="60,34,0,19"/>
 */
static wchar_t* CMYK_COLOUR_STATE_CYBOL_FORMAT = L"colour/cmyk";
static int* CMYK_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colour/rgb state cybol format.
 *
 * Description:
 *
 * A colour whose values are given in the RGB colour model.
 *
 * The abbreviation RGB refers to the three colours:
 * red, green, and blue.
 *
 * Examples:
 *
 * <node name="value" channel="inline" format="colour/rgb" model="82,135,206"/>
 */
static wchar_t* RGB_COLOUR_STATE_CYBOL_FORMAT = L"colour/rgb";
static int* RGB_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The colour/terminal state cybol format.
 *
 * Description:
 *
 * A terminal colour value as written word representing the pre-defined colour name.
 *
 * Examples:
 *
 * <node name="foreground" channel="inline" format="colour/terminal" model="blue"/>
 * <node name="background" channel="inline" format="colour/terminal" model="white"/>
 */
static wchar_t* TERMINAL_COLOUR_STATE_CYBOL_FORMAT = L"colour/terminal";
static int* TERMINAL_COLOUR_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COLOUR_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
