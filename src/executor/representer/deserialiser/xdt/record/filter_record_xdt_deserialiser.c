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

#ifndef FILTER_RECORD_XDT_DESERIALISER_SOURCE
#define FILTER_RECORD_XDT_DESERIALISER_SOURCE

#include "../../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../../constant/name/cybol/cybol_name.c"
#include "../../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../../executor/modifier/appender/item_appender.c"
#include "../../../../../executor/accessor/name_getter/array_name_getter.c"
#include "../../../../../executor/modifier/overwriter/item_overwriter.c"
#include "../../../../../executor/representer/deserialiser/cybol/integer/primitive_value_integer_cybol_deserialiser.c"
#include "../../../../../logger/logger.c"

/**
 * Deserialises the xdt record by filtering out record begin fields.
 *
 * @param p0 the destination model item
 * @param p1 the source name data
 * @param p2 the source name count
 * @param p3 the source model data
 * @param p4 the source model count
 * @param p5 the parent model item (pointer reference)
 */
void deserialise_xdt_record_filter(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise xdt record filter.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The field identification.
    int i = *NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL;

    // Deserialise identification as integer primitive.
    deserialise_cybol_integer_value_primitive((void*) &i, p1, p2, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    // Compare if field represents a record identification.
    compare_integer_equal((void*) &r, (void*) &i, (void*) RECORD_IDENTIFICATION_FIELD_XDT_NAME);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The part name, format, type, model, properties item.
        void* pn = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Allocate record part.
        allocate_part((void*) &p, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        // Get record part name item.
        // CAUTION! Retrieve data ONLY AFTER having called desired functions!
        // Inside the structure, arrays may have been reallocated,
        // with elements pointing to different memory areas now.
        copy_array_forward((void*) &pn, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NAME_PART_STATE_CYBOI_NAME);

        // Fill record part name item with field model.
        overwrite_item_element(pn, p3, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, p4, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DATA_ITEM_STATE_CYBOI_NAME);

        // Remember record part model as future parent node.
        copy_pointer(p5, (void*) &p);

    } else {

        // Add field part to destination.
        append_item_element(p0, (void*) &p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }
}

/* FILTER_RECORD_XDT_DESERIALISER_SOURCE */
#endif
