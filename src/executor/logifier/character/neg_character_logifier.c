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

#ifndef NEG_CHARACTER_LOGIFIER_SOURCE
#define NEG_CHARACTER_LOGIFIER_SOURCE

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
 * Apply bit logic operation neg (second's complement).
 *
 * @param p0 the value
 */
void logify_character_neg(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        unsigned char* v = (unsigned char*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Logify character neg.");

        *v = (~(*v))+1;

    if(*v < 0){
        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Value range exceeded");
    }
    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not logify character neg. The value is null.");
    }
}

/* NEG_CHARACTER_LOGIFIER_SOURCE */
#endif
