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

#ifndef BEGIN_JOINED_STRING_SELECTOR_SOURCE
#define BEGIN_JOINED_STRING_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Forks deserialisation between a branch WITH and WITHOUT given quotation character.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source wide character data
 * @param p3 the source wide character count
 * @param p3 the fork character sequence
 */
void select_joined_string_begin(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise joined string begin.");
    fwprintf(stdout, L"Debug: Deserialise joined string begin. source wide character count p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise joined string begin. source wide character count *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (px == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A quotation character sequence is NOT given.
        //

        deserialise_joined_string_value(p2, p3, (void*) &vc, (void*) &b);

    } else {

        //
        // A quotation character sequence IS given.
        //

        select_joined_string_begin_quotation(p2, p3, (void*) &vc, (void*) &b);
    }
}

/* BEGIN_JOINED_STRING_SELECTOR_SOURCE */
#endif
