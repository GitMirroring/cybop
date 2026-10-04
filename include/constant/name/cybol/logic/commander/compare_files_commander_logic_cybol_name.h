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

#ifndef COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER
#define COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

/** The path_1 parameter for the compare files logic in cybol. */
static wchar_t* PATH_1_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"path1";
static int* PATH_1_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The path_2 parameter for the compare files logic in cybol. */
static wchar_t* PATH_2_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"path2";
static int* PATH_2_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print differing chars option for the compare files logic in cybol. */
static wchar_t* PRINT_DIFFERING_CHARS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"print-differing-chars";
static int* PRINT_DIFFERING_CHARS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_21_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print offset option for the compare files logic in cybol. */
static wchar_t* PRINT_OFFSET_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"print-offset";
static int* PRINT_OFFSET_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The print nothing option for the compare files logic in cybol. */
static wchar_t* SILENT_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"silent";
static int* SILENT_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The Case insensitive option for the compare files logic in cybol. */
static wchar_t* CASE_INSENSITIVE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"case-insensitive";
static int* CASE_INSENSITIVE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_16_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare unicode option for the compare files logic in cybol. */
static wchar_t* UNICODE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"unicode";
static int* UNICODE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_7_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compare ascii option for the compare files logic in cybol. */
static wchar_t* ASCII_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"ascii";
static int* ASCII_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The display line numbers option for the compare files logic in cybol. */
static wchar_t* DISPLAY_LINE_NUMBERS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"line-numbers";
static int* DISPLAY_LINE_NUMBERS_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_12_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The compress whitespace option for the compare files logic in cybol. */
static wchar_t* COMPRESS_WHITESPACE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME = L"compress-whitespace";
static int* COMPRESS_WHITESPACE_COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_COUNT = NUMBER_19_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* COMPARE_FILES_COMMANDER_LOGIC_CYBOL_NAME_CONSTANT_HEADER */
#endif
