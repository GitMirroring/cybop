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

#ifndef REFERENCE_SMTP_RESPONSE_DESERIALISER_SOURCE
#define REFERENCE_SMTP_RESPONSE_DESERIALISER_SOURCE

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

/**
 * Create reference from smtp response line.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source response line data
 * @param p3 the source response line count
 */
void deserialise_smtp_response_reference(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise smtp response reference.");
    fwprintf(stdout, L"Debug: Deserialise smtp response reference. p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise smtp response reference. *p3: %i\n", *((int*) p3));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    // Deserialise smtp response line.
    deserialise_smtp_response_line(p0, p1, (void*) &d, (void*) &c);
}

/* REFERENCE_SMTP_RESPONSE_DESERIALISER_SOURCE */
#endif
