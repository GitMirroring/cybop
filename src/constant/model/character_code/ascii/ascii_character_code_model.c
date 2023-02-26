/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef ASCII_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define ASCII_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

//
// A "Character Set" consists of three parts:
// - Character Repertoire: a, b, c etc., e.g. ISO 8859-1 with 256 characters and Unicode with ~ 1 Mio. characters
// - Character Code: table assigning numbers, e.g. a = 97, b = 98, c = 99 etc.
// - Character Encoding: storing code numbers in Bytes, e.g. 97 = 01100001, 98 = 01100010, 99 = 01100011 etc.
//

//
// The American Standard Code for Information Interchange (ASCII)
// is a character-encoding scheme originally based on the English alphabet.
// ASCII codes represent text in computers, communications equipment,
// and other devices that use text.
// Most modern character-encoding schemes are based on ASCII,
// though they support many additional characters.
//
// ASCII includes definitions for 128 characters:
// - 33 are non-printing control characters (many now obsolete)
//   that affect how text and space is processed;
// - 95 printable characters, including the space
//   (which is considered an invisible graphic).
//
// The IANA prefers the name US-ASCII to avoid ambiguity.
// ASCII was the most commonly used character encoding on the
// World Wide Web (WWW) until December 2007, when it was surpassed by UTF-8.
//
// This file contains ASCII character code constants.
//

//
// The non-printable control characters in range 0x00-0x1F
//

/**
 * The null ascii character code model. U+0000
 * It is used as string termination in the C programming language.
 */
static unsigned char NULL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x00 };
static unsigned char* NULL_ASCII_CHARACTER_CODE_MODEL = NULL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The start of heading ascii character code model. U+0001 */
static unsigned char START_OF_HEADING_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x01 };
static unsigned char* START_OF_HEADING_ASCII_CHARACTER_CODE_MODEL = START_OF_HEADING_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The start of text ascii character code model. U+0002 */
static unsigned char START_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x02 };
static unsigned char* START_OF_TEXT_ASCII_CHARACTER_CODE_MODEL = START_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of text ascii character code model. U+0003 */
static unsigned char END_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x03 };
static unsigned char* END_OF_TEXT_ASCII_CHARACTER_CODE_MODEL = END_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission ascii character code model. U+0004 */
static unsigned char END_OF_TRANSMISSION_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x04 };
static unsigned char* END_OF_TRANSMISSION_ASCII_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The enquiry ascii character code model. U+0005 */
static unsigned char ENQUIRY_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x05 };
static unsigned char* ENQUIRY_ASCII_CHARACTER_CODE_MODEL = ENQUIRY_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The acknowledge ascii character code model. U+0006 */
static unsigned char ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x06 };
static unsigned char* ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL = ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The bell ascii character code model. U+0007 */
static unsigned char BELL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x07 };
static unsigned char* BELL_ASCII_CHARACTER_CODE_MODEL = BELL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The backspace ascii character code model. U+0008 */
static unsigned char BACKSPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x08 };
static unsigned char* BACKSPACE_ASCII_CHARACTER_CODE_MODEL = BACKSPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The character tabulation ascii character code model.
 *
 * U+0009
 *
 * Alias names:
 * HORIZONTAL TAB
 */
static unsigned char CHARACTER_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x09 };
static unsigned char* CHARACTER_TABULATION_ASCII_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The line feed ascii character code model.
 *
 * U+000A
 *
 * Alias names:
 * LINE FEED (LF)
 * NEW LINE (NL)
 * END OF LINE (EOL)
 */
static unsigned char LINE_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0A };
static unsigned char* LINE_FEED_ASCII_CHARACTER_CODE_MODEL = LINE_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The line tabulation ascii character code model.
 *
 * U+000B
 *
 * Alias names:
 * VERTICAL TAB
 */
static unsigned char LINE_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0B };
static unsigned char* LINE_TABULATION_ASCII_CHARACTER_CODE_MODEL = LINE_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The form feed ascii character code model.
 *
 * U+000C
 *
 * Alias names:
 * NEW PAGE (NP)
 */
