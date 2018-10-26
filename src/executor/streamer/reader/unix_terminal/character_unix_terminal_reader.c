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
 * @param p1 the source file descriptor
 * @param p2 the blocking flag
 * @param p3 the loop break flag
 * @param p4 the escape character flag
 * @param p5 the ansi escape code flag
 * @param p6 the input character
 */
void read_unix_terminal_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    if (p6 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        wint_t* c = (wint_t*) p6;

        if (p5 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* aec = (int*) p5;

            if (p4 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                int* esc = (int*) p4;

                if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* f = (int*) p1;

                    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Read unix terminal character.");

                    fwprintf(stdout, L"TEST read unix terminal character f: %i\n", f);
                    fwprintf(stdout, L"TEST read unix terminal character *f: %i\n", *((int*) f));

                    //
                    // Associate a stream with the given open file descriptor.
                    //
                    // CAUTION! A stream is a pointer to a FILE structure that
                    // contains information about a file.
                    //
                    // CAUTION! The opentype argument HAS TO MATCH the actual mode
                    // of the open file descriptor.
                    //
                    // CAUTION! The opentype option "r" means an existing file
                    // is opened for reading only.
                    // The initial contents of the file are unchanged and
                    // the initial file position is at the beginning of the file.
                    //
                    // CAUTION! The 'b' option is not permitted in the
                    // opentype string of the "fdopen" function.
                    //
                    // CAUTION! The file position indicator of the new stream
                    // is THE SAME file offset associated with the file descriptor.
                    // The error indicator and end of file (EOF) indicator
                    // for the stream are CLEARED.
                    //
                    void* s = (void*) fdopen(*f, "r");

                    //
                    //?? TODO: Fix the following!
                    //
                    // For some reason, the file descriptor-to-stream conversion above does not work.
                    // It causes the terminal not to be able to "fgetwc" characters (returnes -1).
                    // (In sensor, "fgetwc" works fine, but not in receiver.)
                    // Probably, the stream is ok, but possibly the file position pointer
                    // is not reset back to the beginning? But is this necessary for stdin?
                    //
                    // Therefore, use "stdin" as TEMPORARY workaround.
                    //
//??                    void* fs = (void*) stdin;

                    fwprintf(stdout, L"TEST read unix terminal character s: %i\n", s);

                    if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

                        FILE* fs = (FILE*) s;

                        fwprintf(stdout, L"TEST read unix terminal character fs: %i\n", fs);

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
                        *c = fgetwc(fs);

                        fwprintf(stdout, L"TEST read unix terminal character c: %i\n", *c);

                        // Check for end-of-file condition or read error,
                        // in which case WEOF (the integer -1) is returned.
                        //
                        // It is true, the "sense_unix_terminal" function
                        // already filters out invalid characters
                        // recognised by the return value WEOF.
                        // However, to be on the safe side, they are
                        // filtered out here once more.
                        if (*c != WEOF) {

                            if (*aec == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                // Reset ansi escape code flag.
                                copy_integer(p5, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                // Append source character to destination item.
                                modify_item(p0, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                // Set loop break flag.
                                // An escape character followed by a left square bracket character
                                // were received before. So this is an ansi escape code sequence.
                                // Since all values have been received, the loop can be left now.
                                copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                            } else if (*esc == *TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                                // Reset escape character flag.
                                copy_integer(p4, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                // An escape character was received before.

                                if (*c == *((wint_t*) LEFT_SQUARE_BRACKET_UNICODE_CHARACTER_CODE_MODEL)) {

                                    // The escape character received before is
                                    // followed by an opening square bracket,
                                    // which means that this is the start of
                                    // an ansi escape code.

                                    // Set ansi escape code flag.
                                    copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                    // Append source character to destination item.
                                    modify_item(p0, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                } else {

                                    // This is NOT going to be an escape control sequence.
                                    // An escape- followed by another, second character
                                    // (which is not an opening square bracket)
                                    // has been detected.

                                    // Unget this character so that it may be
                                    // processed once more later on.
                                    ungetwc(*c, fs);

                                    // Set loop break flag.
                                    copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                                }

                            } else if (*c == *((wint_t*) ESCAPE_UNICODE_CHARACTER_CODE_MODEL)) {

                                // Set escape character flag.
                                copy_integer(p4, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                                // Copy source character to destination character array.
                                modify_item(p0, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                            } else {

                                // Copy source character to destination character array.
                                modify_item(p0, p6, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

                                // Reset blocking flag.
                                // Some input has been received,
                                // so that waiting is not necessary anymore.
                                // In case the blocking flag is not needed or used,
                                // this resetting does NOT disturb or harm the programme.
                                copy_integer(p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

                                // CAUTION! Do NOT set loop break flag here,
                                // if more than just one character are to be
                                // received in a sequence, e.g. an ansi escape code.
                                // In this case, only a WEOF will break the loop.
                            }

                        } else {

                            // CAUTION! Do NOT log message here, since this is NOT an error.
                            // The last return value in a sequence of characters is always invalid.
                            // This is the only way to recognise the end. So, this is normal behaviour.

                            // Set loop break flag.
                            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                        }

                    } else {

                        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The source file stream is null.");

                        fwprintf(stdout, L"Error: Could not read unix terminal character. The source file stream is null.\n");
                    }

                } else {

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The source file descriptor is null.");
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The escape character mode is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The ansi escape code mode is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not read unix terminal character. The input character is null.");
    }
}

/* CHARACTER_UNIX_TERMINAL_READER_SOURCE */
#endif
