/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WEBDAV_REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER
#define WEBDAV_REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The copy webdav request method http model. Copies a resource from one uri to another. */
static unsigned char* COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "COPY";
static int* COPY_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The lock webdav request method http model. Locks a resource. */
static unsigned char* LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "LOCK";
static int* LOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mkcol webdav request method http model. Creates a collection (also called directory). */
static unsigned char* MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "MKCOL";
static int* MKCOL_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move webdav request method http model. Moves a resource from one uri to another. */
static unsigned char* MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "MOVE";
static int* MOVE_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The propfind webdav request method http model. Reads properties as resources from an xml file. Retrieves the directory structure of a remote system. */
static unsigned char* PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "PROPFIND";
static int* PROPFIND_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The proppatch webdav request method http model. Changes and deletes various properties of a resource in one single atomic act. */
static unsigned char* PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "PROPPATCH";
static int* PROPPATCH_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unlock webdav request method http model. Unlocks a resource. */
static unsigned char* UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL = "UNLOCK";
static int* UNLOCK_WEBDAV_REQUEST_METHOD_HTTP_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WEBDAV_REQUEST_METHOD_HTTP_MODEL_CONSTANT_HEADER */
#endif
