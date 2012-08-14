/*
 * Copyright (C) 1999-2012. Christian Heller.
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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.11.0 2012-01-01
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PERCENT_ENCODING_SERIALISER_SOURCE
#define PERCENT_ENCODING_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/percent_encoding/data_percent_encoding_serialiser.c"
#include "../../../../logger/logger.c"

/**
 * Serialises into percent-encoded character data.
 *
 * @param p0 the destination character item
 * @param p1 the source wide character data
 * @param p2 the source wide character count
 */
void serialise_percent_encoding(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise percent encoding.");

    // The source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Copy source data position.
    copy_pointer((void*) &d, (void*) &p1);
    // Copy source count remaining.
    copy_integer((void*) &c, p2);

    // CAUTION! A copy of source count remaining is forwarded here,
    // so that the original source value does not get changed.
    // CAUTION! The source data position does NOT have to be copied,
    // since the parametre that was handed over is already a copy.
    // A local copy was made anyway, not to risk parametre falsification.
    // Its reference is forwarded, as it gets incremented by sub routines inside.
    serialise_percent_encoding_data(p0, (void*) &d, (void*) &c);
}

/* PERCENT_ENCODING_SERIALISER_SOURCE */
#endif
