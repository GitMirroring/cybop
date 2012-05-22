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

#ifndef INTEGRAL_GLOBALISER_SOURCE
#define INTEGRAL_GLOBALISER_SOURCE

#include "../../variable/type_size/integral_type_size.c"

/**
 * Allocates and initialises integral global variables.
 */
void globalise_integral() {

    // Allocate and initialise signed int integral type size.
    //
    // CAUTION! The standard type "int" corresponds to type "signed int".
    // Therefore, type "signed int" is allocated first,
    // so that it may be used as size for all other types.
    //
    // CAUTION! The "sizeof" operator must be used TWICE here,
    // because SIGNED_INTEGER_INTEGRAL_TYPE_SIZE cannot
    // be used before having been initialised itself.
    SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(sizeof(int));
    *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed int);

    // Allocate and initialise signed char integral type size.
    SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(signed char);

    // Allocate and initialise unsigned char integral type size.
    UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(unsigned char);

    // Allocate and initialise signed short int integral type size.
    SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed short int);

    // Allocate and initialise unsigned short int integral type size.
    UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned short int);

    // CAUTION! This is the place where "signed int" would
    // actually belong, when sorting types after their size.
    // However, it was allocated as first type,
    // since it is used as size for all other types.

    // Allocate and initialise unsigned int integral type size.
    UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned int);

    // Allocate and initialise signed long int integral type size.
    SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long int);

    // Allocate and initialise unsigned long int integral type size.
    UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long int);

    // Allocate and initialise signed long long int integral type size.
    SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long long int);

    // Allocate and initialise unsigned long long int integral type size.
    UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long long int);

    // Allocate and initialise wchar_t integral type size.
    WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = (int*) malloc(*SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);
    *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(wchar_t);
}

/* INTEGRAL_GLOBALISER_SOURCE */
#endif
