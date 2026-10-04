/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Franziska Wehner <franziska.wehner@it2011.ba-leipzig.de>
 */

#ifndef STATE_CYBOI_FORMAT_CONSTANT_HEADER
#define STATE_CYBOI_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// CAUTION! These constants should actually be put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// However, STATE and LOGIC constants have been split into TWO files,
// for reasons of better overview.
//
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..999
// - logic constants: 1000..2999
//

//
// application
//

/** The acad application state cyboi format. */
static int* ACAD_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The applefile application state cyboi format. */
static int* APPLEFILE_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The astound application state cyboi format. */
static int* ASTOUND_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dsptype application state cyboi format. */
static int* DSPTYPE_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dxf application state cyboi format. */
static int* DXF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The futuresplash application state cyboi format. */
static int* FUTURESPLASH_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gzip application state cyboi format. */
static int* GZIP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The listenup application state cyboi format. */
static int* LISTENUP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mac-binhex40 application state cyboi format. */
static int* MAC_BINHEX40_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mbedlet application state cyboi format. */
static int* MBEDLET_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mif application state cyboi format. */
static int* MIF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The msexcel application state cyboi format. */
static int* MSEXCEL_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mshelp application state cyboi format. */
static int* MSHELP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mspowerpoint application state cyboi format. */
static int* MSPOWERPOINT_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The msword application state cyboi format. */
static int* MSWORD_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The octet-stream application state cyboi format. */
static int* OCTET_STREAM_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The oda application state cyboi format. */
static int* ODA_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pdf application state cyboi format. */
static int* PDF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The postscript application state cyboi format. */
static int* POSTSCRIPT_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The RTC application state cyboi format. */
static int* RTC_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rtf application state cyboi format. */
static int* RTF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The studiom application state cyboi format. */
static int* STUDIOM_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The toolbook application state cyboi format. */
static int* TOOLBOOK_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vnd.ms-excel application state cyboi format. */
static int* VND_MS_EXCEL_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vocaltec-media-desc application state cyboi format. */
static int* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vocaltec-media-file application state cyboi format. */
static int* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xhtml+xml application state cyboi format. */
static int* XHTML_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_26_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml application state cyboi format. */
static int* XML_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-bcpio application state cyboi format. */
static int* X_BCPIO_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_28_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-compress application state cyboi format. */
static int* X_COMPRESS_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-cpio application state cyboi format. */
static int* X_CPIO_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-csh application state cyboi format. */
static int* X_CSH_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-director application state cyboi format. */
static int* X_DIRECTOR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_32_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-dvi application state cyboi format. */
static int* X_DVI_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-envoy application state cyboi format. */
static int* X_ENVOY_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_34_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-gtar application state cyboi format. */
static int* X_GTAR_STREAM_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_35_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-httpd-php application state cyboi format. */
static int* X_HTTPD_PHP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_36_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-javascript application state cyboi format. */
static int* X_JAVASCRIPT_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_37_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-latex application state cyboi format. */
static int* X_LATEX_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_38_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-macbinary application state cyboi format. */
static int* X_MACBINARY_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_39_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-mif application state cyboi format. */
static int* X_MIF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_40_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-netcdf application state cyboi format. */
static int* X_NETCDF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_41_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-nschat application state cyboi format. */
static int* X_NSCHAT_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_42_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sh application state cyboi format. */
static int* X_SH_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_43_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-shar application state cyboi format. */
static int* X_SHAR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_44_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sprite application state cyboi format. */
static int* X_SPRITE_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_45_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-stuffit application state cyboi format. */
static int* X_STUFFIT_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_46_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-supercard application state cyboi format. */
static int* X_SUPERCARD_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_47_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sv4cpio application state cyboi format. */
static int* X_SV4CPIO_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_48_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sv4crc application state cyboi format. */
static int* X_SV4CRC_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_49_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tar application state cyboi format. */
static int* X_TAR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tcl application state cyboi format. */
static int* X_TCL_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tex application state cyboi format. */
static int* X_TEX_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-texinfo application state cyboi format. */
static int* X_TEXINFO_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-troff application state cyboi format. */
static int* X_TROFF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_54_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-troff-man application state cyboi format. */
static int* X_TROFF_MAN_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_55_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-troff-me application state cyboi format. */
static int* X_TROFF_ME_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_56_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-troff-ms application state cyboi format. */
static int* X_TROFF_MS_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_57_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-ustar application state cyboi format. */
static int* X_USTAR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_58_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-wais-source application state cyboi format. */
static int* X_WAIS_SOURCE_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_59_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-www-form-urlencoded application state cyboi format. */
static int* X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_60_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The zip application state cyboi format. */
static int* ZIP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_61_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// audio
//

