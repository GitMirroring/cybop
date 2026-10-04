/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/**
 * The path for the word count file logic cybol name.
 *
 * It indicates the path of a file for word count
 */
static wchar_t* PATH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"path";
static int* PATH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The byte option for word count file logic cybol name.
 *
 * It outputs the number of bytes
 */
static wchar_t* BYTE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"bytes";
static int* BYTE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The char option for word count file logic cybol name.
 *
 * It outputs the number of chars
 */
static wchar_t* CHAR_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"chars";
static int* CHAR_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The line option for word count file logic cybol name.
 *
 * It outputs the number of lines
 */
static wchar_t* LINE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"lines";
static int* LINE_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The max-line-length option for word count file logic cybol name.
 *
 * It outputs the length of the longest line
 */
static wchar_t* MAX_LINE_LENGTH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"max-line-length";
static int* MAX_LINE_LENGTH_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_15_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/**
 * The word option for word count file logic cybol name.
 *
 * It outputs the number of words
 */
static wchar_t* WORD_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME = L"words";
static int* WORD_WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* WORD_COUNT_FILE_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
