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
 * @author Franziska Wehner
 */

#ifndef ISO_8859_8_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define ISO_8859_8_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
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
// This file contains ISO-8859-8 character code constants:
// Latin/Hebrew
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The non-printable control characters in range 0x80-0x9F
// which are defined by "ISO-8859" but not "ISO/IEC 8859"
//

/**
 * The padding character iso-8859-8 character code model. U+0080
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* PADDING_CHARACTER_ISO_8859_8_CHARACTER_CODE_MODEL = PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The high octet preset iso-8859-8 character code model. U+0081
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* HIGH_OCTET_PRESET_ISO_8859_8_CHARACTER_CODE_MODEL = HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The break permitted here iso-8859-8 character code model. U+0082 */
static unsigned char* BREAK_PERMITTED_HERE_ISO_8859_8_CHARACTER_CODE_MODEL = BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The no break here iso-8859-8 character code model. U+0083 */
static unsigned char* NO_BREAK_HERE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The index iso-8859-8 character code model. U+0084 */
static unsigned char* INDEX_ISO_8859_8_CHARACTER_CODE_MODEL = INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The next line iso-8859-8 character code model. U+0085 */
static unsigned char* NEXT_LINE_ISO_8859_8_CHARACTER_CODE_MODEL = NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of selected area iso-8859-8 character code model. U+0086 */
static unsigned char* START_OF_SELECTED_AREA_ISO_8859_8_CHARACTER_CODE_MODEL = START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of selected area iso-8859-8 character code model. U+0087 */
static unsigned char* END_OF_SELECTED_AREA_ISO_8859_8_CHARACTER_CODE_MODEL = END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation set iso-8859-8 character code model. U+0088 */
static unsigned char* CHARACTER_TABULATION_SET_ISO_8859_8_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation with justification iso-8859-8 character code model. U+0089 */
static unsigned char* CHARACTER_TABULATION_WITH_JUSTIFICATION_ISO_8859_8_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation set iso-8859-8 character code model. U+008A */
static unsigned char* LINE_TABULATION_SET_ISO_8859_8_CHARACTER_CODE_MODEL = LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line forward iso-8859-8 character code model. U+008B */
static unsigned char* PARTIAL_LINE_FORWARD_ISO_8859_8_CHARACTER_CODE_MODEL = PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line backward iso-8859-8 character code model. U+008C */
static unsigned char* PARTIAL_LINE_BACKWARD_ISO_8859_8_CHARACTER_CODE_MODEL = PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse line feed iso-8859-8 character code model. U+008D */
static unsigned char* REVERSE_LINE_FEED_ISO_8859_8_CHARACTER_CODE_MODEL = REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift two iso-8859-8 character code model. U+008E */
static unsigned char* SINGLE_SHIFT_TWO_ISO_8859_8_CHARACTER_CODE_MODEL = SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift three iso-8859-8 character code model. U+008F */
static unsigned char* SINGLE_SHIFT_THREE_ISO_8859_8_CHARACTER_CODE_MODEL = SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control string iso-8859-8 character code model. U+0090 */
static unsigned char* DEVICE_CONTROL_STRING_ISO_8859_8_CHARACTER_CODE_MODEL = DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use one iso-8859-8 character code model. U+0091 */
static unsigned char* PRIVATE_USE_ONE_ISO_8859_8_CHARACTER_CODE_MODEL = PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use two iso-8859-8 character code model. U+0092 */
static unsigned char* PRIVATE_USE_TWO_ISO_8859_8_CHARACTER_CODE_MODEL = PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The set transmit state iso-8859-8 character code model. U+0093 */
static unsigned char* SET_TRANSMIT_STATE_ISO_8859_8_CHARACTER_CODE_MODEL = SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel character iso-8859-8 character code model. U+0094 */
static unsigned char* CANCEL_CHARACTER_ISO_8859_8_CHARACTER_CODE_MODEL = CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The message waiting iso-8859-8 character code model. U+0095 */
static unsigned char* MESSAGE_WAITING_ISO_8859_8_CHARACTER_CODE_MODEL = MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of guarded area iso-8859-8 character code model. U+0096 */
static unsigned char* START_OF_GUARDED_AREA_ISO_8859_8_CHARACTER_CODE_MODEL = START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of guarded area iso-8859-8 character code model. U+0097 */
static unsigned char* END_OF_GUARDED_AREA_ISO_8859_8_CHARACTER_CODE_MODEL = END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of string iso-8859-8 character code model. U+0098 */
static unsigned char* START_OF_STRING_ISO_8859_8_CHARACTER_CODE_MODEL = START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The single graphic character introducer iso-8859-8 character code model. U+0099
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429.
 */
