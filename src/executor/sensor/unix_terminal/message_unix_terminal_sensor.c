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

#ifndef MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE
#define MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE

#include <stdio.h> // fdopen
#include <threads.h> // mtx_t, mtx_lock, mtx_unlock
#include <wchar.h> // fgetwc, fgetwc_unlocked

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Senses unix terminal message.
 *
 * @param p0 the interrupt request
 * @param p1 the access mutex
 * @param p2 the file stream
 */
void sense_unix_terminal_message(void* p0, void* p1, void* p2) {

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        FILE* f = (FILE*) p2;

        if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            mtx_t* m = (mtx_t*) p1;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                volatile sig_atomic_t* i = (volatile sig_atomic_t*) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal message.");
                //?? fwprintf(stdout, L"Test: Sense unix terminal message. p0: %i\n", p0);

                //
                // Lock mutex.
                //
                // CAUTION! This function call blocks the current thread
                // until the mutex is locked.
                //
                // CAUTION! This guarantees exclusive access to
                // input/output resources as well as the interrupt request,
                // which are shared between input sensing (child) threads
                // and the main (parent) thread.
                //
                // CAUTION! Not all input/output channels use sensing threads.
                // Sometimes, the main thread is the only one accessing resources.
                //
                mtx_lock(m);

                //
                // Get character from source input stream of terminal.
                //
                // This is just to detect if some character is available,
                // what is also called "peeking ahead" at the input.
                //
                // CAUTION! The multibyte character is converted to a
                // wide character internally in glibc function "fgetwc".
                //
                // CAUTION! Use 'wint_t' instead of 'int' as return type for
                // 'fgetwc()', since that returns 'WEOF' instead of 'EOF'!
                //
                // CAUTION! The return value of type "wint_t"
                // MAY BE CASTED to "wchar_t".
                //
                // CAUTION! Do NOT use function "fgetwc_unlocked",
                // since it is a gnu extension and may not exist everywhere.
                //
                // CAUTION! Do NOT use the function "read", which is lower-level
                // and may even be a system call directly into the OS.
                // Furthermore, it is NOT standard C, but part of POSIX.
                //

//?? --
                int testf = fileno(stdin);
                struct termios testm;
                int teste = tcgetattr(testf, &testm);

                fwprintf(stdout, L"Test: Sense unix terminal message. termios testf: %i\n", testf);
                fwprintf(stdout, L"Test: Sense unix terminal message. termios testm: %i\n", testm);
                fwprintf(stdout, L"Test: Sense unix terminal message. termios teste: %i\n", teste);
                fwprintf(stdout, L"Test: Sense unix terminal message. termios testm.c_cc[VMIN]: %i\n", testm.c_cc[VMIN]);
//?? --

                volatile wint_t c = fgetwc(f);

                fwprintf(stdout, L"Test: Sense unix terminal message. c: %i\n", c);

                //
                // The WEOF constant usually corresponds to the value -1.
                //
                // CAUTION! However, do NOT compare like the following:
                //     if (c < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
                // The reason is that wint_t and int comparison might deliver
                // wrong results, so that an input is mistakenly assumed below.
                //
                if (c != WEOF) {

                    //
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
                    // The GNU C library only supports ONE character of pushback.
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
                    //
                    fwprintf(stdout, L"Test: Sense unix terminal message. unread c: %i\n", c);
                    ungetwc(c, f);

/*??
                    //?? TEST BEGIN
                    wint_t test = fgetwc(f);
                    fwprintf(stdout, L"TEST sense unix terminal c SECOND READING: %lc\n", c);
                    ungetwc(test, f);
                    test = fgetwc(f);
                    fwprintf(stdout, L"TEST sense unix terminal c THIRD READING: %lc\n", c);
                    ungetwc(test, f);
                    //?? TEST END
*/

                    // Set interrupt request.
                    copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                } else {

                    //
                    // The returned value is WEOF.
                    //
                    // CAUTION! This error should NEVER happen, since
                    // the terminal is set to "blocking" mode (VMIN = 1)
                    // so that it will only return when at least
                    // ONE VALID character is available.
                    //

                    //
                    //?? TODO: This is commented out temporarily,
                    // as long as operating system signal handling
                    // for interrupting the sensing thread does not work yet.
                    //
                    // Otherwise, many of these error messages are written
                    // to standard output, because on system SHUTDOWN,
                    // the sensing thread is still running but  due to
                    // missing (already destroyed) resources in non-blocking mode.
                    //
                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The returned value is WEOF.");
                    fwprintf(stdout, L"Error: Could not sense unix terminal message. The returned value is WEOF. p0: %i\n", p0);
                }

                // Unlock mutex.
                mtx_unlock(m);

                //
                // Wait until interrupt request is reset by main thread.
                //
                // This endless waiting loop is also called "busy waiting".
                // Its running causes the processor (cpu) to run at 100 %.
                // However, the usual case is that the main thread needs
                // only minimal time to handle the interrupt request,
                // so that this endless loop is left very quickly.
                //
                fwprintf(stdout, L"Test: Sense unix terminal message. enter loop. *i: %i\n", *i);
                while (*i != *FALSE_BOOLEAN_STATE_CYBOI_MODEL);
                fwprintf(stdout, L"Test: Sense unix terminal message. leave loop. *i: %i\n", *i);

                static int testcounter = 1;
                testcounter++;
                fwprintf(stdout, L"Test: Sense unix terminal message. testcounter: %i\n", testcounter);
                if (testcounter == 5) exit(0);

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The interrupt request is null.");
                fwprintf(stdout, L"Error: Could not sense unix terminal message. The interrupt request is null. p0: %i\n", p0);
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The access mutex is null.");
            fwprintf(stdout, L"Error: Could not sense unix terminal message. The access mutex is null. p1: %i\n", p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal message. The file stream is null.");
        fwprintf(stdout, L"Error: Could not sense unix terminal message. The file stream is null. p2: %i\n", p2);
    }
}

/* MESSAGE_UNIX_TERMINAL_SENSOR_SOURCE */
#endif
