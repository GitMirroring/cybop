/*
 * Copyright (C) 1999-2023. Christian Heller.
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
 * @version CYBOP 0.25.0 2023-03-01
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef HANDLER_SOURCE
#define HANDLER_SOURCE

#include "../constant/format/cyboi/state_cyboi_format.c"
#include "../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../constant/model/cyboi/state/state_cyboi_model.c"
#include "../constant/name/cyboi/state/item_state_cyboi_name.c"
#include "../constant/name/cyboi/state/part_state_cyboi_name.c"
#include "../constant/name/cyboi/state/primitive_state_cyboi_name.c"
#include "../constant/type/cyboi/state_cyboi_type.c"
#include "../controller/handler/operation_handler.c"
#include "../controller/handler/part_handler.c"
#include "../executor/comparator/integer/equal_integer_comparator.c"
#include "../executor/copier/array_copier.c"
#include "../executor/copier/integer_copier.c"
#include "../executor/copier/pointer_copier.c"
#include "../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"
#include "../executor/stacker/popper/popper.c"
#include "../executor/stacker/pusher/pusher.c"
#include "../logger/logger.c"

/**
 * Handles the signal.
 *
 * This function identifies the signal type and then calls a suitable handler for either:
 * - path
 * - part (compound)
 * - operation
 *
 * @param p0 the signal part
 * @param p1 the internal memory data
 * @param p2 the knowledge memory part (pointer reference)
 * @param p3 the stack memory item
 * @param p4 the signal memory item
 * @param p5 the internal memory data (pointer reference)
 * @param p6 the direct execution flag
 * @param p7 the shutdown flag
 * @param p8 the cybol loop break property
 */
void handle(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"\n");
    log_message_terminated((void*) INFORMATION_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle.");
    //?? fwprintf(stdout, L"Information: Handle. signal p0: %i\n", p0);

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
    // The knowledge signal part.
    void* part = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source path data position.
    void* pathd = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source path count remaining.
    int pathc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get signal part format, model, properties.
    copy_array_forward((void*) &f, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &m, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &p, p0, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) PROPERTIES_PART_STATE_CYBOI_NAME);

    // Get signal part format, model, properties data, count.
    copy_array_forward((void*) &fd, f, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &md, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &mc, m, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pd, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &pc, p, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, fd, (void*) CYBOL_PATH_TEXT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a runtime cybol-path pointing to an operation.
            //

            //?? fwprintf(stdout, L"Debug: Handle. cybol path: %i\n", *((int*) fd));

            //
            // CAUTION! There is a DIFFERENCE in how a part containing a cybol path as model is retrieved:
            //
            // 1 Leave cybol path as is
            //
            // - used in function "copy_array_forward" identifying a tree node by index
            // - used in function "get_name_array" identifying a tree node by name
            // - treats cybol path as pure string
            // - returns the properties of this cybol path part itself
            //
            // 2 Resolve cybol path
            //
            // - used in functions "get_part_name", "get_part_knowledge", "deserialise_knowledge" identifying a tree node by path
            // - resolves the cybol path diving deep into the tree hierarchy
            // - returns the properties of the tree node that the cybol path points to
            //
            // Therefore, different functions are used depending on the purpose:
            //
            // - copy_array_forward: get part as compound element to be handed over to "handle", done in "handle_element" and "read_signal"
            // - get_name_array: get part as model to be handed over to "handle", done in sequence/loop/branch
            // - get_part_name: retrieve the properties belonging to a cybol operation, done in most applicator functions
            //

            // Copy source path data position.
            copy_pointer((void*) &pathd, (void*) &md);
            // Copy source path count remaining.
            copy_integer((void*) &pathc, mc);

            //
            // Get signal part referenced by a knowledge path.
            //
            // CAUTION! Hand over name as reference!
            //
            // CAUTION! A COPY of path data and count is forwarded here,
            // so that the original values do NOT get changed.
            // This is IMPORTANT since otherwise, the original data position
            // gets increased and the count remaining decreased to zero,
            // so that knowledge access works only once, but not anymore afterwards.
            //
            deserialise_knowledge((void*) &part, p2, (void*) &pathd, (void*) &pathc, p2, p3, p1, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

            // Push (add) local variable parts onto stack memory.
            push(p3, pd, pc, p2, p5);

            //
            // Handle signal.
            //
            // The properties (pd, pc) represent runtime arguments
            // for the called compound operation.
            //
            // A cybol operation called via cybol-path is comparable to a function call
            // in the C programming language that is handing over arguments in parentheses.
            //
            handle(part, p1, p2, p3, p4, p5, p6, p7, p8);

            // Pop (remove) runtime argument parts from stack memory.
            pop(p3, pc);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT remove this section with "PART_ELEMENT_STATE_CYBOI_FORMAT"!
        // It is needed for at least initial startup logic residing in CYBOL
        // files only, before any logic is created and contained as runtime
        // knowledge models in the knowledge memory.
        //
        compare_integer_equal((void*) &r, fd, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // This is a compound operation.
            //

            //?? fwprintf(stdout, L"Debug: Handle. part element: %i\n", *((int*) fd));

            // Push (add) local variable parts onto stack memory.
            push(p3, pd, pc, p2, p5);

            // Handle compound part signal.
            handle_part(md, mc, p1, p2, p3, p4, p5, p6, p7, p8);

            // Pop (remove) runtime argument parts from stack memory.
            pop(p3, pc);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // This is a primitive operation.
        //

        //
        // CAUTION! This comparison is to improve performance.
        // It is actually NOT necessary here, since
        // a null value gets filtered out in the
        // "handle_operation" function as well.
        //
        if (fd != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Handle. operation: %i\n", *((int*) fd));

            // Handle primitive operation signal.
            handle_operation(pd, pc, p1, p2, p3, p4, p5, p7, fd);
        }
    }
}

/* HANDLER_SOURCE */
#endif
