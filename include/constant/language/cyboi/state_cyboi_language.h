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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STATE_CYBOI_LANGUAGE_CONSTANT_HEADER
#define STATE_CYBOI_LANGUAGE_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

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

/** The json application state cyboi language. */
static int* JSON_APPLICATION_STATE_CYBOI_LANGUAGE = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mbox application state cyboi language. */
static int* MBOX_APPLICATION_STATE_CYBOI_LANGUAGE = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pdf application state cyboi format. */
//?? static int* PDF_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xml application state cyboi language. */
static int* XML_APPLICATION_STATE_CYBOI_LANGUAGE = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The zip application state cyboi format. */
//?? static int* ZIP_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application vnd
//

/** The vnd.ms-excel application state cyboi format. */
//?? static int* VND_MS_EXCEL_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// application x
//

/** The x-latex application state cyboi format. */
//?? static int* X_LATEX_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-tar application state cyboi format. */
//?? static int* X_TAR_APPLICATION_STATE_CYBOI_FORMAT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// audio
//

/** The mpeg audio state cyboi format. */
//?? static int* MPEG_AUDIO_STATE_CYBOI_FORMAT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vorbis audio state cyboi format. */
//?? static int* VORBIS_AUDIO_STATE_CYBOI_FORMAT = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// bluetooth
//

/** The synchronisation-profile bluetooth state cyboi format. */
//?? static int* SYNCHRONISATION_PROFILE_BLUETOOTH_STATE_CYBOI_FORMAT = NUMBER_150_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// chronology
//

/** The buddhist chronology state cyboi language. */
static int* BUDDHIST_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_160_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The coptic chronology state cyboi language. */
static int* COPTIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_161_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ethiopic chronology state cyboi language. */
static int* ETHIOPIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_162_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gregorian-julian chronology state cyboi language. */
static int* GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_163_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gregorian chronology state cyboi language. */
static int* GREGORIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_164_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The islamic chronology state cyboi language. */
static int* ISLAMIC_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_165_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso chronology state cyboi language. */
static int* ISO_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_166_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The julian date (jd) chronology state cyboi language. */
static int* JD_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_167_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The julian chronology state cyboi language. */
static int* JULIAN_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_168_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The modified julian date (mjd) chronology state cyboi language. */
static int* MJD_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_169_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The posix (unix) chronology state cyboi language. */
static int* POSIX_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_170_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The international atomic time (tai) chronology state cyboi language. */
static int* TAI_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_171_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The international time (ti) chronology state cyboi language. */
static int* TI_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_172_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The truncated julian date (tjd) chronology state cyboi language. */
static int* TJD_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_173_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The coordinated universal time (utc) chronology state cyboi language. */
static int* UTC_CHRONOLOGY_STATE_CYBOI_LANGUAGE = NUMBER_174_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// image
//

/** The gif image state cyboi format. */
//?? static int* GIF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The jpeg image state cyboi format. */
//?? static int* JPEG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The png image state cyboi format. */
//?? static int* PNG_IMAGE_STATE_CYBOI_FORMAT = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tiff image state cyboi format. */
//?? static int* TIFF_IMAGE_STATE_CYBOI_FORMAT = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// inode
//

/** The socket inode state cyboi format. */
//?? static int* SOCKET_INODE_STATE_CYBOI_FORMAT = NUMBER_250_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// interface
//

/** The x-winamp-skin interface state cyboi language. */
//?? static int* X_WINAMP_SKIN_INTERFACE_STATE_CYBOI_LANGUAGE = NUMBER_270_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// media
//

/** The vcd media state cyboi format. */
//?? static int* VCD_MEDIA_STATE_CYBOI_FORMAT = NUMBER_290_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// message
//

