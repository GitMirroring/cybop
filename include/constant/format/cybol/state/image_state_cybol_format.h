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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Franziska Wehner
 */

#ifndef IMAGE_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define IMAGE_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Image
//
// IANA media type: image
//

/**
 * The image/cis-cod state cybol format.
 *
 * CIS-Cod files.
 * Registered.
 * Common file suffixes: cod
 */
static wchar_t* CIS_COD_IMAGE_STATE_CYBOL_FORMAT = L"image/cis-cod";
static int* CIS_COD_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/cmu-raster state cybol format.
 *
 * CMU-Raster files.
 * Registered.
 * Common file suffixes: ras
 */
static wchar_t* CMU_RASTER_IMAGE_STATE_CYBOL_FORMAT = L"image/cmu-raster";
static int* CMU_RASTER_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/fif state cybol format.
 *
 * FIF files.
 * Registered.
 * Common file suffixes: fif
 */
static wchar_t* FIF_IMAGE_STATE_CYBOL_FORMAT = L"image/fif";
static int* FIF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/gif state cybol format.
 *
 * Description:
 *
 * An image in Graphics Interchange Format (GIF).
 *
 * The file suffix is gif.
 *
 * Examples:
 *
 * <node name="data" channel="file" format="image/gif" model="path/to/file.gif"/>
 */
static wchar_t* GIF_IMAGE_STATE_CYBOL_FORMAT = L"image/gif";
static int* GIF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/ief state cybol format.
 *
 * IEF files.
 * Registered.
 * Common file suffixes: ief
 */
static wchar_t* IEF_IMAGE_STATE_CYBOL_FORMAT = L"image/ief";
static int* IEF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/jpeg state cybol format.
 *
 * Description:
 *
 * An image format defined by the Joint Photographic Experts Group (JPEG).
 * The format itself is called JPEG as well.
 * Data are normally stored in JPEG File Interchange Format (JFIF).
 *
 * Possible file suffixes are: jpeg, jpg, jpe, jfif, jif.
 *
 * Examples:
 *
 * <node name="data" channel="file" format="image/jpeg" model="path/to/file.jpeg"/>
 */
static wchar_t* JPEG_IMAGE_STATE_CYBOL_FORMAT = L"image/jpeg";
static int* JPEG_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/png state cybol format.
 *
 * Description:
 *
 * An image in Portable Network Graphics (PNG) format.
 *
 * The file suffix is png.
 *
 * Examples:
 *
 * <node name="data" channel="file" format="image/png" model="path/to/file.png"/>
 */
static wchar_t* PNG_IMAGE_STATE_CYBOL_FORMAT = L"image/png";
static int* PNG_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/tiff state cybol format.
 *
 * Tag Image File Format.
 * Common file suffixes: tiff, tif
 */
static wchar_t* TIFF_IMAGE_STATE_CYBOL_FORMAT = L"image/tiff";
static int* TIFF_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/vasa state cybol format.
 *
 * Vasa files.
 * Registered.
 * Common file suffixes: mcf
 */
static wchar_t* VASA_IMAGE_STATE_CYBOL_FORMAT = L"image/vasa";
static int* VASA_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/vnd.microsoft.icon state cybol format.
 */
static wchar_t* VND_MICROSOFT_ICON_APPLICATION_STATE_CYBOL_FORMAT = L"image/vnd.microsoft.icon";
static int* VND_MICROSOFT_ICON_APPLICATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/vnd.wap.wbmp state cybol format.
 *
 * Bitmap files (WAP).
 * Registered.
 * Common file suffixes: wbmp
 */
static wchar_t* VND_WAP_WBMP_IMAGE_STATE_CYBOL_FORMAT = L"image/vnd.wap.wbmp";
static int* VND_WAP_WBMP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-freehand state cybol format.
 *
 * Freehand files.
 * Registered.
 * Common file suffixes: fh4, fh5, fhc
 */
static wchar_t* X_FREEHAND_IMAGE_STATE_CYBOL_FORMAT = L"image/x-freehand";
static int* X_FREEHAND_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-icon state cybol format.
 *
 * Icon files (f.e. Favoriten-Icons).
 * Registered.
 * Common file suffixes: ico
 */
static wchar_t* X_ICON_IMAGE_STATE_CYBOL_FORMAT = L"image/x-icon";
static int* X_ICON_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-anymap state cybol format.
 *
 * PBM Anymap files.
 * Registered.
 * Common file suffixes: pnm
 */
static wchar_t* X_PORTABLE_ANYMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-anymap";
static int* X_PORTABLE_ANYMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-bitmap state cybol format.
 *
 * PBM Bitmap files.
 * Registered.
 * Common file suffixes: pbm
 */
static wchar_t* X_PORTABLE_BITMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-bitmap";
static int* X_PORTABLE_BITMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-graymap state cybol format.
 *
 * PBM Graymap files.
 * Registered.
 * Common file suffixes: pgm
 */
static wchar_t* X_PORTABLE_GARYMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-graymap";
static int* X_PORTABLE_GRAYMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-portable-pixmap state cybol format.
 *
 * PBM Pixmap files.
 * Registered.
 * Common file suffixes: ppm
 */
static wchar_t* X_PORTABLE_PIXMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-portable-pixmap";
static int* X_PORTABLE_PIXMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-rgb state cybol format.
 *
 * RGB files.
 * Registered.
 * Common file suffixes: rgb
 */
static wchar_t* X_RGB_IMAGE_STATE_CYBOL_FORMAT = L"image/x-rgb";
static int* X_RGB_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-windowdump state cybol format.
 *
 * X-Windows Dump.
 * Registered.
 * Common file suffixes: xwd
 */
static wchar_t* X_WINDOWDUMP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-windowdump";
static int* X_WINDOWDUMP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-xbitmap state cybol format.
 *
 * XBM files.
 * Registered.
 * Common file suffixes: xbm
 */
static wchar_t* X_XBITMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-xbitmap";
static int* X_XBITMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The image/x-xpixmap state cybol format.
 *
 * XPM files.
 * Registered.
 * Common file suffixes: xpm
 */
static wchar_t* X_XPIXMAP_IMAGE_STATE_CYBOL_FORMAT = L"image/x-xpixmap";
static int* X_XPIXMAP_IMAGE_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* IMAGE_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
