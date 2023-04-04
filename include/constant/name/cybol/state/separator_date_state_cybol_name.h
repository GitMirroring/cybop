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

#ifndef SEPARATOR_DATE_STATE_CYBOL_NAME_CONSTANT_HEADER
#define SEPARATOR_DATE_STATE_CYBOL_NAME_CONSTANT_HEADER

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
// CAUTION! ISO 8601:2000 allowed truncation (by agreement),
// where leading components of a date or time are omitted.
// Notably, this allowed two-digit years to be used and
// the ambiguous formats YY-MM-DD and YYMMDD.
// This provision was removed in ISO 8601:2004.
//
// Examples:
//
// YYYY-MM-DD   2004-07-11
// YYYYMMDD     20040711
// YY-MM-DD     04-07-11
// YYMMDD       040711
// YYYY-MM      2004-07
// YYYY         2004
// YYYY-Www     2004-W28
// YYYYWww      2004W28
// YYYY-Www-D   2004-W28-7
// YYYYWwwD     2004W287
// YY-Www       04-W28
// YYWww        04W28
// YY-Www-D     04-W28-7
// YYWwwD       04W287
// YYYY-DDD     2004-193
// YYYYDDD      2004193
//
// Examples with negative values:
//
// -YYYY-MM-DD  -0333-07-11
// -YYYYMMDD    -03330711
// -YY-MM-DD    -33-07-11
// -YYMMDD      -330711
// -YYYY-MM     -0333-07
// -YYYY        -0333
// -YYYY-Www    -0333-W28
// -YYYYWww     -0333W28
// -YYYY-Www-D  -0333-W28-7
// -YYYYWwwD    -0333W287
// -YY-Www      -33-W28
// -YYWww       -33W28
// -YY-Www-D    -33-W28-7
// -YYWwwD      -33W287
// -YYYY-DDD    -0333-193
// -YYYYDDD     -0333193
//

/**
 * The ce separator date state cybol name.
 *
 * It indicates that a date lies after (or "in") an epoch (era).
 *
 * CE is the abbreviation for Common/Current/Christian Era.
 * It is an alternative naming of the traditional
 * calendar era Anno Domini, abbreviated AD.
 *
 * "2013 CE" corresponds to "AD 2013"
 *
 * Symbol: +
 */
static wchar_t* CE_SEPARATOR_DATE_STATE_CYBOL_NAME = PLUS_SIGN_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* CE_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The bce separator date state cybol name.
 *
 * It indicates that a date lies before an epoch (era).
 *
 * BCE is the abbreviation for Before the Common/Current/Christian Era.
 * It is an alternative naming of the traditional
 * calendar era Before Christ, abbreviated BC.
 *
 * "399 BCE" corresponds to "399 BC"
 *
 * Symbol: -
 */
static wchar_t* BCE_SEPARATOR_DATE_STATE_CYBOL_NAME = HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* BCE_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The date element separator date state cybol name.
 *
 * It separates date elements.
 *
 * Symbol: -
 */
static wchar_t* DATE_ELEMENT_SEPARATOR_DATE_STATE_CYBOL_NAME = HYPHEN_MINUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* DATE_ELEMENT_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The week separator date state cybol name.
 *
 * It indicates that a week value is following.
 *
 * Symbol: W
 */
static wchar_t* WEEK_SEPARATOR_DATE_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_W_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* WEEK_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The time separator date state cybol name.
 *
 * It separates date and time.
 *
 * Symbol: T
 */
static wchar_t* TIME_SEPARATOR_DATE_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_T_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* TIME_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration separator date state cybol name.
 *
 * Symbol: P
 *
 * It is placed at the start of the duration representation
 * and may thus separate a date and duration.
 * The duration designator is historically called "period".
 */
static wchar_t* DURATION_SEPARATOR_DATE_STATE_CYBOL_NAME = LATIN_CAPITAL_LETTER_P_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* DURATION_SEPARATOR_DATE_STATE_CYBOL_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_DATE_STATE_CYBOL_NAME_CONSTANT_HEADER */
#endif
