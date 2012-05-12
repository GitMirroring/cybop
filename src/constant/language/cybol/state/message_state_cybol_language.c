/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE
#define MESSAGE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE

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
// Message.
//
// IANA media type: message
//

/**
 * The message/ansi-escape-code cybol language.
 */
static wchar_t ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'a', L'n', L's', L'i', L'-', L'e', L's', L'c', L'a', L'p', L'e', L'-', L'c', L'o', L'd', L'e'};
static wchar_t* ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOL_LANGUAGE = ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* ANSI_ESCAPE_CODE_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_24_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/http cybol language.
 *
 * An HTTP header message.
 */
static wchar_t HTTP_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p'};
static wchar_t* HTTP_MESSAGE_STATE_CYBOL_LANGUAGE = HTTP_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* HTTP_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/http-request cybol language.
 *
 * An HTTP request message.
 * This is a CYBOL extension.
 */
static wchar_t HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p', L'-', L'r', L'e', L'q', L'u', L'e', L's', L't'};
static wchar_t* HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE = HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/http-response cybol language.
 *
 * An HTTP response message.
 * This is a CYBOL extension.
 */
static wchar_t HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'h', L't', L't', L'p', L'-', L'r', L'e', L's', L'p', L'o', L'n', L's', L'e'};
static wchar_t* HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE = HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/news cybol language.
 */
static wchar_t NEWS_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY[] = {L'm', L'e', L's', L's', L'a', L'g', L'e', L'/', L'n', L'e', L'w', L's'};
static wchar_t* NEWS_MESSAGE_STATE_CYBOL_LANGUAGE = NEWS_MESSAGE_STATE_CYBOL_LANGUAGE_ARRAY;
static int* NEWS_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MESSAGE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
