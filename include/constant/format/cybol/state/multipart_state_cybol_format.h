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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Franziska Wehner
 */

#ifndef MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_HEADER
#define MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_HEADER

#include <stddef.h> // wchar_t

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.h"

//
// Multipart (archives and other objects made of more than one part)
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

/* MULTIPART_STATE_CYBOL_FORMAT_CONSTANT_HEADER */
#endif
