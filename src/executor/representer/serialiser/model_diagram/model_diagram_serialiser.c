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

#ifndef MODEL_DIAGRAM_SERIALISER_SOURCE
#define MODEL_DIAGRAM_SERIALISER_SOURCE

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/model_diagram/node_model_diagram_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/cybol/double/double_cybol_serialiser.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the model into a model diagram.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source type data
 * @param p4 the source model data
 * @param p5 the source model count
 * @param p6 the source properties data
 * @param p7 the source properties count
 */
void serialise_model_diagram(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise model diagram.");

    // The tree level.
    // CAUTION! Do NOT forward the NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
    // since the tree level value gets changed in the following functions!
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Encode model diagram root node.
    serialise_model_diagram_node(p0, p1, p2, p3, p4, p5, p6, p7, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &l);
}

/* MODEL_DIAGRAM_SERIALISER_SOURCE */
#endif
