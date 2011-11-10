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

#ifndef LOGIC_CYBOI_TYPE_CONSTANT_SOURCE
#define LOGIC_CYBOI_TYPE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//

//
// Logify.
//

/** The not logic cyboi type. */
static int* NOT_LOGIC_CYBOI_TYPE = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The and logic cyboi type. */
static int* AND_LOGIC_CYBOI_TYPE = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The or logic cyboi type. */
static int* OR_LOGIC_CYBOI_TYPE = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nand logic cyboi type. */
static int* NAND_LOGIC_CYBOI_TYPE = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nor logic cyboi type. */
static int* NOR_LOGIC_CYBOI_TYPE = NUMBER_4_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xor logic cyboi type. */
static int* XOR_LOGIC_CYBOI_TYPE = NUMBER_5_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xnor logic cyboi type. */
static int* XNOR_LOGIC_CYBOI_TYPE = NUMBER_6_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Compare.
//

/** The equal logic cyboi type. */
static int* EQUAL_LOGIC_CYBOI_TYPE = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-part logic cyboi type. */
static int* EQUAL_PART_LOGIC_CYBOI_TYPE = NUMBER_51_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-prefix logic cyboi type. */
static int* EQUAL_PREFIX_LOGIC_CYBOI_TYPE = NUMBER_52_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-suffix logic cyboi type. */
static int* EQUAL_SUFFIX_LOGIC_CYBOI_TYPE = NUMBER_53_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater logic cyboi type. */
static int* GREATER_LOGIC_CYBOI_TYPE = NUMBER_54_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal logic cyboi type. */
static int* GREATER_OR_EQUAL_LOGIC_CYBOI_TYPE = NUMBER_55_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller logic cyboi type. */
static int* SMALLER_LOGIC_CYBOI_TYPE = NUMBER_56_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller-or-equal logic cyboi type. */
static int* SMALLER_OR_EQUAL_LOGIC_CYBOI_TYPE = NUMBER_57_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal logic cyboi type. */
static int* UNEQUAL_LOGIC_CYBOI_TYPE = NUMBER_58_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Calculate.
//

/** The absolute logic cyboi type. */
static int* ABSOLUTE_LOGIC_CYBOI_TYPE = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The add logic cyboi type. */
static int* ADD_LOGIC_CYBOI_TYPE = NUMBER_101_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The divide logic cyboi type. */
static int* DIVIDE_LOGIC_CYBOI_TYPE = NUMBER_102_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiply logic cyboi type. */
static int* MULTIPLY_LOGIC_CYBOI_TYPE = NUMBER_103_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The negate logic cyboi type. */
static int* NEGATE_LOGIC_CYBOI_TYPE = NUMBER_104_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reduce logic cyboi type. */
static int* REDUCE_LOGIC_CYBOI_TYPE = NUMBER_105_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remainder logic cyboi type. */
static int* REMAINDER_LOGIC_CYBOI_TYPE = NUMBER_106_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The subtract logic cyboi type. */
static int* SUBTRACT_LOGIC_CYBOI_TYPE = NUMBER_107_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Memorise.
//

/** The create logic cyboi type. */
static int* CREATE_LOGIC_CYBOI_TYPE = NUMBER_200_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy logic cyboi type. */
static int* DESTROY_LOGIC_CYBOI_TYPE = NUMBER_201_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Modify.
//

/** The append logic cyboi type. */
static int* APPEND_LOGIC_CYBOI_TYPE = NUMBER_210_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The build logic cyboi type. */
static int* BUILD_LOGIC_CYBOI_TYPE = NUMBER_211_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count logic cyboi type. */
static int* COUNT_LOGIC_CYBOI_TYPE = NUMBER_212_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The get logic cyboi type. */
static int* GET_LOGIC_CYBOI_TYPE = NUMBER_213_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insert logic cyboi type. */
static int* INSERT_LOGIC_CYBOI_TYPE = NUMBER_214_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overwrite logic cyboi type. */
static int* OVERWRITE_LOGIC_CYBOI_TYPE = NUMBER_215_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove logic cyboi type. */
static int* REMOVE_LOGIC_CYBOI_TYPE = NUMBER_216_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Flow.
//

/** The branch logic cyboi type. */
static int* BRANCH_LOGIC_CYBOI_TYPE = NUMBER_300_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop logic cyboi type. */
static int* LOOP_LOGIC_CYBOI_TYPE = NUMBER_301_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sequence logic cyboi type. */
static int* SEQUENCE_LOGIC_CYBOI_TYPE = NUMBER_302_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Convert.
//

/** The decode logic cyboi type. */
static int* DECODE_LOGIC_CYBOI_TYPE = NUMBER_400_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encode logic cyboi type. */
static int* ENCODE_LOGIC_CYBOI_TYPE = NUMBER_401_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Maintain.
//

/** The shutdown logic cyboi type. */
static int* SHUTDOWN_LOGIC_CYBOI_TYPE = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The startup logic cyboi type. */
static int* STARTUP_LOGIC_CYBOI_TYPE = NUMBER_501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Live.
//

/** The interrupt logic cyboi type. */
static int* INTERRUPT_LOGIC_CYBOI_TYPE = NUMBER_510_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sense logic cyboi type. */
static int* SENSE_LOGIC_CYBOI_TYPE = NUMBER_511_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Communicate.
//

/** The receive logic cyboi type. */
static int* RECEIVE_LOGIC_CYBOI_TYPE = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The send logic cyboi type. */
static int* SEND_LOGIC_CYBOI_TYPE = NUMBER_601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// File.
//

/** The archive logic cyboi type. */
static int* ARCHIVE_LOGIC_CYBOI_TYPE = NUMBER_800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy logic cyboi type. */
static int* COPY_LOGIC_CYBOI_TYPE = NUMBER_801_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list-directory-contents logic cyboi type. */
static int* LIST_DIRECTORY_CONTENTS_LOGIC_CYBOI_TYPE = NUMBER_802_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Run.
//

/** The run logic cyboi type. */
static int* RUN_LOGIC_CYBOI_TYPE = NUMBER_1000_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIC_CYBOI_TYPE_CONSTANT_SOURCE */
#endif
