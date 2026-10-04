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

#ifndef INTEGRAL_TYPE_SIZE_VARIABLE_HEADER
#define INTEGRAL_TYPE_SIZE_VARIABLE_HEADER

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

//
// The standard header "limits.h" defines the minimum and maximum values
// of the integral primitive data types, amongst other limits.
//

//
// The integral types come in different sizes, with varying
// amounts of memory usage and range of representable numbers.
// Modifiers are used to designate the size: short, long and long long.
//

//
// Date Range
//
// The C standard does not require that any of the type sizes
// be necessarily different. It is perfectly valid, for example,
// if all types are 64 bits long.
//
// In order to allow a simple and concise description of the sizes
// a compiler will apply to each of the four types, a simple
// naming scheme has been devised. See 64-Bit Programming Models.
// Two popular schemes are:
// - ILP32: int, long int and pointer types are 32 bits long
// - LP64: long int and pointers are 64 bits, and int are 32 bits
// Most implementations under these schemes use 16-bit short ints.
//
// -----------------------------------------------------
// | Long Form     | Short Form    | Data Range [Byte] |
// -----------------------------------------------------
// | signed char   | char          |  1 (8 Bit)        |
// | short int     | short         |  2 (16 Bit)       |
// | long int      | long          |  4 (32 Bit)       |
// | long long int | long long     |  8 (64 Bit)       |
// -----------------------------------------------------
//
// CAUTION! The datatype "int" covers DIFFERENT DATA RANGES
// (2 Byte or 4 Byte), depending on the platform.
// It therefore seems better to use EXPLICIT data types, in order
// to make cyboi run correctly on different platforms (16/32/64 Bit).
//
// In cyboi, only the correct LONG FORM is used for datatype names.
// For standard integer numbers, the LARGEST datatype "long long int" is used.
//
// http://openbook.galileo-press.de/c_von_a_bis_z/
//

//
// Performance
//
// Using 32-bit variables (like "long") IS BETTER than working
// with 8- or 16-bit ones (like "short" or "unsigned char"),
// since the latter might SLOW DOWN PROCESSOR SPEED due to
// memory addressing mechanisms. Most processors are totally
// 32-bit -- just the size of the "int" type.
//
// Pointers on 64 Bit systems are 64 Bit, but at least
// MULTIPLES of 32 bytes.
//
// Increase in speed means more memory consumption due to
// larger type sizes. But this is always the decision:
// Space or time? Precision or momentum?
// (Heisenberg uncertainty principle?)
//
// In the end, this is one more argument for using the
// datatype "long long int" for standard integers.
//

//
// Sign
//
// All C integer types have signed and unsigned variants.
// If "signed" or "unsigned" is not specified explicitly,
// in most circumstances "signed" is assumed by default.
//
// CAUTION! For the datatype "char", the C language specification
// does NOT define whether or not it contains a sign.
// This might lead to errors when used on different platforms.
// For historic reasons plain "char" is a type distinct
// from both "signed char" and "unsigned char".
// It may be a signed type or an unsigned type, depending on
// the compiler and the character set (C guarantees that
// members of the C basic character set have positive values).
// Similarly, bit field types specified as plain "int" may be
// signed or unsigned, depending on the compiler.
//
// CAUTION! For the datatype "wchar_t" an explicit "signed"
// or "unsigned" is NOT defined. It depends on the actual
// underlying type, if it is signed or not.
//
// http://openbook.galileo-press.de/c_von_a_bis_z/
//

/**
 * The signed char integral type size.
 *
 * Minimum allowed range: -127..+127
 * Typical allowed range: -128..+127
 * Typical size [Byte]: 1
 * Typical size [Bit]: 8
 */
//?? int SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The unsigned char integral type size.
 *
 * Minimum allowed range: 0..+255
 * Typical allowed range: 0..+255
 * Typical size [Byte]: 1
 * Typical size [Bit]: 8
 */
int UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY[1];
int* UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The signed short int integral type size.
 *
 * Minimum allowed range: -32767..+32767
 * Typical allowed range: -32768..+32767
 * Typical size [Byte]: 2
 * Typical size [Bit]: 16
 */
int SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
int* SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The unsigned short int integral type size.
 *
 * Minimum allowed range: 0..+65535
 * Typical allowed range: 0..+65535
 * Typical size [Byte]: 2
 * Typical size [Bit]: 16
 */
//?? int UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The signed int integral type size.
 *
 * Minimum allowed range: -32767..+32767
 * Typical allowed range: -32768..+32767 (antique systems) or -2147483648..+2147483647
 * Typical size [Byte]: 2 (antique systems) or 4
 * Typical size [Bit]: 16 (antique systems) or 32
 */
int SIGNED_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
int* SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = SIGNED_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The unsigned int integral type size.
 *
 * Minimum allowed range: 0..+65535
 * Typical allowed range: 0..+65535 (antique systems) or 0..+4294967295
 * Typical size [Byte]: 2 (antique systems) or 4
 * Typical size [Bit]: 16 (antique systems) or 32
 */
//?? int UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The signed long int integral type size.
 *
 * Minimum allowed range: -2147483647..+2147483647
 * Typical allowed range: -2147483648..+2147483647 or -9223372036854775808..+9223372036854775807 (64-Bit systems)
 * Typical size [Byte]: 4 or 8 (64-Bit systems)
 * Typical size [Bit]: 32 or 64 (64-Bit systems)
 */
//?? int SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The unsigned long int integral type size.
 *
 * Minimum allowed range: 0..+4294967295
 * Typical allowed range: 0..+4294967295 or 0..+18446744073709551615 (64-Bit systems)
 * Typical size [Byte]: 4 or 8 (64-Bit systems)
 * Typical size [Bit]: 32 or 64 (64-Bit systems)
 */
//?? int UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The signed long long int integral type size.
 *
 * Minimum allowed range: -9223372036854775807..+9223372036854775807
 * Typical allowed range: -9223372036854775808..+9223372036854775807
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
int SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
int* SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The unsigned long long int integral type size.
 *
 * Minimum allowed range: 0..+18446744073709551615
 * Typical allowed range: 0..+18446744073709551615
 * Typical size [Byte]: 8
 * Typical size [Bit]: 64
 */
//?? int UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY[1];
//?? int* UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE_ARRAY;

/**
 * The wchar_t integral type size.
 *
 * This type is defined in the headers <stdlib.h> and <wchar.h>
 * as a typedef of a 32 Bit signed integer.
 *
 * Minimum allowed range: -127..+127 (capable of storing all elements of the basic character set)
 * Typical allowed range: -128..+127 or -32768..+32767 or -2147483648..+2147483647 (capable of representing all Unicode / UCS-4 / ISO 10646 values)
 * Typical size [Byte]: 1 (some embedded systems) or 2 (some Unix systems, Java, Win32, Win64, .NET) or 4 (GNU systems)
 * Typical size [Bit]: 8 (some embedded systems) or 16 (some Unix systems, Java, Win32, Win64, .NET) or 32 (GNU systems)
 */
int WIDE_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY[1];
int* WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = WIDE_CHARACTER_INTEGRAL_TYPE_SIZE_ARRAY;

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    /**
     * The double word integral type size.
     *
     * It is a 32-bit unsigned integer. See comment at "unsigned long int".
     *
     * This type is declared in IntSafe.h as follows:
     * typedef unsigned long DWORD;
     *
     * http://msdn.microsoft.com/en-us/library/windows/desktop/aa383751%28v=vs.85%29.aspx
     */
    int DOUBLE_WORD_INTEGRAL_TYPE_SIZE_ARRAY[1];
    int* DOUBLE_WORD_INTEGRAL_TYPE_SIZE = DOUBLE_WORD_INTEGRAL_TYPE_SIZE_ARRAY;
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/* INTEGRAL_TYPE_SIZE_VARIABLE_HEADER */
#endif
