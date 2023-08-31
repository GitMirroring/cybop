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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef VECTOR_STATE_CYBOI_NAME_CONSTANT_HEADER
#define VECTOR_STATE_CYBOI_NAME_CONSTANT_HEADER

//
// Library interface
//

#include "constant.h"

//
// The vector size is set in file "state_cyboi_model.h"!
//

/** The dimension 0 vector memory name. In a (spatial) vector, this is the x coordinate. */
static int* DIMENSION_0_VECTOR_STATE_CYBOI_NAME = NUMBER_0_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dimension 1 vector memory name. In a (spatial) vector, this is the y coordinate. */
static int* DIMENSION_1_VECTOR_STATE_CYBOI_NAME = NUMBER_1_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/** The dimension 2 vector memory name. In a (spatial) vector, this is the z coordinate. */
static int* DIMENSION_2_VECTOR_STATE_CYBOI_NAME = NUMBER_2_INTEGER_STATE_CYBOI_MODEL_ARRAY;

/* VECTOR_STATE_CYBOI_NAME_CONSTANT_HEADER */
#endif