/** The basic audio state cyboi format. */
static int* BASIC_AUDIO_STATE_CYBOI_FORMAT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echospeech audio state cyboi format. */
static int* ECHOSPEECH_AUDIO_STATE_CYBOI_FORMAT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpeg audio state cyboi format. */
static int* MPEG_AUDIO_STATE_CYBOI_FORMAT = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tsplayer audio state cyboi format. */
static int* TSPLAYER_AUDIO_STATE_CYBOI_FORMAT = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vorbis audio state cyboi format. */
static int* VORBIS_AUDIO_STATE_CYBOI_FORMAT = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The voxware audio state cyboi format. */
static int* VOXWARE_AUDIO_STATE_CYBOI_FORMAT = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-aiff audio state cyboi format. */
static int* X_AIFF_AUDIO_STATE_CYBOI_FORMAT = NUMBER_106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-dspeech audio state cyboi format. */
static int* X_DSPEECH_AUDIO_STATE_CYBOI_FORMAT = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-midi audio state cyboi format. */
static int* X_MIDI_AUDIO_STATE_CYBOI_FORMAT = NUMBER_108_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-mpeg audio state cyboi format. */
static int* X_MPEG_AUDIO_STATE_CYBOI_FORMAT = NUMBER_109_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-pn-realaudio audio state cyboi format. */
static int* X_PN_REALAUDIO_AUDIO_STATE_CYBOI_FORMAT = NUMBER_110_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-pn-realaudio-plugin audio state cyboi format. */
static int* X_PN_REALAUDIO_PLUGIN_AUDIO_STATE_CYBOI_FORMAT = NUMBER_111_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-qt-stream audio state cyboi format. */
static int* X_QT_STREAM_AUDIO_STATE_CYBOI_FORMAT = NUMBER_112_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-wav audio state cyboi format. */
static int* X_WAV_AUDIO_STATE_CYBOI_FORMAT = NUMBER_113_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// colour
//

/** The cmyk colour state cyboi format. */
static int* CMYK_COLOUR_STATE_CYBOI_FORMAT = NUMBER_150_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rgb colour state cyboi format. */
static int* RGB_COLOUR_STATE_CYBOI_FORMAT = NUMBER_151_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The terminal colour state cyboi format. */
static int* TERMINAL_COLOUR_STATE_CYBOI_FORMAT = NUMBER_152_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// datetime
//

/** The ascension datetime state cyboi format. */
static int* ASCENSION_DATETIME_STATE_CYBOI_FORMAT = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The day-of-month datetime state cyboi format. */
static int* DAY_OF_MONTH_DATETIME_STATE_CYBOI_FORMAT = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The day-of-week datetime state cyboi format. */
static int* DAY_OF_WEEK_DATETIME_STATE_CYBOI_FORMAT = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The day-of-year datetime state cyboi format. */
static int* DAY_OF_YEAR_DATETIME_STATE_CYBOI_FORMAT = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dd.mm.yyyy datetime state cyboi format. */
static int* DD_DOT_MM_DOT_YYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dd/mm/yy datetime state cyboi format. */
static int* DD_SLASH_MM_SLASH_YY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dd/mm/yyyy datetime state cyboi format. */
static int* DD_SLASH_MM_SLASH_YYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_206_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ddmmyyyy datetime state cyboi format. */
static int* DDMMYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_207_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The easter-monday datetime state cyboi format. */
static int* EASTER_MONDAY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_208_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The easter-sunday datetime state cyboi format. */
static int* EASTER_SUNDAY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_209_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso datetime state cyboi format. */
static int* ISO_DATETIME_STATE_CYBOI_FORMAT = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mm/dd/yy datetime state cyboi format. */
static int* MM_SLASH_DD_SLASH_YY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_211_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mm/dd/yyyy datetime state cyboi format. */
static int* MM_SLASH_DD_SLASH_YYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_212_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mmyy datetime state cyboi format. */
static int* MMYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The month-of-year datetime state cyboi format. */
static int* MONTH_OF_YEAR_DATETIME_STATE_CYBOI_FORMAT = NUMBER_214_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The qyyyy datetime state cyboi format. */
static int* QYYYY_DATETIME_STATE_CYBOI_FORMAT = NUMBER_215_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The week-of-month datetime state cyboi format. */
static int* WEEK_OF_MONTH_DATETIME_STATE_CYBOI_FORMAT = NUMBER_216_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The week-of-year datetime state cyboi format. */
static int* WEEK_OF_YEAR_DATETIME_STATE_CYBOI_FORMAT = NUMBER_217_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// drawing
//

