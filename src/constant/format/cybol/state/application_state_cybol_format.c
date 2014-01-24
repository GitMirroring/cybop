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
static wchar_t APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'a', L'p', L'p', L'l', L'e', L'f', L'i', L'l', L'e'};
static wchar_t* APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT = APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
static wchar_t* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT = FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
static wchar_t MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'm', L'a', L'c', L'-', L'b', L'i', L'n', L'h', L'e', L'x', L'4', L'0'};
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
 * The application/vocaltec-media-desc.
 *
 * Vocaltec Mediadesc files
 * Registered.
 * Suffixes: vmd
 */
static wchar_t VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'v', L'o', L'c', L'a', L'l', L't', L'e', L'c', L'-', L'm', L'e', L'd', L'i', L'a', L'-', L'd', L'e', L's', L'c'};
static wchar_t* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT = VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vocaltec-media-file.
 *
 * Vocaltec Media files
 * Registered.
 * Suffixes: vmf
 */
static wchar_t VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'v', L'o', L'c', L'a', L'l', L't', L'e', L'c', L'-', L'm', L'e', L'd', L'i', L'a', L'-', L'f', L'i', L'l', L'e'};
static wchar_t* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT = VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
 * The application/xml.
 *
 * XML files
 * Registered.
 * Suffixes: xml
 */
static wchar_t XML_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'm', L'l'};
static wchar_t* XML_APPLICATION_STATE_CYBOL_FORMAT = XML_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* XML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-bcpio.
 *
 * BCPIO files
 * Registered.
 * Suffixes: bcpio
 */
static wchar_t X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'b', L'c', L'p', L'i', L'o'};
static wchar_t* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT = X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-compress.
 *
 * zlib compressed files
 * Registered.
 * Suffixes: z
 */
static wchar_t X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'c', L'o', L'm', L'p', L'r', L'e', L's', L's'};
static wchar_t* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT = X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-cpio.
 *
 * CPIO files
 * Registered.
 * Suffixes: cpio
 */
static wchar_t X_CPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'c', L'p', L'i', L'o'};
static wchar_t* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT = X_CPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-csh.
 *
 * C-Shellscript files
 * Registered.
 * Suffixes: csh
 */
static wchar_t X_CSH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'c', L's', L'h'};
static wchar_t* X_CSH_APPLICATION_STATE_CYBOL_FORMAT = X_CSH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_CSH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-director.
 *
 * Macromedia Director files
 * Registered.
 * Suffixes: dcr, dir, dxr
 */
static wchar_t X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'd', L'i', L'r', L'e', L'c', L't', L'o', L'r'};
static wchar_t* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT = X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-dvi.
 *
 * DVI files
 * Registered.
 * Suffixes: dvi
 */
static wchar_t X_DVI_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'd', L'v', L'i'};
static wchar_t* X_DVI_APPLICATION_STATE_CYBOL_FORMAT = X_DVI_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_DVI_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-envoy.
 *
 * Envoy files
 * Registered.
 * Suffixes: evy
 */
static wchar_t X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'e', L'n', L'v', L'o', L'y'};
static wchar_t* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT = X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-gtar.
 *
 * GNU tar files
 * Registered.
 * Suffixes: gtar
 */
static wchar_t X_GTAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'g', L't', L'a', L'r'};
static wchar_t* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT = X_GTAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-hdf.
 *
 * HDF files
 * Registered.
 * Suffixes: hdf
 */
static wchar_t X_HDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'h', L'd', L'f'};
static wchar_t* X_HDF_APPLICATION_STATE_CYBOL_FORMAT = X_HDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_HDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-httpd-php.
 *
 * PHP files
 * Registered.
 * Suffixes: php, phtml
 */
static wchar_t X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'h', L't', L't', L'p', L'd', L'-', L'p', L'h', L'p'};
static wchar_t* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT = X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-javascript.
 *
 * server side JavaScript files
 * Registered.
 * Suffixes: js
 */
static wchar_t X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'j', L'a', L'v', L'a', L's', L'c', L'r', L'i', L'p', L't'};
static wchar_t* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT = X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-macbinary.
 *
 * Macintosh binary files
 * Registered.
 * Suffixes: bin
 */
static wchar_t X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'm', L'a', L'c', L'b', L'i', L'n', L'a', L'r', L'y'};
static wchar_t* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT = X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-mif.
 *
 * FrameMaker Interchange Format files
 * Registered.
 * Suffixes: mif
 */
static wchar_t X_MIF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'm', L'i', L'f'};
static wchar_t* X_MIF_APPLICATION_STATE_CYBOL_FORMAT = X_MIF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-netcdf.
 *
 * Unidata CDF files
 * Registered.
 * Suffixes: nc, cdf
 */
static wchar_t X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'n', L'e', L't', L'c', L'd', L'f'};
static wchar_t* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT = X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-nschat.
 *
 * NS Chat files
 * Registered.
 * Suffixes: nsc
 */
