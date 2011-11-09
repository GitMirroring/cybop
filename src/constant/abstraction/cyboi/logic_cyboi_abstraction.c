/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: memory_abstraction.c,v $ $Revision: 1.12 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef LOGIC_CYBOI_ABSTRACTION_CONSTANT_SOURCE
#define LOGIC_CYBOI_ABSTRACTION_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//

//
// Logify.
//

/** The not logic cyboi abstraction. */
static int* NOT_LOGIC_CYBOI_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The and logic cyboi abstraction. */
static int* AND_LOGIC_CYBOI_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The or logic cyboi abstraction. */
static int* OR_LOGIC_CYBOI_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The nand logic cyboi abstraction. */
static int* NAND_LOGIC_CYBOI_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The nor logic cyboi abstraction. */
static int* NOR_LOGIC_CYBOI_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The xor logic cyboi abstraction. */
static int* XOR_LOGIC_CYBOI_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The xnor logic cyboi abstraction. */
static int* XNOR_LOGIC_CYBOI_ABSTRACTION = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

//
// Compare.
//

/** The equal logic cyboi abstraction. */
static int* EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-part logic cyboi abstraction. */
static int* EQUAL_PART_LOGIC_CYBOI_ABSTRACTION = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-prefix logic cyboi abstraction. */
static int* EQUAL_PREFIX_LOGIC_CYBOI_ABSTRACTION = NUMBER_52_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-suffix logic cyboi abstraction. */
static int* EQUAL_SUFFIX_LOGIC_CYBOI_ABSTRACTION = NUMBER_53_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater logic cyboi abstraction. */
static int* GREATER_LOGIC_CYBOI_ABSTRACTION = NUMBER_54_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater-or-equal logic cyboi abstraction. */
static int* GREATER_OR_EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_55_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller logic cyboi abstraction. */
static int* SMALLER_LOGIC_CYBOI_ABSTRACTION = NUMBER_56_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller-or-equal logic cyboi abstraction. */
static int* SMALLER_OR_EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_57_INTEGER_MEMORY_MODEL_ARRAY;

/** The unequal logic cyboi abstraction. */
static int* UNEQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_58_INTEGER_MEMORY_MODEL_ARRAY;

//
// Calculate.
//

/** The absolute logic cyboi abstraction. */
static int* ABSOLUTE_LOGIC_CYBOI_ABSTRACTION = NUMBER_100_INTEGER_MEMORY_MODEL_ARRAY;

/** The add logic cyboi abstraction. */
static int* ADD_LOGIC_CYBOI_ABSTRACTION = NUMBER_101_INTEGER_MEMORY_MODEL_ARRAY;

/** The divide logic cyboi abstraction. */
static int* DIVIDE_LOGIC_CYBOI_ABSTRACTION = NUMBER_102_INTEGER_MEMORY_MODEL_ARRAY;

/** The multiply logic cyboi abstraction. */
static int* MULTIPLY_LOGIC_CYBOI_ABSTRACTION = NUMBER_103_INTEGER_MEMORY_MODEL_ARRAY;

/** The negate logic cyboi abstraction. */
static int* NEGATE_LOGIC_CYBOI_ABSTRACTION = NUMBER_104_INTEGER_MEMORY_MODEL_ARRAY;

/** The reduce logic cyboi abstraction. */
static int* REDUCE_LOGIC_CYBOI_ABSTRACTION = NUMBER_105_INTEGER_MEMORY_MODEL_ARRAY;

/** The remainder logic cyboi abstraction. */
static int* REMAINDER_LOGIC_CYBOI_ABSTRACTION = NUMBER_106_INTEGER_MEMORY_MODEL_ARRAY;

/** The subtract logic cyboi abstraction. */
static int* SUBTRACT_LOGIC_CYBOI_ABSTRACTION = NUMBER_107_INTEGER_MEMORY_MODEL_ARRAY;

//
// Memorise.
//

/** The create logic cyboi abstraction. */
static int* CREATE_LOGIC_CYBOI_ABSTRACTION = NUMBER_200_INTEGER_MEMORY_MODEL_ARRAY;

/** The destroy logic cyboi abstraction. */
static int* DESTROY_LOGIC_CYBOI_ABSTRACTION = NUMBER_201_INTEGER_MEMORY_MODEL_ARRAY;

//
// Modify.
//

