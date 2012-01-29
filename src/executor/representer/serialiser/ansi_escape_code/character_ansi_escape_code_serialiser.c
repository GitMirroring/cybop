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

#ifndef CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE
#define CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE

#ifdef CYGWIN_ENVIRONMENT
#include <windows.h>
/* CYGWIN_ENVIRONMENT */
#endif

#include <stdio.h>
#include <wchar.h>

#include "../../../../constant/model/character_code/unicode/unicode_character_code_model.c"
#include "../../../../constant/model/cybol/layout/compass_layout_cybol_model.c"
#include "../../../../constant/model/cybol/border_cybol_model.c"
#include "../../../../constant/model/cybol/http_request_cybol_model.c"
#include "../../../../constant/model/cybol/layout_cybol_model.c"
#include "../../../../constant/model/cybol/shape_cybol_model.c"
#include "../../../../constant/model/terminal/ansi_escape_code_model.c"
#include "../../../../constant/model/cyboi/log/message_log_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/boolean_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/integer_state_cyboi_model.c"
#include "../../../../constant/model/cyboi/state/pointer_state_cyboi_model.c"
#include "../../../../constant/name/cybol/keyboard_key_cybol_name.c"
#include "../../../../constant/name/cybol/super_cybol_name.c"
#include "../../../../constant/name/cybol/text_user_interface_cybol_name.c"
#include "../../../../constant/name/memory/vector_memory_name.c"
#include "../../../../constant/type/cyboi/state_cyboi_type.c"
#include "../../../../executor/accessor/getter/compound_getter.c"
#include "../../../../executor/accessor/getter.c"
#include "../../../../executor/representer/serialiser/cybol/integer/integer_cybol_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_background_serialiser.c"
#include "../../../../executor/representer/serialiser/terminal_foreground_serialiser.c"
#include "../../../../executor/modifier/overwriter/appender/item_appender.c"
#include "../../../../logger/logger.c"

/**
 * Serialises the ansi escape code character into an escape control sequence.
 *
 * @param p0 the destination control sequence code item
 * @param p1 the x coordinate
 * @param p2 the y coordinate
 * @param p3 the z coordinate
 * @param p4 the background colour
 * @param p5 the background colour count
 * @param p6 the foreground colour
 * @param p7 the foreground colour count
 * @param p8 the hidden flag
 * @param p9 the inverse flag
 * @param p10 the blink flag
 * @param p11 the underline flag
 * @param p12 the bold flag
 * @param p13 the character
 */
void serialise_ansi_escape_code_character(void* p0, void* p1, void* p2, void* p3, void* p4, void* p5, void* p6, void* p7, void* p8, void* p9, void* p10, void* p11, void* p12, void* p13) {

    log_message_terminated((void*) DEBUG_LEVEL_LOG_CYBOI_MODEL, (void*) L"Serialise ansi escape code character.");

    // CAUTION! The top-left terminal corner is 1:1, but the given positions
    // start counting from 0, so that 1 has to be added to all positions!
    // Therefore, the coordinates handed over need to be corrected.

    // The corrected y, x.
    int cy = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;
    int cx = *NUMBER_0_INTEGER_STATE_CYBOI_MODEL;

    // Correct y, x.
    calculate_integer_add((void*) &cy, p2);
    calculate_integer_add((void*) &cy, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);
    calculate_integer_add((void*) &cx, p1);
    calculate_integer_add((void*) &cx, (void*) NUMBER_1_INTEGER_STATE_CYBOI_MODEL);

    //
    // Position cursor.
    //
    // Example:
    // printf("\033[%d;%dH", y_row, x_column)
    //

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cy, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    append_item_element(p0, (void*) SEMICOLON_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_cybol_integer_value(p0, (void*) &cx, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT);
    append_item_element(p0, (void*) LATIN_CAPITAL_LETTER_H_UNICODE_CHARACTER_CODE_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    append_item_element(p0, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_OFF_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    //
    // Add background and foreground properties.
    //
    // Example:
    // printf("\033[32mgreen colour\033[0mswitched off.")
    //

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_ansi_escape_code_background(p0, p4, p5);
    append_item_element(p0, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    serialise_ansi_escape_code_foreground(p0, p6, p7);
    append_item_element(p0, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ATTRIBUTE_SUFFIX_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);

    //
    // Set character properties.
    //
    // Example:
    // printf("\033[1mbold \033[0mswitched off.")
    //

    // The comparison result.
    int r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Set hidden property.
    compare_integer_unequal((void*) &r, p10, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(p0, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) HIDDEN_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Set inverse property.
    compare_integer_unequal((void*) &r, p11, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(p0, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) INVERSE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Set blink property.
    compare_integer_unequal((void*) &r, p12, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(p0, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BLINK_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Set underline property.
    compare_integer_unequal((void*) &r, p13, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(p0, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) UNDERLINE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Reset comparison result.
    r = *FALSE_BOOLEAN_STATE_CYBOI_MODEL;

    // Set bold property.
    compare_integer_unequal((void*) &r, p14, (void*) FALSE_BOOLEAN_STATE_CYBOI_MODEL);

    if (r != *FALSE_BOOLEAN_STATE_CYBOI_MODEL) {

        append_item_element(p0, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) ESCAPE_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
        append_item_element(p0, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) BOLD_ESCAPE_CONTROL_SEQUENCE_TERMINAL_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
    }

    // Set character.
    append_item_element(p0, p15, (void*) WIDE_CHARACTER_TEXT_STATE_CYBOI_TYPE, (void*) PRIMITIVE_STATE_CYBOI_MODEL_COUNT, (void*) VALUE_PRIMITIVE_STATE_CYBOI_NAME);
}

/* CHARACTER_ANSI_ESCAPE_CODE_SERIALISER_SOURCE */
#endif
