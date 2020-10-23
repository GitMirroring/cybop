/*
 * Copyright (C) 1999-2020. Christian Heller.
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
 * @version CYBOP 0.21.0 2020-07-29
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_KNOWLEDGE_DESERIALISER_SOURCE
#define PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// Forward declarations.
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7);

/**
 * Deserialises a knowledge part.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 * @param p7 the source whole part element index:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for stack variables
 */
void deserialise_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part.");

    fwprintf(stdout, L"TEST: Deserialise knowledge part.\n");
    fwprintf(stdout, L"TEST: knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));

    // The new whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The comparison result for the whole.
    int rw = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The comparison result for the element.
    int re = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Compare if knowledge path count remaining contains at least one character.
    //
    // CAUTION! In case p3 is null, the comparison result remains false that way.
    //
    compare_integer_greater((void*) &rw, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

    if (rw != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The knowledge path contains another element to follow.
        //

        //
        // Get new whole part.
        //
        // CAUTION! Forward the source whole part element INDEX p7 as argument here,
        // since it identifies the memory to retrieve the part from.
        //
        deserialise_knowledge((void*) &w, p1, p2, p3, p4, p5, p6, p7);

        if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // Compare if knowledge path count remaining contains at least one character.
            //
            // CAUTION! In case p3 is null, the comparison result remains false that way.
            //
            compare_integer_greater((void*) &re, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL);

            if (re != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                //
                // The knowledge path contains another element to follow.
                //

                //
                // Get element part.
                //
                // Process knowledge path hierarchy recursively further down,
                // using new whole part.
                //
                // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
                // but NULL instead, since the next separator is unknown yet.
                //
                deserialise_knowledge((void*) &e, (void*) &w, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL);

                if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

                    // Take the element (child) as result.
                    copy_pointer(p0, (void*) &e);

                } else {

                    //
                    // The returned element (child) is NULL, even though the
                    // knowledge path contained another element to follow.
                    // That is, something went wrong.
                    //
                    // Possible reasons:
                    // 1 Node does not exist.
                    // 2 Knowledge path is wrong.
                    //

                    log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge part. The returned element (child) is NULL, even though the knowledge path contained another element to follow.");
                    fwprintf(stdout, L"Error: Could not deserialise knowledge part. The returned element (child) is NULL, even though the knowledge path contained another element to follow. e: %i\n", e);

                    //
                    // Reset destination part to NULL.
                    //
                    // CAUTION! This is important since otherwise, a previously
                    // retrieved whole part will be returned and the cybol application
                    // work with it instead of the child element actually meant.
                    // But this could MIX UP the whole cybol application
                    // and surely lead to errors.
                    //
                    copy_pointer(p0, NULL_POINTER_STATE_CYBOI_MODEL);
                }

            } else {

                //
                // The knowledge path contains NO MORE elements to follow.
                // Its end has been reached.
                //

                //
                // Take the whole (parent) as result,
                // since it is the last existing part in the hierarchy.
                //
                copy_pointer(p0, (void*) &w);
            }

        } else {

            //
            // The returned whole (parent) is NULL, even though the
            // knowledge path contained another element to follow.
            // That is, something went wrong.
            //
            // Possible reasons:
            // 1 Node does not exist.
            // 2 Knowledge path is wrong.
            //

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge part. The returned whole (parent) is NULL, even though the knowledge path contained another element to follow.");
            fwprintf(stdout, L"Error: Could not deserialise knowledge part. The returned whole (parent) is NULL, even though the knowledge path contained another element to follow. w: %i\n", w);

            //
            // Reset destination part to NULL.
            //
            // CAUTION! This is important since otherwise, a previously
            // retrieved whole part will be returned and the cybol application
            // work with it instead of the child element actually meant.
            // But this could MIX UP the whole cybol application
            // and surely lead to errors.
            //
            copy_pointer(p0, NULL_POINTER_STATE_CYBOI_MODEL);
        }

    } else {

        //
        // The knowledge path contains NO MORE elements to follow.
        // Its end has been reached.
        //

        // Do NOTHING here.
    }
}

/* PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
