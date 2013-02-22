/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef SIGNAL_CHECKER_SOURCE
#define SIGNAL_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/checker/empty_checker.c"
#include "../../controller/checker/found_checker.c"
#include "../../executor/accessor/getter/item_getter.c"
#include "../../logger/logger.c"

/**
 * Checks for a signal and if none exists, for interrupts.
 *
 * There are various possibilities to process signals:
 *
 * 1 Signals - Interrupts
 *
 * First process all signals found in the signal memory
 * and only then check interrupts for new input.
 * The drawback of this solution is that the processing of a signal with
 * a long processing time cannot be interrupted by a key press or mouse click,
 * since these are not recognised as long as the interrupt flags are not checked.
 *
 * 2 Interrupts - Signals
 *
 * First check for and process all interrupts
 * and only then process the signals found in signal memory.
 * The drawback here might be that the system never comes to processing signals,
 * for example when acting as web server with thousands of client requests.
 * In this case, the client requests in form of socket interrupts would be
 * processed on and on and only if no more client requests could be found,
 * the actual signals in the signal memory would be processed.
 *
 * Further alternatives are welcome!
 *
 * The current solution implemented here is number 1.
 *
 * @param p0 the internal memory data
 * @param p1 the knowledge memory part
 * @param p2 the signal memory item
 * @param p3 the signal memory sleep time
 * @param p4 the shutdown flag
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n\n");
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check signal.");

    // The signal part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory index used to search for a signal.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get next signal to be processed from position index zero.
    // CAUTION! The signal memory item's count is checked inside
    // this function. If it is smaller or equal to the given index
    // (here: zero), then the signal value s is NOT changed,
    // i.e. it remains NULL if initialised so before.
    get_item_element((void*) &s, p2, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i, (void*) DATA_ITEM_STATE_CYBOI_NAME);

//?? fwprintf(stdout, L"\nTEST check signal s: %i\n\n", s);

    if (s != *NULL_POINTER_STATE_CYBOI_MODEL) {

        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.

        check_found(s, p0, p1, p2, (void*) &i, p4);

    } else {

        // No signal is available in the signal memory.
        // Query interrupt flags for requests.

        check_empty(p0, p1, p2, p3, p4);
    }

    //
    // CAUTION! Do NOT destroy the signal or its parts here!
    // A signal represents a logic model stored in the knowledge tree.
    // That knowledge tree and its parts get created at
    // system startup or later and destroyed when processing a
    // corresponding CYBOL operation, or at system shutdown.
    //
}

/* SIGNAL_CHECKER_SOURCE */
#endif
