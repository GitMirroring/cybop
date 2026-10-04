/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "logger.h"

//
// Representer interface
//

#include "cybol.h"

/**
 * Deserialises a cybol source.
 *
 * @param p0 the new destination part model OR properties item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the language properties (constraints) data
 * @param p6 the language properties (constraints) count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the stack memory item
 * @param p9 the internal memory data
 * @param p10 the language
 * @param p11 the decimal separator data
 * @param p12 the decimal separator count
 * @param p13 the thousands separator data
 * @param p14 the thousands separator count
 * @param p15 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p16 the root node flag
 * @param p17 the initial fileread flag
 * @param p18 the format
 * @param p19 the channel
 */
void deserialise_cybol_source(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13, void* p14, void* p15, void* p16, void* p17, void* p18, void* p19) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol source.");
    //?? fwprintf(stdout, L"Debug: Deserialise cybol source. channel p19: %i\n", p19);
    //?? fwprintf(stdout, L"Debug: Deserialise cybol source. channel *p19: %i\n", *((int*) p19));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) FILE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise cybol source. file channel r: %i\n", r);

            // CAUTION! The order is: format, language, channel.
            deserialise_cybol_file(p0, p1, p2, p5, p6, p7, p8, p9, p18, p10, p19);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p19, (void*) INLINE_CYBOI_CHANNEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise cybol source. inline channel r: %i\n", r);

            // Fill part model item taken from cybol source part properties.
            deserialise_cybol(p0, *NULL_POINTER_STATE_CYBOI_MODEL, p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol source. The channel is unknown.");
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. p19: %i\n", p19);
        fwprintf(stdout, L"Warning: Could not deserialise cybol source. The channel is unknown. *p19: %i\n", *((int*) p19));
    }
}
