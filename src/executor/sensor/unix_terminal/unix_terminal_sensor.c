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

#ifndef UNIX_TERMINAL_SENSOR_SOURCE
#define UNIX_TERMINAL_SENSOR_SOURCE

#include <stdio.h> // fdopen
#include <wchar.h> // fgetwc, fgetwc_unlocked

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../logger/logger.c"

/**
 * Senses unix terminal message.
 *
 * @param p0 the data available flag
 * @param p1 the file descriptor
 */
void sense_unix_terminal(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        //
        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Sense unix terminal.");
        //

//??         fwprintf(stdout, L"TEST sense unix terminal, file descriptor p1: %i\n", *((int*) p1));

        //
        // The file stream associated with the given file descriptor.
        //
        // CAUTION! The mode of the stream must be compatible with the mode of the
        // file descriptor. Possible modes are : "r", "r+", "w", "w+", "a", "a+"
        //
        // CAUTION! The file position indicator of the new stream is set to
        // that belonging to the file descriptor. The error and end-of-file
        // indicators are cleared.
        // Modes "w" or "w+" do not cause truncation of the file.
        //
        // CAUTION! The file descriptor is not duplicated. It will be closed
        // when the stream created by fdopen() is closed.
        // The  result of applying fdopen() to a shared memory object is undefined.
        //
        // https://stackoverflow.com/questions/1516766/how-to-get-a-file-stream-from-a-file-descriptor
        //
        // CAUTION! The opentype string "r+" means an existing file
        // is opened for both reading and writing:
        // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Opening-Streams
        //
        // CAUTION! Don't confuse terminal attributes with file attributes.
        // A device special file which is associated with a terminal
        // has file attributes as described in File Attributes:
        // https://www.gnu.org/software/libc/manual/html_mono/libc.html#File-Attributes
        // These are unrelated to the attributes of the terminal device itself,
        // which are discussed in this section:
        // https://www.gnu.org/software/libc/manual/html_mono/libc.html#Low_002dLevel-Terminal-Interface
        //
//??        void* fs = (void*) fdopen(*f, "r+");
        void* fs = stdin;

        if (fs != *NULL_POINTER_STATE_CYBOI_MODEL) {

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
            wint_t c = fgetwc((FILE*) fs);

            // The WEOF constant usually corresponds to the value: -1
            //
            // CAUTION! However, do NOT compare like the following:
            // if (c < *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {
            // The reason is that wint_t and int comparison might deliver
            // wrong results, so that an input is mistakenly assumed below.
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
//??                 fwprintf(stdout, L"TEST: sense unix terminal. c: %i\n", c);

                ungetwc(c, (FILE*) fs);

/*??
                //?? TEST BEGIN
                wint_t test = fgetwc((FILE*) fs);
                fwprintf(stdout, L"TEST sense unix terminal c SECOND READING: %lc\n", c);
                ungetwc(test, (FILE*) fs);
                test = fgetwc((FILE*) fs);
                fwprintf(stdout, L"TEST sense unix terminal c THIRD READING: %lc\n", c);
                ungetwc(test, (FILE*) fs);
                //?? TEST END
*/

                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            fwprintf(stdout, L"Error: Could not sense unix terminal. The file stream is null. fs: %i\n", fs);

            // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
            // Otherwise, it would produce huge log files filled up with useless entries.
            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal. The file stream is null.");
        }

    } else {

        fwprintf(stdout, L"Error: Could not sense unix terminal. The file descriptor is null.\n");

        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense unix terminal. The file descriptor is null.");
    }
}

/* UNIX_TERMINAL_SENSOR_SOURCE */
#endif
