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

#ifndef MODE_JSON_SELECTOR_SOURCE
#define MODE_JSON_SELECTOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/json/mode_json_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/representer/deserialiser/json/element_json_deserialiser.c"
#include "../../../executor/representer/deserialiser/json/value_json_deserialiser.c"
#include "../../../executor/selector/json/begin_value_json_selector.c"
#include "../../../logger/logger.c"

/**
 * Selects the deserialiser (parser) mode.
 *
 * @param p0 the destination model item
 * @param p1 the destination properties item
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 * @param p4 the member name data
 * @param p5 the member name count
 * @param p6 the break flag
 * @param p7 the mode
 */
void select_json_mode(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select json mode.");
    fwprintf(stdout, L"Debug: Select json mode. count remaining p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Select json mode. count remaining *p3: %i\n", *((int*) p3));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) ARRAY_MODE_JSON_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is an array element.
            //

            deserialise_json_element(p0, p1, p2, p3, p4, p5);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) OBJECT_MODE_JSON_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is an object member PAIR containing name and value.
            //

            select_json_value_begin(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p7, (void*) VALUE_MODE_JSON_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a SIMPLE value.
            //
            // In the case of a string, it may represent either of:
            // - simple array element
            // - object member name
            // - object member value
            //

            select_json_value_begin(p0, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select json mode. The mode is unknown.");
        fwprintf(stdout, L"Warning: Could not select json mode. The mode is unknown. count remaining p3: %i\n", p3);
        fwprintf(stdout, L"Warning: Could not select json mode. The mode is unknown. count remaining *p3: %i\n", *((int*) p3));
        fwprintf(stdout, L"Warning: Could not select json mode. The mode is unknown. mode p6: %i\n", p6);
        fwprintf(stdout, L"Warning: Could not select json mode. The mode is unknown. mode *p6: %i\n", *((int*) p6));
    }
}

/* MODE_JSON_SELECTOR_SOURCE */
#endif
