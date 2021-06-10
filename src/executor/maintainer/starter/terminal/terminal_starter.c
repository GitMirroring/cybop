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

#ifndef TERMINAL_STARTER_SOURCE
#define TERMINAL_STARTER_SOURCE

#include <stdio.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/maintainer/starter/terminal/stream_terminal_starter.c"
#include "../../../../logger/logger.c"

/**
 * Starts up the terminal.
 *
 * @param p0 the input/output entry
 */
void startup_terminal(void* p0) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Startup terminal.");

    //
    // The terminal output- and input file streams.
    //
    // CAUTION! The standard input/output streams "stdin"
    // and "stdout" exist on posix as well as on win32.
    //
    void* os = (void*) stdout;
    void* is = (void*) stdin;

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
    // However, output- AND input stream have to be stored here in
    // the input/output entry. It is true that both streams have
    // identical terminal settings. But if only the output stream was stored,
    // then the missing input stream would cause read errors.
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
    // Therefore, the function "startup_terminal_mode" is called twice,
    // once for input and another time for output.
    //
    // Arguments:
    //
    // The second argument is the file stream.
    // CAUTION! Hand it over as pointer REFERENCE.
    //
    // The third argument is a boolean value (flag)
    // indicating input (true) or output (false).
    // CAUTION! Do NOT set it to *NULL_POINTER_STATE_CYBOI_MODEL
    // since it is evaluated not only for the windows operating system
    // but also in function "startup_terminal_mode_store".
    //

#if defined(__linux__) || defined(__unix__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#elif defined(__APPLE__) && defined(__MACH__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    startup_terminal_stream(p0, (void*) &os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    startup_terminal_stream(p0, (void*) &is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_STARTER_SOURCE */
#endif
