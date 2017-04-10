/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_TYPE_SIZE_GLOBALISER_SOURCE
#define SIGNAL_TYPE_SIZE_GLOBALISER_SOURCE

#include <signal.h>

#include "../../../variable/type_size/signal_type_size.c"

/**
 * Initialises signal type size global variables.
 */
void globalise_type_size_signal() {

    *ATOMIC_SIGNAL_TYPE_SIZE = sizeof (sig_atomic_t);
    *VOLATILE_ATOMIC_SIGNAL_TYPE_SIZE = sizeof (volatile sig_atomic_t);
}

/* SIGNAL_TYPE_SIZE_GLOBALISER_SOURCE */
#endif
