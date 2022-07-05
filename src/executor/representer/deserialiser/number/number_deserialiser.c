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
 */

#ifndef NUMBER_DESERIALISER_SOURCE
#define NUMBER_DESERIALISER_SOURCE

#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/number/number_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the wide character number into a double or integer item.
 *
 * Examples of possible number formats:
 * - integer decimal: -24
 * - integer hexadecimal: -0x18
 * - integer octal: -030
 * - fraction decimal: 7E-3 -1.23e12 -1.23e+4 11. 11.0 .11e2 11e0 0.007 0.7e-2 .7E-2
 * - fraction vulgar: -1/2
 * - complex cartesian: 1+2 2-7 -5+5 -3-2 -1.23+5.0 -1.23e12+.11e2
 *   CAUTION! The "i" (or "j" in electrical engineering) in the imaginary part is NEGLECTED: 1+2i --> 1+2
 *   CAUTION! Using fractions for real and imaginary part of a complex number is NOT supported, e.g. -1/2+3/4
 * - complex polar: -2*exp(-45) -2*E(-45) -2exp(-45) -2E(-45) -1.23*exp(-45) -1.23E4E(-45)
 *   CAUTION! The "i" (or "j" in electrical engineering) in the exponent is NEGLECTED: -2*exp(i45) --> -2*exp(45)
 *
 * @param p0 the minus sign flag
 * @param p1 the destination format
 * @param p2 the destination type
 * @param p3 the destination integer value one
 * @param p4 the destination integer value two
 * @param p5 the destination double value one
 * @param p6 the destination double value two
 * @param p7 the source data
 * @param p8 the source count
 */
void deserialise_number(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise number.");
    fwprintf(stdout, L"Debug: Deserialise number. source count p8: %i\n", p8);
    fwprintf(stdout, L"Debug: Deserialise number. source count *p8: %i\n", *((int*) p8));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p6);
    // Copy source count remaining.
    copy_integer((void*) &c, p7);

    //
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    deserialise_number_whitespace(p0, p1, p2, p3, p4, p5, (void*) &d, (void*) &c);
}

/* NUMBER_DESERIALISER_SOURCE */
#endif
