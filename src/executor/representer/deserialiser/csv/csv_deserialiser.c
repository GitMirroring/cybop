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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef CSV_DESERIALISER_SOURCE
#define CSV_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/representer/deserialiser/numeral/number_numeral_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the character separated value (csv) wide character sequence into separate parts.
 *
 * The separation characters may be:
 *
 *
 *
 * @param p0 the destination number item
 * @param p1 the destination number part (pointer reference)
 * @param p2 the source wide character data
 * @param p3 the source wide character count
 * @param p4 the number part name data
 * @param p5 the number part name count
 * @param p6 the destination number item format
 */
void deserialise_numeral(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral.");
    fwprintf(stdout, L"Debug: Deserialise numeral. source count p3: %i\n", p3);
    fwprintf(stdout, L"Debug: Deserialise numeral. source count *p3: %i\n", *((int*) p3));

    //
    // The destination number item.
    //
    // CAUTION! It has to be declared HERE and NOT only in
    // file "number_numeral_deserialiser.c", since many numerals
    // may follow in a sequence (vector, array) recursively calling
    // the function "deserialise_numeral_number", and this
    // number item has to be forwarded to all of them.
    //
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy destination number item.
    copy_pointer((void*) &i, (void*) &p0);
    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p2);
    // Copy source count remaining.
    copy_integer((void*) &c, p3);

    //
    // Deserialise number.
    //
    // CAUTION! The destination number item is handed over as REFERENCE
    // since it may get assigned the model of a new allocated part inside.
    //
    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    //
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    //
    deserialise_numeral_number((void*) &i, p1, (void*) &d, (void*) &c, p4, p5, p6);
}

/* CSV_DESERIALISER_SOURCE */
#endif
