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

#ifndef MESSAGE_TERMINAL_SENSOR_SOURCE
#define MESSAGE_TERMINAL_SENSOR_SOURCE

#ifdef GNU_LINUX_OPERATING_SYSTEM

#include <pthread.h>
#include <signal.h>
#include <wchar.h>

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../logger/logger.c"

/**
 * Senses terminal message.
 *
 * @param p0 the interrupt
 * @param p1 the mutex
 * @param p2 the sleep time
 * @param p3 the input stream
 */
void sense_terminal_message(void* p0, void* p1, void* p2, void* p3) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE* is = (FILE*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            double* st = (double*) p2;

            if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                pthread_mutex_t* mt = (pthread_mutex_t*) p1;

                if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    int* irq = (int*) p0;

                    // CAUTION! DO NOT log this function call!
                    // This function is executed within a thread, but the
                    // logging is not guaranteed to be thread-safe and might
                    // cause unpredictable programme behaviour.
                    // Also, this function runs in an endless loop and would produce huge log files.
                    // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply sense terminal message.");

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

                    // Get character from terminal input stream,
                    // just to detect that some (event) character is available.
                    // This is also called "peeking ahead" at the input.
                    //
                    // CAUTION! Use 'wint_t' instead of 'int' as return type for
                    // 'getwchar()', since that returns 'WEOF' instead of 'EOF'!
                    wint_t c = fgetwc(is);

//?? fwprintf(stdout, L"TEST sense terminal message c: %i\n", c);

                    if (c == WEOF) {

                        // No valid character was returned.

                        // Sleep for some time.
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        sleep(*st);

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
                        ungetwc(c, is);

                        // Set terminal interrupt request to indicate
                        // that a message has been received via terminal,
                        // which may now be processed in the main thread of this system.
                        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
                    }

                    // Unlock terminal mutex.
                    pthread_mutex_unlock(mt);

                    while (*irq != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // Sleep as long as the terminal interrupt is not handled and reset yet.
                        //
                        // This is to give the central processing unit (cpu) some
                        // time to breathe, that is to be idle or to process other signals.
                        //
                        // Also, many character inputs are processed at once in the main thread
                        // and only if there are no further characters to be read, the irq flag is reset,
                        // so that this endless loop can be left and new inputs detected.
                        sleep(*st);
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
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The sleep time is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense terminal message. The input stream is null.");
    }
}

/* GNU_LINUX_OPERATING_SYSTEM */
#endif

/* MESSAGE_TERMINAL_SENSOR_SOURCE */
#endif
