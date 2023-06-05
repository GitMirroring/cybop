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

//
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Tests if this is a root node.
 *
 * @param p0 the root flag
 * @param p1 the source name part
 * @param p2 the source channel part
 * @param p3 the source format part
 * @param p4 the source model part
 */
void deserialise_cybol_test(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol test.");
    // fwprintf(stdout, L"Debug: Deserialise cybol test. p0: %i\n", p0);
    // fwprintf(stdout, L"Debug: Deserialise cybol test. *p0: %i\n", *((int*) p0));

    //
    // CAUTION! This test is IMPORTANT!
    // If a source format (type) attribute is NOT given,
    // then this is (hopefully) the cybol ROOT node.
    //
    // CAUTION! It is true, a root flag was set initially when starting
    // to deserialise the cybol source, and forwarded as parametre.
    // However, that flag was only used to call the correct
    // function, but source data were just forwarded to it.
    // Another test (guess) for root node IS necessary here.
    // If NO format (type) is given, then this is a ROOT node.
    //
    // CAUTION! Do ONLY compare those variables,
    // for which NO DEFAULT VALUE has been set before.
    //
    // CAUTION! Do NOT mix up the xml TAG name with the "name" ATTRIBUTE of a node.
    // When talking about a part name, then the "name" ATTRIBUTE is meant here.
    //
    if ((p1 == *NULL_POINTER_STATE_CYBOI_MODEL) && (p2 == *NULL_POINTER_STATE_CYBOI_MODEL)
        && (p3 == *NULL_POINTER_STATE_CYBOI_MODEL) && (p4 == *NULL_POINTER_STATE_CYBOI_MODEL)) {

        copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}
