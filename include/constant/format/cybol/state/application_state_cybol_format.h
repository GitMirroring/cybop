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
 * @author Franziska Wehner>
 */

#ifndef APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Application (multi-purpose)
//
// IANA media type: application
//

/**
 * The application/acad state cybol format.
 *
 * AutoCAD files (by NCSA).
 *
 * Common file suffixes: dwg
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
 * Common file suffixes: asd, asn
 */
static wchar_t* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT = L"application/astound";
static int* ASTOUND_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dsptype state cybol format.
 *
 * TSP files.
 * Registered.
 * Common file suffixes: tsp
 */
static wchar_t* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT = L"application/dsptype";
static int* DSPTYPE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/dxf state cybol format.
 *
 * AutoCAD files (by CERN).
 * Registered.
 * Common file suffixes: dxf
 */
static wchar_t* DXF_APPLICATION_STATE_CYBOL_FORMAT = L"application/dxf";
static int* DXF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/EDI-X12 state cybol format.
 *
 * EDI X12 data; Defined in RFC 1767
 */
static wchar_t* EDI_X12_APPLICATION_STATE_CYBOL_FORMAT = L"application/EDI-X12";
static int* EDI_X12_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/EDIFACT state cybol format.
 *
 * EDI EDIFACT data; Defined in RFC 1767
 */
static wchar_t* EDIFACT_APPLICATION_STATE_CYBOL_FORMAT = L"application/EDIFACT";
static int* EDIFACT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/futuresplash state cybol format.
 *
 * Flash Futuresplash files.
 * Registered.
 * Common file suffixes: spl
 */
static wchar_t* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT = L"application/futuresplash";
static int* FUTURESPLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/gzip state cybol format.
 *
 * GNU Zip files.
 * Registered.
 * Common file suffixes: gz
 */
static wchar_t* GZIP_APPLICATION_STATE_CYBOL_FORMAT = L"application/gzip";
static int* GZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/javascript state cybol format.
 *
 * TODO: Description:
 *
 * A JavaScript program script.
 *
 * Common file suffixes: js
 *
 * There are three MIME assignments for javascript data:
 * - application/javascript (official)
 * - application/x-javascript (outdated)
 * - text/javascript (unofficial)
 *
 * Preference should be given to the OFFICIAL mime type "application/javascript".
 *
 * TODO: Examples:
 *
 * <node name="program_source_code" channel="file" format="application/javascript" model="path/to/file.js"/>
 */
static wchar_t* JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT = L"application/javascript";
static int* JAVASCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/json state cybol format.
 *
 * Description:
 *
 * Text data given in JavaScript Object Notation (JSON).
 *
 * There are three MIME assignments for json data:
 * - application/json (official)
 * - text/json (unofficial)
 * - text/javascript (unofficial)
 *
 * Preference should be given to the OFFICIAL mime type "application/json".
 *
 * Examples:
 *
 * <node name="data" channel="file" format="application/json" model="path/to/file.json"/>
 */
static wchar_t* JSON_APPLICATION_STATE_CYBOL_FORMAT = L"application/json";
static int* JSON_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/listenup state cybol format.
 *
 * Listenup files.
 * Registered.
 * Common file suffixes: ptlk
 */
static wchar_t* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT = L"application/listenup";
static int* LISTENUP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mac-binhex40 state cybol format.
 *
 * Macintosh Binär files.
 * Registered.
 * Common file suffixes: hqx
 */
static wchar_t* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT = L"application/mac-binhex40";
static int* MAC_BINHEX40_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mbedlet state cybol format.
 *
 * Mbedlet files.
 * Registered.
 * Common file suffixes: mbd
 */
static wchar_t* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT = L"application/mbedlet";
static int* MBEDLET_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mif state cybol format.
 *
 * FrameMaker Interchange Format files.
 * Registered.
 * Common file suffixes: mif
 */
static wchar_t* MIF_APPLICATION_STATE_CYBOL_FORMAT = L"application/mif";
static int* MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msexcel state cybol format.
 *
 * Microsoft Excel files.
 * Registered.
 * Common file suffixes: xls, xla
 */
