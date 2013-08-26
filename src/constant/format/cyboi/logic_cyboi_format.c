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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGIC_CYBOI_FORMAT_CONSTANT_SOURCE
#define LOGIC_CYBOI_FORMAT_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//
// CAUTION! However, STATE and LOGIC constants have been split into TWO files.
// Mind the following ranges and DO NOT MIX them:
// - state constants: 0..499
// - logic constants: 500..999
//

//
// access
//

/** The channel get access logic cyboi format. */
static int* CHANNEL_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count access logic cyboi format. */
static int* COUNT_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty indicate access logic cyboi format. */
static int* EMPTY_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encoding get access logic cyboi format. */
static int* ENCODING_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_503_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The exists indicate access logic cyboi format. */
static int* EXISTS_INDICATE_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_504_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The format get access logic cyboi format. */
static int* FORMAT_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_505_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The language get access logic cyboi format. */
static int* LANGUAGE_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_506_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The name get access logic cyboi format. */
static int* NAME_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_507_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The type get access logic cyboi format. */
static int* TYPE_GET_ACCESS_LOGIC_CYBOI_FORMAT = NUMBER_508_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// calculate
//

/** The absolute calculate logic cyboi format. */
static int* ABSOLUTE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_520_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The add calculate logic cyboi format. */
static int* ADD_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_521_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The divide calculate logic cyboi format. */
static int* DIVIDE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_522_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The modulo calculate logic cyboi format. */
static int* MODULO_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_523_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiply calculate logic cyboi format. */
static int* MULTIPLY_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_524_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The negate calculate logic cyboi format. */
static int* NEGATE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_525_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reduce calculate logic cyboi format. */
static int* REDUCE_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_526_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remainder calculate logic cyboi format. */
static int* REMAINDER_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_527_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The subtract calculate logic cyboi format. */
static int* SUBTRACT_CALCULATE_LOGIC_CYBOI_FORMAT = NUMBER_528_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// cast
//

/** The byte cast logic cyboi format. */
static int* BYTE_CAST_LOGIC_CYBOI_FORMAT = NUMBER_530_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The character cast logic cyboi format. */
static int* CHARACTER_CAST_LOGIC_CYBOI_FORMAT = NUMBER_531_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The double cast logic cyboi format. */
static int* DOUBLE_CAST_LOGIC_CYBOI_FORMAT = NUMBER_532_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The integer cast logic cyboi format. */
static int* INTEGER_CAST_LOGIC_CYBOI_FORMAT = NUMBER_533_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// communicate
//

/** The receive communicate logic cyboi format. */
static int* RECEIVE_COMMUNICATE_LOGIC_CYBOI_FORMAT = NUMBER_550_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The send communicate logic cyboi format. */
static int* SEND_COMMUNICATE_LOGIC_CYBOI_FORMAT = NUMBER_551_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// compare
//

/** The equal compare logic cyboi format. */
static int* EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater compare logic cyboi format. */
static int* GREATER_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal compare logic cyboi format. */
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_602_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller compare logic cyboi format. */
static int* SMALLER_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_603_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller-or-equal compare logic cyboi format. */
static int* SMALLER_OR_EQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_604_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal compare logic cyboi format. */
static int* UNEQUAL_COMPARE_LOGIC_CYBOI_FORMAT = NUMBER_605_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// convert
//

/** The decode convert logic cyboi format. */
static int* DECODE_CONVERT_LOGIC_CYBOI_FORMAT = NUMBER_650_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encode convert logic cyboi format. */
static int* ENCODE_CONVERT_LOGIC_CYBOI_FORMAT = NUMBER_651_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// command
//

/** The archive command logic cyboi format. */
static int* ARCHIVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy command logic cyboi format. */
static int* COPY_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The echo command logic cyboi format. */
static int* ECHO_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_702_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list-directory-contents command logic cyboi format. */
static int* LIST_DIRECTORY_CONTENTS_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_703_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The move command logic cyboi format. */
static int* MOVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_704_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove command logic cyboi format. */
static int* REMOVE_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_705_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The tape archiver command logic cyboi format. */
static int* TAPE_ARCHIVER_COMMAND_LOGIC_CYBOI_FORMAT = NUMBER_706_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// flow
//

