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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ISO_8859_10_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define ISO_8859_10_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/iso_6429/c0_iso_6429_character_code_model.c"
#include "../../../../constant/model/character_code/iso_6429/c1_iso_6429_character_code_model.c"

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//

//
// ISO/IEC 8859 is a joint ISO and IEC series of standards for 8-bit character encodings.
// The series of standards consists of numbered parts, such as ISO/IEC 8859-1, ISO/IEC 8859-2, etc.
// There are 15 parts, excluding the abandoned ISO/IEC 8859-12.
// The ISO working group maintaining this series of standards has been disbanded.
// ISO/IEC 8859 parts 1, 2, 3, and 4 were originally Ecma International standard ECMA-94.
//
// While "ISO/IEC 8859" (without hyphen) does NOT define
// any characters for ranges 0x00-0x1F and 0x7F-0x9F,
// the "ISO-8859" (WITH hyphen and WITHOUT "IEC") standard
// registered with the IANA specifies non-printable
// control characters within these FREE areas.
// Therefore, both are related and do NOT conflict.
//
// For easier handling, both are merged here, so that
// cyboi is able to handle printable characters as defined
// in "ISO/IEC 8859" AS WELL AS control characters of "ISO-8859".
//
// This file contains ISO-8859-10 character code constants:
// Latin-6 Nordic
//

//
// The non-printable control characters in range 0x00-0x1F
// which are defined by "ISO-8859" but not "ISO/IEC 8859".
//

