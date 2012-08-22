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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATE_CYBOI_FORMAT_CONSTANT_SOURCE
#define STATE_CYBOI_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// CAUTION! However, STATE and LOGIC constants have been split into TWO files.
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..499
// - logic constants: 500..999
//

//
// colour
//

/** The cmyk colour state cyboi format. */
static int* CMYK_COLOUR_STATE_CYBOI_FORMAT = NUMBER_180_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rgb colour state cyboi format. */
static int* RGB_COLOUR_STATE_CYBOI_FORMAT = NUMBER_181_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal colour state cyboi format. */
static int* TERMINAL_COLOUR_STATE_CYBOI_FORMAT = NUMBER_182_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// datetime
//

/** The yyyy-mm-dd datetime state cyboi format. */
static int* YYYY_MM_DD_DATETIME_STATE_CYBOI_FORMAT = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hh-mm-ss datetime state cyboi format. */
static int* HH_MM_SS_DATETIME_STATE_CYBOI_FORMAT = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yyyymmddthhmmss datetime state cyboi format. */
static int* YYYYMMDDTHHMMSS_DATETIME_STATE_CYBOI_FORMAT = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-hhmm datetime state cyboi format. */
static int* XDT_DATE_HHMM_DATETIME_STATE_CYBOI_FORMAT = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-hhmmhhmm datetime state cyboi format. */
static int* XDT_DATE_HHMMHHMM_DATETIME_STATE_CYBOI_FORMAT = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-yymmnnn datetime state cyboi format. */
static int* XDT_DATE_YYMMNNN_DATETIME_STATE_CYBOI_FORMAT = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-ddmmyyyy datetime state cyboi format. */
static int* XDT_DATE_DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-mmyy datetime state cyboi format. */
static int* XDT_DATE_MMYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_207_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-ddmmyyyyddmmyyyy datetime state cyboi format. */
static int* XDT_DATE_DDMMYYYYDDMMYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_208_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-time-hhmmss datetime state cyboi format. */
static int* XDT_TIME_HHMMSS_DATETIME_STATE_CYBOI_FORMAT = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-time-hhmm datetime state cyboi format. */
static int* XDT_TIME_HHMM_DATETIME_STATE_CYBOI_FORMAT = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/** The part element state cyboi format. */
static int* PART_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// example
//

/** The example state cyboi format. */
static int* EXAMPLE_STATE_CYBOI_FORMAT = NUMBER_230_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// fonts
//

/** The package fonts state cyboi format. */
static int* PACKAGE_FONTS_STATE_CYBOI_FORMAT = NUMBER_250_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi format. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// meta
//

/** The channel meta state cyboi format. */
static int* CHANNEL_META_STATE_CYBOI_FORMAT = NUMBER_330_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding meta state cyboi format. */
static int* ENCODING_META_STATE_CYBOI_FORMAT = NUMBER_331_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language meta state cyboi format. */
static int* LANGUAGE_META_STATE_CYBOI_FORMAT = NUMBER_332_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format meta state cyboi format. */
static int* FORMAT_META_STATE_CYBOI_FORMAT = NUMBER_333_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type meta state cyboi format. */
static int* TYPE_META_STATE_CYBOI_FORMAT = NUMBER_334_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The complex-cartesian number state cyboi format. */
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT = NUMBER_350_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-polar number state cyboi format. */
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_351_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-decimal number state cyboi format. */
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT = NUMBER_352_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-vulgar number state cyboi format. */
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_353_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi format. */
static int* INTEGER_NUMBER_STATE_CYBOI_FORMAT = NUMBER_354_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// path
//

/** The reference path state cyboi format. */
static int* REFERENCE_PATH_STATE_CYBOI_FORMAT = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The knowledge path state cyboi format. */
static int* KNOWLEDGE_PATH_STATE_CYBOI_FORMAT = NUMBER_401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The ascii text state cyboi format. */
static int* ASCII_TEXT_STATE_CYBOI_FORMAT = NUMBER_420_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plain text state cyboi format. */
static int* PLAIN_TEXT_STATE_CYBOI_FORMAT = NUMBER_421_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The html text state cyboi format. */
static int* HTML_TEXT_STATE_CYBOI_FORMAT = NUMBER_422_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_FORMAT_CONSTANT_SOURCE */
#endif
