/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE
#define END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../../executor/searcher/selector/xdt/bdt/number_6200_end_compound_field_bdt_xdt_selector.c"
#include "../../../../../logger/logger.c"

/**
 * Checks if the source field is permitted to be a child of parent.
 *
 * If it is not, then the source field demarcates the end
 * of the compound parent field's children.
 *
 * @param p0 the end flag
 * @param p1 the source field name
 * @param p2 the parent field name
 */
void select_xdt_bdt_field_compound_end(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xdt bdt field compound end.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Record 0001
    //

    //
    // Record 0020
    //

    //
    // Record spec
    //

/*??
    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_9900_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_9900(p0, p1);
        }
    }
*/

    //
    // Record iden
    //

    //
    // Record 0010
    //

    //
    // Record adrs
    //

    //
    // Record term
    //

    //
    // Record diag
    //

    //
    // Record grnk
    //

    //
    // Record hapo
    //

    //
    // Record bbst
    //

    //
    // Record text
    //

    //
    // Record 6100
    //

    //
    // Record 6200
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, p2, (void*) NUMBER_6200_INTEGER_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            select_xdt_bdt_field_compound_end_6200(p0, p1);
        }
    }

    //
    // Record 0101
    //

    //
    // Record 0102
    //

    //
    // Record 0103
    //

    //
    // Record 0104
    //

    //
    // Record 0109
    //

    //
    // Record sad1
    //

    //
    // Record sad2
    //

    //
    // Record sad3
    //

    //
    // Record gevk
    //

    //
    // Record hävg
    //

    //
    // Record medi
    //

    //
    // Record kv
    //

    //
    // Record padx
    //

    //
    // Record 0021
    //

    //
    // Record 0002
    //

    //
    // ... else ...
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Do NOT log this case, since it is
        // normal on the root level of each record,
        // where fields do not have a parent field.
        // log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not select xdt bdt field compound end. The parent field name is unknown.");
    }
}

/* END_COMPOUND_FIELD_BDT_XDT_SELECTOR_SOURCE */
#endif
