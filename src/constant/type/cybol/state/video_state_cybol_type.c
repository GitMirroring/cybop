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

#ifndef VIDEO_STATE_CYBOL_TYPE_CONSTANT_SOURCE
#define VIDEO_STATE_CYBOL_TYPE_CONSTANT_SOURCE

#include <stddef.h>
#include "../../../../constant/model/memory/integer_memory_model.c"

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
 * The video/avi cybol type.
 */
static wchar_t AVI_VIDEO_STATE_CYBOL_TYPE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'a', L'v', L'i'};
static wchar_t* AVI_VIDEO_STATE_CYBOL_TYPE = AVI_VIDEO_STATE_CYBOL_TYPE_ARRAY;
static int* AVI_VIDEO_STATE_CYBOL_TYPE_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The video/mp4 cybol type.
 *
 * MP4 video.
 * Defined in RFC 4337.
 * Suffixes: mp4
 */
static wchar_t MP4_VIDEO_STATE_CYBOL_TYPE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'm', L'p', L'4'};
static wchar_t* MP4_VIDEO_STATE_CYBOL_TYPE = MP4_VIDEO_STATE_CYBOL_TYPE_ARRAY;
static int* MP4_VIDEO_STATE_CYBOL_TYPE_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The video/mpeg cybol type.
 *
 * MPEG-1 videwith multiplexed audio.
 * Defined in RFC 2045 and RFC 2046.
 * Suffixes: mpeg, mpg, mpe
 */
static wchar_t MPEG_VIDEO_STATE_CYBOL_TYPE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'm', L'p', L'e', L'g'};
static wchar_t* MPEG_VIDEO_STATE_CYBOL_TYPE = MPEG_VIDEO_STATE_CYBOL_TYPE_ARRAY;
static int* MPEG_VIDEO_STATE_CYBOL_TYPE_COUNT = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The video/quicktime cybol type.
 *
 * QuickTime video.
 * Registered.
 * Suffixes: qt, mov
 */
static wchar_t QUICKTIME_VIDEO_STATE_CYBOL_TYPE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'q', L'u', L'i', L'c', L'k', L't', L'i', L'm', L'e'};
static wchar_t* QUICKTIME_VIDEO_STATE_CYBOL_TYPE = QUICKTIME_VIDEO_STATE_CYBOL_TYPE_ARRAY;
static int* QUICKTIME_VIDEO_STATE_CYBOL_TYPE_COUNT = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/**
 * The video/x-ms-wmv cybol type.
 *
 * Windows Media Video.
 * Documented in Microsoft KB 288102.
 * Suffixes: wmv
 */
static wchar_t X_MS_WMV_VIDEO_STATE_CYBOL_TYPE_ARRAY[] = {L'v', L'i', L'd', L'e', L'o', L'/', L'x', L'-', L'm', L's', L'-', L'w', L'm', L'v'};
static wchar_t* X_MS_WMV_VIDEO_STATE_CYBOL_TYPE = X_MS_WMV_VIDEO_STATE_CYBOL_TYPE_ARRAY;
static int* X_MS_WMV_VIDEO_STATE_CYBOL_TYPE_COUNT = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/* VIDEO_STATE_CYBOL_TYPE_CONSTANT_SOURCE */
#endif
