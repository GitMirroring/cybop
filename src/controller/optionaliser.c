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
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef OPTIONALISER_SOURCE
#define OPTIONALISER_SOURCE

#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../controller/optionaliser/argument_optionaliser.c"
#include "../executor/comparator/basic/integer/greater_or_equal_integer_comparator.c"
#include "../executor/modifier/copier/integer_copier.c"

/**
 * Optionalises the given command line argument options.
 *
 * The GNU Standards for Command Line Interfaces to be found at:
 * http://www.gnu.org/prep/standards/html_node/Command_002dLine-Interfaces.html
 * write:
 * "All programs should support two standard options: '--version' and '--help'."
 * Therefore, this function checks for these two command line argument options.
 *
 * A further option that was added is '--test'. It is just to ease cyboi
 * development because that way, programmers can easily call test functions.
 *
 * The standard option used to run cybol applications is '--knowledge'.
 * Behind it, the cybol file name needs to be given as argument.
 * The cyboi interpreter then starts up the system.
 *
 * Optionally, a '--loglevel' and 'logfile' may be given, each followed by a value.
 * In the case of the loglevel, the value may be one of:
 * - off
 * - error
 * - warning
 * - information
 * - debug
 * where 'debug' is the most verbose one.
 * The logfile expects just an arbitrary file name.
 *
 * If none of these options can be found, cyboi displays the help message.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the log file stream (pointer reference)
 * @param p4 the arguments (pointer reference)
 * @param p5 the arguments count
 */
void optionalise(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    // log_write((void*) stdout, L"Information: Optionalise command line arguments.\n");

    // The loop variable.
    //
    // CAUTION! Do NOT initialise it with 0, as the first command line
    // argument is the command itself, and not an option!
    int j = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

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

        compare_integer_greater_or_equal((void*) &b, (void*) &j, p5);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        optionalise_argument(p0, p1, p2, p3, p4, p5, (void*) &j);

        // Increment loop variable.
        j++;
    }
}

/* OPTIONALISER_SOURCE */
#endif
