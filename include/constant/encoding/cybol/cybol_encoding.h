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
 */

#ifndef CYBOL_ENCODING_CONSTANT_HEADER
#define CYBOL_ENCODING_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character encoding constants.
//

/**
 * The ascii cybol encoding.
 *
 * American Standard Code for Information Interchange (ASCII).
 */
static wchar_t* ASCII_CYBOL_ENCODING = L"ascii";
static int* ASCII_CYBOL_ENCODING_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The big-5 cybol encoding.
 *
 * Big-5 or Big5: Traditional Chinese (Taiwan, Hong Kong, Macau).
 */
static wchar_t* BIG_5_CYBOL_ENCODING = L"big-5";
static int* BIG_5_CYBOL_ENCODING_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The ebcdic cybol encoding.
 *
 * Extended Binary Coded Decimal Interchange Code (EBCDIC).
 */
static wchar_t* EBCDIC_CYBOL_ENCODING = L"ebcdic";
static int* EBCDIC_CYBOL_ENCODING_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The gb cybol encoding.
 *
 * Guobiao code (GB): Simplified Chinese (Mainland China, South East).
 */
static wchar_t* GB_CYBOL_ENCODING = L"gb";
static int* GB_CYBOL_ENCODING_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The shift-jis cybol encoding.
 *
 * Shift JIS for Japanese (Microsoft Code page 932).
 */
static wchar_t* SHIFT_JIS_CYBOL_ENCODING = L"shift-jis";
static int* SHIFT_JIS_CYBOL_ENCODING_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The unicode universal cybol encoding.
 *
 * Universal Character Set (UCS).
 *
 * Plane 0 (0000–FFFF): Basic Multilingual Plane (BMP)
 * Plane 1 (10000–1FFFF): Supplementary Multilingual Plane (SMP)
 * Plane 2 (20000–2FFFF): Supplementary Ideographic Plane (SIP)
 * Planes 3 to 13 (30000–DFFFF) not assigned
 * Plane 14 (E0000–EFFFF): Supplementary Special-purpose Plane (SSP)
 * Plane 15 (F0000–FFFFF) and Plane 16 (100000–10FFFF): Private Use Area (PUA)
 */
static wchar_t* UNIVERSAL_CYBOL_ENCODING = L"universal";
static int* UNIVERSAL_CYBOL_ENCODING_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOL_ENCODING_CONSTANT_HEADER */
#endif
