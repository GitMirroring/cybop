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

#ifndef MODEL_DIAGRAM_ENCODER_SOURCE
#define MODEL_DIAGRAM_ENCODER_SOURCE

#include "../../../../constant/type/cybol/text_cybol_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/converter/encoder/model_diagram/node_model_diagram_encoder.c"
#include "../../../../executor/converter/encoder/integer_vector_encoder.c"
#include "../../../../executor/converter/encoder/double_vector_encoder.c"
#include "../../../../executor/modifier/copier/array_copier.c"
#include "../../../../logger/logger.c"

/**
 * Encodes the knowledge model and creates a model diagram from it.
 *
 * A model diagram in this case is a textual representation of a knowledge model,
 * in form of many line feed-separated lines representing a model part each.
 *
 * @param p0 the destination model diagram (Hand over as reference!)
 * @param p1 the destination model diagram count
 * @param p2 the destination model diagram size
 * @param p3 the source part
 */
void encode_model_diagram(void* p0, void* p1, void* p2, void* p3) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Encode model diagram.");

    // The part elements retrieved as reference.
    void* n = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part elements.
    copy_array_forward((void*) &n, p3, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) NAME_PART_MEMORY_NAME);
    copy_array_forward((void*) &a, p3, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
    copy_array_forward((void*) &m, p3, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &d, p3, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) PROPERTIES_PART_MEMORY_NAME);

    // The part elements data, count retrieved as reference.
    void* nd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* nc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get part elements data, count retrieved as reference.
    copy_array_forward((void*) &nd, n, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &nc, n, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ad, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dd, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The tree level.
    // CAUTION! Do NOT forward NUMBER_0_INTEGER_STATE_CYBOI_MODEL constant directly,
    // since the tree level value gets changed in the following functions!
    int l = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Encode model diagram root node.
    encode_model_diagram_node(p0, p1, p2, nd, nc, ad, ac, md, mc, dd, dc, (void*) &l, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);
}

/* MODEL_DIAGRAM_ENCODER_SOURCE */
#endif
