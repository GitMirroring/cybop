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

#ifndef TERMINAL_STARTER_SOURCE
#define TERMINAL_STARTER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/setter/io_entry_setter.c"
#include "../../../../executor/calculator/integer/add_integer_calculator.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/maintainer/starter/terminal/mode_terminal_starter.c"
#include "../../../../executor/maintainer/starter/terminal/open_terminal_starter.c"
#include "../../../../executor/memoriser/allocator/array_allocator.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the terminal.
 *
 * @param p0 the internal memory data
 * @param p1 the service identification (comparable to a socket port)
 */
void startup_terminal(void* p0, void* p1) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal.");

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

        if (io == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

            //
            // Allocate input/output entry.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_array((void*) &io, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) IO_ENTRY_STATE_CYBOI_TYPE);
            //
            // Allocate client list item.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_item((void*) &cl, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

            fwprintf(stdout, L"TEST: startup terminal io: %i \n", io);
            fwprintf(stdout, L"TEST: startup terminal cl: %i \n", cl);

            // Open terminal output- and input file descriptors.
            startup_terminal_open((void*) &outf, (void*) &inf);

            fwprintf(stdout, L"TEST: startup terminal outf: %i \n", outf);
            fwprintf(stdout, L"TEST: startup terminal outf: %i \n", inf);

            //
            // Configure terminal mode.
            //
            // Linux:
            //
            // CAUTION! Although some functions specify the terminal device with a file descriptor,
            // the attributes are those of the terminal device itself and NOT of the file descriptor.
            // This means that the effects of changing terminal attributes are persistent;
            // if another process opens the same terminal file later on, it will see
            // the CHANGED attributes even though it doesn’t have anything to do with
            // the open file descriptor originally specified in changing the attributes.
            //
            // Similarly, if a single process has multiple or duplicated file descriptors
            // for the same terminal device, changing the terminal attributes affects
            // INPUT AND OUTPUT to ALL of these file descriptors.
            //
            // This means, for example, that one can’t open one file descriptor or stream
            // to read from a terminal in the normal line-buffered, echoed mode;
            // and simultaneously have another file descriptor for the same terminal
            // that one uses to read from it in single-character, non-echoed mode.
            // Instead, one has to EXPLICITLY SWITCH the terminal back and forth between the two modes.
            //
            // Reference:
            // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Mode-Functions
            //
            // Windows:
            //
            // A console consists of an input buffer and one or more output (screen) buffers.
            // The mode of a console buffer determines how the console behaves
            // during input and output (I/O) operations.
            // ONE SET OF FLAG CONSTANTS is used with INPUT handles,
            // and ANOTHER SET is used with screen buffer (OUTPUT) handles.
            // Setting the output modes of one screen buffer does not affect
            // the output modes of other screen buffers.
            //
            // Reference:
            // https://docs.microsoft.com/en-us/windows/console/setconsolemode
            //
            // Decision:
            //
            // Linux terminal modes are valid for input AND output,
            // so that it does NOT matter whether the input- or output file descriptor
            // is handed over as argument here. Either may be used.
            // In windows, however, a DIFFERENT SET OF FLAGS is used for each,
            // input and output.
            //
            // Due to the fact that windows distinguishes between the
            // input and output mode settings, both are treated SEPARATELY here,
            // i.e. the function "startup_terminal_mode" is called twice,
            // once for input and another time for output.
            //
            // The sets of flag constants are definitely different, to be verified here:
            // https://docs.microsoft.com/en-us/windows/console/setconsolemode
            // The input- and output constants have OVERLAPPING VALUES (identification),
            // so that both MUST NOT be combined or set together.
            //
            // For linux, this redundant storage of mode settings
            // is actually not necessary, but does no harm either.
            //
            // The third (and last) argument is a boolean value indicating
            // whether input or output mode is meant,
            // so that the correct flags may be used internally.
            //
            startup_terminal_mode((void*) &outf, io, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
            startup_terminal_mode((void*) &inf, io, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            //
            // Store terminal file descriptors in input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            set_io_entry_element(io, (void*) &outf, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            set_io_entry_element(io, (void*) &inf, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
            //
            // Store client list item in input/output entry.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the array's count and size are CONSTANT.
            //
            // CAUTION! Do NOT hand over input/output entry as pointer reference.
            //
            set_io_entry_element(io, (void*) &cl, (void*) CLIENT_LIST_INPUT_OUTPUT_STATE_CYBOI_NAME);

            //
            // Store input/output entry in internal memory.
            //
            // CAUTION! Do NOT use "overwrite_array" function here,
            // since it adapts the array count and size.
            // But the internal array's count and size are CONSTANT.
            //
            // CAUTION! Hand over input/output entry as pointer REFERENCE.
            //
            copy_array_forward(p0, (void*) &io, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &i, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The terminal already exists in internal memory.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal. The service identification is invalid.");
    }
}

/* TERMINAL_STARTER_SOURCE */
#endif
