/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef GET_IO_MAINTAINER_SOURCE
#define GET_IO_MAINTAINER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/calculator/integer/add_integer_calculator.c"
#include "../../executor/comparator/integer/greater_or_equal_integer_comparator.c"
#include "../../executor/copier/array_copier.c"
#include "../../logger/logger.c"

/**
 * Retrieves the input/output entry from internal memory.
 *
 * @param p0 the input/output entry (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the service identification (e.g. socket port)
 */
void maintain_io_get(void* p0, void* p1, void* p2, void* p3) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Maintain io get.");
    //

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Calculate internal memory index.
    //
    // - add input output base
    // - add service identification (input/output entry index)
    //
    // CAUTION! If the service identification is null, then it is NOT copied here.
    // In this case, the base internal memory index added before
    // remains as is which is the same as a service identification of zero.
    //
    calculate_integer_add((void*) &i, p2);
    calculate_integer_add((void*) &i, p3);

    // CAUTION! Use greater-or-equal operator >=,
    // since the first service has the identification zero.
    compare_integer_greater_or_equal((void*) &r, (void*) &i, p2);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The given service identification is valid.

        // Get input/output entry from internal memory.
        copy_array_forward(p0, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not maintain io get. The service identification is invalid.");
    }
}

/* GET_IO_MAINTAINER_SOURCE */
#endif
