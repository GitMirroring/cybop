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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef TAG_HTML_MODEL_CONSTANT_HEADER
#define TAG_HTML_MODEL_CONSTANT_HEADER

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// These constants represent empty (void) elements,
// following the html specification.
//

/**
 * The area tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* AREA_TAG_HTML_MODEL = L"area";
static int* AREA_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The base tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* BASE_TAG_HTML_MODEL = L"base";
static int* BASE_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The br tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* BR_TAG_HTML_MODEL = L"br";
static int* BR_TAG_HTML_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The col tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* COL_TAG_HTML_MODEL = L"col";
static int* COL_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* COMMAND_TAG_HTML_MODEL = L"command";
static int* COMMAND_TAG_HTML_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The embed tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* EMBED_TAG_HTML_MODEL = L"embed";
static int* EMBED_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hr tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* HR_TAG_HTML_MODEL = L"hr";
static int* HR_TAG_HTML_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The img tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* IMG_TAG_HTML_MODEL = L"img";
static int* IMG_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The input tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* INPUT_TAG_HTML_MODEL = L"input";
static int* INPUT_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The keygen tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* KEYGEN_TAG_HTML_MODEL = L"keygen";
static int* KEYGEN_TAG_HTML_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The link tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* LINK_TAG_HTML_MODEL = L"link";
static int* LINK_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* META_TAG_HTML_MODEL = L"meta";
static int* META_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The param tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* PARAM_TAG_HTML_MODEL = L"param";
static int* PARAM_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pre tag html model.
 *
 * The pre element represents a block of preformatted text,
 * in which structure is represented by typographic conventions
 * rather than by elements.
 */
static wchar_t* PRE_TAG_HTML_MODEL = L"pre";
static int* PRE_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The source tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* SOURCE_TAG_HTML_MODEL = L"source";
static int* SOURCE_TAG_HTML_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The track tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* TRACK_TAG_HTML_MODEL = L"track";
static int* TRACK_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wbr tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t* WBR_TAG_HTML_MODEL = L"wbr";
static int* WBR_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAG_HTML_MODEL_CONSTANT_HEADER */
#endif
