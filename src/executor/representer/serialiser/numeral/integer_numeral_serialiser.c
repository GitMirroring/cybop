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

#ifndef INTEGER_NUMERAL_SERIALISER_SOURCE
#define INTEGER_NUMERAL_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the integer value into a wide character sequence.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 * @param p3 the number base
 * @param p4 the number prefix flag
 * @param p5 the decimal separator
 * @param p6 the decimal places
 * @param p7 the scientific notation flag
 * @param p8 the format
 */
void serialise_numeral_integer(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise numeral integer.");
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. format p8: %i\n", p8);
    //?? fwprintf(stdout, L"Debug: Serialise numeral integer. format *p8: %i\n", *((int*) p8));

    while (TRUE) {

    }
}

/* INTEGER_NUMERAL_SERIALISER_SOURCE */
#endif
