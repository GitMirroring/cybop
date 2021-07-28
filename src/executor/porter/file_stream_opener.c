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

#ifndef FILE_STREAM_OPENER_SOURCE
#define FILE_STREAM_OPENER_SOURCE

#include <errno.h> // errno
#include <stdio.h> // FILE, fopen

#include "../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/memoriser/allocator/item_allocator.c"
#include "../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../logger/logger.c"

/**
 * Opens a file stream.
 *
 * @param p0 the file stream (pointer reference)
 * @param p1 the file name data
 * @param p2 the file name count
 * @param p3 the opentype
 */
void open_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        char* t = (char*) p3;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** s = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open file stream.");

            // The terminated file name item.
            void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
            // The terminated file name item data.
            void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;

            //
            // Allocate terminated file name item.
            //
            // CAUTION! Do NOT use wide characters here.
            //
            // CAUTION! Due to memory allocation handling, the size MUST NOT
            // be negative or zero, but have at least a value of ONE.
            //
            allocate_item((void*) &n, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

            // Encode wide character name into multibyte character array.
            encode_utf_8(n, p1, p2);

            // Add null termination character.
            modify_item(n, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

            //
            // Get terminated file name item data.
            //
            // CAUTION! Retrieve data ONLY AFTER having called desired functions!
            // Inside the structure, arrays may have been reallocated,
            // with elements pointing to different memory areas now.
            //
            copy_array_forward((void*) &nd, n, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

            //
            // Initialise error number.
            //
            // It is a global variable/function and other operations
            // may have set some value that is not wanted here.
            //
            // CAUTION! Initialise the error number BEFORE calling
            // the function that might cause an error.
            //
            errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // Open file.
            //
            // CAUTION! The file name CANNOT be handed over as is.
            // CYBOI strings are NOT terminated with the null character '\0'.
            // Since 'fopen' expects a null terminated string, the termination character
            // must be added to the string before that is used to open the file.
            //
            // CAUTION! The mode string can also include the letter 'b'
            // either as a last character or as a character between.
            // This is strictly for compatibility with C89 and has no effect;
            // the 'b' is ignored on all POSIX conforming systems, including Linux.
            // Other systems may treat text files and binary files differently.
            // Since cyboi is also compiled for windows using "mingw",
            // and mingw replaces "carriage return" when opening a file in text mode,
            // the 'b' character is added to the mode here.
            //
            // http://man7.org/linux/man-pages/man3/fopen.3.html
            //
            // Example:
            //
            // This problem became obvious when opening xDT German medical data files.
            // Following the xDT standard, they are to use CR+LF as end of line.
            // Parsing would not work anymore, if CR characters got replaced
            // on opening the file.
            //
            *s = (void*) fopen((char*) nd, t);

            if (*s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Open file stream. Success.");
                fwprintf(stdout, L"Debug: Open file stream. Success. *s: %i\n", *s);

            } else {

                //
                // An error occured.
                //

                fwprintf(stdout, L"Could not open file stream. The file stream is null. nd: %s\n", (char*) nd);

                if (errno == EACCES) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. The process does not have search permission for a directory component of the file name.");
                    fwprintf(stdout, L"Error: Could not open file stream. The process does not have search permission for a directory component of the file name. error EACCES: %i\n", errno);

                } else if (errno == ENAMETOOLONG) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");
                    fwprintf(stdout, L"Error: Could not open file stream. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX. error ENAMETOOLONG: %i\n", errno);

                } else if (errno == ENOENT) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. This error is reported when a file referenced as a directory component in the file name doesn't exist, or when a component is a symbolic link whose target file does not exist.");
                    fwprintf(stdout, L"Error: Could not open file stream. This error is reported when a file referenced as a directory component in the file name doesn't exist, or when a component is a symbolic link whose target file does not exist. error ENOENT: %i\n", errno);

                } else if (errno == ENOTDIR) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. A file that is referenced as a directory component in the file name exists, but it isn't a directory.");
                    fwprintf(stdout, L"Error: Could not open file stream. A file that is referenced as a directory component in the file name exists, but it isn't a directory. error ENOTDIR: %i\n", errno);

                } else if (errno == ELOOP) {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops.");
                    fwprintf(stdout, L"Error: Could not open file stream. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops. error ELOOP: %i\n", errno);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. An unknown error occured.");
                    fwprintf(stdout, L"Error: Could not open file stream. An unknown error occured. errno: %i file: %s\n", errno, (char*) nd);
                }
            }

            // Deallocate terminated file name item.
            deallocate_item((void*) &n, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. The file stream is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not open file stream. The opentype is null.");
    }
}

/* FILE_STREAM_OPENER_SOURCE */
#endif
