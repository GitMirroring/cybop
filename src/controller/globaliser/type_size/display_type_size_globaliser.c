/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DISPLAY_TYPE_SIZE_GLOBALISER_SOURCE
#define DISPLAY_TYPE_SIZE_GLOBALISER_SOURCE

#ifdef __APPLE__
#elif WIN32
    #include <windows.h>
#elif GNU_LINUX_OPERATING_SYSTEM
#else
#endif

#include "../../../variable/type_size/display_type_size.c"

/**
 * Initialises display type size global variables.
 */
void globalise_type_size_display() {

#ifdef __APPLE__
#elif WIN32
    *WNDCLASSEX_DISPLAY_TYPE_SIZE = sizeof (WNDCLASSEX);
#elif GNU_LINUX_OPERATING_SYSTEM
#else
#endif
}

/* DISPLAY_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
