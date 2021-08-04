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

#ifndef CHARACTER_UNIX_TERMINAL_READER_SOURCE
#define CHARACTER_UNIX_TERMINAL_READER_SOURCE

#include <stdio.h> // FILE, fdopen
#include <wchar.h> // wint_t, fgetwc, WEOF

#include "../../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/modifier/item_modifier.c"
#include "../../../../logger/logger.c"

//
// Why is all this ansi escape code detection done here
// and not only in the corresponding deserialiser?
//
// There are at least two reasons:
//
// 1 Endless Input
//
// If the system tried to read in all characters arriving at the terminal,
// there would be the danger of endless input causing an endless loop.
// Therefore, it makes sense to evaluate characters in between,
// to have a loop break and to let the system execute signals now and then.
//
// 2 Dependent Input
//
// If an experienced user knows the application user interface by heart
// he might blindly press the keys to dive into the menu structure.
// In this case, the first key press possibly relates to another user interface
// than the second one, e.g. if the first action opens another dialogue.
// In other words: The second input depends upon the result of the first.
// For such cases it is important to evaluate the first input
// before reading in further inputs.
//

/**
 * Reads a unix terminal character.
 *
 * @param p0 the destination item
 * @param p1 the source file stream
 * @param p2 the loop break flag
 * @param p3 the escape character flag
 * @param p4 the ansi escape code flag
 * @param p5 the input character
 */
void read_unix_terminal_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wint_t* c = (wint_t*) p5;

        if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* aec = (int*) p4;

            if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* esc = (int*) p3;

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    //?? FILE* f = (FILE*) p1;
                    int* f = (int*) p1;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read unix terminal character.");
                    //?? fwprintf(stdout, L"Test: Read unix terminal character. f: %i\n", f);

                    //
                    // Get character from source input stream of terminal.
                    //
                    // CAUTION! The multibyte character is converted to a
                    // wide character internally in glibc function "fgetwc".
                    //
                    // CAUTION! Use 'wint_t' instead of 'int' as return type for
                    // 'getwchar()', since that returns 'WEOF' instead of 'EOF'!
                    //
                    // CAUTION! The return value of type "wint_t"
                    // MAY BE CASTED to "wchar_t".
                    //
                    //?? *c = fgetwc(f);
                    // Read character from read pipe file descriptor.
                    size_t s = sizeof(*c);
                    int n = read(*f, (void*) c, s);
                    fwprintf(stdout, L"Test: Read unix terminal character. n: %i\n", n);
                    fwprintf(stdout, L"Test: Read unix terminal character. c: %i\n", *c);

                    //
                    // Check for end-of-file condition or read error,
                    // in which case WEOF (the integer -1) is returned.
                    //
                    if (*c != WEOF) {

                        if (*aec == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                            //
                            // The character sequence ESC[ was received before.
                            // This is the beginning of an ansi escape code sequence.
                            //

                            // Reset ansi escape code flag.
                            copy_integer(p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                            //
                            // Append source character to destination item.
                            // This is the actual ansi escape code.
                            //
                            modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            //
                            // Set loop break flag.
                            // All values have been received, so that the loop can be left now.
                            //
                            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                        } else if (*esc == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                            //
                            // The escape character ESC was received before.
                            // This might be the beginning of an ansi escape code.
                            //

                            // Reset escape character flag.
                            copy_integer(p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                            if (*c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                                //
                                // The escape character ESC received before
                                // is followed by an opening square bracket [.
                                // This is the beginning of an ansi escape code.
                                //

                                // Set ansi escape code flag.
                                copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                // Append source character to destination item.
                                modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            } else {

                                //
                                // The escape character ESC received before
                                // is followed by another, second character
                                // which is NOT an opening square bracket.
                                // This is NOT going to be an ansi escape code sequence.
                                //

                                //
                                // Unread this character so that it may be
                                // processed once more later on.
                                //
//??                                ungetwc(*c, f);

                                // Set loop break flag.
                                copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                            }

                        } else if (*c == *((wint_t*) ESCAPE_UNICODE_CHARACTER_CODE_MODEL)) {

                            //
                            // The escape character ESC was received.
                            // This might be the beginning of an ansi escape code.
                            //

                            // Set escape character flag.
                            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                            // Copy source character to destination character array.
                            modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                        } else {

                            //
                            // No special characters have been found.
                            // So this is a normal source character
                            // that is just copied to the destination.
                            //

                            // Copy source character to destination character array.
                            modify_item(p0, p5, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            //
                            // CAUTION! Do NOT set loop break flag here.
                            // More than just one character might have to be
                            // received in a sequence, e.g. an ansi escape code.
                            // In this case, only a WEOF will break the loop.
                            //
                        }

                    } else {

                        //
                        // CAUTION! Do NOT log message here, since this is NOT an error.
                        // The last return value in a sequence of characters is always invalid.
                        // This is the only way to recognise the end. So, this is normal behaviour.
                        //

                        // Set loop break flag.
                        copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The source file stream is null.");
                    fwprintf(stdout, L"Error: Could not read unix terminal character. The source file stream is null.\n");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The escape character mode is null.");
                fwprintf(stdout, L"Error: Could not read unix terminal character. The escape character mode is null.\n");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The ansi escape code mode is null.");
            fwprintf(stdout, L"Error: Could not read unix terminal character. The ansi escape code mode is null.\n");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The input character is null.");
        fwprintf(stdout, L"Error: Could not read unix terminal character. The input character is null.\n");
    }
}

/* CHARACTER_UNIX_TERMINAL_READER_SOURCE */
#endif