static unsigned char FORM_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0C };
static unsigned char* FORM_FEED_ASCII_CHARACTER_CODE_MODEL = FORM_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The carriage return (enter) ascii character code model. U+000D */
static unsigned char CARRIAGE_RETURN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0D };
static unsigned char* CARRIAGE_RETURN_ASCII_CHARACTER_CODE_MODEL = CARRIAGE_RETURN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The shift out ascii character code model. U+000E */
static unsigned char SHIFT_OUT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0E };
static unsigned char* SHIFT_OUT_ASCII_CHARACTER_CODE_MODEL = SHIFT_OUT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The shift in ascii character code model. U+000F */
static unsigned char SHIFT_IN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x0F };
static unsigned char* SHIFT_IN_ASCII_CHARACTER_CODE_MODEL = SHIFT_IN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The data link escape ascii character code model. U+0010 */
static unsigned char DATA_LINK_ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x10 };
static unsigned char* DATA_LINK_ESCAPE_ASCII_CHARACTER_CODE_MODEL = DATA_LINK_ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control one ascii character code model. U+0011 */
static unsigned char DEVICE_CONTROL_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x11 };
static unsigned char* DEVICE_CONTROL_ONE_ASCII_CHARACTER_CODE_MODEL = DEVICE_CONTROL_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control two ascii character code model. U+0012 */
static unsigned char DEVICE_CONTROL_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x12 };
static unsigned char* DEVICE_CONTROL_TWO_ASCII_CHARACTER_CODE_MODEL = DEVICE_CONTROL_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control three ascii character code model. U+0013 */
static unsigned char DEVICE_CONTROL_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x13 };
static unsigned char* DEVICE_CONTROL_THREE_ASCII_CHARACTER_CODE_MODEL = DEVICE_CONTROL_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control four ascii character code model. U+0014 */
static unsigned char DEVICE_CONTROL_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x14 };
static unsigned char* DEVICE_CONTROL_FOUR_ASCII_CHARACTER_CODE_MODEL = DEVICE_CONTROL_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The negative acknowledge ascii character code model. U+0015 */
static unsigned char NEGATIVE_ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x15 };
static unsigned char* NEGATIVE_ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL = NEGATIVE_ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The synchronous idle ascii character code model. U+0016 */
static unsigned char SYNCHRONOUS_IDLE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x16 };
static unsigned char* SYNCHRONOUS_IDLE_ASCII_CHARACTER_CODE_MODEL = SYNCHRONOUS_IDLE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission block ascii character code model. U+0017 */
static unsigned char END_OF_TRANSMISSION_BLOCK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x17 };
static unsigned char* END_OF_TRANSMISSION_BLOCK_ASCII_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_BLOCK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel ascii character code model. U+0018 */
static unsigned char CANCEL_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x18 };
static unsigned char* CANCEL_ASCII_CHARACTER_CODE_MODEL = CANCEL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of medium ascii character code model. U+0019 */
static unsigned char END_OF_MEDIUM_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x19 };
static unsigned char* END_OF_MEDIUM_ASCII_CHARACTER_CODE_MODEL = END_OF_MEDIUM_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The substitute ascii character code model. U+001A */
static unsigned char SUBSTITUTE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1A };
static unsigned char* SUBSTITUTE_ASCII_CHARACTER_CODE_MODEL = SUBSTITUTE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The escape ascii character code model. U+001B */
static unsigned char ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1B };
static unsigned char* ESCAPE_ASCII_CHARACTER_CODE_MODEL = ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The file separator ascii character code model. U+001C */
static unsigned char FILE_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1C };
static unsigned char* FILE_SEPARATOR_ASCII_CHARACTER_CODE_MODEL = FILE_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The group separator ascii character code model. U+001D */
static unsigned char GROUP_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1D };
static unsigned char* GROUP_SEPARATOR_ASCII_CHARACTER_CODE_MODEL = GROUP_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The record separator ascii character code model. U+001E */
static unsigned char RECORD_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1E };
static unsigned char* RECORD_SEPARATOR_ASCII_CHARACTER_CODE_MODEL = RECORD_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The unit separator ascii character code model. U+001F */
static unsigned char UNIT_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x1F };
static unsigned char* UNIT_SEPARATOR_ASCII_CHARACTER_CODE_MODEL = UNIT_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0x20-0x7E
//