/** The x-dwf drawing state cyboi format. */
static int* X_DWF_DRAWING_STATE_CYBOI_FORMAT = NUMBER_250_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// duration
//

/** The ddmmyyyyddmmyyyy duration state cyboi format. */
static int* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOI_FORMAT = NUMBER_280_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hhmmhhmm duration state cyboi format. */
static int* HHMMHHMM_DURATION_STATE_CYBOI_FORMAT = NUMBER_281_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso duration state cyboi format. */
static int* ISO_DURATION_STATE_CYBOI_FORMAT = NUMBER_282_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jd duration state cyboi format. */
static int* JD_DURATION_STATE_CYBOI_FORMAT = NUMBER_283_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The julian duration state cyboi format. */
static int* JULIAN_DURATION_STATE_CYBOI_FORMAT = NUMBER_284_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The si duration state cyboi format. */
static int* SI_DURATION_STATE_CYBOI_FORMAT = NUMBER_285_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The yyyy duration state cyboi format. */
static int* YYYY_DURATION_STATE_CYBOI_FORMAT = NUMBER_286_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// element
//

/** The part element state cyboi format. */
static int* PART_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The property element state cyboi format. */
static int* PROPERTY_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reference element state cyboi format. */
static int* REFERENCE_ELEMENT_STATE_CYBOI_FORMAT = NUMBER_302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// example
//

/** The example state cyboi format. */
static int* EXAMPLE_STATE_CYBOI_FORMAT = NUMBER_330_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// fonts
//

/** The package fonts state cyboi format. */
static int* PACKAGE_FONTS_STATE_CYBOI_FORMAT = NUMBER_360_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// image
//

/** The cis-cod image state cyboi format. */
static int* CIS_COD_IMAGE_STATE_CYBOI_FORMAT = NUMBER_380_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cmu-raster image state cyboi format. */
static int* CMU_RASTER_IMAGE_STATE_CYBOI_FORMAT = NUMBER_381_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fif image state cyboi format. */
static int* FIF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_382_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gif image state cyboi format. */
static int* GIF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_383_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ief image state cyboi format. */
static int* IEF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_384_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jpeg image state cyboi format. */
static int* JPEG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_385_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The png image state cyboi format. */
static int* PNG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_386_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tiff image state cyboi format. */
static int* TIFF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_387_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vasa image state cyboi format. */
static int* VASA_IMAGE_STATE_CYBOI_FORMAT = NUMBER_388_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vnd.wap.wbmp image state cyboi format. */
static int* VND_WAP_WBMP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_389_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-freehand image state cyboi format. */
static int* X_FREEHAND_IMAGE_STATE_CYBOI_FORMAT = NUMBER_390_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-icon image state cyboi format. */
static int* X_ICON_IMAGE_STATE_CYBOI_FORMAT = NUMBER_391_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-portable-anymap image state cyboi format. */
static int* X_PORTABLE_ANYMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_392_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-portable-bitmap image state cyboi format. */
static int* X_PORTABLE_BITMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_393_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-portable-graymap image state cyboi format. */
static int* X_PORTABLE_GARYMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_394_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-portable-pixmap image state cyboi format. */
static int* X_PORTABLE_PIXMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_395_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-rgb image state cyboi format. */
static int* X_RGB_IMAGE_STATE_CYBOI_FORMAT = NUMBER_396_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-windowdump image state cyboi format. */
static int* X_WINDOWDUMP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_397_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-xbitmap image state cyboi format. */
static int* X_XBITMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_398_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-xpixmap image state cyboi format. */
static int* X_XPIXMAP_IMAGE_STATE_CYBOI_FORMAT = NUMBER_399_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logicvalue
//

