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
// System interface
//

#include <stdio.h> // stdout
#include <wchar.h> // fwprintf

//
// Library interface
//

#include "arithmetic.h"
#include "constant.h"
#include "cybol.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Pushes (adds) a part onto stack memory.
 *
 * @param p0 the stack memory item
 * @param p1 the source part (pointer reference)
 * @param p2 the source name data
 * @param p3 the source name count
 * @param p4 the source format
 * @param p5 the source model data
 * @param p6 the source model count
 * @param p7 the knowledge memory part (pointer reference)
 * @param p8 the internal memory data
 */
void push_model(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Push model.");
    //?? fwprintf(stdout, L"Debug: Push model. p4: %i\n", p4);
    //?? fwprintf(stdout, L"Debug: Push model. *p4: %i\n", *((int*) p4));

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;
    // The part.
    void* p = *NULL_POINTER_STATE_CYBOI_MODEL;

    // Check for reference format.
    compare_integer_equal((void*) &r, p4, (void*) REFERENCE_ELEMENT_STATE_CYBOI_FORMAT);

    if (r == *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        //
        // The source part is NOT a pointer reference.
        //

        //
        // Copy part.
        //
        // CAUTION! The destination part gets allocated INSIDE the called fnction.
        //
        copy_part((void*) &p, p1);

    } else {

        //
        // The source part IS a pointer reference.
        //

        //?? fwprintf(stdout, L"Debug: Push model. pointer reference p4: %i\n", p4);

        // The source model data position.
        void* d = *NULL_POINTER_STATE_CYBOI_MODEL;
        // The source model count remaining.
        int c = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
        // The original part.
        void* o = *NULL_POINTER_STATE_CYBOI_MODEL;

        // Copy source model data position.
        copy_pointer((void*) &d, (void*) &p5);
        // Copy source model count remaining.
        copy_integer((void*) &c, p6);

        //
        // Get part from knowledge memory using source model as path.
        //
        // CAUTION! A copy of source count remaining is forwarded here,
        // so that the original source value does not get changed.
        //
        // CAUTION! The source data position does NOT have to be copied,
        // since the parametre that was handed over is already a copy.
        // A local copy was made anyway, not to risk parametre falsification.
        // Its reference is forwarded, as it gets incremented by sub routines inside.
        //
        deserialise_knowledge((void*) &o, p7, (void*) &d, (void*) &c, p7, p0, p8, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

        //
        // Allocate part.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_part((void*) &p, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) PART_ELEMENT_STATE_CYBOI_TYPE);

        //
        // Fill part.
        //
        // CAUTION! Do NOT forget to assign the format and type.
        //
        modify_part(p, p2, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, p3, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
        modify_part(p, (void*) PART_ELEMENT_STATE_CYBOI_FORMAT, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        modify_part(p, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);
        //
        // CAUTION! Set deep copy flag to FALSE, since only the pointer REFERENCE
        // is to be copied (SHALLOW COPY), but NOT the whole source part tree.
        //
        modify_part(p, (void*) &o, (void*) PART_ELEMENT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) NUMBER_0_INTEGER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) MODEL_PART_STATE_CYBOI_NAME);
    }

    //
    // Append part to stack memory item (PUSH).
    //
    // CAUTION! Use PART_ELEMENT_STATE_CYBOI_TYPE and NOT just POINTER_STATE_CYBOI_TYPE here.
    // This is necessary in order to activate rubbish (garbage) collection (gc).
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
}
