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

#ifndef FILE_SYSTEM_SENDER_SOURCE
#define FILE_SYSTEM_SENDER_SOURCE

#include <stdio.h>

#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/encoder/utf/utf_8_encoder.c"
#include "../../../logger/logger.c"
#include "../../../variable/reallocation_factor.c"

/**
 * Sends a character to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the break flag
 */
void send_file_character(void* p0, void* p1, void* p2, void* p3) {

    // The character.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Read character from source array.
    copy_array_forward(c, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Write character to file.
    char e = fputc(*((char*) c), (FILE*) p0);

    // Test error value.
    if (e == EOF) {

        // Set break flag, so that the loop can be left in the next cycle.
        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/**
 * Sends a wide character to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source data
 * @param p2 the source index
 * @param p3 the break flag
 */
void send_file_wide_character(void* p0, void* p1, void* p2, void* p3) {

    // The character.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Read character from source array.
    // CAUTION! Do NOT use WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE here!
    // The input is char, but stdout was set to wide character mode at cyboi startup.
    copy_array_forward(c, p1, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p2);

    // Write character to file.
    //
    // CAUTION! Do NOT use the "fputwc" function here, but "fwprintf" instead.
    // The input is char, but stdout was set to wide character mode at cyboi startup.
    // Therefore, fwprintf is used to convert char to wchar_t output.
    int e = fwprintf((FILE*) p0, L"%s", (char*) c);

    // Test error value.
    if (e != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // Set break flag, so that the loop can be left in the next cycle.
        copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/**
 * Sends an element to file.
 *
 * @param p0 the destination file stream
 * @param p1 the source array
 * @param p2 the source array index
 * @param p3 the break flag
 * @param p4 the wide character flag (FALSE_BOOLEAN_STATE_CYBOI_MODEL - char; TRUE_BOOLEAN_STATE_CYBOI_MODEL - wchar_t)
 */
void send_file_element(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* w = (int*) p4;

        if (*w == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            send_file_character(p0, p1, p2, p3);

        } else {

            send_file_wide_character(p0, p1, p2, p3);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file element. The wide character flag is null.");
    }
}

/**
 * Sends a file stream.
 *
 * @param p0 the destination file stream
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the wide character flag (FALSE_BOOLEAN_STATE_CYBOI_MODEL - char; TRUE_BOOLEAN_STATE_CYBOI_MODEL - wchar_t)
 */
void send_file_stream(void* p0, void* p1, void* p2, void* p3) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* sc = (int*) p2;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send file stream.");

fwprintf(stdout, L"TEST CONTENT d:\n%s\n", (char*) p1);
fwprintf(stdout, L"TEST CONTENT c: %i\n", *((int*) p2));

            // The loop variable.
            int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
            // The break flag.
            int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

            while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                if ((j >= *sc) || (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL)) {

                    break;
                }

                send_file_element(p0, p1, (void*) &j, (void*) &b, p3);

                j++;
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file stream. The file is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file stream. The source count is null.");
    }
}

/**
 * Sends a file that was read from a byte array.
 *
 * @param p0 the destination file name data (pointer reference)
 * @param p1 the destination file name count
 * @param p2 the destination file name size
 * @param p3 the source byte array
 * @param p4 the source byte array count
 */
void send_file(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* dc = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** d = (void**) p0;

            log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send file.");

            // The comparison result.
            int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
            // The file.
            FILE* f = (FILE*) *NULL_POINTER_STATE_CYBOI_MODEL;

fwprintf(stdout, L"TEST send 0:\n%i\n", *d);
            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_all_array((void*) &r, *d, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p1, (void*) STANDARD_OUTPUT_STREAM_TERMINAL_MODEL_COUNT);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // The given string is not a file name, but specifies the "standard_output".
                    f = stdout;

                    send_file_stream((void*) f, p3, p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

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
                }
            }

fwprintf(stdout, L"TEST send 1:\n%i\n", *d);
            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                compare_all_array((void*) &r, *d, (void*) STANDARD_ERROR_OUTPUT_STREAM_TERMINAL_MODEL, (void*) EQUAL_COMPARE_LOGIC_CYBOI_TYPE, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p1, (void*) STANDARD_ERROR_OUTPUT_STREAM_TERMINAL_MODEL_COUNT);

                if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                    // The given string is not a file name, but specifies the "standard_error_output".
                    f = stderr;

                    send_file_stream((void*) f, p3, p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

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
                }
            }

fwprintf(stdout, L"TEST send 2:\n%i\n", *d);
            if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                // If the given name does neither match the standard output
                // nor the standard error output, then interpret it as file name.

                // The terminated file name item.
                void* tn = *NULL_POINTER_STATE_CYBOI_MODEL;
                // The terminated file name item data, count.
                void* tnd = *NULL_POINTER_STATE_CYBOI_MODEL;

                // Allocate terminated file name item.
                allocate_item((void*) &tn, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

                // Encode wide character option into multibyte character array.
                encode_utf_8(tn, *d, p1);

                // Add null termination character to terminated file name.
                append_item_element(tn, (void*) NULL_CONTROL_ASCII_CHARACTER_CODE_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

                // Get terminated file name item data, count.
                // CAUTION! Retrieve data ONLY AFTER having called desired functions!
                // Inside the structure, arrays may have been reallocated,
                // with elements pointing to different memory areas now.
                copy_array_forward((void*) &tnd, tn, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

fwprintf(stdout, L"TEST send 3 tnd: %s\n", (char*) tnd);

                // Open file.
                // CAUTION! The file name cannot be handed over as is.
                // CYBOI strings are NOT terminated with the null character '\0'.
                // Since 'fopen' expects a null terminated string, the termination character
                // must be added to the string before that is used to open the file.
                f = fopen((char*) tnd, "w");

fwprintf(stdout, L"TEST send 4 f: %i\n", f);
                if (f != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    send_file_stream((void*) f, p3, p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

fwprintf(stdout, L"TEST send 5: %i\n", f);
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
                    fclose(f);

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file. The file is null.");
                }

                // Deallocate terminated file name item.
                deallocate_item((void*) &tn, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file. The destination is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not send file. The destination count is null.");
    }
}

/**
 * Sends a knowledge model as byte stream to the operating system's file system.
 *
 * @param p0 the internal memory
 * @param p1 the source name
 * @param p2 the source name count
 * @param p3 the source type
 * @param p4 the source type count
 * @param p5 the source model
 * @param p6 the source model count
 * @param p7 the source properties
 * @param p8 the source properties count
 * @param p9 the knowledge memory
 * @param p10 the knowledge memory count
 * @param p11 the language model
 * @param p12 the language model count
 * @param p13 the source clean flag
 * @param p14 the source clean flag count
 * @param p15 the file name
 * @param p16 the file name count
 */
void send_file_system(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8,
    void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Send file system.");

    // The serialised wide character item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encoded character item data, count.
    void* ed = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ec = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serialised wide character item data, count.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate serialised wide character array.
    allocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Allocate encoded character item.
    allocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise source knowledge model into serialised wide character array.
//    serialise(s, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);

    // Get serialised wide character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sc, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode serialised wide character array into encoded character array.
    encode_utf_8(e, sd, sc);

    // Get encoded character item data, count.
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    copy_array_forward((void*) &ed, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ec, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Write encoded array into file.
    send_file((void*) &p15, p16, *NULL_POINTER_STATE_CYBOI_MODEL, ed, ec);

    // Deallocate serialised wide character item.
    deallocate_item((void*) &s, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    // Deallocate encoded character item.
    deallocate_item((void*) &e, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);
}

/* FILE_SYSTEM_SENDER_SOURCE */
#endif
