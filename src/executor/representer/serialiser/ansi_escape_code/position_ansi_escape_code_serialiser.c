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

#include <stdio.h>
#include <wchar.h>

//
// Library interface
//

#include "arithmetic.h"
#include "communication.h"
#include "constant.h"
#include "knowledge.h"
#include "logger.h"
#include "type.h"

/**
 * Serialises the position into an ansi escape code.
 *
 * Example:
 * printf("\033[%d;%dH", y_row, x_column)
 *
 * @param p0 the destination ansi escape code item
 * @param p1 the source x coordinate
 * @param p2 the source y coordinate
 */
void serialise_ansi_escape_code_position(void* p0, void* p1, void* p2) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code position.");

    //
    // CAUTION! The top-left terminal corner is 1:1,
    // but the given cybol positions start counting from 0,
    // so that 1 has to be ADDED to all positions!
    // Therefore, the coordinates handed over need to be corrected.
    //

    // The y, x coordinates.
    int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    // The y, x wide character items.
    void* iy = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ix = *NULL_POINTER_STATE_CYBOI_MODEL;
    // The y, x wide character items data, count.
    void* iyd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* iyc = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ixd = *NULL_POINTER_STATE_CYBOI_MODEL;
    void* ixc = *NULL_POINTER_STATE_CYBOI_MODEL;

    //
    // Allocate y, x wide character items.
    //
    // CAUTION! Due to memory allocation handling, the size MUST NOT
    // be negative or zero, but have at least a value of ONE.
    //
    allocate_item((void*) &iy, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    allocate_item((void*) &ix, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);

    //
    // Correct y, x coordinates.
    //
    // The origin of the coordinate system (1,1)
    // is at the top, left cell of the terminal.
    //
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cy, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &cx, p1);
    calculate_integer_add((void*) &cx, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    // Serialise integer values into wide character items.
    serialise_numeral_integer(iy, (void*) &cy, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);
    serialise_numeral_integer(ix, (void*) &cx, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) DECIMAL_BASE_NUMERAL_MODEL, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL);

    //
    // Get y, x wide character items data, count.
    //
    // CAUTION! Retrieve data ONLY AFTER having called desired functions!
    // Inside the structure, arrays may have been reallocated,
    // with elements pointing to different memory areas now.
    //
    copy_array_forward((void*) &iyd, iy, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &iyc, iy, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ixd, ix, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    copy_array_forward((void*) &ixc, ix, (void*) POINTER_STATE_CYBOI_TYPE, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) COUNT_ITEM_STATE_CYBOI_NAME);

    //
    // Position cursor.
    //

    serialise_ansi_escape_code_character(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);
    // Deserialise y wide character data into ascii character data.
    deserialise_ascii(p0, iyd, iyc);
    serialise_ansi_escape_code_character(p0, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL_COUNT);
    // Deserialise x wide character data into ascii character data.
    deserialise_ascii(p0, ixd, ixc);
    serialise_ansi_escape_code_character(p0, (void*) POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL, (void*) POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT);

    // Deallocate y, x wide character items.
    deallocate_item((void*) &iy, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
    deallocate_item((void*) &ix, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE);
}
