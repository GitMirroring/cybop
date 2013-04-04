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

#ifndef TERMINAL_SHUTTER_SOURCE
#define TERMINAL_SHUTTER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>
#ifdef GNU_LINUX_OPERATING_SYSTEM
    #include <termios.h>
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/lifeguard/interrupter/thread_interrupter.c"
#include "../../../../executor/maintainer/shutter/terminal/attributes_terminal_shutter.c"
#include "../../../../executor/maintainer/shutter/terminal/close_terminal_shutter.c"
#include "../../../../logger/logger.c"

/**
 * Shuts down the terminal.
 *
 * This is done in the reverse order the service was started up.
 *
 * @param p0 the internal memory data
 * @param p1 the service thread
 * @param p2 the service thread interrupt
 */
void shutdown_terminal(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Shutdown terminal.");

    // The input- and output file descriptor item.
    void* ip = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* op = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The input- and output file descriptor item data.
    void* ipd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* opd = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get input- and output file descriptor item.
    copy_array_forward((void*) &ip, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &op, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Only deallocate terminal resources if AT LEAST ONE,
    // the input- OR output stream internal is NOT null.
    if ((ip != *NULL_POINTER_STATE_CYBOI_MODEL) || (op != *NULL_POINTER_STATE_CYBOI_MODEL)) {

        // Interrupt terminal service thread.
        interrupt_thread(p1, p2);

        // Get input- and output file descriptor item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &ipd, ip, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &opd, op, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // The input- and output file descriptor item data as integer.
        int* ipdi = (int*) ipd;
        int* opdi = (int*) opd;

        //
        // Reset attributes of terminal.
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

            shutdown_terminal_attributes(ipd, p0);

        } else if (*opdi >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            shutdown_terminal_attributes(opd, p0);

        } else {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. The file descriptor is zero or negative.");
        }

        //
        // CAUTION! The input- and output file descriptors are NOT closed here,
        // since they reference the "stdin" and "stdout" streams of the system,
        // which MUST NOT be closed.
        //
        // However, if they have to be closed one day for some reason,
        // then do NOT put these function calls in the if-else branch
        // of the attributes above!
        // Whilst the attributes have to be reset just ONCE for the terminal,
        // no matter which of the file descriptors are given,
        // the file descriptors themselves have to be closed each, one by one.
        //
        // shutdown_terminal_close(ipd);
        // shutdown_terminal_close(opd);

        // Deallocate input- and output file descriptor item.
        deallocate_item((void*) &ip, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);
        deallocate_item((void*) &op, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Reset terminal file descriptor.
        // CAUTION! Assign NULL to the internal memory.
        // It is ESSENTIAL, since cyboi tests for null pointers.
        // Otherwise, wild pointers would lead to memory corruption.
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) INPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        copy_array_forward(p0, (void*) NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) OUTPUT_FILE_DESCRIPTOR_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not shutdown terminal. There is no terminal running.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* TERMINAL_SHUTTER_SOURCE */
#endif
