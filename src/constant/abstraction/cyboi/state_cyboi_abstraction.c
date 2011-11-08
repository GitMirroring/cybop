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

#ifndef STATE_CYBOI_ABSTRACTION_CONSTANT_SOURCE
#define STATE_CYBOI_ABSTRACTION_CONSTANT_SOURCE

#include <stddef.h>

#include "../../../constant/model/memory/integer_memory_model.c"

//
// CAUTION! These constants have been put into just ONE file,
// because they have to be assigned a unique identification integer,
// which is easier to verify having they here altogether.
//

//
// Pointer.
//

/** The pointer state cyboi abstraction. */
static int* POINTER_STATE_CYBOI_ABSTRACTION = NUMBER_0_INTEGER_MEMORY_MODEL_ARRAY;

//
// Logic value.
//

/** The boolean state cyboi abstraction. */
static int* BOOLEAN_STATE_CYBOI_ABSTRACTION = NUMBER_10_INTEGER_MEMORY_MODEL_ARRAY;

//
// Number.
//

/** The complex state cyboi abstraction. */
static int* COMPLEX_STATE_CYBOI_ABSTRACTION = NUMBER_20_INTEGER_MEMORY_MODEL_ARRAY;

/** The double state cyboi abstraction. */
static int* DOUBLE_STATE_CYBOI_ABSTRACTION = NUMBER_21_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction state cyboi abstraction. */
static int* FRACTION_STATE_CYBOI_ABSTRACTION = NUMBER_22_INTEGER_MEMORY_MODEL_ARRAY;

/** The integer state cyboi abstraction. */
static int* INTEGER_STATE_CYBOI_ABSTRACTION = NUMBER_23_INTEGER_MEMORY_MODEL_ARRAY;

/** The unsigned long state cyboi abstraction. */
static int* UNSIGNED_LONG_STATE_CYBOI_ABSTRACTION = NUMBER_24_INTEGER_MEMORY_MODEL_ARRAY;

//
// Text.
//

/** The character state cyboi abstraction. */
static int* CHARACTER_STATE_CYBOI_ABSTRACTION = NUMBER_30_INTEGER_MEMORY_MODEL_ARRAY;

/** The wide character state cyboi abstraction. */
static int* WIDE_CHARACTER_STATE_CYBOI_ABSTRACTION = NUMBER_31_INTEGER_MEMORY_MODEL_ARRAY;

//
// Date time.
//

/** The datetime state cyboi abstraction. */
static int* DATETIME_STATE_CYBOI_ABSTRACTION = NUMBER_40_INTEGER_MEMORY_MODEL_ARRAY;

//
// Path.
//

/** The encapsulated knowledge path state cyboi abstraction. */
static int* ENCAPSULATED_KNOWLEDGE_PATH_STATE_CYBOI_ABSTRACTION = NUMBER_50_INTEGER_MEMORY_MODEL_ARRAY;

/** The knowledge path state cyboi abstraction. */
static int* KNOWLEDGE_PATH_STATE_CYBOI_ABSTRACTION = NUMBER_51_INTEGER_MEMORY_MODEL_ARRAY;

//
// Part.
//

/** The part state cyboi abstraction. */
static int* PART_STATE_CYBOI_ABSTRACTION = NUMBER_60_INTEGER_MEMORY_MODEL_ARRAY;

/* STATE_CYBOI_ABSTRACTION_CONSTANT_SOURCE */
#endif