/** The branch flow logic cyboi format. */
static int* BRANCH_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_750_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop flow logic cyboi format. */
static int* LOOP_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_751_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sequence flow logic cyboi format. */
static int* SEQUENCE_FLOW_LOGIC_CYBOI_FORMAT = NUMBER_752_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// live
//

/** The exit live logic cyboi format. */
static int* EXIT_LIVE_LOGIC_CYBOI_FORMAT = NUMBER_780_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interrupt live logic cyboi format. */
static int* INTERRUPT_LIVE_LOGIC_CYBOI_FORMAT = NUMBER_781_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sense live logic cyboi format. */
static int* SENSE_LIVE_LOGIC_CYBOI_FORMAT = NUMBER_782_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logify
//

/** The and logify logic cyboi format. */
static int* AND_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nand logify logic cyboi format. */
static int* NAND_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_801_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The neg logify logic cyboi format. */
static int* NEG_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_802_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nor logify logic cyboi format. */
static int* NOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_803_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not logify logic cyboi format. */
static int* NOT_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_804_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The or logify logic cyboi format. */
static int* OR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_805_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xnor logify logic cyboi format. */
static int* XNOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_806_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xor logify logic cyboi format. */
static int* XOR_LOGIFY_LOGIC_CYBOI_FORMAT = NUMBER_807_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// maintain
//

/** The shutdown maintain logic cyboi format. */
static int* SHUTDOWN_MAINTAIN_LOGIC_CYBOI_FORMAT = NUMBER_820_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The startup maintain logic cyboi format. */
static int* STARTUP_MAINTAIN_LOGIC_CYBOI_FORMAT = NUMBER_821_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// manipulate
//

/** The check manipulate logic cyboi format. */
static int* CHECK_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_850_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The clear manipulate logic cyboi format. */
static int* CLEAR_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_851_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate left manipulate logic cyboi format. */
static int* ROTATE_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_852_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate right manipulate logic cyboi format. */
static int* ROTATE_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_853_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The set manipulate logic cyboi format. */
static int* SET_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_854_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift left manipulate logic cyboi format. */
static int* SHIFT_LEFT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_855_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift right manipulate logic cyboi format. */
static int* SHIFT_RIGHT_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_856_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The toggle manipulate logic cyboi format. */
static int* TOGGLE_MANIPULATE_LOGIC_CYBOI_FORMAT = NUMBER_857_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// memorise
//

/** The create memorise logic cyboi format. */
static int* CREATE_MEMORISE_LOGIC_CYBOI_FORMAT = NUMBER_900_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy memorise logic cyboi format. */
static int* DESTROY_MEMORISE_LOGIC_CYBOI_FORMAT = NUMBER_901_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// modify
//

/** The append modify logic cyboi format. */
static int* APPEND_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_910_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The build modify logic cyboi format. */
static int* BUILD_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_911_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The empty modify logic cyboi format. */
static int* EMPTY_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_912_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The fill modify logic cyboi format. */
static int* FILL_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_913_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insert modify logic cyboi format. */
static int* INSERT_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_914_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overwrite modify logic cyboi format. */
static int* OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_915_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove modify logic cyboi format. */
static int* REMOVE_MODIFY_LOGIC_CYBOI_FORMAT = NUMBER_916_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// represent
//

/** The deserialise represent logic cyboi format. */
static int* DESERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT = NUMBER_920_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The serialise represent logic cyboi format. */
static int* SERIALISE_REPRESENT_LOGIC_CYBOI_FORMAT = NUMBER_921_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// run
//

/** The run logic cyboi format. */
static int* RUN_LOGIC_CYBOI_FORMAT = NUMBER_930_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nano sleep run logic cyboi format. */
static int* NANO_SLEEP_RUN_LOGIC_CYBOI_FORMAT = NUMBER_931_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The second sleep run logic cyboi format. */
static int* SECOND_SLEEP_RUN_LOGIC_CYBOI_FORMAT = NUMBER_932_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIC_CYBOI_FORMAT_CONSTANT_SOURCE */
#endif
