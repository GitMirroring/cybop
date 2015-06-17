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

#ifndef CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

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
// Chronology (calendar system).
//
// IANA media type: --
//
// See also:
// http://www.joda.org/joda-time/key_chronology.html
//

/**
 * The chronology/buddhist state cybol language.
 *
 * Buddhist calendar.
 */
static wchar_t* BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/buddhist";
static int* BUDDHIST_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/coptic state cybol language.
 *
 * Coptic calendar.
 */
static wchar_t* COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/coptic";
static int* COPTIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/ethiopic state cybol language.
 *
 * Ethiopic calendar.
 */
static wchar_t* ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/ethiopic";
static int* ETHIOPIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/gregorian-julian state cybol language.
 *
 * Gregorian-Julian cutover calendar.
 */
static wchar_t* GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/gregorian-julian";
static int* GREGORIAN_JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_27_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/gregorian state cybol language.
 *
 * Gregorian calendar.
 */
static wchar_t* GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/gregorian";
static int* GREGORIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/islamic state cybol language.
 *
 * Islamic calendar.
 */
static wchar_t* ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/islamic";
static int* ISLAMIC_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/iso state cybol language.
 *
 * ISO calendar.
 */
static wchar_t* ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/iso";
static int* ISO_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The chronology/julian state cybol language.
 *
 * Julian calendar.
 */
static wchar_t* JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE = L"chronology/julian";
static int* JULIAN_CHRONOLOGY_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* CHRONOLOGY_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
