/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPEN_TERMINAL_STARTER_SOURCE
#define OPEN_TERMINAL_STARTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#include <termios.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/terminal/get_attributes_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Opens the terminal.
 *
 * @param p0 the internal memory data
 */
void startup_terminal_open(void* p0) {

    // The input- and output file descriptor item.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input- and output file descriptor item data.
    void* ipd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* opd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input- and output file descriptor item.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only create new terminal resources if both,
    // input- AND output file descriptor are null.
    if ((ip == *NULL_POINTER_STATE_CYBOI_MODEL) && (op == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal open.");

        // Allocate input- and output file descriptor item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        // CAUTION! Use "item" for input- and output storage in internal memory,
        // since their counts and sizes are needed for deallocation.
        allocate_item((void*) &ip, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        allocate_item((void*) &op, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Set input- and output file descriptor item.
        // CAUTION! Add it as soon as it was allocated above
        // ALWAYS and not only if opened successfully below.
        // Otherwise, in case of an error, the shutdown function
        // freeing it may not find it leading to a memory leak.
        copy_array_forward(p0, (void*) &ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) &op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Get input- and output file descriptor item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &ipd, ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &opd, op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        if ((ipd != *NULL_POINTER_STATE_CYBOI_MODEL) && (opd != *NULL_POINTER_STATE_CYBOI_MODEL)) {

            // The input- and output file descriptor item data as integer.
            int* ipdi = (int*) ipd;
            int* opdi = (int*) opd;

            // The input- and output file stream.
            FILE* ips = stdin;
            FILE* ops = stdout;

            // Get input- and output file descriptor item data as integer
            // from input- and output file stream.
            *ipdi = fileno(ips);
            *opdi = fileno(ops);

            //
            // Get and set attributes of terminal.
            //
            // Although tcgetattr and tcsetattr specify the terminal device with a file descriptor,
            // the attributes are those of the terminal device itself and not of the file descriptor.
            // This means that the effects of changing terminal attributes are persistent;
            // if another process opens the terminal file later on, it will see the changed attributes
            // even though it doesn't have anything to do with the open file descriptor originally
            // specified in changing the attributes.
            //
            // Similarly, if a single process has multiple or duplicated file descriptors
            // for the same terminal device, changing the terminal attributes affects
            // input and output to all of these file descriptors.
            // This means, for example, that one can't open one file descriptor or stream
            // to read from a terminal in the normal line-buffered, echoed mode;
            // and simultaneously have another file descriptor for the same terminal
            // that one uses to read from it in single-character, non-echoed mode.
            // Instead, one has to explicitly switch the terminal back and forth between the two modes.
            //
            // Therefore, it does not matter whether the input- OR
            // output file descriptor is specified here. EITHER may be used.
            // The attribute changes affect the whole terminal,
            // that is input AND output.
            //
            if (*ipdi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                startup_terminal_attributes_get(ipd, p0);

            } else if (*opdi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                startup_terminal_attributes_get(opd, p0);

            } else {

                // The normal return value from "open" is a
                // non-negative integer file descriptor.
                // In the case of an error, a value of
                // minus one is returned instead.

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal open. The input- or output file descriptor is invalid.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal open. The input- or output item data or both are null.");
        }

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not startup terminal open. The input- or output item or both already exist.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* OPEN_TERMINAL_STARTER_SOURCE */
#endif
