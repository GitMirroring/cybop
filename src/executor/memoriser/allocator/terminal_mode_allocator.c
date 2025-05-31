/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

//
// Unix terminal mode:
//
// The structure of type "struct termios" stores the
// ENTIRE collection of attributes of a terminal / serial port.
// It is used with the functions "tcgetattr" and
// "tcsetattr" to get and set the attributes.
//
// CAUTION! When setting serial port modes, one should call "tcgetattr" first
// to get the current modes of the particular serial port device,
// modify only those modes that you are really interested in,
// and store the result with tcsetattr.
//
// It's a bad idea to simply initialize a "struct termios" structure
// to a chosen set of attributes and pass it directly to "tcsetattr".
// The programme may be run years from now, on systems that support
// members not documented here. The way to avoid setting these members
// to unreasonable values is to avoid changing them.
//
// What's more, different serial port devices may require
// different mode settings in order to function properly.
// So you should avoid blindly copying attributes
// from one serial port device to another.
//
// When a member contains a collection of independent flags,
// as the c_iflag, c_oflag and c_cflag members do,
// even setting the entire member is a bad idea,
// because particular operating systems have their own flags.
// Instead, one should start with the current value of the member
// and alter only those flags whose values matter in the programme,
// leaving any other flags unchanged.
//

/**
 * Allocates a terminal mode structure.
 *
 * @param p0 the terminal mode (pointer reference)
 */
void allocate_terminal_mode(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Allocate terminal mode.");

#if defined(__linux__) || defined(__unix__)
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNIX_TERMINAL_MODE_STATE_CYBOI_TYPE);
#elif defined(__APPLE__) && defined(__MACH__)
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) UNIX_TERMINAL_MODE_STATE_CYBOI_TYPE);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_array(p0, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) WIN32_CONSOLE_MODE_STATE_CYBOI_TYPE);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
