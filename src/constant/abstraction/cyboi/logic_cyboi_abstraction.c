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
// Compare.
//

/** The equal logic cyboi abstraction. */
static int* EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-part logic cyboi abstraction. */
static int* EQUAL_PART_LOGIC_CYBOI_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-prefix logic cyboi abstraction. */
static int* EQUAL_PREFIX_LOGIC_CYBOI_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The equal-suffix logic cyboi abstraction. */
static int* EQUAL_SUFFIX_LOGIC_CYBOI_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater logic cyboi abstraction. */
static int* GREATER_LOGIC_CYBOI_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The greater-or-equal logic cyboi abstraction. */
static int* GREATER_OR_EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller logic cyboi abstraction. */
static int* SMALLER_LOGIC_CYBOI_ABSTRACTION = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The smaller-or-equal logic cyboi abstraction. */
static int* SMALLER_OR_EQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The unequal logic cyboi abstraction. */
static int* UNEQUAL_LOGIC_CYBOI_ABSTRACTION = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

//
// Calculate.
//

/** The absolute logic cyboi abstraction. */
static int* ABSOLUTE_LOGIC_CYBOI_ABSTRACTION = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The add logic cyboi abstraction. */
static int* ADD_LOGIC_CYBOI_ABSTRACTION = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The divide logic cyboi abstraction. */
static int* DIVIDE_LOGIC_CYBOI_ABSTRACTION = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/** The multiply logic cyboi abstraction. */
static int* MULTIPLY_LOGIC_CYBOI_ABSTRACTION = NUMBER_13_INTEGER_MEMORY_MODEL_ARRAY;

/** The negate logic cyboi abstraction. */
static int* NEGATE_LOGIC_CYBOI_ABSTRACTION = NUMBER_14_INTEGER_MEMORY_MODEL_ARRAY;

/** The reduce logic cyboi abstraction. */
static int* REDUCE_LOGIC_CYBOI_ABSTRACTION = NUMBER_15_INTEGER_MEMORY_MODEL_ARRAY;

/** The subtract logic cyboi abstraction. */
static int* SUBTRACT_LOGIC_CYBOI_ABSTRACTION = NUMBER_16_INTEGER_MEMORY_MODEL_ARRAY;

//
// Memorise.
//

/** The create logic cyboi abstraction. */
static int* CREATE_LOGIC_CYBOI_ABSTRACTION = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The destroy logic cyboi abstraction. */
static int* DESTROY_LOGIC_CYBOI_ABSTRACTION = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

//
// Modify.
//

/** The append logic cyboi abstraction. */
static int* APPEND_LOGIC_CYBOI_ABSTRACTION = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The build logic cyboi abstraction. */
static int* BUILD_LOGIC_CYBOI_ABSTRACTION = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

/** The count logic cyboi abstraction. */
static int* COUNT_LOGIC_CYBOI_ABSTRACTION = NUMBER_32_INTEGER_MEMORY_MODEL_ARRAY;

/** The get logic cyboi abstraction. */
static int* GET_LOGIC_CYBOI_ABSTRACTION = NUMBER_33_INTEGER_MEMORY_MODEL_ARRAY;

/** The insert logic cyboi abstraction. */
static int* INSERT_LOGIC_CYBOI_ABSTRACTION = NUMBER_34_INTEGER_MEMORY_MODEL_ARRAY;

/** The overwrite logic cyboi abstraction. */
static int* OVERWRITE_LOGIC_CYBOI_ABSTRACTION = NUMBER_35_INTEGER_MEMORY_MODEL_ARRAY;

/** The remove logic cyboi abstraction. */
static int* REMOVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_36_INTEGER_MEMORY_MODEL_ARRAY;

//
// Flow.
//

/** The branch logic cyboi abstraction. */
static int* BRANCH_LOGIC_CYBOI_ABSTRACTION = NUMBER_40_INTEGER_MEMORY_MODEL_ARRAY;

/** The loop logic cyboi abstraction. */
static int* LOOP_LOGIC_CYBOI_ABSTRACTION = NUMBER_41_INTEGER_MEMORY_MODEL_ARRAY;

/** The sequence logic cyboi abstraction. */
static int* SEQUENCE_LOGIC_CYBOI_ABSTRACTION = NUMBER_42_INTEGER_MEMORY_MODEL_ARRAY;

//
// Convert.
//

/** The decode logic cyboi abstraction. */
static int* DECODE_LOGIC_CYBOI_ABSTRACTION = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The encode logic cyboi abstraction. */
static int* ENCODE_LOGIC_CYBOI_ABSTRACTION = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

//
// Maintain.
//

/** The shutdown logic cyboi abstraction. */
static int* SHUTDOWN_LOGIC_CYBOI_ABSTRACTION = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/** The startup logic cyboi abstraction. */
static int* STARTUP_LOGIC_CYBOI_ABSTRACTION = NUMBER_61_INTEGER_MEMORY_MODEL_ARRAY;

//
// Live.
//

/** The interrupt logic cyboi abstraction. */
static int* INTERRUPT_LOGIC_CYBOI_ABSTRACTION = NUMBER_70_INTEGER_MEMORY_MODEL_ARRAY;

/** The sense logic cyboi abstraction. */
static int* SENSE_LOGIC_CYBOI_ABSTRACTION = NUMBER_71_INTEGER_MEMORY_MODEL_ARRAY;

//
// Communicate.
//

/** The receive logic cyboi abstraction. */
static int* RECEIVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_80_INTEGER_MEMORY_MODEL_ARRAY;

/** The send logic cyboi abstraction. */
static int* SEND_LOGIC_CYBOI_ABSTRACTION = NUMBER_81_INTEGER_MEMORY_MODEL_ARRAY;

//
// File.
//

/** The archive logic cyboi abstraction. */
static int* ARCHIVE_LOGIC_CYBOI_ABSTRACTION = NUMBER_90_INTEGER_MEMORY_MODEL_ARRAY;

/** The copy logic cyboi abstraction. */
static int* COPY_LOGIC_CYBOI_ABSTRACTION = NUMBER_91_INTEGER_MEMORY_MODEL_ARRAY;

/** The list-directory-contents logic cyboi abstraction. */
static int* LIST_DIRECTORY_CONTENTS_LOGIC_CYBOI_ABSTRACTION = NUMBER_92_INTEGER_MEMORY_MODEL_ARRAY;

//
// Run.
//

/** The run logic cyboi abstraction. */
static int* RUN_LOGIC_CYBOI_ABSTRACTION = NUMBER_100_INTEGER_MEMORY_MODEL_ARRAY;

/* LOGIC_CYBOI_ABSTRACTION_CONSTANT_SOURCE */
#endif
