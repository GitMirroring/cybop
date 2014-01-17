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

#ifndef APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Application (multi-purpose).
//
// IANA media type: application
//

/*??
application/EDI-X12: EDI X12 data; Defined in RFC 1767
application/EDIFACT: EDI EDIFACT data; Defined in RFC 1767
application/javascript: JavaScript; Defined in RFC 4329
application/json: JavaScript Object Notation JSON; Defined in RFC 4627
application/octet-stream: Arbitrary byte stream. This is thought of as the "default" media type used by several operating systems, often used tidentify executable files, files of unknown type, or files that should be downloaded in protocols that dnot provide a separate "content disposition" header. RFC 2046 specifies this as the fallback for unrecognized subtypes of other types.
application/ogg: Ogg, a multimedia bitstream container format; Defined in RFC 3534
*/

/**
 * The application/acad state cybol type.
 *
 * AutoCAD files (by NCSA).
 * Registered.
 * Suffixes: dwg
 */
static wchar_t ACAD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'a', L'c', L'a', L'd'};
static wchar_t* ACAD_APPLICATION_STATE_CYBOL_FORMAT = ACAD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ACAD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/applefile state cybol type.
 *
 * AppleFile-Dateien files.
 * Registered.
 */
static wchar_t APLLEFILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'a', L'p', L'p', L'l', L'e', L'f', L'i', L'l', L'e'};
static wchar_t* APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT = APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* APLLEFILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/astound state cybol type.
 *
 * Astound files.
 * Registered.
 * Suffixes: asd, asn
 */
static wchar_t ASTOUND_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'a', L's', L't', L'o', L'u', L'n', L'd'};
static wchar_t* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT = ASTOUND_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dsptype state cybol type.
 *
 * TSP files.
 * Registered.
 * Suffixes: tsp
 */
static wchar_t DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'd', L's', L'p', L't', L'y', L'p', L'e'};
static wchar_t* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT = DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dxf state cybol type.
 *
 * AutoCAD files (by CERN).
 * Registered.
 * Suffixes: dxf
 */
static wchar_t DXF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'd', L'x', L'f'};
static wchar_t* DXF_APPLICATION_STATE_CYBOL_FORMAT = DXF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* DXF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/futuresplash state cybol type.
 *
 * Flash Futuresplash files.
 * Registered.
 * Suffixes: spl
 */
static wchar_t FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'f', L'u', L't', L'u', L'r', L'e', L's', L'p', L'l', L'a', L's', L'h'};
static wchar_t* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT = FUTURESPALSH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* FUTURESPALSH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/gzip state cybol type.
 *
 * GNU Zip files.
 * Registered.
 * Suffixes: gz
 */
static wchar_t GZIP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'g', L'z', L'i', L'p'};
static wchar_t* GZIP_APPLICATION_STATE_CYBOL_FORMAT = GZIP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* GZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/listenup state cybol type.
 *
 * Listenup files.
 * Registered.
 * Suffixes: ptlk
 */
static wchar_t LISTENUP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'l', L'i', L's', L't', L'e', L'n', L'u', L'p'};
static wchar_t* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT = LISTENUP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mac-binhex40 state cybol type.
 *
 * Macintosh Binär files.
 * Registered.
 * Suffixes: hqx
 */
static wchar_t MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L'a', L'c', L'-' L'b', L'i', L'n', L'h', L'e', L'x', L'4', L'0'};
static wchar_t* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT = MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mbedlet state cybol type.
 *
 * Mbedlet files.
 * Registered.
 * Suffixes: mbd
 */
static wchar_t MBEDLET_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L'b', L'e', L'd', L'l', L'e', L't'};
static wchar_t* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT = MBEDLET_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mif state cybol type.
 *
 * FrameMaker Interchange Format files.
 * Registered.
 * Suffixes: mif
 */
static wchar_t MIF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L'i', L'f'};
static wchar_t* MIF_APPLICATION_STATE_CYBOL_FORMAT = MIF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msexcel state cybol type.
 *
 * Microsoft Excel files.
 * Registered.
 * Suffixes: xls, xla
 */
