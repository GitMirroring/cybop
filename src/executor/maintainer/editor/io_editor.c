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

#ifndef IO_EDITOR_SOURCE
#define IO_EDITOR_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/input_output_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/copier/array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Edits the input/output entry settings of the given service.
 *
 * @param p0 the input/output entry
 * @param p1 the terminal blocking mode
 * @param p2 the terminal canonical mode
 * @param p3 the terminal echo mode
 */
void edit_io(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Edit io.");
    //?? fwprintf(stdout, L"Debug: Edit io. p0: %i\n", p0);

    // The terminal blocking mode.
    void* b = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal canonical mode.
    void* c = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal echo mode.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get terminal blocking mode from input/output entry.
    copy_array_forward((void*) &b, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) BLOCKING_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get terminal canonical mode from input/output entry.
    copy_array_forward((void*) &c, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) CANONICAL_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);
    // Get terminal echo mode from input/output entry.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ECHO_TERMINAL_INPUT_OUTPUT_STATE_CYBOI_NAME);

    // Initialise terminal blocking mode.
    copy_integer(b, p1);
    // Initialise terminal canonical mode.
    copy_integer(c, p2);
    // Initialise terminal echo mode.
    copy_integer(e, p3);
}

/* IO_EDITOR_SOURCE */
#endif
