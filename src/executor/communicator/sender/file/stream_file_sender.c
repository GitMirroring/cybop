/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_FILE_SENDER_SOURCE
#define STREAM_FILE_SENDER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/communicator/sender/file/content_file_sender.c"
#include "../../../../executor/comparator/all/array_all_comparator.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/reallocation_factor.c"

/**
 * Sends source to file with given name.
 *
 * @param p0 the destination file name data
 * @param p1 the destination file name count
 * @param p2 the source data
 * @param p3 the source count
 */
void send_file_stream(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send file stream.");

    // The terminated file name item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminated file name item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate terminated file name item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character file name into multibyte character data.
    encode_utf_8(t, p0, p1);

    // Add null termination character to terminated file name.
    append_item_element(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Get terminated file name item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // The file.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Open file.
    // CAUTION! The file name cannot be handed over as is.
    // CYBOI strings are NOT terminated with the null character '\0'.
    // Since 'fopen' expects a null terminated string, the termination character
    // must be added to the string before that is used to open the file.
    f = (void*) fopen((char*) td, "w");

    if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

        send_file_content((void*) f, p2, p3);

        // Flush any buffered output on the stream to the file.
        //
        // If this was not done here, the buffered output on the
        // stream would only get flushed automatically when either:
        // - one tried to do output and the output buffer is full
        // - the stream was closed
        // - the program terminated by calling exit
        // - a newline was written with the stream being line buffered
        // - an input operation on any stream actually read data from its file
        fflush((FILE*) f);

        // Close file.
        // CAUTION! Check file for null pointer to avoid a segmentation fault!
        fclose(f);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file stream file. The file is null.");
    }

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* STREAM_FILE_SENDER_SOURCE */
#endif