/** The binary message state cyboi language. */
static int* BINARY_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The binary crlf message state cyboi language. */
static int* BINARY_CRLF_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ftp-response message state cyboi language. */
static int* FTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gui-request message state cyboi language. */
static int* GUI_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_303_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gui-response message state cyboi language. */
static int* GUI_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-request message state cyboi language. */
static int* HTTP_REQUEST_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_305_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The http-response message state cyboi language. */
static int* HTTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_306_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imap-command message state cyboi language. */
static int* IMAP_COMMAND_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_307_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imap-response message state cyboi language. */
static int* IMAP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_308_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The imf message state cyboi language. */
static int* IMF_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_309_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The news message state cyboi language. */
static int* NEWS_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pop3-command message state cyboi language. */
static int* POP3_COMMAND_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_311_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The pop3-reply message state cyboi language. */
static int* POP3_REPLY_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_312_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smtp-command message state cyboi language. */
static int* SMTP_COMMAND_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_313_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smtp-response message state cyboi language. */
static int* SMTP_RESPONSE_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_314_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tui message state cyboi language. */
static int* TUI_MESSAGE_STATE_CYBOI_LANGUAGE = NUMBER_315_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// model
//

/** The vrml model state cyboi format. */
//?? static int* VRML_MODEL_STATE_CYBOI_FORMAT = NUMBER_340_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// multipart
//

/** The mixed multipart state cyboi format. */
//?? static int* MIXED_MULTIPART_STATE_CYBOI_FORMAT = NUMBER_360_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// number
//

/** The terminal mode number state cyboi language. */
static int* TERMINAL_MODE_NUMBER_STATE_CYBOI_LANGUAGE = NUMBER_370_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// print
//

/** The jobs print state cyboi format. */
//?? static int* JOBS_PRINT_STATE_CYBOI_FORMAT = NUMBER_380_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// text
//

/** The authority text state cyboi language. */
static int* AUTHORITY_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The bdt text state cyboi language. */
static int* BDT_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The css text state cyboi language. */
static int* CSS_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_402_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The csv text state cyboi language. */
static int* CSV_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_403_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol+json text state cyboi language. */
static int* CYBOL_JSON_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_404_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol text state cyboi language. */
static int* CYBOL_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_405_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The cybol+xml text state cyboi language. */
static int* CYBOL_XML_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_406_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gdt text state cyboi language. */
static int* GDT_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_407_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The html text state cyboi language. */
static int* HTML_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_408_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The hxp text state cyboi language. */
static int* HXP_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_409_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The joined-string text state cyboi language. */
static int* JOINED_STRING_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_410_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ldt text state cyboi language. */
static int* LDT_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_411_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The model-diagram text state cyboi language. */
static int* MODEL_DIAGRAM_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_412_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sgml text state cyboi language. */
//?? static int* SGML_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_413_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The textline-list text state cyboi language. */
static int* TEXTLINE_LIST_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_414_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The uri text state cyboi language. */
static int* URI_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_415_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xdt-field-description text state cyboi language. */
static int* XDT_FIELD_DESCRIPTION_TEXT_STATE_CYBOI_LANGUAGE = NUMBER_416_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// uri
//

/** The mms uri state cyboi format. */
//?? static int* MMS_URI_STATE_CYBOI_FORMAT = NUMBER_440_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// video
//

/** The avi video state cyboi format. */
//?? static int* AVI_VIDEO_STATE_CYBOI_FORMAT = NUMBER_450_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mp4 video state cyboi format. */
//?? static int* MP4_VIDEO_STATE_CYBOI_FORMAT = NUMBER_451_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mpeg video state cyboi format. */
//?? static int* MPEG_VIDEO_STATE_CYBOI_FORMAT = NUMBER_452_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The quicktime video state cyboi format. */
//?? static int* QUICKTIME_VIDEO_STATE_CYBOI_FORMAT = NUMBER_453_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The x-ms-wmv video state cyboi format. */
//?? static int* X_MS_WMV_VIDEO_STATE_CYBOI_FORMAT = NUMBER_454_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_LANGUAGE_CONSTANT_HEADER */
#endif
