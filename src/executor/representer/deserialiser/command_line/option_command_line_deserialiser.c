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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.13.0 2013-03-29
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTION_COMMAND_LINE_DESERIALISER_SOURCE
#define OPTION_COMMAND_LINE_DESERIALISER_SOURCE

#ifdef WIN32
#include <windows.h>
/* WIN32_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/searcher/selector/command_line/mode_command_line_selector.c"
#include "../../../../executor/searcher/selector/command_line/option_command_line_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the command line option.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the terminated log file name item (multibyte character data)
 * @param p4 the argument data (pointer reference)
 * @param p5 the argument count
 */
void deserialise_command_line_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Information: Deserialise command line.\n");

    // The option data, count.
    void* od = *NULL_POINTER_STATE_CYBOI_MODEL;
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The value data, count.
    void* vd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise option data.
    copy_pointer((void*) &od, p4);

    if (p5 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_smaller_or_equal((void*) &b, p5, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // There are no data left to be processed.
            // A separator was not found, which means
            // that no value was given.

            break;
        }

        select_command_line_option((void*) &b, p4, p5);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The separator has been found.
            // All data following belong to the value.

            // Initialise value data, count.
            copy_pointer((void*) &vd, p4);
            copy_integer((void*) &vc, p5);

            break;

        } else {

            // Increment option count.
            oc++;
        }
    }

    // Not all options require a value.
    // But the option has to be processed here anyway,
    // even if no separator was found, i.e. no value was given.
    select_command_line_mode(p0, p1, p2, p3, vd, (void*) &vc, od, (void*) &oc);
}

/* OPTION_COMMAND_LINE_DESERIALISER_SOURCE */
#endif
