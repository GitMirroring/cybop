/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// cybol
//

#include "../../../executor/representer/deserialiser/cybol/byte_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/channel_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/compound_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/constraints_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/content_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/creation_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/decision_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/destination_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/element_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/encoding_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/file_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/format_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/handover_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/language_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/part_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/retrieval_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/source_cybol_deserialiser.c"
#include "../../../executor/representer/deserialiser/cybol/type_cybol_deserialiser.c"

#include "../../../executor/representer/serialiser/cybol/byte_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/channel_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/compound_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/constraints_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/content_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/element_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/encoding_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/format_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/language_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/part_cybol_serialiser.c"
#include "../../../executor/representer/serialiser/cybol/type_cybol_serialiser.c"

//
// knowledge
//

#include "../../../executor/representer/deserialiser/knowledge/element_knowledge_deserialiser.c"
#include "../../../executor/representer/deserialiser/knowledge/identification_knowledge_deserialiser.c"
#include "../../../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"
#include "../../../executor/representer/deserialiser/knowledge/name_knowledge_deserialiser.c"
#include "../../../executor/representer/deserialiser/knowledge/part_knowledge_deserialiser.c"
#include "../../../executor/representer/deserialiser/knowledge/reference_knowledge_deserialiser.c"

#include "../../../executor/selector/knowledge/begin_knowledge_selector.c"
#include "../../../executor/selector/knowledge/end_knowledge_selector.c"
#include "../../../executor/selector/knowledge/identification_knowledge_selector.c"
#include "../../../executor/selector/knowledge/memory_knowledge_selector.c"
#include "../../../executor/selector/knowledge/move_knowledge_selector.c"
#include "../../../executor/selector/knowledge/root_knowledge_selector.c"

//
// model diagram
//

#include "../../../executor/representer/serialiser/model_diagram/constraints_model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/content_model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/element_model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/indentation_model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/line_model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/model_diagram_serialiser.c"
#include "../../../executor/representer/serialiser/model_diagram/part_model_diagram_serialiser.c"
