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

#ifndef LOGIC_CYBOL_CYBOI_TYPE_CONSTANT_SOURCE
#define LOGIC_CYBOL_CYBOI_TYPE_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

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
// Calculate.
//

/** The absolute logic cybol cyboi type. */
static int* ABSOLUTE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_500_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The add logic cybol cyboi type. */
static int* ADD_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_501_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The divide logic cybol cyboi type. */
static int* DIVIDE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_502_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The multiply logic cybol cyboi type. */
static int* MULTIPLY_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_503_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The negate logic cybol cyboi type. */
static int* NEGATE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_504_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reduce logic cybol cyboi type. */
static int* REDUCE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_505_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remainder logic cybol cyboi type. */
static int* REMAINDER_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_506_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The subtract logic cybol cyboi type. */
static int* SUBTRACT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_507_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Communicate.
//

/** The receive logic cybol cyboi type. */
static int* RECEIVE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_550_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The send logic cybol cyboi type. */
static int* SEND_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_551_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Compare.
//

/** The equal logic cybol cyboi type. */
static int* EQUAL_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_600_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-part logic cybol cyboi type. */
static int* EQUAL_PART_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_601_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-prefix logic cybol cyboi type. */
static int* EQUAL_PREFIX_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_602_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The equal-suffix logic cybol cyboi type. */
static int* EQUAL_SUFFIX_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_603_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater logic cybol cyboi type. */
static int* GREATER_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_604_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The greater-or-equal logic cybol cyboi type. */
static int* GREATER_OR_EQUAL_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_605_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller logic cybol cyboi type. */
static int* SMALLER_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_606_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The smaller-or-equal logic cybol cyboi type. */
static int* SMALLER_OR_EQUAL_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_607_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The unequal logic cybol cyboi type. */
static int* UNEQUAL_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_608_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Convert.
//

/** The decode logic cybol cyboi type. */
static int* DECODE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_650_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The encode logic cybol cyboi type. */
static int* ENCODE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_651_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// File.
//

/** The archive logic cybol cyboi type. */
static int* ARCHIVE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_700_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The copy logic cybol cyboi type. */
static int* COPY_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_701_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The list-directory-contents logic cybol cyboi type. */
static int* LIST_DIRECTORY_CONTENTS_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_702_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Flow.
//

/** The branch logic cybol cyboi type. */
static int* BRANCH_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_750_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The loop logic cybol cyboi type. */
static int* LOOP_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_751_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sequence logic cybol cyboi type. */
static int* SEQUENCE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_752_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Live.
//

/** The exit logic cybol cyboi type. */
static int* EXIT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_780_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The interrupt logic cybol cyboi type. */
static int* INTERRUPT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_781_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The sense logic cybol cyboi type. */
static int* SENSE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_782_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Logify.
//

/** The and logic cybol cyboi type. */
static int* AND_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_800_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nand logic cybol cyboi type. */
static int* NAND_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_801_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The neg logic cybol cyboi type. */
static int* NEG_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_802_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The nor logic cybol cyboi type. */
static int* NOR_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_803_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The not logic cybol cyboi type. */
static int* NOT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_804_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The or logic cybol cyboi type. */
static int* OR_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_805_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xnor logic cybol cyboi type. */
static int* XNOR_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_806_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The xor logic cybol cyboi type. */
static int* XOR_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_807_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Maintain.
//

/** The shutdown logic cybol cyboi type. */
static int* SHUTDOWN_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_820_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The startup logic cybol cyboi type. */
static int* STARTUP_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_821_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Manipulate.
//

/** The get logic cybol cyboi type. */
static int* GET_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_850_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The reset logic cybol cyboi type. */
static int* RESET_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_851_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate left logic cybol cyboi type. */
static int* ROTATE_LEFT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_852_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The rotate right logic cybol cyboi type. */
static int* ROTATE_RIGHT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_853_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The set logic cybol cyboi type. */
static int* SET_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_854_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift left logic cybol cyboi type. */
static int* SHIFT_LEFT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_855_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The shift right logic cybol cyboi type. */
static int* SHIFT_RIGHT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_856_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Memorise.
//

/** The create logic cybol cyboi type. */
static int* CREATE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_900_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The destroy logic cybol cyboi type. */
static int* DESTROY_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_901_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Modify.
//

/** The append logic cybol cyboi type. */
static int* APPEND_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_910_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The build logic cybol cyboi type. */
static int* BUILD_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_911_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The count logic cybol cyboi type. */
static int* COUNT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_912_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The get logic cybol cyboi type. */
static int* GET_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_913_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The insert logic cybol cyboi type. */
static int* INSERT_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_914_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The overwrite logic cybol cyboi type. */
static int* OVERWRITE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_915_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The remove logic cybol cyboi type. */
static int* REMOVE_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_916_INTEGER_STATE_CYBOI_MODEL_ARRAY;

//
// Run.
//

/** The run logic cybol cyboi type. */
static int* RUN_LOGIC_CYBOL_CYBOI_TYPE = NUMBER_999_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* LOGIC_CYBOL_CYBOI_TYPE_CONSTANT_SOURCE */
#endif
