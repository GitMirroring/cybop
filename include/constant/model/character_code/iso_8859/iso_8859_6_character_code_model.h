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
 * @author Franziska Wehner
 */

#ifndef ISO_8859_6_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define ISO_8859_6_CHARACTER_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
// This file contains ISO-8859-6 character code constants:
// Latin/Arabic
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The non-printable control characters in range 0x80-0x9F
// which are defined by "ISO-8859" but not "ISO/IEC 8859"
//

/**
 * The padding character iso-8859-6 character code model. U+0080
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* PADDING_CHARACTER_ISO_8859_6_CHARACTER_CODE_MODEL = PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The high octet preset iso-8859-6 character code model. U+0081
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* HIGH_OCTET_PRESET_ISO_8859_6_CHARACTER_CODE_MODEL = HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The break permitted here iso-8859-6 character code model. U+0082 */
static unsigned char* BREAK_PERMITTED_HERE_ISO_8859_6_CHARACTER_CODE_MODEL = BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The no break here iso-8859-6 character code model. U+0083 */
static unsigned char* NO_BREAK_HERE_ISO_8859_6_CHARACTER_CODE_MODEL = NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The index iso-8859-6 character code model. U+0084 */
static unsigned char* INDEX_ISO_8859_6_CHARACTER_CODE_MODEL = INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The next line iso-8859-6 character code model. U+0085 */
static unsigned char* NEXT_LINE_ISO_8859_6_CHARACTER_CODE_MODEL = NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of selected area iso-8859-6 character code model. U+0086 */
static unsigned char* START_OF_SELECTED_AREA_ISO_8859_6_CHARACTER_CODE_MODEL = START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of selected area iso-8859-6 character code model. U+0087 */
static unsigned char* END_OF_SELECTED_AREA_ISO_8859_6_CHARACTER_CODE_MODEL = END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation set iso-8859-6 character code model. U+0088 */
static unsigned char* CHARACTER_TABULATION_SET_ISO_8859_6_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation with justification iso-8859-6 character code model. U+0089 */
static unsigned char* CHARACTER_TABULATION_WITH_JUSTIFICATION_ISO_8859_6_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation set iso-8859-6 character code model. U+008A */
static unsigned char* LINE_TABULATION_SET_ISO_8859_6_CHARACTER_CODE_MODEL = LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line forward iso-8859-6 character code model. U+008B */
static unsigned char* PARTIAL_LINE_FORWARD_ISO_8859_6_CHARACTER_CODE_MODEL = PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line backward iso-8859-6 character code model. U+008C */
static unsigned char* PARTIAL_LINE_BACKWARD_ISO_8859_6_CHARACTER_CODE_MODEL = PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse line feed iso-8859-6 character code model. U+008D */
static unsigned char* REVERSE_LINE_FEED_ISO_8859_6_CHARACTER_CODE_MODEL = REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift two iso-8859-6 character code model. U+008E */
static unsigned char* SINGLE_SHIFT_TWO_ISO_8859_6_CHARACTER_CODE_MODEL = SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift three iso-8859-6 character code model. U+008F */
static unsigned char* SINGLE_SHIFT_THREE_ISO_8859_6_CHARACTER_CODE_MODEL = SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control string iso-8859-6 character code model. U+0090 */
static unsigned char* DEVICE_CONTROL_STRING_ISO_8859_6_CHARACTER_CODE_MODEL = DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use one iso-8859-6 character code model. U+0091 */
static unsigned char* PRIVATE_USE_ONE_ISO_8859_6_CHARACTER_CODE_MODEL = PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use two iso-8859-6 character code model. U+0092 */
static unsigned char* PRIVATE_USE_TWO_ISO_8859_6_CHARACTER_CODE_MODEL = PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The set transmit state iso-8859-6 character code model. U+0093 */
static unsigned char* SET_TRANSMIT_STATE_ISO_8859_6_CHARACTER_CODE_MODEL = SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel character iso-8859-6 character code model. U+0094 */
static unsigned char* CANCEL_CHARACTER_ISO_8859_6_CHARACTER_CODE_MODEL = CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The message waiting iso-8859-6 character code model. U+0095 */
static unsigned char* MESSAGE_WAITING_ISO_8859_6_CHARACTER_CODE_MODEL = MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of guarded area iso-8859-6 character code model. U+0096 */
static unsigned char* START_OF_GUARDED_AREA_ISO_8859_6_CHARACTER_CODE_MODEL = START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of guarded area iso-8859-6 character code model. U+0097 */
static unsigned char* END_OF_GUARDED_AREA_ISO_8859_6_CHARACTER_CODE_MODEL = END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of string iso-8859-6 character code model. U+0098 */
static unsigned char* START_OF_STRING_ISO_8859_6_CHARACTER_CODE_MODEL = START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The single graphic character introducer iso-8859-6 character code model. U+0099
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429.
 */