static wchar_t* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT = L"application/msexcel";
static int* MSEXCEL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mshelp state cybol format.
 *
 * Microsoft Windows Help files.
 * Registered.
 * Common file suffixes: hlp, chm
 */
static wchar_t* MSHELP_APPLICATION_STATE_CYBOL_FORMAT = L"application/mshelp";
static int* MSHELP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/mspowerpoint state cybol format.
 *
 * Microsoft Powerpoint files.
 * Registered.
 * Common file suffixes: ppt, ppz, pps, pot
 */
static wchar_t* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT = L"application/mspowerpoint";
static int* MSPOWERPOINT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/msword state cybol format.
 *
 * Microsoft Word files.
 * Registered.
 * Common file suffixes: doc, dot
 */
static wchar_t* MSWORD_APPLICATION_STATE_CYBOL_FORMAT = L"application/msword";
static int* MSWORD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/octet-stream state cybol format.
 *
 * Description:
 *
 * Arbitrary byte stream.
 *
 * This is thought of as the "default" media type used by several operating systems,
 * often used to identify executable files, files of unknown type, or files that should
 * be downloaded in protocols that do not provide a separate "content disposition" header.
 *
 * RFC 2046 specifies this as the fallback for unrecognized subtypes of other types.
 *
 * Common file suffixes: bin, exe, com, dll, class, dat
 *
 * Caution! Do not mix it up with "number/byte" representing numbers in the range 0..255.
 * Numbers in an array are separated by comma; bytes of a octet stream are not.
 *
 * Examples:
 *
 * <node name="image" channel="inline" format="application/octet-stream" model=""/>
 * <node name="text" channel="file" format="application/octet-stream" model="path/to/file.dat"/>
 */
static wchar_t* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT = L"application/octet-stream";
static int* OCTET_STREAM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/oda state cybol format.
 *
 * Oda files.
 * Registered.
 * Common file suffixes: oda
 */
static wchar_t* ODA_APPLICATION_STATE_CYBOL_FORMAT = L"application/oda";
static int* ODA_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/ogg state cybol format.
 *
 * Ogg, a multimedia bitstream container format; Defined in RFC 3534
 */
static wchar_t* OGG_APPLICATION_STATE_CYBOL_FORMAT = L"application/ogg";
static int* OGG_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/pdf state cybol format.
 *
 * Adobe PDF files
 * Registered.
 * Common file suffixes: pdf
 */
static wchar_t* PDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/pdf";
static int* PDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/postscript state cybol format.
 *
 * Adobe PostScript files
 * Registered.
 * Common file suffixes: ai, eps, ps
 */
static wchar_t* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT = L"application/postscript";
static int* POSTSCRIPT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtc state cybol format.
 *
 * RTC files
 * Registered.
 * Common file suffixes: rtc
 */
static wchar_t* RTC_APPLICATION_STATE_CYBOL_FORMAT = L"application/rtc";
static int* RTC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/rtf state cybol format.
 *
 * Microsoft RTF files
 * Registered.
 * Common file suffixes: rtf
 */
static wchar_t* RTF_APPLICATION_STATE_CYBOL_FORMAT = L"application/rtf";
static int* RTF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/studiom state cybol format.
 *
 * Studiom files
 * Registered.
 * Common file suffixes: smp
 */
static wchar_t* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT = L"application/studiom";
static int* STUDIOM_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/toolbook state cybol format.
 *
 * Toolbook files.
 * Registered.
 * Common file suffixes: tbk
 */
static wchar_t* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT = L"application/toolbook";
static int* TOOLBOOK_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.wap.wmlc state cybol format.
 *
 * WMLC files (WAP).
 * Registered.
 * Common file suffixes: wmlc
 */
static wchar_t* VND_WAP_WMLC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.wap.wmlc";
static int* VND_WAP_WMLC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vnd.wap.wmlscriptc state cybol format.
 *
 * WML-Script-C files (WAP).
 * Registered.
 * Common file suffixes: wmlsc
 */
