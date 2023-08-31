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

#ifndef DOS_850_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define DOS_850_CHARACTER_CODE_MODEL_CONSTANT_HEADER

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
// This file contains dos-850 character code constants.
//

//
// Code page 850 (CCSID 850) (also known as CP 850, IBM 00850, OEM 850, DOS Latin 1)
// is a code page used under DOS and Psion's EPOC16 operating systems in Western Europe.
// Depending on the country setting and system configuration, code page 850 is
// the primary code page and default OEM code page in many countries, including
// various English-speaking locales (e.g. in the United Kingdom, Ireland, and Canada),
// whilst other English-speaking locales (like the United States) default to
// use the hardware code page 437.
//
// Code page 850 differs from code page 437 in that many of the box-drawing
// characters, Greek letters, and various symbols were replaced with additional
// Latin letters with diacritics, thus greatly improving support for Western
// European languages (all characters from ISO 8859-1 are included). At the same
// time, the changes frequently caused display glitches with programs that made
// use of the box-drawing characters to display a GUI-like surface in text mode.
//
// In 1998, code page 858 was derived from this code page by changing code
// point 213 (D5hex) from a dotless i ‹ı› to the euro sign ‹€›.
// Despite this, IBM's PC DOS 2000, released in 1998, changed their definition
// of code page 850 to what they called modified code page 850 now including
// the euro sign at code point 213 instead of adding support for the new code
// page 858.
//
// Systems largely replaced code page 850 with Windows-1252 which contains
// all same letters, and later with Unicode.
//
// Reference:
// https://en.wikipedia.org/wiki/Code_page_850
//

//
// In computing, a hardware code page (HWCP) refers to a code page supported
// natively by a hardware device such as a display adapter or printer.
// The glyphs to present the characters are stored in the alphanumeric character
// generator's resident read-only memory (like ROM or flash) and are thus not
// user-changeable. They are available for use by the system without having to
// load any font definitions into the device first. Startup messages issued by
// a PC's System BIOS or displayed by an operating system before initializing
// its own code page switching logic and font management and before switching
// to graphics mode are displayed in a computer's default hardware code page.
//
// Reference:
// https://en.wikipedia.org/wiki/Hardware_code_page
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The extended ascii characters in range 0x80-0xFF
//

