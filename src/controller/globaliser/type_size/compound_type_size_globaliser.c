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

#ifndef COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE
#define COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE

//
// Library interface
//

#include "variable.h"

/**
 * Initialises compound type size global variables.
 *
 * CAUTION! When editing this file, then also adapt:
 * "controller/globaliser/type_size/compound_type_size_globaliser.c"
 */
void globalise_type_size_compound() {

    // Elements: real + imaginary
    *COMPLEX_COMPOUND_TYPE_SIZE = *DOUBLE_REAL_TYPE_SIZE + *DOUBLE_REAL_TYPE_SIZE;

    // Elements: julian day + julian second
    *DATETIME_COMPOUND_TYPE_SIZE = *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE + *DOUBLE_REAL_TYPE_SIZE;

    //
    // Elements: value + start + end
    //
    // CAUTION! This type size depends upon DATETIME_COMPOUND_TYPE_SIZE,
    // so that it can only be defined AFTER the "datetime" size.
    //
    *DURATION_COMPOUND_TYPE_SIZE = *DATETIME_COMPOUND_TYPE_SIZE + *DATETIME_COMPOUND_TYPE_SIZE + *DATETIME_COMPOUND_TYPE_SIZE;

    // Elements: numerator + denominator
    *FRACTION_COMPOUND_TYPE_SIZE = *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE + *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE;
}

/* COMPOUND_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
