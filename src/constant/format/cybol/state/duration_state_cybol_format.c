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

#ifndef DURATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define DURATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Duration (a period in time).
//
// IANA media type: not defined
// Self-defined media type: duration
// This media type is a CYBOL extension.
//

/**
 * The duration/ddmmyyyyddmmyyyy state cybol type.
 *
 * format: ddmmyyyyddmmyyyy
 * unit: day
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT = DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/hhmmhhmm state cybol type.
 *
 * format: hhmmhhmm
 * unit: minute
 * timescale: gregorian calendar
 * begin: 1582-10-15
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'h', L'h', L'm', L'm', L'h', L'h', L'm', L'm'};
static wchar_t* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT = HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/iso state cybol type.
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
 * This is a CYBOL extension.
 */
static wchar_t ISO_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'i', L's', L'o'};
static wchar_t* ISO_DURATION_STATE_CYBOL_FORMAT = ISO_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ISO_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/jd state cybol type.
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
 * This is a CYBOL extension.
 */
static wchar_t JD_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'j', L'd'};
static wchar_t* JD_DURATION_STATE_CYBOL_FORMAT = JD_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* JD_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/julian state cybol type.
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
 * This is a CYBOL extension.
 */
static wchar_t JULIAN_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'j', L'u', L'l', L'i', L'a', L'n'};
static wchar_t* JULIAN_DURATION_STATE_CYBOL_FORMAT = JULIAN_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* JULIAN_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/si state cybol type.
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
 * This is a CYBOL extension.
 */
static wchar_t SI_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L's', L'i'};
static wchar_t* SI_DURATION_STATE_CYBOL_FORMAT = SI_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* SI_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/yyyy state cybol type.
 *
 * format: iso (defined in ISO 8601)
 * unit: year
 * timescale: gregorian calendar
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t YYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'y', L'y', L'y', L'y'};
static wchar_t* YYYY_DURATION_STATE_CYBOL_FORMAT = YYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* YYYY_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DURATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
