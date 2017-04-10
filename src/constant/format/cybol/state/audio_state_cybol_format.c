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
 * @author Franziska Wehner>
 */

#ifndef AUDIO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define AUDIO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Audio.
//
// IANA media type: audio
//

/**
 * The audio/basic state cybol format.
 *
 * Sound files.
 * Registered.
 * Suffixes: au, snd
 */
static wchar_t* BASIC_AUDIO_STATE_CYBOL_FORMAT = L"audio/basic";
static int* BASIC_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/echospeech state cybol format.
 *
 * Echospeed files.
 * Registered.
 * Suffixes: es
 */
static wchar_t* ECHOSPEECH_AUDIO_STATE_CYBOL_FORMAT = L"audio/echospeech";
static int* ECHOSPEECH_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/mpeg state cybol format.
 *
 * MP3 or other MPEG audio.
 * Defined in RFC 3003.
 * Suffixes: mpeg
 */
static wchar_t* MPEG_AUDIO_STATE_CYBOL_FORMAT = L"audio/mpeg";
static int* MPEG_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/tsplayer state cybol format.
 *
 * TS-Player files.
 * Registered.
 * Suffixes: tsi
 */
static wchar_t* TSPLAYER_AUDIO_STATE_CYBOL_FORMAT = L"audio/tsplayer";
static int* TSPLAYER_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/vorbis state cybol format.
 */
static wchar_t* VORBIS_AUDIO_STATE_CYBOL_FORMAT = L"audio/vorbis";
static int* VORBIS_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/voxware state cybol format.
 *
 * Vox files.
 * Registered.
 * Suffixes: vox
 */
static wchar_t* VOXWARE_AUDIO_STATE_CYBOL_FORMAT = L"audio/voxware";
static int* VOXWARE_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-aiff state cybol format.
 *
 * Vox files.
 * Registered.
 * Suffixes: aif, aiff, aifc
 */
static wchar_t* X_AIFF_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-aiff";
static int* X_AIFF_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-dspeech state cybol format.
 *
 * speech files.
 * Registered.
 * Suffixes: dus, cht
 */
static wchar_t* X_DSPEECH_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-dspeech";
static int* X_DSPEECH_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-midi state cybol format.
 *
 * MIDI files.
 * Registered.
 * Suffixes: mid, midi
 */
static wchar_t* X_MIDI_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-midi";
static int* X_MIDI_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-mpeg state cybol format.
 *
 * MPEG files.
 * Registered.
 * Suffixes: mp2
 */
static wchar_t* X_MPEG_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-mpeg";
static int* X_MPEG_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-pn-realaudio state cybol format.
 *
 * RealAudio files.
 * Registered.
 * Suffixes: ram, ra
 */
static wchar_t* X_PN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-pn-realaudio";
static int* X_PN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-pn-realaudio-plugin state cybol format.
 *
 * RealAudio-Plugin files.
 * Registered.
 * Suffixes: rpm
 */
static wchar_t* X_PN_REALAUDIO_PLUGIN_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-pn-realaudio-plugin";
static int* X_PN_REALAUDIO_PLUGIN_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-qt-stream state cybol format.
 *
 * Quicktime-Streaming files.
 * Registered.
 * Suffixes: stream
 */
static wchar_t* X_QT_STREAM_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-qt-stream";
static int* X_QT_STREAM_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-wav state cybol format.
 *
 * WAV files.
 * Registered.
 * Suffixes: wav
 */
static wchar_t* X_WAV_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-wav";
static int* X_WAV_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*??
audio/x-ms-wma: Windows Media Audio; Documented in Microsoft KB 288102
audio/vnd.rn-realaudio: RealAudio; Documented in RealPlayer Customer Support Answer 2559
*/

/* AUDIO_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
