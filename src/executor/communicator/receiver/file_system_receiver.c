/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_SYSTEM_RECEIVER_SOURCE
#define FILE_SYSTEM_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <stdio.h>

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/type/cyboi/logic_cyboi_type.c"
#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/stream_model.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/encoder/utf_8_unicode_character_encoder.c"
#include "../../../executor/memoriser/allocator/model_allocator.c"
#include "../../../executor/memoriser/deallocator/model_deallocator.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Receives a file stream.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source file stream
 */
void receive_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive file stream.");

        // Read first character.
        char c = fgetc(p3);

        while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

            if (c == EOF) {

                break;
            }

            // Set character into destination data.
            // The destination count serves as array index for setting the character.
            overwrite_array(p0, (void*) &c, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Read next character.
            c = fgetc(p3);
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive file stream. The file is null.");
    }
}

/**
 * Receives a file and writes it into a byte array.
 *
 * @param p0 the destination data (pointer reference)
 * @param p1 the destination count
 * @param p2 the destination size
 * @param p3 the source data (file name)
 * @param p4 the source count
 */
void receive_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive file.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The file.
    FILE* f = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, (void*) STANDARD_INPUT_STREAM_MODEL, (void*) EQUAL_PRIMITIVE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE, p4, (void*) STANDARD_INPUT_STREAM_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The given string is not a file name, but specifies the "standard_input".
            f = stdin;

            receive_file_stream(p0, p1, p2, (void*) f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // If the given name does not match the standard input, then interpret it as file name.

        // The terminated file name.
        void* tnd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int tnc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        int tns = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Allocate terminated file name.
        allocate_array((void*) &tnd, (void*) &tns, (void*) CHARACTER_STATE_CYBOI_TYPE);

        // Encode wide character name into multibyte character array.
        encode_utf_8_unicode_character_vector((void*) &tnd, (void*) &tnc, (void*) &tns, p3, p4);

        // Add null termination character to terminated file name.
        overwrite_array((void*) &tnd, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) &tnc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &tnc, (void*) &tns, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        // Open file.
        // CAUTION! The file name cannot be handed over as is.
        // CYBOI strings are NOT terminated with the null character '\0'.
        // Since 'fopen' expects a null terminated string, the termination character
        // must be added to the string before that is used to open the file.
        f = fopen((char*) tnd, "r");

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            receive_file_stream(p0, p1, p2, (void*) f);

            // Close file.
            // CAUTION! Check file for null pointer above
            // in order to avoid a segmentation fault here!
            fclose(f);

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive file. The file is null.");
        }

        // Deallocate terminated file name.
        deallocate_array((void*) &tnd, (void*) &tns, (void*) CHARACTER_STATE_CYBOI_TYPE);
    }
}

/**
 * Receives data via file system.
 *
 * @param p0 the destination model item (Hand over as item, since size may change!)
 * @param p1 the destination properties item (Hand over as item, since size may change!)
 * @param p2 the source data (file name)
 * @param p3 the source count
 * @param p4 the type
 */
void receive_file_system(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive file system.");

    // The encoded data, count, size.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int es = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate encoded data.
    allocate_array((void*) &ed, (void*) &es, (void*) CHARACTER_STATE_CYBOI_TYPE);

    // Write file into encoded data.
    receive_file((void*) &ed, (void*) &ec, (void*) &es, p2, p3);

//??    fwprintf(stdout, L"TEST char: %s\n", (char*) ed);

    // The decoded data, count, size.
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int dc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int ds = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Allocate decoded data.
    allocate_array((void*) &dd, (void*) &ds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);

    // Decode encoded data into decoded data.
    decode_utf_8_unicode_character_vector((void*) &dd, (void*) &dc, (void*) &ds, ed, (void*) &ec);

//??    fwprintf(stdout, L"TEST w_char: %ls\n", (wchar_t*) dd);

    // Deallocate encoded data.
    deallocate_array((void*) &ed, (void*) &es, (void*) CHARACTER_STATE_CYBOI_TYPE);

    // Deserialise decoded data into destination model and properties.
    decode(p0, p1, dd, (void*) &dc, p4);

    // Deallocate decoded data.
    deallocate_array((void*) &dd, (void*) &ds, (void*) WIDE_CHARACTER_STATE_CYBOI_TYPE);
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* FILE_SYSTEM_RECEIVER_SOURCE */
#endif
