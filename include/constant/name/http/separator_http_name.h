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

#ifndef SEPARATOR_HTTP_NAME_CONSTANT_HEADER
#define SEPARATOR_HTTP_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

//
// CAUTION! Use Carriage Return (CR) AND Line Feed (LF) characters to break lines!
// This is defined so by the Hypertext Transfer Protocol (HTTP).
//

//
// Request response line.
//

/** The request response line element end (space) separator separator http name. */
static unsigned char* REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME = SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* REQUEST_RESPONSE_LINE_ELEMENT_END_SEPARATOR_HTTP_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The request line ("carriage return" and "line feed") separator separator http name. */
static unsigned char REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_ARRAY[] = { 0x0D, 0x0A };
static unsigned char* REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME = REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_ARRAY;
static int* REQUEST_RESPONSE_LINE_FINAL_ELEMENT_SEPARATOR_HTTP_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Header.
//

/** The header argument ("colon" and "space") separator http name. */
static unsigned char HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_ARRAY[] = { 0x3A, 0x20 };
static unsigned char* HEADER_ARGUMENT_SEPARATOR_HTTP_NAME = HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_ARRAY;
static int* HEADER_ARGUMENT_SEPARATOR_HTTP_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The header value ("semicolon" and "space") separator http name. */
static unsigned char HEADER_VALUE_SEPARATOR_HTTP_NAME_ARRAY[] = { 0x3B, 0x20 };
static unsigned char* HEADER_VALUE_SEPARATOR_HTTP_NAME = HEADER_VALUE_SEPARATOR_HTTP_NAME_ARRAY;
static int* HEADER_VALUE_SEPARATOR_HTTP_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The header value assignment ("equals sign") separator http name. */
static unsigned char* HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_NAME = EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* HEADER_VALUE_ASSIGNMENT_SEPARATOR_HTTP_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The header ("carriage return" and "line feed") separator http name. */
static unsigned char HEADER_SEPARATOR_HTTP_NAME_ARRAY[] = { 0x0D, 0x0A };
static unsigned char* HEADER_SEPARATOR_HTTP_NAME = HEADER_SEPARATOR_HTTP_NAME_ARRAY;
static int* HEADER_SEPARATOR_HTTP_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Body.
//

/**
 * The body begin (twice "carriage return" and "line feed", in other words: an empty line) separator http name.
 *
 * CAUTION! This constant has to be of type "char" and NOT "wchar_t"!
 * The reason is that cyboi parses for this separator first,
 * while the message is still all in ASCII characters,
 * before converting the complete message header into "wchar_t".
 */
static unsigned char BODY_BEGIN_SEPARATOR_HTTP_NAME_ARRAY[] = { 0x0D, 0x0A, 0x0D, 0x0A };
static unsigned char* BODY_BEGIN_SEPARATOR_HTTP_NAME = BODY_BEGIN_SEPARATOR_HTTP_NAME_ARRAY;
static int* BODY_BEGIN_SEPARATOR_HTTP_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_HTTP_NAME_CONSTANT_HEADER */
#endif
