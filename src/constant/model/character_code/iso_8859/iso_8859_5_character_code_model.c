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
 * CYBOP Developers <cybop-developers@nongnu.org>
 *
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ISO_8859_5_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define ISO_8859_5_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

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
// This file contains ISO-8859-5 character code constants:
// Latin/Cyrillic
//

//
// The ascii characters in range 0x00-0x7F are NOT repeated here
//

//
// The non-printable control characters in range 0x80-0x9F
// which are defined by "ISO-8859" but not "ISO/IEC 8859"
//

/**
 * The padding character iso-8859-5 character code model. U+0080
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* PADDING_CHARACTER_ISO_8859_5_CHARACTER_CODE_MODEL = PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The high octet preset iso-8859-5 character code model. U+0081
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char* HIGH_OCTET_PRESET_ISO_8859_5_CHARACTER_CODE_MODEL = HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The break permitted here iso-8859-5 character code model. U+0082 */
static unsigned char* BREAK_PERMITTED_HERE_ISO_8859_5_CHARACTER_CODE_MODEL = BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The no break here iso-8859-5 character code model. U+0083 */
static unsigned char* NO_BREAK_HERE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The index iso-8859-5 character code model. U+0084 */
static unsigned char* INDEX_ISO_8859_5_CHARACTER_CODE_MODEL = INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The next line iso-8859-5 character code model. U+0085 */
static unsigned char* NEXT_LINE_ISO_8859_5_CHARACTER_CODE_MODEL = NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of selected area iso-8859-5 character code model. U+0086 */
static unsigned char* START_OF_SELECTED_AREA_ISO_8859_5_CHARACTER_CODE_MODEL = START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of selected area iso-8859-5 character code model. U+0087 */
static unsigned char* END_OF_SELECTED_AREA_ISO_8859_5_CHARACTER_CODE_MODEL = END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation set iso-8859-5 character code model. U+0088 */
static unsigned char* CHARACTER_TABULATION_SET_ISO_8859_5_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation with justification iso-8859-5 character code model. U+0089 */
static unsigned char* CHARACTER_TABULATION_WITH_JUSTIFICATION_ISO_8859_5_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation set iso-8859-5 character code model. U+008A */
static unsigned char* LINE_TABULATION_SET_ISO_8859_5_CHARACTER_CODE_MODEL = LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line forward iso-8859-5 character code model. U+008B */
static unsigned char* PARTIAL_LINE_FORWARD_ISO_8859_5_CHARACTER_CODE_MODEL = PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line backward iso-8859-5 character code model. U+008C */
static unsigned char* PARTIAL_LINE_BACKWARD_ISO_8859_5_CHARACTER_CODE_MODEL = PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse line feed iso-8859-5 character code model. U+008D */
static unsigned char* REVERSE_LINE_FEED_ISO_8859_5_CHARACTER_CODE_MODEL = REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift two iso-8859-5 character code model. U+008E */
static unsigned char* SINGLE_SHIFT_TWO_ISO_8859_5_CHARACTER_CODE_MODEL = SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift three iso-8859-5 character code model. U+008F */
static unsigned char* SINGLE_SHIFT_THREE_ISO_8859_5_CHARACTER_CODE_MODEL = SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control string iso-8859-5 character code model. U+0090 */
static unsigned char* DEVICE_CONTROL_STRING_ISO_8859_5_CHARACTER_CODE_MODEL = DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use one iso-8859-5 character code model. U+0091 */
static unsigned char* PRIVATE_USE_ONE_ISO_8859_5_CHARACTER_CODE_MODEL = PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use two iso-8859-5 character code model. U+0092 */
static unsigned char* PRIVATE_USE_TWO_ISO_8859_5_CHARACTER_CODE_MODEL = PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The set transmit state iso-8859-5 character code model. U+0093 */
static unsigned char* SET_TRANSMIT_STATE_ISO_8859_5_CHARACTER_CODE_MODEL = SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel character iso-8859-5 character code model. U+0094 */
static unsigned char* CANCEL_CHARACTER_ISO_8859_5_CHARACTER_CODE_MODEL = CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The message waiting iso-8859-5 character code model. U+0095 */
static unsigned char* MESSAGE_WAITING_ISO_8859_5_CHARACTER_CODE_MODEL = MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of guarded area iso-8859-5 character code model. U+0096 */
static unsigned char* START_OF_GUARDED_AREA_ISO_8859_5_CHARACTER_CODE_MODEL = START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of guarded area iso-8859-5 character code model. U+0097 */
static unsigned char* END_OF_GUARDED_AREA_ISO_8859_5_CHARACTER_CODE_MODEL = END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of string iso-8859-5 character code model. U+0098 */
static unsigned char* START_OF_STRING_ISO_8859_5_CHARACTER_CODE_MODEL = START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The single graphic character introducer iso-8859-5 character code model. U+0099
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429.
 */
