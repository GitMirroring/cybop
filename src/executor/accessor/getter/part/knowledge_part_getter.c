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

#ifndef KNOWLEDGE_PART_GETTER_SOURCE
#define KNOWLEDGE_PART_GETTER_SOURCE

#include "../../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/comparator/basic/integer/equal_integer_comparator.c"
#include "../../../../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"
#include "../../../../logger/logger.c"

/**
 * Gets the knowledge part by hierarchical name,
 * whereby the name may also be given as reference name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * The model may specify:
 * - direct: the element directly (e.g.: an integer or character value)
 * - knowledge: the hierarchical name of the element (e.g.: .app.gui.window.title)
 * - reference: the hierarchical name of the name of the element (e.g.: .app.name)
 *   where .app.name itself contains a hierarchical name
 *   that points to an element;
 *   at first, the part name needs to be determined within the parametres;
 *   only then, that name can be used to determine the actual compound element
 * - stack: the name of a variable on stack memory WITHOUT any . or # (e.g.: index)
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source part (pointer reference)
 * @param p2 the knowledge memory part
 * @param p3 the stack memory item
 */
void get_part_knowledge(void* p0, void* p1, void* p2, void* p3) {

    if (p1 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** s = (void**) p1;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part knowledge.");

        // The source part format, model item.
        void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source part format, model item data, count.
        void* sfd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
        void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The temporary source data position and source count remaining.
        void* pathd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int pathc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The temporary part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Get source part format, model item.
        // CAUTION! It is necessary to find out about the format and model.
        // The format may be "path/reference", "path/knowledge", or some other.
        // The model may contain a knowledge path or reference knowledge path.
        copy_array_forward((void*) &sf, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        copy_array_forward((void*) &sm, *s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
        // Get source part format, model data, count.
        copy_array_forward((void*) &sfd, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
        copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

        // The comparison result.
        int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // The following comparisons do, in this order, get a part model item from/as:
        // - stack memory (a model containing the name of a value stored in stack memory)
        // - reference knowledge memory (a model pointing to another model containing a part name)
        // - knowledge memory (a model containing a hierarchical part name)
        // - direct model
        //

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, sfd, (void*) STACK_PATH_STATE_CYBOI_FORMAT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Get part as stack memory model.
                //
                // CAUTION! The format "path/stack" is processed as wchar_t inside.
                // The "properties" are uninteresting, since a stack variable name
                // cannot have constraints. That is, only the model is of interest.
                // It contains the name of the stack variable to be retrieved.
                //
                // Example of a model containing a stack variable name:
                // <node name="result" channel="inline" format="path/stack" model="break"/>
                //

                // Get temporary part from stack memory.
                get_name_item_element((void*) &p, p3, smd, smc, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

                // CAUTION! For this recursive function call to work correctly,
                // CYBOL applications have to use the format "path/knowledge"
                // for all paths that are built up inside as string.
                // If using the format "text/plain", the block below may NOT
                // be reached when comparing with KNOWLEDGE_PATH_STATE_CYBOI_FORMAT.
                get_part_knowledge(p0, (void*) &p, p2, p3);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, sfd, (void*) REFERENCE_PATH_STATE_CYBOI_FORMAT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Get part as reference knowledge.
                //
                // CAUTION! The format "path/reference" is processed as wchar_t inside.
                // The "properties" are uninteresting, since a reference name cannot have
                // constraints. That is, only the model is of interest. It contains the
                // hierarchical name of the knowledge part to be retrieved.
                //
                // Example of a model pointing to another model containing a part name:
                // model=".application.record.name"
                //

                // Copy source data position.
                copy_pointer((void*) &pathd, (void*) &smd);
                // Copy source count remaining.
                copy_integer((void*) &pathc, smc);

                // Get temporary part from knowledge memory.
                // CAUTION! Hand over name as reference!
                // CAUTION! A COPY of path data and count is forwarded here,
                // so that the original values do NOT get changed.
                // This is IMPORTANT since otherwise, the original data position
                // gets increased and the count remaining decreased to zero,
                // so that knowledge access works only once, but not anymore afterwards.
                deserialise_knowledge((void*) &p, p2, (void*) &pathd, (void*) &pathc, p2);

                // CAUTION! For this recursive function call to work correctly,
                // cybol applications have to use the format "path/knowledge"
                // for all paths that are built up inside as string.
                // If using the format "text/plain", the block below may NOT
                // be reached when comparing with KNOWLEDGE_PATH_STATE_CYBOI_FORMAT.
                get_part_knowledge(p0, (void*) &p, p2, p3);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            compare_integer_equal((void*) &r, sfd, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

            if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // Get part as knowledge model.
                //
                // CAUTION! The format "path/knowledge" is processed as wchar_t inside.
                // The "properties" are uninteresting, since a reference name cannot have
                // constraints. That is, only the model is of interest. It contains the
                // hierarchical name of the knowledge part to be retrieved.
                //
                // Example of a model containing a hierarchical part name:
                // model=".application.communication.partners.hostname"
                //

                // Copy source data position.
                copy_pointer((void*) &pathd, (void*) &smd);
                // Copy source count remaining.
                copy_integer((void*) &pathc, smc);

                // Get knowledge part from knowledge memory.
                // CAUTION! Hand over name as reference!
                // CAUTION! A COPY of path data and count is forwarded here,
                // so that the original values do NOT get changed.
                // This is IMPORTANT since otherwise, the original data position
                // gets increased and the count remaining decreased to zero,
                // so that knowledge access works only once, but not anymore afterwards.
                deserialise_knowledge(p0, p2, (void*) &pathd, (void*) &pathc, p2);
            }
        }

        if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Get source part as DIRECT model (inline),
            // i.e. DO NOT interpret the model as path.
            //
            // CAUTION! The source part was already retrieved above.
            // Therefore, the pointer to it is just copied here.
            //
            // CAUTION! The pointer handed over has a size of one
            // and thus does NOT need to be resized,
            // i.e. using the "overwrite" function is NOT necessary here.
            //

            // Copy source part pointer reference.
            copy_pointer(p0, p1);
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part knowledge. The source part is null.");
    }
}

/* KNOWLEDGE_PART_GETTER_SOURCE */
#endif
