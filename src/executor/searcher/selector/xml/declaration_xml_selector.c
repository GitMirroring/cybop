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

#ifndef DECLARATION_XML_SELECTOR_SOURCE
#define DECLARATION_XML_SELECTOR_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/xml/xml_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/searcher/detector/array_detector.c"
#include "../../../../executor/searcher/mover/position_mover.c"
#include "../../../../logger/logger.c"
#include "../../../../variable/type_size/integral_type_size.c"

/**
 * Selects the xml declaration.
 *
 * @param p0 the destination properties item
 * @param p1 the destination break flag
 * @param p2 the source data position (pointer reference)
 * @param p3 the source count remaining
 */
void select_xml_declaration(void* p0, void* p1, void* p2, void* p3) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select xml declaration.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect_array((void*) &r, p2, p3, (void*) DECLARATION_END_XML_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) DECLARATION_END_XML_NAME_COUNT, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Set break flag.
            copy_integer(p1, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // None of the comparisons above delivered a positive (r != 0) result.
        // Therefore, increment the current position by one (pointer size).

        move_position(p2, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    }
}

/* DECLARATION_XML_SELECTOR_SOURCE */
#endif
