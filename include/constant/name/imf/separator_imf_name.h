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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef SEPARATOR_IMF_NAME_CONSTANT_HEADER
#define SEPARATOR_IMF_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The name field header separator ("colon" and "space") imf name. */
static unsigned char NAME_FIELD_HEADER_SEPARATOR_IMF_NAME_ARRAY[] = { 0x3A, 0x20 };
static unsigned char* NAME_FIELD_HEADER_SEPARATOR_IMF_NAME = NAME_FIELD_HEADER_SEPARATOR_IMF_NAME_ARRAY;
static int* NAME_FIELD_HEADER_SEPARATOR_IMF_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The body field header separator ("carriage return" and "line feed") imf name. */
static unsigned char BODY_FIELD_HEADER_SEPARATOR_IMF_NAME_ARRAY[] = { 0x0D, 0x0A };
static unsigned char* BODY_FIELD_HEADER_SEPARATOR_IMF_NAME = BODY_FIELD_HEADER_SEPARATOR_IMF_NAME_ARRAY;
static int* BODY_FIELD_HEADER_SEPARATOR_IMF_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The section header separator (twice "carriage return" and "line feed", in other words: an empty line) imf name.
 *
 * CAUTION! This constant has to be of type "char" and NOT "wchar_t"!
 * The reason is that cyboi parses for this separator first,
 * while the message is still all in ASCII characters,
 * before converting the complete message header into "wchar_t".
 */
static unsigned char SECTION_HEADER_SEPARATOR_IMF_NAME_ARRAY[] = { 0x0D, 0x0A, 0x0D, 0x0A };
static unsigned char* SECTION_HEADER_SEPARATOR_IMF_NAME = SECTION_HEADER_SEPARATOR_IMF_NAME_ARRAY;
static int* SECTION_HEADER_SEPARATOR_IMF_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* SEPARATOR_IMF_NAME_CONSTANT_HEADER */
#endif
