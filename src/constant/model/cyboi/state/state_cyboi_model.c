/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STATE_CYBOI_MODEL_CONSTANT_SOURCE
#define STATE_CYBOI_MODEL_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/extra_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The internal memory cyboi model count.
 *
 * CAUTION! The total number of possible socket ports/services alone is: 65,536
 * Therefore, the internal memory size has to be greater than that, currently 100,000.
 * Also, before the socket base, there are some other input/output values,
 * e.g. for serial port, terminal, display etc. which have to be taken into account.
 */
static int* INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT = NUMBER_100000_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The item cyboi model count. */
static int* ITEM_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The part cyboi model count. */
static int* PART_STATE_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The primitive cyboi model count. */
static int* PRIMITIVE_STATE_CYBOI_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vector cyboi model count. */
static int* VECTOR_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
