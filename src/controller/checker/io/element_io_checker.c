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

#ifndef ELEMENT_IO_CHECKER_SOURCE
#define ELEMENT_IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../controller/checker/io/sense_io_checker.c"
#include "../../../executor/accessor/getter/internal_memory_getter.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/copier/array_copier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output entry data.
 *
 * @param p0 the input/output flag
 * @param p1 the internal memory data
 * @param p2 the input/output base
 * @param p3 the service identification
 * @param p4 the channel
 */
void check_io_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    //
    // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
    // Otherwise, it would produce huge log files filled up with useless entries.
    //
    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io element.");
    //

    // The input/output entry.
    void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input/output entry.
    get_internal_memory_element((void*) &io, p1, p2, p3);

    if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The input/output entry (service) DOES exist in internal memory.
        //

        // The enable flag.
        void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        // Get enable flag from input/output entry.
        copy_array_forward((void*) &e, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Compare enable flag.
        compare_integer_unequal((void*) &r, e, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The enable flag is set, i.e. the service is active.
            //

            check_io_sense(p0, io, p4);
        }

    } else {

        //
        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        // The reason is that an input/output entry being null is the standard case,
        // since all 65536 service identification ports are tested,
        // of whom only one or a few are active.
        //
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not check io element. The input/output entry is null.");
        //
    }
}

/* ELEMENT_IO_CHECKER_SOURCE */
#endif
