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
 * Christian Heller <christian.heller@tuxtax.de>
 *
 * @version CYBOP 0.14.0 2013-05-31
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef GET_SOURCE
#define GET_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/name/cybol/logic/access/get_access_logic_cybol_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/accessor/getter/getter.c"
#include "../../executor/accessor/knowledge_getter/knowledge_part_getter.c"
#include "../../logger/logger.c"

/**
 * Gets an element (attribute) of the given part.
 *
 * Expected parametres:
 * - element (required): the part's element (name, channel, encoding, language, format, type)
 * - part (required): the knowledge path to the part
 *
 * Constraints:
 *
 * @param p0 the parametres data
 * @param p1 the parametres count
 * @param p2 the knowledge memory part
 * @param p3 the operation type
 */
void apply_get(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Apply get.");

    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The part part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get element part.
    get_part_knowledge((void*) &e, p0, (void*) ELEMENT_GET_ACCESS_LOGIC_CYBOL_NAME, (void*) ELEMENT_GET_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2);
    // Get part part.
    get_part_knowledge((void*) &p, p0, (void*) PART_GET_ACCESS_LOGIC_CYBOL_NAME, (void*) PART_GET_ACCESS_LOGIC_CYBOL_NAME_COUNT, p1, p2);

    // Get part element.
    get(e, p, p3);
}

/* GET_SOURCE */
#endif
