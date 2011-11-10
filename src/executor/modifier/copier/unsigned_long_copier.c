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

#ifndef UNSIGNED_LONG_COPIER_SOURCE
#define UNSIGNED_LONG_COPIER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Copies the unsigned long.
 *
 * @param p0 the destination
 * @param p1 the source
 */
void copy_unsigned_long(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        unsigned long* se = (unsigned long*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            unsigned long* de = (unsigned long*) p0;

            log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Copy unsigned long.");

            // Assign source- to destination.
            *de = *se;

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy unsigned long. The destination is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not copy unsigned long. The source is null.");
    }
}

/* UNSIGNED_LONG_COPIER_SOURCE */
#endif
