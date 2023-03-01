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

#ifndef ACCEPT_IO_CHECKER_SOURCE
#define ACCEPT_IO_CHECKER_SOURCE

#include <time.h> // time_t, time()

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/negative_integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../executor/acceptor/acceptor.c"
#include "../../../executor/comparator/integer/greater_integer_comparator.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Checks input output for new client requests.
 *
 * @param p0 the client list item
 * @param p1 the accepttime list item
 * @param p2 the input/output entry
 * @param p3 the channel
 */
void check_io_accept(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io accept.");

    // The sender client.
    int c = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;
    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Accept new client requests.
    accept_client((void*) &c, p2, p0, p3);

    compare_integer_greater((void*) &r, (void*) &c, (void*) NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // A client request has been detected on the server.
        //

        log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io accept. A client request was detected.");
        //?? fwprintf(stdout, L"Information: Check io accept. A client request was detected. c: %i\n", c);

        //
        // Get current calendar time.
        //
        // The type "time_t" is used to represent a simple calendar time.
        // In iso c, it can be either an integer or a floating-point type.
        //
        // On posix-conformant systems, "time_t" is an integer type
        // and its values represent the number of seconds elapsed
        // since the epoch, which is 1970-01-01T00:00:00 UTC.
        //
        time_t t = time(*NULL_POINTER_STATE_CYBOI_MODEL);

        // The current calendar time as integer value.
        int ti = (int) t;

        // Add client to client list item.
        modify_item(p0, (void*) &c, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
        // Add current calendar time to accepttime list item.
        modify_item(p1, (void*) &ti, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        //
        // There is NO client request.
        //

        //
        // CAUTION! Do NOT log messages here, since this function is called in an endless loop.
        // Otherwise, it would produce huge log files filled up with useless entries.
        //
        // This is normal behaviour.
        // Since cyboi is non-blocking using busy waiting,
        // most of the time, no request is found.
        //
        // This else branch will not harm performance,
        // since the compiler does remove empty blocks.
        //
    }
}

/* ACCEPT_IO_CHECKER_SOURCE */
#endif
