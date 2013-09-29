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
 * This format is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y', L'd', L'd', L'm', L'm', L'y', L'y', L'y', L'y'};
static wchar_t* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT = DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* DDMMYYYYDDMMYYYY_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_25_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/hhmmhhmm state cybol type.
 *
 * This format is used e.g. in the German xDT medical standard.
 *
 * This is a CYBOL extension.
 */
static wchar_t HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'h', L'h', L'm', L'm', L'h', L'h', L'm', L'm'};
static wchar_t* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT = HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* HHMMHHMM_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The duration/iso state cybol type.
 *
 * It is defined in ISO 8601.
 *
 * This is a CYBOL extension.
 */
static wchar_t ISO_DURATION_STATE_CYBOL_FORMAT_ARRAY[] = {L'd', L'u', L'r', L'a', L't', L'i', L'o', L'n', L'/', L'i', L's', L'o'};
static wchar_t* ISO_DURATION_STATE_CYBOL_FORMAT = ISO_DURATION_STATE_CYBOL_FORMAT_ARRAY;
static int* ISO_DURATION_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* DURATION_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
