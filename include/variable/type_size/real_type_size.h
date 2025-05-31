/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef REAL_TYPE_SIZE_VARIABLE_HEADER
#define REAL_TYPE_SIZE_VARIABLE_HEADER

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// The standard header file "float.h" defines the minimum and maximum values
// of the floating-point types float, double, and long double.
// It also defines other limits that are relevant to the processing
// of floating-point numbers.
//

//
// Date Range
//
// The C standard is unspecific on the relative sizes of the
// floating point values and only requires a float not to be
// larger than a double, which should not be larger than a long double.
//
// -------------------------------------
// | Data Type     | Data Range [Byte] |
// -------------------------------------
// | float         |  4 (32 Bit)       |
// | double        |  8 (64 Bit)       |
// | long double   | 10 (80 Bit)       |
// -------------------------------------
//
// CAUTION! The size and range of floating point numbers are
// NOT DEFINED and absolutely implementation-dependent.
// Their internal representation depends on the compiler used.
//
// CAUTION! The datatype "long double" has a size of 10 Byte
// on 16 Bit machines. It gets filled up from 10 to 12 Byte
// on 32 Bit machines. HP-UX machines even need 16 Byte of memory.
//
// CAUTION! Using the datatype "double" SUFFICES for most applications.
// If higher precision is needed, then special libraries with functions
// for infinite precision should be used rather than "long double".
//
// In cyboi, for floating point numbers, the STANDARD datatype "double" is used.
//
// http://openbook.galileo-press.de/c_von_a_bis_z/
//

//
// Representation
//
// Each of the three types of real values may represent values
// in a different form, often one of the IEEE floating point formats:
// http://en.wikipedia.org/wiki/IEEE_floating-point
//
// Floating-point constants may be written in decimal notation, e.g. 1.23.
//
// Scientific notation may be used by adding e or E followed by a
// decimal exponent, e.g. 1.23e2 (which has the value 123).
// Either a decimal point or an exponent is required
// (otherwise, the number is an integer constant).
//
// Hexadecimal floating-point constants follow similar rules except that
// they must be prefixed by 0x and use p to specify a binary exponent,
// e.g. 0xAp-2 (which has the value 2.5, since 10 * 2^-2 = 10 / 4).
//
// Both decimal and hexadecimal floating-point constants may be suffixed by:
// - f or F to indicate a constant of type float,
// - by l or L to indicate type long double
// - or left unsuffixed for a double constant.
//

/**
 * The float real type size.
 *
 * single-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−37..1×10^37
 * Typical size [Byte]: 4
 * Typical size [Bit]: 32
 */
//?? int FLOAT_REAL_TYPE_SIZE_ARRAY[1];
//?? int* FLOAT_REAL_TYPE_SIZE = FLOAT_REAL_TYPE_SIZE_ARRAY;

/**
 * The double real type size.
 *
 * double-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−308..1×10^308
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
int DOUBLE_REAL_TYPE_SIZE_ARRAY[1];
int* DOUBLE_REAL_TYPE_SIZE = DOUBLE_REAL_TYPE_SIZE_ARRAY;

/**
 * The long double real type size.
 *
 * double-extended-precision
 *
 * Minimum allowed range: 1×10^−37..1×10^37
 * Typical allowed range: 1×10^−308..1×10^308 or 1×10^−4932..1×10^4932 (x87 FPU systems)
 * Typical size [Byte]: 8 or 12
 * Typical size [Bit]: 64 or 96
 */
//?? int LONG_DOUBLE_REAL_TYPE_SIZE_ARRAY[1];
//?? int* LONG_DOUBLE_REAL_TYPE_SIZE = LONG_DOUBLE_REAL_TYPE_SIZE_ARRAY;

/* REAL_TYPE_SIZE_VARIABLE_HEADER */
#endif
