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

#ifndef NOT_BOOLEAN_LOGIFIER_SOURCE
#define NOT_BOOLEAN_LOGIFIER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Negates the given value following boolean logic.
 *
 * @param p0 the output, which is the first operand BEFORE the operation (number 1 if operand is false; number 0 otherwise; unchanged if null)
 */
void logify_boolean_not(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* o = (int*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify boolean not.");

        *o = !(*o);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify boolean not. The output is null.");
    }
}

/* NOT_BOOLEAN_LOGIFIER_SOURCE */
#endif
