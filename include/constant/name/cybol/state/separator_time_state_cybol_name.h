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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEPARATOR_TIME_STATE_CYBOL_NAME_CONSTANT_HEADER
#define SEPARATOR_TIME_STATE_CYBOL_NAME_CONSTANT_HEADER

#include <stddef.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.h"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// The following constants were defined according to the standard:
// ISO 8601:2004
//
// Examples:
//
// hh:mm:ss     16:43:16
// hhmmss       164316
// hh:mm        16:43
// hhmm         1643
// hh           16
// hh:mm:ss,f   16:43:16,2345
//
// Examples with time zone:
//
// 2007-08-31T16:47+00:00       16:47 Uhr am 31. August 2007 in der Zeitzone UTC.
// 2007-12-24T18:21Z            18:21 Uhr am 24. Dezember 2007, ebenfalls in der Zeitzone UTC.
// 2008-02-01T09:00:22+05       9:00:22 Uhr am 1. Februar 2008, in einer Zeitzone, die UTC fünf Stunden voraus ist, beispielsweise in der in Pakistan festgelegten Zonenzeit.
// 2009-01-01T12:00:00+01:00    12:00:00 Uhr am 1. Januar 2009 in Wien (MEZ)
// 2009-06-30T18:30:00+02:00    18:30:00 Uhr am 30. Juni 2009 in Wien (MESZ – Sommerzeit)
// 2013-09-16T08:24+02:00       Beispiel einer Zeit am heutigen Tage (für Deutschland, Liechtenstein, Österreich, Schweiz u.a.)
//
// The letter "Z" may be used as abbreviation
// of the utc time zone.
//

/**
 * The time element separator date state cybol name.
 *
 * It separates time elements.
 *
 * Symbol: :
 */
static wchar_t* TIME_ELEMENT_SEPARATOR_DATE_STATE_CYBOL_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* TIME_ELEMENT_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The fraction separator date state cybol name.
 *
 * It separates the integer part of a number and decimal fraction.
 *
 * Symbol: ,
 */
static wchar_t* FRACTION_SEPARATOR_DATE_STATE_CYBOL_NAME = COMMA_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* FRACTION_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The alternative fraction separator date state cybol name.
 *
 * It separates the integer part of a number and decimal fraction.
 *
 * CAUTION! The FRACTION_SEPARATOR_DATE_STATE_CYBOL_NAME should
 * be used instead of this alternative.
 *
 * Symbol: .
 */
static wchar_t* ALTERNATIVE_FRACTION_SEPARATOR_DATE_STATE_CYBOL_NAME = FULL_STOP_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ALTERNATIVE_FRACTION_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The positive offset time zone separator date state cybol name.
 *
 * The Coordinated Universal Time (UTC) is the world time used nowadays.
 * It is identical to the West European Time (WET),
 * also still called Greenwich Mean Time (GMT).
 *
 * Time zones around the world are expressed
 * as positive or negative offsets from utc.
 *
 * A positive offset means "earlier than utc",
 * which is the time zone of a location or country
 * east of London/Great Britain/the utc time zone.
 *
 * Symbol: +
 */
static wchar_t* POSITIVE_OFFSET_TIME_ZONE_SEPARATOR_DATE_STATE_CYBOL_NAME = PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* POSITIVE_OFFSET_TIME_ZONE_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The negative offset time zone separator date state cybol name.
 *
 * The Coordinated Universal Time (UTC) is the world time used nowadays.
 * It is identical to the West European Time (WET),
 * also still called Greenwich Mean Time (GMT).
 *
 * Time zones around the world are expressed
 * as positive or negative offsets from utc.
 *
 * A negative offset means "later than utc",
 * which is the time zone of a location or country
 * west of London/Great Britain/the utc time zone.
 *
 * Symbol: -
 */
static wchar_t* NEGATIVE_OFFSET_TIME_ZONE_SEPARATOR_DATE_STATE_CYBOL_NAME = HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* NEGATIVE_OFFSET_TIME_ZONE_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_TIME_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
