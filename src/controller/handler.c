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

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../constant/type/cybol/operation_cybol_type.c"
#include "../constant/type/cybol/text_cybol_type.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../constant/type/cyboi/logic_cyboi_type.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../controller/handler/encapsulated_handler.c"
#include "../controller/handler/knowledge_handler.c"
#include "../controller/handler/operation_handler.c"
#include "../controller/handler/part_handler.c"
#include "../executor/comparator/all/array_all_comparator.c"
#include "../logger/logger.c"

/**
 * Handles the signal.
 *
 * This function identifies the signal type and then calls either:
 * - part (compound) signal handler
 * - operation signal handler
 *
 * @param p0 the signal part
 * @param p1 the direct execution flag
 * @param p2 the shutdown flag
 * @param p3 the knowledge memory part
 * @param p4 the internal memory array
 * @param p5 the signal memory item
 * @param p6 the signal memory interrupt request flag
 * @param p7 the signal memory mutex
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_terminated_message((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle signal.");

    // The signal part type, model, properties.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal part elements data, count.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* dc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The referenced (by a knowledge path) signal part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part.
    void* ep = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal part type, model, properties.
    copy_array_forward((void*) &a, p0, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) TYPE_PART_MEMORY_NAME);
    copy_array_forward((void*) &m, p0, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
    copy_array_forward((void*) &d, p0, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) PROPERTIES_PART_MEMORY_NAME);
    // Get signal part elements data, count.
    copy_array_forward((void*) &ad, a, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dd, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
    copy_array_forward((void*) &dc, d, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Do NOT remove this section with "PART_MEMORY_TYPE"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        compare_integer_equal((void*) &r, ad, (void*) PART_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Handle compound part signal.
            handle_part(md, mc, dd, dc, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, ad, (void*) ENCAPSULATED_KNOWLEDGE_PATH_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get encapsulated signal part.
            // CAUTION! Hand over name as reference!
            get_part_branch((void*) &ep, p3, (void*) &md, mc);

            // Get encapsulated signal part model item.
            copy_array_forward((void*) &em, ep, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) MODEL_PART_MEMORY_NAME);
            // Get encapsulated signal part model data, count array.
            copy_array_forward((void*) &emd, em, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) DATA_ITEM_MEMORY_NAME);
            copy_array_forward((void*) &emc, em, (void*) POINTER_MEMORY_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_MEMORY_NAME, (void*) COUNT_ITEM_MEMORY_NAME);

            // Get double-encapsulated signal part.
            // CAUTION! Hand over name as reference!
            get_part_branch((void*) &p, p3, (void*) &emd, emc);

            // Handle signal.
            handle(p, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, ad, (void*) KNOWLEDGE_PATH_MEMORY_TYPE);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            // Get signal part referenced by a knowledge path.
            // CAUTION! Hand over name as reference!
            get_part_branch((void*) &p, p3, (void*) &md, mc);

            // Handle signal.
            handle(p, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Handle primitive operation signal.
        handle_operation(dd, dc, p1, p2, p3, p4, p5, p6, p7, ad);
    }
}

/* HANDLER_SOURCE */
#endif
