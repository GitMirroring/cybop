/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef FILE_READER_SOURCE
#define FILE_READER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
 
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/terminal/stream_terminal_model.c"
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

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The file.
    FILE* f = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p1, (void*) STANDARD_INPUT_STREAM_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_FORMAT, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) STANDARD_INPUT_STREAM_TERMINAL_MODEL_COUNT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The given string is not a file name, but specifies the "standard_input".
            f = stdin;

            read_file_content(p0, (void*) f);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // If the given name does not match the standard input,
        // then interpret it as file name.

        // The terminated file name item.
        void* t = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The terminated file name item data.
        void* td = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The mode item.
        void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The mode item data.
        void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The binary mode flag part.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The binary mode flag part model item.
        void* bm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The binary mode flag part model item data.
        void* bmd = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get binary mode flag part.
        get_part_name((void*) &b, p3, (void*) BINARY_MODE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME, (void*) BINARY_MODE_RECEIVE_COMMUNICATION_LOGIC_CYBOL_NAME_COUNT, p4, p5, p6, p7);
        // Get binary mode flag part model item.
        copy_array_forward((void*) &bm, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get binary mode flag part model item data.
        copy_array_forward((void*) &bmd, bm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Allocate terminated file name item.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        // Allocate mode item.
        // CAUTION! Do NOT use wide characters here.
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        allocate_item((void*) &m, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        // Encode wide character name into multibyte character array.
        encode_utf_8(t, p1, p2);
        // Add null termination character.
        modify_item(t, (void*) NULL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        // Add read only character by default.
        modify_item(m, (void*) LATIN_SMALL_LETTER_R_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

        if (bmd != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* bmdi = (int*) bmd;

            if (*bmdi != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // Add binary mode character.
                modify_item(m, (void*) LATIN_SMALL_LETTER_B_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
            }

        } else {

            // The "binary" property was not given in the cybol source,
            // so that the file will be opened in text mode.
            // This is the default.
        }

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

        if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

            read_file_content(p0, (void*) f);

            // Close file.
            // CAUTION! Check file for null pointer above
            // in order to avoid a segmentation fault here!
            int e = fclose(f);

            if (e != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                // An error occured.

                if (e == EOF) {

                    fwprintf(stdout, L"Could not read file. The error EOF was detected on closing the file. e: %i\n", e);
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The error EOF was detected on closing the file.");

                } else {

                    fwprintf(stdout, L"Could not read file. An unknown error was detected on closing the file. e: %i\n", e);
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. An unknown error was detected on closing the file.");
                }
            }

        } else {

            fwprintf(stdout, L"Could not read file. The file descriptor is null. file: %s\n", (char*) td);
            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read file. The file descriptor is null.");
        }

        // Deallocate terminated file name item.
        deallocate_item((void*) &t, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
        // Deallocate mode item.
        deallocate_item((void*) &m, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
    }
}

/* FILE_READER_SOURCE */
#endif
