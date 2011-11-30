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

#ifndef ROOT_PART_CYBOL_DESERIALISER_SOURCE
#define ROOT_PART_CYBOL_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/representer/deserialiser/cybol/properties_cybol_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Deserialises the cybol root part.
 *
 * @param p0 the destination item
 * @param p1 the source part model data
 * @param p2 the source part model count
 * @param p3 the root part flag
 */
void deserialise_cybol_part_root(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise cybol part root.");

    // Reset root part flag, so that
    // child parts are processed normally.
    copy_integer(p3, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    // Fill part properties taken from cybol source part model.
    deserialise_cybol_properties(p0, p1, p2, p3);
}

/* ROOT_PART_CYBOL_DESERIALISER_SOURCE */
#endif
