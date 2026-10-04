/*
 * Copyright (C) 1999-2026. Christian Heller.
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
 * @version CYBOP 0.29.0 2026-10-04
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

#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"

/**
 * Serialises a primitive data type value into text user interface (tui).
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the destination win32 console output data
 * @param p2 the source model data
 * @param p3 the source model count
 * @param p4 the source properties data
 * @param p5 the source properties count
 * @param p6 the sign flag
 * @param p7 the number base
 * @param p8 the classic octal prefix flag (true means 0 as in c/c++; false means modern style 0o as in perl and python)
 * @param p9 the decimal separator data
 * @param p10 the decimal separator count
 * @param p11 the decimal places
 * @param p12 the scientific notation flag
 * @param p13 the format
 */
void serialise_tui_primitive(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise tui primitive.");
    //?? fwprintf(stdout, L"Debug: Serialise tui primitive. format p13: %i\n", p13);
    //?? fwprintf(stdout, L"Debug: Serialise tui primitive. format *p13: %i\n", *((int*) p13));

    // The wide character item.
    void* i = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The wide character item data, count.
    void* id = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ic = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate wide character item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &i, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Serialise primitive data using cybol serialiser.
    serialise_cybol(i, p2, p3, p4, p5, p6, p7, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, p8, p9, p10, p11, p12, p13);

    //
    // Get wide character item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &id, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ic, i, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    // Encode wide character and append it to the destination.
    serialise_tui_wide_character(p0, p1, id, ic);

    // Deallocate wide character item.
    deallocate_item((void*) &i, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
