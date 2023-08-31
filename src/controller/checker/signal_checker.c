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
 * @version CYBOP 0.27.0 2023-08-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "controller.h"
#include "knowledge.h"
#include "logger.h"

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
 * The current solution implemented here is number 1.
 *
 * @param p0 the internal memory data
 * @param p1 the knowledge memory part (pointer reference)
 * @param p2 the stack memory item
 * @param p3 the signal memory item
 * @param p4 the internal memory data (pointer reference)
 * @param p5 the interrupt request pipe
 * @param p6 the shutdown flag
 */
void check_signal(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check signal.");
    //?? fwprintf(stdout, L"Debug: Check signal. shutdown flag p6: %i\n", p6);
    //?? fwprintf(stdout, L"Debug: Check signal. shutdown flag *p6: %i\n", *((int*) p6));

    // The signal item.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal memory item data, count.
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal item data.
    void* sd = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate neutral message item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &s, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) POINTER_STATE_CYBOI_TYPE);

    // Get signal memory item data, count.
    copy_array_forward((void*) &smd, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, p3, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Receive signal.
    //
    // It suffices to hand over: destination signal, signal memory item data and count, channel.
    //
    read_signal(s, smd, smc, *NULL_POINTER_STATE_CYBOI_MODEL);

    //
    // Get signal item data.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    // CAUTION! Do NOT use the "copy_array_forward" function here,
    // since it returns an array, but not the contained element.
    //
    get_item((void*) &sd, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);

    if (sd != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A signal was found and has to be handled.
        // Handling a signal has higher priority than checking for new interrupt requests.
        //

        check_found(sd, p0, p1, p2, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, p4, p6);

    } else {

        //
        // No signal is available in the signal memory.
        // Query interrupt flags for requests.
        //

        check_empty(p0, p3, p5);
    }

    //
    // Deallocate signal item.
    //
    // CAUTION! Do NOT destroy the contained signal or its parts here!
    // A signal represents a logic model stored in the knowledge tree.
    // That knowledge tree and its parts get created at
    // system startup or later and destroyed when processing a
    // corresponding CYBOL operation, or at system shutdown.
    //
    // The signal item used here was just a container to receive
    // and hold a pointer to the actual signal and CAN get deallocated.
    //
    deallocate_item((void*) &s, (void*) POINTER_STATE_CYBOI_TYPE);
}
