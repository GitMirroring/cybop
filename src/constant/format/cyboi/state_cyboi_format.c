/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
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
static int* CMYK_COLOUR_STATE_CYBOI_FORMAT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rgb colour state cyboi format. */
static int* RGB_COLOUR_STATE_CYBOI_FORMAT = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal colour state cyboi format. */
static int* TERMINAL_COLOUR_STATE_CYBOI_FORMAT = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// datetime
//

/** The ddmmyyyy datetime state cyboi format. */
static int* DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gregorian datetime state cyboi format. */
static int* GREGORIAN_DATETIME_STATE_CYBOI_FORMAT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jd datetime state cyboi format. */
static int* JD_DATETIME_STATE_CYBOI_FORMAT = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The julian datetime state cyboi format. */
static int* JULIAN_DATETIME_STATE_CYBOI_FORMAT = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mjd datetime state cyboi format. */
static int* MJD_DATETIME_STATE_CYBOI_FORMAT = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mmyy datetime state cyboi format. */
static int* MMYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The posix datetime state cyboi format. */
static int* POSIX_DATETIME_STATE_CYBOI_FORMAT = NUMBER_106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The qyyyy datetime state cyboi format. */
static int* QYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tai datetime state cyboi format. */
static int* TAI_DATETIME_STATE_CYBOI_FORMAT = NUMBER_108_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ti datetime state cyboi format. */
static int* TI_DATETIME_STATE_CYBOI_FORMAT = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tjd datetime state cyboi format. */
static int* TJD_DATETIME_STATE_CYBOI_FORMAT = NUMBER_110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utc datetime state cyboi format. */
static int* UTC_DATETIME_STATE_CYBOI_FORMAT = NUMBER_111_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// duration
//

/** The ddmmyyyyddmmyyyy duration state cyboi format. */
static int* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOI_FORMAT = NUMBER_150_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hhmmhhmm duration state cyboi format. */
static int* HHMMHHMM_DURATION_STATE_CYBOI_FORMAT = NUMBER_151_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso duration state cyboi format. */
static int* ISO_DURATION_STATE_CYBOI_FORMAT = NUMBER_152_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jd duration state cyboi format. */
static int* JD_DURATION_STATE_CYBOI_FORMAT = NUMBER_153_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The julian duration state cyboi format. */
static int* JULIAN_DURATION_STATE_CYBOI_FORMAT = NUMBER_154_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The si duration state cyboi format. */
static int* SI_DURATION_STATE_CYBOI_FORMAT = NUMBER_155_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yyyy duration state cyboi format. */
static int* YYYY_DURATION_STATE_CYBOI_FORMAT = NUMBER_156_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/** The part element state cyboi format. */
static int* PART_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_220_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The property element state cyboi format. */
static int* PROPERTY_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_221_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/** The byte number state cyboi format. */
static int* BYTE_NUMBER_STATE_CYBOI_FORMAT = NUMBER_350_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-cartesian number state cyboi format. */
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT = NUMBER_351_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-polar number state cyboi format. */
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_352_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-decimal number state cyboi format. */
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT = NUMBER_353_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-vulgar number state cyboi format. */
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_354_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi format. */
static int* INTEGER_NUMBER_STATE_CYBOI_FORMAT = NUMBER_355_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line speed number state cyboi format. */
static int* LINE_SPEED_NUMBER_STATE_CYBOI_FORMAT = NUMBER_356_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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

/** The html text state cyboi format. */
static int* HTML_TEXT_STATE_CYBOI_FORMAT = NUMBER_421_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plain text state cyboi format. */
static int* PLAIN_TEXT_STATE_CYBOI_FORMAT = NUMBER_422_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_FORMAT_CONSTANT_SOURCE */
#endif