static wchar_t* VND_WAP_WMLSCRIPTC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vnd.wap.wmlscriptc";
static int* VND_WAP_WMLSCRIPTC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vocaltec-media-desc state cybol format.
 *
 * Vocaltec Mediadesc files
 * Registered.
 * Common file suffixes: vmd
 */
static wchar_t* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT = L"application/vocaltec-media-desc";
static int* VOCALTEC_MEDIA_DESC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/vocaltec-media-file state cybol format.
 *
 * Vocaltec Media files
 * Registered.
 * Common file suffixes: vmf
 */
static wchar_t* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT = L"application/vocaltec-media-file";
static int* VOCALTEC_MEDIA_FILE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_31_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-bcpio state cybol format.
 *
 * BCPIO files
 * Registered.
 * Common file suffixes: bcpio
 */
static wchar_t* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-bcpio";
static int* X_BCPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-compress state cybol format.
 *
 * zlib compressed files
 * Registered.
 * Common file suffixes: z
 */
static wchar_t* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-compress";
static int* X_COMPRESS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-cpio state cybol format.
 *
 * CPIO files
 * Registered.
 * Common file suffixes: cpio
 */
static wchar_t* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-cpio";
static int* X_CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-csh state cybol format.
 *
 * C-Shellscript files
 * Registered.
 * Common file suffixes: csh
 */
static wchar_t* X_CSH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-csh";
static int* X_CSH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-director state cybol format.
 *
 * Macromedia Director files
 * Registered.
 * Common file suffixes: dcr, dir, dxr
 */
static wchar_t* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-director";
static int* X_DIRECTOR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-dvi state cybol format.
 *
 * Digital Videfiles in DVI format
 *
 * Common file suffixes: dvi
 */
static wchar_t* X_DVI_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-dvi";
static int* X_DVI_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-envoy state cybol format.
 *
 * Envoy files
 * Registered.
 * Common file suffixes: evy
 */
static wchar_t* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-envoy";
static int* X_ENVOY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-gtar state cybol format.
 *
 * GNU tar files
 * Registered.
 * Common file suffixes: gtar
 */
static wchar_t* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-gtar";
static int* X_GTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-hdf state cybol format.
 *
 * HDF files
 * Registered.
 * Common file suffixes: hdf
 */
static wchar_t* X_HDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-hdf";
static int* X_HDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-macbinary state cybol format.
 *
 * Macintosh binary files
 * Registered.
 * Common file suffixes: bin
 */
static wchar_t* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-macbinary";
static int* X_MACBINARY_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-mif state cybol format.
 *
 * FrameMaker Interchange Format files
 * Registered.
 * Common file suffixes: mif
 */
static wchar_t* X_MIF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-mif";
static int* X_MIF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-netcdf state cybol format.
 *
 * Unidata CDF files
 * Registered.
 * Common file suffixes: nc, cdf
 */
static wchar_t* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-netcdf";
static int* X_NETCDF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-nschat state cybol format.
 *
 * NS Chat files
 * Registered.
 * Common file suffixes: nsc
 */
static wchar_t* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-nschat";
static int* X_NSCHAT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sh state cybol format.
 *
 * Bourne Shellscript files
 * Registered.
 * Common file suffixes: sh
 */
static wchar_t* X_SH_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sh";
static int* X_SH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-shar state cybol format.
 *
 * Shell archive files
 * Registered.
 * Common file suffixes: shar
 */
static wchar_t* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-shar";
static int* X_SHAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/shockwave-flash state cybol format.
 *
 * Adobe shockwave flash files documented in Adobe TechNote tn_4151 and Adobe TechNote tn_16509.
 *
 * Common file suffixes: swf, cab
 */
static wchar_t* SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT = L"application/shockwave-flash";
static int* SHOCKWAVE_FLASH_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sprite state cybol format.
 *
 * Sprite files
 * Registered.
 * Common file suffixes: spr, sprite
 */
static wchar_t* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sprite";
static int* X_SPRITE_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/stuffit state cybol format.
 *
 * StuffIt archive files.
 *
 * Common file suffixes: sit
 */
static wchar_t* STUFFIT_APPLICATION_STATE_CYBOL_FORMAT = L"application/stuffit";
static int* STUFFIT_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-supercard state cybol format.
 *
 * Supercard files
 * Registered.
 * Common file suffixes: sca
 */
