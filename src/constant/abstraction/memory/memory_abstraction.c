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

#ifndef MEMORY_ABSTRACTION_SOURCE
#define MEMORY_ABSTRACTION_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

/**
 * The memory abstraction count.
 *
 * This count is valid for ALL memory abstractions below,
 * as they are just integer numbers.
 */
static int* MEMORY_ABSTRACTION_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The character memory abstraction. */
static int* CHARACTER_MEMORY_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

/** The complex memory abstraction. */
static int* COMPLEX_MEMORY_ABSTRACTION = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/** The datetime memory abstraction. */
static int* DATETIME_MEMORY_ABSTRACTION = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The double memory abstraction. */
static int* DOUBLE_MEMORY_ABSTRACTION = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The encapsulated knowledge path memory abstraction. */
static int* ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_ABSTRACTION = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction memory abstraction. */
static int* FRACTION_MEMORY_ABSTRACTION = NUMBER_5_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer memory abstraction. */
static int* INTEGER_MEMORY_ABSTRACTION = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The knowledge path memory abstraction. */
static int* KNOWLEDGE_PATH_MEMORY_ABSTRACTION = NUMBER_7_INTEGER_MEMORY_MODEL_ARRAY;

/** The operation memory abstraction. */
static int* OPERATION_MEMORY_ABSTRACTION = NUMBER_8_INTEGER_MEMORY_MODEL_ARRAY;

/** The part memory abstraction. */
static int* PART_MEMORY_ABSTRACTION = NUMBER_9_INTEGER_MEMORY_MODEL_ARRAY;

/** The pointer memory abstraction. */
static int* POINTER_MEMORY_ABSTRACTION = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long memory abstraction. */
static int* UNSIGNED_LONG_MEMORY_ABSTRACTION = NUMBER_11_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character memory abstraction. */
static int* WIDE_CHARACTER_MEMORY_ABSTRACTION = NUMBER_12_INTEGER_MEMORY_MODEL_ARRAY;

/* MEMORY_ABSTRACTION_SOURCE */
#endif