static unsigned char* SINGLE_GRAPHIC_CHARACTER_INTRODUCER_ISO_8859_6_CHARACTER_CODE_MODEL = SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single character introducer iso-8859-6 character code model. U+009A */
static unsigned char* SINGLE_CHARACTER_INTRODUCER_ISO_8859_6_CHARACTER_CODE_MODEL = SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The control sequence introducer iso-8859-6 character code model. U+009B */
static unsigned char* CONTROL_SEQUENCE_INTRODUCER_ISO_8859_6_CHARACTER_CODE_MODEL = CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The string terminator iso-8859-6 character code model. U+009C */
static unsigned char* STRING_TERMINATOR_ISO_8859_6_CHARACTER_CODE_MODEL = STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The operating system command iso-8859-6 character code model. U+009D */
static unsigned char* OPERATING_SYSTEM_COMMAND_ISO_8859_6_CHARACTER_CODE_MODEL = OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The privacy message iso-8859-6 character code model. U+009E */
static unsigned char* PRIVACY_MESSAGE_ISO_8859_6_CHARACTER_CODE_MODEL = PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The application program commandiso-8859-6 character code model. U+009F */
static unsigned char* APPLICATION_PROGRAM_COMMAND_ISO_8859_6_CHARACTER_CODE_MODEL = APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0xA0-0xFF
//

