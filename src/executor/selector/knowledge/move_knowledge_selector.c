/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "logger.h"

/**
 * Selects the knowledge end with the move depending on the given flag.
 *
 * @param p0 the knowledge path data position (pointer reference)
 * @param p1 the knowledge path count remaining
 * @param p2 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts on heap
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties on heap
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for variables on stack
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 * @param p3 the knowledge path end flag
 * @param p4 the name count
 * @param p5 the break flag
 */
void select_knowledge_move(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge move.");

    if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // The source whole part element index is NOT null.
        //
        // That is, a "." or ":" or "#" HAS been detected before.
        //
        // This is the FIRST time that this function is called
        // from file "part_knowledge_deserialiser.c",
        // in order to deserialise a whole (parent) node.
        //
        // Therefore, the move flag MUST NOT be set here, so that
        // the delimiters ")" and "]" may be detected once again.
        //

        select_knowledge_end(p0, p1, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);

    } else {

        //
        // The source whole part element index is NULL.
        //
        // This is the SECOND time that this function is called
        // from file "part_knowledge_deserialiser.c",
        // in order to deserialise an element (child) node.
        //
        // Therefore, the move flag HAS TO BE set here, so that
        // the delimiters ")" and "]" are NOT detected once again and
        // further characters may get processed down the knowledge path hierarchy.
        //

        select_knowledge_end(p0, p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p3, p4, p5);
    }
}