/** The null iso-8859-10 character code model. U+0000 */
static char* NULL_ISO_8859_10_CHARACTER_CODE_MODEL = NULL_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of heading iso-8859-10 character code model. U+0001 */
static char* START_OF_HEADING_ISO_8859_10_CHARACTER_CODE_MODEL = START_OF_HEADING_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of text iso-8859-10 character code model. U+0002 */
static char* START_OF_TEXT_ISO_8859_10_CHARACTER_CODE_MODEL = START_OF_TEXT_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of text iso-8859-10 character code model. U+0003 */
static char* END_OF_TEXT_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_TEXT_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission iso-8859-10 character code model. U+0004 */
static char* END_OF_TRANSMISSION_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The enquiry iso-8859-10 character code model. U+0005 */
static char* ENQUIRY_ISO_8859_10_CHARACTER_CODE_MODEL = ENQUIRY_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The acknowledge iso-8859-10 character code model. U+0006 */
static char* ACKNOWLEDGE_ISO_8859_10_CHARACTER_CODE_MODEL = ACKNOWLEDGE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The bell iso-8859-10 character code model. U+0007 */
static char* BELL_ISO_8859_10_CHARACTER_CODE_MODEL = BELL_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The backspace iso-8859-10 character code model. U+0008 */
static char* BACKSPACE_ISO_8859_10_CHARACTER_CODE_MODEL = BACKSPACE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation iso-8859-10 character code model. U+0009 */
static char* CHARACTER_TABULATION_ISO_8859_10_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line feed iso-8859-10 character code model. U+000A */
static char* LINE_FEED_ISO_8859_10_CHARACTER_CODE_MODEL = LINE_FEED_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation iso-8859-10 character code model. U+000B */
static char* LINE_TABULATION_ISO_8859_10_CHARACTER_CODE_MODEL = LINE_TABULATION_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The form feed iso-8859-10 character code model. U+000C */
static char* FORM_FEED_ISO_8859_10_CHARACTER_CODE_MODEL = FORM_FEED_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The carriage return (enter) iso-8859-10 character code model. U+000D */
static char* CARRIAGE_RETURN_ISO_8859_10_CHARACTER_CODE_MODEL = CARRIAGE_RETURN_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The shift out iso-8859-10 character code model. U+000E */
static char* SHIFT_OUT_ISO_8859_10_CHARACTER_CODE_MODEL = SHIFT_OUT_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The shift in iso-8859-10 character code model. U+000F */
static char* SHIFT_IN_ISO_8859_10_CHARACTER_CODE_MODEL = SHIFT_IN_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The data link escape iso-8859-10 character code model. U+0010 */
static char* DATA_LINK_ESCAPE_ISO_8859_10_CHARACTER_CODE_MODEL = DATA_LINK_ESCAPE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control one iso-8859-10 character code model. U+0011 */
static char* DEVICE_CONTROL_ONE_ISO_8859_10_CHARACTER_CODE_MODEL = DEVICE_CONTROL_ONE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control two iso-8859-10 character code model. U+0012 */
static char* DEVICE_CONTROL_TWO_ISO_8859_10_CHARACTER_CODE_MODEL = DEVICE_CONTROL_TWO_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control three iso-8859-10 character code model. U+0013 */
static char* DEVICE_CONTROL_THREE_ISO_8859_10_CHARACTER_CODE_MODEL = DEVICE_CONTROL_THREE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control four iso-8859-10 character code model. U+0014 */
static char* DEVICE_CONTROL_FOUR_ISO_8859_10_CHARACTER_CODE_MODEL = DEVICE_CONTROL_FOUR_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The negative acknowledge iso-8859-10 character code model. U+0015 */
static char* NEGATIVE_ACKNOWLEDGE_ISO_8859_10_CHARACTER_CODE_MODEL = NEGATIVE_ACKNOWLEDGE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The synchronous idle iso-8859-10 character code model. U+0016 */
static char* SYNCHRONOUS_IDLE_ISO_8859_10_CHARACTER_CODE_MODEL = SYNCHRONOUS_IDLE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission block iso-8859-10 character code model. U+0017 */
static char* END_OF_TRANSMISSION_BLOCK_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_BLOCK_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel iso-8859-10 character code model. U+0018 */
static char* CANCEL_ISO_8859_10_CHARACTER_CODE_MODEL = CANCEL_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of medium iso-8859-10 character code model. U+0019 */
static char* END_OF_MEDIUM_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_MEDIUM_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The substitute iso-8859-10 character code model. U+001A */
static char* SUBSTITUTE_ISO_8859_10_CHARACTER_CODE_MODEL = SUBSTITUTE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The escape iso-8859-10 character code model. U+001B */
static char* ESCAPE_ISO_8859_10_CHARACTER_CODE_MODEL = ESCAPE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The file separator iso-8859-10 character code model. U+001C */
static char* FILE_SEPARATOR_ISO_8859_10_CHARACTER_CODE_MODEL = FILE_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The group separator iso-8859-10 character code model. U+001D */
static char* GROUP_SEPARATOR_ISO_8859_10_CHARACTER_CODE_MODEL = GROUP_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The record separator iso-8859-10 character code model. U+001E */
static char* RECORD_SEPARATOR_ISO_8859_10_CHARACTER_CODE_MODEL = RECORD_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The unit separator iso-8859-10 character code model. U+001F */
static char* UNIT_SEPARATOR_ISO_8859_10_CHARACTER_CODE_MODEL = UNIT_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0x20-0x7E.
//

