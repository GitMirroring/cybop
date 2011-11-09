/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: http_request_cybol_model.c,v $ $Revision: 1.4 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REQUEST_HTTP_CYBOL_MODEL_CONSTANT_SOURCE
#define REQUEST_HTTP_CYBOL_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/** The get request http cybol model. */
static wchar_t GET_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'g', L'e', L't'};
static wchar_t* GET_REQUEST_HTTP_CYBOL_MODEL = GET_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* GET_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The post request http cybol model. */
static wchar_t POST_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'p', L'o', L's', L't'};
static wchar_t* POST_REQUEST_HTTP_CYBOL_MODEL = POST_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* POST_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The head request http cybol model. */
static wchar_t HEAD_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'h', L'e', L'a', L'd'};
static wchar_t* HEAD_REQUEST_HTTP_CYBOL_MODEL = HEAD_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* HEAD_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The put request http cybol model. */
static wchar_t PUT_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'p', L'u', L't'};
static wchar_t* PUT_REQUEST_HTTP_CYBOL_MODEL = PUT_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* PUT_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The delete request http cybol model. */
static wchar_t DELETE_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'd', L'e', L'l', L'e', L't', L'e'};
static wchar_t* DELETE_REQUEST_HTTP_CYBOL_MODEL = DELETE_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* DELETE_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The trace request http cybol model. */
static wchar_t TRACE_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L't', L'r', L'a', L'c', L'e'};
static wchar_t* TRACE_REQUEST_HTTP_CYBOL_MODEL = TRACE_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* TRACE_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The options request http cybol model. */
static wchar_t OPTIONS_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'o', L'p', L't', L'i', L'o', L'n', L's'};
static wchar_t* OPTIONS_REQUEST_HTTP_CYBOL_MODEL = OPTIONS_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* OPTIONS_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The connect request http cybol model. */
static wchar_t CONNECT_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'n', L'n', L'e', L'c', L't'};
static wchar_t* CONNECT_REQUEST_HTTP_CYBOL_MODEL = CONNECT_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* CONNECT_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The propfind webdav request http cybol model. */
static wchar_t PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'p', L'r', L'o', L'p', L'f', L'i', L'n', L'd'};
static wchar_t* PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* PROPFIND_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The proppatch webdav request http cybol model. */
static wchar_t PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'p', L'r', L'o', L'p', L'p', L'a', L't', L'c', L'h'};
static wchar_t* PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* PROPPATCH_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The mkcol webdav request http cybol model. */
static wchar_t MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'm', L'k', L'c', L'o', L'l'};
static wchar_t* MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* MKCOL_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy webdav request http cybol model. */
static wchar_t COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'c', L'o', L'p', L'y'};
static wchar_t* COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* COPY_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The move webdav request http cybol model. */
static wchar_t MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'm', L'o', L'v', L'e'};
static wchar_t* MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* MOVE_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The lock webdav request http cybol model. */
static wchar_t LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'l', L'o', L'c', L'k'};
static wchar_t* LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* LOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The unlock webdav request http cybol model. */
static wchar_t UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY[] = {L'u', L'n', L'l', L'o', L'c', L'k'};
static wchar_t* UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL = UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_ARRAY;
static int* UNLOCK_WEBDAV_REQUEST_HTTP_CYBOL_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/* REQUEST_HTTP_CYBOL_MODEL_CONSTANT_SOURCE */
#endif
