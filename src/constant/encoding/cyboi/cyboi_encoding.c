/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CYBOI_ENCODING_CONSTANT_SOURCE
#define CYBOI_ENCODING_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having them here altogether.
//

//
// base
//

/** The base-64 cyboi encoding. */
static int* BASE_64_CYBOI_ENCODING = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// dos
//

/** The dos 437 cyboi encoding. */
static int* DOS_437_CYBOI_ENCODING = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dos 850 cyboi encoding. */
static int* DOS_850_CYBOI_ENCODING = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// general
//

/** The ascii cyboi encoding. */
static int* ASCII_CYBOI_ENCODING = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The big-5 cyboi encoding. */
static int* BIG_5_CYBOI_ENCODING = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ebcdic cyboi encoding. */
static int* EBCDIC_CYBOI_ENCODING = NUMBER_202_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gb cyboi encoding. */
static int* GB_CYBOI_ENCODING = NUMBER_203_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift jis cyboi encoding. */
static int* SHIFT_JIS_CYBOI_ENCODING = NUMBER_204_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The universal cyboi encoding. */
static int* UNIVERSAL_CYBOI_ENCODING = NUMBER_205_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// iso 8859
//

/** The iso-8859-1 cyboi encoding. */
static int* ISO_8859_1_CYBOI_ENCODING = NUMBER_301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-2 cyboi encoding. */
static int* ISO_8859_2_CYBOI_ENCODING = NUMBER_302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-3 cyboi encoding. */
static int* ISO_8859_3_CYBOI_ENCODING = NUMBER_303_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-4 cyboi encoding. */
static int* ISO_8859_4_CYBOI_ENCODING = NUMBER_304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-5 cyboi encoding. */
static int* ISO_8859_5_CYBOI_ENCODING = NUMBER_305_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-6 cyboi encoding. */
static int* ISO_8859_6_CYBOI_ENCODING = NUMBER_306_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-7 cyboi encoding. */
static int* ISO_8859_7_CYBOI_ENCODING = NUMBER_307_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-8 cyboi encoding. */
static int* ISO_8859_8_CYBOI_ENCODING = NUMBER_308_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-9 cyboi encoding. */
static int* ISO_8859_9_CYBOI_ENCODING = NUMBER_309_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-10 cyboi encoding. */
static int* ISO_8859_10_CYBOI_ENCODING = NUMBER_310_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-11 cyboi encoding. */
static int* ISO_8859_11_CYBOI_ENCODING = NUMBER_311_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-12 cyboi encoding. */
static int* ISO_8859_12_CYBOI_ENCODING = NUMBER_312_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-13 cyboi encoding. */
static int* ISO_8859_13_CYBOI_ENCODING = NUMBER_313_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-14 cyboi encoding. */
static int* ISO_8859_14_CYBOI_ENCODING = NUMBER_314_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-15 cyboi encoding. */
static int* ISO_8859_15_CYBOI_ENCODING = NUMBER_315_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The iso-8859-16 cyboi encoding. */
static int* ISO_8859_16_CYBOI_ENCODING = NUMBER_316_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// unicode
//

/** The cesu-8 cyboi encoding. */
static int* CESU_8_CYBOI_ENCODING = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The gb 18030 cyboi encoding. */
static int* GB18030_CYBOI_ENCODING = NUMBER_501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The punycode cyboi encoding. */
static int* PUNYCODE_CYBOI_ENCODING = NUMBER_502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf-16 cyboi encoding. */
static int* UTF_16_CYBOI_ENCODING = NUMBER_503_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf-32 cyboi encoding. */
static int* UTF_32_CYBOI_ENCODING = NUMBER_504_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf-7 cyboi encoding. */
static int* UTF_7_CYBOI_ENCODING = NUMBER_505_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf-8 cyboi encoding. */
static int* UTF_8_CYBOI_ENCODING = NUMBER_506_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf ebcdic cyboi encoding. */
static int* UTF_EBCDIC_CYBOI_ENCODING = NUMBER_507_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The utf scsu cyboi encoding. */
static int* UTF_SCSU_CYBOI_ENCODING = NUMBER_508_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// windows
//

/** The windows 874 cyboi encoding. */
static int* WINDOWS_874_CYBOI_ENCODING = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 932 cyboi encoding. */
static int* WINDOWS_932_CYBOI_ENCODING = NUMBER_601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 936 cyboi encoding. */
static int* WINDOWS_936_CYBOI_ENCODING = NUMBER_602_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 949 cyboi encoding. */
static int* WINDOWS_949_CYBOI_ENCODING = NUMBER_603_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 950 cyboi encoding. */
static int* WINDOWS_950_CYBOI_ENCODING = NUMBER_604_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1250 cyboi encoding. */
static int* WINDOWS_1250_CYBOI_ENCODING = NUMBER_605_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1251 cyboi encoding. */
static int* WINDOWS_1251_CYBOI_ENCODING = NUMBER_606_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1252 cyboi encoding. */
static int* WINDOWS_1252_CYBOI_ENCODING = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1253 cyboi encoding. */
static int* WINDOWS_1253_CYBOI_ENCODING = NUMBER_608_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1254 cyboi encoding. */
static int* WINDOWS_1254_CYBOI_ENCODING = NUMBER_609_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1255 cyboi encoding. */
static int* WINDOWS_1255_CYBOI_ENCODING = NUMBER_610_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1256 cyboi encoding. */
static int* WINDOWS_1256_CYBOI_ENCODING = NUMBER_611_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1257 cyboi encoding. */
static int* WINDOWS_1257_CYBOI_ENCODING = NUMBER_612_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The windows 1258 cyboi encoding. */
static int* WINDOWS_1258_CYBOI_ENCODING = NUMBER_613_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CYBOI_ENCODING_CONSTANT_SOURCE */
#endif
