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
 * @version CYBOP 0.23.0 2022-09-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_NUMERAL_DESERIALISER_SOURCE
#define PART_NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/numeral/base_numeral_model.c"
#include "../../../../executor/representer/deserialiser/numeral/decimals_numeral_deserialiser.c"
#include "../../../../executor/representer/deserialiser/numeral/power_numeral_deserialiser.c"
#include "../../../../executor/representer/deserialiser/numeral/value_numeral_deserialiser.c"
#include "../../../../executor/representer/deserialiser/whitespace/whitespace_deserialiser.c"
#include "../../../../executor/selector/numeral/base_numeral_selector.c"
#include "../../../../executor/selector/numeral/sign_numeral_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the first or second part numeral.
 *
 * A vulgar fraction or a complex number consist of TWO parts.
 *
 * @param p0 the destination algebraic sign
 * @param p1 the destination pre point value
 * @param p2 the destination post point value
 * @param p3 the destination number base power
 * @param p4 the source data position (pointer reference)
 * @param p5 the source count remaining
 * @param p6 the detected format
 * @param p7 the detected type
 */
void deserialise_numeral_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral part.");
    fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining p5: %i\n", p5);
    fwprintf(stdout, L"Debug: Deserialise numeral part. source count remaining *p5: %i\n", *((int*) p5));

    // The number base with DECIMAL as default.
    int b = *DECIMAL_BASE_NUMERAL_MODEL;
    // The post point value flag.
    int post = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The number base power flag.
    int p = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Skip any whitespace characters.
    deserialise_whitespace(p4, p5);

    // Deserialise algebraic sign.
    select_numeral_sign(p0, p4, p5);

    // Deserialise number base.
    select_numeral_base((void*) &b, p4, p5);

    fwprintf(stdout, L"Debug: Deserialise numeral part. b: %i\n", b);

    // Deserialise number value.
    deserialise_numeral_value(p1, p4, p5, (void*) &b, (void*) &post, (void*) &p, p6, p7);

    fwprintf(stdout, L"Debug: Deserialise numeral part. p1: %i\n", p1);
    fwprintf(stdout, L"Debug: Deserialise numeral part. *p1: %i\n", *((int*) p1));
    fwprintf(stdout, L"Debug: Deserialise numeral part. post: %i\n", post);

    if (post != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a decimal fraction with post point value.
        //

        // Deserialise post point value.
        deserialise_numeral_decimals(p2, p4, p5, (void*) &b, (void*) &p, p6, p7);
    }

    fwprintf(stdout, L"Debug: Deserialise numeral part. SPECIAL 1 *p1: %i\n", *((int*) p1));

    fwprintf(stdout, L"Debug: Deserialise numeral part. p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral part. *p2: %i\n", *((int*) p2));
    fwprintf(stdout, L"Debug: Deserialise numeral part. p: %i\n", p);

    if (p != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a decimal fraction with number base power.
        //

        // Deserialise number base power.
        deserialise_numeral_power(p3, p4, p5, (void*) &b, p6, p7);
    }

    fwprintf(stdout, L"Debug: Deserialise numeral part. SPECIAL 2 *p1: %i\n", *((int*) p1));
}

/* PART_NUMERAL_DESERIALISER_SOURCE */
#endif
