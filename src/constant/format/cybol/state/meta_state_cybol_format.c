/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Meta.
//
// The meta data contain additional information specifying a model.
//
// IANA media type: not defined
// Self-defined media type: meta
// This media type is a CYBOL extension.
//

/**
 * The meta/channel state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t CHANNEL_META_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L't', L'a', L'/', L'c', L'h', L'a', L'n', L'n', L'e', L'l'};
static wchar_t* CHANNEL_META_STATE_CYBOL_FORMAT = CHANNEL_META_STATE_CYBOL_FORMAT_ARRAY;
static int* CHANNEL_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/encoding state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t ENCODING_META_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L't', L'a', L'/', L'e', L'n', L'c', L'o', L'd', L'i', L'n', L'g'};
static wchar_t* ENCODING_META_STATE_CYBOL_FORMAT = ENCODING_META_STATE_CYBOL_FORMAT_ARRAY;
static int* ENCODING_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/language state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t LANGUAGE_META_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L't', L'a', L'/', L'l', L'a', L'n', L'g', L'u', L'a', L'g', L'e'};
static wchar_t* LANGUAGE_META_STATE_CYBOL_FORMAT = LANGUAGE_META_STATE_CYBOL_FORMAT_ARRAY;
static int* LANGUAGE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/format state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t FORMAT_META_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L't', L'a', L'/', L'f', L'o', L'r', L'm', L'a', L't'};
static wchar_t* FORMAT_META_STATE_CYBOL_FORMAT = FORMAT_META_STATE_CYBOL_FORMAT_ARRAY;
static int* FORMAT_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta/type state cybol type.
 *
 * This is a CYBOL extension.
 */
static wchar_t TYPE_META_STATE_CYBOL_FORMAT_ARRAY[] = {L'm', L'e', L't', L'a', L'/', L't', L'y', L'p', L'e'};
static wchar_t* TYPE_META_STATE_CYBOL_FORMAT = TYPE_META_STATE_CYBOL_FORMAT_ARRAY;
static int* TYPE_META_STATE_CYBOL_FORMAT_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* META_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