/** The boolean logicvalue state cyboi format. */
static int* BOOLEAN_LOGICVALUE_STATE_CYBOI_FORMAT = NUMBER_450_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// message
//

/** The external-body message state cyboi format. */
static int* EXTERNAL_BODY_MESSAGE_STATE_CYBOI_FORMAT = NUMBER_470_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http message state cyboi format. */
static int* HTTP_MESSAGE_STATE_CYBOI_FORMAT = NUMBER_471_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The news message state cyboi format. */
static int* NEWS_MESSAGE_STATE_CYBOI_FORMAT = NUMBER_472_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The partial message state cyboi format. */
static int* PARTIAL_MESSAGE_STATE_CYBOI_FORMAT = NUMBER_473_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rfc822 message state cyboi format. */
static int* RFC822_MESSAGE_STATE_CYBOI_FORMAT = NUMBER_474_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// meta
//

/** The name meta state cyboi format. */
static int* NAME_META_STATE_CYBOI_FORMAT = NUMBER_490_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The channel meta state cyboi format. */
static int* CHANNEL_META_STATE_CYBOI_FORMAT = NUMBER_491_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding meta state cyboi format. */
static int* ENCODING_META_STATE_CYBOI_FORMAT = NUMBER_492_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language meta state cyboi format. */
static int* LANGUAGE_META_STATE_CYBOI_FORMAT = NUMBER_493_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format meta state cyboi format. */
static int* FORMAT_META_STATE_CYBOI_FORMAT = NUMBER_494_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type meta state cyboi format. */
static int* TYPE_META_STATE_CYBOI_FORMAT = NUMBER_495_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model meta state cyboi format. */
static int* MODEL_META_STATE_CYBOI_FORMAT = NUMBER_496_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// model
//

/** The vrml model state cyboi format. */
static int* VRML_MODEL_STATE_CYBOI_FORMAT = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// multipart
//