static wchar_t X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'n', L's', L'c', L'h', L'a', L't'};
static wchar_t* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT = X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sh.
 *
 * Bourne Shellscript files
 * Registered.
 * Suffixes: sh
 */
static wchar_t X_SH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'h'};
static wchar_t* X_SH_APPLICATION_STATE_CYBOL_FORMAT = X_SH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shar.
 *
 * Shell archive files
 * Registered.
 * Suffixes: shar
 */
static wchar_t X_SHAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'h', L'a', L'r'};
static wchar_t* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT = X_SHAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shockwave-flash.
 *
 * Flash Shockwave files
 * Registered.
 * Suffixes: swf, cab
 */
static wchar_t X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'h', L'o', L'c', L'k', L'w', L'a', L'v', L'e', L'-', L'f', L'l', L'a', L's', L'h'};
static wchar_t* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT = X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sprite.
 *
 * Sprite files
 * Registered.
 * Suffixes: spr, sprite
 */
static wchar_t X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'p', L'r', L'i', L't', L'e'};
static wchar_t* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT = X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-stuffit.
 *
 * Stuffit files
 * Registered.
 * Suffixes: sit
 */
static wchar_t X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L't', L'u', L'f', L'f', L'i', L't'};
static wchar_t* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT = X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-supercard.
 *
 * Supercard files
 * Registered.
 * Suffixes: sca
 */
static wchar_t X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'u', L'p', L'e', L'r', L'c', L'a', L'r', L'd'};
static wchar_t* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT = X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4cpio.
 *
 * CPIO files
 * Registered.
 * Suffixes: sv4cpio
 */
static wchar_t X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'v', L'4', L'c', L'p', L'i', L'o'};
static wchar_t* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT = X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4crc.
 *
 * CPIO files with CRC
 * Registered.
 * Suffixes: sv4crc
 */
static wchar_t X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L's', L'v', L'4', L'c', L'r', L'c'};
static wchar_t* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT = X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tcl.
 *
 * TCL script files
 * Registered.
 * Suffixes: tcl
 */
static wchar_t X_TCL_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'c', L'l'};
static wchar_t* X_TCL_APPLICATION_STATE_CYBOL_FORMAT = X_TCL_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TCL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tex.
 *
 * TeX files
 * Registered.
 * Suffixes: tex
 */
static wchar_t X_TEX_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'e', L'x'};
static wchar_t* X_TEX_APPLICATION_STATE_CYBOL_FORMAT = X_TEX_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TEX_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-texinfo.
 *
 * Texinfo files
 * Registered.
 * Suffixes: texinfo, texi
 */
static wchar_t X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'e', L'x', L'i', L'n', L'f', L'o'};
static wchar_t* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT = X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff.
 *
 * TROFF files (UNIX)
 * Registered.
 * Suffixes: t, tr, roff
 */
static wchar_t X_TROFF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'r', L'o', L'f', L'f'};
static wchar_t* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT = X_TROFF_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-man.
 *
 * TROFF files (UNIX)
 * Registered.
 * Suffixes: t, tr, roff
 */
static wchar_t X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'r', L'o', L'f', L'f', L'-', L'm', L'a', L'n'};
static wchar_t* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT = X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-me.
 *
 * TROFF files with ME-Makros (Unix)
 * Registered.
 * Suffixes: me, roff
 */
static wchar_t X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'r', L'o', L'f', L'f', L'-', L'm', L'e'};
static wchar_t* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT = X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-ms.
 *
 * TROFF files with MS-Makros (Unix)
 * Registered.
 * Suffixes: ms, roff
 */
static wchar_t X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L't', L'r', L'o', L'f', L'f', L'-', L'm', L's'};
static wchar_t* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT = X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-ustar.
 *
 * tar archiv files (Posix)
 * Registered.
 * Suffixes: ustar
 */
static wchar_t X_USTAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'u', L's', L't', L'a', L'r'};
static wchar_t* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT = X_USTAR_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-wais-source.
 *
 * WAIS source files
 * Registered.
 * Suffixes: src
 */
static wchar_t X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'w', L'a', L'i', L's', L'-', L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT = X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-www-form-urlencoded.
 *
 * HTML form urlencoded files on CGI
 * Registered.
 */
static wchar_t X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'a', L'p', L'p', L'l', L'i', L'c', L'a', L't', L'i', L'o', L'n', L'/', L'x', L'-', L'w', L'w', L'w', L'-', L'f', L'o', L'r', L'm', L'-', L'u', L'r', L'l', L'e', L'n', L'c', L'o', L'd', L'e', L'd'};
static wchar_t* X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT = X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT_ARRAY;
static int* X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/zip state cybol type.
 *
 * ZIP archive files.
 * Registered.
 * Suffixes: zip
 */
static wchar_t* ZIP_APPLICATION_STATE_CYBOL_FORMAT = L"application/zip";
static int* ZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*??
application/xml-dtd: DTD files; Defined by RFC 3023
*/

/* APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif