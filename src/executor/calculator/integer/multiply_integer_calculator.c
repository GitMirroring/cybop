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
// Library interface
//

#include "logger.h"

/**
 * Multiplies the product with the factor integer.
 *
 * @param p0 the product, which is the first factor BEFORE the operation
 * @param p1 the factor
 */
void calculate_integer_multiply(void* p0, void* p1) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* f = (int*) p1;

        if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            int* p = (int*) p0;

            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Calculate integer multiply.");

            *p = *p * *f;

        } else {

            // CAUTION! Do NOT call the logger here.
            // It uses functions causing circular references.
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate integer multiply. The product is null.");
        }

    } else {

        // CAUTION! Do NOT call the logger here.
        // It uses functions causing circular references.
        // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not calculate integer multiply. The factor is null.");
    }
}
