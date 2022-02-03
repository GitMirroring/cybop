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

#ifndef TERMINAL_EDITOR_SOURCE
#define TERMINAL_EDITOR_SOURCE

#include <stdio.h> // stdout, stdin

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../../../executor/maintainer/editor/terminal/stream_terminal_editor.c"
#include "../../../../logger/logger.c"

/**
 * Edits the terminal settings.
 *
 * @param p0 the input/output entry
 */
void edit_terminal(void* p0) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Edit terminal.");

    //
    // The output- and input file streams.
    //
    // CAUTION! The standard input/output streams "stdin"
    // and "stdout" exist on posix as well as on win32.
    //
    void* os = (void*) stdout;
    void* is = (void*) stdin;

#if defined(__linux__) || defined(__unix__)
    edit_terminal_stream(p0, (void*) os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#elif defined(__APPLE__) && defined(__MACH__)
    edit_terminal_stream(p0, (void*) os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
// Use __CYGWIN__ too, if _WIN32 is not known to mingw.
#elif defined(_WIN32) || defined(__CYGWIN__)
    edit_terminal_stream(p0, (void*) os, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) OUTPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    edit_terminal_stream(p0, (void*) is, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) INPUT_FILE_STREAM_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
#else
    #error "Could not compile system. The operating system is not supported. Check out defined preprocessor macros!"
#endif
}

/* TERMINAL_EDITOR_SOURCE */
#endif
