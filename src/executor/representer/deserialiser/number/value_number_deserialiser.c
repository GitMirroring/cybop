/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 * @author Falk Müller <falk89@web.de>
 */

#ifndef VALUE_NUMBER_DESERIALISER_SOURCE
#define VALUE_NUMBER_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the wide character number into a value.
 *
 * Examples of possible number formats:
 * - integer decimal: -24
 * - integer hexadecimal: -0x18
 * - integer octal: -030
 * - fraction decimal: -1.23e4 -1.23e+4 11. .11e2 11e0 11.0 0.007 0.7e-2 .7E-2 7E-3
 * - fraction vulgar: -1/2
 * - complex cartesian: 1+2 2-7 -5+5 -3-2
 *   CAUTION! The "i" (or "j" in electrical engineering) in the imaginary part is NEGLECTED: 1+2i --> 1+2
 * - complex polar: -2*exp(-45) -2*E(-45) -2exp(-45) -2E(-45)
 *   CAUTION! The "i" (or "j" in electrical engineering) in the exponent is NEGLECTED: -2*exp(i45) --> -2*exp(45)
 *
 * @param p0 the minus sign flag
 * @param p1 the destination format
 * @param p2 the destination type
 * @param p3 the destination integer value one
 * @param p4 the destination integer value two
 * @param p5 the destination double value one
 * @param p6 the destination double value two
 * @param p7 the source data position (pointer reference)
 * @param p8 the source count remaining
 */
void deserialise_number_value(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise number value.");

    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (p7 == *NULL_POINTER_STATE_CYBOI_MODEL) {

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

        compare_integer_less_or_equal((void*) &b, p7, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        // Select algebraic sign.
        select_number_sign(p0, p1, p2, p3, p4, p5, p6, (void*) &b, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* VALUE_NUMBER_DESERIALISER_SOURCE */
#endif
