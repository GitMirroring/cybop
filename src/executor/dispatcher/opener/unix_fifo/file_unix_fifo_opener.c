/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef FILE_UNIX_FIFO_OPENER_SOURCE
#define FILE_UNIX_FIFO_OPENER_SOURCE

#include <sys/stat.h> // mode_t, mkfifo
#include <errno.h> // errno

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

/**
 * Creates a unix fifo special file in the filesystem.
 *
 * @param p0 the filename data
 * @param p1 the filename count
 * @param p2 the open mode (permission bits)
 */
void open_unix_fifo_file(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        mode_t* m = (mode_t*) p2;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open unix fifo file.");
        fwprintf(stdout, L"Debug: Open unix fifo file. p0: %i\n", p0);

        // The terminated file name item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The terminated file name item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate terminated file name item.
        //
        // CAUTION! Do NOT use wide characters here.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Encode wide character name into multibyte character array.
        encode_utf_8(t, p0, p1);

        // Add null termination character.
        modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        //
        // Get terminated file name item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Cast terminated filename item data to correct type.
        char* tdt = (char*) td;

        //
        // Initialise error number.
        //
        // It is a global variable and other operations
        // may have set some value that is not wanted here.
        //
        // CAUTION! Initialise the error number BEFORE calling
        // the function that might cause an error.
        //
        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Create fifo special file in filesystem.
        int r = mkfifo(tdt, *m);

        if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open unix fifo file. Success.");
            fwprintf(stdout, L"Debug: Open unix fifo file. Success. r: %i\n", r);

        } else if (r > *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open unix fifo file. The return value is greater than zero which is undefined.");
            fwprintf(stdout, L"Warning: Could not open unix fifo file. The return value is greater than zero which is undefined. r: %i\n", r);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open unix fifo file. An error occured.");
            fwprintf(stdout, L"Error: Could not open unix fifo file. An error occured. %i\n", r);
            log_errno((void*) &errno);
        }

        // Deallocate terminated file name item.
        deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open unix fifo file. The open mode is null.");
        fwprintf(stdout, L"Error: Could not open unix fifo file. The open mode is null. p2: %i\n", p2);
    }
}

/* FILE_UNIX_FIFO_OPENER_SOURCE */
#endif
