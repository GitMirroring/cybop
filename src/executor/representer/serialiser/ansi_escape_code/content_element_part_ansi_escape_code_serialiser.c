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

#ifndef CONTENT_ELEMENT_PART_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/ansi_escape_code/properties_ansi_escape_code_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_ansi_escape_code(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);

/**
 * Serialises the part element content into ansi escape code.
 *
 * @param p0 the destination item
 * @param p1 the source model data
 * @param p2 the source model count
 * @param p3 the source properties data
 * @param p4 the source properties count
 * @param p5 the source whole properties data
 * @param p6 the source whole properties count
 * @param p7 the knowledge memory part
 * @param p8 the format data
 */
void serialise_ansi_escape_code_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code part element content.");

    // Append properties.
    serialise_ansi_escape_code_properties(p0, p3, p4, p5, p6, p7);

    // Append model.
    serialise_ansi_escape_code(p0, p1, p2, p3, p4, p7, p8);

    // Reset terminal attributes in order to
    // have original settings when leaving cyboi.
    append_item_element(p0, (void*) ESCAPE_ANSI_ESCAPE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ANSI_ESCAPE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(p0, (void*) ATTRIBUTE_OFF_ANSI_ESCAPE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_OFF_ANSI_ESCAPE_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* CONTENT_ELEMENT_PART_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
