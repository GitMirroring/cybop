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
 */

#ifndef DATETIME_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define DATETIME_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Calendar date and time formats
//
// IANA media type: not defined
// Self-defined media type: datetime
// This media type is a CYBOL extension.
//

/**
 * The datetime/ascension state cybol format.
 *
 * name de: Christi Himmelfahrt
 *
 *
 */
static wchar_t* ASCENSION_DATETIME_STATE_CYBOL_FORMAT = L"datetime/ascension";
static int* ASCENSION_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/day-of-month state cybol format.
 *
 *
 */
static wchar_t* DAY_OF_MONTH_DATETIME_STATE_CYBOL_FORMAT = L"datetime/day-of-month";
static int* DAY_OF_MONTH_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/day-of-week state cybol format.
 *
 *
 */
static wchar_t* DAY_OF_WEEK_DATETIME_STATE_CYBOL_FORMAT = L"datetime/day-of-week";
static int* DAY_OF_WEEK_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/day-of-year state cybol format.
 *
 *
 */
static wchar_t* DAY_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT = L"datetime/day-of-year";
static int* DAY_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/dd.mm.yyyy state cybol format.
 *
 * It is used e.g. in Germany, Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * German de jure standard: DIN 1355-1
 *
 *
 */
static wchar_t* DD_DOT_MM_DOT_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd.mm.yyyy";
static int* DD_DOT_MM_DOT_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/dd/mm/yy state cybol format.
 *
 * It is used e.g. in Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * Since the year is AMBIGUOUS, it gets interpreted
 * as being in the 20th century.
 * Example: 01/02/03 gets interpreted as 1903-02-01
 *
 * Since the "year 2000 problem", all dates since then should be
 * and are expected to be given with FOUR year digits.
 *
 *
 */
static wchar_t* DD_SLASH_MM_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd/mm/yy";
static int* DD_SLASH_MM_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/dd/mm/yyyy state cybol format.
 *
 * It is used e.g. in Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 *
 */
static wchar_t* DD_SLASH_MM_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd/mm/yyyy";
static int* DD_SLASH_MM_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/ddmmyyyy state cybol format.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/ddmmyyyy";
static int* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/easter-monday state cybol format.
 *
 * name de: Ostermontag
 *
 *
 */
static wchar_t* EASTER_MONDAY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/easter-monday";
static int* EASTER_MONDAY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/easter-sunday state cybol format.
 *
 * name de: Ostersonntag
 *
 *
 */
static wchar_t* EASTER_SUNDAY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/easter-sunday";
static int* EASTER_SUNDAY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/iso state cybol format.
 *
 *
 */
static wchar_t* ISO_DATETIME_STATE_CYBOL_FORMAT = L"datetime/iso";
static int* ISO_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mm/dd/yy state cybol format.
 *
 * It is used e.g. in the USA, Philippines, Saudia Arabia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * Since the year is AMBIGUOUS, it gets interpreted
 * as being in the 20th century.
 * Example: 01/02/03 gets interpreted as 1903-01-02
 *
 * Since the "year 2000 problem", all dates since then should be
 * and are expected to be given with FOUR year digits.
 *
 *
 */
static wchar_t* MM_SLASH_DD_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mm/dd/yy";
static int* MM_SLASH_DD_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mm/dd/yyyy state cybol format.
 *
 * It is used e.g. in the USA, Philippines, Saudia Arabia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 *
 */
static wchar_t* MM_SLASH_DD_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mm/dd/yyyy";
static int* MM_SLASH_DD_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mmyy state cybol format.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* MMYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mmyy";
static int* MMYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/month-of-year state cybol format.
 *
 *
 */
static wchar_t* MONTH_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT = L"datetime/month-of-year";
static int* MONTH_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/qyyyy state cybol format.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* QYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/qyyyy";
static int* QYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/week-of-month state cybol format.
 *
 *
 */
static wchar_t* WEEK_OF_MONTH_DATETIME_STATE_CYBOL_FORMAT = L"datetime/week-of-month";
static int* WEEK_OF_MONTH_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_22_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/week-of-year state cybol format.
 *
 *
 */
static wchar_t* WEEK_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT = L"datetime/week-of-year";
static int* WEEK_OF_YEAR_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATETIME_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
