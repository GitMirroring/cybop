/*
 * Copyright (C) 1999-2016. Christian Heller.
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
 * @version CYBOP 0.18.0 2016-12-21
 * @author Christian Heller <christian.heller@tuxtax.de>
 */

#ifndef POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/ansi_escape_code/ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/level_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/representer/serialiser/cybol/integer/value_integer_cybol_serialiser.c"
#include "../../../../logger/logger.c"

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

    // CAUTION! The top-left terminal corner is 1:1,
    // but the given cybol positions start counting from 0,
    // so that 1 has to be added to all positions!
    // Therefore, the coordinates handed over need to be corrected.

    // The y, x coordinates.
    int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Correct y, x coordinates.
    // The origin of the coordinate system (1,1)
    // is at the top, left cell of the terminal.
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cy, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &cx, p1);
    calculate_integer_add((void*) &cx, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Position cursor.
    //

    modify_item_element(p0, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PREFIX_ANSI_ESCAPE_CODE_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cy, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    modify_item_element(p0, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_SEPARATOR_ANSI_ESCAPE_CODE_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cx, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) NUMBER_10_INTEGER_STATE_CYBOI_MODEL);
    modify_item_element(p0, (void*) POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) POSITION_SUFFIX_ANSI_ESCAPE_CODE_MODEL_COUNT, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME, (void*) TRUE_BOOLEAN_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, *NULL_POINTER_STATE_CYBOI_MODEL, (void*) APPEND_MODIFY_LOGIC_CYBOI_FORMAT, (void*) DATA_ITEM_STATE_CYBOI_NAME);
}

/* POSITION_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
