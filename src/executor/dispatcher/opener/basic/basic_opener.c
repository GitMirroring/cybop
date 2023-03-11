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

#ifndef BASIC_OPENER_SOURCE
#define BASIC_OPENER_SOURCE

#include <sys/stat.h> // mode_t
#include <errno.h> // errno
#include <fcntl.h> // open

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/copier/array/forward_array_copier.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "logger.h"

/**
 * Opens the device pointed to by the given filename.
 *
 * @param p0 the file descriptor, e.g. a file, serial port, terminal, socket
 * @param p1 the filename data
 * @param p2 the filename count
 * @param p3 the open flags
 * @param p4 the open mode (permission bits, used only when a file is created, may otherwise be null)
 */
void open_basic(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        mode_t* m = (mode_t*) p4;

        if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* f = (int*) p3;

            //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open basic.");
            //?? fwprintf(stdout, L"Debug: Open basic. p0: %i\n", p0);

            // The terminated filename item.
            void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminated filename item data.
            void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate terminated filename item.
            //
            // CAUTION! Do NOT use wide characters here.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Encode wide character name into multibyte character array.
            encode_utf_8(t, p1, p2);

            // Add null termination character.
            modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            //
            // Get terminated filename item data.
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

            //
            // Open file.
            //
            // CAUTION! The filename CANNOT be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            //
            // CAUTION! The last argument (mode) is used only when a file is CREATED,
            // but it doesn't hurt to supply the argument in any case.
            //
            int r = open(tdt, *f, *m);

            if (r >= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                //?? log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open basic. Success.");
                //?? fwprintf(stdout, L"Debug: Open basic. Success. r: %i\n", r);

                // Copy file descriptor to destination.
                copy_integer(p0, (void*) &r);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open basic. An error occured.");
                fwprintf(stdout, L"Error: Could not open basic. An error occured. %i\n", r);
                fwprintf(stdout, L"Error: Could not open basic. filename tdt: %s\n", tdt);
                log_error((void*) &errno);
            }

            // Deallocate terminated filename item.
            deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open basic. The open flags is null.");
            fwprintf(stdout, L"Error: Could not open basic. The open flags is null. p3: %i\n", p3);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open basic. The open mode is null.");
        fwprintf(stdout, L"Error: Could not open basic. The open mode is null. p4: %i\n", p4);
    }
}

/* BASIC_OPENER_SOURCE */
#endif
