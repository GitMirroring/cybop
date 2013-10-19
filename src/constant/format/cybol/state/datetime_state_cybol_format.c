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

#ifndef DATETIME_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define DATETIME_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Datetime (a point in time; calendar date and time formats).
//
// IANA media type: not defined
// Self-defined media type: datetime
// This media type is a CYBOL extension.
//

/**
 * The datetime/ddmmyyyy state cybol type.
 *
 * format: ddmmyyyy
 * unit: day
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT = DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/gregorian state cybol type.
 *
 * format: iso (defined in ISO 8601)
 * unit: day
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * Identical to "datetime/utc", but based on DAYS and NOT seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t GREGORIAN_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'g', L'r', L'e', L'g', L'o', L'r', L'i', L'a', L'n'};
static wchar_t* GREGORIAN_DATETIME_STATE_CYBOL_FORMAT = GREGORIAN_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* GREGORIAN_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/jd state cybol type.
 *
 * format: double
 * unit: day
 * timescale: proleptic julian calendar
 * begin: January 1, 4713 B.C.
 *
 * Continuous counting of days.
 * Used by astronomers.
 *
 * This is a CYBOL extension.
 */
static wchar_t JD_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'j', L'd'};
static wchar_t* JD_DATETIME_STATE_CYBOL_FORMAT = JD_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* JD_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/julian state cybol type.
 *
 * format: iso (defined in ISO 8601)
 * unit: day
 * timescale: julian calendar
 * begin: 45 B.C.
 *
 * Replaced by gregorian calendar on 1582-10-15 (gregorian date).
 *
 * This is a CYBOL extension.
 */
static wchar_t JULIAN_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'j', L'u', L'l', L'i', L'a', L'n'};
static wchar_t* JULIAN_DATETIME_STATE_CYBOL_FORMAT = JULIAN_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* JULIAN_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mjd state cybol type.
 *
 * format: double
 * unit: day
 * timescale: proleptic julian calendar
 * begin: 1858-11-17T00:00:00
 * definition: JD - 2400000.5
 *
 * Continuous counting of days.
 * Used by astronomers.
 *
 * This is a CYBOL extension.
 */
static wchar_t MJD_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'm', L'j', L'd'};
static wchar_t* MJD_DATETIME_STATE_CYBOL_FORMAT = MJD_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* MJD_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mmyy state cybol type.
 *
 * format: mmyyyy
 * unit: month
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 * After conversion to the cyboi-internal format,
 * the date specifies the FIRST DAY of the given month.
 *
 * This is a CYBOL extension.
 */
static wchar_t MMYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'm', L'm', L'y', L'y'};
static wchar_t* MMYY_DATETIME_STATE_CYBOL_FORMAT = MMYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* MMYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/posix state cybol type.
 *
 * format: integer
 * unit: SI-second
 * timescale: gregorian calendar
 * begin: 1970-01-01
 *
 * Continuous counting of SI-seconds, INCONSISTENTLY
 * leaving out (jumping over) leap seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t POSIX_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'p', L'o', L's', L'i', L'x'};
static wchar_t* POSIX_DATETIME_STATE_CYBOL_FORMAT = POSIX_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* POSIX_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/qyyyy state cybol type.
 *
 * format: qyyyy
 * unit: quarter
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 * After conversion to the cyboi-internal format,
 * the date specifies the FIRST DAY of the FIRST MONTH
 * of the given quarter.
 *
 * This is a CYBOL extension.
 */
static wchar_t QYYYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'q', L'y', L'y', L'y', L'y'};
static wchar_t* QYYYY_DATETIME_STATE_CYBOL_FORMAT = QYYYY_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* QYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/tai state cybol type.
 *
 * format: integer
 * unit: SI-second
 * timescale: tai
 * begin: 1958-01-01T00:00 TAI roughly corresponding to Universal Time (UT)
 *
 * Continuous counting of SI-seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t TAI_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L't', L'a', L'i'};
static wchar_t* TAI_DATETIME_STATE_CYBOL_FORMAT = TAI_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* TAI_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/ti state cybol type.
 *
 * format: integer
 * unit: SI-second
 * timescale: ti
 * begin: 2022-01-01T00:00 UTC
 *
 * Continuous counting of SI-seconds.
 * Based upon "datetime/tai".
 * Will replace "datetime/utc" on 2022-01-01T00:00 UTC.
 *
 * This is a CYBOL extension.
 */
static wchar_t TI_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L't', L'i'};
static wchar_t* TI_DATETIME_STATE_CYBOL_FORMAT = TI_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* TI_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/utc state cybol type.
 *
 * format: iso (defined in ISO 8601)
 * unit: SI-second
 * range of seconds: 0..60 due to "leap second"
 * timescale: gregorian calendar
 * begin: 1963
 *
 * Will be replaced by "datetime/ti" on 2022-01-01T00:00 UTC.
 *
 * This is a CYBOL extension.
 */
static wchar_t UTC_DATETIME_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'a', L't', L'e', L't', L'i', L'm', L'e', L'/', L'u', L't', L'c'};
static wchar_t* UTC_DATETIME_STATE_CYBOL_FORMAT = UTC_DATETIME_STATE_CYBOL_FORMAT_ARRAY;
static int* UTC_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATETIME_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
