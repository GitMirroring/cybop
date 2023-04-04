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

#ifndef AUDIO_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define AUDIO_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Audio
//
// IANA media type: audio
//

/**
 * The audio/basic state cybol format.
 *
 * Sound files.
 * Registered.
 * Common file suffixes: au, snd
 */
static wchar_t* BASIC_AUDIO_STATE_CYBOL_FORMAT = L"audio/basic";
static int* BASIC_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/echospeech state cybol format.
 *
 * Echospeed files.
 * Registered.
 * Common file suffixes: es
 */
static wchar_t* ECHOSPEECH_AUDIO_STATE_CYBOL_FORMAT = L"audio/echospeech";
static int* ECHOSPEECH_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/mpeg state cybol format.
 *
 * MP3 or other MPEG audio.
 * Defined in RFC 3003.
 * Common file suffixes: mpeg
 */
static wchar_t* MPEG_AUDIO_STATE_CYBOL_FORMAT = L"audio/mpeg";
static int* MPEG_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/tsplayer state cybol format.
 *
 * TS-Player files.
 * Registered.
 * Common file suffixes: tsi
 */
static wchar_t* TSPLAYER_AUDIO_STATE_CYBOL_FORMAT = L"audio/tsplayer";
static int* TSPLAYER_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/vnd.rn-realaudio state cybol format.
 *
 * RealAudio; Documented in RealPlayer Customer Support Answer 2559
 */
static wchar_t* VND_RN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT = L"audio/vnd.rn-realaudio";
static int* VND_RN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

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
 * Common file suffixes: vox
 */
static wchar_t* VOXWARE_AUDIO_STATE_CYBOL_FORMAT = L"audio/voxware";
static int* VOXWARE_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-aiff state cybol format.
 *
 * Vox files.
 * Registered.
 * Common file suffixes: aif, aiff, aifc
 */
static wchar_t* X_AIFF_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-aiff";
static int* X_AIFF_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-dspeech state cybol format.
 *
 * speech files.
 * Registered.
 * Common file suffixes: dus, cht
 */
static wchar_t* X_DSPEECH_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-dspeech";
static int* X_DSPEECH_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-midi state cybol format.
 *
 * MIDI files.
 * Registered.
 * Common file suffixes: mid, midi
 */
static wchar_t* X_MIDI_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-midi";
static int* X_MIDI_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-mpeg state cybol format.
 *
 * MPEG files.
 * Registered.
 * Common file suffixes: mp2
 */
static wchar_t* X_MPEG_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-mpeg";
static int* X_MPEG_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-ms-wma state cybol format.
 *
 * Windows Media Audio; Documented in Microsoft KB 288102
 */
static wchar_t* X_MS_WMA_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-ms-wma";
static int* X_MS_WMA_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-pn-realaudio state cybol format.
 *
 * RealAudio files.
 * Registered.
 * Common file suffixes: ram, ra
 */
static wchar_t* X_PN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-pn-realaudio";
static int* X_PN_REALAUDIO_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-pn-realaudio-plugin state cybol format.
 *
 * RealAudio-Plugin files.
 * Registered.
 * Common file suffixes: rpm
 */
static wchar_t* X_PN_REALAUDIO_PLUGIN_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-pn-realaudio-plugin";
static int* X_PN_REALAUDIO_PLUGIN_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-qt-stream state cybol format.
 *
 * Quicktime-Streaming files.
 * Registered.
 * Common file suffixes: stream
 */
static wchar_t* X_QT_STREAM_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-qt-stream";
static int* X_QT_STREAM_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The audio/x-wav state cybol format.
 *
 * WAV files.
 * Registered.
 * Common file suffixes: wav
 */
static wchar_t* X_WAV_AUDIO_STATE_CYBOL_FORMAT = L"audio/x-wav";
static int* X_WAV_AUDIO_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* AUDIO_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
