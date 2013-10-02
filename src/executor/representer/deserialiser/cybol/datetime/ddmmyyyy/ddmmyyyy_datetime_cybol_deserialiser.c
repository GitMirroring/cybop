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

#ifndef DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE
#define DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE

#include "../../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../../executor/representer/deserialiser/cybol/datetime/ddmmyyyy/elements_ddmmyyyy_datetime_cybol_deserialiser.c"
#include "../../../../../../logger/logger.c"

/**
 * Deserialises the ddmmyyyy wide character data into a datetime model.
 *
 * @param p0 the destination model item
 * @param p1 the source data
 * @param p2 the source count
 */
void deserialise_cybol_datetime_ddmmyyyy(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol datetime ddmmyyyy.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    compare_integer_equal((void*) &r, p2, (void*) NUMBER_8_INTEGER_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        deserialise_cybol_datetime_ddmmyyyy_elements(p0, p1);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise cybol datetime ddmmyyyy. The source count is unequal 8.");
    }
}

/* DDMMYYYY_DATETIME_CYBOL_DESERIALISER_SOURCE */
#endif