/** The no-break space iso-8859-6 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA0 };
static unsigned char* NO_BREAK_SPACE_ISO_8859_6_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The currency sign iso-8859-6 character code model. U+00A4 */
static unsigned char CURRENCY_SIGN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA4 };
static unsigned char* CURRENCY_SIGN_ISO_8859_6_CHARACTER_CODE_MODEL = CURRENCY_SIGN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic comma iso-8859-6 character code model. U+00AC */
static unsigned char ARABIC_COMMA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAC };
static unsigned char* ARABIC_COMMA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_COMMA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The soft hyphen iso-8859-6 character code model. U+00AD */
static unsigned char SOFT_HYPHEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAD };
static unsigned char* SOFT_HYPHEN_ISO_8859_6_CHARACTER_CODE_MODEL = SOFT_HYPHEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic semicolon iso-8859-6 character code model. U+00BB */
static unsigned char ARABIC_SEMICOLON_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBB };
static unsigned char* ARABIC_SEMICOLON_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_SEMICOLON_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic question mark iso-8859-6 character code model. U+00BF */
static unsigned char ARABIC_QUESTION_MARK_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBF };
static unsigned char* ARABIC_QUESTION_MARK_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_QUESTION_MARK_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter hamza iso-8859-6 character code model. U+00C1 */
static unsigned char ARABIC_LETTER_HAMZA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC1 };
static unsigned char* ARABIC_LETTER_HAMZA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_HAMZA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter alef with madda above iso-8859-6 character code model. U+00C2 */
static unsigned char ARABIC_LETTER_ALEF_WITH_MADDA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC2 };
static unsigned char* ARABIC_LETTER_ALEF_WITH_MADDA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ALEF_WITH_MADDA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter alef with hamza above iso-8859-6 character code model. U+00C3 */
static unsigned char ARABIC_LETTER_ALEF_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC3 };
static unsigned char* ARABIC_LETTER_ALEF_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ALEF_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter waw with hamza above iso-8859-6 character code model. U+00C4 */
static unsigned char ARABIC_LETTER_WAW_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC4 };
static unsigned char* ARABIC_LETTER_WAW_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_WAW_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter alef with hamza below iso-8859-6 character code model. U+00C5 */
static unsigned char ARABIC_LETTER_ALEF_WITH_HAMZA_BELOW_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC5 };
static unsigned char* ARABIC_LETTER_ALEF_WITH_HAMZA_BELOW_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ALEF_WITH_HAMZA_BELOW_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter yeh with hamza above iso-8859-6 character code model. U+00C6 */
static unsigned char ARABIC_LETTER_YEH_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC6 };
static unsigned char* ARABIC_LETTER_YEH_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_YEH_WITH_HAMZA_ABOVE_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter alef iso-8859-6 character code model. U+00C7 */
static unsigned char ARABIC_LETTER_ALEF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC7 };
static unsigned char* ARABIC_LETTER_ALEF_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ALEF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter beh iso-8859-6 character code model. U+00C8 */
static unsigned char ARABIC_LETTER_BEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC8 };
static unsigned char* ARABIC_LETTER_BEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_BEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter teh marbuta iso-8859-6 character code model. U+00C9 */
static unsigned char ARABIC_LETTER_TEH_MARBUTA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xC9 };
static unsigned char* ARABIC_LETTER_TEH_MARBUTA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_TEH_MARBUTA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter teh iso-8859-6 character code model. U+00CA */
static unsigned char ARABIC_LETTER_TEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCA };
static unsigned char* ARABIC_LETTER_TEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_TEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter theh iso-8859-6 character code model. U+00CB */
static unsigned char ARABIC_LETTER_THEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCB };
static unsigned char* ARABIC_LETTER_THEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_THEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter jeem iso-8859-6 character code model. U+00CC */
static unsigned char ARABIC_LETTER_JEEM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCC };
static unsigned char* ARABIC_LETTER_JEEM_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_JEEM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter hah iso-8859-6 character code model. U+00CD */
static unsigned char ARABIC_LETTER_HAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCD };
static unsigned char* ARABIC_LETTER_HAH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_HAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter khah iso-8859-6 character code model. U+00CE */
static unsigned char ARABIC_LETTER_KHAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCE };
static unsigned char* ARABIC_LETTER_KHAH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_KHAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter dal iso-8859-6 character code model. U+00CF */
static unsigned char ARABIC_LETTER_DAL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xCF };
static unsigned char* ARABIC_LETTER_DAL_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_DAL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter thal iso-8859-6 character code model. U+00D0 */
static unsigned char ARABIC_LETTER_THAL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD0 };
static unsigned char* ARABIC_LETTER_THAL_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_THAL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter reh iso-8859-6 character code model. U+00D1 */
static unsigned char ARABIC_LETTER_REH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD1 };
static unsigned char* ARABIC_LETTER_REH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_REH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter zain iso-8859-6 character code model. U+00D2 */
static unsigned char ARABIC_LETTER_ZAIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD2 };
static unsigned char* ARABIC_LETTER_ZAIN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ZAIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter seen iso-8859-6 character code model. U+00D3 */
static unsigned char ARABIC_LETTER_SEEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD3 };
static unsigned char* ARABIC_LETTER_SEEN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_SEEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter sheen iso-8859-6 character code model. U+00D4 */
static unsigned char ARABIC_LETTER_SHEEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD4 };
static unsigned char* ARABIC_LETTER_SHEEN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_SHEEN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter said iso-8859-6 character code model. U+00D5 */
static unsigned char ARABIC_LETTER_SAD_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD5 };
static unsigned char* ARABIC_LETTER_SAD_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_SAD_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter dad iso-8859-6 character code model. U+00D6 */
static unsigned char ARABIC_LETTER_DAD_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD6 };
static unsigned char* ARABIC_LETTER_DAD_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_DAD_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter tah iso-8859-6 character code model. U+00D7 */
static unsigned char ARABIC_LETTER_TAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD7 };
static unsigned char* ARABIC_LETTER_TAH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_TAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter zah iso-8859-6 character code model. U+00D8 */
static unsigned char ARABIC_LETTER_ZAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD8 };
static unsigned char* ARABIC_LETTER_ZAH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ZAH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter ain iso-8859-6 character code model. U+00D9 */
static unsigned char ARABIC_LETTER_AIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xD9 };
static unsigned char* ARABIC_LETTER_AIN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_AIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter ghain iso-8859-6 character code model. U+00DA */
static unsigned char ARABIC_LETTER_GHAIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xDA };
static unsigned char* ARABIC_LETTER_GHAIN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_GHAIN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic tatweel iso-8859-6 character code model. U+00E0 */
static unsigned char ARABIC_TATWEEL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE0 };
static unsigned char* ARABIC_TATWEEL_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_TATWEEL_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter feh iso-8859-6 character code model. U+00E1 */
static unsigned char ARABIC_LETTER_FEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE1 };
static unsigned char* ARABIC_LETTER_FEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_FEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter qaf iso-8859-6 character code model. U+00E2 */
static unsigned char ARABIC_LETTER_QAF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE2 };
static unsigned char* ARABIC_LETTER_QAFISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_QAF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter kaf iso-8859-6 character code model. U+00E3 */
static unsigned char ARABIC_LETTER_KAF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE3 };
static unsigned char* ARABIC_LETTER_KAF_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_KAF_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter lam iso-8859-6 character code model. U+00E4 */
static unsigned char ARABIC_LETTER_LAM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE4 };
static unsigned char* ARABIC_LETTER_LAM_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_LAM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter meem iso-8859-6 character code model. U+00E5 */
static unsigned char ARABIC_LETTER_MEEM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE5 };
static unsigned char* ARABIC_LETTER_MEEM_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_MEEM_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter noon iso-8859-6 character code model. U+00E6 */
static unsigned char ARABIC_LETTER_NOON_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE6 };
static unsigned char* ARABIC_LETTER_NOON_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_NOON_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter heh iso-8859-6 character code model. U+00E7 */
static unsigned char ARABIC_LETTER_HEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE7 };
static unsigned char* ARABIC_LETTER_HEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_HEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter waw iso-8859-6 character code model. U+00E8 */
static unsigned char ARABIC_LETTER_WAW_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE8 };
static unsigned char* ARABIC_LETTER_WAW_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_WAW_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter alef makusra iso-8859-6 character code model. U+00E9 */
static unsigned char ARABIC_LETTER_ALEF_MAKSURA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE9 };
static unsigned char* ARABIC_LETTER_ALEF_MAKSURA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_ALEF_MAKSURA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic letter yeh iso-8859-6 character code model. U+00EA */
static unsigned char ARABIC_LETTER_YEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEA };
static unsigned char* ARABIC_LETTER_YEH_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_LETTER_YEH_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic fathatan iso-8859-6 character code model. U+00EB */
static unsigned char ARABIC_FATHATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEB };
static unsigned char* ARABIC_FATHATAN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_FATHATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic dammatan iso-8859-6 character code model. U+00EC */
static unsigned char ARABIC_DAMMATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEC };
static unsigned char* ARABIC_DAMMATAN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_DAMMATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic kasratan iso-8859-6 character code model. U+00ED */
static unsigned char ARABIC_KASRATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xED };
static unsigned char* ARABIC_KASRATAN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_KASRATAN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic fatha iso-8859-6 character code model. U+00EE */
static unsigned char ARABIC_FATHA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEE };
static unsigned char* ARABIC_FATHA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_FATHA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic damma iso-8859-6 character code model. U+00EF */
static unsigned char ARABIC_DAMMA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEF };
static unsigned char* ARABIC_DAMMA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_DAMMA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic kasra iso-8859-6 character code model. U+00F0 */
static unsigned char ARABIC_KASRA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF0 };
static unsigned char* ARABIC_KASRA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_KASRA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic shadda iso-8859-6 character code model. U+00F1 */
static unsigned char ARABIC_SHADDA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF1 };
static unsigned char* ARABIC_SHADDA_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_SHADDA_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/** The arabic sukun iso-8859-6 character code model. U+00F2 */
static unsigned char ARABIC_SUKUN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF2 };
static unsigned char* ARABIC_SUKUN_ISO_8859_6_CHARACTER_CODE_MODEL = ARABIC_SUKUN_ISO_8859_6_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_6_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
