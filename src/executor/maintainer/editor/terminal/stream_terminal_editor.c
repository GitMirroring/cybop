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

#ifndef STREAM_TERMINAL_EDITOR_SOURCE
#define STREAM_TERMINAL_EDITOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../../executor/maintainer/editor/terminal/mode_terminal_editor.c"
#include "../../../../executor/maintainer/editor/terminal/get_file_number_terminal_editor.c"
#include "../../../../logger/logger.c"

/**
 * Edits the terminal stream.
 *
 * @param p0 the input/output entry
 * @param p1 the file stream
 */
void edit_terminal_stream(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Edit terminal stream.");

    // The terminal file descriptor.
    int d = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Get terminal file descriptor from file stream.
    edit_terminal_file_number_get((void*) &d, p1);

    // Edit original terminal mode.
    edit_terminal_mode((void*) &d, p0);
}

/* STREAM_TERMINAL_EDITOR_SOURCE */
#endif
