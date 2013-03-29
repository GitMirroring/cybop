/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
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
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA2    0x00A2  #       CENT SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA3    0x00A3  #       POUND SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA4    0x00A4  #       CURRENCY SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA5    0x00A5  #       YEN SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA6    0x00A6  #       BROKEN BAR
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA7    0x00A7  #       SECTION SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA8    0x00A8  #       DIAERESIS
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xA9    0x00A9  #       COPYRIGHT SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAA    0x00D7  #       MULTIPLICATION SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAB    0x00AB  #       LEFT-POINTING DOUBLE ANGLE QUOTATION MARK
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAC    0x00AC  #       NOT SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAD    0x00AD  #       SOFT HYPHEN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAE    0x00AE  #       REGISTERED SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xAF    0x00AF  #       MACRON
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB0    0x00B0  #       DEGREE SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB1    0x00B1  #       PLUS-MINUS SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB2    0x00B2  #       SUPERSCRIPT TWO
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB3    0x00B3  #       SUPERSCRIPT THREE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB4    0x00B4  #       ACUTE ACCENT
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB5    0x00B5  #       MICRO SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB6    0x00B6  #       PILCROW SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB7    0x00B7  #       MIDDLE DOT
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB8    0x00B8  #       CEDILLA
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xB9    0x00B9  #       SUPERSCRIPT ONE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xBA    0x00F7  #       DIVISION SIGN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xBB    0x00BB  #       RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xBC    0x00BC  #       VULGAR FRACTION ONE QUARTER
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xBD    0x00BD  #       VULGAR FRACTION ONE HALF
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xBE    0x00BE  #       VULGAR FRACTION THREE QUARTERS
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xDF    0x2017  #       DOUBLE LOW LINE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE0    0x05D0  #       HEBREW LETTER ALEF
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE1    0x05D1  #       HEBREW LETTER BET
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE2    0x05D2  #       HEBREW LETTER GIMEL
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE3    0x05D3  #       HEBREW LETTER DALET
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE4    0x05D4  #       HEBREW LETTER HE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE5    0x05D5  #       HEBREW LETTER VAV
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE6    0x05D6  #       HEBREW LETTER ZAYIN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE7    0x05D7  #       HEBREW LETTER HET
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE8    0x05D8  #       HEBREW LETTER TET
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xE9    0x05D9  #       HEBREW LETTER YOD
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xEA    0x05DA  #       HEBREW LETTER FINAL KAF
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xEB    0x05DB  #       HEBREW LETTER KAF
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xEC    0x05DC  #       HEBREW LETTER LAMED
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xED    0x05DD  #       HEBREW LETTER FINAL MEM
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xEE    0x05DE  #       HEBREW LETTER MEM
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xEF    0x05DF  #       HEBREW LETTER FINAL NUN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF0    0x05E0  #       HEBREW LETTER NUN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF1    0x05E1  #       HEBREW LETTER SAMEKH
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF2    0x05E2  #       HEBREW LETTER AYIN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF3    0x05E3  #       HEBREW LETTER FINAL PE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF4    0x05E4  #       HEBREW LETTER PE
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF5    0x05E5  #       HEBREW LETTER FINAL TSADI
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF6    0x05E6  #       HEBREW LETTER TSADI
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF7    0x05E7  #       HEBREW LETTER QOF
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF8    0x05E8  #       HEBREW LETTER RESH
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xF9    0x05E9  #       HEBREW LETTER SHIN
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xFA    0x05EA  #       HEBREW LETTER TAV
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xFD    0x200E  #       LEFT-TO-RIGHT MARK
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

0xFE    0x200F  #       RIGHT-TO-LEFT MARK
/** The no-break space iso-8859-8 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_8_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_8_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
