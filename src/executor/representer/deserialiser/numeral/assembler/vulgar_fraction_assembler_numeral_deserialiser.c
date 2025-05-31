/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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
#include "knowledge.h"
#include "logger.h"

/**
 * Assembles the vulgar fraction from the given values.
 *
 * @param p0 the destination vulgar fraction
 * @param p1 the numerator algebraic sign
 * @param p2 the numerator value
 * @param p3 the denominator algebraic sign
 * @param p4 the denominator value
 */
void deserialise_numeral_assembler_fraction_vulgar(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral assembler fraction vulgar.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction vulgar. numerator value p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction vulgar. numerator value *p2: %i\n", *((int*) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction vulgar. denominator value p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral assembler fraction vulgar. denominator value *p4: %i\n", *((int*) p4));

    // The numerator.
    int n = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The denominator.
    int d = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Deserialise numerator.
    deserialise_numeral_assembler_integer((void*) &n, p1, p2);
    // Deserialise denominator.
    deserialise_numeral_assembler_integer((void*) &d, p3, p4);

    // Assign numerator.
    set_fraction_element(p0, (void*) &n, (void*) NUMERATOR_FRACTION_STATE_CYBOI_NAME);
    // Assign denominator.
    set_fraction_element(p0, (void*) &d, (void*) DENOMINATOR_FRACTION_STATE_CYBOI_NAME);
}
