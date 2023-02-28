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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef NUMERAL_DESERIALISER_SOURCE
#define NUMERAL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/integer_copier.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../executor/representer/deserialiser/numeral/number_numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the source wide character numeral sequence into a number item.
 *
 * A description of possible numeral formats can be found
 * in file "number_state_cybol_format.c".
 *
 * This function may be called WITH or WITHOUT existing destination item, e.g.:
 *
 * CYBOL deserialiser:
 * - a destination part got allocated already and EXISTS
 * - its format and hence type were known due to their specification in cybol
 *
 * JSON deserialiser:
 * - the destination part is NULL
 * - its format and type have to be detected within the numeral deserialiser
 * - afterwards, a new number part may get allocated and
 *   its model item assigned to the destination number item
 *
 * CAUTION! The retrieval of language properties constraints such as the
 * decimal separator should NOT happen here since then, they would have
 * to be read for each single number which is not very efficient.
 * Therefore, retrieve the constraints somewhere outside in the calling
 * function and hand them over as ready parametres to here.
 *
 * The consider number base prefix flag has the following meaning:
 * - true: CONSIDER integer prefixes like "0x" for hexadecimal,
 *   as used in c/c++, perl or python
 * - false: IGNORE prefixes as is needed in json and is the DEFAULT so that
 *   floating point numbers with zero as pre-point value get recognised
 *   correctly with decimal number base
 *
 * @param p0 the destination number (for cybol deserialiser; null for json)
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source wide character data
 * @param p3 the source wide character count
 * @param p4 the decimal separator data
 * @param p5 the decimal separator count
 * @param p6 the thousands separator data
 * @param p7 the thousands separator count
 * @param p8 the consider number base prefix flag (true means CONSIDER prefixes; false means IGNORE them)
 * @param p9 the number part name data
 * @param p10 the number part name count
 * @param p11 the destination number item format
 */
void deserialise_numeral(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral.");
    //?? fwprintf(stdout, L"Debug: Deserialise numeral. source count p3: %i\n", p3);
    //?? fwprintf(stdout, L"Debug: Deserialise numeral. source count *p3: %i\n", *((int*) p3));
    //?? fwprintf(stdout, L"Debug: Deserialise numeral. source count p2: %ls\n", (wchar_t*) p2);

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    //
    // Deserialise number.
    //
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    deserialise_numeral_number(p0, p1, (void*) &d, (void*) &c, p4, p5, p6, p7, p8, p9, p10, p11);
}

/* NUMERAL_DESERIALISER_SOURCE */
#endif
