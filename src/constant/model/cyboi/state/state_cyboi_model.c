/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef STATE_CYBOI_MODEL_CONSTANT_SOURCE
#define STATE_CYBOI_MODEL_CONSTANT_SOURCE

#include "../../../../constant/model/cyboi/state/extra_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"

/**
 * The internal memory state cyboi model count.
 *
 * CAUTION! The total number of possible socket ports/services alone is: 65,536.
 * Therefore, the internal memory size has to be greater than that.
 * It is currently set to the power of two 98304 = 65536 + 32768,
 * for easier memory allocation handling.
 *
 * Also, before the socket base, there are some other input/output values,
 * e.g. for serial port, terminal, display etc. which have to be taken into account.
 * See internal memory indices in file "internal_memory_state_cyboi_name.c"!
 *
 * A standard central processing unit (cpu) = processor
 * has a value around 256 in its interrupt descriptor table (idt).
 */
static int* INTERNAL_MEMORY_STATE_CYBOI_MODEL_COUNT = NUMBER_98304_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The input/output entry state cyboi model count. */
static int* IO_ENTRY_STATE_CYBOI_MODEL_COUNT = NUMBER_50_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The item state cyboi model count. */
static int* ITEM_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The part state cyboi model count. */
static int* PART_STATE_CYBOI_MODEL_COUNT = NUMBER_9_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The primitive state cyboi model count. */
static int* PRIMITIVE_STATE_CYBOI_MODEL_COUNT = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The vector state cyboi model count. */
static int* VECTOR_STATE_CYBOI_MODEL_COUNT = NUMBER_3_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* STATE_CYBOI_MODEL_CONSTANT_SOURCE */
#endif
