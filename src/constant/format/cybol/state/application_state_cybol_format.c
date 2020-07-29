/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Franziska Wehner>
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
 * The application/acad state cybol format.
 *
 * AutoCAD files (by NCSA).
 * Registered.
 * Suffixes: dwg
 */
static wchar_t* ACAD_APPLICATION_STATE_CYBOL_FORMAT = L"application/acad";
static int* ACAD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/applefile state cybol format.
 *
 * AppleFile-Dateien files.
 * Registered.
 */
static wchar_t* APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT = L"application/applefile";
static int* APPLEFILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/astound state cybol format.
 *
 * Astound files.
 * Registered.
 * Suffixes: asd, asn
 */
static wchar_t* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT = L"application/astound";
static int* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dsptype state cybol format.
 *
 * TSP files.
 * Registered.
 * Suffixes: tsp
 */
static wchar_t* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT = L"application/dsptype";
static int* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dxf state cybol format.
 *
 * AutoCAD files (by CERN).
 * Registered.
 * Suffixes: dxf
 */
static wchar_t* DXF_APPLICATION_STATE_CYBOL_FORMAT = L"application/dxf";
static int* DXF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/futuresplash state cybol format.
 *
 * Flash Futuresplash files.
 * Registered.
 * Suffixes: spl
 */
static wchar_t* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT = L"application/futuresplash";
static int* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/gzip state cybol format.
 *
 * GNU Zip files.
 * Registered.
 * Suffixes: gz
 */
static wchar_t* GZIP_APPLICATION_STATE_CYBOL_FORMAT = L"application/gzip";
static int* GZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/listenup state cybol format.
 *
 * Listenup files.
 * Registered.
 * Suffixes: ptlk
 */
static wchar_t* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT = L"application/listenup";
static int* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mac-binhex40 state cybol format.
 *
 * Macintosh Binär files.
 * Registered.
 * Suffixes: hqx
 */
static wchar_t* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT = L"application/mac-binhex40";
static int* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mbedlet state cybol format.
 *
 * Mbedlet files.
 * Registered.
 * Suffixes: mbd
 */
static wchar_t* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT = L"application/mbedlet";
static int* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mif state cybol format.
 *
 * FrameMaker Interchange Format files.
 * Registered.
 * Suffixes: mif
 */
static wchar_t* MIF_APPLICATION_STATE_CYBOL_FORMAT = L"application/mif";
static int* MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msexcel state cybol format.
 *
 * Microsoft Excel files.
 * Registered.
 * Suffixes: xls, xla
 */
static wchar_t* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT = L"application/msexcel";
static int* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mshelp state cybol format.
 *
 * Microsoft Windows Help files.
 * Registered.
 * Suffixes: hlp, chm
 */
static wchar_t* MSHELP_APPLICATION_STATE_CYBOL_FORMAT = L"application/mshelp";
static int* MSHELP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mspowerpoint state cybol format.
 *
 * Microsoft Powerpoint files.
 * Registered.
 * Suffixes: ppt, ppz, pps, pot
 */
static wchar_t* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT = L"application/mspowerpoint";
static int* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msword state cybol format.
 *
 * Microsoft Word files.
 * Registered.
 * Suffixes: doc, dot
 */
static wchar_t* MSWORD_APPLICATION_STATE_CYBOL_FORMAT = L"application/msword";
static int* MSWORD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/octet-stream state cybol format.
 *
 * Executable files.
 * Registered.
 * Suffixes: bin, exe, com, dll, class
 */
static wchar_t* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT = L"application/octet-stream";
static int* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/oda state cybol format.
 *
 * Oda files.
 * Registered.
 * Suffixes: oda
 */
static wchar_t* ODA_APPLICATION_STATE_CYBOL_FORMAT = L"application/oda";
static int* ODA_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/pdf state cybol format.
 *
 * Adobe PDF files
 * Registered.
 * Suffixes: pdf
 */
static wchar_t* PDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/pdf";
static int* PDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/postscript state cybol format.
 *
 * Adobe PostScript files
 * Registered.
 * Suffixes: ai, eps, ps
 */
