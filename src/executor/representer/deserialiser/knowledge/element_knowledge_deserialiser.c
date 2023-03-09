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

#ifndef ELEMENT_KNOWLEDGE_DESERIALISER_SOURCE
#define ELEMENT_KNOWLEDGE_DESERIALISER_SOURCE

//
// Executable interface
//

#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../executor/copier/pointer_copier.c"
#include "../../../../logger/logger.c"

//
// Forbidden includes
//
// CAUTION! Do NOT include the following files since otherwise,
// circular references would occur due to module dependencies.
// Instead, forward declarations are used further below.
// Therefore, the following includes are to be commented OUT
// and listed here just for information.
//

// #include "../../../../executor/representer/deserialiser/knowledge/knowledge_deserialiser.c"

//
// Forward declarations
//

void deserialise_knowledge(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8);

/**
 * Deserialises the knowledge element node as child of the given whole (parent) node.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part (pointer reference)
 * @param p2 the knowledge path data position (pointer reference)
 * @param p3 the knowledge path count remaining
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the stack memory item
 * @param p6 the internal memory data
 */
void deserialise_knowledge_element(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise knowledge element.");
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. whole (parent) node p1: %i\n", p1);
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. whole (parent) node *p1: %i\n", *((void**) p1));
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. knowledge path data position: %ls\n", (wchar_t*) *((void**) p2));
    //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. knowledge path count remaining: %i\n", *((int*) p3));

    // The element part.
    void* e = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The knowledge path end flag.
    int f = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    //
    // Get element part.
    //
    // Process knowledge path hierarchy recursively further down,
    // using whole part that was handed over as parametre.
    //
    // CAUTION! Do NOT forward the source whole part element index p7 as argument,
    // but NULL instead, since the next separator is UNKNOWN yet.
    //
    deserialise_knowledge((void*) &e, p1, p2, p3, p4, p5, p6, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) &f);

    if (f != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. knowledge path end HAS been reached: %i\n", f);

        //
        // The knowledge path does NOT contain further elements.
        // Its END has been reached.
        //

        //
        // Take the whole (parent) as result,
        // since it is the last existing part in the hierarchy.
        //
        copy_pointer(p0, p1);

    } else {

        //
        // The knowledge path DOES contain further elements.
        //

        //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. knowledge path end has NOT been reached: %i\n", f);

        if (e != *NULL_POINTER_STATE_CYBOI_MODEL) {

            //
            // The element (child) WAS successfully retrieved.
            //
            // CAUTION! If an element (child) could NOT be retrieved,
            // then the reasons might be:
            //
            // 1) a SPELLING error
            // 2) the element (child) does NOT EXIST
            //
            // Case 2 may be REGULAR behaviour in a cybol application
            // since sometimes, knowledge paths may point to NON-EXISTING nodes.
            //
            // Therefore, just do NOTHING in this case.
            // Even a reset of p0 to null is NOT necessary,
            // since other elements (parents) were NOT assigned yet.
            //
            // However, it IS IMPORTANT that the return value is ONLY set,
            // if a valid existing element (child) was found.
            // Assigning the whole (parent) instead of a non-existing element (child)
            // would cause a cybol application to manipulate
            // the parent instead of the (non-existing) child node,
            // which would definitely lead to WRONG application data.
            //

            //?? fwprintf(stdout, L"Debug: Deserialise knowledge element. element (child) exists: %i\n", e);

            //
            // Take the element (child) as result.
            //
            // CAUTION! The element (child) has HIGHER priority
            // than the whole (parent) found before.
            //
            copy_pointer(p0, (void*) &e);

        } else {

            //
            // CAUTION! Do NOT log this error message since in some applications,
            // nodes do not exist on purpose so that this error may be IGNORED.
            //
            // log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise knowledge element. The element (child) is null.");
            // fwprintf(stdout, L"Error: Could not deserialise knowledge element. The element (child) is null. element: %i\n", e);
            //
        }
    }
}

/* ELEMENT_KNOWLEDGE_DESERIALISER_SOURCE */
#endif
