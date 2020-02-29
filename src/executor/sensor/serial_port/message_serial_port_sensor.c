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

#ifndef MESSAGE_SERIAL_PORT_SENSOR_SOURCE
#define MESSAGE_SERIAL_PORT_SENSOR_SOURCE

#include <stdio.h>
#include <wchar.h>

#include "../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/runner/sleeper.c"

/**
 * Senses serial port message.
 *
 * @param p3 the file descriptor data
 */
void sense_serial_port_message(void* p0) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p0;

        // The file stream created from the given file descriptor.
        // CAUTION! The opentype string "r+" means an existing file
        // is opened for both reading and writing.
        // The initial contents of the file are unchanged and
        // the initial file position is at the beginning of the file.
        void* fs = (void*) fdopen(*f, "r+");

        if (fs != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // Get character from source input stream of terminal.
            //
            // This is just to detect that some character is available,
            // what is also called "peeking ahead" at the input.
            unsigned char c = fgetc((FILE*) fs);

            // The EOF constant usually corresponds to the value: -1
            if (c != ((unsigned char) EOF)) {

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
                ungetc(c, (FILE*) fs);

//?? fwprintf(stdout, L"TEST sense serial port message c: %c\n", c);

                // Set serial port interrupt request to indicate
                // that a message has been received via serial port,
                // which may now be processed in the main thread of this system.
                copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
            }

        } else {

            fwprintf(stdout, L"Error: Could not sense serial port message. The file stream is null. fs: %i\n", fs);

            // CAUTION! DO NOT log this function call!
            // This function is executed within a thread, but the
            // logging is not guaranteed to be thread-safe and might
            // cause unpredictable programme behaviour.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense serial port message. The file stream is null.");
        }

    } else {

        // CAUTION! DO NOT log this function call!
        // This function is executed within a thread, but the
        // logging is not guaranteed to be thread-safe and might
        // cause unpredictable programme behaviour.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not sense serial port message. The input stream is null.");
    }
}

/* MESSAGE_SERIAL_PORT_SENSOR_SOURCE */
#endif
