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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REFERENCE_COUNTER_SOURCE
#define REFERENCE_COUNTER_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

/** The array reference counter. */
static int ARRAY_REFERENCE_COUNTER_ARRAY[1];
static int* ARRAY_REFERENCE_COUNTER = ARRAY_REFERENCE_COUNTER_ARRAY;

/** The item reference counter. */
static int ITEM_REFERENCE_COUNTER_ARRAY[1];
static int* ITEM_REFERENCE_COUNTER = ITEM_REFERENCE_COUNTER_ARRAY;

/** The part reference counter. */
static int PART_REFERENCE_COUNTER_ARRAY[1];
static int* PART_REFERENCE_COUNTER = PART_REFERENCE_COUNTER_ARRAY;

/* REFERENCE_COUNTER_SOURCE */
#endif
