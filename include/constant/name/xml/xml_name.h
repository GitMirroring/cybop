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
 * @author Edson Silva <edsonlead@gmail.com>
 */

#ifndef XML_NAME_CONSTANT_HEADER
#define XML_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The attribute begin xml name. */
static wchar_t* ATTRIBUTE_BEGIN_XML_NAME = L" ";
static int* ATTRIBUTE_BEGIN_XML_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The attribute value begin xml name. */
static wchar_t* ATTRIBUTE_VALUE_BEGIN_XML_NAME = L"=\"";
static int* ATTRIBUTE_VALUE_BEGIN_XML_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The attribute value end xml name. */
static wchar_t* ATTRIBUTE_VALUE_END_XML_NAME = L"\"";
static int* ATTRIBUTE_VALUE_END_XML_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The comment begin xml name. */
static wchar_t* COMMENT_BEGIN_XML_NAME = L"<!--";
static int* COMMENT_BEGIN_XML_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The comment end xml name. */
static wchar_t* COMMENT_END_XML_NAME = L"-->";
static int* COMMENT_END_XML_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The declaration begin xml name. */
static wchar_t* DECLARATION_BEGIN_XML_NAME = L"<?xml";
static int* DECLARATION_BEGIN_XML_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The declaration end xml name. */
static wchar_t* DECLARATION_END_XML_NAME = L"?>";
static int* DECLARATION_END_XML_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The definition begin xml name. */
static wchar_t* DEFINITION_BEGIN_XML_NAME = L"<!";
static int* DEFINITION_BEGIN_XML_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The definition end xml name. */
static wchar_t* DEFINITION_END_XML_NAME = L">";
static int* DEFINITION_END_XML_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty tag end xml name. */
static wchar_t* EMPTY_TAG_END_XML_NAME = L"/>";
static int* EMPTY_TAG_END_XML_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty tag space end xml name. */
static wchar_t* EMPTY_TAG_SPACE_END_XML_NAME = L" />";
static int* EMPTY_TAG_SPACE_END_XML_NAME_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The end tag begin xml name. */
static wchar_t* END_TAG_BEGIN_XML_NAME = L"</";
static int* END_TAG_BEGIN_XML_NAME_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The start tag begin xml name. */
static wchar_t* START_TAG_BEGIN_XML_NAME = L"<";
static int* START_TAG_BEGIN_XML_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tag end xml name. */
static wchar_t* TAG_END_XML_NAME = L">";
static int* TAG_END_XML_NAME_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* XML_NAME_CONSTANT_HEADER */
#endif
