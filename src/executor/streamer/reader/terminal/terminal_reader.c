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

#ifndef TERMINAL_READER_SOURCE
#define TERMINAL_READER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/streamer/reader/terminal/stream_terminal_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads data via terminal.
 *
 * @param p0 the destination item
 * @param p1 the input/output entry
 * @param p2 the interrupt request
 * @param p3 the mutex
 * @param p4 the internal memory data
 */
void read_terminal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        mtx_t* m = (mtx_t*) p3;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read terminal.");

        // The input file stream.
        //?? void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The pipe.
        //?? void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The read pipe file descriptor.
        //?? int rp = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
        // The wide character buffer item.
        void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The wide character buffer item data, count.
        void* wd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* wc = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get input file stream from input/output entry.
        //?? copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get pipe from input/output entry.
        //?? copy_array_forward((void*) &p, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get read pipe stream from input/output entry.
        //?? copy_array_forward((void*) &s, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) READ_STREAM_PIPE_INPUT_OUTPUT_STATE_CYBOI_NAME);
        // Get read pipe file descriptor.
        //?? copy_array_forward((void*) &rp, p, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
        // Get wide character buffer item from input/output entry.
        copy_array_forward((void*) &w, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) WIDE_CHARACTER_BUFFER_GENERAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
        //
        // Get wide character buffer item data, count.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &wd, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &wc, w, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        //?? fwprintf(stdout, L"Test: Read terminal. rp: %i\n", rp);
        fwprintf(stdout, L"Test: Read terminal. wc: %i\n", wc);
        fwprintf(stdout, L"Test: Read terminal. *wc: %i\n", *((int*) wc));

        //
        // Lock mutex.
        //
        // CAUTION! This function call blocks the current thread
        // until the mutex is locked.
        //
        // CAUTION! This guarantees exclusive access to
        // input/output resources as well as the interrupt request,
        // which are shared between input sensing (child) threads
        // and the main (parent) thread.
        //
        // CAUTION! Not all input/output channels use sensing threads.
        // Sometimes, the main thread is the only one accessing resources.
        // However, in order to have a uniform implementation,
        // a mutex exists for all channels and it does no harm
        // to lock it here even if only the main thread accesses it.
        //
        mtx_lock(m);

        // Read data from file stream.
        //?? read_terminal_stream(p0, s, p2, p3, p4);
        //?? read_terminal_stream(p0, (void*) &rp, p2, p3, p4);
        modify_item(p0, wd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, wc, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        // Unlock mutex.
        mtx_unlock(m);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read terminal. The mutex is null.");
        fwprintf(stdout, L"Error: Could not read terminal. The mutex is null.\n");
    }
}

/* TERMINAL_READER_SOURCE */
#endif
