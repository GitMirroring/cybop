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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef RESPONSE_HEADER_HTTP_NAME_CONSTANT_HEADER
#define RESPONSE_HEADER_HTTP_NAME_CONSTANT_HEADER

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

/** The Accept-Ranges response header http name. */
static unsigned char* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME = "Accept-Ranges";
static int* ACCEPT_RANGES_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_13_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Age response header http name. */
static unsigned char* AGE_RESPONSE_HEADER_HTTP_NAME = "Age";
static int* AGE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ETag response header http name. */
static unsigned char* ETAG_RESPONSE_HEADER_HTTP_NAME = "ETag";
static int* ETAG_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Location response header http name. */
static unsigned char* LOCATION_RESPONSE_HEADER_HTTP_NAME = "Location";
static int* LOCATION_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Proxy-Authenticate response header http name. */
static unsigned char* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = "Proxy-Authenticate";
static int* PROXY_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_18_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Retry-After response header http name. */
static unsigned char* RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME = "Retry-After";
static int* RETRY_AFTER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Server response header http name. */
static unsigned char* SERVER_RESPONSE_HEADER_HTTP_NAME = "Server";
static int* SERVER_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The WWW-Authenticate response header http name. */
static unsigned char* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME = "WWW-Authenticate";
static int* WWW_AUTHENTICATE_RESPONSE_HEADER_HTTP_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* RESPONSE_HEADER_HTTP_NAME_CONSTANT_HEADER */
#endif
