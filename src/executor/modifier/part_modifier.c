/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef PART_MODIFIER_SOURCE
#define PART_MODIFIER_SOURCE

#include "../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../../constant/type/cyboi/state_cyboi_type.c"
#include "../../executor/modifier/copier/array_copier.c"
#include "../../executor/modifier/item_modifier.c"
#include "../../logger/logger.c"

/**
 * Modifies the destination part element given by the
 * destination part element index with the source array.
 *
 * The destination part element may be either of:
 * name, type, model, properties.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination part index
 * @param p5 the source array index
 * @param p6 the adjust count flag
 * @param p7 the model flag
 * @param p8 the properties flag
 * @param p9 the operation type
 * @param p10 the destination part element index
 */
void modify_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify part element.");

    // The destination part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p10);

    // Modify item as element of the part container.
    modify_item_element(e, p1, p2, p3, p4, p5, p6, p7, p8, p9, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/**
 * Modifies the destination- with the source part.
 *
 * The name, type, properties of the destination part
 * remain unchanged. Only the model gets overwritten.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the type
 * @param p3 the count
 * @param p4 the destination index
 * @param p5 the source index
 * @param p6 the adjust count flag
 * @param p7 the model flag
 * @param p8 the properties flag
 * @param p9 the operation type
 */
void modify_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Modify part.");

    // The destination model, properties.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dp = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination model, properties.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &dp, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Modify destination- with source part model item.
    modify_item(dm, sm, p2, p3, p4, p5, p6, p7, p8, p9);
}

/* PART_MODIFIER_SOURCE */
#endif
