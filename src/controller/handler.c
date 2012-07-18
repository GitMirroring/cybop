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

#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../constant/format/cyboi/logic_cyboi_format.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../controller/handler/operation_handler.c"
#include "../controller/handler/part_handler.c"
#include "../executor/comparator/all/array_all_comparator.c"
#include "../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"
#include "../logger/logger.c"

/**
 * Handles the signal.
 *
 * This function identifies the signal type and then calls either:
 * - part (compound) signal handler
 * - operation signal handler
 *
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part
 * @param p3 the signal memory item
 * @param p4 the signal memory interrupt
 * @param p5 the signal memory mutex
 * @param p6 the direct execution flag
 * @param p7 the shutdown flag
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle signal.");

    // The signal part format, model, properties.
    void* f = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* m = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The signal part format, model, properties data, count.
    void* fd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* md = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* mc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* pc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The referenced (by a knowledge path) signal part.
    void* part = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part model.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated signal part model data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Get signal part format, model, properties.
    copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Get signal part format, model, properties data, count.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

/*??
if (fd != *NULL_POINTER_STATE_CYBOI_MODEL) {
fwprintf(stdout, L"TEST handle *fd: %i\n", *((int*) fd));
} else {
fwprintf(stdout, L"TEST handle NULL fd: %i\n", fd);
}
*/

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // CAUTION! Do NOT remove this section with "PART_ELEMENT_STATE_CYBOI_FORMAT"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        compare_integer_equal((void*) &r, fd, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST handle part: %i\n", r);

            // Handle compound part signal.
            //
            // CAUTION! The signal part properties are possibly
            // necessary one day for pre- and post conditions etc.
            handle_part(md, mc, pd, pc, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, fd, (void*) ENCAPSULATED_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST handle encapsulated: %i\n", r);

            // Get encapsulated signal part.
            // CAUTION! Hand over name as reference!
            deserialise_knowledge((void*) &e, p2, (void*) &md, mc);

            // Get encapsulated signal part model item.
            copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get encapsulated signal part model data, count array.
            copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Get double-encapsulated signal part.
            // CAUTION! Hand over name as reference!
            deserialise_knowledge((void*) &part, p2, (void*) &emd, emc);

            // Handle signal.
            handle(part, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, fd, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

//?? fwprintf(stdout, L"TEST handle knowledge: %i\n", r);

            // Get signal part referenced by a knowledge path.
            // CAUTION! Hand over name as reference!
            deserialise_knowledge((void*) &part, p2, (void*) &md, mc);

            // Handle signal.
            handle(part, p1, p2, p3, p4, p5, p6, p7);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // Handle primitive operation signal.
        handle_operation(pd, pc, p1, p2, p3, p4, p5, p7, fd);
    }
}

/* HANDLER_SOURCE */
#endif
