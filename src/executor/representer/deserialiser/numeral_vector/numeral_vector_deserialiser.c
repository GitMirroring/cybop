/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef NUMERAL_VECTOR_DESERIALISER_SOURCE
#define NUMERAL_VECTOR_DESERIALISER_SOURCE

//
// Library interface
//

#include "constant.h"

//
// Executable interface
//

#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/numeral_vector/item_numeral_vector_deserialiser.c"
#include "logger.h"

/**
 * Deserialises the source numeral vector into elements of the destination number item.
 *
 * CAUTION! This function is applicable to CYBOL but NOT to json, since:
 * - in cybol, EACH number gets interpreted as vector (array)
 * - in json, arrays and numbers are treated DIFFERENTLY
 *
 * Since in json, each number stands for itself, it may call the function
 * "deserialise_numeral" DIRECTLY, without having to care about vectors.
 * This also solves the problem that in json, the number type is unknown and
 * has to get detected from the value, which would complicate vector handling.
 *
 * @param p0 the destination number item
 * @param p1 the source wide character vector data
 * @param p2 the source wide character vector count
 * @param p3 the decimal separator data
 * @param p4 the decimal separator count
 * @param p5 the thousands separator data
 * @param p6 the thousands separator count
 * @param p7 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p8 the destination number item format
 */
void deserialise_numeral_vector(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral vector.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector. source count p2: %i\n", p2);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral vector. source count *p2: %i\n", *((int*) p2));

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    //
    // Allocate temporary item.
    //
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    deserialise_numeral_vector_item(p0, (void*) &d, (void*) &c, p3, p4, p5, p6, p7, p8);
}

/* NUMERAL_VECTOR_DESERIALISER_SOURCE */
#endif