/** The space iso-8859-10 character code model. U+0020 */
static char* SPACE_ISO_8859_10_CHARACTER_CODE_MODEL = SPACE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The exclamation mark iso-8859-10 character code model. U+0021 */
static char* EXCLAMATION_MARK_ISO_8859_10_CHARACTER_CODE_MODEL = EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The quotation mark iso-8859-10 character code model. U+0022 */
static char* QUOTATION_MARK_ISO_8859_10_CHARACTER_CODE_MODEL = QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The number sign iso-8859-10 character code model. U+0023 */
static char* NUMBER_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The dollar sign iso-8859-10 character code model. U+0024 */
static char* DOLLAR_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The percent sign iso-8859-10 character code model. U+0025 */
static char* PERCENT_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The ampersand iso-8859-10 character code model. U+0026 */
static char* AMPERSAND_ISO_8859_10_CHARACTER_CODE_MODEL = AMPERSAND_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The apostrophe iso-8859-10 character code model. U+0027 */
static char* APOSTROPHE_ISO_8859_10_CHARACTER_CODE_MODEL = APOSTROPHE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left parenthesis iso-8859-10 character code model. U+0028 */
static char* LEFT_PARENTHESIS_ISO_8859_10_CHARACTER_CODE_MODEL = LEFT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right parenthesis iso-8859-10 character code model. U+0029 */
static char* RIGHT_PARENTHESIS_ISO_8859_10_CHARACTER_CODE_MODEL = RIGHT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The asterisk iso-8859-10 character code model. U+002A */
static char* ASTERISK_ISO_8859_10_CHARACTER_CODE_MODEL = ASTERISK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The plus sign iso-8859-10 character code model. U+002B */
static char* PLUS_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The comma iso-8859-10 character code model. U+002C */
static char* COMMA_ISO_8859_10_CHARACTER_CODE_MODEL = COMMA_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The hyphen minus iso-8859-10 character code model. U+002D */
static char* HYPHEN_MINUS_ISO_8859_10_CHARACTER_CODE_MODEL = HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The full stop iso-8859-10 character code model. U+002E */
static char* FULL_STOP_ISO_8859_10_CHARACTER_CODE_MODEL = FULL_STOP_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The solidus iso-8859-10 character code model. U+002F */
static char* SOLIDUS_ISO_8859_10_CHARACTER_CODE_MODEL = SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit zero iso-8859-10 character code model. U+0030 */
static char* DIGIT_ZERO_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_ZERO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit one iso-8859-10 character code model. U+0031 */
static char* DIGIT_ONE_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit two iso-8859-10 character code model. U+0032 */
static char* DIGIT_TWO_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit three iso-8859-10 character code model. U+0033 */
static char* DIGIT_THREE_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit four iso-8859-10 character code model. U+0034 */
static char* DIGIT_FOUR_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit five iso-8859-10 character code model. U+0035 */
static char* DIGIT_FIVE_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_FIVE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit six iso-8859-10 character code model. U+0036 */
static char* DIGIT_SIX_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_SIX_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit seven iso-8859-10 character code model. U+0037 */
static char* DIGIT_SEVEN_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_SEVEN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit eight iso-8859-10 character code model. U+0038 */
static char* DIGIT_EIGHT_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_EIGHT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit nine iso-8859-10 character code model. U+0039 */
static char* DIGIT_NINE_ISO_8859_10_CHARACTER_CODE_MODEL = DIGIT_NINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The colon iso-8859-10 character code model. U+003A */
static char* COLON_ISO_8859_10_CHARACTER_CODE_MODEL = COLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The semicolon iso-8859-10 character code model. U+003B */
static char* SEMICOLON_ISO_8859_10_CHARACTER_CODE_MODEL = SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The less than sign iso-8859-10 character code model. U+003C */
static char* LESS_THAN_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The equals sign iso-8859-10 character code model. U+003D */
static char* EQUALS_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The greater than sign iso-8859-10 character code model. U+003E */
static char* GREATER_THAN_SIGN_ISO_8859_10_CHARACTER_CODE_MODEL = GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The question mark iso-8859-10 character code model. U+003F */
static char* QUESTION_MARK_ISO_8859_10_CHARACTER_CODE_MODEL = QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The commercial at iso-8859-10 character code model. U+0040 */
static char* COMMERCIAL_AT_ISO_8859_10_CHARACTER_CODE_MODEL = COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a iso-8859-10 character code model. U+0041 */
static char* LATIN_CAPITAL_LETTER_A_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter b iso-8859-10 character code model. U+0042 */
static char* LATIN_CAPITAL_LETTER_B_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter c iso-8859-10 character code model. U+0043 */
static char* LATIN_CAPITAL_LETTER_C_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter d iso-8859-10 character code model. U+0044 */
static char* LATIN_CAPITAL_LETTER_D_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e iso-8859-10 character code model. U+0045 */
static char* LATIN_CAPITAL_LETTER_E_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter f iso-8859-10 character code model. U+0046 */
static char* LATIN_CAPITAL_LETTER_F_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter g iso-8859-10 character code model. U+0047 */
static char* LATIN_CAPITAL_LETTER_G_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter h iso-8859-10 character code model. U+0048 */
static char* LATIN_CAPITAL_LETTER_H_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i iso-8859-10 character code model. U+0049 */
static char* LATIN_CAPITAL_LETTER_I_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter j iso-8859-10 character code model. U+004A */
static char* LATIN_CAPITAL_LETTER_J_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter k iso-8859-10 character code model. U+004B */
static char* LATIN_CAPITAL_LETTER_K_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter l iso-8859-10 character code model. U+004C */
static char* LATIN_CAPITAL_LETTER_L_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter m iso-8859-10 character code model. U+004D */
static char* LATIN_CAPITAL_LETTER_M_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter n iso-8859-10 character code model. U+004E */
static char* LATIN_CAPITAL_LETTER_N_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o iso-8859-10 character code model. U+004F */
static char* LATIN_CAPITAL_LETTER_O_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter p iso-8859-10 character code model. U+0050 */
static char* LATIN_CAPITAL_LETTER_P_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter q iso-8859-10 character code model. U+0051 */
static char* LATIN_CAPITAL_LETTER_Q_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter r iso-8859-10 character code model. U+0052 */
static char* LATIN_CAPITAL_LETTER_R_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter s iso-8859-10 character code model. U+0053 */
static char* LATIN_CAPITAL_LETTER_S_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter t iso-8859-10 character code model. U+0054 */
static char* LATIN_CAPITAL_LETTER_T_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u iso-8859-10 character code model. U+0055 */
static char* LATIN_CAPITAL_LETTER_U_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter v iso-8859-10 character code model. U+0056 */
static char* LATIN_CAPITAL_LETTER_V_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter w iso-8859-10 character code model. U+0057 */
static char* LATIN_CAPITAL_LETTER_W_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter x iso-8859-10 character code model. U+0058 */
static char* LATIN_CAPITAL_LETTER_X_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter y iso-8859-10 character code model. U+0059 */
static char* LATIN_CAPITAL_LETTER_Y_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter z iso-8859-10 character code model. U+005A */
static char* LATIN_CAPITAL_LETTER_Z_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left square bracket iso-8859-10 character code model. U+005B */
static char* LEFT_SQUARE_BRACKET_ISO_8859_10_CHARACTER_CODE_MODEL = LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse solidus iso-8859-10 character code model. U+005C */
static char* REVERSE_SOLIDUS_ISO_8859_10_CHARACTER_CODE_MODEL = REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right square bracket iso-8859-10 character code model. U+005D */
static char* RIGHT_SQUARE_BRACKET_ISO_8859_10_CHARACTER_CODE_MODEL = RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The circumflex accent iso-8859-10 character code model. U+005E */
static char* CIRCUMFLEX_ACCENT_ISO_8859_10_CHARACTER_CODE_MODEL = CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The low line iso-8859-10 character code model. U+005F */
static char* LOW_LINE_ISO_8859_10_CHARACTER_CODE_MODEL = LOW_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The grave accent iso-8859-10 character code model. U+0060 */
static char* GRAVE_ACCENT_ISO_8859_10_CHARACTER_CODE_MODEL = GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a iso-8859-10 character code model. U+0061 */
static char* LATIN_SMALL_LETTER_A_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter b iso-8859-10 character code model. U+0062 */
static char* LATIN_SMALL_LETTER_B_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter c iso-8859-10 character code model. U+0063 */
static char* LATIN_SMALL_LETTER_C_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter d iso-8859-10 character code model. U+0064 */
static char* LATIN_SMALL_LETTER_D_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e iso-8859-10 character code model. U+0065 */
static char* LATIN_SMALL_LETTER_E_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter f iso-8859-10 character code model. U+0066 */
static char* LATIN_SMALL_LETTER_F_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter g iso-8859-10 character code model. U+0067 */
static char* LATIN_SMALL_LETTER_G_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter h iso-8859-10 character code model. U+0068 */
static char* LATIN_SMALL_LETTER_H_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i iso-8859-10 character code model. U+0069 */
static char* LATIN_SMALL_LETTER_I_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter j iso-8859-10 character code model. U+006A */
static char* LATIN_SMALL_LETTER_J_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter k iso-8859-10 character code model. U+006B */
static char* LATIN_SMALL_LETTER_K_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter l iso-8859-10 character code model. U+006C */
static char* LATIN_SMALL_LETTER_L_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter m iso-8859-10 character code model. U+006D */
static char* LATIN_SMALL_LETTER_M_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter n iso-8859-10 character code model. U+006E */
static char* LATIN_SMALL_LETTER_N_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o iso-8859-10 character code model. U+006F */
static char* LATIN_SMALL_LETTER_O_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter p iso-8859-10 character code model. U+0070 */
static char* LATIN_SMALL_LETTER_P_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter q iso-8859-10 character code model. U+0071 */
static char* LATIN_SMALL_LETTER_Q_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter r iso-8859-10 character code model. U+0072 */
static char* LATIN_SMALL_LETTER_R_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter s iso-8859-10 character code model. U+0073 */
static char* LATIN_SMALL_LETTER_S_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter t iso-8859-10 character code model. U+0074 */
static char* LATIN_SMALL_LETTER_T_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u iso-8859-10 character code model. U+0075 */
static char* LATIN_SMALL_LETTER_U_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter v iso-8859-10 character code model. U+0076 */
static char* LATIN_SMALL_LETTER_V_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter w iso-8859-10 character code model. U+0077 */
static char* LATIN_SMALL_LETTER_W_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter x iso-8859-10 character code model. U+0078 */
static char* LATIN_SMALL_LETTER_X_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter y iso-8859-10 character code model. U+0079 */
static char* LATIN_SMALL_LETTER_Y_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter z iso-8859-10 character code model. U+007A */
static char* LATIN_SMALL_LETTER_Z_ISO_8859_10_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left curly bracket iso-8859-10 character code model. U+007B */
static char* LEFT_CURLY_BRACKET_ISO_8859_10_CHARACTER_CODE_MODEL = LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The vertical line iso-8859-10 character code model. U+007C */
static char* VERTICAL_LINE_ISO_8859_10_CHARACTER_CODE_MODEL = VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right curly bracket iso-8859-10 character code model. U+007D */
static char* RIGHT_CURLY_BRACKET_ISO_8859_10_CHARACTER_CODE_MODEL = RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The tilde iso-8859-10 character code model. U+007E */
static char* TILDE_ISO_8859_10_CHARACTER_CODE_MODEL = TILDE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