/** The space ascii character code model. U+0020 */
static unsigned char SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x20 };
static unsigned char* SPACE_ASCII_CHARACTER_CODE_MODEL = SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The exclamation mark ascii character code model. U+0021 */
static unsigned char EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x21 };
static unsigned char* EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL = EXCLAMATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The quotation mark ascii character code model. U+0022 */
static unsigned char QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x22 };
static unsigned char* QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL = QUOTATION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The number sign ascii character code model. U+0023 */
static unsigned char NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x23 };
static unsigned char* NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL = NUMBER_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The dollar sign ascii character code model. U+0024 */
static unsigned char DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x24 };
static unsigned char* DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL = DOLLAR_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The percent sign ascii character code model. U+0025 */
static unsigned char PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x25 };
static unsigned char* PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL = PERCENT_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The ampersand ascii character code model. U+0026 */
static unsigned char AMPERSAND_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x26 };
static unsigned char* AMPERSAND_ASCII_CHARACTER_CODE_MODEL = AMPERSAND_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The apostrophe ascii character code model. U+0027 */
static unsigned char APOSTROPHE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x27 };
static unsigned char* APOSTROPHE_ASCII_CHARACTER_CODE_MODEL = APOSTROPHE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left parenthesis ascii character code model. U+0028 */
static unsigned char LEFT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x28 };
static unsigned char* LEFT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL = LEFT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right parenthesis ascii character code model. U+0029 */
static unsigned char RIGHT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x29 };
static unsigned char* RIGHT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL = RIGHT_PARENTHESIS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The asterisk ascii character code model. U+002A */
static unsigned char ASTERISK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2A };
static unsigned char* ASTERISK_ASCII_CHARACTER_CODE_MODEL = ASTERISK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The plus sign ascii character code model. U+002B */
static unsigned char PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2B };
static unsigned char* PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL = PLUS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The comma ascii character code model. U+002C */
static unsigned char COMMA_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2C };
static unsigned char* COMMA_ASCII_CHARACTER_CODE_MODEL = COMMA_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The hyphen minus ascii character code model.
 *
 * Unicode category: Punctuation, Dash
 * Unicode: U+002D
 * UTF-8: 0x2D
 * Octal escaped UTF-8: \055
 * Decimal entity reference: &#45;
 *
 * Alias names:
 * hyphen or minus sign
 *
 * Notes:
 * used for either hyphen or minus sign
 *
 * See also:
 * U+2010 HYPHEN
 * U+2011 NON-BREAKING HYPHEN
 * U+2012 FIGURE DASH
 * U+2013 EN DASH
 * U+2212 MINUS SIGN
 */
static unsigned char HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2D };
static unsigned char* HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL = HYPHEN_MINUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The full stop ascii character code model. U+002E */
static unsigned char FULL_STOP_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2E };
static unsigned char* FULL_STOP_ASCII_CHARACTER_CODE_MODEL = FULL_STOP_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The solidus ascii character code model. U+002F */
static unsigned char SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x2F };
static unsigned char* SOLIDUS_ASCII_CHARACTER_CODE_MODEL = SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit zero ascii character code model. U+0030 */
static unsigned char DIGIT_ZERO_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x30 };
static unsigned char* DIGIT_ZERO_ASCII_CHARACTER_CODE_MODEL = DIGIT_ZERO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit one ascii character code model. U+0031 */
static unsigned char DIGIT_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x31 };
static unsigned char* DIGIT_ONE_ASCII_CHARACTER_CODE_MODEL = DIGIT_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit two ascii character code model. U+0032 */
static unsigned char DIGIT_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x32 };
static unsigned char* DIGIT_TWO_ASCII_CHARACTER_CODE_MODEL = DIGIT_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit three ascii character code model. U+0033 */
static unsigned char DIGIT_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x33 };
static unsigned char* DIGIT_THREE_ASCII_CHARACTER_CODE_MODEL = DIGIT_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit four ascii character code model. U+0034 */
static unsigned char DIGIT_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x34 };
static unsigned char* DIGIT_FOUR_ASCII_CHARACTER_CODE_MODEL = DIGIT_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit five ascii character code model. U+0035 */
static unsigned char DIGIT_FIVE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x35 };
static unsigned char* DIGIT_FIVE_ASCII_CHARACTER_CODE_MODEL = DIGIT_FIVE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit six ascii character code model. U+0036 */
static unsigned char DIGIT_SIX_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x36 };
static unsigned char* DIGIT_SIX_ASCII_CHARACTER_CODE_MODEL = DIGIT_SIX_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit seven ascii character code model. U+0037 */
static unsigned char DIGIT_SEVEN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x37 };
static unsigned char* DIGIT_SEVEN_ASCII_CHARACTER_CODE_MODEL = DIGIT_SEVEN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit eight ascii character code model. U+0038 */
static unsigned char DIGIT_EIGHT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x38 };
static unsigned char* DIGIT_EIGHT_ASCII_CHARACTER_CODE_MODEL = DIGIT_EIGHT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The digit nine ascii character code model. U+0039 */
static unsigned char DIGIT_NINE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x39 };
static unsigned char* DIGIT_NINE_ASCII_CHARACTER_CODE_MODEL = DIGIT_NINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The colon ascii character code model. U+003A */
static unsigned char COLON_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3A };
static unsigned char* COLON_ASCII_CHARACTER_CODE_MODEL = COLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The semicolon ascii character code model. U+003B */
static unsigned char SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3B };
static unsigned char* SEMICOLON_ASCII_CHARACTER_CODE_MODEL = SEMICOLON_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The less than sign ascii character code model. U+003C */
static unsigned char LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3C };
static unsigned char* LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL = LESS_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The equals sign ascii character code model.
 *
 * Unicode category: Symbol, Math
 * Unicode: U+003D
 * UTF-8: 0x3D
 * Octal escaped UTF-8: \075
 * Decimal entity reference: &#61;
 *
 * Notes:
 * other related characters: U+2241 NOT TILDE-U+2263 STRICTLY EQUIVALENT TO
 *
 * See also:
 * U+2260 NOT EQUAL TO
 * U+2261 IDENTICAL TO
 */