static unsigned char* SINGLE_GRAPHIC_CHARACTER_INTRODUCER_ISO_8859_8_CHARACTER_CODE_MODEL = SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single character introducer iso-8859-8 character code model. U+009A */
static unsigned char* SINGLE_CHARACTER_INTRODUCER_ISO_8859_8_CHARACTER_CODE_MODEL = SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The control sequence introducer iso-8859-8 character code model. U+009B */
static unsigned char* CONTROL_SEQUENCE_INTRODUCER_ISO_8859_8_CHARACTER_CODE_MODEL = CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The string terminator iso-8859-8 character code model. U+009C */
static unsigned char* STRING_TERMINATOR_ISO_8859_8_CHARACTER_CODE_MODEL = STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The operating system command iso-8859-8 character code model. U+009D */
static unsigned char* OPERATING_SYSTEM_COMMAND_ISO_8859_8_CHARACTER_CODE_MODEL = OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The privacy message iso-8859-8 character code model. U+009E */
static unsigned char* PRIVACY_MESSAGE_ISO_8859_8_CHARACTER_CODE_MODEL = PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The application program commandiso-8859-8 character code model. U+009F */
static unsigned char* APPLICATION_PROGRAM_COMMAND_ISO_8859_8_CHARACTER_CODE_MODEL = APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0xA0-0xFF
//

