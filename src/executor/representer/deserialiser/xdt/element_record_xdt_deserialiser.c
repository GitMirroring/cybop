/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef ELEMENT_RECORD_XDT_DESERIALISER_SOURCE
#define ELEMENT_RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../executor/representer/deserialiser/xdt/field_xdt_deserialiser.c"
#include "../../../../executor/representer/deserialiser/xdt/hierarchy_field_xdt_deserialiser.c"
#include "../../../../executor/searcher/selector/xdt/hierarchy_field_xdt_selector.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises an xdt record element.
 *
 * @param p0 the destination parent properties item
 * @param p1 the destination part properties item
 * @param p2 the current tree level
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 * @param p5 the loop break flag
 * @param p6 the bdt standard main version
 */
void deserialise_xdt_record_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record element.");

    // The field content data, count.
    void* cd = *NULL_POINTER_STATE_CYBOI_MODEL;
    int cc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field identification.
    int i = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field dependency hierarchy.
    int h = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The field size.
    int s = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    deserialise_xdt_field((void*) &cd, (void*) &cc, (void*) &i, (void*) &h, (void*) &s, p3, p4, p6);

    if (h == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        // Probably, the bdt main version is < 3.
        // In this case, the hierarchy dependency byte does not exist.
        // Therefore, another function has to be called.

        // Figure out field hierarchy.
        deserialise_xdt_field_hierarchy((void*) &h, (void*) &i);
    }

    // Process field depending on hierarchy level.
    select_xdt_field_hierarchy(p0, p1, p2, p3, p4, cd, (void*) &cc, (void*) &i, (void*) &h, (void*) &s, p5, p6);
}

/* ELEMENT_RECORD_XDT_DESERIALISER_SOURCE */
#endif
