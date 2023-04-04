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

#ifndef C0_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_HEADER
#define C0_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_HEADER

//
// System interface
//

#include <stddef.h> // wchar_t

//
// Library interface
//

#include "constant.h"

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
// This file contains C0 control code constants.
//

/** The null c0 iso-6429 character code model. U+0000 */
static unsigned char* NULL_C0_ISO_6429_CHARACTER_CODE_MODEL = NULL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The start of heading c0 iso-6429 character code model. U+0001 */
static unsigned char* START_OF_HEADING_C0_ISO_6429_CHARACTER_CODE_MODEL = START_OF_HEADING_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The start of text c0 iso-6429 character code model. U+0002 */
static unsigned char* START_OF_TEXT_C0_ISO_6429_CHARACTER_CODE_MODEL = START_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of text c0 iso-6429 character code model. U+0003 */
static unsigned char* END_OF_TEXT_C0_ISO_6429_CHARACTER_CODE_MODEL = END_OF_TEXT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission c0 iso-6429 character code model. U+0004 */
static unsigned char* END_OF_TRANSMISSION_C0_ISO_6429_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The enquiry c0 iso-6429 character code model. U+0005 */
static unsigned char* ENQUIRY_C0_ISO_6429_CHARACTER_CODE_MODEL = ENQUIRY_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The acknowledge c0 iso-6429 character code model. U+0006 */
static unsigned char* ACKNOWLEDGE_C0_ISO_6429_CHARACTER_CODE_MODEL = ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The bell c0 iso-6429 character code model. U+0007 */
static unsigned char* BELL_C0_ISO_6429_CHARACTER_CODE_MODEL = BELL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The backspace c0 iso-6429 character code model. U+0008 */
static unsigned char* BACKSPACE_C0_ISO_6429_CHARACTER_CODE_MODEL = BACKSPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The character tabulation c0 iso-6429 character code model. U+0009 */
static unsigned char* CHARACTER_TABULATION_C0_ISO_6429_CHARACTER_CODE_MODEL = CHARACTER_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The line feed c0 iso-6429 character code model. U+000A */
static unsigned char* LINE_FEED_C0_ISO_6429_CHARACTER_CODE_MODEL = LINE_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The line tabulation c0 iso-6429 character code model. U+000B */
static unsigned char* LINE_TABULATION_C0_ISO_6429_CHARACTER_CODE_MODEL = LINE_TABULATION_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The form feed c0 iso-6429 character code model. U+000C */
static unsigned char* FORM_FEED_C0_ISO_6429_CHARACTER_CODE_MODEL = FORM_FEED_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The carriage return (enter) c0 iso-6429 character code model. U+000D */
static unsigned char* CARRIAGE_RETURN_C0_ISO_6429_CHARACTER_CODE_MODEL = CARRIAGE_RETURN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The shift out c0 iso-6429 character code model. U+000E */
static unsigned char* SHIFT_OUT_C0_ISO_6429_CHARACTER_CODE_MODEL = SHIFT_OUT_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The shift in c0 iso-6429 character code model. U+000F */
static unsigned char* SHIFT_IN_C0_ISO_6429_CHARACTER_CODE_MODEL = SHIFT_IN_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The data link escape c0 iso-6429 character code model. U+0010 */
static unsigned char* DATA_LINK_ESCAPE_C0_ISO_6429_CHARACTER_CODE_MODEL = DATA_LINK_ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control one c0 iso-6429 character code model. U+0011 */
static unsigned char* DEVICE_CONTROL_ONE_C0_ISO_6429_CHARACTER_CODE_MODEL = DEVICE_CONTROL_ONE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control two c0 iso-6429 character code model. U+0012 */
static unsigned char* DEVICE_CONTROL_TWO_C0_ISO_6429_CHARACTER_CODE_MODEL = DEVICE_CONTROL_TWO_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control three c0 iso-6429 character code model. U+0013 */
static unsigned char* DEVICE_CONTROL_THREE_C0_ISO_6429_CHARACTER_CODE_MODEL = DEVICE_CONTROL_THREE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The device control four c0 iso-6429 character code model. U+0014 */
static unsigned char* DEVICE_CONTROL_FOUR_C0_ISO_6429_CHARACTER_CODE_MODEL = DEVICE_CONTROL_FOUR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The negative acknowledge c0 iso-6429 character code model. U+0015 */
static unsigned char* NEGATIVE_ACKNOWLEDGE_C0_ISO_6429_CHARACTER_CODE_MODEL = NEGATIVE_ACKNOWLEDGE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The synchronous idle c0 iso-6429 character code model. U+0016 */
static unsigned char* SYNCHRONOUS_IDLE_C0_ISO_6429_CHARACTER_CODE_MODEL = SYNCHRONOUS_IDLE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of transmission block c0 iso-6429 character code model. U+0017 */
static unsigned char* END_OF_TRANSMISSION_BLOCK_C0_ISO_6429_CHARACTER_CODE_MODEL = END_OF_TRANSMISSION_BLOCK_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The cancel c0 iso-6429 character code model. U+0018 */
static unsigned char* CANCEL_C0_ISO_6429_CHARACTER_CODE_MODEL = CANCEL_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The end of medium c0 iso-6429 character code model. U+0019 */
static unsigned char* END_OF_MEDIUM_C0_ISO_6429_CHARACTER_CODE_MODEL = END_OF_MEDIUM_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The substitute c0 iso-6429 character code model. U+001A */
static unsigned char* SUBSTITUTE_C0_ISO_6429_CHARACTER_CODE_MODEL = SUBSTITUTE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The escape c0 iso-6429 character code model. U+001B */
static unsigned char* ESCAPE_C0_ISO_6429_CHARACTER_CODE_MODEL = ESCAPE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The file separator c0 iso-6429 character code model. U+001C */
static unsigned char* FILE_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL = FILE_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The group separator c0 iso-6429 character code model. U+001D */
static unsigned char* GROUP_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL = GROUP_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The record separator c0 iso-6429 character code model. U+001E */
static unsigned char* RECORD_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL = RECORD_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The unit separator c0 iso-6429 character code model. U+001F */
static unsigned char* UNIT_SEPARATOR_C0_ISO_6429_CHARACTER_CODE_MODEL = UNIT_SEPARATOR_ASCII_CHARACTER_CODE_MODEL_ARRAY;

//
// While not technically part of the C0 control character range,
// the following two characters are defined in ISO/IEC 2022
// as always being available regardless of which sets of control
// characters and graphics characters have been registered.
// They can be thought of as having some characteristics of control characters.
//

/** The space c0 iso-6429 character code model. U+0020 */
static unsigned char* SPACE_C0_ISO_6429_CHARACTER_CODE_MODEL = SPACE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/** The delete c0 iso-6429 character code model. U+007F */
static unsigned char* DELETE_C0_ISO_6429_CHARACTER_CODE_MODEL = DELETE_ASCII_CHARACTER_CODE_MODEL_ARRAY;

/* C0_ISO_6429_CHARACTER_CODE_MODEL_CONSTANT_HEADER */
#endif
