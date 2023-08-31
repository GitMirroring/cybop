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

#ifndef DURATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define DURATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// Duration (a period in time)
//
// IANA media type: not defined
// Self-defined media type: duration
// This media type is a CYBOL extension.
//

//?? TODO: Possibly delete this later, since it is an xdt constant.
/**
 * The duration/ddmmyyyyddmmyyyy state cybol format.
 *
 * format: ddmmyyyyddmmyyyy
 * unit: day
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT = L"duration/ddmmyyyyddmmyyyy";
static int* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? TODO: Possibly delete this later, since it is an xdt constant.
/**
 * The duration/hhmmhhmm state cybol format.
 *
 * format: hhmmhhmm
 * unit: minute
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT = L"duration/hhmmhhmm";
static int* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/iso state cybol format.
 *
 * format: iso (defined in ISO 8601)
 * unit: two dates or one date and a difference
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * Identical to "datetime/utc", but based on DAYS and NOT seconds.
 *
 * It may be used together with the following datetime formats:
 * - datetime/utc
 * - datetime/gregorian
 *
 *
 */
static wchar_t* ISO_DURATION_STATE_CYBOL_FORMAT = L"duration/iso";
static int* ISO_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/jd state cybol format.
 *
 * format: double
 * unit: day
 * timescale: proleptic julian calendar
 * begin: January 1, 4713 B.C.
 *
 * Continuous counting of days.
 * Used by astronomers.
 *
 * It may be used together with the following datetime formats:
 * - datetime/jd
 * - datetime/mjd
 *
 *
 */
static wchar_t* JD_DURATION_STATE_CYBOL_FORMAT = L"duration/jd";
static int* JD_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/julian state cybol format.
 *
 * format: iso (defined in ISO 8601)
 * unit: two dates or one date and a difference
 * timescale: julian calendar
 * begin: 45 B.C.
 *
 * Replaced by gregorian calendar on 1582-10-15 (gregorian date).
 * It may be used together with the following datetime formats:
 * - datetime/julian
 *
 *
 */
static wchar_t* JULIAN_DURATION_STATE_CYBOL_FORMAT = L"duration/julian";
static int* JULIAN_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/si state cybol format.
 *
 * format: iso (defined in ISO 8601)
 * unit: SI-second
 * timescale: gregorian calendar
 *
 * It may be used together with the following datetime formats:
 * - datetime/ti
 * - datetime/tai
 * - datetime/posix
 *
 *
 */
static wchar_t* SI_DURATION_STATE_CYBOL_FORMAT = L"duration/si";
static int* SI_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//?? TODO: Possibly delete this later, since it is an xdt constant.
/**
 * The duration/yyyy state cybol format.
 *
 * format: iso (defined in ISO 8601)
 * unit: year
 * timescale: gregorian calendar
 *
 * It is used e.g. in the German xDT medical standard.
 *
 *
 */
static wchar_t* YYYY_DURATION_STATE_CYBOL_FORMAT = L"duration/yyyy";
static int* YYYY_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DURATION_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
