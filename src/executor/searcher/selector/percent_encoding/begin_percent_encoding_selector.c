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
 * @version CYBOP 0.12.0 2012-08-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef BEGIN_PERCENT_ENCODING_SELECTOR_SOURCE
#define BEGIN_PERCENT_ENCODING_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/percent_encoding/percent_encoding_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/deserialiser/percent_encoding/character_percent_encoding_deserialiser.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"

/**
 * Selects the percent-encoded character's begin.
 *
 * @param p0 the destination item
 * @param p1 the source data position (pointer reference)
 * @param p2 the source count remaining
 */
void select_percent_encoding_begin(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select percent encoding begin.");

    //
    // CAUTION! The comparison result HAS TO BE ZERO, if a detection is to be taking place!
    // Many "detect" functions are called in a sequence, below.
    // If the result of one detection function was positive (r == 1),
    // then that function increments the current position and decrements the remaining count.
    // In this case, further detection functions following afterwards might detect
    // further characters and CHANGE the current position and remaining count, and so forth,
    // which would have the effect of "jumping" over some characters and produce WRONG RESULTS!
    // Therefore, the checks for (r == 0) below avoid another detection,
    // if the result already has a value unequal zero.
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Set last flag to "true", so that the pointer is
        // moved forward and only the actual character code remains.
        //
        // CAUTION! The data are available as multibyte (NOT wide) character sequence.
        detect_array((void*) &r, p1, p2, (void*) BEGIN_PERCENT_ENCODING_NAME, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BEGIN_PERCENT_ENCODING_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            deserialise_percent_encoding_character(p0, p1, p2);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! The data are available as multibyte (NOT wide) character sequence.
        move_position(p1, p2, (void*) CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);
    }
}

/* BEGIN_PERCENT_ENCODING_SELECTOR_SOURCE */
#endif
