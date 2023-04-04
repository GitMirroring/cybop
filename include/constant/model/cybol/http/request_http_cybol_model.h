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

#ifndef REQUEST_HTTP_CYBOL_MODEL_CONSTANT_HEADER
#define REQUEST_HTTP_CYBOL_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The get request http cybol model. */
static wchar_t* GET_REQUEST_HTTP_CYBOL_MODEL = L"get";
static int* GET_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The post request http cybol model. */
static wchar_t* POST_REQUEST_HTTP_CYBOL_MODEL = L"post";
static int* POST_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The head request http cybol model. */
static wchar_t* HEAD_REQUEST_HTTP_CYBOL_MODEL = L"head";
static int* HEAD_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The put request http cybol model. */
static wchar_t* PUT_REQUEST_HTTP_CYBOL_MODEL = L"put";
static int* PUT_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The delete request http cybol model. */
static wchar_t* DELETE_REQUEST_HTTP_CYBOL_MODEL = L"delete";
static int* DELETE_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The trace request http cybol model. */
static wchar_t* TRACE_REQUEST_HTTP_CYBOL_MODEL = L"trace";
static int* TRACE_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The options request http cybol model. */
static wchar_t* OPTIONS_REQUEST_HTTP_CYBOL_MODEL = L"options";
static int* OPTIONS_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The connect request http cybol model. */
static wchar_t* CONNECT_REQUEST_HTTP_CYBOL_MODEL = L"connect";
static int* CONNECT_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The propfind webdav request http cybol model. */
static wchar_t* PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"propfind";
static int* PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The proppatch webdav request http cybol model. */
static wchar_t* PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"proppatch";
static int* PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The mkcol webdav request http cybol model. */
static wchar_t* MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"mkcol";
static int* MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy webdav request http cybol model. */
static wchar_t* COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"copy";
static int* COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move webdav request http cybol model. */
static wchar_t* MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"move";
static int* MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The lock webdav request http cybol model. */
static wchar_t* LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"lock";
static int* LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unlock webdav request http cybol model. */
static wchar_t* UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = L"unlock";
static int* UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* REQUEST_HTTP_CYBOL_MODEL_CONSTANT_HEADER */
#endif
