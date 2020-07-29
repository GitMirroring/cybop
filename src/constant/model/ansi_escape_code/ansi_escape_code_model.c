/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE
#define ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The attribute separator ansi escape code model.
 *
 * ;
 */
static wchar_t* ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL = SEMICOLON_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The attribute suffix ansi escape code model.
 *
 * ESC[P;...;Pm
 *
 * Mnemonic:
 * SGR (Set Graphics Rendition)
 */
static wchar_t* ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL = LATIN_SMALL_LETTER_M_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erase display ansi escape code model.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static wchar_t ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x0032, 0x004A};
static wchar_t* ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL = ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erase line ansi escape code model.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static wchar_t* ERASE_LINE_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_K_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* ERASE_LINE_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The position suffix ansi escape code model.
 *
 * ESC[P;PH
 *
 * Mnemonic:
 * CUP (Cursor Position)
 * HVP (Horizontal and Vertical Position)
 */
static wchar_t* POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL_ARRAY;
static int* POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prefix ansi escape code model.
 *
 * ESC[
 */
static wchar_t PREFIX_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = {0x001B, 0x005B};
static wchar_t* PREFIX_ANSI_ESCAPE_CODE_MODEL = PREFIX_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ANSI_ESCAPE_CODE_MODEL_CONSTANT_SOURCE */
#endif
