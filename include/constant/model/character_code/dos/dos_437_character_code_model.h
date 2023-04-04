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

#ifndef DOS_437_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define DOS_437_CHARACTER_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//
// This file contains dos-437 character code constants.
//

//
// Code page 437 (CCSID 437) is the character set of the original IBM PC (personal computer).
// It is also known as CP437, OEM-US, OEM 437, PC-8 or DOS Latin US.
// The set includes all printable ASCII characters as well as some accented
// letters (diacritics), Greek letters, icons, and line-drawing symbols.
// It is sometimes referred to as the "OEM font" or "high ASCII", or as
// "extended ASCII" (one of many mutually incompatible ASCII extensions).
//
// This character set remains the primary set in the core of any EGA and
// VGA-compatible graphics card. As such, text shown when a PC reboots,
// before fonts can be loaded and rendered, is typically rendered using
// this character set. Many file formats developed at the time of the
// IBM PC are based on code page 437 as well.
//
// Reference:
// https://en.wikipedia.org/wiki/Code_page_437
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The extended ascii characters in range 0x80-0xFF
//

/** The latin capital letter c with cedilla dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x80 };
static unsigned char* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x81 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with acute dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x82 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with circumflex dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x83 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x84 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with grave dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x85 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with ring above dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x86 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter c with cedilla dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x87 };
static unsigned char* LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with circumflex dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x88 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x89 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with grave dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8a };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8b };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with circumflex dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8c };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with grave dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8d };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with diaeresis dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8e };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with ring above dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8f };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e with acute dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x90 };
static unsigned char* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter ae dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x91 };
static unsigned char* LATIN_SMALL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter ae dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x92 };
static unsigned char* LATIN_CAPITAL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_AE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with circumflex dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x93 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x94 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with grave dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x95 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with circumflex dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x96 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with grave dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x97 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter y with diaeresis dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x98 };
static unsigned char* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with diaeresis dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x99 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u with diaeresis dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9a };
static unsigned char* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The cent sign dos 437 character code model. */
static unsigned char CENT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9b };
static unsigned char* CENT_SIGN_DOS_437_CHARACTER_CODE_MODEL = CENT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The pound sign dos 437 character code model. */
static unsigned char POUND_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9c };
static unsigned char* POUND_SIGN_DOS_437_CHARACTER_CODE_MODEL = POUND_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The yen sign dos 437 character code model. */
static unsigned char YEN_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9d };
static unsigned char* YEN_SIGN_DOS_437_CHARACTER_CODE_MODEL = YEN_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The peseta sign dos 437 character code model. */
static unsigned char PESETA_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9e };
static unsigned char* PESETA_SIGN_DOS_437_CHARACTER_CODE_MODEL = PESETA_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter f with hook dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9f };
static unsigned char* LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with acute dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa0 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with acute dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa1 };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with acute dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa2 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with acute dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa3 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter n with tilde dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa4 };
static unsigned char* LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter n with tilde dos 437 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa5 };
static unsigned char* LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The feminine ordinal indicator dos 437 character code model. */
static unsigned char FEMININE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa6 };
static unsigned char* FEMININE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL = FEMININE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The masculine ordinal indicator dos 437 character code model. */
static unsigned char MASCULINE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa7 };
static unsigned char* MASCULINE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL = MASCULINE_ORDINAL_INDICATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The inverted question mark dos 437 character code model. */
static unsigned char INVERTED_QUESTION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa8 };
static unsigned char* INVERTED_QUESTION_MARK_DOS_437_CHARACTER_CODE_MODEL = INVERTED_QUESTION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The reversed not sign dos 437 character code model. */
static unsigned char REVERSED_NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa9 };
static unsigned char* REVERSED_NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL = REVERSED_NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The not sign (negation) dos 437 character code model. */
static unsigned char NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xaa };
static unsigned char* NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL = NOT_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one half (fraction one half) dos 437 character code model. */
static unsigned char VULGAR_FRACTION_ONE_HALF_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xab };
static unsigned char* VULGAR_FRACTION_ONE_HALF_DOS_437_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_HALF_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one quarter (fraction one quarter) dos 437 character code model. */
static unsigned char VULGAR_FRACTION_ONE_QUARTER_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xac };
static unsigned char* VULGAR_FRACTION_ONE_QUARTER_DOS_437_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_QUARTER_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The inverted exclamation mark dos 437 character code model. */
static unsigned char INVERTED_EXCLAMATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xad };
static unsigned char* INVERTED_EXCLAMATION_MARK_DOS_437_CHARACTER_CODE_MODEL = INVERTED_EXCLAMATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The left pointing double angle quotation mark (left double angle quotes) dos 437 character code model. */
static unsigned char LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xae };
static unsigned char* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL = LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The right pointing double angle quotation mark (left double angle quotes) dos 437 character code model. */
static unsigned char RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xaf };
static unsigned char* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL = RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The light shade dos 437 character code model. */
static unsigned char LIGHT_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb0 };
static unsigned char* LIGHT_SHADE_DOS_437_CHARACTER_CODE_MODEL = LIGHT_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The medium shade dos 437 character code model. */
static unsigned char MEDIUM_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb1 };
static unsigned char* MEDIUM_SHADE_DOS_437_CHARACTER_CODE_MODEL = MEDIUM_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The dark shade dos 437 character code model. */
static unsigned char DARK_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb2 };
static unsigned char* DARK_SHADE_DOS_437_CHARACTER_CODE_MODEL = DARK_SHADE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb3 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb4 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical single and left double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb5 };
static unsigned char* BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical double and left single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb6 };
static unsigned char* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down double and left single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb7 };
static unsigned char* BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down single and left double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb8 };
static unsigned char* BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb9 };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xba };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbb };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbc };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up double and left single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbd };
static unsigned char* BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_DOUBLE_AND_LEFT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up single and left double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbe };
static unsigned char* BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_SINGLE_AND_LEFT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbf };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc0 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc1 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc2 };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc3 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc4 };
static unsigned char* BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc5 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical single and right double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc6 };
static unsigned char* BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical double and right single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc7 };
static unsigned char* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc8 };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc9 };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xca };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcb };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcc };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcd };
static unsigned char* BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and horizontal dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xce };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up single and horizontal double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcf };
static unsigned char* BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up double and horizontal single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd0 };
static unsigned char* BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down single and horizontal double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd1 };
static unsigned char* BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down double and horizontal single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd2 };
static unsigned char* BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up double and right single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd3 };
static unsigned char* BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings up single and right double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd4 };
static unsigned char* BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_UP_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down single and right double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd5 };
static unsigned char* BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_SINGLE_AND_RIGHT_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings down double and right single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd6 };
static unsigned char* BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOWN_DOUBLE_AND_RIGHT_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical double and horizontal single dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd7 };
static unsigned char* BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_DOUBLE_AND_HORIZONTAL_SINGLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings vertical single and horizontal double dos 437 character code model. */
static unsigned char BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd8 };
static unsigned char* BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_VERTICAL_SINGLE_AND_HORIZONTAL_DOUBLE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and left dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd9 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and right dos 437 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xda };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The full block dos 437 character code model. */
static unsigned char FULL_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdb };
static unsigned char* FULL_BLOCK_DOS_437_CHARACTER_CODE_MODEL = FULL_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The lower half block dos 437 character code model. */
static unsigned char LOWER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdc };
static unsigned char* LOWER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL = LOWER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The left half block dos 437 character code model. */
static unsigned char LEFT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdd };
static unsigned char* LEFT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL = LEFT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The right half block dos 437 character code model. */
static unsigned char RIGHT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xde };
static unsigned char* RIGHT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL = RIGHT_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The upper half block dos 437 character code model. */
static unsigned char UPPER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdf };
static unsigned char* UPPER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL = UPPER_HALF_BLOCK_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter alpha dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_ALPHA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe0 };
static unsigned char* GREEK_SMALL_LETTER_ALPHA_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_ALPHA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter sharp s (ess-zed) dos 437 character code model. */
static unsigned char LATIN_SMALL_LETTER_SHARP_S_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe1 };
static unsigned char* LATIN_SMALL_LETTER_SHARP_S_DOS_437_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_SHARP_S_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek capital letter gamma dos 437 character code model. */
static unsigned char GREEK_CAPITAL_LETTER_GAMMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe2 };
static unsigned char* GREEK_CAPITAL_LETTER_GAMMA_DOS_437_CHARACTER_CODE_MODEL = GREEK_CAPITAL_LETTER_GAMMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter pi dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_PI_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe3 };
static unsigned char* GREEK_SMALL_LETTER_PI_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_PI_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek capital letter sigma dos 437 character code model. */
static unsigned char GREEK_CAPITAL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe4 };
static unsigned char* GREEK_CAPITAL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL = GREEK_CAPITAL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter sigma dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe5 };
static unsigned char* GREEK_SMALL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_SIGMA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter mu (micro sign) dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_MU_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe6 };
static unsigned char* GREEK_SMALL_LETTER_MU_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_MU_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter tau dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_TAU_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe7 };
static unsigned char* GREEK_SMALL_LETTER_TAU_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_TAU_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek capital letter phi dos 437 character code model. */
static unsigned char GREEK_CAPITAL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe8 };
static unsigned char* GREEK_CAPITAL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL = GREEK_CAPITAL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek capital letter theta dos 437 character code model. */
static unsigned char GREEK_CAPITAL_LETTER_THETA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe9 };
static unsigned char* GREEK_CAPITAL_LETTER_THETA_DOS_437_CHARACTER_CODE_MODEL = GREEK_CAPITAL_LETTER_THETA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek capital letter omega dos 437 character code model. */
static unsigned char GREEK_CAPITAL_LETTER_OMEGA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xea };
static unsigned char* GREEK_CAPITAL_LETTER_OMEGA_DOS_437_CHARACTER_CODE_MODEL = GREEK_CAPITAL_LETTER_OMEGA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter delta dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_DELTA_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xeb };
static unsigned char* GREEK_SMALL_LETTER_DELTA_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_DELTA_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The infinity dos 437 character code model. */
static unsigned char INFINITY_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xec };
static unsigned char* INFINITY_DOS_437_CHARACTER_CODE_MODEL = INFINITY_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter phi dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xed };
static unsigned char* GREEK_SMALL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_PHI_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter epsilon dos 437 character code model. */
static unsigned char GREEK_SMALL_LETTER_EPSILON_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xee };
static unsigned char* GREEK_SMALL_LETTER_EPSILON_DOS_437_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_EPSILON_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The intersection dos 437 character code model. */
static unsigned char INTERSECTION_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xef };
static unsigned char* INTERSECTION_DOS_437_CHARACTER_CODE_MODEL = INTERSECTION_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The identical to dos 437 character code model. */
static unsigned char IDENTICAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf0 };
static unsigned char* IDENTICAL_TO_DOS_437_CHARACTER_CODE_MODEL = IDENTICAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The plus-minus sign (plus-or-minus sign) dos 437 character code model. */
static unsigned char PLUS_MINUS_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf1 };
static unsigned char* PLUS_MINUS_SIGN_DOS_437_CHARACTER_CODE_MODEL = PLUS_MINUS_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The greater-than or equal to dos 437 character code model. */
static unsigned char GREATER_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf2 };
static unsigned char* GREATER_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL = GREATER_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The less-than or equal to dos 437 character code model. */
static unsigned char LESS_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf3 };
static unsigned char* LESS_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL = LESS_THAN_OR_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The top half integral dos 437 character code model. */
static unsigned char TOP_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf4 };
static unsigned char* TOP_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL = TOP_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The bottom half integral dos 437 character code model. */
static unsigned char BOTTOM_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf5 };
static unsigned char* BOTTOM_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL = BOTTOM_HALF_INTEGRAL_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The division sign dos 437 character code model. */
static unsigned char DIVISION_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf6 };
static unsigned char* DIVISION_SIGN_DOS_437_CHARACTER_CODE_MODEL = DIVISION_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The almost equal to dos 437 character code model. */
static unsigned char ALMOST_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf7 };
static unsigned char* ALMOST_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL = ALMOST_EQUAL_TO_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The degree sign dos 437 character code model. */
static unsigned char DEGREE_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf8 };
static unsigned char* DEGREE_SIGN_DOS_437_CHARACTER_CODE_MODEL = DEGREE_SIGN_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The bullet operator dos 437 character code model. */
static unsigned char BULLET_OPERATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf9 };
static unsigned char* BULLET_OPERATOR_DOS_437_CHARACTER_CODE_MODEL = BULLET_OPERATOR_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The middle dot (georgian comma) dos 437 character code model. */
static unsigned char MIDDLE_DOT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfa };
static unsigned char* MIDDLE_DOT_DOS_437_CHARACTER_CODE_MODEL = MIDDLE_DOT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The square root dos 437 character code model. */
static unsigned char SQUARE_ROOT_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfb };
static unsigned char* SQUARE_ROOT_DOS_437_CHARACTER_CODE_MODEL = SQUARE_ROOT_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript latin small letter n dos 437 character code model. */
static unsigned char SUPERSCRIPT_LATIN_SMALL_LETTER_N_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfc };
static unsigned char* SUPERSCRIPT_LATIN_SMALL_LETTER_N_DOS_437_CHARACTER_CODE_MODEL = SUPERSCRIPT_LATIN_SMALL_LETTER_N_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript two (squared) dos 437 character code model. */
static unsigned char SUPERSCRIPT_TWO_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfd };
static unsigned char* SUPERSCRIPT_TWO_DOS_437_CHARACTER_CODE_MODEL = SUPERSCRIPT_TWO_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The black square dos 437 character code model. */
static unsigned char BLACK_SQUARE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfe };
static unsigned char* BLACK_SQUARE_DOS_437_CHARACTER_CODE_MODEL = BLACK_SQUARE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/** The no-break space (non-breaking space) dos 437 character code model. */
static unsigned char NO_BREAK_SPACE_DOS_437_CHARACTER_CODE_MODEL_ARRAY[] = { 0xff };
static unsigned char* NO_BREAK_SPACE_DOS_437_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_DOS_437_CHARACTER_CODE_MODEL_ARRAY;

/* DOS_437_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
