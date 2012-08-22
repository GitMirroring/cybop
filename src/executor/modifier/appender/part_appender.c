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

#ifndef PART_APPENDER_SOURCE
#define PART_APPENDER_SOURCE

#include "../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../../../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../../../executor/modifier/overwriter/part_overwriter.c"
#include "../../../logger/logger.c"

/**
 * Appends the source array to the destination part element
 * given by the destination part element index.
 *
 * The destination part element may be either of:
 * name, type, model, properties.
 *
 * A destination index is not expected as parametre,
 * since the source is appended at the end.
 *
 * @param p0 the destination part
 * @param p1 the source array
 * @param p2 the type
 * @param p3 the count
 * @param p4 the source array index
 * @param p5 the destination part element index
 */
void append_part_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Append part element.");

    // The destination part element.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination part element.
    copy_array_forward((void*) &e, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, p5);

    // Append item as element of the part container.
    append_item_element(e, p1, p2, p3, p4);
}

/**
 * Appends the source- to the destination part.
 *
 * The name, type, properties of the destination part
 * remain unchanged. Only the model gets appended.
 *
 * A destination index is not expected as parametre,
 * since the source is appended at the end.
 *
 * @param p0 the destination part
 * @param p1 the source part
 * @param p2 the type
 * @param p3 the count
 * @param p4 the source index
 */
void append_part(void* p0, void* p1, void* p2, void* p3, void* p4) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Append part.");

    // The destination model.
    void* dm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source model.
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get destination model.
    copy_array_forward((void*) &dm, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source model.
    copy_array_forward((void*) &sm, p1, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);

    // Append source- to destination part model item.
    append_item(dm, sm, p2, p3, p4);
}

/* PART_APPENDER_SOURCE */
#endif
