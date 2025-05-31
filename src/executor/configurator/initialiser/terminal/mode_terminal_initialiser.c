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

#include "client.h"
#include "constant.h"
#include "logger.h"

//
// Linux:
//
// Although some functions specify the terminal device with a file descriptor,
// the attributes are those of the terminal device itself and NOT of the file descriptor.
// This means that the effects of changing terminal attributes are persistent;
// if another process opens the same terminal file later on, it will see
// the CHANGED attributes even though it doesn't have anything to do with
// the open file descriptor originally specified in changing the attributes.
//
// Similarly, if a single process has multiple or duplicated file descriptors
// for the same terminal device, changing the terminal attributes affects
// INPUT AND OUTPUT to ALL of these file descriptors.
//
// This means, for example, that one can't open one file descriptor or stream
// to read from a terminal in the normal line-buffered, echoed mode;
// and simultaneously have another file descriptor for the same terminal
// that one uses to read from it in single-character, non-echoed mode.
// Instead, one has to EXPLICITLY SWITCH the terminal back and forth between the two modes.
//
// Reference:
// https://www.gnu.org/software/libc/manual/html_mono/libc.html#Mode-Functions
//
// Since linux terminal modes are valid for input AND output,
// it does NOT matter whether the input- or output file descriptor
// is handed over as argument here. Either may be used.
// A redundant storage of mode settings does not make sense.
//

//
// Windows:
//
// A console consists of an input buffer and one or more output (screen) buffers.
// The mode of a console buffer determines how the console behaves
// during input and output (I/O) operations.
// ONE SET OF FLAG CONSTANTS is used with INPUT handles,
// and ANOTHER SET is used with screen buffer (OUTPUT) handles.
// Setting the output modes of one screen buffer does not affect
// the output modes of other screen buffers.
//
// Reference:
// https://docs.microsoft.com/en-us/windows/console/setconsolemode
//
// The sets of flag constants are definitely different, to be verified here:
// https://docs.microsoft.com/en-us/windows/console/setconsolemode
// The input- and output constants have OVERLAPPING VALUES (identification),
// so that both MUST NOT be combined or set together.
//
// Since windows distinguishes between the input and output mode settings
// and uses a DIFFERENT SET OF FLAGS for each, both are treated SEPARATELY here.
//

/**
 * Initialises the terminal mode.
 *
 * @param p0 the terminal mode
 */
void initialise_terminal_mode(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Initialise terminal mode.");

#if defined(__linux__) || defined(__unix__)
    initialise_unix_terminal(p0);
#elif defined(__APPLE__) && defined(__MACH__)
    initialise_unix_terminal(p0);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    initialise_win32_console_input(p0);
    initialise_win32_console_output(p0);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}
