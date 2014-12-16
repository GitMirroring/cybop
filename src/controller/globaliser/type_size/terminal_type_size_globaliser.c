/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef TERMINAL_TYPE_SIZE_GLOBALISER_SOURCE
#define TERMINAL_TYPE_SIZE_GLOBALISER_SOURCE

#ifdef __APPLE__
    #include <termios.h>
#elif WIN32
#elif GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#else
    #include <termios.h>
#endif

#include "../../../variable/type_size/terminal_type_size.c"

/**
 * Initialises terminal type size global variables.
 */
void globalise_type_size_terminal() {

#ifdef __APPLE__
    *TERMIOS_TERMINAL_TYPE_SIZE = sizeof (struct termios);
#elif WIN32
#elif GNU_LINUX_OPERATING_SYSTEM
    *TERMIOS_TERMINAL_TYPE_SIZE = sizeof (struct termios);
#else
    *TERMIOS_TERMINAL_TYPE_SIZE = sizeof (struct termios);
#endif
}

/* TERMINAL_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
