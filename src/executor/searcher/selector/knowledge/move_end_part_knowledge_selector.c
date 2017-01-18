/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef MOVE_END_PART_KNOWLEDGE_SELECTOR_SOURCE
#define MOVE_END_PART_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/knowledge/separator_knowledge_cyboi_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/copier/integer_copier.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

/**
 * Selects the knowledge part end with the move depending on the given flag.
 *
 * @param p0 the break flag
 * @param p1 the knowledge path data position (pointer reference)
 * @param p2 the knowledge path count remaining
 * @param p3 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 */
void select_knowledge_part_end_move(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge part end move.");

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The source whole part element index is NOT null.
        // That is, this is the FIRST time that this function is called
        // from "deserialise_knowledge_part" via "deserialise_knowledge_part_name".
        // Therefore, the move flag MUST NOT be set here,
        // so that the delimiter ")" may be detected once again.
        //

        select_knowledge_part_end((void*) &b, p1, p2, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    } else {

        //
        // The source whole part element index is NULL.
        // That is, this is the SECOND time that this function is called
        // from "deserialise_knowledge_part" via "deserialise_knowledge_part_name".
        // Therefore, the move flag HAS TO BE set here,
        // so that the delimiter ")" is NOT detected once again and
        // further characters may get processed down the knowledge path hierarchy.
        //

        select_knowledge_part_end((void*) &b, p1, p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* MOVE_END_PART_KNOWLEDGE_SELECTOR_SOURCE */
#endif
