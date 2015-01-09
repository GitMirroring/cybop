/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef WAIT_CHECKER_SOURCE
#define WAIT_CHECKER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cyboi/state/internal_memory_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../controller/checker/sense_checker.c"
#include "../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/copier/integer_copier.c"
#include "../../logger/logger.c"

/**
 * Waits for an interrupt request.
 *
 * @param p0 the internal memory data
 * @param p1 the sleep time
 */
void check_wait(void* p0, void* p1) {

    // The internal memory index.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The enable flag and interrupt request.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* irq = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? TODO: ------------- All following variables are old and to be DELETED soon.
    // The display enable flag and interrupt request.
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial enable flag and interrupt request.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The socket enable flag and interrupt request.
    void* soe = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* soi = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal enable flag and interrupt request.
    void* te = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // CAUTION! For reasons of efficiency, the following values
    // are retrieved here and NOT inside the loop below.
    //

    // Get display enable flag and interrupt request.
    copy_array_forward((void*) &de, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &di, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get serial enable flag and interrupt request.
    copy_array_forward((void*) &se, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &si, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

/*??
    // Get socket enable flag and interrupt request.
    copy_integer((void*) &i, (void*) HTTP_BASE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) ENABLE_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &soe, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    copy_integer((void*) &i, (void*) HTTP_BASE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_INDEX_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &soi, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
*/

    // Get terminal enable flag and interrupt request.
    copy_array_forward((void*) &te, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ti, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check wait.");

//?? fwprintf(stdout, L"TEST wait *sl: %i\n", *((int*) p1));

    // The break flag.
    // CAUTION! Using this single break flag is easier than
    // querying all possible interrupt request flags below.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The loop variable.
    int j = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Sense interrupt request or sleep.
//??        check_sense(e, irq, p0, (void) &j, (void*) &b);

        //?? TODO: DELETE in the future.
        check_sense_old(de, di, se, si, soe, soi, te, ti, (void*) &b, p0, p1);

        // Increment loop variable.
        j++;
    }

/*??
fwprintf(stdout, L"TEST wait *display_irq: %i\n", *((int*) di));
fwprintf(stdout, L"TEST wait *serial_irq: %i\n", *((int*) si));
fwprintf(stdout, L"TEST wait *socket_irq: %i\n", *((int*) soi));
fwprintf(stdout, L"TEST wait *terminal_irq: %i\n", *((int*) ti));
*/

    // The sleep loop above is left as soon as at least one of the
    // interrupt variables is set to a value other than false (zero).
    // This may happen if some user action is noted in one of the
    // receive threads, e.g. terminal, display, socket.
    // In this case, probably a signal was placed in the signal memory and
    // the corresponding interrupt variable set to "true".
}

/* WAIT_CHECKER_SOURCE */
#endif
