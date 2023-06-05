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
 * @version CYBOP 0.26.0 2023-04-04
 * @author Christian Heller <christian.heller@cybop.org>
 */

//
// Library interface
//

#include "algorithm.h"
#include "arithmetic.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Selects the knowledge end.
 *
 * @param p0 the knowledge path data position (pointer reference)
 * @param p1 the knowledge path count remaining
 * @param p2 the move flag
 * @param p3 the knowledge path end flag
 * @param p4 the name count
 * @param p5 the break flag
 */
void select_knowledge_end(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Select knowledge end.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT move the position, i.e. hand over FALSE as last parametre here.
        // The reason is that a potential new sub part's name or model or property, indicated by
        // a "." or ":" character, respectively, have to be detected once again in another function.
        //
        detect((void*) &r, p0, p1, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) MODEL_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A "." was found.
            //

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // CAUTION! Do NOT move the position, i.e. hand over FALSE as last parametre here.
        // The reason is that a potential new sub part's name or model or property, indicated by
        // a "." or ":" character, respectively, have to be detected once again in another function.
        //
        detect((void*) &r, p0, p1, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PROPERTY_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A ":" was found.
            //

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) END_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_REFERENCE_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, p2);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A "}" was found.
            //

            //
            // Set knowledge path end flag.
            //
            // CAUTION! Setting this flag IS IMPORTANT
            // for deciding whether to assign the whole (parent) or
            // element (child) node in file "part_knowledge_deserialiser.c".
            //
            // There are two files, where the end flag is set:
            // 1) knowledge_deserialiser.c
            // 2) end_knowledge_selector.c
            //
            // Case 1 applies, when the absolute end of the knowledge path
            // has been reached, i.e. count remaining is zero.
            //
            // Case 2 applies, when a SUB PATH was used:
            // - either as name, like e.g. "(.some.path)"
            // - or as index, like e.g. "[#some_index_on_stack]"
            // and the end of that sub path has been reached:
            // - either a ")"
            // - or a "]"
            //
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) END_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_NAME_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, p2);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A ")" was found.
            //

            //
            // Set knowledge path end flag.
            //
            // CAUTION! Setting this flag IS IMPORTANT
            // for deciding whether to assign the whole (parent) or
            // element (child) node in file "part_knowledge_deserialiser.c".
            //
            // There are two files, where the end flag is set:
            // 1) knowledge_deserialiser.c
            // 2) end_knowledge_selector.c
            //
            // Case 1 applies, when the absolute end of the knowledge path
            // has been reached, i.e. count remaining is zero.
            //
            // Case 2 applies, when a SUB PATH was used:
            // - either as name, like e.g. "(.some.path)"
            // - or as index, like e.g. "[#some_index_on_stack]"
            // and the end of that sub path has been reached:
            // - either a ")"
            // - or a "]"
            //
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        detect((void*) &r, p0, p1, (void*) END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) END_INDEX_SEPARATOR_KNOWLEDGE_CYBOI_NAME_COUNT, p2);

        if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

            //
            // A "]" was found.
            //

            //
            // Set knowledge path end flag.
            //
            // CAUTION! Setting this flag IS IMPORTANT
            // for deciding whether to assign the whole (parent) or
            // element (child) node in file "part_knowledge_deserialiser.c".
            //
            // There are two files, where the end flag is set:
            // 1) knowledge_deserialiser.c
            // 2) end_knowledge_selector.c
            //
            // Case 1 applies, when the absolute end of the knowledge path
            // has been reached, i.e. count remaining is zero.
            //
            // Case 2 applies, when a SUB PATH was used:
            // - either as name, like e.g. "(.some.path)"
            // - or as index, like e.g. "[#some_index_on_stack]"
            // and the end of that sub path has been reached:
            // - either a ")"
            // - or a "]"
            //
            copy_integer(p3, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);

            // Set break flag.
            copy_integer(p5, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL);
        }
    }

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        // The step.
        int step = *NUMBER_1_INTEGER_STATE_CYBOI_MODEL;

        // Move the current position.
        move(p0, p1, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) &step, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

        // Adjust name count.
        calculate_integer_add(p4, (void*) &step);
    }
}
