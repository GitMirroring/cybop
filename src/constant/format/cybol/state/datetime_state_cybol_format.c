/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
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

//?? TODO: Possibly delete this later, since it is an xdt constant.
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
static wchar_t* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/ddmmyyyy";
static int* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/gregorian state cybol type.
 *
 * name en: Gregorian calendar
 * name fr: Calendrier grégorien
 * name de: Gregorianischer Kalender
 * format: iso (defined in ISO 8601)
 * unit: day
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * Identical to "datetime/utc", but based on DAYS and NOT seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t* GREGORIAN_DATETIME_STATE_CYBOL_FORMAT = L"datetime/gregorian";
static int* GREGORIAN_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/jd state cybol type.
 *
 * name en: Julian date
 * name fr: Date julien
 * name de: Julianisches Datum
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
static wchar_t* JD_DATETIME_STATE_CYBOL_FORMAT = L"datetime/jd";
static int* JD_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/julian state cybol type.
 *
 * name en: Julian calendar
 * name fr: Calendrier julien
 * name de: Julianischer Kalender
 * format: iso (defined in ISO 8601)
 * unit: day
 * timescale: julian calendar
 * begin: 45 B.C.
 *
 * Replaced by gregorian calendar on 1582-10-15 (gregorian date).
 *
 * This is a CYBOL extension.
 */
static wchar_t* JULIAN_DATETIME_STATE_CYBOL_FORMAT = L"datetime/julian";
static int* JULIAN_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mjd state cybol type.
 *
 * name en: Modified Julian date
 * name fr: Date julien modifié
 * name de: Modifiziertes Julianisches Datum
 * format: double
 * unit: day
 * timescale: proleptic julian calendar
 * begin: 1858-11-17T00:00:00
 * definition: JD - 2400000.5
 *
 * Continuous counting of days since 24th May 1968 0 h UT (JD 2 440 000.5).
 * Used by astronomers.
 *
 * This is a CYBOL extension.
 */
static wchar_t* MJD_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mjd";
static int* MJD_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? TODO: Possibly delete this later, since it is an xdt constant.
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
static wchar_t* MMYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mmyy";
static int* MMYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/posix state cybol type.
 *
 * name: Portable Operating System Interface time
 * synonym: Unix time, Epoch time
 * format: integer
 * unit: SI-second
 * timescale: gregorian calendar
 * begin: 1970-01-01T00:00, NOT counting leap seconds
 * definition: (JD - 2440587.5) * 86400
 *
 * Continuous counting of SI-seconds, INCONSISTENTLY
 * leaving out (jumping over) leap seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t* POSIX_DATETIME_STATE_CYBOL_FORMAT = L"datetime/posix";
static int* POSIX_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? TODO: Possibly delete this later, since it is an xdt constant.
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
static wchar_t* QYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/qyyyy";
static int* QYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/tai state cybol type.
 *
 * name en: International Atomic Time
 * name fr: Temps atomique international
 * name de: Internationale Atomzeit
 * format: integer
 * unit: SI-second
 * timescale: tai
 * begin: 1958-01-01T00:00 TAI roughly corresponding to Universal Time (UT)
 *
 * Continuous counting of SI-seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TAI_DATETIME_STATE_CYBOL_FORMAT = L"datetime/tai";
static int* TAI_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/ti state cybol type.
 *
 * name en: International Time
 * name fr: Temps international
 * name de: Internationale Zeit
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
static wchar_t* TI_DATETIME_STATE_CYBOL_FORMAT = L"datetime/ti";
static int* TI_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/tjd state cybol type.
 *
 * name en: Truncated Julian Date
 * name fr: Date julien tronqué
 * name de: Verkürztes Julianisches Datum
 * format: double
 * unit: day
 * timescale: proleptic julian calendar
 * begin: 1858-11-17T00:00:00
 * definition: JD - 2440000.5
 *
 * Continuous counting of days since 17th November 1858 0 h UT (JD 2 400 000.5).
 * Used by space agencies.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TJD_DATETIME_STATE_CYBOL_FORMAT = L"datetime/tjd";
static int* TJD_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/utc state cybol type.
 *
 * name en: Coordinated Universal Time
 * name fr: Temps universel coordonné
 * name de: Koordinierte Weltzeit
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
static wchar_t* UTC_DATETIME_STATE_CYBOL_FORMAT = L"datetime/utc";
static int* UTC_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATETIME_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
