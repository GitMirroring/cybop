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

#ifndef CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER
#define CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Chronology (calendar system)
//
// IANA media type: not defined
// Self-defined media type: chronology
// This media type is a CYBOL extension.
//
// See also:
// http://www.joda.org/joda-time/key_chronology.html
//

/**
 * The chronology/buddhist state cybol language.
 *
 * timescale: buddhist calendar
 */
static wchar_t* BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/buddhist";
static int* BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/coptic state cybol language.
 *
 * timescale: coptic calendar
 */
static wchar_t* COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/coptic";
static int* COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/ethiopic state cybol language.
 *
 * timescale: ethiopic calendar
 */
static wchar_t* ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/ethiopic";
static int* ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/gregorian-julian state cybol language.
 *
 * timescale: gregorian-julian cutover calendar
 */
static wchar_t* GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/gregorian-julian";
static int* GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/gregorian state cybol language.
 *
 * name en: Gregorian calendar
 * name fr: Calendrier grégorien
 * name de: Gregorianischer Kalender
 * timescale: gregorian calendar
 * begin: 1582-10-15
 * unit: day
 */
static wchar_t* GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/gregorian";
static int* GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/islamic state cybol language.
 *
 * timescale: islamic calendar
 */
static wchar_t* ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/islamic";
static int* ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/iso state cybol language.
 *
 * timescale: iso calendar
 * begin: 1582-10-15
 *
 * ISO 8601 permits using the gregorian calendar also for the time
 * before its introduction on 15th of October 1582.
 * In this proleptic gregorian calendar, there exists a year
 * zero "0000" (contrary to the julian calendar), which is a leap year.
 * Its year "–0001" corresponds to the Julian year 2 BC.
 */
static wchar_t* ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/iso";
static int* ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/jd state cybol type.
 *
 * name en: Julian date
 * name fr: Date julien
 * name de: Julianisches Datum
 * timescale: proleptic julian calendar
 * begin: January 1, 4713 B.C.
 * unit: day
 * format: double
 *
 * Continuous counting of days.
 * Fractions of a day as decimal part.
 * Used by astronomers.
 *
 * This is a CYBOL extension.
 */
static wchar_t* JD_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/jd";
static int* JD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/julian state cybol language.
 *
 * name en: Julian calendar
 * name fr: Calendrier julien
 * name de: Julianischer Kalender
 * timescale: julian calendar
 * begin: 45 B.C.
 * history: replaced by gregorian calendar on 1582-10-15 (gregorian date)
 * unit: day
 */
static wchar_t* JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/julian";
static int* JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/mjd state cybol type.
 *
 * name en: Modified Julian date
 * name fr: Date julien modifié
 * name de: Modifiziertes Julianisches Datum
 * timescale: proleptic julian calendar
 * begin: 1858-11-17T00:00:00
 * definition: JD - 2400000.5
 * unit: day
 * format: double
 *
 * Continuous counting of days since 24th May 1968 0 h UT (JD 2 440 000.5).
 * Used by astronomers.
 *
 * This is a CYBOL extension.
 */
static wchar_t* MJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/mjd";
static int* MJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/posix state cybol type.
 *
 * name: Portable Operating System Interface time
 * synonym: Unix time, Epoch time
 * timescale: gregorian calendar
 * begin: 1970-01-01T00:00, NOT counting leap seconds
 * definition: (JD - 2440587.5) * 86400
 * unit: SI-second
 * format: integer
 *
 * Continuous counting of SI-seconds, INCONSISTENTLY
 * leaving out (jumping over) leap seconds.
 * Therefore, a unix time instant is ambiguous
 * in case of a leap second, since it may stand
 * for the second before or for the leap second itself.
 *
 * This is a CYBOL extension.
 */
static wchar_t* POSIX_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/posix";
static int* POSIX_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/tai state cybol type.
 *
 * name en: International Atomic Time
 * name fr: Temps atomique international
 * name de: Internationale Atomzeit
 * timescale: tai
 * begin: 1958-01-01T00:00 TAI roughly corresponding to Universal Time (UT)
 * unit: SI-second
 * format: integer
 *
 * Continuous counting of SI-seconds.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TAI_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/tai";
static int* TAI_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/ti state cybol type.
 *
 * name en: International Time
 * name fr: Temps international
 * name de: Internationale Zeit
 * timescale: ti
 * begin: 2022-01-01T00:00 UTC
 * unit: SI-second
 * format: integer
 *
 * Continuous counting of SI-seconds.
 * Based upon "chronology/tai".
 * Will replace "chronology/utc" on 2022-01-01T00:00 UTC.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TI_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/ti";
static int* TI_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/tjd state cybol type.
 *
 * name en: Truncated Julian Date
 * name fr: Date julien tronqué
 * name de: Verkürztes Julianisches Datum
 * timescale: proleptic julian calendar
 * begin: 1858-11-17T00:00:00
 * definition: JD - 2440000.5
 * unit: day
 * format: double
 *
 * Continuous counting of days since 17th November 1858 0 h UT (JD 2 400 000.5).
 * Used by space agencies.
 *
 * This is a CYBOL extension.
 */
static wchar_t* TJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/tjd";
static int* TJD_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/utc state cybol type.
 *
 * name en: Coordinated Universal Time
 * name fr: Temps universel coordonné
 * name de: Koordinierte Weltzeit
 * timescale: gregorian calendar
 * begin: 1963
 * unit: SI-second
 * range of seconds: 0..60 due to "leap second"
 *
 * Will be replaced by "chronology/ti" on 2022-01-01T00:00 UTC.
 *
 * This is a CYBOL extension.
 */
static wchar_t* UTC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/utc";
static int* UTC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_HEADER */
#endif
