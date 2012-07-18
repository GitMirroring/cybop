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

#ifndef BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE
#define BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cyboi/knowledge/separator_knowledge_cyboi_name.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

//
// CAUTION! This comment is valid for all "select" functions below.
//
// The comparison result HAS TO BE ZERO (r == 0),
// if a detection is to be taking place!
//
// Many "detect" functions are called in a sequence, below.
// If the result of one detection function was positive (r == 1), then that
// function increments the current position and decrements the remaining count.
// In this case, further detection functions following afterwards might detect
// further characters and CHANGE the current position and remaining count,
// and so forth, which would have the effect of "JUMPING" over some characters
// and produce WRONG RESULTS!
//
// Therefore, the checks for (r == 0) below avoid another detection,
// if the result already has a value unequal zero.
//
// CAUTION! If a detection was successful, then the current position and remaining count
// were already adapted within the corresponding "detect" function (as called below),
// so that they now point to the first character FOLLOWING the detected character sequence.
// Any "decode" function called afterwards can rely on this and start processing right away.
//

/**
 * Selects the knowledge part begin.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 */
void select_knowledge_part_begin(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge part begin.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // The "." or "#" indicate that a new sub part's model or property, respectively, begins.
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p2, p3, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_knowledge_part(p0, p1, p2, p3, (void*) MODEL_PART_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p2, p3, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_knowledge_part(p0, p1, p2, p3, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Move position by one if nothing was found.
        move_position(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* BEGIN_PART_KNOWLEDGE_SELECTOR_SOURCE */
#endif
