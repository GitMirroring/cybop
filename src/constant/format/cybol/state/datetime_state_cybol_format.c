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
// Calendar date and time formats.
//
// IANA media type: not defined
// Self-defined media type: datetime
// This media type is a CYBOL extension.
//

/**
 * The datetime/dd.mm.yyyy state cybol type.
 *
 * It is used e.g. in Germany, Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * German de jure standard: DIN 1355-1
 *
 * This is a CYBOL extension.
 */
static wchar_t* DD_DOT_MM_DOT_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd.mm.yyyy";
static int* DD_DOT_MM_DOT_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/dd/mm/yy state cybol type.
 *
 * It is used e.g. in Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * Since the year is AMBIGUOUS, it gets interpreted
 * as being in the 20th century.
 * Example: 01/02/03 gets interpreted as 1903-02-01
 *
 * Since the "year 2000 problem", all dates since then should be
 * and are expected to be given with FOUR year digits.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DD_SLASH_MM_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd/mm/yy";
static int* DD_SLASH_MM_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/dd/mm/yyyy state cybol type.
 *
 * It is used e.g. in Europe, Russia,
 * South America, India, Africa, Australia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * This is a CYBOL extension.
 */
static wchar_t* DD_SLASH_MM_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/dd/mm/yyyy";
static int* DD_SLASH_MM_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/ddmmyyyy state cybol type.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/ddmmyyyy";
static int* DDMMYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/iso state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t* ISO_DATETIME_STATE_CYBOL_FORMAT = L"datetime/iso";
static int* ISO_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mm/dd/yy state cybol type.
 *
 * It is used e.g. in the USA, Philippines, Saudia Arabia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * Since the year is AMBIGUOUS, it gets interpreted
 * as being in the 20th century.
 * Example: 01/02/03 gets interpreted as 1903-01-02
 *
 * Since the "year 2000 problem", all dates since then should be
 * and are expected to be given with FOUR year digits.
 *
 * This is a CYBOL extension.
 */
static wchar_t* MM_SLASH_DD_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mm/dd/yy";
static int* MM_SLASH_DD_SLASH_YY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mm/dd/yyyy state cybol type.
 *
 * It is used e.g. in the USA, Philippines, Saudia Arabia.
 * https://de.wikipedia.org/wiki/Datumsformat
 *
 * This is a CYBOL extension.
 */
static wchar_t* MM_SLASH_DD_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mm/dd/yyyy";
static int* MM_SLASH_DD_SLASH_YYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/mmyy state cybol type.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t* MMYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/mmyy";
static int* MMYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The datetime/qyyyy state cybol type.
 *
 * It is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t* QYYYY_DATETIME_STATE_CYBOL_FORMAT = L"datetime/qyyyy";
static int* QYYYY_DATETIME_STATE_CYBOL_FORMAT_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DATETIME_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
