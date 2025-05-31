/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Uses the given index to calculate an offset ONLY for the result.
 *
 * The result is treated as array (vector).
 *
 * @param p0 the result (number 1 if true; unchanged otherwise)
 * @param p1 the left operand
 * @param p2 the right operand
 * @param p3 the operation type
 * @param p4 the operand type
 * @param p5 the index
 */
void compare_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Compare vector.");

    // The result.
    // CAUTION! It HAS TO BE initialised with p0,
    // since an offset is added below.
    void* r = p0;

    // Add offset to result.
    add_offset((void*) &r, p4, p5);

    // Add offset to left- and right operand.
    compare_offset(r, p1, p2, p3, p4, p5);
}
