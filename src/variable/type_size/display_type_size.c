/*
 * Copyright (C) 1999-2015. Christian Heller.
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
 * @version CYBOP 0.17.0 2015-04-20
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DISPLAY_TYPE_SIZE_SOURCE
#define DISPLAY_TYPE_SIZE_SOURCE

//
// The global variables.
//
// CAUTION! This is just the variable definition.
// Initialisation happens in directory "controller/globaliser/".
//

#ifdef __APPLE__
#elif WIN32
    /** The window class extended display type size. */
    static int WNDCLASSEX_DISPLAY_TYPE_SIZE_ARRAY[1];
    static int* WNDCLASSEX_DISPLAY_TYPE_SIZE = WNDCLASSEX_DISPLAY_TYPE_SIZE_ARRAY;
#elif GNU_LINUX_OPERATING_SYSTEM
#else
#endif

/* DISPLAY_TYPE_SIZE_SOURCE */
#endif
