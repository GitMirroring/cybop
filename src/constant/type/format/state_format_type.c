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

#ifndef STATE_FORMAT_TYPE_CONSTANT_SOURCE
#define STATE_FORMAT_TYPE_CONSTANT_SOURCE

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

/** The pdf application state format type. */
static int* PDF_APPLICATION_STATE_FORMAT_TYPE = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The zip application state format type. */
static int* ZIP_APPLICATION_STATE_FORMAT_TYPE = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xhtml+xml application state format type. */
static int* XHTML_XML_APPLICATION_STATE_FORMAT_TYPE = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application vnd
//

/** The vnd.ms-excel application state format type. */
static int* VND_MS_EXCEL_APPLICATION_STATE_FORMAT_TYPE = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application x
//

/** The x-latex application state format type. */
static int* X_LATEX_APPLICATION_STATE_FORMAT_TYPE = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tar application state format type. */
static int* X_TAR_APPLICATION_STATE_FORMAT_TYPE = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// audio
//

/** The mpeg audio state format type. */
static int* MPEG_AUDIO_STATE_FORMAT_TYPE = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vorbis audio state format type. */
static int* VORBIS_AUDIO_STATE_FORMAT_TYPE = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// bluetooth
//

/** The synchronisation-profile bluetooth state format type. */
static int* SYNCHRONISATION_PROFILE_BLUETOOTH_STATE_FORMAT_TYPE = NUMBER_150_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// colour
//

/** The cmyk colour state format type. */
static int* CMYK_COLOUR_STATE_FORMAT_TYPE = NUMBER_180_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rgb colour state format type. */
static int* RGB_COLOUR_STATE_FORMAT_TYPE = NUMBER_181_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal-background colour state format type. */
static int* TERMINAL_BACKGROUND_COLOUR_STATE_FORMAT_TYPE = NUMBER_182_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal-foreground colour state format type. */
static int* TERMINAL_FOREGROUND_COLOUR_STATE_FORMAT_TYPE = NUMBER_183_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// datetime
//

/** The yyyy-mm-dd datetime state format type. */
static int* YYYY_MM_DD_DATETIME_STATE_FORMAT_TYPE = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hh-mm-ss datetime state format type. */
static int* HH_MM_SS_DATETIME_STATE_FORMAT_TYPE = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yyyymmddthhmmss datetime state format type. */
static int* YYYYMMDDTHHMMSS_DATETIME_STATE_FORMAT_TYPE = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-hhmm datetime state format type. */
static int* XDT_DATE_HHMM_DATETIME_STATE_FORMAT_TYPE = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-hhmmhhmm datetime state format type. */
static int* XDT_DATE_HHMMHHMM_DATETIME_STATE_FORMAT_TYPE = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-yymmnnn datetime state format type. */
static int* XDT_DATE_YYMMNNN_DATETIME_STATE_FORMAT_TYPE = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-ddmmyyyy datetime state format type. */
static int* XDT_DATE_DDMMYYYY_DATETIME_STATE_FORMAT_TYPE = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-mmyy datetime state format type. */
static int* XDT_DATE_MMYY_DATETIME_STATE_FORMAT_TYPE = NUMBER_207_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-date-ddmmyyyyddmmyyyy datetime state format type. */
static int* XDT_DATE_DDMMYYYYDDMMYYYY_DATETIME_STATE_FORMAT_TYPE = NUMBER_208_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-time-hhmmss datetime state format type. */
static int* XDT_TIME_HHMMSS_DATETIME_STATE_FORMAT_TYPE = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-time-hhmm datetime state format type. */
static int* XDT_TIME_HHMM_DATETIME_STATE_FORMAT_TYPE = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// example
//

/** The example state format type. */
static int* EXAMPLE_STATE_FORMAT_TYPE = NUMBER_230_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// fonts
//

/** The package fonts state format type. */
static int* PACKAGE_FONTS_STATE_FORMAT_TYPE = NUMBER_250_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// image
//

/** The gif image state format type. */
static int* GIF_IMAGE_STATE_FORMAT_TYPE = NUMBER_270_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jpeg image state format type. */
static int* JPEG_IMAGE_STATE_FORMAT_TYPE = NUMBER_271_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The png image state format type. */
static int* PNG_IMAGE_STATE_FORMAT_TYPE = NUMBER_272_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tiff image state format type. */
static int* TIFF_IMAGE_STATE_FORMAT_TYPE = NUMBER_273_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// inode
//

/** The socket inode state format type. */
static int* SOCKET_INODE_STATE_FORMAT_TYPE = NUMBER_280_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// interface
//

/** The x-winamp-skin interface state format type. */
static int* X_WINAMP_SKIN_INTERFACE_STATE_FORMAT_TYPE = NUMBER_290_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state format type. */
static int* BOOLEAN_LOGICVALUE_STATE_FORMAT_TYPE = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// media
//

