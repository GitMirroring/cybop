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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WINDOWS_CYBOL_ENCODING_CONSTANT_SOURCE
#define WINDOWS_CYBOL_ENCODING_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains character encoding constants.
//

/*
 * The windows-874 cybol encoding.
 *
 * Windows-874 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_874_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'8', L'7', L'4'};
static wchar_t* WINDOWS_874_CYBOL_ENCODING = WINDOWS_874_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_874_CYBOL_ENCODING_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-932 cybol encoding.
 *
 * Windows-932 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_932_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'9', L'3', L'2'};
static wchar_t* WINDOWS_932_CYBOL_ENCODING = WINDOWS_932_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_932_CYBOL_ENCODING_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-936 cybol encoding.
 *
 * Windows-936 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_936_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'9', L'3', L'6'};
static wchar_t* WINDOWS_936_CYBOL_ENCODING = WINDOWS_936_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_936_CYBOL_ENCODING_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-949 cybol encoding.
 *
 * Windows-949 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_949_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'9', L'4', L'9'};
static wchar_t* WINDOWS_949_CYBOL_ENCODING = WINDOWS_949_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_949_CYBOL_ENCODING_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-950 cybol encoding.
 *
 * Windows-950 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_950_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'9', L'5', L'0'};
static wchar_t* WINDOWS_950_CYBOL_ENCODING = WINDOWS_950_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_950_CYBOL_ENCODING_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1250 cybol encoding.
 *
 * Windows-1250 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1250_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'0'};
static wchar_t* WINDOWS_1250_CYBOL_ENCODING = WINDOWS_1250_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1250_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1251 cybol encoding.
 *
 * Windows-1251 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1251_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'1'};
static wchar_t* WINDOWS_1251_CYBOL_ENCODING = WINDOWS_1251_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1251_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1252 cybol encoding.
 *
 * Windows-1252 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1252_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'2'};
static wchar_t* WINDOWS_1252_CYBOL_ENCODING = WINDOWS_1252_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1252_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1253 cybol encoding.
 *
 * Windows-1253 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1253_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'3'};
static wchar_t* WINDOWS_1253_CYBOL_ENCODING = WINDOWS_1253_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1253_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1254 cybol encoding.
 *
 * Windows-1254 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1254_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'4'};
static wchar_t* WINDOWS_1254_CYBOL_ENCODING = WINDOWS_1254_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1254_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1255 cybol encoding.
 *
 * Windows-1255 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1255_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'5'};
static wchar_t* WINDOWS_1255_CYBOL_ENCODING = WINDOWS_1255_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1255_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1256 cybol encoding.
 *
 * Windows-1256 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1256_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'6'};
static wchar_t* WINDOWS_1256_CYBOL_ENCODING = WINDOWS_1256_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1256_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1257 cybol encoding.
 *
 * Windows-1257 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1257_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'7'};
static wchar_t* WINDOWS_1257_CYBOL_ENCODING = WINDOWS_1257_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1257_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/*
 * The windows-1258 cybol encoding.
 *
 * Windows-1258 for Central European languages that use Latin script.
 */
static wchar_t WINDOWS_1258_CYBOL_ENCODING_ARRAY[] = {L'w', L'i', L'n', L'd', L'o', L'w', L's', L'-', L'1', L'2', L'5', L'8'};
static wchar_t* WINDOWS_1258_CYBOL_ENCODING = WINDOWS_1258_CYBOL_ENCODING_ARRAY;
static int* WINDOWS_1258_CYBOL_ENCODING_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WINDOWS_CYBOL_ENCODING_CONSTANT_SOURCE */
#endif
