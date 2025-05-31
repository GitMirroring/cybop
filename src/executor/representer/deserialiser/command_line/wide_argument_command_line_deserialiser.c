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

#include <stdio.h>
#include <wchar.h>

//
// Library interface
//

#include "communication.h"
#include "constant.h"
#include "cyboi.h"
#include "knowledge.h"
#include "logger.h"
#include "cyboi.h"

/**
 * Deserialises the command line argument given as wide character data.
 *
 * @param p0 the operation mode
 * @param p1 the cybol knowledge file path item
 * @param p2 the log level
 * @param p3 the test unit
 * @param p4 the terminated log file name item (multibyte character data)
 * @param p5 the argument data
 * @param p6 the argument count
 */
void deserialise_command_line_argument_wide(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6) {

    //
    // CAUTION! DO NOT use logging functionality here!
    // The logger will not work before its options are set.
    // Comment out this function call to avoid disturbing messages at system startup!
    //
    // log_write((void*) stdout, L"Information: Deserialise command line.\n");
    //

    // The argument item.
    void* a = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The argument item data, count.
    void* ad = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ac = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate argument item.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &a, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    // Decode multibyte character into wide character.
    decode_utf_8(a, p5, p6);

    //
    // Get argument item data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &ad, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ac, a, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Deserialise the option.
    //
    // CAUTION! The argument item data gets handed over AS REFERENCE,
    // as it gets manipulated inside the called function.
    //
    deserialise_command_line_option(p0, p1, p2, p3, p4, (void*) &ad, ac);

    // Deallocate argument item.
    deallocate_item((void*) &a, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
