/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.16.0 2014-03-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_CALCULATOR_SOURCE
#define PART_CALCULATOR_SOURCE

#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../logger/logger.c"

/**
 * Calculates left- with right part.
 *
 * Calculates only the parts' models.
 * Does NOT consider both parts' name, type, properties.
 *
 * This is DEEP CALCULATION, i.e. all child nodes will be calculated as well.
 *
 * @param p0 the result part, which contains the operands BEFORE the operation
 * @param p1 the operand part
 * @param p2 the operation type
 */
void calculate_part(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate part.");

    //
    // Recursively call a calculation function, which in turn
    // may call this calculation function and so forth.
    // This is necessary when processing knowledge tree hierarchies.
    //

//??    calculate_all_part_all(p0, p1, p2);
}

/* PART_CALCULATOR_SOURCE */
#endif
