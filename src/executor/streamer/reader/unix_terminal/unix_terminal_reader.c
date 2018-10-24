/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNIX_TERMINAL_READER_SOURCE
#define UNIX_TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/io_entry_getter.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/streamer/reader/unix_terminal/stream_unix_terminal_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads the destination from unix terminal.
 *
 * @param p0 the destination item
 * @param p1 the service identification (comparable to a socket port)
 * @param p2 the internal memory data
 * @param p3 the blocking flag
 */
void read_unix_terminal(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read unix terminal.");

    // The internal memory index.
    int i = *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME;

    // Calculate internal memory index using given service identification.
    calculate_integer_add((void*) &i, p1);

    // CAUTION! Use greater-or-equal operator >=, since the first terminal has the identification zero.
    if (i >= *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME) {

        // The given service identification is valid.

        // The terminal input/output entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get terminal input/output entry from internal memory.
        copy_array_forward((void*) &io, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The terminal input file descriptor.
            int f = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

            //
            // Retrieve terminal file descriptor from input/output entry.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            get_io_entry_element((void*) &f, io, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

            read_unix_terminal_stream(p0, (void*) &f, p3);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal. There is no input/output terminal entry in the internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal. The service identification is invalid.");
    }
}

/* UNIX_TERMINAL_READER_SOURCE */
#endif
