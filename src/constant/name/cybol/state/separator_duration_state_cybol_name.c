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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_SOURCE
#define SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// The following constants were defined according to the standard:
// ISO 8601:2004
// 
// Examples:
// 
// 2005-08-09T18:31:42P3Y6M4DT12H30M17S: bestimmt eine Zeitspanne von 3 Jahren, 6 Monaten, 4 Tagen 12 Stunden, 30 Minuten und 17 Sekunden ab dem 9. August 2005 "kurz nach halb sieben Abends"
// P3Y6M4DT12H30M17S: die gleiche Zeitspanne wie das erste Beispiel, allerdings ohne ein bestimmtes Startdatum zu definieren
// P1D: "Bis morgen zur jetzigen Uhrzeit."
// PT24H: "Bis in 24 Stunden ab jetzt.", was im Falle einer Zeitumstellung vom vorherigen Beispiel abweicht
// 2005-08-09P14W: "Die 14 Wochen beginnend ab dem 9. August 2005."
// 2005-08-09/2005-08-30: "Vom 9. zum 30. August 2005"
// 2005-08-09--2005-08-30: "Vom 9. zum 30. August 2005"
// 2005-08-09/30: "Vom 9. bis 30. August 2005."
//

/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

Y is the year designator that follows the value for the number of years.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

M is the month designator that follows the value for the number of months.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

W is the week designator that follows the value for the number of weeks.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

D is the day designator that follows the value for the number of days.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

T is the time designator that precedes the time components of the representation.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

H is the hour designator that follows the value for the number of hours.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

M is the minute designator that follows the value for the number of minutes.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

S is the second designator that follows the value for the number of seconds.
/** The separator duration state cybol name. */
static wchar_t* SEPARATOR_DURATION_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* SEPARATOR_DURATION_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

--

Y
    Jahr (year)
M 
    Monat (month)
W 
    Woche (week)
D 
    Tag (day)
h 
    Stunde (hour)
m 
    Minute (minute)
s 
    Sekunde (second)
f 
    dezimale Bruchteile einer Sekunde (fraction)
/ 
    Trenner von Start- und Enddatum (bis)

/* SEPARATOR_DURATION_STATE_CYBOL_NAME_CONSTANT_SOURCE */
#endif