//
// The non-printable control characters in range 0x7F-0x9F
// which are defined by "ISO-8859" but not "ISO/IEC 8859".
//

/** The delete iso-8859-10 character code model. U+007F */
static char* DELETE_ISO_8859_10_CHARACTER_CODE_MODEL = DELETE_C0_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The padding character iso-8859-10 character code model. U+0080
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static char* PADDING_CHARACTER_ISO_8859_10_CHARACTER_CODE_MODEL = PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The high octet preset iso-8859-10 character code model. U+0081
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static char* HIGH_OCTET_PRESET_ISO_8859_10_CHARACTER_CODE_MODEL = HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The break permitted here iso-8859-10 character code model. U+0082 */
static char* BREAK_PERMITTED_HERE_ISO_8859_10_CHARACTER_CODE_MODEL = BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The no break here iso-8859-10 character code model. U+0083 */
static char* NO_BREAK_HERE_ISO_8859_10_CHARACTER_CODE_MODEL = NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The index iso-8859-10 character code model. U+0084 */
static char* INDEX_ISO_8859_10_CHARACTER_CODE_MODEL = INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The next line iso-8859-10 character code model. U+0085 */
static char* NEXT_LINE_ISO_8859_10_CHARACTER_CODE_MODEL = NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of selected area iso-8859-10 character code model. U+0086 */
static char* START_OF_SELECTED_AREA_ISO_8859_10_CHARACTER_CODE_MODEL = START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of selected area iso-8859-10 character code model. U+0087 */
static char* END_OF_SELECTED_AREA_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation set iso-8859-10 character code model. U+0088 */
static char* CHARACTER_TABULATION_SET_ISO_8859_10_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation with justification iso-8859-10 character code model. U+0089 */
static char* CHARACTER_TABULATION_WITH_JUSTIFICATION_ISO_8859_10_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation set iso-8859-10 character code model. U+008A */
static char* LINE_TABULATION_SET_ISO_8859_10_CHARACTER_CODE_MODEL = LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line forward iso-8859-10 character code model. U+008B */
static char* PARTIAL_LINE_FORWARD_ISO_8859_10_CHARACTER_CODE_MODEL = PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line backward iso-8859-10 character code model. U+008C */
static char* PARTIAL_LINE_BACKWARD_ISO_8859_10_CHARACTER_CODE_MODEL = PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse line feed iso-8859-10 character code model. U+008D */
static char* REVERSE_LINE_FEED_ISO_8859_10_CHARACTER_CODE_MODEL = REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift 2 iso-8859-10 character code model. U+008E */
static char* SINGLE_SHIFT_2_ISO_8859_10_CHARACTER_CODE_MODEL = SINGLE_SHIFT_2_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift 3 iso-8859-10 character code model. U+008F */
static char* SINGLE_SHIFT_3_ISO_8859_10_CHARACTER_CODE_MODEL = SINGLE_SHIFT_3_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control string iso-8859-10 character code model. U+0090 */
static char* DEVICE_CONTROL_STRING_ISO_8859_10_CHARACTER_CODE_MODEL = DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use 1 iso-8859-10 character code model. U+0091 */
static char* PRIVATE_USE_1_ISO_8859_10_CHARACTER_CODE_MODEL = PRIVATE_USE_1_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use 2 iso-8859-10 character code model. U+0092 */
static char* PRIVATE_USE_2_ISO_8859_10_CHARACTER_CODE_MODEL = PRIVATE_USE_2_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The set transmit state iso-8859-10 character code model. U+0093 */
static char* SET_TRANSMIT_STATE_ISO_8859_10_CHARACTER_CODE_MODEL = SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel character iso-8859-10 character code model. U+0094 */
static char* CANCEL_CHARACTER_ISO_8859_10_CHARACTER_CODE_MODEL = CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The message waiting iso-8859-10 character code model. U+0095 */
static char* MESSAGE_WAITING_ISO_8859_10_CHARACTER_CODE_MODEL = MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of protected area iso-8859-10 character code model. U+0096 */
static char* START_OF_PROTECTED_AREA_ISO_8859_10_CHARACTER_CODE_MODEL = START_OF_PROTECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of protected area iso-8859-10 character code model. U+0097 */
static char* END_OF_PROTECTED_AREA_ISO_8859_10_CHARACTER_CODE_MODEL = END_OF_PROTECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of string iso-8859-10 character code model. U+0098 */
static char* START_OF_STRING_ISO_8859_10_CHARACTER_CODE_MODEL = START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The single graphic character introducer iso-8859-10 character code model. U+0099
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429.
 */