/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA0 };
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The cent sign iso-8859-8 character code model. U+00A2 */
static unsigned char CENT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA2 };
static unsigned char* CENT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = CENT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The pound sign iso-8859-8 character code model. U+00A3 */
static unsigned char POUND_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA3 };
static unsigned char* POUND_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = POUND_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The currency sign iso-8859-8 character code model. U+00A4 */
static unsigned char CURRENCY_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA4 };
static unsigned char* CURRENCY_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = CURRENCY_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The yen sign iso-8859-8 character code model. U+00A5 */
static unsigned char YEN_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA5 };
static unsigned char* YEN_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = YEN_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The broken bar iso-8859-8 character code model. U+00A6 */
static unsigned char BROKEN_BAR_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA6 };
static unsigned char* BROKEN_BAR_ISO_8859_8_CHARACTER_CODE_MODEL = BROKEN_BAR_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The section sign iso-8859-8 character code model. U+00A7 */
static unsigned char SECTION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA7 };
static unsigned char* SECTION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = SECTION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The diaeresis iso-8859-8 character code model. U+00A8 */
static unsigned char DIAERESIS_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA8 };
static unsigned char* DIAERESIS_ISO_8859_8_CHARACTER_CODE_MODEL = DIAERESIS_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The copyright sign iso-8859-8 character code model. U+00A9 */
static unsigned char COPYRIGHT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xA9 };
static unsigned char* COPYRIGHT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = COPYRIGHT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The multiplication sign iso-8859-8 character code model. U+00AA */
static unsigned char MULTIPLICATION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAA };
static unsigned char* MULTIPLICATION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = MULTIPLICATION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The left-pointing double angle quotation mark iso-8859-8 character code model. U+00AB */
static unsigned char LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAB };
static unsigned char* LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL = LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The not sign iso-8859-8 character code model. U+00AC */
static unsigned char NOT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAC };
static unsigned char* NOT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = NOT_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The soft hyphen iso-8859-8 character code model. U+00AD */
static unsigned char SOFT_HYPHEN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAD };
static unsigned char* SOFT_HYPHEN_ISO_8859_8_CHARACTER_CODE_MODEL = SOFT_HYPHEN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The registered sign iso-8859-8 character code model. U+00AE */
static unsigned char REGISTERED_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAE };
static unsigned char* REGISTERED_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = REGISTERED_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The macron iso-8859-8 character code model. U+00AF */
static unsigned char MACRON_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xAF };
static unsigned char* MACRON_ISO_8859_8_CHARACTER_CODE_MODEL = MACRON_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The degree sign iso-8859-8 character code model. U+00B0 */
static unsigned char DEGREE_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB0 };
static unsigned char* DEGREE_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = DEGREE_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The plus-minus sign iso-8859-8 character code model. U+00B1 */
static unsigned char PLUS_MINUS_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB1 };
static unsigned char* PLUS_MINUS_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = PLUS_MINUS_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript two iso-8859-8 character code model. U+00B2 */
static unsigned char SUPERSCRIPT_TWO_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB2 };
static unsigned char* SUPERSCRIPT_TWO_ISO_8859_8_CHARACTER_CODE_MODEL = SUPERSCRIPT_TWO_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript three iso-8859-8 character code model. U+00B3 */
static unsigned char SUPERSCRIPT_THREE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB3 };
static unsigned char* SUPERSCRIPT_THREE_ISO_8859_8_CHARACTER_CODE_MODEL = SUPERSCRIPT_THREE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The acute accent iso-8859-8 character code model. U+00B4 */
static unsigned char ACUTE_ACCENT_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB4 };
static unsigned char* ACUTE_ACCENT_ISO_8859_8_CHARACTER_CODE_MODEL = ACUTE_ACCENT_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The micro sign iso-8859-8 character code model. U+00B5 */
static unsigned char MICRO_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB5 };
static unsigned char* MICRO_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = MICRO_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The pilcrow sign iso-8859-8 character code model. U+00B6 */
static unsigned char PILCROW_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB6 };
static unsigned char* PILCROW_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = PILCROW_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The middle dot iso-8859-8 character code model. U+00B7 */
static unsigned char MIDDLE_DOT_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB7 };
static unsigned char* MIDDLE_DOT_ISO_8859_8_CHARACTER_CODE_MODEL = MIDDLE_DOT_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The cedilla iso-8859-8 character code model. U+00B8 */
static unsigned char CEDILLA_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB8 };
static unsigned char* CEDILLA_ISO_8859_8_CHARACTER_CODE_MODEL = CEDILLA_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The superscript one iso-8859-8 character code model. U+00B9 */
static unsigned char SUPERSCRIPT_ONE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xB9 };
static unsigned char* SUPERSCRIPT_ONE_ISO_8859_8_CHARACTER_CODE_MODEL = SUPERSCRIPT_ONE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The division sign iso-8859-8 character code model. U+00BA */
static unsigned char DIVISION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBA };
static unsigned char* DIVISION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL = DIVISION_SIGN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The right-pointing double quotation mark iso-8859-8 character code model. U+00BB */
static unsigned char RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBB };
static unsigned char* RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL = RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one quarter iso-8859-8 character code model. U+00BC */
static unsigned char VULGAR_FRACTION_ONE_QUARTER_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBC };
static unsigned char* VULGAR_FRACTION_ONE_QUARTER_ISO_8859_8_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_QUARTER_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction one half iso-8859-8 character code model. U+00BD */
static unsigned char VULGAR_FRACTION_ONE_HALF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBD };
static unsigned char* VULGAR_FRACTION_ONE_HALF_ISO_8859_8_CHARACTER_CODE_MODEL = VULGAR_FRACTION_ONE_HALF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The vulgar fraction three quarters iso-8859-8 character code model. U+00BE */
static unsigned char VULGAR_FRACTION_THREE_QUARTERS_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xBE };
static unsigned char* VULGAR_FRACTION_THREE_QUARTERS_ISO_8859_8_CHARACTER_CODE_MODEL = VULGAR_FRACTION_THREE_QUARTERS_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The double low line iso-8859-8 character code model. U+00DF */
static unsigned char DOUBLE_LOW_LINE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xDF };
static unsigned char* DOUBLE_LOW_LINE_ISO_8859_8_CHARACTER_CODE_MODEL = DOUBLE_LOW_LINE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter alef iso-8859-8 character code model. U+00E0 */
static unsigned char HEBREW_LETTER_ALEF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE0 };
static unsigned char* HEBREW_LETTER_ALEF_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_ALEF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter bet iso-8859-8 character code model. U+00E1 */
static unsigned char HEBREW_LETTER_BET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE1 };
static unsigned char* HEBREW_LETTER_BET_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_BET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrw letter gimel iso-8859-8 character code model. U+00E2 */
static unsigned char HEBREW_LETTER_GIMEL_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE2 };
static unsigned char* HEBREW_LETTER_GIMEL_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_GIMEL_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter dalet iso-8859-8 character code model. U+00E3 */
static unsigned char HEBREW_LETTER_DALET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE3 };
static unsigned char* HEBREW_LETTER_DALET_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_DALET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrw letter he iso-8859-8 character code model. U+00E4 */
static unsigned char HEBREW_LETTER_HE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE4 };
static unsigned char* HEBREW_LETTER_HE_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_HE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter vav iso-8859-8 character code model. U+00E5 */
static unsigned char HEBREW_LETTER_VAV_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE5 };
static unsigned char* HEBREW_LETTER_VAV_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_VAV_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter zayin iso-8859-8 character code model. U+00E6 */
static unsigned char HEBREW_LETTER_ZAYIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE6 };
static unsigned char* HEBREW_LETTER_ZAYIN_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_ZAYIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter het iso-8859-8 character code model. U+00E7 */
static unsigned char HEBREW_LETTER_HET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE7 };
static unsigned char* HEBREW_LETTER_HET_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_HET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter tet iso-8859-8 character code model. U+00E8 */
static unsigned char HEBREW_LETTER_TET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE8 };
static unsigned char* HEBREW_LETTER_TET_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_TET_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter yod iso-8859-8 character code model. U+00E9 */
static unsigned char HEBREW_LETTER_YOD_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xE9 };
static unsigned char* HEBREW_LETTER_YOD_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_YOD_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter final kaf iso-8859-8 character code model. U+00EA */
static unsigned char HEBREW_LETTER_FINAL_KAF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEA };
static unsigned char* HEBREW_LETTER_FINAL_KAF_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_FINAL_KAF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter kaf iso-8859-8 character code model. U+00EB */
static unsigned char HEBREW_LETTER_KAF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEB };
static unsigned char* HEBREW_LETTER_KAF_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_KAF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter lamed iso-8859-8 character code model. U+00EC */
static unsigned char HEBREW_LETTER_LAMED_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEC };
static unsigned char* HEBREW_LETTER_LAMED_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_LAMED_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter final mem iso-8859-8 character code model. U+00ED */
static unsigned char HEBREW_LETTER_FINAL_MEM_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xED };
static unsigned char* HEBREW_LETTER_FINAL_MEM_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_FINAL_MEM_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter mem iso-8859-8 character code model. U+00EE */
static unsigned char HEBREW_LETTER_MEM_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEE };
static unsigned char* HEBREW_LETTER_MEM_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_MEM_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter final nun iso-8859-8 character code model. U+00EF */
static unsigned char HEBREW_LETTER_FINAL_NUN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xEF };
static unsigned char* HEBREW_LETTER_FINAL_NUN_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_FINAL_NUN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter nun iso-8859-8 character code model. U+00F0 */
static unsigned char HEBREW_LETTER_NUN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF0 };
static unsigned char* HEBREW_LETTER_NUN_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_NUN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter samekh iso-8859-8 character code model. U+00F1 */
static unsigned char HEBREW_LETTER_SAMEKH_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF1 };
static unsigned char* HEBREW_LETTER_SAMEKH_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_SAMEKH_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter ayin iso-8859-8 character code model. U+00F2 */
static unsigned char HEBREW_LETTER_AYIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF2 };
static unsigned char* HEBREW_LETTER_AYIN_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_AYIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter final pe iso-8859-8 character code model. U+00F3 */
static unsigned char HEBREW_LETTER_FINAL_PE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF3 };
static unsigned char* HEBREW_LETTER_FINAL_PE_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_FINAL_PE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter pe iso-8859-8 character code model. U+00F4 */
static unsigned char HEBREW_LETTER_PE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF4 };
static unsigned char* HEBREW_LETTER_PE_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_PE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter final tsadi iso-8859-8 character code model. U+00F5 */
static unsigned char HEBREW_LETTER_FINAL_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF5 };
static unsigned char* HEBREW_LETTER_FINAL_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_FINAL_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter tsadi iso-8859-8 character code model. U+00F6 */
static unsigned char HEBREW_LETTER_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF6 };
static unsigned char* HEBREW_LETTER_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_TSADI_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter qof iso-8859-8 character code model. U+00F7 */
static unsigned char HEBREW_LETTER_QOF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF7 };
static unsigned char* HEBREW_LETTER_QOF_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_QOF_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter resh iso-8859-8 character code model. U+00F8 */
static unsigned char HEBREW_LETTER_RESH_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF8 };
static unsigned char* HEBREW_LETTER_RESH_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_RESH_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter shin iso-8859-8 character code model. U+00F9 */
static unsigned char HEBREW_LETTER_SHIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xF9 };
static unsigned char* HEBREW_LETTER_SHIN_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_SHIN_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The hebrew letter tav iso-8859-8 character code model. U+00FA */
static unsigned char HEBREW_LETTER_TAV_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xFA };
static unsigned char* HEBREW_LETTER_TAV_ISO_8859_8_CHARACTER_CODE_MODEL = HEBREW_LETTER_TAV_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The left-to-right mark iso-8859-8 character code model. U+00FD */
static unsigned char LEFT_TO_RIGHT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xFD };
static unsigned char* LEFT_TO_RIGHT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL = LEFT_TO_RIGHT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/** The right-to-left mark iso-8859-8 character code model. U+00FE */
static unsigned char RIGHT_TO_LEFT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = { 0xFE };
static unsigned char* RIGHT_TO_LEFT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL = RIGHT_TO_LEFT_MARK_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_8_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
