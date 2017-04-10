/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Franziska Wehner
 */

#ifndef VIDEO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define VIDEO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Video.
//
// IANA media type: video
//

/**
 * The video/avi state cybol format.
 */
static wchar_t* AVI_VIDEO_STATE_CYBOL_FORMAT = L"video/avi";
static int* AVI_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/mp4 state cybol format.
 *
 * MP4 video.
 * Defined in RFC 4337.
 * Suffixes: mp4
 */
static wchar_t* MP4_VIDEO_STATE_CYBOL_FORMAT = L"video/mp4";
static int* MP4_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/mpeg state cybol format.
 *
 * MPEG-1 videwith multiplexed audio.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: mpeg, mpg, mpe
 */
static wchar_t* MPEG_VIDEO_STATE_CYBOL_FORMAT = L"video/mpeg";
static int* MPEG_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/quicktime state cybol format.
 *
 * QuickTime video.
 * Registered.
 * Suffixes: qt, mov
 */
static wchar_t* QUICKTIME_VIDEO_STATE_CYBOL_FORMAT = L"video/quicktime";
static int* QUICKTIME_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/vnd.vivo state cybol format.
 *
 * Vivo files.
 * Registered.
 * Suffixes: viv, vivo
 */
static wchar_t* VND_VIVO_VIDEO_STATE_CYBOL_FORMAT = L"video/vnd.vivo";
static int* VND_VIVO_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/x-msvideo state cybol format.
 *
 * Microsoft AVI files.
 * Registered.
 * Suffixes: avi
 */
static wchar_t* X_MSVIDEO_VIDEO_STATE_CYBOL_FORMAT = L"video/x-msvideo";
static int* X_MSVIDEO_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/x-ms-wmv state cybol format.
 *
 * Windows Media Video.
 * Documented in Microsoft KB 288102.
 * Suffixes: wmv
 */
static wchar_t* X_MS_WMV_VIDEO_STATE_CYBOL_FORMAT = L"video/x-ms-wmv";
static int* X_MS_WMV_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The video/x-sgi-movie state cybol format.
 *
 * Movie files.
 * Registered.
 * Suffixes: movie
 */
static wchar_t* X_SGI_MOVIE_VIDEO_STATE_CYBOL_FORMAT = L"video/x-sgi-movie";
static int* X_SGI_MOVIE_VIDEO_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* VIDEO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
