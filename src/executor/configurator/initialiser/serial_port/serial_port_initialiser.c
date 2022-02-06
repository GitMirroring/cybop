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

#ifndef SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE
#define SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE

#include <stdio.h>

#if defined(__linux__) || defined(__unix__)
    #include <sys/ioctl.h>
    #include <termios.h>
#elif defined(__APPLE__) && defined(__MACH__)
    #include <sys/ioctl.h>
    #include <termios.h>
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    #include <windows.h>
    // source: sys/termios.h
    #define IGNPAR          0000004
    #define CS8             0000060
    #define CLOCAL          0004000
    #define CREAD           0000200
    #define VMIN            6
    #define VTIME           5
    #define TCSANOW         0
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/maintainer/starter/serial_port/get_status_serial_port_starter.c"
#include "../../../../logger/logger.c"

/**
 * Sets the serial port attributes.
 *
 * @param p0 the file descriptor data
 * @param p1 the original attributes
 * @param p2 the baudrate
 */
void startup_serial_port_attributes_set(void* p0, void* p1, void* p2) {

    //
    // Manipulate termios attributes.
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
    //       but control the behaviour of read() when ICANON is disabled;
    //       these are VMIN and VTIME
    //
    // VTIME: the time to wait before read() will return;
    //        its value is (if not 0) always interpreted as a timer in tenths of seconds
    // VMIN: the number of bytes of input to be available, before read() will return
    //

    // Ignore parity.
    a.c_iflag = IGNPAR;
    a.c_oflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    a.c_cflag = *bdi | CS8 | CLOCAL | CREAD;
    a.c_lflag = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Set number of input characters to be available, before read() will return.
    // If set to zero, one character gets processed right away,
    // without waiting for yet another character input.
    a.c_cc[VMIN] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // Set time to wait before read() will return.
    a.c_cc[VTIME] = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
}

/* SET_ATTRIBUTES_SERIAL_PORT_STARTER_SOURCE */
#endif
