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

#ifndef ENTITY_ESCAPE_SERIALISER_SOURCE
#define ENTITY_ESCAPE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../logger/logger.c"

/**
 * Serialises into an entity-escaped character.
 *
 * @param p0 the destination item
 * @param p1 the source data
 * @param p2 the source count
 */
void serialise_escape_entity(void* p0, void* p1, void* p2) {

    // The comparison result.
    int r = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    if (r == *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

        compare_all_array((void*) &r, p3, p4, (void*) SPACE_CHARACTER, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE);

        if (r != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

            t = (void**) &SPACE_URL_ESCAPE_CODE;
            tc = *SPACE_URL_ESCAPE_CODE_COUNT;
            ts = tc;
        }
    }
}

/* ENTITY_ESCAPE_SERIALISER_SOURCE */
#endif
