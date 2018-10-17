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

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

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
#include "../../../../executor/maintainer/shutter/terminal/mode_terminal_shutter.c"
#include "../../../../executor/memoriser/deallocator/array_deallocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (comparable to a socket port)
 */
void shutdown_terminal(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

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
        copy_array_forward((void*) &io, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

        if (io != *NULL_POINTER_STATE_CYBOI_MODEL) {

            fwprintf(stdout, L"TEST: shutdown terminal 0 io: %i \n", io);

            //
            // Reset input/output entry in internal memory to null.
            //
            // CAUTION! It is ESSENTIAL to assign NULL here,
            // since cyboi tests for null pointers and otherwise,
            // wild pointers would lead to memory corruption.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the internal array's count and size are CONSTANT.
            //
            copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

            // The terminal output- and input file descriptors.
            int outf = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
            int inf = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
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

            fwprintf(stdout, L"TEST: shutdown terminal 1 cl: %i \n", cl);

            //
            // Retrieve terminal file descriptors from input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            get_io_entry_element((void*) &outf, io, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            get_io_entry_element((void*) &inf, io, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            //
            // Retrieve client list item from input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            get_io_entry_element((void*) &cl, io, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            fwprintf(stdout, L"TEST: shutdown terminal 2 cl: %i \n", cl);

            // Restore original terminal mode.
            shutdown_terminal_mode((void*) &outf, io, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

            fwprintf(stdout, L"TEST: shutdown terminal 3 cl: %i \n", cl);

            shutdown_terminal_mode((void*) &inf, io, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            fwprintf(stdout, L"TEST: shutdown terminal 4 cl: %i \n", cl);

            //
            // CAUTION! A "close" function is NOT called here,
            // since standard terminal output- and input file descriptors
            // were used at startup and MUST NOT be closed.
            // This is the case for the linux AND win32 operating system.
            //

            // Deallocate input/output entry.
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            deallocate_array((void*) &io, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);

            fwprintf(stdout, L"TEST: shutdown terminal 5 cl: %i \n", cl);

            // Deallocate client list item.
            // CAUTION! The second argument "count" is NULL,
            // since it is only needed for looping elements of type PART,
            // in order to decrement the rubbish (garbage) collection counter.
            deallocate_item((void*) &cl, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            fwprintf(stdout, L"TEST: shutdown terminal 6 cl: %i \n", cl);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. There is no input/output terminal entry in the internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. The service identification is invalid.");
    }
}

/* TERMINAL_SHUTTER_SOURCE */
#endif
