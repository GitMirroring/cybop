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
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_FILE_RECEIVER_SOURCE
#define STREAM_FILE_RECEIVER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/terminal/stream_terminal_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/receiver/file/content_file_receiver.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/converter/decoder.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/representer/deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Receives a file stream.
 *
 * @param p0 the destination item
 * @param p1 the source data (file name)
 * @param p2 the source count
 */
void receive_file_stream(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive file stream.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The file.
    FILE* f = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) STANDARD_INPUT_STREAM_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) STANDARD_INPUT_STREAM_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The given string is not a file name, but specifies the "standard_input".
            f = stdin;

            receive_file_content(p0, (void*) f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // If the given name does not match the standard input,
        // then interpret it as file name.

        // The terminated file name item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The terminated file name item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate terminated file name item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Encode wide character name into multibyte character array.
        encode_utf_8(t, p1, p2);

        // Add null termination character.
        append_item_element(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

        // Get terminated file name item data.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Open file.
        // CAUTION! The file name CANNOT be handed over as is.
        // CYBOI strings are NOT terminated with the null character '\0'.
        // Since 'fopen' expects a null terminated string, the termination character
        // must be added to the string before that is used to open the file.
        f = fopen((char*) td, "r");

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            receive_file_content(p0, (void*) f);

            // Close file.
            // CAUTION! Check file for null pointer above
            // in order to avoid a segmentation fault here!
            fclose(f);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive file stream. The file descriptor is null.");
        }

        // Deallocate terminated file name item.
        deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* STREAM_FILE_RECEIVER_SOURCE */
#endif