static wchar_t* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT = L"application/postscript";
static int* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtc state cybol format.
 *
 * RTC files
 * Registered.
 * Suffixes: rtc
 */
static wchar_t* RTC_APPLICATION_STATE_CYBOL_FORMAT = L"application/rtc";
static int* RTC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtf state cybol format.
 *
 * Microsoft RTF files
 * Registered.
 * Suffixes: rtf
 */
static wchar_t* RTF_APPLICATION_STATE_CYBOL_FORMAT = L"application/rtf";
static int* RTF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/studiom state cybol format.
 *
 * Studiom files
 * Registered.
 * Suffixes: smp
 */
static wchar_t* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT = L"application/studiom";
static int* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/toolbook state cybol format.
 *
 * Toolbook files.
 * Registered.
 * Suffixes: tbk
 */
static wchar_t* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT = L"application/toolbook";
static int* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.wap.wmlc state cybol format.
 *
 * WMLC files (WAP).
 * Registered.
 * Suffixes: wmlc
 */
static wchar_t* VND_WAP_WMLC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.wap.wmlc";
static int* VND_WAP_WMLC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.wap.wmlscriptc state cybol format.
 *
 * WML-Script-C files (WAP).
 * Registered.
 * Suffixes: wmlsc
 */
static wchar_t* VND_WAP_WMLSCRIPTC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.wap.wmlscriptc";
static int* VND_WAP_WMLSCRIPTC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vocaltec-media-desc state cybol format.
 *
 * Vocaltec Mediadesc files
 * Registered.
 * Suffixes: vmd
 */
static wchar_t* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vocaltec-media-desc";
static int* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vocaltec-media-file state cybol format.
 *
 * Vocaltec Media files
 * Registered.
 * Suffixes: vmf
 */
static wchar_t* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT = L"application/vocaltec-media-file";
static int* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xhtml+xml state cybol format.
 *
 * XHTML archive files. Defined by RFC 3236.
 * Registered.
 * Suffixes: xhtml
 */
static wchar_t* XHTML_APPLICATION_STATE_CYBOL_FORMAT = L"application/xhtml+xml";
static int* XHTML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xml state cybol format.
 *
 * XML files
 * Registered.
 * Suffixes: xml
 */
static wchar_t* XML_APPLICATION_STATE_CYBOL_FORMAT = L"application/xml";
static int* XML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-bcpio state cybol format.
 *
 * BCPIO files
 * Registered.
 * Suffixes: bcpio
 */
static wchar_t* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-bcpio";
static int* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-compress state cybol format.
 *
 * zlib compressed files
 * Registered.
 * Suffixes: z
 */
static wchar_t* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-compress";
static int* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-cpio state cybol format.
 *
 * CPIO files
 * Registered.
 * Suffixes: cpio
 */
static wchar_t* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-cpio";
static int* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-csh state cybol format.
 *
 * C-Shellscript files
 * Registered.
 * Suffixes: csh
 */
static wchar_t* X_CSH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-csh";
static int* X_CSH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-director state cybol format.
 *
 * Macromedia Director files
 * Registered.
 * Suffixes: dcr, dir, dxr
 */
static wchar_t* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-director";
static int* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-dvi state cybol format.
 *
 * DVI files
 * Registered.
 * Suffixes: dvi
 */
static wchar_t* X_DVI_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-dvi";
static int* X_DVI_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-envoy state cybol format.
 *
 * Envoy files
 * Registered.
 * Suffixes: evy
 */
static wchar_t* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-envoy";
static int* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-gtar state cybol format.
 *
 * GNU tar files
 * Registered.
 * Suffixes: gtar
 */
static wchar_t* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-gtar";
static int* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-hdf state cybol format.
 *
 * HDF files
 * Registered.
 * Suffixes: hdf
 */
static wchar_t* X_HDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-hdf";
static int* X_HDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-httpd-php state cybol format.
 *
 * PHP files
 * Registered.
 * Suffixes: php, phtml
 */
