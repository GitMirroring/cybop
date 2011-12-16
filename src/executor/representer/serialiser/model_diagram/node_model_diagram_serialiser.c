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

#ifndef NODE_MODEL_DIAGRAM_SERIALISER_SOURCE
#define NODE_MODEL_DIAGRAM_SERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/model_diagram/indentation_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/line_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/model_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/part_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/model_diagram/type_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/double/double_cybol_serialiser.c"
#include "../../../../executor/modifier/inserter/array_inserter.c"
#include "../../../../executor/modifier/overwriter/array_overwriter.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the model diagram node.
 *
 * @param p0 the destination model diagram item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source type data
 * @param p4 the source type count
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the source properties data
 * @param p8 the source properties count
 * @param p9 the properties flag
 * @param p10 the tree level
 */
void serialise_model_diagram_node(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise model diagram node.");

    // Append indentation.
    serialise_model_diagram_indentation(p0, p9, p10);

    // Append part name.
    append_item_element(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p2, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    // Append line.
    serialise_model_diagram_line(p0);

    // Append part type.
    serialise_model_diagram_type(p0, p3);

    // Append part model.
    serialise_model_diagram_model(p0, p5, p6, p10, p3);

    // Append part properties.
    serialise_model_diagram_part(p0, p7, p8, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p10);
}

/* NODE_MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
