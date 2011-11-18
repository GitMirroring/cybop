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

#ifndef THREAD_IDENTIFICATION_UNGLOBALISER_SOURCE
#define THREAD_IDENTIFICATION_UNGLOBALISER_SOURCE

#include <stdlib.h>

/**
 * Deallocates thread identification global variables.
 */
void unglobalise_thread_identification() {

    // Free cyboi service thread.
    free((void*) CYBOI_SERVICE_THREAD);

    // Free terminal thread.
    free((void*) TERMINAL_THREAD);

    // Free www service thread.
    free((void*) WWW_SERVICE_THREAD);

    // Free x window system thread.
    free((void*) X_WINDOW_SYSTEM_THREAD);
}

/* THREAD_IDENTIFICATION_UNGLOBALISER_SOURCE */
#endif
