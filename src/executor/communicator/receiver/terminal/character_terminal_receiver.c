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

#ifndef CHARACTER_TERMINAL_RECEIVER_SOURCE
#define CHARACTER_TERMINAL_RECEIVER_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <errno.h>
#include <wchar.h>

#include "../../../constant/model/character_code/ascii/ascii_character_code_model.c"
#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/comparator/all/array_all_comparator.c"
#include "../../../executor/converter/decoder/utf/utf_8_decoder.c"
#include "../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Receives a terminal character.
 *
 * @param p0 the destination data item
 * @param p1 the source terminal file descriptor
 * @param p2 the source terminal mutex
 * @param p3 the loop break flag
 * @param p4 the escape character mode
 * @param p5 the ansi escape code mode
 * @param p6 the input character
 */
void receive_terminal_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p7 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE* s = (FILE*) p7;

        if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* aec = (int*) p6;

            if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* esc = (int*) p5;

                if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    wint_t* c = (wint_t*) p4;

                    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        int* b = (int*) p3;

                        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Receive terminal character.");

                        // Initialise error number.
                        // It is a global variable/ function and other operations
                        // may have set some value that is not wanted here.
                        //
                        // CAUTION! Initialise the error number BEFORE calling
                        // the function that might cause an error.
                        errno = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                        // Lock terminal mutex.
                        pthread_mutex_lock(p8);

                        // Receive character from source input stream of terminal.
                        //
                        // CAUTION! The multibyte character is converted to a
                        // wide character internally (in glibc function "fgetwc").
                        // The return value of type "wint_t" MAY BE CASTED to "wchar_t".
                        // Calling the "decode" or "decode_utf_8" function
                        // is therefore NOT necessary here!
                        *c = fgetwc(s);

                        // Unlock terminal mutex.
                        pthread_mutex_unlock(p8);

                        if (errno != EILSEQ) {

                            if (*aec == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                // Reset ansi escape code flag.
                                *aec = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                                // Copy source character to destination character array.
                                overwrite_array(p0, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                // Set loop break flag.
                                // An escape character followed by a left square bracket character
                                // were received before. So this is an escape control sequence.
                                // Since all values have been received, the loop can be left now.
                                *b = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                            } else if (*esc == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                // Reset escape character flag.
                                *esc = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                                // An escape character was received before.

                                if (*c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                                    // The escape character received before is followed by an opening square bracket,
                                    // which means that this is the start of an escape control sequence.

                                    // Set ansi escape code flag.
                                    *aec = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                                    // Copy source character to destination character array.
                                    overwrite_array(p0, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                } else {

                                    // This is NOT going to be an escape control sequence.
                                    // An escape- followed by another, second character
                                    // (which is not an opening square bracket) has been detected.

                                    // Lock terminal mutex.
                                    pthread_mutex_lock(p8);

                                    // Unget this character so that it may be processed once more later on.
                                    ungetwc(*c, p7);

                                    // Unlock terminal mutex.
                                    pthread_mutex_unlock(p8);

                                    // Set loop break flag.
                                    *b = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
                                }

                            } else if (*c == *((wint_t*) ESCAPE_CONTROL_UNICODE_CHARACTER_CODE_MODEL)) {

                                // Set escape character flag.
                                *esc = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                                // Copy source character to destination character array.
                                overwrite_array(p0, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                            } else if (*c == WEOF) {

                                // The function "sense_terminal" filters out
                                // invalid (non-existing) characters recognised
                                // by the return value WEOF (-1).
                                // However, to be on the safe side, they are
                                // filtered out here once more.

                                // Set loop break flag.
                                *b = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;

                            } else {

                                // Copy source character to destination character array.
                                overwrite_array(p0, p4, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, p1, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                // Set loop break flag.
                                *b = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
                            }

                        } else {

                            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive from terminal. The character reading failed.");

                            // Set loop break flag.
                            *b = *TRUE_BOOLEAN_STATE_CYBOI_MODEL;
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive terminal character. The loop break flag is null.");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive terminal character. The input character is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive terminal character. The escape character mode is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive terminal character. The ansi escape code is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not receive terminal character. The source input stream is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* CHARACTER_TERMINAL_RECEIVER_SOURCE */
#endif
