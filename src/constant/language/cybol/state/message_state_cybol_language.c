/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
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
 * The message/binary state cybol language.
 *
 * An arbitrary binary message that does not get interpreted in any way.
 * This is a CYBOL extension.
 */
static wchar_t* BINARY_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/binary";
static int* BINARY_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_14_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/cli state cybol language.
 *
 * A command line interface message.
 * This is a CYBOL extension.
 */
static wchar_t* CLI_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/cli";
static int* CLI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/gui state cybol language.
 *
 * A graphical user interface message.
 * This is a CYBOL extension.
 */
static wchar_t* GUI_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/gui";
static int* GUI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/http-request state cybol language.
 *
 * An HTTP request message.
 * This is a CYBOL extension.
 */
static wchar_t* HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/http-request";
static int* HTTP_REQUEST_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_20_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/http-response state cybol language.
 *
 * An HTTP response message.
 * This is a CYBOL extension.
 */
static wchar_t* HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/http-response";
static int* HTTP_RESPONSE_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/news state cybol language.
 */
static wchar_t* NEWS_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/news";
static int* NEWS_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The message/tui state cybol language.
 *
 * A text user interface message.
 * This is a CYBOL extension.
 */
static wchar_t* TUI_MESSAGE_STATE_CYBOL_LANGUAGE = L"message/tui";
static int* TUI_MESSAGE_STATE_CYBOL_LANGUAGE_COUNT = NUMBER_11_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* MESSAGE_STATE_CYBOL_LANGUAGE_CONSTANT_SOURCE */
#endif
