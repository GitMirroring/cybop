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

#ifndef POINTER_STATE_CYBOI_MODEL_CONSTANT_HEADER
#define POINTER_STATE_CYBOI_MODEL_CONSTANT_HEADER

/**
 * The null pointer cyboi model.
 *
 * CAUTION! Do NOT try to use *NUMBER_0_INTEGER_STATE_CYBOI_MODEL here instead of the value 0!
 * Otherwise, the system would show the following error, as it expects a constant value:
 * "error: initializer element is not constant"
 */
static void* NULL_POINTER_STATE_CYBOI_MODEL_ARRAY[] = { (void*) 0 };
static void** NULL_POINTER_STATE_CYBOI_MODEL = NULL_POINTER_STATE_CYBOI_MODEL_ARRAY;

/* POINTER_STATE_CYBOI_MODEL_CONSTANT_HEADER */
#endif
