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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNLOCKER_SOURCE
#define UNLOCKER_SOURCE

#include <threads.h> // mtx_t, mtx_unlock

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../logger/logger.c"

/**
 * Unlocks the mutex if one is given, otherwise does nothing.
 *
 * @param p0 the mutex
 */
int unlock(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        mtx_t* m = (mtx_t*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Unlock.");
        //?? fwprintf(stdout, L"Debug: Unlock. p0: %i\n", p0);
        //?? fwprintf(stdout, L"Debug: Unlock. *p0: %i\n", *((int*) p0));

        mtx_unlock(m);

    } else {

        //
        // CAUTION! Comment out this log message, since direct reading and writing
        // do NOT use a buffer and hence NO mutex, so that it is null in this case.
        //
        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not unlock mutex. The mutex is null.");
        // fwprintf(stdout, L"Warning: Could not unlock mutex. The mutex is null. p0: %i\n", p0);
    }
}

/* UNLOCKER_SOURCE */
#endif
