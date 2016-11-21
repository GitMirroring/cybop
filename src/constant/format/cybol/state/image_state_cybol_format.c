/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Franziska Wehner
 */

#ifndef IMAGE_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define IMAGE_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Image.
//
// IANA media type: image
//

/**
 * The image/cis-cod state cybol type.
 *
 * CIS-Cod files.
 * Registered.
 * Suffixes: cod
 */
static wchar_t* CIS_COD_IMAGE_STATE_CYBOL_FORMAT = L"image/cis-cod";
static int* CIS_COD_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/cmu-raster state cybol type.
 *
 * CMU-Raster files.
 * Registered.
 * Suffixes: ras
 */
static wchar_t* CMU_RASTER_IMAGE_STATE_CYBOL_FORMAT = L"image/cmu-raster";
static int* CMU_RASTER_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/fif state cybol type.
 *
 * FIF files.
 * Registered.
 * Suffixes: fif
 */
static wchar_t* FIF_IMAGE_STATE_CYBOL_FORMAT = L"image/fif";
static int* FIF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/gif state cybol type.
 *
 * GIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: gif
 */
static wchar_t* GIF_IMAGE_STATE_CYBOL_FORMAT = L"image/gif";
static int* GIF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/ief state cybol type.
 *
 * IEF files.
 * Registered.
 * Suffixes: ief
 */
static wchar_t* IEF_IMAGE_STATE_CYBOL_FORMAT = L"image/ief";
static int* IEF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/jpeg state cybol type.
 *
 * JPEG JFIF image.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: jpeg, jpg, jpe
 */
static wchar_t* JPEG_IMAGE_STATE_CYBOL_FORMAT = L"image/jpeg";
static int* JPEG_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/png state cybol type.
 *
 * Portable Network Graphics.
 * Registered.
 * Suffixes: png
 */
static wchar_t* PNG_IMAGE_STATE_CYBOL_FORMAT = L"image/png";
static int* PNG_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/tiff state cybol type.
 *
 * Tag Image File Format.
 * Defined in RFC 3302.
 * Suffixes: tiff, tif
 */
static wchar_t* TIFF_IMAGE_STATE_CYBOL_FORMAT = L"image/tiff";
static int* TIFF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/vasa state cybol type.
 *
 * Vasa files.
 * Registered.
 * Suffixes: mcf
 */
static wchar_t* VASA_IMAGE_STATE_CYBOL_FORMAT = L"image/vasa";
static int* VASA_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/vnd.wap.wbmp state cybol type.
 *
 * Bitmap files (WAP).
 * Registered.
 * Suffixes: wbmp
 */
static wchar_t* VND_WAP_WBMP_IMAGE_STATE_CYBOL_FORMAT = L"image/vnd.wap.wbmp";
static int* VND_WAP_WBMP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-freehand state cybol type.
 *
 * Freehand files.
 * Registered.
 * Suffixes: fh4, fh5, fhc
 */
static wchar_t* X_FREEHAND_IMAGE_STATE_CYBOL_FORMAT = L"image/x-freehand";
static int* X_FREEHAND_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-icon state cybol type.
 *
 * Icon files (f.e. Favoriten-Icons).
 * Registered.
 * Suffixes: ico
 */
static wchar_t* X_ICON_IMAGE_STATE_CYBOL_FORMAT = L"image/x-icon";
static int* X_ICON_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-anymap state cybol type.
 *
 * PBM Anymap files.
 * Registered.
 * Suffixes: pnm
 */
static wchar_t* X_PORTABLE_ANYMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-anymap";
static int* X_PORTABLE_ANYMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-bitmap state cybol type.
 *
 * PBM Bitmap files.
 * Registered.
 * Suffixes: pbm
 */
static wchar_t* X_PORTABLE_BITMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-bitmap";
static int* X_PORTABLE_BITMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-graymap state cybol type.
 *
 * PBM Graymap files.
 * Registered.
 * Suffixes: pgm
 */
static wchar_t* X_PORTABLE_GARYMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-graymap";
static int* X_PORTABLE_GRAYMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-pixmap state cybol type.
 *
 * PBM Pixmap files.
 * Registered.
 * Suffixes: ppm
 */
static wchar_t* X_PORTABLE_PIXMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-pixmap";
static int* X_PORTABLE_PIXMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-rgb state cybol type.
 *
 * RGB files.
 * Registered.
 * Suffixes: rgb
 */
static wchar_t* X_RGB_IMAGE_STATE_CYBOL_FORMAT = L"image/x-rgb";
static int* X_RGB_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-windowdump state cybol type.
 *
 * X-Windows Dump.
 * Registered.
 * Suffixes: xwd
 */
static wchar_t* X_WINDOWDUMP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-windowdump";
static int* X_WINDOWDUMP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-xbitmap state cybol type.
 *
 * XBM files.
 * Registered.
 * Suffixes: xbm
 */
static wchar_t* X_XBITMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-xbitmap";
static int* X_XBITMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-xpixmap state cybol type.
 *
 * XPM files.
 * Registered.
 * Suffixes: xpm
 */
static wchar_t* X_XPIXMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-xpixmap";
static int* X_XPIXMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*??
The image/vnd.microsoft.icon language.
ICO image.
Registered.
*/

/* IMAGE_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
