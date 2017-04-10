/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 * @author Franziska Wehner
 */

#ifndef MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE
#define MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE

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
// Multipart (archives and other objects made of more than one part).
//
// IANA media type: multipart
//

/**
 * The multipart/alternative state cybol format.
 *
 * mixed multipart data.
 * Registered.
 */
static wchar_t* ALTERNATIVE_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/alternative";
static int* ALTERNATIVE_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/byteranges state cybol format.
 *
 * multipart data with Byte information.
 * Registered.
 */
static wchar_t* BYTERANGES_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/byteranges";
static int* BYTERANGES_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/digest state cybol format.
 *
 * multipart data / selection.
 * Registered.
 */
static wchar_t* DIGEST_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/digest";
static int* DIGEST_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/encrypted state cybol format.
 *
 * encrypted multipart data.
 * Registered.
 */
static wchar_t* ENCRYPTED_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/encrypted";
static int* ENCRYPTED_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/form-data state cybol format.
 *
 * multipart data from HTML form (f.e. file upload).
 * Registered.
 */
static wchar_t* FORM_DATA_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/form-data";
static int* FORM_DATA_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/mixed state cybol format.
 *
 * mixed multipart data: MIME E-mail; Defined in RFC 2045 and RFC 2046.
 * Registered.
 */
static wchar_t* MIXED_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/mixed";
static int* MIXED_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/parallel state cybol format.
 *
 * multipart data parallel.
 * Registered.
 */
static wchar_t* PARALLEL_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/parallel";
static int* PARALLEL_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/related state cybol format.
 *
 * multipart data connected.
 * Registered.
 */
static wchar_t* RELATED_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/related";
static int* RELATED_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_17_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/report state cybol format.
 *
 * multipart data / report.
 * Registered.
 */
static wchar_t* REPORT_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/report";
static int* REPORT_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/signed state cybol format.
 *
 * multipart data referred.
 * Registered.
 */
static wchar_t* SIGNED_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/signed";
static int* SIGNED_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The multipart/voice-message state cybol format.
 *
 * multipart data / voice message.
 * Registered.
 */
static wchar_t* VOICE_MESSAGE_MULTIPART_STATE_CYBOL_FORMAT = L"multipart/voice-message";
static int* VOICE_MESSAGE_MULTIPART_STATE_CYBOL_FORMAT_COUNT = NUMBER_23_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_SOURCE */
#endif
