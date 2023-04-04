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

#ifndef HTTP_REQUEST_URI_NAME_CONSTANT_HEADER
#define HTTP_REQUEST_URI_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The no resource (asterisk) http request uri name. */
static wchar_t* NO_RESOURCE_HTTP_REQUEST_URI_NAME = ASTERISK_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* NO_RESOURCE_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The absolute uri (colon, solidus, solidus) http request uri name. */
static wchar_t ABSOLUTE_URI_HTTP_REQUEST_URI_NAME_ARRAY[] = { 0x003A, 0x002F, 0x002F };
static wchar_t* ABSOLUTE_URI_HTTP_REQUEST_URI_NAME = ABSOLUTE_URI_HTTP_REQUEST_URI_NAME_ARRAY;
static int* ABSOLUTE_URI_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The authority form (colon) http request uri name.
 *
 * The sequence (solidus, solidus) is NOT used for detection,
 * since an authority in an http request uri always has to be
 * specified TOGETHER with a port number, separated by a colon.
 * Therefore, the colon in host:port is looked for.
 *
 * The fact that an absolute uri contains a colon behind the scheme
 * is not a problem, since the absolute uri detection is done ABOVE.
 * That is, the authority form detection is done ONLY if the uri
 * is NOT an absolute uri.
 */
static wchar_t* AUTHORITY_FORM_HTTP_REQUEST_URI_NAME = COLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* AUTHORITY_FORM_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The absolute path (solidus) http request uri name. */
static wchar_t* ABSOLUTE_PATH_HTTP_REQUEST_URI_NAME = SOLIDUS_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ABSOLUTE_PATH_HTTP_REQUEST_URI_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* HTTP_REQUEST_URI_NAME_CONSTANT_HEADER */
#endif
