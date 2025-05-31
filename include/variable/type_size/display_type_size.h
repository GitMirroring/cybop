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

#ifndef DISPLAY_TYPE_SIZE_VARIABLE_HEADER
#define DISPLAY_TYPE_SIZE_VARIABLE_HEADER

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

#if defined(__linux__) || defined(__unix__)
#elif defined(__APPLE__) && defined(__MACH__)
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
/** The window class extended display type size. */
int WNDCLASSEX_DISPLAY_TYPE_SIZE_ARRAY[1];
int* WNDCLASSEX_DISPLAY_TYPE_SIZE = WNDCLASSEX_DISPLAY_TYPE_SIZE_ARRAY;
#else
#error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

/* DISPLAY_TYPE_SIZE_VARIABLE_HEADER */
#endif
