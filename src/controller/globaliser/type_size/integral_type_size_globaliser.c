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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <windows.h> // DWORD
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

//
// Library interface
//

#include "variable.h"

/**
 * Initialises integral type size global variables.
 */
void globalise_type_size_integral() {

    //
    // CAUTION! The glibc manual states that the data type of the result
    // of the "sizeof" function may vary between compilers.
    // It therefore recommends to use type "size_t" (instead of "int")
    // as the preferred way to declare any arguments or variables
    // that hold the size of an object.
    //
    // See:
    // http://www.gnu.org/software/libtool/manual/libc/Important-Data-Types.html#Important-Data-Types
    //
    // However, cyboi assigns the sizes of all primitive types to special
    // global integer variables at system startup, in module "globaliser.c".
    // As long as these global integer variables are used, there is
    // no need to work with type "sizt_t" in cyboi source code.
    //
    // But do NOT forget to introduce a variable of type "size_t" in LOCAL CONTEXT
    // and to assign the value of the cyboi-internal int variable to it!
    // Otherwise, memory errors will occur and valgrind memcheck report
    // something like "Invalid read of size 8", at least on 64 Bit machines.
    // On such systems, "size_t" has a size of 8 Byte (unsigned long int),
    // whereas an "int" has the usual size of 4 Byte.
    //

    //?? *SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof (signed char);
    *UNSIGNED_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof (unsigned char);
    *SIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (signed short int);
    //?? *UNSIGNED_SHORT_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (unsigned short int);
    *SIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (signed int);
    //?? *UNSIGNED_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (unsigned int);
    //?? *SIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (signed long int);
    //?? *UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (unsigned long int);
    *SIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (signed long long int);
    //?? *UNSIGNED_LONG_LONG_INTEGER_INTEGRAL_TYPE_SIZE = sizeof (unsigned long long int);
    *WIDE_CHARACTER_INTEGRAL_TYPE_SIZE = sizeof (wchar_t);

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    *DOUBLE_WORD_INTEGRAL_TYPE_SIZE = sizeof (DWORD);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
