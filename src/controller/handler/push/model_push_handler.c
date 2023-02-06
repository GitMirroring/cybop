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
 * @version CYBOP 0.24.0 2022-12-24
 * @author Christian Heller <christian.heller@cybop.org>
 */

#ifndef MODEL_PUSH_HANDLER_SOURCE
#define MODEL_PUSH_HANDLER_SOURCE

#include "../../../constant/format/cyboi/logic_cyboi_format.c"
#include "../../../constant/format/cyboi/state_cyboi_format.c"
#include "../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../constant/model/cyboi/state/state_cyboi_model.c"
#include "../../../executor/comparator/integer/equal_integer_comparator.c"
#include "../../../executor/copier/part_copier.c"
#include "../../../executor/modifier/item_modifier.c"
#include "../../../logger/logger.c"

/**
 * Pushes (adds) a part onto stack memory.
 *
 * @param p0 the stack memory item
 * @param p1 the source part (pointer reference)
 * @param p2 the format
 * @param p3 the type
 * @param p4 the knowledge memory part (pointer reference)
 * @param p5 the internal memory data
 */
void handle_push_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Handle push model.");

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Check for reference format.
    compare_integer_equal((void*) &r, p2, (void*) REFERENCE_ELEMENT_STATE_CYBOI_FORMAT);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The source part is NOT a pointer reference.
        //

        // The part.
        void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

        //
        // Copy part.
        //
        // CAUTION! The destination part gets allocated INSIDE the called fnction.
        //
        copy_part((void*) &p, p1);

        //
        // Store on stack memory (PUSH).
        //
        // CAUTION! Set the deep copying flag to FALSE here, so that pointer
        // references of the given properties get copied as SHALLOW copy.
        // The deep copying flag is relevant for format "element/part" only.
        // It is important to avoid allocating duplicates of the children
        // of the given properties on stack for at least two reasons:
        //
        // 1 Efficiency would suffer when deep-copying large tree branches
        // 2 Reference counting of rubbish (garbage) collection (gc) might get mixed up
        //
        modify_item(p0, (void*) &p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);

    } else {

        //
        // The source part IS a pointer reference.
        //

/*??
        // The temporary source data position and source count remaining.
        void* pathd = *NULL_POINTER_STATE_CYBOI_MODEL;
        int pathc = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

        // Copy source data position.
        copy_pointer((void*) &pathd, (void*) &smd);
        // Copy source count remaining.
        copy_integer((void*) &pathc, smc);

        //
        // Allocate part.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        // CAUTION! Use the cyboi runtime type determined above
        // (NOT the mime type format)!
        //
        //?? allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, td);

        //?? See file "standard_cybol_deserialiser.c"

        //
        // Get knowledge part from knowledge memory.
        //
        // CAUTION! A copy of source count remaining is forwarded here,
        // so that the original source value does not get changed.
        //
        // CAUTION! The source data position does NOT have to be copied,
        // since the parametre that was handed over is already a copy.
        // A local copy was made anyway, not to risk parametre falsification.
        // Its reference is forwarded, as it gets incremented by sub routines inside.
        //
        // Get part reference.
        // via path given as model
        deserialise_knowledge((void*) &p, p3, (void*) &pathd, (void*) &pathc, p3, p0, p4, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        //?? TODO: Reflect: Allocate new part OR just copy pointer (CAUTION! The original heap value might get changed then, when manipulating a stack variable value)

        //
        // Store part reference on stack memory (PUSH).
        // with given name
        //
        // CAUTION! Set the deep copying flag to FALSE here, so that pointer
        // references of the given properties get copied as SHALLOW copy.
        // The deep copying flag is relevant for format "element/part" only.
        // It is important to avoid allocating duplicates of the children
        // of the given properties on stack for at least two reasons:
        //
        // 1 Efficiency would suffer when deep-copying large tree branches
        // 2 Reference counting of rubbish (garbage) collection (gc) might get mixed up
        //
        //?? modify_item(p0, (void*) &a, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT);
*/
    }
}

/* MODEL_PUSH_HANDLER_SOURCE */
#endif
