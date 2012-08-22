
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef THREAD_IDENTIFICATION_GLOBALISER_SOURCE
#define THREAD_IDENTIFICATION_GLOBALISER_SOURCE

#include <pthread.h>

#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../variable/type_size/thread_type_size.c"
#include "../../variable/thread_identification.c"

/**
 * Initialises thread identification global variables.
 */
void globalise_thread_identification() {

    *CYBOI_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    *TERMINAL_THREAD = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    *WWW_SERVICE_THREAD = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    *X_WINDOW_SYSTEM_THREAD = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
}

/* THREAD_IDENTIFICATION_GLOBALISER_SOURCE */
#endif
