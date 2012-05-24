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

    *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed int);
    *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(signed char);
    *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(unsigned char);
    *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed short int);
    *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned short int);
    *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned int);
    *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long int);
    *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long int);
    *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(signed long long int);
    *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof(unsigned long long int);
    *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof(wchar_t);
}

/* INTEGRAL_GLOBALISER_SOURCE */
#endif
