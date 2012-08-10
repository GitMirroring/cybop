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

#ifndef PERCENT_ESCAPE_MODEL_CONSTANT_SOURCE
#define PERCENT_ESCAPE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/** The space   percent escape model. */
static wchar_t SPACE_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'0'};
static wchar_t* SPACE_PERCENT_ESCAPE_MODEL = SPACE_PERCENT_ESCAPE_MODEL_ARRAY;
static int* SPACE_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The number sign # percent escape model. */
static wchar_t NUMBER_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'3'};
static wchar_t* NUMBER_SIGN_PERCENT_ESCAPE_MODEL = NUMBER_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* NUMBER_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dollar sign $ percent escape model. */
static wchar_t DOLLAR_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'4'};
static wchar_t* DOLLAR_SIGN_PERCENT_ESCAPE_MODEL = DOLLAR_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* DOLLAR_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The percent sign % percent escape model. */
static wchar_t PERCENT_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'5'};
static wchar_t* PERCENT_SIGN_PERCENT_ESCAPE_MODEL = PERCENT_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* PERCENT_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The ampersand & percent escape model. */
static wchar_t AMPERSAND_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'6'};
static wchar_t* AMPERSAND_PERCENT_ESCAPE_MODEL = AMPERSAND_PERCENT_ESCAPE_MODEL_ARRAY;
static int* AMPERSAND_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The solidus (slash) / percent escape model. */
static wchar_t SOLIDUS_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'2', L'F'};
static wchar_t* SOLIDUS_PERCENT_ESCAPE_MODEL = SOLIDUS_PERCENT_ESCAPE_MODEL_ARRAY;
static int* SOLIDUS_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The colon : percent escape model. */
static wchar_t COLON_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'A'};
static wchar_t* COLON_PERCENT_ESCAPE_MODEL = COLON_PERCENT_ESCAPE_MODEL_ARRAY;
static int* COLON_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The semicolon ; percent escape model. */
static wchar_t SEMICOLON_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'B'};
static wchar_t* SEMICOLON_PERCENT_ESCAPE_MODEL = SEMICOLON_PERCENT_ESCAPE_MODEL_ARRAY;
static int* SEMICOLON_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The less than sign < percent escape model. */
static wchar_t LESS_THAN_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'C'};
static wchar_t* LESS_THAN_SIGN_PERCENT_ESCAPE_MODEL = LESS_THAN_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* LESS_THAN_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equals sign = percent escape model. */
static wchar_t EQUALS_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'D'};
static wchar_t* EQUALS_SIGN_PERCENT_ESCAPE_MODEL = EQUALS_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* EQUALS_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater than sign > percent escape model. */
static wchar_t GREATER_THAN_SIGN_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'E'};
static wchar_t* GREATER_THAN_SIGN_PERCENT_ESCAPE_MODEL = GREATER_THAN_SIGN_PERCENT_ESCAPE_MODEL_ARRAY;
static int* GREATER_THAN_SIGN_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The question mark ? percent escape model. */
static wchar_t QUESTION_MARK_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'3', L'F'};
static wchar_t* QUESTION_MARK_PERCENT_ESCAPE_MODEL = QUESTION_MARK_PERCENT_ESCAPE_MODEL_ARRAY;
static int* QUESTION_MARK_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The commercial at @ percent escape model. */
static wchar_t COMMERCIAL_AT_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'4', L'0'};
static wchar_t* COMMERCIAL_AT_PERCENT_ESCAPE_MODEL = COMMERCIAL_AT_PERCENT_ESCAPE_MODEL_ARRAY;
static int* COMMERCIAL_AT_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left square bracket [ percent escape model. */
static wchar_t LEFT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'5', L'B'};
static wchar_t* LEFT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL = LEFT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_ARRAY;
static int* LEFT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reverse solidus (backslash) \ percent escape model. */
static wchar_t REVERSE_SOLIDUS_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'5', L'C'};
static wchar_t* REVERSE_SOLIDUS_PERCENT_ESCAPE_MODEL = REVERSE_SOLIDUS_PERCENT_ESCAPE_MODEL_ARRAY;
static int* REVERSE_SOLIDUS_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right square bracket ] percent escape model. */
static wchar_t RIGHT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'5', L'D'};
static wchar_t* RIGHT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL = RIGHT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_ARRAY;
static int* RIGHT_SQUARE_BRACKET_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The caret ^ (circumflex accent) percent escape model. */
static wchar_t CARET_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'5', L'E'};
static wchar_t* CARET_PERCENT_ESCAPE_MODEL = CARET_PERCENT_ESCAPE_MODEL_ARRAY;
static int* CARET_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The grave accent ` percent escape model. */
static wchar_t GRAVE_ACCENT_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'6', L'0'};
static wchar_t* GRAVE_ACCENT_PERCENT_ESCAPE_MODEL = GRAVE_ACCENT_PERCENT_ESCAPE_MODEL_ARRAY;
static int* GRAVE_ACCENT_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The left curly brace { percent escape model. */
static wchar_t LEFT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'7', L'B'};
static wchar_t* LEFT_CURLY_BRACE_PERCENT_ESCAPE_MODEL = LEFT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_ARRAY;
static int* LEFT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vertical bar | percent escape model. */
static wchar_t VERTICAL_BAR_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'7', L'C'};
static wchar_t* VERTICAL_BAR_PERCENT_ESCAPE_MODEL = VERTICAL_BAR_PERCENT_ESCAPE_MODEL_ARRAY;
static int* VERTICAL_BAR_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The right curly brace } percent escape model. */
static wchar_t RIGHT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'7', L'D'};
static wchar_t* RIGHT_CURLY_BRACE_PERCENT_ESCAPE_MODEL = RIGHT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_ARRAY;
static int* RIGHT_CURLY_BRACE_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tilde ~ percent escape model. */
static wchar_t TILDE_PERCENT_ESCAPE_MODEL_ARRAY[] = {L'%', L'7', L'E'};
static wchar_t* TILDE_PERCENT_ESCAPE_MODEL = TILDE_PERCENT_ESCAPE_MODEL_ARRAY;
static int* TILDE_PERCENT_ESCAPE_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* PERCENT_ESCAPE_MODEL_CONSTANT_SOURCE */
#endif
