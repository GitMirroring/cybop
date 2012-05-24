/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef REALLOCATION_FACTOR_SOURCE
#define REALLOCATION_FACTOR_SOURCE

//
// CAUTION! Do NOT try to assign any values here!
// Otherwise, the compiler shows the following error:
// "error: initializer element is not constant"
// Therefore, the variables are only initialised in module "globaliser.c".
//

/** The array reallocation factor. */
static int ARRAY_REALLOCATION_FACTOR_ARRAY[] = {2};
static int* ARRAY_REALLOCATION_FACTOR = ARRAY_REALLOCATION_FACTOR_ARRAY;

/** The cybol file reallocation factor. */
static int CYBOL_FILE_REALLOCATION_FACTOR_ARRAY[] = {2};
static int* CYBOL_FILE_REALLOCATION_FACTOR = CYBOL_FILE_REALLOCATION_FACTOR_ARRAY;

/** The compound reallocation factor. */
static int COMPOUND_REALLOCATION_FACTOR_ARRAY[] = {2};
static int* COMPOUND_REALLOCATION_FACTOR = COMPOUND_REALLOCATION_FACTOR_ARRAY;

/* REALLOCATION_FACTOR_SOURCE */
#endif
