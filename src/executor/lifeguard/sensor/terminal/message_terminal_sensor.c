/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MESSAGE_TERMINAL_SENSOR_SOURCE
#define MESSAGE_TERMINAL_SENSOR_SOURCE

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/runner/sleeper.c"
#include "../../../../logger/logger.c"

/**
 * Senses terminal message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the file descriptor data
 */
void sense_terminal_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p3;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            pthread_mutex_t* mt = (pthread_mutex_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                volatile sig_atomic_t* irq = (volatile sig_atomic_t*) p0;

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // Also, this function runs in an endless loop and would produce huge log files.

                // The file stream created from the given file descriptor.
                // CAUTION! The opentype string "r+" means an existing file
                // is opened for both reading and writing.
                // The initial contents of the file are unchanged and
                // the initial file position is at the beginning of the file.
//??                void* fs = (void*) fdopen(*f, "r+");

                //?? TODO: For some reason, the file descriptor-to-stream conversion above does not work.
                //?? It causes the terminal not to be able to "fgetwc" characters.
                //?? (In sensor, "fgetwc" works fine, but not in receiver.)
                //?? Therefore, "stdin" is used for now.
                void* fs = (void*) stdin;

                if (fs != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // Lock terminal mutex.
                    //
                    // CAUTION! This lock has to stand not only before the interrupt request is set below,
                    // BUT ALSO BEFORE the next character is detected in the input stream!
                    //
                    // This is because the main thread might be reading characters from the
                    // input stream right now in parallel, while this thread tries to read as well.
                    //
                    // This was tested out and lead to errors, because the "ungetwc" function below
                    // was unexpectedly putting back a character such as ^ (escape) or [
                    // which (in the case of escape) caused the programme to exit
                    // and other inputs like arrow down not to be recognised properly.
                    pthread_mutex_lock(mt);

                    // Get character from source input stream of terminal.
                    //
                    // This is just to detect that some character is available,
                    // what is also called "peeking ahead" at the input.
                    //
                    // CAUTION! The multibyte character is converted to a
                    // wide character internally in glibc function "fgetwc".
                    //
                    // CAUTION! Use 'wint_t' instead of 'int' as return type for
                    // 'getwchar()', since that returns 'WEOF' instead of 'EOF'!
                    //
                    // CAUTION! The return value of type "wint_t"
                    // MAY BE CASTED to "wchar_t".
                    wint_t c = fgetwc((FILE*) fs);

                    // The WEOF constant usually corresponds to the value: -1
                    //
                    // CAUTION! However, do NOT compare like the following:
                    // if (c < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                    // The reason is that wint_t and int comparison might deliver
                    // wrong results, so that an input is mistakenly assumed below.
                    if (c == WEOF) {

                        // No valid character was returned.

                        // Sleep for some time.
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        sleep_nano(p2);

                    } else {

                        // Unread character, that is push it back on the stream to
                        // make it available to be input again from the stream, by the
                        // next call to fgetc or another input function on that stream.
                        //
                        // If c is EOF, ungetc does nothing and just returns EOF.
                        // This lets you call ungetc with the return value of getc
                        // without needing to check for an error from getc.
                        //
                        // The character that you push back doesn't have to be the same
                        // as the last character that was actually read from the stream.
                        // In fact, it isn't necessary to actually read any characters
                        // from the stream before unreading them with ungetc!
                        // But that is a strange way to write a program;
                        // usually ungetc is used only to unread a character that was
                        // just read from the same stream.
                        //
                        // The GNU C library only supports one character of pushback.
                        // In other words, it does not work to call ungetc twice without
                        // doing input in between.
                        // Other systems might let you push back multiple characters;
                        // then reading from the stream retrieves the characters in the
                        // reverse order that they were pushed.
                        //
                        // Pushing back characters doesn't alter the file;
                        // only the internal buffering for the stream is affected.
                        // If a file positioning function (such as fseek, fseeko or rewind)
                        // is called, any pending pushed-back characters are discarded.
                        //
                        // Unreading a character on a stream that is at end of file
                        // clears the end-of-file indicator for the stream, because it
                        // makes the character of input available.
                        // After you read that character, trying to read again will
                        // encounter end of file.
                        ungetwc(c, (FILE*) fs);

//?? fwprintf(stdout, L"TEST sense terminal c: %lc\n", c);

/*??
//?? TEST BEGIN
wint_t test = fgetwc((FILE*) fs);
fwprintf(stdout, L"TEST sense terminal c SECOND READING: %lc\n", c);
ungetwc(test, (FILE*) fs);
test = fgetwc((FILE*) fs);
fwprintf(stdout, L"TEST sense terminal c THIRD READING: %lc\n", c);
ungetwc(test, (FILE*) fs);
//?? TEST END
*/

                        // Set terminal interrupt request to indicate
                        // that a message has been received via terminal,
                        // which may now be processed in the main thread of this system.
                        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                    // Unlock terminal mutex.
                    pthread_mutex_unlock(mt);

                    // Access irq as atomic variable.
                    // CAUTION! Therefore better don't use the following line:
                    // while (*irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {
                    while (*irq) {

                        // Sleep as long as the terminal interrupt is not handled and reset yet.
                        //
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        //
                        // Also, many character inputs are processed at once in the main thread
                        // and only if there are no further characters to be read, the irq flag is reset,
                        // so that this endless loop can be left and new inputs detected.
                        sleep_nano(p2);
                    }

                } else {

                    fwprintf(stdout, L"ERROR: Could not sense terminal message. The file stream is null. fs: %i\n", fs);

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The file stream is null.");
                }

            } else {

                // CAUTION! DO NOT log this function call!
                // This function is executed within a thread, but the
                // logging is not guaranteed to be thread-safe and might
                // cause unpredictable programme behaviour.
                // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The interrupt is null.");
            }

        } else {

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The mutex is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The input stream is null.");
    }
}

/* MESSAGE_TERMINAL_SENSOR_SOURCE */
#endif
