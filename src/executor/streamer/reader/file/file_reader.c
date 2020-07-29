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

#ifndef FILE_READER_SOURCE
#define FILE_READER_SOURCE

#include <stdio.h>

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
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
#include "../../../../executor/checker/operation_checker.c"
#include "../../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../../executor/copier/array_copier.c"
#include "../../../../executor/memoriser/allocator/item_allocator.c"
#include "../../../../executor/memoriser/deallocator/item_deallocator.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../executor/streamer/reader/file/content_file_reader.c"
#include "../../../../logger/logger.c"

/**
 * Reads file with the given name.
 *
 * @param p0 the destination item
 * @param p1 the source model data (file name)
 * @param p2 the source model count
 * @param p3 the source properties data (binary mode etc.)
 * @param p4 the source properties count
 * @param p5 the knowledge memory part (pointer reference)
 * @param p6 the stack memory item
 * @param p7 the internal memory data
 */
void read_file(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read file.");

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

    //
    // Allocate terminated file name item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    //
    // Allocate mode item.
    //
    // CAUTION! Do NOT use wide characters here.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Encode wide character name into multibyte character array.
    encode_utf_8(t, p1, p2);

    // Add null termination character.
    modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Add read only character by default.
    modify_item(m, (void*) LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    //
    // Add binary mode character.
    //
    // CAUTION! Always use BINARY MODE to open files,
    // no matter if for reading or writing. Otherwise,
    // when opening files in text mode, the following might happen:
    // - line endings such as <lf> get changed into <lf>+<cr>,
    //   especially on windows operating system
    // - binary data files such as images get corrupted
    //
    modify_item(m, (void*) LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
    // Add null termination character by default.
    modify_item(m, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    //
    // Get terminated file name item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &td, t, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    //
    // Get mode item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    //
    // Initialise error number.
    // It is a global variable/function and other operations
    // may have set some value that is not wanted here.
    //
    // CAUTION! Initialise the error number BEFORE calling
    // the procedure that might cause an error.
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
    f = fopen((char*) td, (char*) md);

    if (((void*) f) != *NULL_POINTER_STATE_CYBOI_MODEL) {

        read_file_content(p0, (void*) f);

        //
        // Close file.
        //
        // CAUTION! Check file for null pointer above
        // in order to avoid a segmentation fault here!
        //
        int e = fclose(f);

        if (e != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            //
            // An error occured.
            //

            fwprintf(stdout, L"Could not read file: %s\n", td);

            if (e == EOF) {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The error EOF was detected on closing the file.");
                fwprintf(stdout, L"Could not read file. The error EOF was detected on closing the file. e: %i\n", e);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. An unknown error was detected on closing the file.");
                fwprintf(stdout, L"Could not read file. An unknown error was detected on closing the file. e: %i\n", e);
            }
        }

    } else {

        //
        // An error occured.
        //

        fwprintf(stdout, L"Could not read file: %s\n", td);

        if (errno == EACCES) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. The process does not have search permission for a directory component of the file name.");
            fwprintf(stdout, L"Could not read file. The file stream is null. The process does not have search permission for a directory component of the file name. error EACCES: %i\n", errno);

        } else if (errno == ENAMETOOLONG) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX.");
            fwprintf(stdout, L"Could not read file. The file stream is null. This error is used when either the total length of a file name is greater than PATH_MAX, or when an individual file name component has a length greater than NAME_MAX. error ENAMETOOLONG: %i\n", errno);

        } else if (errno == ENOENT) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. This error is reported when a file referenced as a directory component in the file name doesn't exist, or when a component is a symbolic link whose target file does not exist.");
            fwprintf(stdout, L"Could not read file. The file stream is null. This error is reported when a file referenced as a directory component in the file name doesn't exist, or when a component is a symbolic link whose target file does not exist. error ENOENT: %i\n", errno);

        } else if (errno == ENOTDIR) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. A file that is referenced as a directory component in the file name exists, but it isn't a directory.");
            fwprintf(stdout, L"Could not read file. The file stream is null. A file that is referenced as a directory component in the file name exists, but it isn't a directory. error ENOTDIR: %i\n", errno);

        } else if (errno == ELOOP) {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops.");
            fwprintf(stdout, L"Could not read file. The file stream is null. Too many symbolic links were resolved while trying to look up the file name. The system has an arbitrary limit on the number of symbolic links that may be resolved in looking up a single file name, as a primitive way to detect loops. error ELOOP: %i\n", errno);

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file stream is null. An unknown error occured.");
            fwprintf(stdout, L"Could not read file. The file stream is null. An unknown error occured. errno: %i file: %s\n", errno, (char*) td);
        }
    }

    // Deallocate terminated file name item.
    deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate mode item.
    deallocate_item((void*) &m, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* FILE_READER_SOURCE */
#endif
