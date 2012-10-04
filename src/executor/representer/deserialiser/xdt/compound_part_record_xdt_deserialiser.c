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

#ifndef COMPOUND_PART_RECORD_XDT_DESERIALISER_SOURCE
#define COMPOUND_PART_RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/calculator/basic/integer/add_integer_calculator.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises xdt record compound part.
 *
 * @param p0 the parent model item
 * @param p1 the current tree level
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void deserialise_xdt_record_part_compound(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record part compound.");

    deserialise_xdt_record_part((void*) &p);

    // Increment current tree level.
    // An alternative could be to assign to it the field hierarchy.
    calculate_integer_add(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Deserialise child fields of this field recursively.
    // Hand over new part as parent parametre.
    deserialise_xdt_record(p, p1, p2, p3);

    // Decrement current tree level.
    calculate_integer_subtract(p1, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
}

/* COMPOUND_PART_RECORD_XDT_DESERIALISER_SOURCE */
#endif
