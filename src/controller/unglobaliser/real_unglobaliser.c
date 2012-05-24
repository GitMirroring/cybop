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

#ifndef REAL_UNGLOBALISER_SOURCE
#define REAL_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates real global variables.
 */
void unglobalise_real() {

    // Free float real type size.
//??    free((void*) FLOAT_REAL_TYPE_SIZE);

    // Free double real type size.
//??    free((void*) DOUBLE_REAL_TYPE_SIZE);

    // Free long double real type size.
//??    free((void*) LONG_DOUBLE_REAL_TYPE_SIZE);
}

/* REAL_UNGLOBALISER_SOURCE */
#endif
