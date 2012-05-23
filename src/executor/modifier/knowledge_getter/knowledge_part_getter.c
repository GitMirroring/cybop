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

#ifndef KNOWLEDGE_PART_GETTER_SOURCE
#define KNOWLEDGE_PART_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../executor/comparator/all/part_all_comparator.c"
#include "../../../executor/modifier/knowledge_getter/branch_part_getter.c"
#include "../../../executor/modifier/name_getter/array_name_getter.c"
#include "../../../logger/logger.c"

/**
 * Gets the knowledge part by hierarchical name,
 * whereby the name may also be given as encapsulated name.
 *
 * A name with missing prefix does not necessarily have to be
 * an error, since property (meta) names are given without prefix.
 * If the hierarchical name does not start with a prefix
 * (part separator '.' or meta separator '#'), then it is
 * used as is, in full length.
 *
 * The model may specify:
 * - the element directly (e.g.: an integer or character value)
 * - the hierarchical name of the element (e.g.: application.gui.window.title)
 * - the hierarchical name of the name of the element (e.g.: application.name)
 *   where application.name itself contains a hierarchical name
 *   that points to an element;
 *   at first, the part name needs to be determined within the parametres;
 *   only then, that name can be used to determine the actual compound element
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source data
 * @param p2 the part name data
 * @param p3 the part name count
 * @param p4 the source count
 * @param p5 the knowledge memory part
 */
void get_part_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part knowledge.");

    // The source part.
    void* s = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part format, model item.
    void* sf = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* sm = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The source part format, model item data, count.
    void* sfd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* smc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated part model item.
    void* em = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The encapsulated part model item data, count.
    void* emd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* emc = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source data position.
    void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The temporary source count remaining.
    int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Get source part.
    get_name_array((void*) &s, p1, p2, p3, p4);
    // Get source part format, model item.
    // CAUTION! It is necessary to find out about the format and model.
    // The format may be "path/encapsulated", "path/knowledge", or some other.
    // The model may contain a knowledge path or encapsulated knowledge path.
    copy_array_forward((void*) &sf, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) FORMAT_PART_STATE_CYBOI_NAME);
    copy_array_forward((void*) &sm, s, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
    // Get source part format, model data, count.
    copy_array_forward((void*) &sfd, sf, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smd, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &smc, sm, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // The following comparisons do, in this order, get a part model item as:
    // - encapsulated knowledge (a model pointing to another model containing a part name)
    // - knowledge (a model containing a hierarchical part name)
    // - direct model
    //

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, sfd, (void*) ENCAPSULATED_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Get part as encapsulated knowledge.
            //
            // CAUTION! The format "path/encapsulated" is processed as wchar_t inside.
            // The "properties" are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model pointing to another model containing a part name:
            // model=".application.record.name"
            //

            // Copy source data position.
            copy_pointer((void*) &d, (void*) &smd);
            // Copy source count remaining.
            copy_integer((void*) &c, smc);

            // CAUTION! A COPY of source count remaining is forwarded here,
            // so that the original source value does not get changed.
            // This is IMPORTANT since otherwise, the original variable's "count"
            // gets decreased to zero, so that knowledge access works only once
            // (while decrementing the "count"), but not anymore afterwards.
            //
            // CAUTION! The source data position does NOT have to be copied,
            // since the parametre that was handed over is already a copy.
            // A local copy was made anyway, not to risk parametre falsification.
            // Its reference is forwarded, as it gets incremented by sub routines inside.

            // Get encapsulated part.
            // CAUTION! Hand over name as reference!
            get_part_branch((void*) &e, p5, (void*) &d, (void*) &c);
            // Get encapsulated part model item.
            copy_array_forward((void*) &em, e, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) MODEL_PART_STATE_CYBOI_NAME);
            // Get encapsulated part model item data, count.
            copy_array_forward((void*) &emd, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
            copy_array_forward((void*) &emc, em, (void*) POINTER_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

            // Copy source data position.
            copy_pointer((void*) &d, (void*) &emd);
            // Copy source count remaining.
            copy_integer((void*) &c, emc);

            // CAUTION! A COPY of source count remaining is forwarded here,
            // so that the original source value does not get changed.
            // This is IMPORTANT since otherwise, the original variable's "count"
            // gets decreased to zero, so that knowledge access works only once
            // (while decrementing the "count"), but not anymore afterwards.
            //
            // CAUTION! The source data position does NOT have to be copied,
            // since the parametre that was handed over is already a copy.
            // A local copy was made anyway, not to risk parametre falsification.
            // Its reference is forwarded, as it gets incremented by sub routines inside.

            // Get knowledge part.
            // CAUTION! Hand over name as reference!
            get_part_branch(p0, p5, (void*) &d, (void*) &c);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        compare_integer_equal((void*) &r, sfd, (void*) KNOWLEDGE_PATH_STATE_CYBOI_FORMAT);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // Get part as knowledge model.
            //
            // CAUTION! The format "path/knowledge" is processed as wchar_t inside.
            // The "properties" are uninteresting, since an encapsulated name cannot have
            // constraints. That is, only the model is of interest. It contains the
            // hierarchical name of the knowledge part to be retrieved.
            //
            // Example of a model containing a hierarchical part name:
            // model=".application.communication.partners.hostname"
            //

            // Copy source data position.
            copy_pointer((void*) &d, (void*) &smd);
            // Copy source count remaining.
            copy_integer((void*) &c, smc);

            // CAUTION! A COPY of source count remaining is forwarded here,
            // so that the original source value does not get changed.
            // This is IMPORTANT since otherwise, the original variable's "count"
            // gets decreased to zero, so that knowledge access works only once
            // (while decrementing the "count"), but not anymore afterwards.
            //
            // CAUTION! The source data position does NOT have to be copied,
            // since the parametre that was handed over is already a copy.
            // A local copy was made anyway, not to risk parametre falsification.
            // Its reference is forwarded, as it gets incremented by sub routines inside.

            // Get knowledge part.
            // CAUTION! Hand over name as reference!
            get_part_branch(p0, p5, (void*) &d, (void*) &c);
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
        copy_pointer(p0, (void*) &s);
    }
}

/* KNOWLEDGE_PART_GETTER_SOURCE */
#endif
