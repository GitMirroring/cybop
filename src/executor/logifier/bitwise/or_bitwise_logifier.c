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

#ifndef OR_BOOLEAN_LOGIFIER_SOURCE
#define OR_BOOLEAN_LOGIFIER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Connects the given values following boolean logic.
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left value
 * @param p2 the right value
 */
void logify_boolean_or(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* rv = (int*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* lv = (int*) p1;

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify boolean or.");

            if ((*lv) || (*rv)) {

                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify boolean or. The left value is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify boolean or. The right value is null.");
    }
}

/* OR_BOOLEAN_LOGIFIER_SOURCE */
#endif