static wchar_t* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-supercard";
static int* X_SUPERCARD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4cpio state cybol format.
 *
 * CPIO files
 * Registered.
 * Common file suffixes: sv4cpio
 */
static wchar_t* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sv4cpio";
static int* X_SV4CPIO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-sv4crc state cybol format.
 *
 * CPIO files with CRC
 * Registered.
 * Common file suffixes: sv4crc
 */
static wchar_t* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-sv4crc";
static int* X_SV4CRC_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tcl state cybol format.
 *
 * TCL script files
 * Registered.
 * Common file suffixes: tcl
 */
static wchar_t* X_TCL_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-tcl";
static int* X_TCL_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-tex state cybol format.
 *
 * TeX files
 * Registered.
 * Common file suffixes: tex
 */
static wchar_t* X_TEX_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-tex";
static int* X_TEX_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-texinfo state cybol format.
 *
 * Texinfo files
 * Registered.
 * Common file suffixes: texinfo, texi
 */
static wchar_t* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-texinfo";
static int* X_TEXINFO_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff state cybol format.
 *
 * TROFF files (UNIX)
 * Registered.
 * Common file suffixes: t, tr, roff
 */
static wchar_t* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff";
static int* X_TROFF_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-man state cybol format.
 *
 * TROFF files (UNIX)
 * Registered.
 * Common file suffixes: t, tr, roff
 */
static wchar_t* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-man";
static int* X_TROFF_MAN_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-me state cybol format.
 *
 * TROFF files with ME-Makros (Unix)
 * Registered.
 * Common file suffixes: me, roff
 */
static wchar_t* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-me";
static int* X_TROFF_ME_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-troff-ms state cybol format.
 *
 * TROFF files with MS-Makros (Unix)
 * Registered.
 * Common file suffixes: ms, roff
 */
static wchar_t* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-troff-ms";
static int* X_TROFF_MS_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-ustar state cybol format.
 *
 * tar archiv files (Posix)
 * Registered.
 * Common file suffixes: ustar
 */
static wchar_t* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT = L"application/x-ustar";
static int* X_USTAR_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/x-wais-source state cybol format.
 *
 * WAIS source files
 * Registered.
 * Common file suffixes: src
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
 * The application/xhtml+xml state cybol format.
 *
 * XHTML archive files. Defined by RFC 3236.
 * Registered.
 * Common file suffixes: xhtml
 */
static wchar_t* XHTML_APPLICATION_STATE_CYBOL_FORMAT = L"application/xhtml+xml";
static int* XHTML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xml state cybol format.
 *
 * Description:
 *
 * Data given in XML format.
 *
 * The Extensible Markup Language (XML) version 1.0 was defined in 1998.
 * Its structure and vocabulary can be defined freely, either as
 * Document Type Definition (DTD) or as XML Schema Definition (XSD).
 *
 * If given in form of a file, then the suffix is xml in case no DTD or XSD
 * is available. Otherwise, a suffix representing the DTD or XSD may be used.
 *
 * There are two MIME assignments for XML data:
 * - application/xml (RFC 7303, previously RFC 3023)
 * - text/xml (RFC 7303, previously RFC 3023)
 * However, since the introduction of RFC 7303, these are
 * to be regarded as the SAME in ALL aspects except name.
 *
 * Examples:
 *
 * <node name="document" channel="file" format="application/xml" model="path/to/file.xml"/>
 */
static wchar_t* XML_APPLICATION_STATE_CYBOL_FORMAT = L"application/xml";
static int* XML_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/xml-dtd state cybol format.
 *
 * DTD files; Defined by RFC 3023
 */
static wchar_t* XML_DTD_APPLICATION_STATE_CYBOL_FORMAT = L"application/xml-dtd";
static int* XML_DTD_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The application/zip state cybol format.
 *
 * ZIP archive files.
 * Registered.
 * Common file suffixes: zip
 */
static wchar_t* ZIP_APPLICATION_STATE_CYBOL_FORMAT = L"application/zip";
static int* ZIP_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* APPLICATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
