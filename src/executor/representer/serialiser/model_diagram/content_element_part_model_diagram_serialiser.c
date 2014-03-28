/*
 * Copyright (C) 1999-2014. Christian Heller.
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
 * @version CYBOP 0.15.0 2013-09-22
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef CONTENT_ELEMENT_PART_MODEL_DIAGRAM_SERIALISER_SOURCE
#define CONTENT_ELEMENT_PART_MODEL_DIAGRAM_SERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/modifier/appender/item_appender.c"
#include "../../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/indentation_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/line_model_diagram_serialiser.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6);
void serialise_model_diagram_part(void* p0, void* p1, void* p2, void* p3, void* p4);

/**
 * Serialises the part element content into model diagram.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source format data
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 * @param p8 the properties flag
 * @param p9 the tree level
 */
void serialise_model_diagram_part_element_content(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise model diagram part element content.");

    // Append indentation.
    serialise_model_diagram_indentation(p0, p8, p9);

    // Append part name.
    append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Append line.
    serialise_model_diagram_line(p0);

    // Append part format.
    serialise_cybol_format(p0, p3);

    // Append line.
    serialise_model_diagram_line(p0);

    // Append part model.
    serialise_model_diagram(p0, p4, p5, p6, p7, p9, p3);

    // Append part properties.
    serialise_model_diagram_part(p0, p6, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p9);
}

/* CONTENT_ELEMENT_PART_MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
