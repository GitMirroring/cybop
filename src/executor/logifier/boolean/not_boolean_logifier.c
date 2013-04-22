/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef NOT_BOOLEAN_LOGIFIER_SOURCE
#define NOT_BOOLEAN_LOGIFIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Negates the given value following boolean logic.
 *
 * @param p0 the result (number 1 if operand is false; number 0 if operand is true; unchanged if null)
 * @param p1 the value
 */
void logify_boolean_not(void* p0) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* v = (int*) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify boolean not.");

        if !(*v) {

            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        } else {

            copy_integer(p0, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify boolean not. The value is null.");
    }
}

/* NOT_BOOLEAN_LOGIFIER_SOURCE */
#endif
