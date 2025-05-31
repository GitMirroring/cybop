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

#ifndef ENTITY_HEADER_HTTP_NAME_CONSTANT_HEADER
#define ENTITY_HEADER_HTTP_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// The following constants are taken from the HTTP 1.1 RFC 2616 specification:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec14.html#sec14
// They are sorted alphabetically here.
//

/** The Allow entity header http name. */
static unsigned char* ALLOW_ENTITY_HEADER_HTTP_NAME = "Allow";
static int* ALLOW_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Encoding entity header http name. */
static unsigned char* CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME = "Content-Encoding";
static int* CONTENT_ENCODING_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Language entity header http name. */
static unsigned char* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME = "Content-Language";
static int* CONTENT_LANGUAGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Length entity header http name. */
static unsigned char* CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME = "Content-Length";
static int* CONTENT_LENGTH_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Location entity header http name. */
static unsigned char* CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME = "Content-Location";
static int* CONTENT_LOCATION_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-MD5 entity header http name. */
static unsigned char* CONTENT_MD5_ENTITY_HEADER_HTTP_NAME = "Content-MD5";
static int* CONTENT_MD5_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Range entity header http name. */
static unsigned char* CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME = "Content-Range";
static int* CONTENT_RANGE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Content-Type entity header http name. */
static unsigned char* CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME = "Content-Type";
static int* CONTENT_TYPE_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Expires entity header http name. */
static unsigned char* EXPIRES_ENTITY_HEADER_HTTP_NAME = "Expires";
static int* EXPIRES_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Last-Modified entity header http name. */
static unsigned char* LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME = "Last-Modified";
static int* LAST_MODIFIED_ENTITY_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ENTITY_HEADER_HTTP_NAME_CONSTANT_HEADER */
#endif