/** The alternative multipart state cyboi format. */
static int* ALTERNATIVE_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_520_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The byteranges multipart state cyboi format. */
static int* BYTERANGES_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_521_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The digest multipart state cyboi format. */
static int* DIGEST_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_522_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encrypted multipart state cyboi format. */
static int* ENCRYPTED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_523_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The form-data multipart state cyboi format. */
static int* FORM_DATA_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_524_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mixed multipart state cyboi format. */
static int* MIXED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_525_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The parallel multipart state cyboi format. */
static int* PARALLEL_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_526_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The related multipart state cyboi format. */
static int* RELATED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_527_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The report multipart state cyboi format. */
static int* REPORT_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_528_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The signed multipart state cyboi format. */
static int* SIGNED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_529_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The voice-message multipart state cyboi format. */
static int* VOICE_MESSAGE_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_530_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The byte number state cyboi format. */
static int* BYTE_NUMBER_STATE_CYBOI_FORMAT = NUMBER_550_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-cartesian number state cyboi format. */
static int* COMPLEX_CARTESIAN_NUMBER_STATE_CYBOI_FORMAT = NUMBER_551_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The complex-polar number state cyboi format. */
static int* COMPLEX_POLAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_552_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-decimal number state cyboi format. */
static int* FRACTION_DECIMAL_NUMBER_STATE_CYBOI_FORMAT = NUMBER_553_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fraction-vulgar number state cyboi format. */
static int* FRACTION_VULGAR_NUMBER_STATE_CYBOI_FORMAT = NUMBER_554_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer number state cyboi format. */
static int* INTEGER_NUMBER_STATE_CYBOI_FORMAT = NUMBER_555_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The line speed number state cyboi format. */
static int* LINE_SPEED_NUMBER_STATE_CYBOI_FORMAT = NUMBER_556_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The ascii text state cyboi format. */
static int* ASCII_TEXT_STATE_CYBOI_FORMAT = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol-path text state cyboi format. */
static int* CYBOL_PATH_TEXT_STATE_CYBOI_FORMAT = NUMBER_610_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The html text state cyboi format. */
static int* HTML_TEXT_STATE_CYBOI_FORMAT = NUMBER_620_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The javascript text state cyboi format. */
static int* JAVASCRIPT_TEXT_STATE_CYBOI_FORMAT = NUMBER_621_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The plain text state cyboi format. */
static int* PLAIN_TEXT_STATE_CYBOI_FORMAT = NUMBER_622_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The richtext text state cyboi format. */
static int* RICHTEXT_TEXT_STATE_CYBOI_FORMAT = NUMBER_623_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rtf text state cyboi format. */
static int* RTF_TEXT_STATE_CYBOI_FORMAT = NUMBER_624_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tab-separated-values text state cyboi format. */
static int* TAB_SEPARATED_VALUES_TEXT_STATE_CYBOI_FORMAT = NUMBER_625_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vnd.wap.wml text state cyboi format. */
static int* VND_WAP_WML_TEXT_STATE_CYBOI_FORMAT = NUMBER_630_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vnd.wap.wmlscript text state cyboi format. */
static int* VND_WAP_WMLSCRIPT_TEXT_STATE_CYBOI_FORMAT = NUMBER_631_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml text state cyboi format. */
static int* XML_TEXT_STATE_CYBOI_FORMAT = NUMBER_632_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml-external-parsed-entity text state cyboi format. */
static int* XML_EXTERNAL_PARSED_ENTITY_TEXT_STATE_CYBOI_FORMAT = NUMBER_633_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-setext text state cyboi format. */
static int* X_SETEXT_TEXT_STATE_CYBOI_FORMAT = NUMBER_640_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sgml text state cyboi format. */
static int* X_SGML_TEXT_STATE_CYBOI_FORMAT = NUMBER_641_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-speech text state cyboi format. */
static int* X_SPEECH_TEXT_STATE_CYBOI_FORMAT = NUMBER_642_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// video
//

/** The avi video state cyboi format. */
static int* AVI_VIDEO_STATE_CYBOI_FORMAT = NUMBER_650_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mp4 video state cyboi format. */
static int* MP4_VIDEO_STATE_CYBOI_FORMAT = NUMBER_651_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpeg video state cyboi format. */
static int* MPEG_VIDEO_STATE_CYBOI_FORMAT = NUMBER_652_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The quicktime video state cyboi format. */
static int* QUICKTIME_VIDEO_STATE_CYBOI_FORMAT = NUMBER_653_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vnd.vivo video state cyboi format. */
static int* VND_VIVO_VIDEO_STATE_CYBOI_FORMAT = NUMBER_654_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-msvideo video state cyboi format. */
static int* X_MSVIDEO_VIDEO_STATE_CYBOI_FORMAT = NUMBER_655_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-ms-wmv video state cyboi format. */
static int* X_MS_WMV_VIDEO_STATE_CYBOI_FORMAT = NUMBER_656_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-sgi-movie video state cyboi format. */
static int* X_SGI_MOVIE_VIDEO_STATE_CYBOI_FORMAT = NUMBER_657_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// workbook
//

/** The formulaone workbook state cyboi format. */
static int* FORMULAONE_WORKBOOK_STATE_CYBOI_FORMAT = NUMBER_680_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// x-world
//

/** The x-3dmf x-world state cyboi format. */
static int* FX_3DMF_X_WORLD_STATE_CYBOI_FORMAT = NUMBER_700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-vrml x-world state cyboi format. */
static int* X_VRML_X_WORLD_STATE_CYBOI_FORMAT = NUMBER_701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_FORMAT_CONSTANT_HEADER */
#endif
