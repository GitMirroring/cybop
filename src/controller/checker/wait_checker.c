/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
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
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The cyboi service enable flag and interrupt request.
    void* ce = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ci = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The display enable flag and interrupt request.
    void* de = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* di = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The serial port enable flag and interrupt request.
    void* se = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* si = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The terminal enable flag and interrupt request.
    void* te = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ti = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The www service enable flag and interrupt request.
    void* we = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* wi = *NULL_POINTER_STATE_CYBOI_MODEL;

    // CAUTION! For reasons of efficiency, the following values
    // are retrieved here and NOT inside the loop below.

    // Get cyboi service enable flag and interrupt request.
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) ENABLE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ce, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    copy_integer((void*) &i, (void*) CYBOI_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ci, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    // Get display enable flag and interrupt request.
    copy_array_forward((void*) &de, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &di, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get serial port enable flag and interrupt request.
    copy_array_forward((void*) &se, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &si, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_SERIAL_PORT_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get terminal enable flag and interrupt request.
    copy_array_forward((void*) &te, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) ENABLE_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ti, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) INTERRUPT_REQUEST_TERMINAL_INTERNAL_MEMORY_STATE_CYBOI_NAME);

    // Get www service enable flag and interrupt request.
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) ENABLE_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &we, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);
    copy_integer((void*) &i, (void*) WWW_BASE_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    calculate_integer_add((void*) &i, (void*) INTERRUPT_REQUEST_SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME);
    copy_array_forward((void*) &wi, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) &i);

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check wait.");

//?? fwprintf(stdout, L"TEST wait *sl: %i\n", *((int*) p1));

    // The break flag.
    // CAUTION! Using this single break flag is easier than
    // querying all possible interrupt request flags below.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Sense interrupt request or sleep.
        check_sense(ce, ci, de, di, se, si, te, ti, we, wi, (void*) &b, p0, p1);
    }

/*??
fwprintf(stdout, L"TEST wait *cyboi_service_irq: %i\n", *((int*) ci));
fwprintf(stdout, L"TEST wait *display_irq: %i\n", *((int*) di));
fwprintf(stdout, L"TEST wait *serial_port_irq: %i\n", *((int*) si));
fwprintf(stdout, L"TEST wait *terminal_irq: %i\n", *((int*) ti));
fwprintf(stdout, L"TEST wait *www_service_irq: %i\n", *((int*) wi));
*/

    // The sleep loop above is left as soon as at least one of the
    // interrupt variables is set to a value other than false (zero).
    // This may happen if some user action is noted in one of the
    // receive threads, e.g. terminal, display, tcp socket.
    // In this case, probably a signal was placed in the signal memory and
    // the corresponding interrupt variable set to true (one).
}

/* WAIT_CHECKER_SOURCE */
#endif