/** The vcd media state format type. */
static int* VCD_MEDIA_STATE_FORMAT_TYPE = NUMBER_310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// message
//

/** The http message state format type. */
static int* HTTP_MESSAGE_STATE_FORMAT_TYPE = NUMBER_320_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-request message state format type. */
static int* HTTP_REQUEST_MESSAGE_STATE_FORMAT_TYPE = NUMBER_321_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-response message state format type. */
static int* HTTP_RESPONSE_MESSAGE_STATE_FORMAT_TYPE = NUMBER_322_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The news message state format type. */
static int* NEWS_MESSAGE_STATE_FORMAT_TYPE = NUMBER_323_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// meta
//

/** The channel meta state format type. */
static int* CHANNEL_META_STATE_FORMAT_TYPE = NUMBER_330_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding meta state format type. */
static int* ENCODING_META_STATE_FORMAT_TYPE = NUMBER_331_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format meta state format type. */
static int* FORMAT_META_STATE_FORMAT_TYPE = NUMBER_332_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type meta state format type. */
static int* TYPE_META_STATE_FORMAT_TYPE = NUMBER_333_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// model
//

/** The vrml model state format type. */
static int* VRML_MODEL_STATE_FORMAT_TYPE = NUMBER_340_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// multipart
//

/** The mixed multipart state format type. */
static int* MIXED_MULTIPART_STATE_FORMAT_TYPE = NUMBER_345_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The complex-cartesian number state format type. */
static int* COMPLEX_CARTESIAN_NUMBER_STATE_FORMAT_TYPE = NUMBER_350_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-polar number state format type. */
static int* COMPLEX_POLAR_NUMBER_STATE_FORMAT_TYPE = NUMBER_353_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-decimal number state format type. */
static int* FRACTION_DECIMAL_NUMBER_STATE_FORMAT_TYPE = NUMBER_351_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-vulgar number state format type. */
static int* FRACTION_VULGAR_NUMBER_STATE_FORMAT_TYPE = NUMBER_354_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state format type. */
static int* INTEGER_NUMBER_STATE_FORMAT_TYPE = NUMBER_352_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// path
//

/** The encapsulated path state format type. */
static int* ENCAPSULATED_PATH_STATE_FORMAT_TYPE = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The knowledge path state format type. */
static int* KNOWLEDGE_PATH_STATE_FORMAT_TYPE = NUMBER_401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// print
//

/** The jobs print state format type. */
static int* JOBS_PRINT_STATE_FORMAT_TYPE = NUMBER_410_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The ascii text state format type. */
static int* ASCII_TEXT_STATE_FORMAT_TYPE = NUMBER_420_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The authority text state format type. */
static int* AUTHORITY_TEXT_STATE_FORMAT_TYPE = NUMBER_421_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The css text state format type. */
static int* CSS_TEXT_STATE_FORMAT_TYPE = NUMBER_422_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol text state format type. */
static int* CYBOL_TEXT_STATE_FORMAT_TYPE = NUMBER_423_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The html text state format type. */
static int* HTML_TEXT_STATE_FORMAT_TYPE = NUMBER_425_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hxp text state format type. */
static int* HXP_TEXT_STATE_FORMAT_TYPE = NUMBER_426_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model-diagram text state format type. */
static int* MODEL_DIAGRAM_TEXT_STATE_FORMAT_TYPE = NUMBER_427_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plain text state format type. */
static int* PLAIN_TEXT_STATE_FORMAT_TYPE = NUMBER_428_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uri text state format type. */
static int* URI_TEXT_STATE_FORMAT_TYPE = NUMBER_430_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt text state format type. */
static int* XDT_TEXT_STATE_FORMAT_TYPE = NUMBER_431_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml text state format type. */
static int* XML_TEXT_STATE_FORMAT_TYPE = NUMBER_432_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// uri
//

/** The mms uri state format type. */
static int* MMS_URI_STATE_FORMAT_TYPE = NUMBER_440_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// video
//

/** The avi video state format type. */
static int* AVI_VIDEO_STATE_FORMAT_TYPE = NUMBER_450_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mp4 video state format type. */
static int* MP4_VIDEO_STATE_FORMAT_TYPE = NUMBER_451_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpeg video state format type. */
static int* MPEG_VIDEO_STATE_FORMAT_TYPE = NUMBER_452_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The quicktime video state format type. */
static int* QUICKTIME_VIDEO_STATE_FORMAT_TYPE = NUMBER_453_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-ms-wmv video state format type. */
static int* X_MS_WMV_VIDEO_STATE_FORMAT_TYPE = NUMBER_454_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_FORMAT_TYPE_CONSTANT_SOURCE */
#endif
