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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGIC_FORMAT_TYPE_CONSTANT_SOURCE
#define LOGIC_FORMAT_TYPE_CONSTANT_SOURCE

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
// calculate
//

/** The absolute calculate logic format type. */
static int* ABSOLUTE_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The add calculate logic format type. */
static int* ADD_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The divide calculate logic format type. */
static int* DIVIDE_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiply calculate logic format type. */
static int* MULTIPLY_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_503_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The negate calculate logic format type. */
static int* NEGATE_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_504_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reduce calculate logic format type. */
static int* REDUCE_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_505_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remainder calculate logic format type. */
static int* REMAINDER_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_506_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The subtract calculate logic format type. */
static int* SUBTRACT_CALCULATE_LOGIC_FORMAT_TYPE = NUMBER_507_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// communicate
//

/** The receive communicate logic format type. */
static int* RECEIVE_COMMUNICATE_LOGIC_FORMAT_TYPE = NUMBER_550_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The send communicate logic format type. */
static int* SEND_COMMUNICATE_LOGIC_FORMAT_TYPE = NUMBER_551_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// compare
//

/** The equal compare logic format type. */
static int* EQUAL_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-part compare logic format type. */
static int* EQUAL_PART_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-prefix compare logic format type. */
static int* EQUAL_PREFIX_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_602_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-suffix compare logic format type. */
static int* EQUAL_SUFFIX_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_603_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater compare logic format type. */
static int* GREATER_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_604_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal compare logic format type. */
static int* GREATER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_605_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller compare logic format type. */
static int* SMALLER_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_606_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller-or-equal compare logic format type. */
static int* SMALLER_OR_EQUAL_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal compare logic format type. */
static int* UNEQUAL_COMPARE_LOGIC_FORMAT_TYPE = NUMBER_608_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// convert
//

/** The decode convert logic format type. */
static int* DECODE_CONVERT_LOGIC_FORMAT_TYPE = NUMBER_650_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encode convert logic format type. */
static int* ENCODE_CONVERT_LOGIC_FORMAT_TYPE = NUMBER_651_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// file
//

/** The archive file logic format type. */
static int* ARCHIVE_FILE_LOGIC_FORMAT_TYPE = NUMBER_700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy file logic format type. */
static int* COPY_FILE_LOGIC_FORMAT_TYPE = NUMBER_701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list-directory-contents file logic format type. */
static int* LIST_DIRECTORY_CONTENTS_FILE_LOGIC_FORMAT_TYPE = NUMBER_702_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// flow
//

/** The branch flow logic format type. */
static int* BRANCH_FLOW_LOGIC_FORMAT_TYPE = NUMBER_750_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop flow logic format type. */
static int* LOOP_FLOW_LOGIC_FORMAT_TYPE = NUMBER_751_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sequence flow logic format type. */
static int* SEQUENCE_FLOW_LOGIC_FORMAT_TYPE = NUMBER_752_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// live
//

/** The exit live logic format type. */
static int* EXIT_LIVE_LOGIC_FORMAT_TYPE = NUMBER_780_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interrupt live logic format type. */
static int* INTERRUPT_LIVE_LOGIC_FORMAT_TYPE = NUMBER_781_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sense live logic format type. */
static int* SENSE_LIVE_LOGIC_FORMAT_TYPE = NUMBER_782_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// logify
//

/** The and logify logic format type. */
static int* AND_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nand logify logic format type. */
static int* NAND_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_801_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The neg logify logic format type. */
static int* NEG_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_802_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nor logify logic format type. */
static int* NOR_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_803_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not logify logic format type. */
static int* NOT_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_804_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The or logify logic format type. */
static int* OR_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_805_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xnor logify logic format type. */
static int* XNOR_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_806_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xor logify logic format type. */
static int* XOR_LOGIFY_LOGIC_FORMAT_TYPE = NUMBER_807_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// maintain
//

/** The shutdown maintain logic format type. */
static int* SHUTDOWN_MAINTAIN_LOGIC_FORMAT_TYPE = NUMBER_820_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The startup maintain logic format type. */
static int* STARTUP_MAINTAIN_LOGIC_FORMAT_TYPE = NUMBER_821_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// manipulate
//

/** The get manipulate logic format type. */
static int* GET_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_850_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reset manipulate logic format type. */
static int* RESET_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_851_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate left manipulate logic format type. */
static int* ROTATE_LEFT_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_852_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate right manipulate logic format type. */
static int* ROTATE_RIGHT_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_853_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The set manipulate logic format type. */
static int* SET_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_854_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift left manipulate logic format type. */
static int* SHIFT_LEFT_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_855_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift right manipulate logic format type. */
static int* SHIFT_RIGHT_MANIPULATE_LOGIC_FORMAT_TYPE = NUMBER_856_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// memorise
//

/** The create memorise logic format type. */
static int* CREATE_MEMORISE_LOGIC_FORMAT_TYPE = NUMBER_900_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy memorise logic format type. */
static int* DESTROY_MEMORISE_LOGIC_FORMAT_TYPE = NUMBER_901_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// modify
//

/** The append modify logic format type. */
static int* APPEND_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_910_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The build modify logic format type. */
static int* BUILD_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_911_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count modify logic format type. */
static int* COUNT_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_912_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The get modify logic format type. */
static int* GET_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_913_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insert modify logic format type. */
static int* INSERT_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_914_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overwrite modify logic format type. */
static int* OVERWRITE_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_915_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove modify logic format type. */
static int* REMOVE_MODIFY_LOGIC_FORMAT_TYPE = NUMBER_916_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// run
//

/** The run logic format type. */
static int* RUN_LOGIC_FORMAT_TYPE = NUMBER_999_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIC_FORMAT_TYPE_CONSTANT_SOURCE */
#endif