/** The latin capital letter c with cedilla dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x80 };
static unsigned char* LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x81 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x82 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with circumflex dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x83 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x84 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with grave dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x85 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with ring above dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x86 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter c with cedilla dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x87 };
static unsigned char* LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_C_WITH_CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with circumflex dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x88 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x89 };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e with grave dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8a };
static unsigned char* LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8b };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with circumflex dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8c };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with grave dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8d };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with diaeresis dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8e };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with ring above dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8f };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x90 };
static unsigned char* LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter ae dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x91 };
static unsigned char* LATIN_SMALL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter ae dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x92 };
static unsigned char* LATIN_CAPITAL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_AE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with circumflex dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x93 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x94 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with grave dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x95 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with circumflex dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x96 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with grave dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x97 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter y with diaeresis dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x98 };
static unsigned char* LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Y_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with diaeresis dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x99 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u with diaeresis dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9a };
static unsigned char* LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with stroke dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9b };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The pound sign dos 850 character code model. */
static unsigned char POUND_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9c };
static unsigned char* POUND_SIGN_DOS_850_CHARACTER_CODE_MODEL = POUND_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with stroke dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9d };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_STROKE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The multiplication sign dos 850 character code model. */
static unsigned char MULTIPLICATION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9e };
static unsigned char* MULTIPLICATION_SIGN_DOS_850_CHARACTER_CODE_MODEL = MULTIPLICATION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter f with hook dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9f };
static unsigned char* LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_F_WITH_HOOK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa0 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa1 };
static unsigned char* LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa2 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa3 };
static unsigned char* LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter n with tilde dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa4 };
static unsigned char* LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter n with tilde dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa5 };
static unsigned char* LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_N_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The feminine ordinal indicator dos 850 character code model. */
static unsigned char FEMININE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa6 };
static unsigned char* FEMININE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL = FEMININE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The masculine ordinal indicator dos 850 character code model. */
static unsigned char MASCULINE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa7 };
static unsigned char* MASCULINE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL = MASCULINE_ORDINAL_INDICATOR_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The inverted question mark dos 850 character code model. */
static unsigned char INVERTED_QUESTION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa8 };
static unsigned char* INVERTED_QUESTION_MARK_DOS_850_CHARACTER_CODE_MODEL = INVERTED_QUESTION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The registered sign dos 850 character code model. */
static unsigned char REGISTERED_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xa9 };
static unsigned char* REGISTERED_SIGN_DOS_850_CHARACTER_CODE_MODEL = REGISTERED_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The not sign (negation) dos 850 character code model. */
static unsigned char NOT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xaa };
static unsigned char* NOT_SIGN_DOS_850_CHARACTER_CODE_MODEL = NOT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one half (fraction one half) dos 850 character code model. */
static unsigned char VULGAR_FRACTION_ONE_HALF_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xab };
static unsigned char* VULGAR_FRACTION_ONE_HALF_DOS_850_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_HALF_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one quarter (fraction one quarter) dos 850 character code model. */
static unsigned char VULGAR_FRACTION_ONE_QUARTER_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xac };
static unsigned char* VULGAR_FRACTION_ONE_QUARTER_DOS_850_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_QUARTER_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The inverted exclamation mark dos 850 character code model. */
static unsigned char INVERTED_EXCLAMATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xad };
static unsigned char* INVERTED_EXCLAMATION_MARK_DOS_850_CHARACTER_CODE_MODEL = INVERTED_EXCLAMATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The left pointing double angle quotation mark (left double angle quotes) dos 850 character code model. */
static unsigned char LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xae };
static unsigned char* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL = LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The right pointing double angle quotation mark (left double angle quotes) dos 850 character code model. */
static unsigned char RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xaf };
static unsigned char* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL = RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The light shade dos 850 character code model. */
static unsigned char LIGHT_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb0 };
static unsigned char* LIGHT_SHADE_DOS_850_CHARACTER_CODE_MODEL = LIGHT_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The medium shade dos 850 character code model. */
static unsigned char MEDIUM_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb1 };
static unsigned char* MEDIUM_SHADE_DOS_850_CHARACTER_CODE_MODEL = MEDIUM_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The dark shade dos 850 character code model. */
static unsigned char DARK_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb2 };
static unsigned char* DARK_SHADE_DOS_850_CHARACTER_CODE_MODEL = DARK_SHADE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb3 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb4 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb5 };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with circumflex dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb6 };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with grave dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb7 };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The copyright sign dos 850 character code model. */
static unsigned char COPYRIGHT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb8 };
static unsigned char* COPYRIGHT_SIGN_DOS_850_CHARACTER_CODE_MODEL = COPYRIGHT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xb9 };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xba };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbb };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbc };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The cent sign dos 850 character code model. */
static unsigned char CENT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbd };
static unsigned char* CENT_SIGN_DOS_850_CHARACTER_CODE_MODEL = CENT_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The yen sign dos 850 character code model. */
static unsigned char YEN_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbe };
static unsigned char* YEN_SIGN_DOS_850_CHARACTER_CODE_MODEL = YEN_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xbf };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc0 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc1 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc2 };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc3 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc4 };
static unsigned char* BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light vertical and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc5 };
static unsigned char* BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a with tilde dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc6 };
static unsigned char* LATIN_SMALL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a with tilde dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc7 };
static unsigned char* LATIN_CAPITAL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc8 };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xc9 };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double up and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xca };
static unsigned char* BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_UP_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double down and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcb };
static unsigned char* BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_DOWN_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcc };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcd };
static unsigned char* BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings double vertical and horizontal dos 850 character code model. */
static unsigned char BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xce };
static unsigned char* BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_DOUBLE_VERTICAL_AND_HORIZONTAL_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The currency sign dos 850 character code model. */
static unsigned char CURRENCY_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xcf };
static unsigned char* CURRENCY_SIGN_DOS_850_CHARACTER_CODE_MODEL = CURRENCY_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter eth dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd0 };
static unsigned char* LATIN_SMALL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter eth dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd1 };
static unsigned char* LATIN_CAPITAL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_ETH_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e with circumflex dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd2 };
static unsigned char* LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e with diaeresis dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd3 };
static unsigned char* LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e with grave dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd4 };
static unsigned char* LATIN_CAPITAL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter dotless i dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_DOTLESS_I_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd5 };
static unsigned char* LATIN_SMALL_LETTER_DOTLESS_I_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_DOTLESS_I_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd6 };
static unsigned char* LATIN_CAPITAL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i with circumflex dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd7 };
static unsigned char* LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i with diaeresis dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd8 };
static unsigned char* LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light up and left dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xd9 };
static unsigned char* BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_UP_AND_LEFT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The box drawings light down and right dos 850 character code model. */
static unsigned char BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xda };
static unsigned char* BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL = BOX_DRAWINGS_LIGHT_DOWN_AND_RIGHT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The full block dos 850 character code model. */
static unsigned char FULL_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdb };
static unsigned char* FULL_BLOCK_DOS_850_CHARACTER_CODE_MODEL = FULL_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The lower half block dos 850 character code model. */
static unsigned char LOWER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdc };
static unsigned char* LOWER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL = LOWER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The broken bar dos 850 character code model. */
static unsigned char BROKEN_BAR_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdd };
static unsigned char* BROKEN_BAR_DOS_850_CHARACTER_CODE_MODEL = BROKEN_BAR_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i with grave dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xde };
static unsigned char* LATIN_CAPITAL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The upper half block dos 850 character code model. */
static unsigned char UPPER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xdf };
static unsigned char* UPPER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL = UPPER_HALF_BLOCK_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe0 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter sharp s (ess-zed) dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_SHARP_S_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe1 };
static unsigned char* LATIN_SMALL_LETTER_SHARP_S_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_SHARP_S_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with circumflex dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe2 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with grave dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe3 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o with tilde dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe4 };
static unsigned char* LATIN_SMALL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o with tilde dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe5 };
static unsigned char* LATIN_CAPITAL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_WITH_TILDE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The greek small letter mu (micro sign) dos 850 character code model. */
static unsigned char GREEK_SMALL_LETTER_MU_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe6 };
static unsigned char* GREEK_SMALL_LETTER_MU_DOS_850_CHARACTER_CODE_MODEL = GREEK_SMALL_LETTER_MU_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter thorn dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe7 };
static unsigned char* LATIN_SMALL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter thorn dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe8 };
static unsigned char* LATIN_CAPITAL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_THORN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xe9 };
static unsigned char* LATIN_CAPITAL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u with circumflex dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xea };
static unsigned char* LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u with grave dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xeb };
static unsigned char* LATIN_CAPITAL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_WITH_GRAVE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter y with acute dos 850 character code model. */
static unsigned char LATIN_SMALL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xec };
static unsigned char* LATIN_SMALL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter y with acute dos 850 character code model. */
static unsigned char LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xed };
static unsigned char* LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Y_WITH_ACUTE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The macron dos 850 character code model. */
static unsigned char MACRON_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xee };
static unsigned char* MACRON_DOS_850_CHARACTER_CODE_MODEL = MACRON_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The acute accent dos 850 character code model. */
static unsigned char ACUTE_ACCENT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xef };
static unsigned char* ACUTE_ACCENT_DOS_850_CHARACTER_CODE_MODEL = ACUTE_ACCENT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The soft hyphen dos 850 character code model. */
static unsigned char SOFT_HYPHEN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf0 };
static unsigned char* SOFT_HYPHEN_DOS_850_CHARACTER_CODE_MODEL = SOFT_HYPHEN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The plus-minus sign (plus-or-minus sign) dos 850 character code model. */
static unsigned char PLUS_MINUS_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf1 };
static unsigned char* PLUS_MINUS_SIGN_DOS_850_CHARACTER_CODE_MODEL = PLUS_MINUS_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The double low line dos 850 character code model. */
static unsigned char DOUBLE_LOW_LINE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf2 };
static unsigned char* DOUBLE_LOW_LINE_DOS_850_CHARACTER_CODE_MODEL = DOUBLE_LOW_LINE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction three quarters dos 850 character code model. */
static unsigned char VULGAR_FRACTION_THREE_QUARTERS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf3 };
static unsigned char* VULGAR_FRACTION_THREE_QUARTERS_DOS_850_CHARACTER_CODE_MODEL = VULGAR_FRACTION_THREE_QUARTERS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The pilcrow sign dos 850 character code model. */
static unsigned char PILCROW_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf4 };
static unsigned char* PILCROW_SIGN_DOS_850_CHARACTER_CODE_MODEL = PILCROW_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The section sign dos 850 character code model. */
static unsigned char SECTION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf5 };
static unsigned char* SECTION_SIGN_DOS_850_CHARACTER_CODE_MODEL = SECTION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The division sign dos 850 character code model. */
static unsigned char DIVISION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf6 };
static unsigned char* DIVISION_SIGN_DOS_850_CHARACTER_CODE_MODEL = DIVISION_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The cedilla dos 850 character code model. */
static unsigned char CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf7 };
static unsigned char* CEDILLA_DOS_850_CHARACTER_CODE_MODEL = CEDILLA_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The degree sign dos 850 character code model. */
static unsigned char DEGREE_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf8 };
static unsigned char* DEGREE_SIGN_DOS_850_CHARACTER_CODE_MODEL = DEGREE_SIGN_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The diaeresis dos 850 character code model. */
static unsigned char DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xf9 };
static unsigned char* DIAERESIS_DOS_850_CHARACTER_CODE_MODEL = DIAERESIS_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The middle dot (georgian comma) dos 850 character code model. */
static unsigned char MIDDLE_DOT_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfa };
static unsigned char* MIDDLE_DOT_DOS_850_CHARACTER_CODE_MODEL = MIDDLE_DOT_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript one dos 850 character code model. */
static unsigned char SUPERSCRIPT_ONE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfb };
static unsigned char* SUPERSCRIPT_ONE_DOS_850_CHARACTER_CODE_MODEL = SUPERSCRIPT_ONE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript three dos 850 character code model. */
static unsigned char SUPERSCRIPT_THREE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfc };
static unsigned char* SUPERSCRIPT_THREE_DOS_850_CHARACTER_CODE_MODEL = SUPERSCRIPT_THREE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript two (squared) dos 850 character code model. */
static unsigned char SUPERSCRIPT_TWO_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfd };
static unsigned char* SUPERSCRIPT_TWO_DOS_850_CHARACTER_CODE_MODEL = SUPERSCRIPT_TWO_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The black square dos 850 character code model. */
static unsigned char BLACK_SQUARE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xfe };
static unsigned char* BLACK_SQUARE_DOS_850_CHARACTER_CODE_MODEL = BLACK_SQUARE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/** The no-break space (non-breaking space) dos 850 character code model. */
static unsigned char NO_BREAK_SPACE_DOS_850_CHARACTER_CODE_MODEL_ARRAY[] = { 0xff };
static unsigned char* NO_BREAK_SPACE_DOS_850_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_DOS_850_CHARACTER_CODE_MODEL_ARRAY;

/* DOS_850_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
