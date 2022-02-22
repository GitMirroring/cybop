/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef INTERRUPT_PIPE_READER_SOURCE
#define INTERRUPT_PIPE_READER_SOURCE

#include <unistd.h> // read

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/item_getter.c"
#include "../../../../executor/porter/locker.c"
#include "../../../../executor/porter/unlocker.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Reads message from interrupt pipe.
 *
 * @param p0 the destination handler (pointer reference)
 * @param p1 the source interrupt pipe read file descriptor
 * @param p2 the source interrupt handlers item
 * @param p3 the interrupt mutex
 */
void read_interrupt_pipe(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        //
        // CAUTION! Do NOT log messages within thread,
        // in order to avoid race conditions and other conflicts.
        //
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read interrupt pipe.");
        fwprintf(stdout, L"Debug: Read interrupt pipe. f: %i\n", f);
        fwprintf(stdout, L"Debug: Read interrupt pipe. *f: %i\n", *f);

        // The pipe value.
        int v = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

        //
        // Lock mutex.
        //
        // CAUTION! If only the pipe was accessed, then using a mutex
        // would NOT be necessary here, for the following reasons:
        //
        // 1 The values are only READ but nothing is written.
        //
        // 2 While there may be potentially many threads
        //   WRITING to this interrupt pipe, there is just ONE
        //   function in the main signal (event) loop reading it.
        //   Therefore, conflicts are impossible.
        //
        // 3 The ORDER of the values in the pipe is UNCHANGED.
        //   If new values are written to the pipe in one
        //   of the threads, then they are added at the end.
        //   A MUTEX is used for WRITING, so that all values
        //   belonging together are placed at once.
        //   Therefore, one can always be sure that the values
        //   being read in a sequence here really do belong together,
        //   to the same interrupt.
        //
        // CAUTION! However, using a mutex IS NECESSARY due to
        // the HANDLER ARRAY managed in parallel to the interrupt pipe.
        //
        lock(p3);

        //
        // Read from interrupt pipe.
        //
        // CAUTION! The safe way is to use the functions "snprintf" and "strtol".
        // However, if both processes were created using the same compiler version,
        // one can take advantage of the fact that anything in C can be
        // read or written as an array of char (byte).
        //
        // Example:
        //
        // int n = something();
        // write(pipe_w, &n, sizeof(n));
        // int n;
        // read(pipe_r, &n, sizeof(n));
        //
        // https://stackoverflow.com/questions/5237041/how-to-send-integer-with-pipe-between-two-processes
        //
        int n = read(*f, (void*) &v, (void*) SIGNED_INTEGER_INTEGRAL_TYPE_SIZE);

        fwprintf(stdout, L"Debug: Read interrupt pipe. n1: %i\n", n);
        fwprintf(stdout, L"Debug: Read interrupt pipe. v: %i\n", v);

        //
        // Get interrupt pipe handlers item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        // Alternative:
        //
        // Get interrupt pipe handlers item data.
        // copy_array_forward((void*) &hd, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Get handler from interrupt pipe handlers item data.
        // copy_array_forward(p0, hd, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        //

        // Get handler from source interrupt pipe handlers item.
        get_item(p0, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        // Remove handler from source interrupt pipe handlers item.
        modify_item(p2, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) REMOVE_MODIFY_LOGIC_CYBOI_FORMAT);

        // Unlock mutex.
        unlock(p3);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read interrupt pipe. The source interrupt pipe read file descriptor is null.");
        fwprintf(stdout, L"Error: Could not read interrupt pipe. The source interrupt pipe read file descriptor is null. p2: %i\n", p2);
    }
}

/* INTERRUPT_PIPE_READER_SOURCE */
#endif
