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

#ifndef NUMERAL_VECTOR_DESERIALISER_SOURCE
#define NUMERAL_VECTOR_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Splits the source numeral vector into parts which are stored as child nodes of the destination part.
 *
 * CAUTION! This function is applicable to cybol but NOT to json, since:
 * - in cybol, EACH number gets interpreted as vector (array)
 * - in json, arrays and numbers are treated DIFFERENTLY
 *
 * Since in json, each number stands for itself, it may call the function
 * "deserialise_numeral" DIRECTLY, without having to care about vectors.
 * This also solves the problem that in json, the number type is unknown and
 * has to get detected from the value, which would complicate vector handling.
 *
 * @param p0 the destination number item (for cybol deserialiser; null for json)
 * @param p1 the source wide character vector data
 * @param p2 the source wide character vector count
 * @param p3 the destination number item format
 */
void deserialise_numeral_vector(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral vector.");
    fwprintf(stdout, L"Debug: Deserialise numeral vector. source count p2: %i\n", p2);
    fwprintf(stdout, L"Debug: Deserialise numeral vector. source count *p2: %i\n", *((int*) p2));

    // Allocate temporary item storing strings representing a number each.

    // Deserialise numeral vector storing the single numbers as child nodes of the temporary item.

    // Iterate through the temporary item.
    // Each child node represents a number.

    while (...) {

        // Deserialise string into number.

        // Append number to destination number item.
    }

    // Deallocate temporary item storing strings representing a number each.
}

/* NUMERAL_VECTOR_DESERIALISER_SOURCE */
#endif