static char* SINGLE_GRAPHIC_CHARACTER_INTRODUCER_ISO_8859_10_CHARACTER_CODE_MODEL = SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single character introducer iso-8859-10 character code model. U+009A */
static char* SINGLE_CHARACTER_INTRODUCER_ISO_8859_10_CHARACTER_CODE_MODEL = SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The control sequence introducer iso-8859-10 character code model. U+009B */
static char* CONTROL_SEQUENCE_INTRODUCER_ISO_8859_10_CHARACTER_CODE_MODEL = CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The string terminator iso-8859-10 character code model. U+009C */
static char* STRING_TERMINATOR_ISO_8859_10_CHARACTER_CODE_MODEL = STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The operating system command iso-8859-10 character code model. U+009D */
static char* OPERATING_SYSTEM_COMMAND_ISO_8859_10_CHARACTER_CODE_MODEL = OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The privacy message iso-8859-10 character code model. U+009E */
static char* PRIVACY_MESSAGE_ISO_8859_10_CHARACTER_CODE_MODEL = PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The application programme command iso-8859-10 character code model. U+009F */
static char* APPLICATION_PROGRAMME_COMMAND_ISO_8859_10_CHARACTER_CODE_MODEL = APPLICATION_PROGRAMME_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0xA0-0xFF.
//

//?? TODO: Continue here ...

/** The TODO iso-8859-10 character code model. U+00TODO */
//?? static char TODO_ISO_8859_10_CHARACTER_CODE_MODEL_ARRAY[] = {0xTODO};
//?? static char* TODO_ISO_8859_10_CHARACTER_CODE_MODEL = TODO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_10_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
