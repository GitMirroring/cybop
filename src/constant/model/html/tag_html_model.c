/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TAG_HTML_MODEL_CONSTANT_SOURCE
#define TAG_HTML_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The area tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t AREA_TAG_HTML_MODEL_ARRAY[] = {L'a', L'r', L'e', L'a'};
static wchar_t* AREA_TAG_HTML_MODEL = AREA_TAG_HTML_MODEL_ARRAY;
static int* AREA_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The base tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t BASE_TAG_HTML_MODEL_ARRAY[] = {L'b', L'a', L's', L'e'};
static wchar_t* BASE_TAG_HTML_MODEL = BASE_TAG_HTML_MODEL_ARRAY;
static int* BASE_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The br tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t BR_TAG_HTML_MODEL_ARRAY[] = {L'b', L'r'};
static wchar_t* BR_TAG_HTML_MODEL = BR_TAG_HTML_MODEL_ARRAY;
static int* BR_TAG_HTML_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The col tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t COL_TAG_HTML_MODEL_ARRAY[] = {L'c', L'o', L'l'};
static wchar_t* COL_TAG_HTML_MODEL = COL_TAG_HTML_MODEL_ARRAY;
static int* COL_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The command tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t COMMAND_TAG_HTML_MODEL_ARRAY[] = {L'c', L'o', L'm', L'm', L'a', L'n', L'd'};
static wchar_t* COMMAND_TAG_HTML_MODEL = COMMAND_TAG_HTML_MODEL_ARRAY;
static int* COMMAND_TAG_HTML_MODEL_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The embed tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t EMBED_TAG_HTML_MODEL_ARRAY[] = {L'e', L'm', L'b', L'e', L'd'};
static wchar_t* EMBED_TAG_HTML_MODEL = EMBED_TAG_HTML_MODEL_ARRAY;
static int* EMBED_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The hr tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t HR_TAG_HTML_MODEL_ARRAY[] = {L'h', L'r'};
static wchar_t* HR_TAG_HTML_MODEL = HR_TAG_HTML_MODEL_ARRAY;
static int* HR_TAG_HTML_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The img tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t IMG_TAG_HTML_MODEL_ARRAY[] = {L'i', L'm', L'g'};
static wchar_t* IMG_TAG_HTML_MODEL = IMG_TAG_HTML_MODEL_ARRAY;
static int* IMG_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The input tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t INPUT_TAG_HTML_MODEL_ARRAY[] = {L'i', L'n', L'p', L'u', L't'};
static wchar_t* INPUT_TAG_HTML_MODEL = INPUT_TAG_HTML_MODEL_ARRAY;
static int* INPUT_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The keygen tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t KEYGEN_TAG_HTML_MODEL_ARRAY[] = {L'k', L'e', L'y', L'g', L'e', L'n'};
static wchar_t* KEYGEN_TAG_HTML_MODEL = KEYGEN_TAG_HTML_MODEL_ARRAY;
static int* KEYGEN_TAG_HTML_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The link tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t LINK_TAG_HTML_MODEL_ARRAY[] = {L'l', L'i', L'n', L'k'};
static wchar_t* LINK_TAG_HTML_MODEL = LINK_TAG_HTML_MODEL_ARRAY;
static int* LINK_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The meta tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t META_TAG_HTML_MODEL_ARRAY[] = {L'm', L'e', L't', L'a'};
static wchar_t* META_TAG_HTML_MODEL = META_TAG_HTML_MODEL_ARRAY;
static int* META_TAG_HTML_MODEL_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The param tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t PARAM_TAG_HTML_MODEL_ARRAY[] = {L'p', L'a', L'r', L'a', L'm'};
static wchar_t* PARAM_TAG_HTML_MODEL = PARAM_TAG_HTML_MODEL_ARRAY;
static int* PARAM_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The pre tag html model.
 *
 * The pre element represents a block of preformatted text,
 * in which structure is represented by typographic conventions
 * rather than by elements.
 */
static wchar_t PRE_TAG_HTML_MODEL_ARRAY[] = {L'p', L'r', L'e'};
static wchar_t* PRE_TAG_HTML_MODEL = PRE_TAG_HTML_MODEL_ARRAY;
static int* PRE_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The source tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t SOURCE_TAG_HTML_MODEL_ARRAY[] = {L's', L'o', L'u', L'r', L'c', L'e'};
static wchar_t* SOURCE_TAG_HTML_MODEL = SOURCE_TAG_HTML_MODEL_ARRAY;
static int* SOURCE_TAG_HTML_MODEL_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The track tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t TRACK_TAG_HTML_MODEL_ARRAY[] = {L't', L'r', L'a', L'c', L'k'};
static wchar_t* TRACK_TAG_HTML_MODEL = TRACK_TAG_HTML_MODEL_ARRAY;
static int* TRACK_TAG_HTML_MODEL_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The wbr tag html model.
 *
 * This tag is allowed to be empty (void element),
 * following the html specification.
 */
static wchar_t WBR_TAG_HTML_MODEL_ARRAY[] = {L'w', L'b', L'r'};
static wchar_t* WBR_TAG_HTML_MODEL = WBR_TAG_HTML_MODEL_ARRAY;
static int* WBR_TAG_HTML_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* TAG_HTML_MODEL_CONSTANT_SOURCE */
#endif
