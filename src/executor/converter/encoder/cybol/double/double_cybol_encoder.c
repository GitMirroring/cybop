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
 * @version $RCSfile: boolean_converter.c,v $ $Revision: 1.24 $ $Date: 2009-01-31 16:06:33 $ $Author: christian $
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef DOUBLE_CYBOL_ENCODER_SOURCE
#define DOUBLE_CYBOL_ENCODER_SOURCE

#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/type/memory/memory_type.c"
#include "../../../../constant/model/cybol/boolean_cybol_model.c"
#include "../../../../constant/model/log/message_log_model.c"
#include "../../../../constant/model/memory/boolean_memory_model.c"
#include "../../../../constant/model/memory/integer_memory_model.c"
#include "../../../../constant/model/memory/pointer_memory_model.c"
#include "../../../../constant/name/memory/primitive_memory_name.c"
#include "../../../../logger/logger.c"
#include "../../../../executor/memoriser/allocator.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"

/**
 * Encodes the double values into comma-separated wide character values.
 *
 * @param p0 the destination item
 * @param p1 the source double data
 * @param p2 the source double count
 */
void encode_cybol_double(void* p0, void* p1, void* p2) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_MODEL, (void*) L"Encode cybol double.");

    // The loop variable.
    int j = *NUMBER_0_INTEGER_MEMORY_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_MEMORY_MODEL;

    while (*TRUE_BOOLEAN_MEMORY_MODEL) {

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p2);

        if (b != *FALSE_BOOLEAN_MEMORY_MODEL) {

            break;
        }

        encode_cybol_double_separator(p0, (void*) &j);
        encode_cybol_double_value(p0, p1, (void*) &j);

        // Increment loop variable.
        j++;
    }
}

/* DOUBLE_CYBOL_ENCODER_SOURCE */
#endif
