/*
 * Copyright (C) 1999-2022. Christian Heller.
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
 * @version CYBOP 0.22.0 2022-02-22
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef PART_KNOWLEDGE_DESERIALISER_SOURCE
#define PART_KNOWLEDGE_DESERIALISER_SOURCE

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// Forward declarations
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

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
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts on heap
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties on heap
 *           - NUMBER_MINUS_1_INTEGER_STATE_CYBOI_MODEL for variables on stack
 *           - *NULL_POINTER_STATE_CYBOI_MODEL if none of the above applies
 */
void deserialise_knowledge_part(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge part.");

    // The new whole part.
    void* w = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;

    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 0. knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 0. knowledge path count remaining: %i\n", *((int*) p3));

    //
    // Get new whole part.
    //
    // CAUTION! Forward the source whole part element INDEX p7 as argument here,
    // since it identifies the memory to retrieve the part from.
    //
    deserialise_knowledge((void*) &w, p1, p2, p3, p4, p5, p6, p7, *NULL_POINTER_STATE_CYBOI_MODEL);

    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 1. knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 1. knowledge path count remaining: %i\n", *((int*) p3));

    if (w != *NULL_POINTER_STATE_CYBOI_MODEL) {

        //
        // A new whole (parent) EXISTS.
        // Further processing of the knowledge path makes sense.
        //

        //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. a new whole (parent) exists: %i\n", w);

        // The knowledge path end flag.
        int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

        //
        // Get element part.
        //
        // Process knowledge path hierarchy recursively further down,
        // using new whole part.
        //
        // CAUTION! Do NOT forward the source whole part element index p7 as argument here,
        // but NULL instead, since the next separator is unknown yet.
        //
        deserialise_knowledge((void*) &e, (void*) &w, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &f);

        //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 2. knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));
        //?? fwprintf(stdout, L"Debug: Deserialise knowledge part 2. knowledge path count remaining: %i\n", *((int*) p3));

        if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. knowledge path end has been reached: %i\n", f);

            //
            // The knowledge path does NOT contain further elements.
            // Its END has been reached.
            //

            //
            // Take the whole (parent) as result,
            // since it is the last existing part in the hierarchy.
            //
            copy_pointer(p0, (void*) &w);

        } else {

            //
            // The knowledge path DOES contain further elements.
            //

            //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. knowledge path end has NOT been reached: %i\n", f);

            if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

                //
                // The element (child) WAS successfully retrieved.
                //

                //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. element (child) exists: %i\n", e);

                //
                // Take the element (child) as result.
                //
                // The element (child) has higher priority
                // than the whole (parent) found before.
                //
                copy_pointer(p0, (void*) &e);

            } else {

                //
                // The element (child) could NOT be retrieved.
                //
                // Reasons might be:
                // 1) a SPELLING error
                // 2) the element (child) does NOT EXIST
                //
                // Case 2 may be REGULAR behaviour in a cybol application
                // since sometimes, knowledge paths may point to NON-EXISTING nodes.
                //

                //
                // Do NOTHING here.
                //
                // CAUTION! A reset of p0 to null is NOT necessary,
                // since other elements (parents) were not assigned yet.
                //
                // However, it IS IMPORTANT that the return value is only set,
                // if a valid existing element (child) was found.
                // Assigning the whole (parent) instead of a non-existing element (child)
                // would cause a cybol application to manipulate
                // the parent instead of the (non-existing) child node,
                // which would definitely lead to WRONG application data.
                //
                // CAUTION: In order to keep the log file size low,
                // the following log messages are commented out.
                //
                // CAUTION: This empty block containing a comment only
                // does no harm, since the compiler will remove it anyway.
                //

                //?? fwprintf(stdout, L"Debug: Deserialise knowledge part. element (child) is null: %i\n", e);
            }
        }

    } else {

        //
        // The whole (parent) does not exist.
        //
        // This may be REGULAR behaviour in a cybol application since
        // sometimes, knowledge paths may point to NON-EXISTING nodes.
        //
        // CAUTION! In order to keep the log file size low,
        // the following log messages are commented out.
        //
        // CAUTION: This empty block containing a comment only
        // does no harm, since the compiler will remove it anyway.
        //

        //?? log_message_terminated((void*) WARNING_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge part. The new whole (parent) is null.");
        //?? fwprintf(stdout, L"Warning: Could not deserialise knowledge part. The new whole (parent) is null. w: %i\n", w);
    }
}

/* PART_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
