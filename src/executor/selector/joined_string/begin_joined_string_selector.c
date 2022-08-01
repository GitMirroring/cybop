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

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/representer/deserialiser/value_joined_string_deserialiser.c"
#include "../../../executor/selector/quotation_begin_joined_string_selector.c"
#include "../../../logger/logger.c"

/**
 * Forks deserialisation between a branch WITH and WITHOUT given quotation character.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 * @param p3 the delimiter data, e.g. a comma OR semicolon OR some character sequence
 * @param p4 the delimiter count
 * @param p5 the escape data, e.g. a DOUBLE quotation mark
 * @param p6 the escape count
 * @param p7 the quotation end PLUS delimiter data, e.g. a quotation mark + comma OR apostrophe + semicolon
 * @param p8 the quotation end PLUS delimiter count
 * @param p9 the quotation end data, e.g. a quotation mark
 * @param p10 the quotation end count
 * @param p11 the quotation begin data, e.g. a quotation mark
 * @param p12 the quotation begin count
 * @param p13 the part name data
 * @param p14 the part name count
 * @param p15 the break flag
 */
void select_joined_string_begin(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select joined string begin.");
    fwprintf(stdout, L"Debug: Select joined string begin. source count remaining p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Select joined string begin. source count remaining *p1: %i\n", *((int*) p1));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (px == *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A quotation begin character sequence is NOT given.
        //

        deserialise_joined_string_value(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p13, p14);

    } else {

        //
        // A quotation begin character sequence IS given.
        //

        select_joined_string_begin_quotation(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15);
    }
}

/* BEGIN_JOINED_STRING_SELECTOR_SOURCE */
#endif
