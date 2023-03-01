/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef UNIX_SERIAL_PORT_INITIALISER_SOURCE
#define UNIX_SERIAL_PORT_INITIALISER_SOURCE

#include <termios.h> // struct termios, ISTRIP etc.

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../logger/logger.c"

//
// Manipulate termios mode (attributes).
//
// A good documentation of possible flags may be found at:
// http://www.unixguide.net/unix/programming/3.6.2.shtml
//
// c_iflag: input mode flags; always needed, only not if using software flow control (ick)
// c_oflag: output mode flags; mostly hacks to make output to slow serial ports work,
//          newer systems have dropped almost all of them as obsolete
// c_cflag: control mode flags; set character size, generate even parity, enabling hardware flow control
// c_lflag: local mode flags; most applications will probably want to turn off ICANON
//          (canonical, i.e. line-based, input processing), ECHO and ISIG
// c_cc: an array of characters that have special meanings on input;
//       these characters are given names like VINTR, VSTOP etc.
//       the names are indexes into the array
//       two of these "characters" are not really characters at all,
//       but control the behaviour of function "read" when ICANON is disabled;
//       these are VMIN and VTIME
//
// VTIME: the time to wait before function "read" will return;
//        its value is (if not 0) always interpreted as a timer in tenths of seconds
// VMIN: the number of bytes of input to be available, before function "read" will return
//

/**
 * Initialises the unix terminal mode for a serial port.
 *
 * @param p0 the terminal mode
 * @param p1 the baudrate
 */
void initialise_unix_serial_port(void* p0, void* p1) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        struct termios* m = (struct termios*) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise unix serial port.");
        fwprintf(stdout, L"Debug: Initialise unix serial port. baudrate p1: %i\n", p1);
        fwprintf(stdout, L"Debug: Initialise unix serial port. baudrate *p1: %i\n", *((int*) p1));

        // The serialised baudrate item.
        void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The serialised baudrate item data.
        void* bd = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Allocate serialised baudrate item.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_item((void*) &b, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

        // Serialise baudrate integer value.
        serialise_terminal_mode_line_speed(b, p1);

        //
        // Get serialised wide character item data.
        //
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        //
        copy_array_forward((void*) &bd, b, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        if (bd != *NULL_POINTER_STATE_CYBOI_MODEL) {

            // The serialised baudrate item data as integer.
            int* bdi = (int*) bd;

            // Ignore parity.
            (*m).c_iflag = IGNPAR;

            (*m).c_oflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            (*m).c_cflag = *bdi | CS8 | CLOCAL | CREAD;

            (*m).c_lflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            //
            // Set blocking mode.
            //
            // Set number of input characters to be AVAILABLE, before "read" will return.
            //
            // Some documentations recommend to set TIME = 0 and MIN = 1 in noncanonical mode.
            // This means that "read" will BLOCK until at least one byte is available
            // and maintains best compatibility with normal behaviour of terminals.
            //
            // If set to ZERO, a character gets processed right away,
            // WITHOUT waiting for yet another character input, which is
            // the equivalent of non-blocking mode and NOT wanted here.
            //
            (*m).c_cc[VMIN] = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

            // Set time to wait before "read" will return.
            (*m).c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

            // Turn on DTR.
            //?? s |= TIOCM_DTR;
            // Turn on RTS.
            //?? s |= TIOCM_RTS;

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise unix serial port. The baudrate item data is null.");
        }

        //
        // Deallocate serialised baudrate array.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        deallocate_item((void*) &b, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not initialise unix serial port. The terminal mode is null.");
    }
}

/* UNIX_SERIAL_PORT_INITIALISER_SOURCE */
#endif
