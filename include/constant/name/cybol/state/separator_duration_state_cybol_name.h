/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_HEADER
#define SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// The following constants were defined according to the standard:
// ISO 8601:2004
//
// Examples:
//
// 2005-08-09T18:31:42P3Y6M4DT12H30M17S bestimmt eine Zeitspanne von 3 Jahren, 6 Monaten, 4 Tagen 12 Stunden, 30 Minuten und 17 Sekunden ab dem 9. August 2005 "kurz nach halb sieben Abends"
// P3Y6M4DT12H30M17S                    die gleiche Zeitspanne wie das erste Beispiel, allerdings ohne ein bestimmtes Startdatum zu definieren
// P1D                                  "Bis morgen zur jetzigen Uhrzeit."
// PT24H                                "Bis in 24 Stunden ab jetzt.", was im Falle einer Zeitumstellung vom vorherigen Beispiel abweicht
// 2005-08-09P14W                       "Die 14 Wochen beginnend ab dem 9. August 2005."
// 2005-08-09/2005-08-30                "Vom 9. zum 30. August 2005"
// 2005-08-09--2005-08-30               "Vom 9. zum 30. August 2005"
// 2005-08-09/30                        "Vom 9. bis 30. August 2005."
//

/**
 * The year separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of years.
 *
 * Symbol: Y
 */
static wchar_t* YEAR_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_Y_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* YEAR_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The month separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of months.
 *
 * Symbol: M
 */
static wchar_t* MONTH_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_M_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* MONTH_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The week separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of weeks.
 *
 * Symbol: W
 */
static wchar_t* WEEK_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_W_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* WEEK_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The day separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of days.
 *
 * Symbol: D
 */
static wchar_t* DAY_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_D_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* DAY_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The time separator duration state cybol name.
 *
 * It is the designator that precedes the
 * time components of the representation.
 *
 * Symbol: T
 */
static wchar_t* TIME_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_T_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* TIME_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hour separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of hours.
 *
 * Symbol: H
 */
static wchar_t* HOUR_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* HOUR_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The minute separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of minutes.
 *
 * Symbol: M
 */
static wchar_t* MINUTE_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_M_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* MINUTE_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The second separator duration state cybol name.
 *
 * It is the designator that follows the value
 * for the number of seconds.
 *
 * Symbol: S
 */
static wchar_t* SECOND_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_S_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SECOND_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fraction separator duration state cybol name.
 *
 * It is the designator that precedes the
 * decimal fraction of a second.
 *
 * Symbol: F
 */
static wchar_t* FRACTION_SEPARATOR_DURATION_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_F_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* FRACTION_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The start-end separator duration state cybol name.
 *
 * It separates a start- and an end date
 * and has the meaning of "to".
 *
 * Symbol: /
 */
static wchar_t* START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alternative start-end separator duration state cybol name.
 *
 * It separates a start- and an end date
 * and has the meaning of "to".
 *
 * CAUTION! The START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME should
 * be used instead of this alternative.
 *
 * Symbol: --
 */
static wchar_t ALTERNATIVE_START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME_ARRAY[] = { 0x002D, 0x002D };
static wchar_t* ALTERNATIVE_START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME = ALTERNATIVE_START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME_ARRAY;
static int* ALTERNATIVE_START_END_SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
