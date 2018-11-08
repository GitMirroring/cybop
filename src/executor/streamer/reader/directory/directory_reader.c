/*
 * Copyright (C) 1999-2018. Christian Heller.
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
 * @version CYBOP 0.20.0 2018-06-30
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef DIRECTORY_READER_SOURCE
#define DIRECTORY_READER_SOURCE

#include <dirent.h>
#include <errno.h>
#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/logic/communication/receive_communication_logic_cybol_name.c"
#include "../../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/part/name_part_getter.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/streamer/reader/directory/close_directory_reader.c"
#include "../../../../executor/streamer/reader/directory/entries_directory_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads all files within the given directory.
 *
 * @param p0 the destination item
 * @param p1 the source model data (directory name)
 * @param p2 the source model count
 * @param p3 the source properties data (binary mode etc.)
 * @param p4 the source properties count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 */
void read_directory(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read directory.");

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
    modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Get terminated file name item data.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    // Initialise error number.
    // It is a global variable/function and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the procedure that might cause an error.
    errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Open directory stream.
    //
    // CAUTION! The file name CANNOT be handed over as is.
    // CYBOI strings are NOT terminated with the null character '\0'.
    // Since 'fopen' expects a null terminated string, the termination character
    // must be added to the string before that is used to open the file.
    //
    DIR* d = opendir((char*) td);

    if (d != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // Read directory entries.
//??        read_directory_entries((void*) d);

        // Close directory stream.
        read_directory_close((void*) d);

    } else {

        // An error occured.

        if (errno == EACCES) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. The process does not have search permission for a directory component of the file name. error EACCES: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. The process does not have search permission for a directory component of the file name.");

        } else if (errno == ENAMETOOLONG) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX. error ENAMETOOLONG: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");

        } else if (errno == ENOENT) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist. error ENOENT: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. This error is reported when a file referenced as a directory component in the file name doesn’t exist, or when a component is a symbolic link whose target file does not exist.");

        } else if (errno == ENOTDIR) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. A file that is referenced as a directory component in the file name exists, but it isn’t a directory. error ENOTDIR: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. A file that is referenced as a directory component in the file name exists, but it isn’t a directory.");

        } else if (errno == ELOOP) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops. error ELOOP: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops.");

        } else if (errno == EACCES) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. Read permission is denied for the directory named by dirname. error EACCES: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. Read permission is denied for the directory named by dirname.");

        } else if (errno == EMFILE) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. The process has too many files open. error EMFILE: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. The process has too many files open.");

        } else if (errno == ENFILE) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. The entire system, or perhaps the file system which contains the directory, cannot support any additional open files at the moment. error ENFILE: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. The entire system, or perhaps the file system which contains the directory, cannot support any additional open files at the moment.");

        } else if (errno == ENOMEM) {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. Not enough memory available. error ENOMEM: %i\n", errno);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. Not enough memory available.");

        } else {

            fwprintf(stdout, L"Could not read directory. The directory stream is null. An unknown error occured. errno: %i directory: %s\n", errno, (char*) td);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read directory. The directory stream is null. An unknown error occured.");
        }
    }

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* DIRECTORY_READER_SOURCE */
#endif
