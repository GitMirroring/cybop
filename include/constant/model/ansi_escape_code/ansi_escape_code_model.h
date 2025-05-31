/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER
#define ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The attribute separator ansi escape code model.
 *
 * ;
 */
static char* ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL = SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The attribute suffix ansi escape code model.
 *
 * ESC[P;...;Pm
 *
 * Mnemonic:
 * SGR (Set Graphics Rendition)
 */
static char* ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL = LATIN_SMALL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* ATTRIBUTE_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erase display ansi escape code model.
 *
 * ESC[2J
 *
 * Mnemonic:
 * ED (Erase Display)
 */
static char ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x32, 0x4A };
static char* ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL = ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* ERASE_DISPLAY_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The erase line ansi escape code model.
 *
 * ESC[K
 *
 * Mnemonic:
 * EL (Erase Line)
 */
static char* ERASE_LINE_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY;
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
static char* POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL = LATIN_CAPITAL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY;
static int* POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The prefix ansi escape code model.
 *
 * ESC[
 */
static char PREFIX_ANSI_ESCAPE_CODE_MODEL_ARRAY[] = { 0x1B, 0x5B };
static char* PREFIX_ANSI_ESCAPE_CODE_MODEL = PREFIX_ANSI_ESCAPE_CODE_MODEL_ARRAY;
static int* PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* ANSI_ESCAPE_CODE_MODEL_CONSTANT_HEADER */
#endif
