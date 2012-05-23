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
// application
//

/** The pdf application state cyboi format. */
static int* PDF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The zip application state cyboi format. */
static int* ZIP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xhtml+xml application state cyboi format. */
static int* XHTML_XML_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application vnd
//

/** The vnd.ms-excel application state cyboi format. */
static int* VND_MS_EXCEL_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application x
//

/** The x-latex application state cyboi format. */
static int* X_LATEX_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tar application state cyboi format. */
static int* X_TAR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// audio
//

/** The mpeg audio state cyboi format. */
static int* MPEG_AUDIO_STATE_CYBOI_FORMAT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vorbis audio state cyboi format. */
static int* VORBIS_AUDIO_STATE_CYBOI_FORMAT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// bluetooth
//

/** The synchronisation-profile bluetooth state cyboi format. */
static int* SYNCHRONISATION_PROFILE_BLUETOOTH_STATE_CYBOI_FORMAT = NUMBER_150_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
// image
//

/** The gif image state cyboi format. */
static int* GIF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_270_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jpeg image state cyboi format. */
static int* JPEG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_271_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The png image state cyboi format. */
static int* PNG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_272_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tiff image state cyboi format. */
static int* TIFF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_273_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// inode
//

/** The socket inode state cyboi format. */
static int* SOCKET_INODE_STATE_CYBOI_FORMAT = NUMBER_280_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi format. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// media
//

/** The vcd media state cyboi format. */
static int* VCD_MEDIA_STATE_CYBOI_FORMAT = NUMBER_310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
// model
//

/** The vrml model state cyboi format. */
static int* VRML_MODEL_STATE_CYBOI_FORMAT = NUMBER_340_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// multipart
//

/** The mixed multipart state cyboi format. */
static int* MIXED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_345_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The complex-cartesian number state cyboi format. */
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT = NUMBER_350_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-polar number state cyboi format. */
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_353_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-decimal number state cyboi format. */
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT = NUMBER_351_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-vulgar number state cyboi format. */
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_354_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi format. */
static int* INTEGER_NUMBER_STATE_CYBOI_FORMAT = NUMBER_352_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// path
//

/** The encapsulated path state cyboi format. */
static int* ENCAPSULATED_PATH_STATE_CYBOI_FORMAT = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The knowledge path state cyboi format. */
static int* KNOWLEDGE_PATH_STATE_CYBOI_FORMAT = NUMBER_401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// print
//

/** The jobs print state cyboi format. */
static int* JOBS_PRINT_STATE_CYBOI_FORMAT = NUMBER_410_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The ascii text state cyboi format. */
static int* ASCII_TEXT_STATE_CYBOI_FORMAT = NUMBER_420_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plain text state cyboi format. */
static int* PLAIN_TEXT_STATE_CYBOI_FORMAT = NUMBER_428_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// uri
//

/** The mms uri state cyboi format. */
static int* MMS_URI_STATE_CYBOI_FORMAT = NUMBER_440_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// video
//

/** The avi video state cyboi format. */
static int* AVI_VIDEO_STATE_CYBOI_FORMAT = NUMBER_450_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mp4 video state cyboi format. */
static int* MP4_VIDEO_STATE_CYBOI_FORMAT = NUMBER_451_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpeg video state cyboi format. */
static int* MPEG_VIDEO_STATE_CYBOI_FORMAT = NUMBER_452_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The quicktime video state cyboi format. */
static int* QUICKTIME_VIDEO_STATE_CYBOI_FORMAT = NUMBER_453_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-ms-wmv video state cyboi format. */
static int* X_MS_WMV_VIDEO_STATE_CYBOI_FORMAT = NUMBER_454_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_FORMAT_CONSTANT_SOURCE */
#endif