static unsigned char EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3D };
static unsigned char* EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL = EQUALS_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The greater than sign ascii character code model. U+003E */
static unsigned char GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3E };
static unsigned char* GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL = GREATER_THAN_SIGN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The question mark ascii character code model. U+003F */
static unsigned char QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x3F };
static unsigned char* QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL = QUESTION_MARK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The commercial at ascii character code model. U+0040 */
static unsigned char COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x40 };
static unsigned char* COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL = COMMERCIAL_AT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter a ascii character code model. U+0041 */
static unsigned char LATIN_CAPITAL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x41 };
static unsigned char* LATIN_CAPITAL_LETTER_A_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter b ascii character code model. U+0042 */
static unsigned char LATIN_CAPITAL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x42 };
static unsigned char* LATIN_CAPITAL_LETTER_B_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter c ascii character code model. U+0043 */
static unsigned char LATIN_CAPITAL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x43 };
static unsigned char* LATIN_CAPITAL_LETTER_C_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter d ascii character code model. U+0044 */
static unsigned char LATIN_CAPITAL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x44 };
static unsigned char* LATIN_CAPITAL_LETTER_D_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter e ascii character code model. U+0045 */
static unsigned char LATIN_CAPITAL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x45 };
static unsigned char* LATIN_CAPITAL_LETTER_E_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter f ascii character code model. U+0046 */
static unsigned char LATIN_CAPITAL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x46 };
static unsigned char* LATIN_CAPITAL_LETTER_F_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter g ascii character code model. U+0047 */
static unsigned char LATIN_CAPITAL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x47 };
static unsigned char* LATIN_CAPITAL_LETTER_G_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter h ascii character code model. U+0048 */
static unsigned char LATIN_CAPITAL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x48 };
static unsigned char* LATIN_CAPITAL_LETTER_H_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter i ascii character code model. U+0049 */
static unsigned char LATIN_CAPITAL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x49 };
static unsigned char* LATIN_CAPITAL_LETTER_I_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter j ascii character code model. U+004A */
static unsigned char LATIN_CAPITAL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4A };
static unsigned char* LATIN_CAPITAL_LETTER_J_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter k ascii character code model. U+004B */
static unsigned char LATIN_CAPITAL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4B };
static unsigned char* LATIN_CAPITAL_LETTER_K_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter l ascii character code model. U+004C */
static unsigned char LATIN_CAPITAL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4C };
static unsigned char* LATIN_CAPITAL_LETTER_L_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter m ascii character code model. U+004D */
static unsigned char LATIN_CAPITAL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4D };
static unsigned char* LATIN_CAPITAL_LETTER_M_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter n ascii character code model. U+004E */
static unsigned char LATIN_CAPITAL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4E };
static unsigned char* LATIN_CAPITAL_LETTER_N_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter o ascii character code model. U+004F */
static unsigned char LATIN_CAPITAL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x4F };
static unsigned char* LATIN_CAPITAL_LETTER_O_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter p ascii character code model. U+0050 */
static unsigned char LATIN_CAPITAL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x50 };
static unsigned char* LATIN_CAPITAL_LETTER_P_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter q ascii character code model. U+0051 */
static unsigned char LATIN_CAPITAL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x51 };
static unsigned char* LATIN_CAPITAL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter r ascii character code model. U+0052 */
static unsigned char LATIN_CAPITAL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x52 };
static unsigned char* LATIN_CAPITAL_LETTER_R_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter s ascii character code model. U+0053 */
static unsigned char LATIN_CAPITAL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x53 };
static unsigned char* LATIN_CAPITAL_LETTER_S_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter t ascii character code model. U+0054 */
static unsigned char LATIN_CAPITAL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x54 };
static unsigned char* LATIN_CAPITAL_LETTER_T_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter u ascii character code model. U+0055 */
static unsigned char LATIN_CAPITAL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x55 };
static unsigned char* LATIN_CAPITAL_LETTER_U_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter v ascii character code model. U+0056 */
static unsigned char LATIN_CAPITAL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x56 };
static unsigned char* LATIN_CAPITAL_LETTER_V_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter w ascii character code model. U+0057 */
static unsigned char LATIN_CAPITAL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x57 };
static unsigned char* LATIN_CAPITAL_LETTER_W_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter x ascii character code model. U+0058 */
static unsigned char LATIN_CAPITAL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x58 };
static unsigned char* LATIN_CAPITAL_LETTER_X_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter y ascii character code model. U+0059 */
static unsigned char LATIN_CAPITAL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x59 };
static unsigned char* LATIN_CAPITAL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin capital letter z ascii character code model. U+005A */
static unsigned char LATIN_CAPITAL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5A };
static unsigned char* LATIN_CAPITAL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL = LATIN_CAPITAL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left square bracket ascii character code model. U+005B */
static unsigned char LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5B };
static unsigned char* LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL = LEFT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse solidus ascii character code model. U+005C */
static unsigned char REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5C };
static unsigned char* REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL = REVERSE_SOLIDUS_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right square bracket ascii character code model. U+005D */
static unsigned char RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5D };
static unsigned char* RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL = RIGHT_SQUARE_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The circumflex accent ascii character code model. U+005E */
static unsigned char CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5E };
static unsigned char* CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL = CIRCUMFLEX_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The low line ascii character code model. U+005F */
static unsigned char LOW_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x5F };
static unsigned char* LOW_LINE_ASCII_CHARACTER_CODE_MODEL = LOW_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The grave accent ascii character code model. U+0060 */
static unsigned char GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x60 };
static unsigned char* GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL = GRAVE_ACCENT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter a ascii character code model. U+0061 */
static unsigned char LATIN_SMALL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x61 };
static unsigned char* LATIN_SMALL_LETTER_A_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_A_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter b ascii character code model. U+0062 */
static unsigned char LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x62 };
static unsigned char* LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter c ascii character code model. U+0063 */
static unsigned char LATIN_SMALL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x63 };
static unsigned char* LATIN_SMALL_LETTER_C_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_C_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter d ascii character code model. U+0064 */
static unsigned char LATIN_SMALL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x64 };
static unsigned char* LATIN_SMALL_LETTER_D_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_D_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter e ascii character code model. U+0065 */
static unsigned char LATIN_SMALL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x65 };
static unsigned char* LATIN_SMALL_LETTER_E_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_E_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter f ascii character code model. U+0066 */
static unsigned char LATIN_SMALL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x66 };
static unsigned char* LATIN_SMALL_LETTER_F_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_F_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter g ascii character code model. U+0067 */
static unsigned char LATIN_SMALL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x67 };
static unsigned char* LATIN_SMALL_LETTER_G_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_G_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter h ascii character code model. U+0068 */
static unsigned char LATIN_SMALL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x68 };
static unsigned char* LATIN_SMALL_LETTER_H_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_H_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter i ascii character code model. U+0069 */
static unsigned char LATIN_SMALL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x69 };
static unsigned char* LATIN_SMALL_LETTER_I_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_I_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter j ascii character code model. U+006A */
static unsigned char LATIN_SMALL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6A };
static unsigned char* LATIN_SMALL_LETTER_J_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_J_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter k ascii character code model. U+006B */
static unsigned char LATIN_SMALL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6B };
static unsigned char* LATIN_SMALL_LETTER_K_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_K_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter l ascii character code model. U+006C */
static unsigned char LATIN_SMALL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6C };
static unsigned char* LATIN_SMALL_LETTER_L_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_L_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter m ascii character code model. U+006D */
static unsigned char LATIN_SMALL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6D };
static unsigned char* LATIN_SMALL_LETTER_M_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_M_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter n ascii character code model. U+006E */
static unsigned char LATIN_SMALL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6E };
static unsigned char* LATIN_SMALL_LETTER_N_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_N_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter o ascii character code model. U+006F */
static unsigned char LATIN_SMALL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x6F };
static unsigned char* LATIN_SMALL_LETTER_O_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_O_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter p ascii character code model. U+0070 */
static unsigned char LATIN_SMALL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x70 };
static unsigned char* LATIN_SMALL_LETTER_P_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_P_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter q ascii character code model. U+0071 */
static unsigned char LATIN_SMALL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x71 };
static unsigned char* LATIN_SMALL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Q_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter r ascii character code model. U+0072 */
static unsigned char LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x72 };
static unsigned char* LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter s ascii character code model. U+0073 */
static unsigned char LATIN_SMALL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x73 };
static unsigned char* LATIN_SMALL_LETTER_S_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_S_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter t ascii character code model. U+0074 */
static unsigned char LATIN_SMALL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x74 };
static unsigned char* LATIN_SMALL_LETTER_T_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_T_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter u ascii character code model. U+0075 */
static unsigned char LATIN_SMALL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x75 };
static unsigned char* LATIN_SMALL_LETTER_U_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_U_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter v ascii character code model. U+0076 */
static unsigned char LATIN_SMALL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x76 };
static unsigned char* LATIN_SMALL_LETTER_V_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_V_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter w ascii character code model. U+0077 */
static unsigned char LATIN_SMALL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x77 };
static unsigned char* LATIN_SMALL_LETTER_W_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_W_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter x ascii character code model. U+0078 */
static unsigned char LATIN_SMALL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x78 };
static unsigned char* LATIN_SMALL_LETTER_X_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_X_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter y ascii character code model. U+0079 */
static unsigned char LATIN_SMALL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x79 };
static unsigned char* LATIN_SMALL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Y_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The latin small letter z ascii character code model. U+007A */
static unsigned char LATIN_SMALL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7A };
static unsigned char* LATIN_SMALL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL = LATIN_SMALL_LETTER_Z_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The left curly bracket ascii character code model. U+007B */
static unsigned char LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7B };
static unsigned char* LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL = LEFT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The vertical line ascii character code model.
 *
 * Unicode category: Symbol, Math
 * Unicode: U+007C
 * UTF-8: 0x7C
 * Octal escaped UTF-8: \174
 * Decimal entity reference: &#124;
 *
 * Alias names:
 * VERTICAL BAR
 *
 * Notes:
 * used in pairs to indicate absolute value
 *
 * See also:
 * U+01C0 LATIN LETTER DENTAL CLICK
 * U+05C0 HEBREW PUNCTUATION PASEQ
 * U+2223 DIVIDES
 * U+2758 LIGHT VERTICAL BAR
 */
static unsigned char VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7C };
static unsigned char* VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL = VERTICAL_LINE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The right curly bracket ascii character code model. U+007D */
static unsigned char RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7D };
static unsigned char* RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL = RIGHT_CURLY_BRACKET_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The tilde ascii character code model. U+007E */
static unsigned char TILDE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7E };
static unsigned char* TILDE_ASCII_CHARACTER_CODE_MODEL = TILDE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

//
// The non-printable control character 0x7F
//

/** The delete ascii character code model. U+007F */
static unsigned char DELETE_ASCII_CHARACTER_CODE_MODEL_ARRAY[] = { 0x7F };
static unsigned char* DELETE_ASCII_CHARACTER_CODE_MODEL = DELETE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/* ASCII_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