/** The append logic cyboi abstraction. */
static int* APPEND_LOGIC_CYBOI_ABSTRACTION = NUMBER_210_INTEGER_MEMORY_MODEL_ARRAY;

/** The build logic cyboi abstraction. */
static int* BUILD_LOGIC_CYBOI_ABSTRACTION = NUMBER_211_INTEGER_MEMORY_MODEL_ARRAY;

/** The count logic cyboi abstraction. */
static int* COUNT_LOGIC_CYBOI_ABSTRACTION = NUMBER_212_INTEGER_MEMORY_MODEL_ARRAY;

/** The get logic cyboi abstraction. */
static int* GET_LOGIC_CYBOI_ABSTRACTION = NUMBER_213_INTEGER_MEMORY_MODEL_ARRAY;

/** The insert logic cyboi abstraction. */
static int* INSERT_LOGIC_CYBOI_ABSTRACTION = NUMBER_214_INTEGER_MEMORY_MODEL_ARRAY;

/** The overwrite logic cyboi abstraction. */
static int* OVERWRITE_LOGIC_CYBOI_ABSTRACTION = NUMBER_215_INTEGER_MEMORY_MODEL_ARRAY;

/** The remove logic cyboi abstraction. */
static int* REMOVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_216_INTEGER_MEMORY_MODEL_ARRAY;

//
// Flow.
//

/** The branch logic cyboi abstraction. */
static int* BRANCH_LOGIC_CYBOI_ABSTRACTION = NUMBER_300_INTEGER_MEMORY_MODEL_ARRAY;

/** The loop logic cyboi abstraction. */
static int* LOOP_LOGIC_CYBOI_ABSTRACTION = NUMBER_301_INTEGER_MEMORY_MODEL_ARRAY;

/** The sequence logic cyboi abstraction. */
static int* SEQUENCE_LOGIC_CYBOI_ABSTRACTION = NUMBER_302_INTEGER_MEMORY_MODEL_ARRAY;

//
// Convert.
//

/** The decode logic cyboi abstraction. */
static int* DECODE_LOGIC_CYBOI_ABSTRACTION = NUMBER_400_INTEGER_MEMORY_MODEL_ARRAY;

/** The encode logic cyboi abstraction. */
static int* ENCODE_LOGIC_CYBOI_ABSTRACTION = NUMBER_401_INTEGER_MEMORY_MODEL_ARRAY;

//
// Maintain.
//

/** The shutdown logic cyboi abstraction. */
static int* SHUTDOWN_LOGIC_CYBOI_ABSTRACTION = NUMBER_500_INTEGER_MEMORY_MODEL_ARRAY;

/** The startup logic cyboi abstraction. */
static int* STARTUP_LOGIC_CYBOI_ABSTRACTION = NUMBER_501_INTEGER_MEMORY_MODEL_ARRAY;

//
// Live.
//

/** The interrupt logic cyboi abstraction. */
static int* INTERRUPT_LOGIC_CYBOI_ABSTRACTION = NUMBER_510_INTEGER_MEMORY_MODEL_ARRAY;

/** The sense logic cyboi abstraction. */
static int* SENSE_LOGIC_CYBOI_ABSTRACTION = NUMBER_511_INTEGER_MEMORY_MODEL_ARRAY;

//
// Communicate.
//

/** The receive logic cyboi abstraction. */
static int* RECEIVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_600_INTEGER_MEMORY_MODEL_ARRAY;

/** The send logic cyboi abstraction. */
static int* SEND_LOGIC_CYBOI_ABSTRACTION = NUMBER_601_INTEGER_MEMORY_MODEL_ARRAY;

//
// File.
//

/** The archive logic cyboi abstraction. */
static int* ARCHIVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_800_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy logic cyboi abstraction. */
static int* COPY_LOGIC_CYBOI_ABSTRACTION = NUMBER_801_INTEGER_MEMORY_MODEL_ARRAY;

/** The list-directory-contents logic cyboi abstraction. */
static int* LIST_DIRECTORY_CONTENTS_LOGIC_CYBOI_ABSTRACTION = NUMBER_802_INTEGER_MEMORY_MODEL_ARRAY;

//
// Run.
//

/** The run logic cyboi abstraction. */
static int* RUN_LOGIC_CYBOI_ABSTRACTION = NUMBER_1000_INTEGER_MEMORY_MODEL_ARRAY;

/* LOGIC_CYBOI_ABSTRACTION_CONSTANT_SOURCE */
#endif
