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

#ifndef ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE
#define ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE

#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/xml_cybol_name.c"
#include "../../../../constant/name/xml_name.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the attribute begin or tag end.
 *
 * @param p0 the destination has attribute flag
 * @param p1 the destination has content flag
 * @param p2 the destination is empty flag
 * @param p3 the source data position (pointer reference)
 * @param p4 the source count remaining
 */
void select_xml_attribute_begin_or_tag_end(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xml attribute begin or tag end.");

    //
    // CAUTION! The ORDER of the following function calls is IMPORTANT!
    // The empty tag end "/>" has to be searched BEFORE
    // the simple tag end ">", because of the slash "/" character.
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

        detect_array((void*) &r, p3, p4, (void*) EMPTY_TAG_END_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) EMPTY_TAG_END_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The empty tag end was found.
            // Set is empty flag.
            copy_integer(p2, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) TAG_END_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) TAG_END_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The tag end, indicating subsequent element content, was found.
            // Set has content flag.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p3, p4, (void*) ATTRIBUTE_BEGIN_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_BEGIN_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // The tag name end, indicating subsequent attributes, was found.
            // Set has attribute flag.
            copy_integer(p0, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        move_position(p3, p4, (void*) WIDE_CHARACTER_INTEGRAL_TYPE_SIZE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* ATTRIBUTE_BEGIN_OR_TAG_END_XML_SELECTOR_SOURCE */
#endif
