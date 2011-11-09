/*
 * Copyright (C) 1999-2011. Christian Heller.
 *
 * This file is part of the Cybernetics Oriented Interpreter (CYBOI).
 *
 * CYBOI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CYBOI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with CYBOI.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Cybernetics Oriented Programming (CYBOP) <http://www.cybop.org>
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version $RCSfile: multiplier.c,v $ $Revision: 1.1 $ $Date: 2009-10-06 21:25:26 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIZE_DETERMINER_SOURCE
#define SIZE_DETERMINER_SOURCE

#include <stdlib.h>
#include <string.h>

#include "../../constant/type/memory/memory_type.c"
#include "../../constant/model/log/message_log_model.c"
#include "../../constant/model/memory/integer_memory_model.c"
#include "../../constant/model/memory/pointer_memory_model.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../logger/logger.c"
#include "../../variable/type_size/integral_type_size.c"
#include "../../variable/type_size/pointer_type_size.c"
#include "../../variable/type_size/real_type_size.c"

/**
 * Determines the size of the given type.
 *
 * @param p0 the size
 * @param p1 the type
 */
void determine_size(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_MEMORY_MODEL) {

        int* a = (int*) p1;

        log_terminated_message((void*) DEBUG_LEVEL_LOG_MODEL, (void*) L"Determine size.");

        if (*a == *CHARACTER_MEMORY_TYPE) {

            copy_integer(p0, (void*) SIGNED_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *DOUBLE_MEMORY_TYPE) {

            copy_integer(p0, (void*) DOUBLE_REAL_TYPE_SIZE);

        } else if (*a == *FRACTION_MEMORY_TYPE) {

            // CAUTION! This "fraction" type IS NEEDED,
            // e.g. when DEEP copying a part. Do NOT delete!
            // It is actually a pointer array, of which each
            // pointer references a fraction structure.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*a == *INTEGER_MEMORY_TYPE) {

            copy_integer(p0, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *PART_MEMORY_TYPE) {

            // CAUTION! This "part" type IS NEEDED,
            // e.g. when DEEP copying a part. Do NOT delete!
            // It is actually a pointer array, of which each
            // pointer references a part structure.
            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*a == *POINTER_MEMORY_TYPE) {

            copy_integer(p0, (void*) POINTER_TYPE_SIZE);

        } else if (*a == *UNSIGNED_LONG_MEMORY_TYPE) {

            copy_integer(p0, (void*) UNSIGNED_LONG_INTEGER_INTEGRAL_TYPE_SIZE);

        } else if (*a == *WIDE_CHARACTER_MEMORY_TYPE) {

            copy_integer(p0, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE);

        } else {

            log_terminated_message((void*) WARNING_LEVEL_LOG_MODEL, (void*) L"Could not determine size. The type is unknown.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_MODEL, (void*) L"Could not determine size. The type is null.");
    }
}

/* SIZE_DETERMINER_SOURCE */
#endif
