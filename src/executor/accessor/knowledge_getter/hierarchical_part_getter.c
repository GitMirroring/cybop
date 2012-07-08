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

#ifndef HIERARCHICAL_PART_GETTER_SOURCE
#define HIERARCHICAL_PART_GETTER_SOURCE

#include "../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/accessor/name_getter/part_name_getter.c"
#include "../../../executor/searcher/selector/knowledge/name_knowledge_selector.c"
#include "../../../logger/logger.c"

//
// Forward declaration.
//

void get_part_branch(void* p0, void* p1, void* p2, void* p3);

/**
 * Gets the knowledge part by hierarchical name.
 *
 * @param p0 the destination part (pointer reference)
 * @param p1 the source whole part
 * @param p2 the hierarchical part name current position (pointer reference)
 * @param p3 the hierarchical part name remaining count
 * @param p4 the source whole part element index (one of:
 *           - MODEL_PART_STATE_CYBOI_NAME for structural parts
 *           - PROPERTIES_PART_STATE_CYBOI_NAME for meta properties)
 */
void get_part_hierarchical(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p3 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        int* rem = (int*) p3;

        if (p2 != *NULL_POINTER_STATE_CYBOI_MODEL) {

            void** pos = (void**) p2;

            if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

                void** d = (void**) p0;

                log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part hierarchical.");

                // The element.
                void* e = *pos;
                int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // The break flag.
                int b = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // CAUTION! The function "select_knowledge_name"
                        // may have decremented the remaining count,
                        // if neither a . nor a # delimiter were found.
                        //
                        // This is regularly the case if a part was the
                        // LAST IN THE HIERARCHY, having no further
                        // child nodes to follow in the name.
                        //
                        // In order to also consider such parts, the
                        // following function calls ARE NECESSARY here.

                        // CAUTION! In case the remaining count is too small
                        // or zero (name does not exist) right at the beginning,
                        // then the destination remains UNTOUCHED.

                        // Find part by name in whole model or properties
                        // (depending on part element index p4).
                        get_name_part_element(p0, p1, e, (void*) &ec, p4);

                        // CAUTION! There is NO USE in processing the knowledge hierarchy
                        // recursively further down here, since the part was the
                        // LAST IN THE HIERARCHY, having no further
                        // child nodes to follow in the name.
                        // Therefore, the following function is disabled:
                        // get_part_branch(p0, *d, p2, p3);

                        break;
                    }

                    // If a . or # delimiter is found, then the break flag is set to "true".
                    // Otherwise, the position is just moved by one character forward.
                    select_knowledge_name((void*) &b, p2, p3);

                    if (b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

                        // CAUTION! Do NOT relate this comparison with the
                        // remaining count comparison from above in the following way:
                        // if ((b != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) || (*rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {
                        //
                        // If they were related using the boolean OR operator,
                        // then the element count ec would always be ONE TOO SMALL,
                        // since the last loop would be omitted and ec not incremented (below).

                        // Find part by name in whole model or properties
                        // (depending on part element index p4).
                        get_name_part_element(p0, p1, e, (void*) &ec, p4);

                        // Process knowledge hierarchy recursively further down.
                        //
                        // CAUTION! The current p0 is the SOURCE AND DESTINATION!
                        // A part node of the source p1 was assigned to p0 above,
                        // so that p0 is now the source.
                        // If it has a child part, then that will be assigned to the
                        // destination. Otherwise, the destination remains UNTOUCHED.
                        //
                        // CAUTION! Hand over the source as dereferenced parametre!
                        get_part_branch(p0, *d, p2, p3);

                        break;

                    } else {

                        // Increment element count.
                        // A . or # delimiter has NOT been found, so that this
                        // is somewhere in the middle of an element name.
                        ec++;
                    }
                }

            } else {

                log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The destination part is null.");
            }

        } else {

            log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The current position is null.");
        }

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The remaining count is null.");
    }
}

/* HIERARCHICAL_PART_GETTER_SOURCE */
#endif
