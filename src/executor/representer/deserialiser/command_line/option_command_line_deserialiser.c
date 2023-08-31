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

#include <stdio.h>
#include <wchar.h>

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "cyboi.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Deserialises the command line option.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the test unit
 * @param p4 the terminated log file name item (multibyte character data)
 * @param p5 the argument data (pointer reference)
 * @param p6 the argument count
 */
void deserialise_command_line_option(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! DO NOT use logging functionality here!
    //
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    //
    // log_write((void*) stdout, L"Information: Deserialise command line.\n");
    //

    // The option data, count.
    void* od = *NULL_POINTER_STATE_CYBOI_MODEL;
    int oc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The value data, count.
    void* vd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int vc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Initialise option data.
    copy_pointer((void*) &od, p5);

    if (p6 == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // CAUTION! If the loop count handed over as parametre is NULL,
        // then the break flag will NEVER be set to true, because the loop
        // variable comparison does (correctly) not consider null values.
        // Therefore, in this case, the break flag is set to true already here.
        //
        // Initialising the break flag with true will NOT work either, since it:
        // a) will be left untouched if a comparison operand is null;
        // b) would have to be reset to true in each loop cycle.
        //
        copy_integer((void*) &b, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, p6, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // There are no data left to be processed.
            //
            // A separator was not found, which means that NO VALUE was given.
            //

            break;
        }

        select_command_line_option((void*) &b, p5, p6, (void*) &oc);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // The separator has been found.
            // All data following belong to the value.
            //

            // Initialise value data, count.
            copy_pointer((void*) &vd, p5);
            copy_integer((void*) &vc, p6);

            break;
        }
    }

    //
    // Not all options require a value.
    // But the option has to be processed here anyway,
    // even if no separator was found, i.e. no value was given.
    //
    select_command_line_mode(p0, p1, p2, p3, p4, vd, (void*) &vc, od, (void*) &oc);
}
