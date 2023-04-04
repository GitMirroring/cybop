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

#ifndef STATE_CYBOI_MODEL_CONSTANT_HEADER
#define STATE_CYBOI_MODEL_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

/** The client entry state cyboi model count. */
static int* CLIENT_ENTRY_STATE_CYBOI_MODEL_COUNT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The input output entry state cyboi model count. */
static int* INPUT_OUTPUT_ENTRY_STATE_CYBOI_MODEL_COUNT = NUMBER_10_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The internal memory state cyboi model count. */
static int* INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT = NUMBER_30_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The item state cyboi model count. */
static int* ITEM_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The part state cyboi model count. */
static int* PART_STATE_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The primitive state cyboi model count. */
static int* PRIMITIVE_STATE_CYBOI_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The server entry state cyboi model count. */
static int* SERVER_ENTRY_STATE_CYBOI_MODEL_COUNT = NUMBER_100_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vector state cyboi model count. */
static int* VECTOR_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_MODEL_CONSTANT_HEADER */
#endif
