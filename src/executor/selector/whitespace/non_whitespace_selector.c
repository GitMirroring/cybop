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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef NON_WHITESPACE_SELECTOR_SOURCE
#define NON_WHITESPACE_SELECTOR_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../executor/copier/integer_copier.c"
#include "../../../executor/logifier/boolean/not_boolean_logifier.c"
#include "../../../executor/selector/whitespace/whitespace_selector.c"
#include "../../../logger/logger.c"

/**
 * Detects a non-whitespace character.
 *
 * Returns TRUE if a NON-whitespace character is found.
 *
 * @param p0 the destination non-whitespace flag
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_whitespace_non(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select whitespace non.");
    //?? fwprintf(stdout, L"Debug: Select whitespace non. count remaining p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Select whitespace non. count remaining *p2: %i\n", *((int*) p2));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check for whitespace character.
    select_whitespace((void*) &r, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Invert comparison result.
    logify_boolean_not((void*) &r);

    // Assign destination non-whitespace flag.
    copy_integer(p0, (void*) &r);
}

/* NON_WHITESPACE_SELECTOR_SOURCE */
#endif