static wchar_t* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-httpd-php";
static int* X_HTTPD_PHP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-javascript state cybol format.
 *
 * server side JavaScript files
 * Registered.
 * Suffixes: js
 */
static wchar_t* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-javascript";
static int* X_JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-macbinary state cybol format.
 *
 * Macintosh binary files
 * Registered.
 * Suffixes: bin
 */
static wchar_t* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-macbinary";
static int* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-mif state cybol format.
 *
 * FrameMaker Interchange Format files
 * Registered.
 * Suffixes: mif
 */
static wchar_t* X_MIF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-mif";
static int* X_MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-netcdf state cybol format.
 *
 * Unidata CDF files
 * Registered.
 * Suffixes: nc, cdf
 */
static wchar_t* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-netcdf";
static int* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-nschat state cybol format.
 *
 * NS Chat files
 * Registered.
 * Suffixes: nsc
 */
static wchar_t* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-nschat";
static int* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sh state cybol format.
 *
 * Bourne Shellscript files
 * Registered.
 * Suffixes: sh
 */
static wchar_t* X_SH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sh";
static int* X_SH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shar state cybol format.
 *
 * Shell archive files
 * Registered.
 * Suffixes: shar
 */
static wchar_t* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-shar";
static int* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shockwave-flash state cybol format.
 *
 * Flash Shockwave files
 * Registered.
 * Suffixes: swf, cab
 */
static wchar_t* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-shockwave-flash";
static int* X_SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_29_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sprite state cybol format.
 *
 * Sprite files
 * Registered.
 * Suffixes: spr, sprite
 */
static wchar_t* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sprite";
static int* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-stuffit state cybol format.
 *
 * Stuffit files
 * Registered.
 * Suffixes: sit
 */
static wchar_t* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-stuffit";
static int* X_STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-supercard state cybol format.
 *
 * Supercard files
 * Registered.
 * Suffixes: sca
 */
static wchar_t* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-supercard";
static int* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4cpio state cybol format.
 *
 * CPIO files
 * Registered.
 * Suffixes: sv4cpio
 */
static wchar_t* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sv4cpio";
static int* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4crc state cybol format.
 *
 * CPIO files with CRC
 * Registered.
 * Suffixes: sv4crc
 */
static wchar_t* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sv4crc";
static int* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tcl state cybol format.
 *
 * TCL script files
 * Registered.
 * Suffixes: tcl
 */
static wchar_t* X_TCL_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-tcl";
static int* X_TCL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tex state cybol format.
 *
 * TeX files
 * Registered.
 * Suffixes: tex
 */
static wchar_t* X_TEX_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-tex";
static int* X_TEX_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-texinfo state cybol format.
 *
 * Texinfo files
 * Registered.
 * Suffixes: texinfo, texi
 */
static wchar_t* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-texinfo";
static int* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff state cybol format.
 *
 * TROFF files (UNIX)
 * Registered.
 * Suffixes: t, tr, roff
 */
static wchar_t* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff";
static int* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-man state cybol format.
 *
 * TROFF files (UNIX)
 * Registered.
 * Suffixes: t, tr, roff
 */
static wchar_t* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-man";
static int* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-me state cybol format.
 *
 * TROFF files with ME-Makros (Unix)
 * Registered.
 * Suffixes: me, roff
 */
static wchar_t* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-me";
static int* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-ms state cybol format.
 *
 * TROFF files with MS-Makros (Unix)
 * Registered.
 * Suffixes: ms, roff
 */
static wchar_t* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-ms";
static int* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-ustar state cybol format.
 *
 * tar archiv files (Posix)
 * Registered.
 * Suffixes: ustar
 */
static wchar_t* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-ustar";
static int* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-wais-source state cybol format.
 *
 * WAIS source files
 * Registered.
 * Suffixes: src
 */
static wchar_t* X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-wais-source";
static int* X_WAIS_SOURCE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-www-form-urlencoded state cybol format.
 *
 * HTML form urlencoded files on CGI
 * Registered.
 */
static wchar_t* X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-www-form-urlencoded";
static int* X_WWW_FORM_URLENCODED_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_33_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/zip state cybol format.
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
