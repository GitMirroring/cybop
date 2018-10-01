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

#ifndef SERVER_TERMINAL_STARTER_SOURCE
#define SERVER_TERMINAL_STARTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/maintainer/starter/terminal/open_terminal_starter.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Starts up server terminal.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (comparable to a socket port)
 */
void startup_terminal_server(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal server.");

    // The internal memory index.
    int i = *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME;

    fwprintf(stdout, L"TEST: startup terminal server io index: %i \n", i);
    fwprintf(stdout, L"TEST: startup terminal server port p1: %i \n", p1);
    fwprintf(stdout, L"TEST: startup terminal server port *p1: %i \n", *((int*) p1));

    // Calculate internal memory index using given service identification.
    calculate_integer_add((void*) &i, p1);

    // CAUTION! Use greater-or-equal operator >=, since the first terminal has the identification zero.
    if (i >= *TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME) {

        // The given service identification is valid.

        // The terminal input/output entry.
        void* io = *NULL_POINTER_STATE_CYBOI_MODEL;

        fwprintf(stdout, L"TEST: startup terminal server io index with service identification: %i \n", i);

        // Get terminal input/output entry from internal memory.
        copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

            //?? TODO: Temporary solution using stdin / stdout.
            // The terminal file stream.
            FILE* s = stdin; //?? TODO: OPTIONAL: stdout
            // Get terminal file descriptor as integer from file stream.
            int f = fileno(s);
            //
            // The client list item.
            //
            // CAUTION! A client list IS needed here,
            // since the data sensing mechanism relies on it.
            // This is so even though only ONE user (client)
            // may be logged into a terminal at a given time,
            // which is also called a "user session".
            //
            void* cl = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate input/output entry.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &io, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);
            // Open terminal.
            startup_terminal_open((void*) &f, io);
            //
            // Allocate client list item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_item((void*) &cl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            fwprintf(stdout, L"TEST: startup terminal server file descriptor f: %i\n", f);
            fwprintf(stdout, L"TEST: startup terminal server client list cl: %i\n", cl);

            //
            // Store terminal file descriptor in input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            set_io_entry_element((void*) &io, (void*) &f, (void*) FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            //
            // Store client list item in input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            set_io_entry_element((void*) &io, (void*) &cl, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            //
            // Store input/output entry in internal memory.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the internal array's count and size are CONSTANT.
            //
            copy_array_forward(p0, (void*) &io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal server. The terminal already exists in internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal server. The internal memory base is wrong, due to an invalid port.");
    }
}

/* SERVER_TERMINAL_STARTER_SOURCE */
#endif
