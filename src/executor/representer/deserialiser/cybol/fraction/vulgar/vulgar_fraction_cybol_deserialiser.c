/*
 * Copyright (C) 1999-2013. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE
#define VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../../executor/representer/deserialiser/cybol/integer/integer_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the wide character data into a vulgar fraction.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_fraction_vulgar(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol fraction vulgar.");

    //
    // CAUTION! A fraction number consists of
    // two integer numbers. However, the function
    // "deserialise_cybol_fraction_decimal"
    // is NOT called directly here, since:
    //
    // (1) an uneven number of integer values
    // might be given, which would lead to
    // wrong results;
    //
    // (2) an extension of the destination
    // fraction number always comprises
    // memory space for TWO integer numbers,
    // so that an extension for just one
    // integer number would lead to errors
    // like segmentation faults when trying
    // to access the fraction number, if only
    // allocated for one instead of two integers
    //

    // The temporary fraction.
    void* t = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Allocate temporary fraction item.
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    allocate_item((void*) &t, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);

    // Deserialise source data
    // (two integer numbers representing a fraction).
    deserialise_cybol_integer(t, p1, p2);

    // Append temporary fraction to destination.
    append_item(p0, t, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Deallocate temporary fraction.
    deallocate_item((void*) &t, (void*) FRACTION_NUMBER_STATE_CYBOI_TYPE);
}

/* VULGAR_FRACTION_CYBOL_DESERIALISER_SOURCE */
#endif
