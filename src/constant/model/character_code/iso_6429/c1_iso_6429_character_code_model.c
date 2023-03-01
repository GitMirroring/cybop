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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef C1_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_SOURCE
#define C1_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"

//
// Most character encodings, in addition to representing printable characters,
// may also represent additional information about the text, such as:
// - the position of a cursor
// - an instruction to start a new line
// - a message that the text has been received
//
// The C0 and C1 control code or control characters sets define
// control codes for use in text by computer systems that use
// the ISO/IEC 2022 system of specifying control and graphic characters.
//
// The defined codes range in:
// - C0: 0x00-0x1F
// - C1: 0x80-0x9F
//
// The default C0 set was originally defined in ISO 646 (ASCII),
// while the default C1 set was originally defined in ECMA-48
// (harmonised later with ISO 6429).
// While other C0 and C1 sets are available for
// specialised applications, they are rarely used.
//
// This file contains C1 control code constants.
//

/**
 * The padding character c1 iso-6429 character code model. U+0080
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x80 };
static unsigned char* PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL = PADDING_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The high octet preset c1 iso-6429 character code model. U+0081
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429 (ECMA-48).
 */
static unsigned char HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x81 };
static unsigned char* HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL = HIGH_OCTET_PRESET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The break permitted here c1 iso-6429 character code model. U+0082 */
static unsigned char BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x82 };
static unsigned char* BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL = BREAK_PERMITTED_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The no break here c1 iso-6429 character code model. U+0083 */
static unsigned char NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x83 };
static unsigned char* NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL = NO_BREAK_HERE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The index c1 iso-6429 character code model. U+0084 */
static unsigned char INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x84 };
static unsigned char* INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL = INDEX_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The next line c1 iso-6429 character code model. U+0085 */
static unsigned char NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x85 };
static unsigned char* NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL = NEXT_LINE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of selected area c1 iso-6429 character code model. U+0086 */
static unsigned char START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x86 };
static unsigned char* START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL = START_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of selected area c1 iso-6429 character code model. U+0087 */
static unsigned char END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x87 };
static unsigned char* END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL = END_OF_SELECTED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation set c1 iso-6429 character code model. U+0088 */
static unsigned char CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x88 };
static unsigned char* CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation with justification c1 iso-6429 character code model. U+0089 */
static unsigned char CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x89 };
static unsigned char* CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_WITH_JUSTIFICATION_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation set c1 iso-6429 character code model. U+008A */
static unsigned char LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8A };
static unsigned char* LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL = LINE_TABULATION_SET_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line forward c1 iso-6429 character code model. U+008B */
static unsigned char PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8B };
static unsigned char* PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL = PARTIAL_LINE_FORWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The partial line backward c1 iso-6429 character code model. U+008C */
static unsigned char PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8C };
static unsigned char* PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL = PARTIAL_LINE_BACKWARD_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The reverse line feed c1 iso-6429 character code model. U+008D */
static unsigned char REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8D };
static unsigned char* REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL = REVERSE_LINE_FEED_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift two c1 iso-6429 character code model. U+008E */
static unsigned char SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8E };
static unsigned char* SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL = SINGLE_SHIFT_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single-shift three c1 iso-6429 character code model. U+008F */
static unsigned char SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x8F };
static unsigned char* SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL = SINGLE_SHIFT_THREE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The device control string c1 iso-6429 character code model. U+0090 */
static unsigned char DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x90 };
static unsigned char* DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL = DEVICE_CONTROL_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use one c1 iso-6429 character code model. U+0091 */
static unsigned char PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x91 };
static unsigned char* PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL = PRIVATE_USE_ONE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The private use two c1 iso-6429 character code model. U+0092 */
static unsigned char PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x92 };
static unsigned char* PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL = PRIVATE_USE_TWO_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The set transmit state c1 iso-6429 character code model. U+0093 */
static unsigned char SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x93 };
static unsigned char* SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL = SET_TRANSMIT_STATE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel character c1 iso-6429 character code model. U+0094 */
static unsigned char CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x94 };
static unsigned char* CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL = CANCEL_CHARACTER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The message waiting c1 iso-6429 character code model. U+0095 */
static unsigned char MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x95 };
static unsigned char* MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL = MESSAGE_WAITING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of guarded area c1 iso-6429 character code model. U+0096 */
static unsigned char START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x96 };
static unsigned char* START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL = START_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The end of guarded area c1 iso-6429 character code model. U+0097 */
static unsigned char END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x97 };
static unsigned char* END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL = END_OF_GUARDED_AREA_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The start of string c1 iso-6429 character code model. U+0098 */
static unsigned char START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x98 };
static unsigned char* START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL = START_OF_STRING_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/**
 * The single graphic character introducer c1 iso-6429 character code model. U+0099
 *
 * Listed as XXX in Unicode. Not part of ISO/IEC 6429.
 */
static unsigned char SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x99 };
static unsigned char* SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL = SINGLE_GRAPHIC_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The single character introducer c1 iso-6429 character code model. U+009A */
static unsigned char SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9A };
static unsigned char* SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL = SINGLE_CHARACTER_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The control sequence introducer c1 iso-6429 character code model. U+009B */
static unsigned char CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9B };
static unsigned char* CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL = CONTROL_SEQUENCE_INTRODUCER_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The string terminator c1 iso-6429 character code model. U+009C */
static unsigned char STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9C };
static unsigned char* STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL = STRING_TERMINATOR_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The operating system command c1 iso-6429 character code model. U+009D */
static unsigned char OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9D };
static unsigned char* OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL = OPERATING_SYSTEM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The privacy message c1 iso-6429 character code model. U+009E */
static unsigned char PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9E };
static unsigned char* PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL = PRIVACY_MESSAGE_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/** The application program commandc1 iso-6429 character code model. U+009F */
static unsigned char APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY[] = { 0x9F };
static unsigned char* APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL = APPLICATION_PROGRAM_COMMAND_C1_ISO_6429_CHARACTER_CODE_MODEL_ARRAY;

/* C1_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_SOURCE */
#endif
