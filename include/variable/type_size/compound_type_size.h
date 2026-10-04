/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPOUND_TYPE_SIZE_VARIABLE_HEADER
#define COMPOUND_TYPE_SIZE_VARIABLE_HEADER

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// Some data types are composed of several fields, e.g.:
// - datetime
// - duration
// - fraction number
// - complex number
//
// These are usually not offered by a programming library
// and therefore have to be defined here.
//
// CAUTION! In a first effort, it was tried to provide compound
// data types as special structures to be allocated within cyboi.
// However, there is one big problem: MEMORY LEAKS!
//
// When copying compound source data, a new destination value
// has to be allocated. But if the new data overwrite an old value,
// then that old value will NEVER BE DEALLOCATED, since it is not
// reachable anymore!
//
// When dealing with cyboi "part" structures, this is not a problem,
// since each part keeps a "reference" field for automatic
// rubbish (garbage) collection.
//
// But the introduction of such rubbish (garbage) collection
// for compound data other than "part" is NOT wanted. It would
// pollute and complicate the cyboi system architecture.
//
// Therefore, compound data are NOT kept in special structures,
// but in standard arrays instead, just as other primitive data.
// Their size is calculated as the sum of its fields' type sizes.
//

/** The complex compound type size. */
int COMPLEX_COMPOUND_TYPE_SIZE_ARRAY[1];
int* COMPLEX_COMPOUND_TYPE_SIZE = COMPLEX_COMPOUND_TYPE_SIZE_ARRAY;

/** The datetime compound type size. */
int DATETIME_COMPOUND_TYPE_SIZE_ARRAY[1];
int* DATETIME_COMPOUND_TYPE_SIZE = DATETIME_COMPOUND_TYPE_SIZE_ARRAY;

/** The duration compound type size. */
int DURATION_COMPOUND_TYPE_SIZE_ARRAY[1];
int* DURATION_COMPOUND_TYPE_SIZE = DURATION_COMPOUND_TYPE_SIZE_ARRAY;

/** The fraction compound type size. */
int FRACTION_COMPOUND_TYPE_SIZE_ARRAY[1];
int* FRACTION_COMPOUND_TYPE_SIZE = FRACTION_COMPOUND_TYPE_SIZE_ARRAY;

/* COMPOUND_TYPE_SIZE_VARIABLE_HEADER */
#endif
