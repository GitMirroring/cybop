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
 * @version $RCSfile: memory_model.c,v $ $Revision: 1.3 $ $Date: 2009-01-31 16:06:30 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STATE_CYBOI_MODEL_CONSTANT_SOURCE
#define STATE_CYBOI_MODEL_CONSTANT_SOURCE

#include "../../constant/model/memory/integer_memory_model.c"

/** The complex cyboi model count. */
static int* COMPLEX_STATE_CYBOI_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The datetime cyboi model count. */
static int* DATETIME_STATE_CYBOI_MODEL_COUNT = NUMBER_6_INTEGER_MEMORY_MODEL_ARRAY;

/** The fraction cyboi model count. */
static int* FRACTION_STATE_CYBOI_MODEL_COUNT = NUMBER_2_INTEGER_MEMORY_MODEL_ARRAY;

/** The internal memory cyboi model count. */
static int* INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT = NUMBER_1000_INTEGER_MEMORY_MODEL_ARRAY;

/** The item cyboi model count. */
static int* ITEM_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_MEMORY_MODEL_ARRAY;

/** The part cyboi model count. */
static int* PART_STATE_CYBOI_MODEL_COUNT = NUMBER_4_INTEGER_MEMORY_MODEL_ARRAY;

/** The primitive cyboi model count. */
static int* PRIMITIVE_STATE_CYBOI_MODEL_COUNT = NUMBER_1_INTEGER_MEMORY_MODEL_ARRAY;

/* STATE_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