static unsigned char* SINGLE_GRAPHIC_CHARACTER_INTRODUCER_ISO_8859_5_CHARACTER_CODE_MODEL = SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single character introducer iso-8859-5 character code model. U+009A */
static unsigned char* SINGLE_CHARACTER_INTRODUCER_ISO_8859_5_CHARACTER_CODE_MODEL = SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The control sequence introducer iso-8859-5 character code model. U+009B */
static unsigned char* CONTROL_SEQUENCE_INTRODUCER_ISO_8859_5_CHARACTER_CODE_MODEL = CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The string terminator iso-8859-5 character code model. U+009C */
static unsigned char* STRING_TERMINATOR_ISO_8859_5_CHARACTER_CODE_MODEL = STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The operating system command iso-8859-5 character code model. U+009D */
static unsigned char* OPERATING_SYSTEM_COMMAND_ISO_8859_5_CHARACTER_CODE_MODEL = OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The privacy message iso-8859-5 character code model. U+009E */
static unsigned char* PRIVACY_MESSAGE_ISO_8859_5_CHARACTER_CODE_MODEL = PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The application program commandiso-8859-5 character code model. U+009F */
static unsigned char* APPLICATION_PROGRAM_COMMAND_ISO_8859_5_CHARACTER_CODE_MODEL = APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

//
// The printable characters in range 0xA0-0xFF
//