static wchar_t MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L's', L'e', L'x', L'c', L'e', L'l'};
static wchar_t* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT = MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mshelp state cybol type.
 *
 * Microsoft Windows Help files.
 * Registered.
 * Suffixes: hlp, chm
 */
static wchar_t MSHELP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L's', L'h', L'e', L'l', L'p'};
static wchar_t* MSHELP_APPLICATION_STATE_CYBOL_FORMAT = MSHELP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MSHELP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mspowerpoint state cybol type.
 *
 * Microsoft Powerpoint files.
 * Registered.
 * Suffixes: ppt, ppz, pps, pot
 */
static wchar_t MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L's', L'p', L'o', L'w', L'e', L'r', L'p', L'o', L'i', L'n', L't'};
static wchar_t* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT = MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msword state cybol type.
 *
 * Microsoft Word files.
 * Registered.
 * Suffixes: doc, dot
 */
static wchar_t MSWORD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L's', L'w', L'o', L'r', L'd'};
static wchar_t* MSWORD_APPLICATION_STATE_CYBOL_FORMAT = MSWORD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* MSWORD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/octet-stream state cybol type.
 *
 * Executable files.
 * Registered.
 * Suffixes: bin, exe, com, dll, class
 */
static wchar_t OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'o', L'c', L't', L'e', L't', L'-', L's', L't', L'r', L'e', L'a', L'm'};
static wchar_t* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT = OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/oda state cybol type.
 *
 * Oda files.
 * Registered.
 * Suffixes: oda
 */
static wchar_t ODA_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'o', L'd', L'a'};
static wchar_t* ODA_APPLICATION_STATE_CYBOL_FORMAT = ODA_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ODA_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/pdf state cybol type.
 *
 * Adobe PDF files
 * Registered.
 * Suffixes: pdf 
 */
static wchar_t PDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'p', L'd', L'f'};
static wchar_t* PDF_APPLICATION_STATE_CYBOL_FORMAT = PDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* PDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/postscript state cybol type.
 *
 * Adobe PostScript files
 * Registered.
 * Suffixes: ai, eps, ps 
 */
static wchar_t POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'p', L'o', L's', L't', L's', L'c', L'r', L'i', L'p', L't'};
static wchar_t* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT = POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtc state cybol type.
 *
 * RTC files
 * Registered.
 * Suffixes: rtc
 */
static wchar_t RTC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'r', L't', L'c'};
static wchar_t* RTC_APPLICATION_STATE_CYBOL_FORMAT = RTC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* RTC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtf state cybol type.
 *
 * Microsoft RTF files
 * Registered.
 * Suffixes: rtf
 */
static wchar_t RTF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'r', L't', L'f'};
static wchar_t* RTF_APPLICATION_STATE_CYBOL_FORMAT = RTF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* RTF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/studiom state cybol type.
 *
 * Studiom files
 * Registered.
 * Suffixes: smp
 */
static wchar_t STUDIOM_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L's', L't', L'u', L'd', L'i', L'o', L'm'};
static wchar_t* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT = STUDIOM_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/toolbook state cybol type.
 *
 * Toolbook files
 * Registered.
 * Suffixes: tbk
 */
static wchar_t TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L't', L'o', L'o', L'l', L'b', L'o', L'o', L'k'};
static wchar_t* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT = TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xhtml+xml state cybol type.
 *
 * XHTML archive files. Defined by RFC 3236.
 * Registered.
 * Suffixes: xhtml
 */
static wchar_t XHTML_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'h', L't', L'm', L'l'};
static wchar_t* XHTML_APPLICATION_STATE_CYBOL_FORMAT = XHTML_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* XHTML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/zip state cybol type.
 *
 * ZIP archive files.
 * Registered.
 * Suffixes: zip
 */
static wchar_t ZIP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'z', L'i', L'p'};
static wchar_t* ZIP_APPLICATION_STATE_CYBOL_FORMAT = ZIP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*??
application/xml-dtd: DTD files; Defined by RFC 3023
*/

/* APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
