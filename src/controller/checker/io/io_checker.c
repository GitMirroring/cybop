/*
 * Copyright (C) 1999-2017. Christian Heller.
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
 * @version CYBOP 0.19.0 2017-04-10
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef IO_CHECKER_SOURCE
#define IO_CHECKER_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/comparator/integer/unequal_integer_comparator.c"
#include "../../../executor/lifeguard/sensor/display/display_sensor.c"
#include "../../../executor/lifeguard/sensor/terminal/terminal_sensor.c"
#include "../../../executor/logifier/boolean/or_boolean_logifier.c"
#include "../../../executor/copier/integer_copier.c"
#include "../../../controller/checker/io/all_io_checker.c"
#include "../../../logger/logger.c"

/**
 * Senses interrupt request at the given channels.
 *
 * This is the NEW solution avoiding threads,
 * in order to be more platform-independent.
 *
 * @param p0 the io flag
 * @param p1 the internal memory data
 */
void check_io(void* p0, void* p1) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Check io.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        sense_display((void*) &r, p1);
//??        check_io_all((void*) &r, p1, (void*) DISPLAY_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//??        sense_serial((void*) &r, p1);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        check_io_all((void*) &r, p1, (void*) SOCKET_INTERNAL_MEMORY_STATE_CYBOI_NAME, (void*) NUMBER_65536_INTEGER_STATE_CYBOI_MODEL);
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        sense_terminal((void*) &r, *NULL_POINTER_STATE_CYBOI_MODEL, p1);
    }

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Set interrupt request.
        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* IO_CHECKER_SOURCE */
#endif
