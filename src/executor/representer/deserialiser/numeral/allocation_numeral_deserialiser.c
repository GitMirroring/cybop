/*
 * Copyright (C) 1999-2025. Christian Heller.
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
 * @version CYBOP 0.28.0 2025-05-31
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

#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Allocates a number part.
 *
 * @param p0 the destination number part (pointer reference)
 * @param p1 the number part name data
 * @param p2 the number part name count
 * @param p3 the number part format
 * @param p4 the number part type
 */
void deserialise_numeral_allocation(void* p0, void* p1, void* p2, void* p3, void* p4) {

    if (p0 != *NULL_POINTER_STATE_CYBOI_MODEL) {

        void** p = (void**) p0;

        log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Deserialise numeral allocation.");
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. name data p1: %ls\n", (wchar_t*) p1);
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. name count p2: %i\n", p2);
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. name count *p2: %i\n", *((int*) p2));
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. format p3: %i\n", p3);
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. format *p3: %i\n", *((int*) p3));
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. type p4: %i\n", p4);
        //?? fwprintf(stdout, L"Debug: Deserialise numeral allocation. type *p4: %i\n", *((int*) p4));

        //
        // Declaration
        //

        //
        // CAUTION! These local variables are IMPORTANT, so that a default value may
        // be assigned. Without a type used for allocation, memory leaks might occur.
        //

        // The name data, count with default.
        void* nd = (void*) L"ERROR_MISSING_NAME";
        int nc = *NUMBER_18_INTEGER_STATE_CYBOI_MODEL;
        // The format with INTEGER as default.
        int f = *INTEGER_NUMBER_STATE_CYBOI_FORMAT;
        // The type with INTEGER as default.
        int t = *INTEGER_NUMBER_STATE_CYBOI_TYPE;

        //
        // Initialisation
        //

        // Copy name data, count.
        copy_integer((void*) &nd, (void*) &p1);
        copy_integer((void*) &nc, p2);
        // Copy format.
        copy_integer((void*) &f, p3);
        // Copy type.
        copy_integer((void*) &t, p4);

        //
        // Allocation
        //

        //
        // Allocate number part.
        //
        // CAUTION! Due to memory allocation handling, the size MUST NOT
        // be negative or zero, but have at least a value of ONE.
        //
        allocate_part(p0, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) &t);

        //
        // Assignment
        //

        //
        // Fill number part.
        //
        // CAUTION! Do NOT forget to assign the format and type.
        //
        modify_part(*p, nd, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) &nc, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) NAME_PART_STATE_CYBOI_NAME);
        modify_part(*p, (void*) &f, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) FORMAT_PART_STATE_CYBOI_NAME);
        modify_part(*p, (void*) &t, (void*) INTEGER_NUMBER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) OVERWRITE_MODIFY_LOGIC_CYBOI_FORMAT, (void*) TYPE_PART_STATE_CYBOI_NAME);

    } else {

        log_message_terminated((void*) ERROR_LEVEL_LOG_CYBOI_MODEL, (void*) L"Could not deserialise numeral allocation. The destination number part is null.");
        fwprintf(stdout, L"Error: Could not deserialise numeral allocation. The destination number part is null. p0: %i\n", p0);
    }
}
