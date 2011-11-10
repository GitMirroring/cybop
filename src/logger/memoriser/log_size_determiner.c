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

#ifndef LOG_SIZE_DETERMINER_SOURCE
#define LOG_SIZE_DETERMINER_SOURCE

#include <stdlib.h>
#include <string.h>
#include "../../constant/type/memory/memory_type.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../logger/accessor/assigner/log_integer_assigner.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/pointer_type_size.c"
#include "../../variable/type_size/real_type_size.c"

/**
 * Determines the size of the given type.
 *
 * @param p0 the size
 * @param p1 the type
 */
void log_determine_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p1;

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not determine size. The type is null."

        if (*a == *CHARACTER_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *DOUBLE_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);

        } else if (*a == *INTEGER_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *POINTER_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*a == *UNSIGNED_LONG_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *WIDE_CHARACTER_MEMORY_TYPE) {

            log_copy_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else {

            // CAUTION! DO NOT use logging functionality here!
            // The logger cannot log itself.
            // "Could not determine size. The type is unknown."
        }

    } else {

        // CAUTION! DO NOT use logging functionality here!
        // The logger cannot log itself.
        // "Could not determine size. The type is null."
    }
}

/* LOG_SIZE_DETERMINER_SOURCE */
#endif
