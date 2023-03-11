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

#ifndef EMPTY_CHECKER_SOURCE
#define EMPTY_CHECKER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../executor/copier/array/forward_array_copier.c"
#include "../../executor/copier/integer_copier.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../executor/streamer/reader/interrupt_pipe/interrupt_pipe_reader.c"
#include "logger.h"

/**
 * Handles the situation that no signal is available in the signal memory
 * and queries interrupt requests instead.
 *
 * @param p0 the internal memory data
 * @param p1 the signal memory item
 * @param p2 the interrupt pipe
 */
void check_empty(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check empty.");
    //?? fwprintf(stdout, L"Debug: Check empty. p1: %i\n", p1);

    // The read interrupt request pipe file descriptor.
    int rd = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The handler (cybol callback function, signal event part representing the interrupt request handler).
    void* h = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The client identification.
    int id = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The internal memory client identification.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get read interrupt request pipe file descriptor.
    copy_array_forward((void*) &rd, p2, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    //
    // Read from interrupt pipe.
    //
    // The interrupt request pipe expects the following integer numbers.
    //
    // - channel: for choosing the correct LISTS in internal memory
    // - server flag: for choosing CLIENT- or SERVER list in internal memory (false == client; true == server)
    // - identification (id): for choosing the correct client- or server entry WITHIN the list, e.g. a client window id or server port number
    //
    // The correct cybol handler (callback function) can then be retrieved
    // from client- or server entry, in order to be executed in cyboi.
    // It is MANDATORY for input processing and OPTIONAL for output.
    //
    // Since the cybol handler refers to the corresponding device identifiation,
    // that one has to be set in cyboi YET BEFORE executing the handler.
    // Therefore, the corresponding SENDER or RECEIVER device identification
    // has to be set in cyboi.
    //
    read_interrupt_pipe((void*) &h, (void*) &id, (void*) &rd);

    //?? fwprintf(stdout, L"Debug: Check empty. rd: %i\n", rd);
    //?? fwprintf(stdout, L"Debug: Check empty. h: %i\n", h);
    //?? fwprintf(stdout, L"Debug: Check empty. id: %i\n", id);

    //
    // Add part model (signal) to signal memory.
    //
    // CAUTION! Use simple POINTER_STATE_CYBOI_TYPE and NOT PART_ELEMENT_STATE_CYBOI_TYPE here.
    // The signal memory just holds references to knowledge memory parts (signals),
    // but only the knowledge memory may care about rubbish (garbage) collection.
    //
    // Example:
    // Assume there are two signals in the signal memory.
    // The second references a logic part that is to be destroyed by the first.
    // If reference counting from rubbish (garbage) collection were used,
    // then the logic part serving as second signal could not be deallocated
    // as long as it is still referenced from the signal memory item.
    //
    // But probably, there is a reason the first signal wants to destroy the
    // second and consequently, the second should not be executed anymore.
    // After destruction, the second signal just points to null, which is ignored.
    // Hence, rubbish (garbage) collection would only disturb here
    // and should be left to the knowledge memory.
    //
    // CAUTION! If the handler is NULL, then it does NOT get copied inside.
    // A handler (callback cybol operation) does not always have to be given,
    // e.g. in an asynchronous send operation, a feedback is not always wanted or needed.
    //
    modify_item(p1, (void*) &h, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    // Get client identification from internal memory.
    copy_array_forward((void*) &i, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) IDENTIFICATION_INTERRUPT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Copy client identification.
    copy_integer(i, (void*) &id);
}

/* EMPTY_CHECKER_SOURCE */
#endif