/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA1    0x0401  #       CYRILLIC CAPITAL LETTER IO
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA2    0x0402  #       CYRILLIC CAPITAL LETTER DJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA3    0x0403  #       CYRILLIC CAPITAL LETTER GJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA4    0x0404  #       CYRILLIC CAPITAL LETTER UKRAINIAN IE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA5    0x0405  #       CYRILLIC CAPITAL LETTER DZE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA6    0x0406  #       CYRILLIC CAPITAL LETTER BYELORUSSIAN-UKRAINIAN I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA7    0x0407  #       CYRILLIC CAPITAL LETTER YI
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA8    0x0408  #       CYRILLIC CAPITAL LETTER JE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xA9    0x0409  #       CYRILLIC CAPITAL LETTER LJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAA    0x040A  #       CYRILLIC CAPITAL LETTER NJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAB    0x040B  #       CYRILLIC CAPITAL LETTER TSHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAC    0x040C  #       CYRILLIC CAPITAL LETTER KJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAD    0x00AD  #       SOFT HYPHEN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAE    0x040E  #       CYRILLIC CAPITAL LETTER SHORT U
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xAF    0x040F  #       CYRILLIC CAPITAL LETTER DZHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB0    0x0410  #       CYRILLIC CAPITAL LETTER A
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB1    0x0411  #       CYRILLIC CAPITAL LETTER BE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB2    0x0412  #       CYRILLIC CAPITAL LETTER VE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB3    0x0413  #       CYRILLIC CAPITAL LETTER GHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB4    0x0414  #       CYRILLIC CAPITAL LETTER DE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB5    0x0415  #       CYRILLIC CAPITAL LETTER IE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB6    0x0416  #       CYRILLIC CAPITAL LETTER ZHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB7    0x0417  #       CYRILLIC CAPITAL LETTER ZE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB8    0x0418  #       CYRILLIC CAPITAL LETTER I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xB9    0x0419  #       CYRILLIC CAPITAL LETTER SHORT I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBA    0x041A  #       CYRILLIC CAPITAL LETTER KA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBB    0x041B  #       CYRILLIC CAPITAL LETTER EL
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBC    0x041C  #       CYRILLIC CAPITAL LETTER EM
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBD    0x041D  #       CYRILLIC CAPITAL LETTER EN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBE    0x041E  #       CYRILLIC CAPITAL LETTER O
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xBF    0x041F  #       CYRILLIC CAPITAL LETTER PE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC0    0x0420  #       CYRILLIC CAPITAL LETTER ER
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC1    0x0421  #       CYRILLIC CAPITAL LETTER ES
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC2    0x0422  #       CYRILLIC CAPITAL LETTER TE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC3    0x0423  #       CYRILLIC CAPITAL LETTER U
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC4    0x0424  #       CYRILLIC CAPITAL LETTER EF
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC5    0x0425  #       CYRILLIC CAPITAL LETTER HA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC6    0x0426  #       CYRILLIC CAPITAL LETTER TSE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC7    0x0427  #       CYRILLIC CAPITAL LETTER CHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC8    0x0428  #       CYRILLIC CAPITAL LETTER SHA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xC9    0x0429  #       CYRILLIC CAPITAL LETTER SHCHA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCA    0x042A  #       CYRILLIC CAPITAL LETTER HARD SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCB    0x042B  #       CYRILLIC CAPITAL LETTER YERU
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCC    0x042C  #       CYRILLIC CAPITAL LETTER SOFT SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCD    0x042D  #       CYRILLIC CAPITAL LETTER E
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCE    0x042E  #       CYRILLIC CAPITAL LETTER YU
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xCF    0x042F  #       CYRILLIC CAPITAL LETTER YA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD0    0x0430  #       CYRILLIC SMALL LETTER A
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD1    0x0431  #       CYRILLIC SMALL LETTER BE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD2    0x0432  #       CYRILLIC SMALL LETTER VE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD3    0x0433  #       CYRILLIC SMALL LETTER GHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD4    0x0434  #       CYRILLIC SMALL LETTER DE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD5    0x0435  #       CYRILLIC SMALL LETTER IE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD6    0x0436  #       CYRILLIC SMALL LETTER ZHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD7    0x0437  #       CYRILLIC SMALL LETTER ZE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD8    0x0438  #       CYRILLIC SMALL LETTER I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xD9    0x0439  #       CYRILLIC SMALL LETTER SHORT I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDA    0x043A  #       CYRILLIC SMALL LETTER KA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDB    0x043B  #       CYRILLIC SMALL LETTER EL
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDC    0x043C  #       CYRILLIC SMALL LETTER EM
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDD    0x043D  #       CYRILLIC SMALL LETTER EN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDE    0x043E  #       CYRILLIC SMALL LETTER O
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xDF    0x043F  #       CYRILLIC SMALL LETTER PE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE0    0x0440  #       CYRILLIC SMALL LETTER ER
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE1    0x0441  #       CYRILLIC SMALL LETTER ES
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE2    0x0442  #       CYRILLIC SMALL LETTER TE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE3    0x0443  #       CYRILLIC SMALL LETTER U
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE4    0x0444  #       CYRILLIC SMALL LETTER EF
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE5    0x0445  #       CYRILLIC SMALL LETTER HA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE6    0x0446  #       CYRILLIC SMALL LETTER TSE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE7    0x0447  #       CYRILLIC SMALL LETTER CHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE8    0x0448  #       CYRILLIC SMALL LETTER SHA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xE9    0x0449  #       CYRILLIC SMALL LETTER SHCHA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xEA    0x044A  #       CYRILLIC SMALL LETTER HARD SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xEB    0x044B  #       CYRILLIC SMALL LETTER YERU
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xEC    0x044C  #       CYRILLIC SMALL LETTER SOFT SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xED    0x044D  #       CYRILLIC SMALL LETTER E
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xEE    0x044E  #       CYRILLIC SMALL LETTER YU
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xEF    0x044F  #       CYRILLIC SMALL LETTER YA
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF0    0x2116  #       NUMERO SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF1    0x0451  #       CYRILLIC SMALL LETTER IO
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF2    0x0452  #       CYRILLIC SMALL LETTER DJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF3    0x0453  #       CYRILLIC SMALL LETTER GJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF4    0x0454  #       CYRILLIC SMALL LETTER UKRAINIAN IE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF5    0x0455  #       CYRILLIC SMALL LETTER DZE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF6    0x0456  #       CYRILLIC SMALL LETTER BYELORUSSIAN-UKRAINIAN I
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF7    0x0457  #       CYRILLIC SMALL LETTER YI
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF8    0x0458  #       CYRILLIC SMALL LETTER JE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xF9    0x0459  #       CYRILLIC SMALL LETTER LJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFA    0x045A  #       CYRILLIC SMALL LETTER NJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFB    0x045B  #       CYRILLIC SMALL LETTER TSHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFC    0x045C  #       CYRILLIC SMALL LETTER KJE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFD    0x00A7  #       SECTION SIGN
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFE    0x045E  #       CYRILLIC SMALL LETTER SHORT U
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

0xFF    0x045F  #       CYRILLIC SMALL LETTER DZHE
/** The no-break space iso-8859-5 character code model. U+00A0 */
static unsigned char NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY[] = {0xA0};
static unsigned char* NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL = NO_BREAK_SPACE_ISO_8859_5_CHARACTER_CODE_MODEL_ARRAY;

/* ISO_8859_5_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
