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
#include "../../../constant/model/memory/boolean_memory_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../executor/modifier/getter/name_part_getter.c"
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

                log_terminated_message((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Get part hierarchical.");

                // The element.
                void* e = *pos;
                int ec = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
                // The break flag.
                int b = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

                while (*TRUE_BOOLEAN_STATE_CYBOI_MODEL) {

                    if (*rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // CAUTION! The function "select_knowledge_name"
                        // may have decremented the remaining count,
                        // if neither "." nor "#" were found.
                        // But this is regularly the case if a
                        // part was the last in the hierarchy,
                        // having no further child nodes.
                        // In order to also consider such parts, the
                        // following function calls are necessary here.
                        //
                        // In case the remaining count is too small right
                        // at the beginning, or the name does not exist,
                        // then the following functions will just return null.

                        // Find part by name in whole model or properties
                        // (depending on part element index p4).
                        get_name_part_element(p0, p1, e, (void*) &ec, p4);

                        // Process knowledge hierarchy recursively further down.
                        //
                        // CAUTION! The current p0 is the SOURCE AND DESTINATION!
                        // A part node of the source p1 was assigned to p0 above,
                        // so that p0 is now the source.
                        // Its child part will be assigned to the destination again.
                        //
                        // CAUTION! Hand over the source as dereferenced parametre!
                        get_part_branch(p0, *d, p2, p3);

                        break;
                    }

                    select_knowledge_name((void*) &b, p2, p3);

                    if (b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) {

                        // CAUTION! Do NOT relate this comparison with the
                        // remaining count comparison from above in the following way:
                        // if ((b != *NUMBER_0_INTEGER_STATE_CYBOI_MODEL) || (*rem <= *NUMBER_0_INTEGER_STATE_CYBOI_MODEL)) {
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
                        // Its child part will be assigned to the destination again.
                        //
                        // CAUTION! Hand over the source as dereferenced parametre!
                        get_part_branch(p0, *d, p2, p3);

                        break;

                    } else {

                        // Increment request method count.
                        ec++;
                    }
                }

            } else {

                log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The destination part is null.");
            }

        } else {

            log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The current position is null.");
        }

    } else {

        log_terminated_message((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not get part hierarchical. The remaining count is null.");
    }
}

/* HIERARCHICAL_PART_GETTER_SOURCE */
#endif
