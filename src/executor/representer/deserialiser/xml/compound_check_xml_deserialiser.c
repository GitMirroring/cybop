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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef COMPOUND_CHECK_XML_DESERIALISER_SOURCE
#define COMPOUND_CHECK_XML_DESERIALISER_SOURCE

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "xml.h"

/**
 * Checks if this is going to be a compound node.
 *
 * This function peeks ahead into the parsed data in order to
 * find out if there are any child nodes embedded which
 * would mean that this is going to be a COMPOUND tree node.
 *
 * @param p0 the compound flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void deserialise_xml_check_compound(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xml check compound.");
    //?? fwprintf(stdout, L"Debug: Deserialise xml check compound. p0: %i\n", p0);

    // The source data position COPY.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining COPY.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The break flag.
    int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    //
    // Checking the loop count for null is NOT necessary here,
    // since it is NOT a pointer but a local integer variable.
    //

    while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_less_or_equal((void*) &b, (void*) &c, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

        if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            break;
        }

        select_xml_check_compound(p0, (void*) &d, (void*) &c, (void*) &b);
    }
}

/* COMPOUND_CHECK_XML_DESERIALISER_SOURCE */
#endif
