/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef STREAM_FILE_WRITER_SOURCE
#define STREAM_FILE_WRITER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/checker/array_checker.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/streamer/writer/file/content_file_writer.c"
#include "../../../../logger/logger.c"

/**
 * Writes source to file with given name.
 *
 * @param p0 the destination file name data
 * @param p1 the destination file name count
 * @param p2 the source data
 * @param p3 the source count
 */
void write_file_stream(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Write file stream.");

    // The file.
    FILE* f = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminated file name item.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminated file name item data.
    void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mode item.
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The mode item data.
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate terminated file name item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate mode item.
    // CAUTION! Do NOT use wide characters here.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character file name into multibyte character data.
    encode_utf_8(t, p0, p1);

    // Add null termination character to terminated file name.
    modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Add write character by default.
    modify_item(m, (void*) LATIN_SMALL_LETTER_W_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Add null termination character by default.
    modify_item(m, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Get terminated file name item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    // Get mode item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Initialise error number.
    // It is a global variable/function and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the procedure that might cause an error.
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Open file.
    //
    // CAUTION! The file name cannot be handed over as is.
    // CYBOI strings are NOT terminated with the null character '\0'.
    // Since 'fopen' expects a null terminated string, the termination character
    // must be added to the string before that is used to open the file.
    //
    f = fopen((char*) td, (char*) md);

    if (((void*) f) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        write_file_content((void*) f, p2, p3);

        // Flush any buffered output on the stream to the file.
        //
        // If this was not done here, the buffered output on the
        // stream would only get flushed automatically when either:
        // - one tried to do output and the output buffer is full
        // - the stream was closed
        // - the program terminated by calling exit
        // - a newline was written with the stream being line buffered
        // - an input operation on any stream actually read data from its file
        fflush(f);

        // Close file.
        // CAUTION! Check file for null pointer to avoid a segmentation fault!
        int e = fclose(f);

        if (e != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            // An error occured.

            if (e == EOF) {

                fwprintf(stdout, L"Could not write file stream. The error EOF was detected on closing the file. e: %i\n", e);
                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The error EOF was detected on closing the file.");

            } else {

                fwprintf(stdout, L"Could not write file stream. An unknown error was detected on closing the file. e: %i\n", e);
                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. An unknown error was detected on closing the file.");
            }
        }

    } else {

        // An error occured.

        if (errno == EACCES) {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. The process does not have search permission for a directory component of the file name. error EACCES: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. The process does not have search permission for a directory component of the file name.");

        } else if (errno == ENAMETOOLONG) {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX. error ENAMETOOLONG: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");

        } else if (errno == ENOENT) {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist. error ENOENT: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist.");

        } else if (errno == ENOTDIR) {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. A file that is referenced as a directory component in the file name exists, but it isn’t a directory. error ENOTDIR: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. A file that is referenced as a directory component in the file name exists, but it isn’t a directory.");

        } else if (errno == ELOOP) {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops. error ELOOP: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops.");

        } else {

            fwprintf(stdout, L"Could not write file stream. The file stream is null. An unknown error occured. errno: %i file: %s\n", errno, (char*) td);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not write file stream. The file stream is null. An unknown error occured.");
        }
    }

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate mode item.
    deallocate_item((void*) &m, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* STREAM_FILE_WRITER_SOURCE */
#endif
