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

#ifndef ENTRY_TERMINAL_READER_SOURCE
#define ENTRY_TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Determines the terminal input/output entry.
 *
 * @param p0 the terminal input file stream (pointer reference)
 * @param p1 the internal memory data
 * @param p2 the service identification
 */
void read_terminal_entry(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read terminal entry.");

    // The internal memory index.
    int i = *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME;

    //
    // Calculate internal memory index using given service identification.
    //
    // CAUTION! If the service identification is null,
    // then NOTHING GETS COPIED here.
    // In this case, the base internal memory index defined above
    // remains as is which is the same as a service identification of zero.
    //
    calculate_integer_add((void*) &i, p2);

    // CAUTION! Use greater-or-equal operator >=, since the first terminal has the identification zero.
    if (i >= *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME) {

        // The given service identification is valid.

        // The terminal input/output entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get terminal input/output entry from internal memory.
        copy_array_forward((void*) &io, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // Retrieve terminal output file stream from input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Hand over file stream as pointer REFERENCE.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            copy_array_forward(p0, io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read terminal entry. There is no input/output terminal entry in the internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read terminal entry. The service identification is invalid.");
    }
}

/* ENTRY_TERMINAL_READER_SOURCE */
#endif
